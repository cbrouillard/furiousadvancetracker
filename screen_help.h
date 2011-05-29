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

// prototypes
void FAT_screenHelp_init(u8 screenIdForHelp);
void FAT_screenHelp_checkButtons();

/**
 * \brief Fonction principale de l'écran (callback). 
 */
void FAT_screenHelp_mainFunc() {
    if (mutex) {
        ham_CopyObjToOAM();
        if (iCanPressAKey) {
            FAT_screenHelp_checkButtons();
        }
    }
}

/**
 * \brief Initialisation de l'écran. 
 */
void FAT_screenHelp_init(u8 screenIdForHelp) {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    switch (screenIdForHelp) {
        case SCREEN_PROJECT_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_help_projet_Tiles, SIZEOF_16BIT(screen_help_projet_Tiles), 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_help_projet_Map, 1024, 0, 0);
            break;
        case SCREEN_LIVE_ID:
            break;
        case SCREEN_SONG_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_help_song_Tiles, SIZEOF_16BIT(screen_help_song_Tiles), 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_help_song_Map, 1024, 0, 0);
            break;
        case SCREEN_BLOCKS_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_help_blocks_Tiles, SIZEOF_16BIT(screen_help_blocks_Tiles), 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_help_blocks_Map, 1024, 0, 0);
            break;
        case SCREEN_NOTES_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_help_notes_Tiles, SIZEOF_16BIT(screen_help_notes_Tiles), 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_help_notes_Map, 1024, 0, 0);
            break;
        case SCREEN_EFFECTS_ID:
            break;
        case SCREEN_COMPOSER_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_help_composer_Tiles, SIZEOF_16BIT(screen_help_composer_Tiles), 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_help_composer_Map, 1024, 0, 0);
            break;
        case SCREEN_INSTRUMENTS_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_help_instrument_Tiles, SIZEOF_16BIT(screen_help_instrument_Tiles), 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_help_instrument_Map, 1024, 0, 0);
            break;
        case SCREEN_FILESYSTEM_ID:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_help_filesystem_Tiles, SIZEOF_16BIT(screen_help_filesystem_Tiles), 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_help_filesystem_Map, 1024, 0, 0);
            break;
    }
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    FAT_cursors_hideAllCursors();

    // démarrage du cycle pour l'écran
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_screenHelp_mainFunc);
    
    isHelpActivated = 1;
}

/**
 * \brief Cette fonction permet de tester les actions utilisateurs sur l'écran. 
 */
void FAT_screenHelp_checkButtons() {
    if (F_CTRLINPUT_SELECT_PRESSED) {
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

        if (F_CTRLINPUT_B_PRESSED) {
            iCanPressAKey = 0;
            isHelpActivated = 0;
            FAT_switchToScreen(FAT_currentScreen);
        }

        // TODO commit project cursor move
        FAT_keys_waitForAnotherKeyTouch();
    }
}

#endif	/* SCREEN_HELP_H */

