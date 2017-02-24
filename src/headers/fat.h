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

#define NB_OSC_NOTES_PER_SHAPE 12

/**
 * \brief Tableau constant de chaines utiles à l'affichage du paramètre output d'un instrument.
 */
extern const char* outputText [4];

extern u8 FAT_live_nbChannelPlaying;

void FAT_init();
void FAT_showHelp(u8 screenId);
void FAT_switchToScreen(u8 screenId, u8 fromId);
void FAT_mainLoop();
void FAT_allScreen_singleCheckButtons();
void FAT_forceClearTextLayer();
void FAT_reinitScreen();
void FAT_showIntro();
void VBLInterruptHandler(void);
void FAT_initScreenPalette() ;
void FAT_initSpritePalette();

u8 FAT_getCurrentScreen ();
void FAT_setCurrentScreen (u8 screen);
u8* FAT_getActualSequencesForChannel ();

#include "../soundApi/soundApi.h"
#include "../gfx/ResourceData.h"

#include "sprites/cursors.h"
#include "sprites/player_cursors.h"

#include "system/data.h"
#include "system/filesystem.h"
#include "system/player.h"

#include "dialogs/popup.h"
#include "dialogs/yesno.h"
#include "dialogs/keyboard.h"

#include "screens/screen_song.h"
#include "screens/screen_filesystem.h"
#include "screens/screen_project.h"
#include "screens/screen_live.h"
#include "screens/screen_composer.h"
#include "screens/screen_blocks.h"
#include "screens/screen_notes.h"
#include "screens/screen_instrument.h"
#include "screens/screen_effects.h"
#include "screens/screen_help.h"

#endif
