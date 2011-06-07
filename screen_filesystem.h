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
 * \file screen_filesystem.h
 * \brief Ce fichier contient toutes les fonctions utiles pour la gestion de l'écran filesystem.
 */

#ifndef _SCREEN_FILESYSTEM_H_
#define _SCREEN_FILESYSTEM_H_

#define FILESYSTEM_MODE_SAVE 0
#define FILESYSTEM_MODE_LOAD 1

/** \brief Numéro de case ou l'affichage des notes démarre. */
#define SCREENFILESYSTEM_LINE_START_Y 2
/** \brief Nombre total de notes affichées sur l'écran. */
#define SCREENFILESYSTEM_NB_LINES_ON_SCREEN 16
/** \brief Numéro de case ou l'affichage des numéros de ligne démarre. */
#define SCREENFILESYSTEM_LINE_X 0
/** \brief Numéro de case ou l'affichage des noms des tracks démarre. */
#define SCREENFILESYSTEM_LINE_TRACKNAME_X 3

/** \brief Permet de savoir si la popup est affichée au dessus de l'écran ou non. */
bool FAT_screenFilesystem_isPopuped = 0;
/** \brief Quel est le mode actuel pour l'écran filesystem ? LOAD/SAVE */
u8 FAT_filesystem_actualMode = FILESYSTEM_MODE_SAVE;

/** \brief Chaines de caractères pour représenter le mode actuel de l'écran filesystem. */
const char* modes[2] = {"SAVE", "LOAD"};

// prototypes
void FAT_screenFilesystem_init();
void FAT_screenFilesystem_checkButtons();
void FAT_screenFilesystem_printInfos();
void FAT_screenFilesystem_pressA();

#include "screen_filesystem_cursor.h"

/**
 * \brief Fonction principale de l'écran (callback). 
 */
void FAT_screenFilesystem_mainFunc() {
    if (mutex) {
        ham_CopyObjToOAM();
        if (iCanPressAKey) {
            FAT_screenFilesystem_checkButtons();
        }
    }
}

/**
 * \brief Change le mode pour l'écran filesystem.
 * @param modeId
 */
void FAT_screenFilesystem_setMode(u8 modeId) {
    FAT_filesystem_actualMode = modeId;
}

/**
 * \brief Affiche le mode sur la partie droite de l'interface. 
 */
void FAT_screenFilesystem_printMode() {
    mutex = 0;
    ham_DrawText(16, 3, "Mode %s", modes[FAT_filesystem_actualMode]);
    mutex = 1;
}

/**
 * \brief Cette fonction se content d'imprimer le numéro de ligne sur la partie
 * gauche de l'interface. 
 */
void FAT_screenFilesystem_printLineColumns() {
    mutex = 0;
    u8 y = SCREENFILESYSTEM_LINE_START_Y;
    for (int c = 0; c < (SCREENFILESYSTEM_NB_LINES_ON_SCREEN); c++) {
        ham_DrawText(SCREENFILESYSTEM_LINE_X, y, FAT_FORMAT_LINE, c);
        y += 1;
    }
    mutex = 1;
}

/**
 * \brief Affiche tous les noms des chansons déjà enregistrées. 
 */
void FAT_screenFilesystem_printAllTracksName() {
    mutex = 0;
    u8 track = 0;
    u8 y = SCREENFILESYSTEM_LINE_START_Y;
    while (track < MAX_TRACKS) {
        ham_DrawText(SCREENFILESYSTEM_LINE_TRACKNAME_X, y, "%.8s %.2x", FAT_filesystem_getTrackName(track),
                FAT_filesystem_getTrackNbWork(track));
        track++;
        y++;
    }

    mutex = 1;
}

/**
 * \brief Affiche quelques informations comme le numéro de ligne actuelle, le nom de la chanson
 * sélectionnée, ... 
 */
void FAT_screenFilesystem_printInfos() {
    mutex = 0;
    ham_DrawText(16, 5, "line %.2x", FAT_screenFilesystem_currentSelectedLine);
    ham_DrawText(16, 6, "Name %.8s", FAT_filesystem_getTrackName(FAT_screenFilesystem_currentSelectedLine));
    ham_DrawText(16, 7, "size %.4x", FAT_filesystem_getTrackSizeChecked(FAT_screenFilesystem_currentSelectedLine));
    ham_DrawText(16, 8, "work %.2x", FAT_filesystem_getTrackNbWork(FAT_screenFilesystem_currentSelectedLine));
    mutex = 1;
}

/**
 * \brief Initialisation de l'écran. 
 */
void FAT_screenFilesystem_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_filesystem_Tiles, SIZEOF_16BIT(screen_filesystem_Tiles), 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_filesystem_Map, 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    // affichage d'un peu de texte
    FAT_screenFilesystem_printLineColumns();
    FAT_screenFilesystem_printAllTracksName();
    FAT_screenFilesystem_printMode();
    FAT_screenFilesystem_printInfos();

    // affichage des curseurs
    FAT_cursors_showCursor8();
    FAT_cursors_showCursor2();
    FAT_screenFilesystem_commitCursorMove();
}

/**
 * \brief Cette fonction permet de tester les actions utilisateurs sur l'écran. 
 */
void FAT_screenFilesystem_checkButtons() {
    if (F_CTRLINPUT_SELECT_PRESSED) {
        if (!FAT_screenFilesystem_isPopuped) {
            FAT_cursors_hideCursor8();
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenFilesystem_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenFilesystem_isPopuped) {
            FAT_popup_hide();
            FAT_cursors_showCursor8();
            FAT_cursors_showCursor2();
            FAT_screenFilesystem_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_FILESYSTEM_ID) {
                // TODO hide project cursor
                FAT_cursors_hideCursor8();
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (F_CTRLINPUT_R_PRESSED && F_CTRLINPUT_L_PRESSED) {
            iCanPressAKey = 0;
            FAT_showHelp(SCREEN_FILESYSTEM_ID);
        }

        if (F_CTRLINPUT_RIGHT_PRESSED) {
            iCanPressAKey = 0;
        }

        if (F_CTRLINPUT_LEFT_PRESSED) {
            iCanPressAKey = 0;
        }

        if (F_CTRLINPUT_DOWN_PRESSED) {
            iCanPressAKey = 0;
            FAT_screenFilesystem_moveCursorDown();
        }

        if (F_CTRLINPUT_UP_PRESSED) {
            iCanPressAKey = 0;
            FAT_screenFilesystem_moveCursorUp();
        }

        if (F_CTRLINPUT_A_PRESSED) {
            FAT_screenFilesystem_pressA();
        }

        FAT_screenFilesystem_commitCursorMove();

        // TODO commit project cursor move
        FAT_keys_waitForAnotherKeyTouch();
    }
}

/**
 * \brief Fonction dédicacée à la gestion de la touche A sur l'écran filesystem. 
 */
void FAT_screenFilesystem_pressA() {
    iCanPressAKey = 0;

    if (FAT_screenFilesystem_currentSelectedLine >= MAX_TRACKS_WITHOUT_COMPRESSION) {

        FAT_yesno_show(DIALOG_SORRY_SAVE);

    } else {

        switch (FAT_filesystem_actualMode) {
            case FILESYSTEM_MODE_LOAD:
                FAT_yesno_show(DIALOG_LOAD, FAT_screenFilesystem_currentSelectedLine);
                break;

            case FILESYSTEM_MODE_SAVE:
                FAT_yesno_show(DIALOG_SAVE, FAT_screenFilesystem_currentSelectedLine);
                break;
        }
    }
}

#endif
