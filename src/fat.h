/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/**
 * \file fat.h
 * \brief Ce fichier contient quelques macros, définitions et des fonctions de routine pour le tracker.
 * 
 * Il contient également tous les include vers les autres fichiers.
 */

#ifndef _FAT_H_
#define _FAT_H_

#define TEXT_LAYER 1
#define SCREEN_LAYER 3

/** \brief Id écran projet */
#define SCREEN_PROJECT_ID 0
/** \brief Id écran live */
#define SCREEN_LIVE_ID 1
/** \brief Id écran composer */
#define SCREEN_COMPOSER_ID 2
/** \brief Id écran song */
#define SCREEN_SONG_ID 3
/** \brief Id écran block */
#define SCREEN_BLOCKS_ID 4
/** \brief Id écran notes */
#define SCREEN_NOTES_ID 5
/** \brief Id écran instrument */
#define SCREEN_INSTRUMENTS_ID 6
/** \brief Id écran effects (tables) */
#define SCREEN_EFFECTS_ID 7
/** \brief Id écran filesystem. */
#define SCREEN_FILESYSTEM_ID 8
/** \brief Id écran help. */
#define SCREEN_HELP_ID 9
/** \brief Nombre total d'écran disponible pour FAT */
#define NB_SCREEN 8;
/** \brief Numéro de la couleur du texte. Ce numéro correspond à une couleur dans la palette. <b>NE PAS TOUCHER</b>*/
#define TEXT_COLOR 245 // 159, 247
/** \brief Position par défaut du curseur de changement d'onglet (partie instrument).*/
#define INPUT_R_CURSOR_CHANGE_X 216
/** \brief Position par défaut du curseur de changement d'onglet (partie instrument).*/
#define INPUT_R_CURSOR_CHANGE_Y 24

/** \brief Définition du temps d'attente MINIMUM entre 2 appui sur la touche START. Ce chiffre peut 
 être pondéré avec une valeur paramétrable. */
#define WAIT_FOR_START 40

/** \brief Définition globale du format d'affichage des numéros de lignes. */
#define FAT_FORMAT_LINE "%.2x"

/** \brief Stocke l'id de l'écran sur lequel l'utilisateur se situe. */
u8 FAT_currentScreen = SCREEN_SONG_ID;

/** \brief Variable quasi temporaire afin de savoir si on a activé l'écran d'aide. */
u8 isHelpActivated = 0;

void FAT_initSpritePalette();
void FAT_initScreenPalette();
void FAT_switchToScreen(u8 screenId);
void FAT_showHelp(u8 screenId);
void FAT_reinitScreen();
void FAT_forceClearTextLayer();
void FAT_waitVSync();
void FAT_blockCPU(u16 time);

void VBLInterruptHandler(void) {
    hel_ObjTransmit();
    // acknowledge interrupt
    hel_IntrAcknowledge(INT_TYPE_VBL);
}

#include "gfx/ResourceData.h"

#include "data.h"
#include "filesystem.h"
#include "cursors.h"


/** \brief Prototype. Fonction définie dans player.h. */
void FAT_player_startPlayerFromSequences(u8 startLine);
/** \brief Prototype. Fonction définie dans player.h. */
void FAT_player_startPlayerFromBlocks(u8 sequenceId, u8 startLine, u8 channel);
/** \brief Prototype. Fonction définie dans player.h. */
void FAT_player_startPlayerFromNotes(u8 blockId, u8 startLine, u8 channel);
/** \brief Prototype. Fonction définie dans player.h. */
void FAT_player_stopPlayer();
/** \brief Prototype. Fonction définie dans player.h. */
void FAT_player_playComposerNote(u8 noteLine);
/** \brief Prototype. Fonction définie dans player.h. */
void FAT_player_startPlayerFromSequences_onlyOneColumn(u8 line, u8 channel);

void FAT_player_stopPlayer_onlyOneColumn(u8 channel);
bool FAT_isChannelCurrentlyPlaying (u8 channel);

/**
 * \brief Permet de savoir si le player est en train de jouer la chanson.
 */
