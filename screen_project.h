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

/** \brief Petit tableau pour stocker les chaines YES et NOP. */
const char* yesOrNo[2] = {"NOP\0", "YES\0"};

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
        ham_CopyObjToOAM();
        if (iCanPressAKey) {
            FAT_screenProject_checkButtons();
        }
    }
}

/**
 * \brief Affiche les infos du projet sur l'écran. 
 */
void FAT_screenProject_printInfos() {
    mutex = 0;
    ham_DrawText(1, 4, "TEMPO     %3d", FAT_tracker.tempo);
    ham_DrawText(1, 5, "TRANSPOSE %.2x", FAT_tracker.transpose);
    ham_DrawText(1, 8, "KEYREPEAT %.2x", FAT_tracker.keyRepeat);
    ham_DrawText(1, 9, "PREVIEW   %.3s", yesOrNo[FAT_tracker.previewEnable != 0]);
    ham_DrawText(1, 12, "NEW  PRJ  OK");
    ham_DrawText(1, 13, "SAVE PRJ  OK");
    ham_DrawText(1, 14, "LOAD PRJ  OK");
    
    ham_DrawText(1, 1, "FAT PROJECT v%s", FAT_VERSION);
    mutex = 1;
}

/**
 * \brief Affiche des informations relatives au projet (comme la taille en sav, 
 * le nombre de fois enregistré, ...) 
 */
void FAT_screenProject_printProject (){
    mutex = 0;
    ham_DrawText(16, 3, "Name %.8s", FAT_tracker.songName);
    ham_DrawText(16, 4, "size %.4x", sizeof (FAT_tracker));
    ham_DrawText (16,5, "work %.2x", FAT_tracker.nbWork);
    mutex = 1;
    
}

/**
 * \brief Fonction d'initialisation de l'écran. 
 */
void FAT_screenProject_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_projet_Tiles, SIZEOF_16BIT(screen_projet_Tiles), 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_projet_Map, 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    // affichage d'un peu de texte
    FAT_screenProject_printInfos();
    FAT_screenProject_printProject ();

    // cache quelques curseurs
    FAT_cursors_hideCursor8();
    
    // init du curseur
    FAT_screenProject_initCursor();
    FAT_screenProject_displayGoodCursor();
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

        FAT_popup_checkButtons();

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

        if (F_CTRLINPUT_A_PRESSED) {
            FAT_screenProject_pressA();
        } else {

            if (F_CTRLINPUT_START_PRESSED) {
                iCanPressAKey = 0;
                if (!FAT_isCurrentlyPlaying) {
                    FAT_player_startPlayerFromSequences(FAT_screenSong_currentSelectedLine);
                } else {
                    FAT_player_stopPlayer();
                }
            }
            
            if (F_CTRLINPUT_R_PRESSED && F_CTRLINPUT_L_PRESSED){
                iCanPressAKey = 0;
                FAT_showHelp(SCREEN_PROJECT_ID);
            }

            if (F_CTRLINPUT_RIGHT_PRESSED) {
                iCanPressAKey = 0;
            }

            if (F_CTRLINPUT_LEFT_PRESSED) {
                iCanPressAKey = 0;
            }

            if (F_CTRLINPUT_DOWN_PRESSED) {
                iCanPressAKey = 0;
                FAT_screenProject_moveCursorDown();
            }

            if (F_CTRLINPUT_UP_PRESSED) {
                iCanPressAKey = 0;
                FAT_screenProject_moveCursorUp();
            }

            FAT_screenProject_commitCursorMove();
        }

        FAT_keys_waitForAnotherKeyTouch();
    }
}

/**
 * \brief Cette fonction est dédiée à la gestion de l'interaction avec la touche A. 
 */
void FAT_screenProject_pressA() {
    s8 addedValue = 0;
    if (F_CTRLINPUT_LEFT_PRESSED) {
        iCanPressAKey = 0;
        addedValue = -1;
    }

    if (F_CTRLINPUT_RIGHT_PRESSED) {
        iCanPressAKey = 0;
        addedValue = 1;
    }

    if (F_CTRLINPUT_UP_PRESSED) {
        iCanPressAKey = 0;
        addedValue = 16;
    }

    if (F_CTRLINPUT_DOWN_PRESSED) {
        iCanPressAKey = 0;
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
        case 5:
            // TODO afficher la boite de dialogue
            //FAT_yesno_show(DIALOG_SAVE);
            //FAT_data_project_save();
            iCanPressAKey = 0;
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_screenFilesystem_setMode (FILESYSTEM_MODE_SAVE);
            FAT_switchToScreen(SCREEN_FILESYSTEM_ID);
            break;
        case 6:
            // TODO afficher la boite de dialogue
            //FAT_yesno_show(DIALOG_LOAD);
            //            FAT_data_project_load();
            iCanPressAKey = 0;
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_screenFilesystem_setMode (FILESYSTEM_MODE_LOAD);
            FAT_switchToScreen(SCREEN_FILESYSTEM_ID);
            break;
        case 2:
            FAT_data_project_changeKeyRepeat(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 3:
            FAT_data_project_changePreview(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 4:
            FAT_yesno_show(DIALOG_NEW);
            break;
    }

}

#endif
