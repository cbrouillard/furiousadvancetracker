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
#define WAIT_FOR_START 50

/**
 * \brief Cette variable sert à gérer les contextes conflictuels (notamment dans les
 * boucles affichant du texte à gogo). 
 * 
 * Si le mutex est à zéro alors aucun affichage ne pourra avoir lieu.
 * 
 * Usage:
 * <code>void printBeaucoupTexte() {
 *      mutex = 0;
 *      print text1
 *      print text2
 *      mutex = 1;
 * }</code>
 * <b>NE PAS TOUCHER !</b>
 */
bool mutex = 1;

/** \brief Définition globale du format d'affichage des numéros de lignes. */
#define FAT_FORMAT_LINE "%.2x\0"

/** \brief Stocke l'id de l'écran sur lequel l'utilisateur se situe. */
u8 FAT_currentScreen = SCREEN_SONG_ID;

void FAT_initSpritePalette();
void FAT_initScreenPalette();
void FAT_switchToScreen(u8 screenId);
void FAT_reinitScreen();
void FAT_forceClearTextLayer();
void FAT_waitVSync();
void FAT_blockCPU(u16 time);

#include "gfx.h"

#include "data.h"
#include "filesystem.h"
#include "cursors.h"

/**
 * \brief Permet de savoir si l'utilisateur a le droit d'appuyer sur une touche
 */
u8 iCanPressAKey = 1;

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


/**
 * \brief Compteur pour décompter le temps d'attente entre 2 appuis de la touche START.
 */
u16 waitForStart = 0;

/**
 * \brief Fonction attachée à un timer permettant de resetter la possibilités d'appuyer
 * sur une touche. 
 */
void FAT_player_timerFunc_iCanPressAKey();

/**
 * \brief Cette fonction déclanche le timer permettant d'attendre élégamment un temps
 * donné avant d'autoriser la répétition d'une touche. 
 */
void FAT_keys_waitForAnotherKeyTouch();

/**
 * \brief Permet de savoir si le player est en train de jouer la chanson.
 */
bool FAT_isCurrentlyPlaying = 0;

#include "popup.h"
#include "yesno_dialog.h"
#include "screen_song.h"
#include "screen_filesystem.h"
#include "screen_project.h"
#include "screen_live.h"
#include "screen_composer.h"
#include "screen_blocks.h"
#include "screen_notes.h"
#include "screen_instrument.h"
#include "screen_effects.h"

#include "player.h"

/**
 * \brief Fonction callback associée avec un TIMER: permet de décompter le temps
 * d'attente pour l'appui sur une touche. 
 */
void FAT_player_timerFunc_iCanPressAKey() {
    waitForStart++;
    if (waitForStart >= (WAIT_FOR_START + FAT_tracker.keyRepeat) && !iCanPressAKey) {
        iCanPressAKey = 1;
        waitForStart = 0;
        M_TIM2CNT_IRQ_DISABLE
        M_TIM2CNT_TIMER_STOP
#ifdef DEBUG_ON
                ham_DrawText(21, 16, "KEY ON ");
#endif
    }
}

/**
 * \brief Cette fonction déclanche le timer permettant d'attendre élégamment un temps
 * donné avant d'autoriser la répétition d'une touche. 
 */