bool FAT_isCurrentlyPlaying = 0;
u8 FAT_live_nbChannelPlaying = 0;

#include "popup.h"
#include "yesno_dialog.h"
#include "dialog_keyboard.h"
#include "screen_song.h"
#include "screen_filesystem.h"
#include "screen_project.h"
#include "screen_live.h"
#include "screen_composer.h"
#include "screen_blocks.h"
#include "screen_notes.h"
#include "screen_instrument.h"
#include "screen_effects.h"
#include "screen_help.h"

#include "player.h"

u8 ATTR_EWRAM ATTR_ALIGNED(4) g_BgTextSystemMemory[HEL_SUBSYSTEM_BGTEXT_REQUIREDMEMORY];
u16 ATTR_EWRAM g_CharLUT[256];
// attention, table ASCII uniquement sinon ça fout la grouille.
const unsigned char CHARORDER[] =
        " BCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmn"\
    "opqrstuvwxyz0123456789,.-;:A#^+*@"\
    "!\"~$%&/()=?|\\<>[]{}¹²³°";

u8 ATTR_EWRAM ATTR_ALIGNED(4) g_ObjSystemBuffer[HEL_SUBSYSTEM_OBJ_REQUIREDMEMORY];

/**
 * \brief Initialisation de HAM et d'autres données propres à FAT. 
 * 
 * Initialisations:
 * - HAM (init, text, bgMode, textCol, fx)
 * - les palettes pour FAT (screen et sprite)
 * - la popup de déplacement 
 * - les curseurs
 * - les sprites
 * - les données du projet
 */
void FAT_init() {
    // HAM !
    ham_Init();
    hel_SysSetPrefetch(TRUE);

    FAT_filesystem_checkFs();

    hel_BgSetMode(0);

    hel_BgTextInit((void*) g_BgTextSystemMemory);
    hel_ObjInit(g_ObjSystemBuffer);

    hel_PadInit();
    hel_PadSetRepeatDelay(PAD_BUTTON_R | PAD_BUTTON_L | PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_UP | PAD_BUTTON_DOWN | PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_START, 1);
    hel_PadSetRepeatRate(PAD_BUTTON_R | PAD_BUTTON_L | PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_UP | PAD_BUTTON_DOWN | PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_START, 10);

    // Initialize the tileset and an empty
    // mapset using regular HAMlib functions
    //ham_bg[TEXT_LAYER].ti = ham_InitTileSet(ResData(RES_TEXT_RAW), RES_TEXT_RAW_SIZE16, 1, 1);
    ham_bg[TEXT_LAYER].ti = ham_InitTileSet((void*) ResData(RES_TEXT_RAW), RES_TEXT_RAW_SIZE16, 1, 1);
    ham_bg[TEXT_LAYER].mi = ham_InitMapEmptySet((u8) 1024, 0);

    hel_BgTextCreate(
            TEXT_LAYER, // BgNo
            1, // Width of one character specified in tiles
            1, // Height of one character specified in tiles
            //ResData(RES_CHARSET8X8_MAP), // Pointer to character map
            ResData(RES_TEXT_MAP),
            CHARORDER, // Pointer to array that reflects the order of characters on source graphic
            g_CharLUT, // Pointer to buffer that receives the generated lookup table
            BGTEXT_FLAGS_GENERATELUT); // Flags that control creation and print behaviour

    ham_InitBg(TEXT_LAYER, TRUE, 0, FALSE);

    hel_FxInit();
    hel_FxSetMode(  FX_LAYER_SELECT(0, 0, 0, 0, 1, 0),
                    FX_LAYER_SELECT(0, 0, 1, 1, 0, 0),
                    FX_MODE_ALPHABLEND);
    hel_FxSetAlphaLevel(7, 0);

    hel_IntrStartHandler(INT_TYPE_VBL, (void*) &VBLInterruptHandler);

    // initialisation des palettes.
    FAT_initScreenPalette();
    FAT_initSpritePalette();

    // initialisation de l'écran "Popup" (la map de déplacement)
    FAT_popup_init();

    // initialisation des curseurs
    FAT_initCursor1();
    FAT_initCursor2();
    FAT_initCursor3();
    FAT_initCursor8();
    FAT_initCursorChange();
    FAT_initCursorsKeyboard();
    FAT_popup_initCursors();
    FAT_screenInstrument_tabCursorInit();

    FAT_player_initCursors();
    //FAT_cursors_initCursorsChannel ();

    // chargement des sprites pour l'écran instrument
    FAT_screenInstrument_initSpritesForInstrument();

    FAT_screenSong_initCursor();
    FAT_screenLive_initCursor();
    FAT_screenNotes_initCursor();
    FAT_screenBlocks_initCursor();
    FAT_screenComposer_initCursor();
    FAT_screenFilesystem_initCursor();

    // intialisation des données "tracker" stockées en RAM
    FAT_data_initData();
}

