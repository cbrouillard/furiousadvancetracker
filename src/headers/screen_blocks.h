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
 * \file screen_blocks.h
 * \brief Fichier réservé pour la gestion de l'écran BLOCKS.
 */

#ifndef _SCREEN_BLOCKS_H_
#define _SCREEN_BLOCKS_H_

/** \brief Numéro du tiles ou l'affichage démarre (en case tile). */
#define SCREENBLOCKS_LINE_START_Y 2
/** \brief Début de l'affichage des blocks. */
#define SCREENBLOCKS_BLOCK_LINE_X 3
/** \brief Début de l'affichage du paramètre transpose. */
#define SCREENBLOCKS_TRANSPOSE_LINE_X 6
/** \brief Début de l'affichage de la commande assignée au block. */
#define SCREENBLOCKS_EFFECT_LINE_X 8
/** \brief Début de l'affichage des numéros de lignes. */
#define SCREENBLOCKS_LINE_X 0
/** \brief Nombre de blocks visibles à l'écran. */
#define SCREENBLOCKS_NB_LINES_ON_SCREEN 16
/**  \brief Taille en tiles d'un block (Y). */
#define SCREENBLOCKS_LINE_SIZE_Y 1

// ID des colonnes réprésentées par l'interface (ne compte pas la colonne du numéro de ligne)
/** \brief Id de la colonne des BLOCKS. Utile seulement pour la gestion du curseur. */
#define SCREENBLOCKS_COLUMN_ID_BLK 0
/** \brief Id de la colonne du transpose. Utile seulement pour la gestion du curseur. */
#define SCREENBLOCKS_COLUMN_ID_TSP 1
/** \brief Id de la colonne du nom de la commande. Utile seulement pour la gestion du curseur. */
#define SCREENBLOCKS_COLUMN_ID_CMD_NAME 2
/** \brief Id de la colonne de la valeur de la commande. Utile seulement pour la gestion du curseur. */
#define SCREENBLOCKS_COLUMN_ID_CMD_PARAM 3

u8 FAT_screenBlocks_getCurrentSequenceId ();
u8 FAT_screenBlocks_getCurrentSelectedLine();
void FAT_screenBlocks_setCurrentSelectedLine(u8 value);
u8 FAT_screenBlocks_getCurrentSelectedColumn();
void FAT_screenBlocks_setCurrentSelectedColumn(u8 value);
void FAT_screenBlocks_incCurrentSelectedLine ();
void FAT_screenBlocks_decCurrentSelectedLine ();

void FAT_screenBlocks_printLineColumns();
void FAT_screenBlocks_printInfos();
void FAT_screenBlocks_printSequenceNumber();
void FAT_screenBlocks_printBlock(u8 line);
void FAT_screenBlocks_printTranspose(u8 line);
void FAT_screenBlocks_printEffect(u8 line);
void FAT_screenBlocks_printAllBlocks();
void FAT_screenBlocks_printAllScreenText();
void FAT_screenBlocks_init(u8 fromScreenId);
void FAT_screenBlocks_checkButtons();
void FAT_screenBlocks_pressB();
void FAT_screenBlocks_pressOrHeldA();

#include "cursors.h"
#include "fat.h"
#include "screen_blocks_cursor.h"

#endif
