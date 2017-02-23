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
* \file help.c
* \brief Ecran help.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../headers/screen_help.h"

/** \brief Permet de savoir si la popup est affichée au dessus de l'écran ou non. */
bool FAT_screenHelp_isPopuped = 0;

/** \brief Cette variable permet de savoir depuis quel écran l'aide à été appelée. */
u8 FAT_help_fromScreenId;

/**
 * \brief Initialisation de l'écran.
 */
void FAT_screenHelp_init(u8 screenIdForHelp) {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    switch (screenIdForHelp) {
        case SCREEN_PROJECT_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_PROJET_RAW), RES_SCREEN_HELP_PROJET_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_PROJET_MAP), 640, 0, 0);
            break;
        case SCREEN_SONG_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_SONG_RAW), RES_SCREEN_HELP_SONG_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_SONG_MAP), 640, 0, 0);
            break;
        case SCREEN_BLOCKS_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_BLOCKS_RAW), RES_SCREEN_HELP_BLOCKS_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_BLOCKS_MAP), 640, 0, 0);
            break;
        case SCREEN_NOTES_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_NOTES_RAW), RES_SCREEN_HELP_NOTES_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_NOTES_MAP), 640, 0, 0);
            break;
        case SCREEN_EFFECTS_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_EFFECTS_RAW), RES_SCREEN_HELP_EFFECTS_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_EFFECTS_MAP), 640, 0, 0);
            break;
        case SCREEN_COMPOSER_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_COMPOSER_RAW), RES_SCREEN_HELP_COMPOSER_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_COMPOSER_MAP), 640, 0, 0);
            break;
        case SCREEN_INSTRUMENTS_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_INSTRUMENT_RAW), RES_SCREEN_HELP_INSTRUMENT_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_INSTRUMENT_MAP), 640, 0, 0);
            break;
        case SCREEN_FILESYSTEM_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_FILESYSTEM_RAW), RES_SCREEN_HELP_FILESYSTEM_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_FILESYSTEM_MAP), 640, 0, 0);
            break;
        case SCREEN_LIVE_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_LIVE_RAW), RES_SCREEN_HELP_LIVE_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_LIVE_MAP), 640, 0, 0);
            break;
    }
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    FAT_player_hideAllCursors ();
    FAT_cursors_hideAllCursors();

    isHelpActivated = 1;
    FAT_currentScreen = SCREEN_HELP_ID;
    FAT_help_fromScreenId = screenIdForHelp;

    FAT_popup_hide();
}

/**
 * \brief Cette fonction permet de tester les actions utilisateurs sur l'écran.
 */
void FAT_screenHelp_checkButtons() {
    hel_PadCapture();

    if (hel_PadQuery()->Pressed.B) {
        isHelpActivated = 0;
        FAT_switchToScreen(FAT_help_fromScreenId, SCREEN_HELP_ID);
    }

}
