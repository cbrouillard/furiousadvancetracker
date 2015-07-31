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
 * \file screen_help.h
 * \brief Ce fichier le code pour afficher TOUS les écrans d'aide.
 * 
 */

#ifndef _SCREEN_HELP_H_
#define	_SCREEN_HELP_H_

#include "fat.h"


/** \brief Permet de savoir si la popup est affichée au dessus de l'écran ou non. */
bool FAT_screenHelp_isPopuped = 0;

/** \brief Cette variable permet de savoir depuis quel écran l'aide à été appelée. */
u8 FAT_help_fromScreenId;

// prototypes
void FAT_screenHelp_init(u8 screenIdForHelp);
void FAT_screenHelp_checkButtons();

/**
 * \brief Initialisation de l'écran. 
 */
void FAT_screenHelp_init(u8 screenIdForHelp) {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    switch (screenIdForHelp) {
        case SCREEN_PROJECT_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_PROJET_RAW), RES_SCREEN_HELP_PROJET_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_PROJET_MAP), 1024, 0, 0);
            break;
        case SCREEN_SONG_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_SONG_RAW), RES_SCREEN_HELP_SONG_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_SONG_MAP), 1024, 0, 0);
            break;
        case SCREEN_BLOCKS_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_BLOCKS_RAW), RES_SCREEN_HELP_BLOCKS_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_BLOCKS_MAP), 1024, 0, 0);
            break;
        case SCREEN_NOTES_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_NOTES_RAW), RES_SCREEN_HELP_NOTES_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_NOTES_MAP), 1024, 0, 0);
            break;
        case SCREEN_EFFECTS_ID:
            break;
        case SCREEN_COMPOSER_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_COMPOSER_RAW), RES_SCREEN_HELP_COMPOSER_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_COMPOSER_MAP), 1024, 0, 0);
            break;
        case SCREEN_INSTRUMENTS_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_INSTRUMENT_RAW), RES_SCREEN_HELP_INSTRUMENT_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_INSTRUMENT_MAP), 1024, 0, 0);
            break;
        case SCREEN_FILESYSTEM_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_FILESYSTEM_RAW), RES_SCREEN_HELP_FILESYSTEM_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_FILESYSTEM_MAP), 1024, 0, 0);
            break;
        case SCREEN_LIVE_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_HELP_LIVE_RAW), RES_SCREEN_HELP_LIVE_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_HELP_LIVE_MAP), 1024, 0, 0);
            break;
    }
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    FAT_cursors_hideAllCursors();

    isHelpActivated = 1;
    FAT_currentScreen = SCREEN_HELP_ID;
    FAT_help_fromScreenId = screenIdForHelp;
}

/**
 * \brief Cette fonction permet de tester les actions utilisateurs sur l'écran. 
 */
void FAT_screenHelp_checkButtons() {
    hel_PadCapture();

    if (hel_PadQuery()->Held.Select) {
        if (!FAT_screenHelp_isPopuped) {
            // TODO hide project cursor
            FAT_popup_show();
            FAT_screenHelp_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenHelp_isPopuped) {
            FAT_popup_hide();
            // TODO show project cursor
            FAT_screenHelp_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_HELP_ID) {
                // TODO hide project cursor
                isHelpActivated = 0;
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (hel_PadQuery()->Pressed.B) {
            isHelpActivated = 0;
            FAT_switchToScreen(FAT_help_fromScreenId);
        }

    }
}

#endif	/* SCREEN_HELP_H */

