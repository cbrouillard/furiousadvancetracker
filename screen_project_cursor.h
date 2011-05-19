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
 * \file screen_project_cursor.h
 * \brief Ce fichier contient toutes les fonctions utiles pour la gestion du curseur de l'écran projet.
 */

#ifndef _SCREEN_PROJECT_CURSOR_H_
#define	_SCREEN_PROJECT_CURSOR_H_

/** \brief Position du premier bloc de donnée sur l'écran. */
#define SCREENPROJECT_FIRST_BLOCK_X 88
/** \brief Position du premier bloc de donnée sur l'écran. */
#define SCREENPROJECT_FIRST_BLOCK_Y 32
/** \brief Position du dernier bloc de donnée sur l'écran. */
#define SCREENPROJECT_LAST_BLOCK_Y 136

/** \brief Nombre de lignes affichées à l'écran. */
#define SCREENPROJECT_NB_LINES_ON_SCREEN 7

/** \brief Position actuelle du curseur de sélection. */
u8 FAT_screenProject_cursorX; 
/** \brief Position actuelle du curseur de sélection. */
u8 FAT_screenProject_cursorY;
/** \brief Numéro de ligne actuellement sélectionnée. */
u8 FAT_screenProject_currentSelectedLine;
/** \brief Numéro de colonne actuellement sélectionnée. */
u8  FAT_screenProject_currentSelectedColumn;

/**
 * \brief Tableau constant des positions des blocs de données sur l'écran. 
 */
const u8 PROJECT_PULSE_BLOCK_Y[SCREENPROJECT_NB_LINES_ON_SCREEN] = {31, 39, 63, 71, 95, 103, 111};

/**
 * \brief Cette fonction permet de valider le déplacement du curseur de sélection sur l'écran. 
 */
void FAT_screenProject_commitCursorMove() {
    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
        case 3:
            ham_SetObjXY(FAT_cursor3_obj, FAT_screenProject_cursorX, FAT_screenProject_cursorY);
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
            ham_SetObjXY(FAT_cursor2_obj, FAT_screenProject_cursorX, FAT_screenProject_cursorY);
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
            FAT_cursors_hideCursor2();
            FAT_cursors_showCursor3();
            break;
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
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
 * \brief Déplace le curseur vers le bas.
 */
void FAT_screenProject_moveCursorDown() {

    if (FAT_screenProject_currentSelectedLine < SCREENPROJECT_NB_LINES_ON_SCREEN - 1) {
        if (!(FAT_screenProject_cursorY >= SCREENPROJECT_LAST_BLOCK_Y - 1)) {
            FAT_screenProject_currentSelectedLine++;
            FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
        }
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
    }
    FAT_screenProject_displayGoodCursor();
}

#endif	/* SCREEN_PROJECT_CURSOR_H */

