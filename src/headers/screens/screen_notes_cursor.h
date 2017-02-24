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
 * \file screen_notes_cursor.h
 * \brief Fichier dédié à la gestion du curseur dans l'instrument NOTE.
 */

#ifndef _SCREEN_NOTES_CURSOR_H_
#define	_SCREEN_NOTES_CURSOR_H_

/** \brief Taille d'un block de 3 cases en pixels. */
#define SCREENNOTES_BLOCK3_SIZE_X 24
/** \brief Taille d'un block de 2 cases en pixels. */
#define SCREENNOTES_BLOCK2_SIZE_X 16
/** \brief Hauteur d'un block en pixels. */
#define SCREENNOTES_BLOCK_SIZE_Y 8

// paramètre de l'interface
/** \brief Espace blanc entre chaque donnée. */
#define SCREENNOTES_WHITE_SPACE_X 8
/** \brief Position en pixel du dernier bloc de note. */
#define SCREENNOTES_LAST_BLOCK_X 143
/** \brief Position en pixel du dernier bloc de note. */
#define SCREENNOTES_LAST_BLOCK_Y 135
/** \brief Position en pixel du premier bloc de note. */
#define SCREENNOTES_FIRST_BLOCK_X 24
/** \brief Position en pixel du premier bloc de note. */
#define SCREENNOTES_FIRST_BLOCK_Y 16

void FAT_screenNotes_initCursor();
void FAT_screenNotes_moveCursorRight();
void FAT_screenNotes_moveCursorLeft();
void FAT_screenNotes_moveCursorDown();
void FAT_screenNotes_moveCursorUp();
void FAT_screenNotes_commitCursorMove();
void FAT_screenNotes_moveCursorAllUp ();
void FAT_screenNotes_moveCursorAllDown ();

u8 FAT_screenNotes_getCurrentSelectedLine();
u8 FAT_screenNotes_getCurrentSelectedColumn();

#endif	/* SCREEN_NOTES_CURSOR_H */
