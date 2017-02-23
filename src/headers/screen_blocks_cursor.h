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
 * \file screen_blocks_cursor.h
 * \brief Fichier de gestion du curseur pour l'écran BLOCKS.
 */

#ifndef _SCREEN_BLOCKS_CURSOR_H_
#define	_SCREEN_BLOCKS_CURSOR_H_

/** \brief Taille d'un block. */
#define SCREENBLOCKS_BLOCK_SIZE_X 16
/** \brief Taille d'un block. */
#define SCREENBLOCKS_BLOCK_SIZE_Y 8

// paramètre de l'interface
/**
 * \brief Taille de l'espace entre chaque colonne de l'interface.
 */
#define SCREENBLOCKS_WHITE_SPACE_X 8
/** \brief Position du dernier block. */
#define SCREENBLOCKS_LAST_BLOCK_X 143
/** \brief Position du dernier block. */
#define SCREENBLOCKS_LAST_BLOCK_Y 135
/** \brief Position du premier block. */
#define SCREENBLOCKS_FIRST_BLOCK_X 24
/** \brief Position du premier block. */
#define SCREENBLOCKS_FIRST_BLOCK_Y 16

void FAT_screenBlocks_initCursor();
void FAT_screenBlocks_moveCursorRight();
void FAT_screenBlocks_moveCursorLeft();
void FAT_screenBlocks_moveCursorDown();
void FAT_screenBlocks_moveCursorUp();
void FAT_screenBlocks_commitCursorMove();
void FAT_screenBlocks_moveCursorAllUp ();
void FAT_screenBlocks_moveCursorAllDown ();

u8 FAT_screenBlocks_getCurrentSelectedLine();
u8 FAT_screenBlocks_getCurrentSelectedColumn();

#include "screen_blocks.h"

#endif	/* SCREEN_BLOCKS_CURSOR_H */
