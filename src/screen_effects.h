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
 * \file screen_effects.h
 * \brief Ce fichier contient toutes les fonctions utiles pour la gestion de l'écran EFFECTS.
 * 
 * Cet écran est globalement similaire à celui des tables dans LSDJ.
 */

#ifndef _SCREEN_EFFECTS_H_
#define _SCREEN_EFFECTS_H_

/** \brief Permet de savoir si la popup est affichée au dessus de l'écran ou non. */
bool FAT_screenEffects_isPopuped = 0;

// prototypes
void FAT_screenEffects_init();
void FAT_screenEffects_checkButtons();

/**
 * \brief Initialisation de l'écran. 
 */
void FAT_screenEffects_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_EFFECTS_RAW), RES_SCREEN_EFFECTS_RAW_SIZE16, 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_EFFECTS_MAP), 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    // affichage d'un peu de texte


    FAT_player_hideAllCursors ();
    // démarrage du cycle pour l'écran
    //hel_IntrUpdateHandler(INT_TYPE_VBL, (void*) &FAT_screenEffects_mainFunc);
}

/**
 * \brief Cette fonction permet de tester les actions utilisateurs sur l'écran. 
 */
void FAT_screenEffects_checkButtons() {
    hel_PadCapture();

    if (hel_PadQuery()->Held.Select) {
        if (!FAT_screenEffects_isPopuped) {
            // TODO hide project cursor
            FAT_popup_show();
            FAT_screenEffects_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenEffects_isPopuped) {
            FAT_popup_hide();
            // TODO show project cursor
            FAT_screenEffects_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_EFFECTS_ID) {
                // TODO hide project cursor
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (hel_PadQuery()->Pressed.Right) {
        }

        if (hel_PadQuery()->Pressed.Left) {
        }

        if (hel_PadQuery()->Pressed.Down) {
        }

        if (hel_PadQuery()->Pressed.Up) {
        }

        if (hel_PadQuery()->Pressed.A || hel_PadQuery()->Held.A) {
        }

        // TODO commit project cursor move
    }
}

#endif
