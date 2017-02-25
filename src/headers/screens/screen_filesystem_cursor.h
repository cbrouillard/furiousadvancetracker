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
 * \file screen_filesystem_cursor.h
 * \brief Fichier dédié à la gestion du curseur dans l'écran filesystem.
 */


#ifndef _SCREEN_FILESYSTEM_CURSOR_H_
#define	_SCREEN_FILESYSTEM_CURSOR_H_

/** \brief Position en pixel du premier bloc. */
#define SCREENFILESYSTEM_FIRST_BLOCK_X 24
/** \brief Position en pixel du premier bloc d'action. */
#define SCREENFILESYSTEM_FIRST_ACTION_X 95
/** \brief Position en pixel du premier bloc. */
#define SCREENFILESYSTEM_FIRST_BLOCK_Y 16

/** \brief Position en pixel du dernier bloc. */
#define SCREENFILESYSTEM_LAST_BLOCK_Y 135
/** \brief Hauteur d'un block en pixels. */
#define SCREENFILESYSTEM_BLOCK_SIZE_Y 8

void FAT_screenFilesystem_initCursor();
void FAT_screenFilesystem_moveCursorDown();
void FAT_screenFilesystem_moveCursorUp();
void FAT_screenFilesystem_commitCursorMove();

u8 FAT_screenFilesystem_getCurrentSelectedLine();

#endif	/* SCREEN_FILESYSTEM_CURSOR_H */
