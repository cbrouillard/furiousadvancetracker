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
void FAT_screenFilesystem_pressOrHeldA();

#include "screen_filesystem_cursor.h"


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
    hel_BgTextPrintF(TEXT_LAYER, 16, 3, 0, "Mode %s", modes[FAT_filesystem_actualMode]);
}

/**
 * \brief Cette fonction se content d'imprimer le numéro de ligne sur la partie
 * gauche de l'interface. 
 */
void FAT_screenFilesystem_printLineColumns() {
    u8 y = SCREENFILESYSTEM_LINE_START_Y;
    for (int c = 0; c < (SCREENFILESYSTEM_NB_LINES_ON_SCREEN); c++) {
        hel_BgTextPrintF(TEXT_LAYER, SCREENFILESYSTEM_LINE_X, y, 0, FAT_FORMAT_LINE, c);
        y += 1;
    }
}

/**
 * \brief Affiche tous les noms des chansons déjà enregistrées. 
 */
void FAT_screenFilesystem_printAllTracksName() {
    u8 track = 0;
    u8 y = SCREENFILESYSTEM_LINE_START_Y;
    while (track < MAX_TRACKS) {
        hel_BgTextPrintF(TEXT_LAYER, SCREENFILESYSTEM_LINE_TRACKNAME_X, y, 0, "%.8s %.2x", FAT_filesystem_getTrackName(track),
                FAT_filesystem_getTrackNbWork(track));
        track++;
        y++;
    }

}

/**
 * \brief Affiche quelques informations comme le numéro de ligne actuelle, le nom de la chanson
 * sélectionnée, ... 
 */
void FAT_screenFilesystem_printInfos() {
    hel_BgTextPrintF(TEXT_LAYER, 16, 5, 0, "Line %.2x", FAT_screenFilesystem_currentSelectedLine);
    hel_BgTextPrintF(TEXT_LAYER, 16, 6, 0, "Name %.8s", FAT_filesystem_getTrackName(FAT_screenFilesystem_currentSelectedLine));
    hel_BgTextPrintF(TEXT_LAYER, 16, 7, 0, "Size %.4x", FAT_filesystem_getTrackSizeChecked(FAT_screenFilesystem_currentSelectedLine));
    hel_BgTextPrintF(TEXT_LAYER, 16, 8, 0, "Work %.2x", FAT_filesystem_getTrackNbWork(FAT_screenFilesystem_currentSelectedLine));
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

    // démarrage du cycle pour l'écran
    //hel_IntrUpdateHandler(INT_TYPE_VBL, (void*) &FAT_screenFilesystem_mainFunc);
}

/**
 * \brief Cette fonction permet de tester les actions utilisateurs sur l'écran. 
 */
void FAT_screenFilesystem_checkButtons() {
    hel_PadCapture();

    if (hel_PadQuery()->Held.Select) {
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

        if (hel_PadQuery()->Pressed.R && hel_PadQuery()->Pressed.L) {
            FAT_showHelp(SCREEN_FILESYSTEM_ID);
        }

        if (hel_PadQuery()->Pressed.Right) {
        }

        if (hel_PadQuery()->Pressed.Left) {
        }

        if (hel_PadQuery()->Pressed.Down) {
            FAT_screenFilesystem_moveCursorDown();
        }

        if (hel_PadQuery()->Pressed.Up) {
            FAT_screenFilesystem_moveCursorUp();
        }

        if (hel_PadQuery()->Pressed.A) {
            FAT_screenFilesystem_pressOrHeldA();
        }

        FAT_screenFilesystem_commitCursorMove();
    }
}

/**
 * \brief Fonction dédicacée à la gestion de la touche A sur l'écran filesystem. 
 */
void FAT_screenFilesystem_pressOrHeldA() {

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
