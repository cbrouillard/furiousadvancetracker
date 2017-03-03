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
#define SCREENPROJECT_NB_LINES_ON_SCREEN 10

void FAT_screenProject_commitCursorMove();
void FAT_screenProject_displayGoodCursor();
void FAT_screenProject_initCursor();
void FAT_screenProject_moveCursorRight();
void FAT_screenProject_moveCursorLeft();
void FAT_screenProject_moveCursorDown();
void FAT_screenProject_moveCursorUp();

u8 FAT_screenProject_getCurrentSelectedLine();
u8 FAT_screenProject_getCurrentSelectedColumn();

#endif	/* SCREEN_PROJECT_CURSOR_H */
