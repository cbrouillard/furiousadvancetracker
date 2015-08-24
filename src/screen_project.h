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
void FAT_screenProject_pressOrHeldA();

/**
 * \brief Affiche les infos du projet sur l'écran. 
 */
void FAT_screenProject_printInfos() {
    hel_BgTextPrintF(TEXT_LAYER, 1, 4, 0, "Tempo     %3d", FAT_tracker.tempo);
    hel_BgTextPrintF(TEXT_LAYER, 1, 5, 0, "Transpose %.2x", FAT_tracker.transpose);
    hel_BgTextPrintF(TEXT_LAYER, 1, 8, 0, "KeyRepeat %.2x", FAT_tracker.keyRepeat);
    hel_BgTextPrintF(TEXT_LAYER, 1, 9, 0, "Preview   %.3s", yesOrNo[FAT_tracker.previewEnable != 0]);
    hel_BgTextPrintF(TEXT_LAYER, 1, 10, 0, "GreedPlay %.3s", yesOrNo[FAT_tracker.greedPlay != 0]);
    hel_BgTextPrintF(TEXT_LAYER, 1, 13, 0, "New  Prj  OK");
    hel_BgTextPrintF(TEXT_LAYER, 1, 14, 0, "Save Prj  OK");
    hel_BgTextPrintF(TEXT_LAYER, 1, 15, 0, "Load Prj  OK");

    hel_BgTextPrintF(TEXT_LAYER, 1, 1, 0, "FAT project v%s", FAT_VERSION);
}

/**
 * \brief Affiche des informations relatives au projet (comme la taille en sav, 
 * le nombre de fois enregistré, ...) 
 */
void FAT_screenProject_printProject() {
    hel_BgTextPrintF(TEXT_LAYER, 16, 3, 0, "Name %.8s", FAT_tracker.songName);
    hel_BgTextPrintF(TEXT_LAYER, 16, 4, 0, "Mem  %.d B", sizeof (FAT_tracker));
    hel_BgTextPrintF(TEXT_LAYER, 16, 5, 0, "Work %.2x", FAT_tracker.nbWork);

}

/**
 * \brief Fonction d'initialisation de l'écran. 
 */
void FAT_screenProject_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_PROJET_RAW), RES_SCREEN_PROJET_RAW_SIZE16, 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_PROJET_MAP), 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    // affichage d'un peu de texte
    FAT_screenProject_printInfos();
    FAT_screenProject_printProject();

    // cache quelques curseurs
    FAT_cursors_hideCursor8();

    // init du curseur
    FAT_player_hideAllCursors ();
    FAT_screenProject_initCursor();
    FAT_screenProject_displayGoodCursor();
}

/**
 * \brief Teste les actions utilisateurs sur l'écran. 
 */
void FAT_screenProject_checkButtons() {
    hel_PadCapture();
    
    if (hel_PadQuery()->Held.Select) {
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

        if (hel_PadQuery()->Held.A || hel_PadQuery()->Pressed.A) {
            FAT_screenProject_pressOrHeldA();
        } else {

            if (hel_PadQuery()->Pressed.Start) {
                if (!FAT_isCurrentlyPlaying) {
                    FAT_player_startPlayerFromSequences(FAT_screenSong_currentSelectedLine);
                } else {
                    FAT_player_stopPlayer();
                }
            }

            if (hel_PadQuery()->Pressed.R && hel_PadQuery()->Pressed.L) {
                FAT_showHelp(SCREEN_PROJECT_ID);
            }

            if (hel_PadQuery()->Pressed.Right) {
            }

            if (hel_PadQuery()->Pressed.Left) {
            }

            if (hel_PadQuery()->Pressed.Down) {
                FAT_screenProject_moveCursorDown();
            }

            if (hel_PadQuery()->Pressed.Up) {
                FAT_screenProject_moveCursorUp();
            }

            FAT_screenProject_commitCursorMove();
        }
    }
}

/**
 * \brief Cette fonction est dédiée à la gestion de l'interaction avec la touche A. 
 */
void FAT_screenProject_pressOrHeldA() {
    s8 addedValue = 0;
    if (hel_PadQuery()->Pressed.Left) {
        addedValue = -1;
    }

    if (hel_PadQuery()->Pressed.Right) {
        addedValue = 1;
    }

    if (hel_PadQuery()->Pressed.Up) {
        addedValue = 16;
    }

    if (hel_PadQuery()->Pressed.Down) {
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
            FAT_data_project_changeKeyRepeat(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 3:
            FAT_data_project_changePreview(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 4:
            FAT_data_project_changeGreedPlay(addedValue);
            FAT_screenProject_printInfos();
            break;
        case 5:
            FAT_yesno_show(DIALOG_NEW);
            break;
        case 6:
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_screenFilesystem_setMode(FILESYSTEM_MODE_SAVE);
            FAT_switchToScreen(SCREEN_FILESYSTEM_ID);
            break;
        case 7:
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_screenFilesystem_setMode(FILESYSTEM_MODE_LOAD);
            FAT_switchToScreen(SCREEN_FILESYSTEM_ID);
            break;



    }

}

#endif