void FAT_keys_waitForAnotherKeyTouch() {
#ifdef DEBUG_ON
    ham_DrawText(21, 16, "KEY OFF");
#endif
    if (!iCanPressAKey) {
        ham_StartIntHandler(INT_TYPE_TIM2, (void*) &FAT_player_timerFunc_iCanPressAKey);

        R_TIM2CNT = 0;
        M_TIM2CNT_IRQ_ENABLE
        M_TIM2CNT_TIMER_START
    }
}

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
    
    FAT_filesystem_checkFs ();

    ham_SetBgMode(0);
    ham_InitText(1);
    ham_SetTextCol(TEXT_COLOR, 0);

    ham_SetFxMode(FX_LAYER_SELECT(0, 0, 0, 0, 1, 0),
            FX_LAYER_SELECT(0, 0, 1, 1, 0, 0),
            FX_MODE_ALPHABLEND);
    ham_SetFxAlphaLevel(7, 7);

    // initialisation des palettes.
    FAT_initScreenPalette();
    FAT_initSpritePalette();

    // initialisation de l'écran "Popup" (la map de déplacement)
    FAT_popup_init();
    // initialisation du layer Dialog

    // initialisation des curseurs
    FAT_initCursor1();
    FAT_initCursor2();
    FAT_initCursor3();
    FAT_initCursor8();
    FAT_initCursorChange();
    FAT_initCursorLoad();
    FAT_initCursorSave();
    FAT_popup_initCursors();
    FAT_screenInstrument_tabCursorInit();

    FAT_player_initCursors();
    //FAT_cursors_initCursorsChannel ();

    // chargement des sprites pour l'écran instrument
    FAT_screenInstrument_initSpritesForInstrument();

    FAT_screenSong_initCursor();
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
    ham_LoadBGPal((void*) intro_Palette, 256);
}

/**
 * \brief Méthode pour afficher un simple écran "titre" avec une boucle infinie en
 * attente du bouton "START". 
 */
void FAT_showIntro() {
    FAT_reinitScreen();

    // jouer un petit son d'exemple
    snd_tmp_playSampleTest();

    FAT_initIntroPalette();

    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_intro_Tiles, SIZEOF_16BIT(screen_intro_Tiles), 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_intro_Map, 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 0, 0);
#ifdef DEBUG_ON
    ham_DrawText(1, 15, "DEBUG ON");
    ham_DrawText(1, 16, "SIZE %d octets", (sizeof (tracker)));
#endif
    ham_DrawText(1, 19, "version %s", FAT_VERSION);
    while (!F_CTRLINPUT_START_PRESSED && !F_CTRLINPUT_A_PRESSED && !F_CTRLINPUT_B_PRESSED
            && !F_CTRLINPUT_DOWN_PRESSED && !F_CTRLINPUT_LEFT_PRESSED && !F_CTRLINPUT_RIGHT_PRESSED && !F_CTRLINPUT_UP_PRESSED
            && !F_CTRLINPUT_L_PRESSED && !F_CTRLINPUT_R_PRESSED
            && !F_CTRLINPUT_SELECT_PRESSED) {
    }

    ham_InitBg(SCREEN_LAYER, 0, 3, 0);
    FAT_initScreenPalette();
}

/**
 * \brief Méthode qui permet de réinitialiser le BG2 proprement. 
 * 
 * <b>NE PAS TOUCHER !  </b>
 */
void FAT_reinitScreen() {
    if (ham_bg[SCREEN_LAYER].ti) {
        //        ham_InitBg(2, 0, 3, 0);
        ham_DeInitTileSet(ham_bg[SCREEN_LAYER].ti);
        ham_DeInitMapSet(ham_bg[SCREEN_LAYER].mi);
    }
    FAT_forceClearTextLayer();
}

/**
 * \brief Méthode à réfactorer : effacer l'écran texte en affichant des espaces partout. 
 * 
 * Performance warning ! Afficher du texte via HAM est lent !
 */
void FAT_forceClearTextLayer() {
    mutex = 0;
    for (u8 l = 1; l < 20; l++) {
        ham_DrawText(0, l, "                              ");
    }
    mutex = 1;
}

/**
 * \brief La palette pour l'écran d'introduction est différente: cette fonction la charge au bon endroit.
 */
void FAT_initSpritePalette() {
    ham_LoadObjPal((void*) sprite_Palette, 256);
}

/**
 * \brief Charge la palette pour les écrans: les sprites sont exclus. 
 */
void FAT_initScreenPalette() {
    ham_LoadBGPal((void*) screen_Palette, 256);
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

