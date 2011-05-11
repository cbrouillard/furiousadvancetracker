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
 * \file screen_live.h
 * \brief Fichier contenant toutes les fonctions pour gérer l'écran LIVE.
 */

#ifndef _SCREEN_LIVE_H_
#define _SCREEN_LIVE_H_

/** \brief Permet de savoir si la popup de déplacement est affichée au dessus de l'écran. */
bool FAT_screenLive_isPopuped = 0;

// prototypes
void FAT_screenLive_init();
void FAT_screenLive_checkButtons();

/**
 * \brief Fonction principale de l'écran (callback). 
 */
void FAT_screenLive_mainFunc() {
    if (mutex) {
        ham_CopyObjToOAM();
        if (iCanPressAKey) {
            FAT_screenLive_checkButtons();
        }
    }
}

/**
 * \brief Initialisation de l'écran. 
 */
void FAT_screenLive_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[2].ti = ham_InitTileSet((void*) screen_live_Tiles, SIZEOF_16BIT(screen_live_Tiles), 1, 1);
    ham_bg[2].mi = ham_InitMapSet((void *) screen_live_Map, 1024, 0, 0);
    ham_InitBg(2, 1, 3, 0);

    // affichage d'un peu de texte

    // démarrage du cycle pour l'écran
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_screenLive_mainFunc);
}

/**
 * \brief Teste les actions utilisateurs. 
 */
void FAT_screenLive_checkButtons() {
    if (F_CTRLINPUT_SELECT_PRESSED) {
        if (!FAT_screenLive_isPopuped) {
            // TODO hide project cursor
            FAT_popup_show();
            FAT_screenLive_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenLive_isPopuped) {
            FAT_popup_hide();
            // TODO show project cursor
            FAT_screenLive_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_LIVE_ID) {
                // TODO hide project cursor
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (F_CTRLINPUT_RIGHT_PRESSED) {
            iCanPressAKey = 0;
        }

        if (F_CTRLINPUT_LEFT_PRESSED) {
            iCanPressAKey = 0;
        }

        if (F_CTRLINPUT_DOWN_PRESSED) {
            iCanPressAKey = 0;
        }

        if (F_CTRLINPUT_UP_PRESSED) {
            iCanPressAKey = 0;
        }

        if (F_CTRLINPUT_A_PRESSED) {
            iCanPressAKey = 0;

        }

        // TODO commit project cursor move
        FAT_keys_waitForAnotherKeyTouch();
    }
}


#endif
