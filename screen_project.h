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
 * \file screen_project.h 
 * \brief Ce fichier contient toutes les fonctions utiles pour la gestion de l'écran 
 * project.
 */

#ifndef _SCREEN_PROJECT_H_
#define _SCREEN_PROJECT_H_

#include "screen_project_cursor.h"

/**
 * \brief Permet de savoir si la popup est affichée au dessus de l'écran.
 */
bool FAT_screenProject_isPopuped = 0;

// prototypes
void FAT_screenProject_checkButtons();
void FAT_screenProject_pressA();

/**
 * \brief Fonction principale de l'écran (callback). 
 */
void FAT_screenProject_mainFunc() {
    if (mutex) {
        speedCounter++;
        ham_CopyObjToOAM();
        FAT_screenProject_checkButtons();
    }
}

/**
 * \brief Affiche les infos du projet sur l'écran. 
 */
void FAT_screenProject_printInfos() {
    mutex = 0;
    ham_DrawText(1, 4, "TEMPO     %3d", FAT_tracker.tempo);
    ham_DrawText(1, 5, "TRANSPOSE %.2x", FAT_tracker.transpose);
    ham_DrawText(1, 8, "SAVE PRJ  OK");
    ham_DrawText(1, 9, "LOAD PRJ  OK");
    ham_DrawText(1, 1, "PROJECT: %s", FAT_tracker.songName);
    mutex = 1;
}

/**
 * \brief Fonction d'initialisation de l'écran. 
 */
void FAT_screenProject_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[2].ti = ham_InitTileSet((void*) screen_projet_Tiles, SIZEOF_16BIT(screen_projet_Tiles), 1, 1);
    ham_bg[2].mi = ham_InitMapSet((void *) screen_projet_Map, 1024, 0, 0);
    ham_InitBg(2, 1, 3, 0);

    // affichage d'un peu de texte
    FAT_screenProject_printInfos();

    // init du curseur
    FAT_screenProject_initCursor();
    FAT_screenProject_displayGoodCursor();

    // démarrage du cycle pour l'écran
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_screenProject_mainFunc);
}

/**
 * \brief Teste les actions utilisateurs sur l'écran. 
 */
void FAT_screenProject_checkButtons() {
    if (F_CTRLINPUT_SELECT_PRESSED) {
        if (!FAT_screenProject_isPopuped) {
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            FAT_popup_show();
            FAT_screenProject_isPopuped = 1;
        }

        if (speedCounter >= SLOWDOWN_COUNTER) {
            FAT_popup_checkButtons();
            speedCounter = 0;
        }

    } else {
        if (FAT_screenProject_isPopuped) {
            FAT_popup_hide();
            FAT_screenProject_displayGoodCursor();
            FAT_screenProject_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_PROJECT_ID) {
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor3();
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (speedCounter >= SLOWDOWN_COUNTER) {
            if (F_CTRLINPUT_A_PRESSED) {
                FAT_screenProject_pressA();
            } else {

                if (F_CTRLINPUT_START_PRESSED) {
                    if (!FAT_isCurrentlyPlaying) {
                        FAT_player_startPlayerFromSequences(FAT_screenSong_currentSelectedLine);
                    } else {
                        FAT_player_stopPlayer();
                    }
                }

                if (F_CTRLINPUT_RIGHT_PRESSED) {
                }

                if (F_CTRLINPUT_LEFT_PRESSED) {
                }

                if (F_CTRLINPUT_DOWN_PRESSED) {
                    FAT_screenProject_moveCursorDown();
                }

                if (F_CTRLINPUT_UP_PRESSED) {
                    FAT_screenProject_moveCursorUp();
                }

                FAT_screenProject_commitCursorMove();
            }

            speedCounter = 0;
        }
    }
}

/**
 * \brief Cette fonction est dédiée à la gestion de l'interaction avec la touche A. 
 */
void FAT_screenProject_pressA() {
    s8 addedValue = 0;
    if (F_CTRLINPUT_LEFT_PRESSED) {
        addedValue = -1;
    }

    if (F_CTRLINPUT_RIGHT_PRESSED) {
        addedValue = 1;
    }

    if (F_CTRLINPUT_UP_PRESSED) {
        addedValue = 16;
    }

    if (F_CTRLINPUT_DOWN_PRESSED) {
        addedValue = -16;
    }

    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
            FAT_data_project_changeTempo(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 1:
            FAT_data_project_changeTranspose(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 2:
            FAT_data_project_save();
            break;
        case 3:
            FAT_data_project_load();
            break;
    }

}

#endif