/**
 * \brief Charge la palette réservée pour l'écran d'intro. 
 */
void FAT_initIntroPalette() {
    hel_PalBgLoad256(ResData16(RES_INTRO_PAL));
}

/**
 * \brief Méthode pour afficher un simple écran "titre" avec une boucle infinie en
 * attente du bouton "START". 
 */
void FAT_showIntro() {
    FAT_reinitScreen();

    FAT_initIntroPalette();

    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_INTRO_RAW), RES_INTRO_RAW_SIZE16, 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_INTRO_MAP), 1024, 0, 0);

    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

#ifdef DEBUG_ON
    hel_BgTextPrint(TEXT_LAYER, 1, 14, 0, "DEBUG ON");
    hel_BgTextPrintF(TEXT_LAYER, 1, 16, 0, "SIZE %d octets", (SIZEOF_8BIT (tracker)));
#endif
    hel_BgTextPrintF(TEXT_LAYER, 22, 19, 0, "%.3d kits", snd_countAvailableKits());

    while (1) {

        hel_PadCapture();

        if (hel_PadQuery()->Pressed.Start ||
                hel_PadQuery()->Pressed.Select ||
                hel_PadQuery()->Pressed.A ||
                hel_PadQuery()->Pressed.B ||
                hel_PadQuery()->Pressed.Up ||
                hel_PadQuery()->Pressed.Down ||
                hel_PadQuery()->Pressed.Right ||
                hel_PadQuery()->Pressed.Left ||
                hel_PadQuery()->Pressed.R ||
                hel_PadQuery()->Pressed.L
                ) {
            break;
        }

        // Wait for Vertical Blank
        hel_SwiVBlankIntrWait();
    }
    
    ham_InitBg(SCREEN_LAYER, 0, 3, 0);
    FAT_initScreenPalette();
}

/**
 * \brief Méthode qui permet de réinitialiser le BG SCREEN_LAYER proprement.
 * 
 * <b>NE PAS TOUCHER !  </b>
 */
void FAT_reinitScreen() {
    if (ham_bg[SCREEN_LAYER].ti) {
        ham_DeInitTileSet(ham_bg[SCREEN_LAYER].ti);
        ham_DeInitMapSet(ham_bg[SCREEN_LAYER].mi);
        FAT_forceClearTextLayer();
    }
}

/**
 * \brief Méthode à réfactorer : effacer l'écran texte en affichant des espaces partout. 
 * 
 * Performance warning ! Afficher du texte via HAM est lent !
 */
void FAT_forceClearTextLayer() {
    if (ham_bg[TEXT_LAYER].ti) {

        ham_DeInitTileSet(ham_bg[TEXT_LAYER].ti);
        ham_DeInitMapSet(ham_bg[TEXT_LAYER].mi);

        ham_bg[TEXT_LAYER].ti = ham_InitTileSet((void*) ResData(RES_TEXT_RAW), RES_TEXT_RAW_SIZE16, 1, 1);
        ham_bg[TEXT_LAYER].mi = ham_InitMapEmptySet((u8) 1024, 0);
    }

}

/**
 * \brief La palette pour les sprites est différente: cette fonction la charge au bon endroit.
 */
