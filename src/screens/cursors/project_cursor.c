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
* \file project_cursor.c
* \brief Gestion du curseur sur l'écran projet.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../../headers/fat.h"

/**
 * \brief Tableau constant des positions des blocs de données sur l'écran.
 */
const u8 PROJECT_PULSE_BLOCK_Y[SCREENPROJECT_NB_LINES_ON_SCREEN] = {31, 39, 63, 71, 79, 103, 111, 119, 63};

/** \brief Position actuelle du curseur de sélection. */
u8 FAT_screenProject_cursorX;
/** \brief Position actuelle du curseur de sélection. */
u8 FAT_screenProject_cursorY;
/** \brief Numéro de ligne actuellement sélectionnée. */
u8 FAT_screenProject_currentSelectedLine;
u8 FAT_screenProject_getCurrentSelectedLine(){
  return FAT_screenProject_currentSelectedLine;
}
/** \brief Numéro de colonne actuellement sélectionnée. */
u8 FAT_screenProject_currentSelectedColumn;
u8 FAT_screenProject_getCurrentSelectedColumn(){
  return FAT_screenProject_currentSelectedColumn;
}

/**
 * \brief Cette fonction permet de valider le déplacement du curseur de sélection sur l'écran.
 */
void FAT_screenProject_commitCursorMove() {
    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
        case 3:
        case 4:
            FAT_cursors_moveCursor3 (FAT_screenProject_cursorX, FAT_screenProject_cursorY);
            break;
        case 8:
            FAT_cursors_moveCursor3 ((SCREENPROJECT_FIRST_BLOCK_X-1) + 120, FAT_screenProject_cursorY);
            break;
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
            FAT_cursors_moveCursor2 (FAT_screenProject_cursorX, FAT_screenProject_cursorY);
            break;
    }
}

/**
 * \brief Affiche le curseur à la bonne taille en fonction de la donnée actuellement sélectionnée.
 */
void FAT_screenProject_displayGoodCursor() {
    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
        case 3:
        case 4:
        case 8:
            FAT_cursors_hideCursor2();
            FAT_cursors_showCursor3();
            break;
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
            FAT_cursors_hideCursor3();
            FAT_cursors_showCursor2();
            break;

    }
}

/**
 * \brief Initialisation du curseur (position uniquement) et remise à zéro des
 * numéros de ligne et colonne sélectionnés.
 */
void FAT_screenProject_initCursor() {

    FAT_screenProject_cursorX = SCREENPROJECT_FIRST_BLOCK_X - 1;
    FAT_screenProject_cursorY = SCREENPROJECT_FIRST_BLOCK_Y - 1;

    FAT_screenProject_currentSelectedLine = 0;
    FAT_screenProject_currentSelectedColumn = 0;

    FAT_screenProject_commitCursorMove();
}

/**
 * \brief Déplace le curseur vers la droite.
 */
void FAT_screenProject_moveCursorRight() {
    FAT_screenProject_currentSelectedLine = 8;
    FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
    FAT_screenProject_displayGoodCursor();
}

/**
 * \brief Déplace le curseur vers la gauche.
 */
void FAT_screenProject_moveCursorLeft() {
    FAT_screenProject_currentSelectedLine = 2;
    FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
    FAT_screenProject_displayGoodCursor();
}

/**
 * \brief Déplace le curseur vers le bas.
 */
void FAT_screenProject_moveCursorDown() {

    if (FAT_screenProject_currentSelectedLine < SCREENPROJECT_NB_LINES_ON_SCREEN - 2) {
        if (!(FAT_screenProject_cursorY >= SCREENPROJECT_LAST_BLOCK_Y - 1)) {
            FAT_screenProject_currentSelectedLine++;
            FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
        }
    } else {
        FAT_screenProject_currentSelectedLine = 0;
        FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
    }
    FAT_screenProject_displayGoodCursor();

}

/**
 * \brief Déplace le curseur vers le haut.
 */
void FAT_screenProject_moveCursorUp() {
    if (FAT_screenProject_currentSelectedLine > 0) {
        if (!(FAT_screenProject_cursorY <= SCREENPROJECT_FIRST_BLOCK_Y - 1)) {
            FAT_screenProject_currentSelectedLine--;
            FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
        }
    }else {
        FAT_screenProject_currentSelectedLine = SCREENPROJECT_NB_LINES_ON_SCREEN - 2;
        FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
    }
    FAT_screenProject_displayGoodCursor();
}
