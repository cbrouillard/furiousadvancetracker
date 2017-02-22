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

#include "../soundApi/soundApi.h"

/**
 * \brief Version actuelle de FAT.
 */
#define FAT_VERSION "1.1.0"

#define POPUP_LAYER 0
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

#define SCREEN_DIALOG_ANY 100

/** \brief Position par défaut du curseur de changement d'onglet (partie instrument).*/
#define INPUT_R_CURSOR_CHANGE_X 216
/** \brief Position par défaut du curseur de changement d'onglet (partie instrument).*/
#define INPUT_R_CURSOR_CHANGE_Y 24

/** \brief Définition globale du format d'affichage des numéros de lignes. */
#define FAT_FORMAT_LINE "%.2x"

/** \brief Stocke l'id de l'écran sur lequel l'utilisateur se situe. */
u8 FAT_currentScreen = SCREEN_SONG_ID;

/** \brief Variable quasi temporaire afin de savoir si on a activé l'écran d'aide. */
u8 isHelpActivated = 0;

#define NB_OSC_NOTES_PER_SHAPE 12

void FAT_initSpritePalette();
void FAT_initScreenPalette();
void FAT_switchToScreen(u8 screenId, u8 fromId);
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

#include "../gfx/ResourceData.h"

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
void FAT_player_startPlayerFromLive_oneChannel(u8 line, u8 channel);

void FAT_player_stopPlayer_onlyOneColumn(u8 channel);
bool FAT_isChannelCurrentlyPlaying (u8 channel);

void FAT_player_moveOrHideCursor(u8 channel);
void FAT_player_hideAllCursors();

/**
 * \brief Permet de savoir si le player est en train de jouer la chanson.
 */
bool FAT_isCurrentlyPlaying = 0;
u8 FAT_live_nbChannelPlaying = 0;

/** \brief Repères pour le player: les valeurs dans les tableaux représentent des numéros de lignes (séquences). */
u8 actualSequencesForChannel[6];

/**
 * \brief Tableau constant de chaines utiles à l'affichage du paramètre output d'un instrument.
 */
const char* outputText [4] = {"  ", "L ", " R", "LR"};

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

void FAT_init ();
void FAT_initSpritePalette();
void FAT_initScreenPalette();

/**
 * \brief Méthode pour afficher un simple écran "titre" avec une boucle infinie en
 * attente du bouton "START".
 */
void FAT_showIntro() {

    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_INTRO_RAW), RES_INTRO_RAW_SIZE16, 1, 1);
    // Create a map for background
    hel_MapCreate(SCREEN_LAYER,        // Background number
                  32,   // width in tiles
                  20,   // height in tiles
                  ResData(RES_INTRO_MAP),   // Pointer to source MapData
                  sizeof(u16),                  // DataTypeSize of one element from Source MapData
                  MAP_FLAGS_DEFAULT);           // Flags to control map behaviour

    ham_InitBg(SCREEN_LAYER, 1, 3, FALSE);

    hel_BgTextPrintF(TEXT_LAYER, 23, 16, 0, "%.3dkits", snd_countAvailableKits());

    for (;;) {

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
void FAT_switchToScreen(u8 screenId, u8 fromId) {
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
            FAT_screenBlocks_init(fromId);
            break;
        case SCREEN_NOTES_ID:
            FAT_screenNotes_init(fromId);
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

#endif