void FAT_initSpritePalette() {
    hel_PalObjLoad16(ResData16(RES_SPRITES_PAL), 0);
}

/**
 * \brief Charge la palette pour les écrans: les sprites sont exclus. 
 */
void FAT_initScreenPalette() {
    hel_PalBgLoad256(ResData16(RES_SCREEN_PAL));
}

void FAT_allScreen_singleCheckButtons() {
    switch (FAT_currentScreen) {
        case SCREEN_PROJECT_ID:
            FAT_screenProject_checkButtons();
            break;
        case SCREEN_LIVE_ID:
            FAT_screenLive_checkButtons();
            break;
        case SCREEN_SONG_ID:
            FAT_screenSong_checkButtons();
            break;
        case SCREEN_BLOCKS_ID:
            FAT_screenBlocks_checkButtons();
            break;
        case SCREEN_NOTES_ID:
            FAT_screenNotes_checkButtons();
            break;
        case SCREEN_EFFECTS_ID:
            FAT_screenEffects_checkButtons();
            break;
        case SCREEN_COMPOSER_ID:
            FAT_screenComposer_checkButtons();
            break;
        case SCREEN_INSTRUMENTS_ID:
            FAT_screenInstrument_checkButtons();
            break;
        case SCREEN_FILESYSTEM_ID:
            FAT_screenFilesystem_checkButtons();
            break;
        case SCREEN_HELP_ID:
            FAT_screenHelp_checkButtons();

            break;
    }
}

void FAT_mainLoop() {
    for (;;) {

        if (FAT_isCurrentlyPlaying) {

            FAT_player_continueToPlay();
        }

        FAT_allScreen_singleCheckButtons();
        // Wait for Vertical Blank
        hel_SwiVBlankIntrWait();

    }
}

/**
 * \brief Cette méthode permet de changer d'écran.
 * 
 * @param screenId l'id de l'écran que l'on souhaite afficher.
 */
void FAT_switchToScreen(u8 screenId) {
    FAT_currentScreen = screenId;
    switch (screenId) {
        case SCREEN_PROJECT_ID:
            FAT_screenProject_init();
            break;
        case SCREEN_LIVE_ID:
            FAT_screenLive_init();
            break;
        case SCREEN_SONG_ID:
            FAT_screenSong_init();
            break;
        case SCREEN_BLOCKS_ID:
            FAT_screenBlocks_init();
            break;
        case SCREEN_NOTES_ID:
            FAT_screenNotes_init();
            break;
        case SCREEN_EFFECTS_ID:
            FAT_screenEffects_init();
            break;
        case SCREEN_COMPOSER_ID:
            FAT_screenComposer_init();
            break;
        case SCREEN_INSTRUMENTS_ID:
            FAT_screenInstrument_init();
            break;
        case SCREEN_FILESYSTEM_ID:
            FAT_screenFilesystem_init();

            break;
    }

    FAT_popup_moveSelectedScreenCursor();
}

/**
 * \brief Affiche l'écran d'aide correspondant à l'id passé en paramètres.
 * \param screenId le numéro d'écran actuellement consulté. 
 */
void FAT_showHelp(u8 screenId) {
    FAT_screenHelp_init(screenId);
}

/**
 * \brief Attendre la synchronisation du balayage vertical. 
 */
void FAT_waitVSync() {
    while (F_VCNT_CURRENT_SCANLINE < 160) {
    }
}

/**
 * \brief Permet de patienter un certain nombre de cycle de balayage vertical.
 * @param nbFrames le nombre de balayage à attendre.
 */
void FAT_wait(u32 nbFrames) {
    u32 i = 0;

    while (i++ < nbFrames)
        FAT_waitVSync();
}

/**
 * \brief Bloque le cpu un certain temps. 
 * 
 * Attention le temps n'est pas exprimé en secondes ! Il s'agit juste d'une variable:
 * plus elle est grande, plus le temps de blocage est long.
 * 
 * @param time variable pour définir le temps d'attente
 */
void FAT_blockCPU(u16 time) {
    u16 i = 0;
    while (i++ < time) {
        // CPU bloqué
    }
}

#endif

