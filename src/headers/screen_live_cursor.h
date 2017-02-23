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
 * \file screen_song_cursor.h
 * \brief Ce fichier contient toutes les définitions de fonctions utiles pour la gestion
 * du curseur sur l'écran SONG.
 */

#ifndef _SCREENLIVECURSOR_H_
#define _SCREENLIVECURSOR_H_

/** \brief Taille d'un bloc d'affichage séquence 16*8 en pixels. */
#define SCREENLIVE_BLOCK_SIZE_X 16
/** \brief Taille d'un bloc d'affichage séquence 16*8 en pixels. */
#define SCREENLIVE_BLOCK_SIZE_Y 8

// paramètre de l'interface
/** \brief Espace définit entre chaque colonne (px). */
#define SCREENLIVE_WHITE_SPACE_X 8
/** \brief Coordonnée du dernier bloc en bas à droite de l'écran (px). */
#define SCREENLIVE_LAST_BLOCK_X 143
/** \brief Absisse du dernier bloc en bas à droite de l'écran (px). */
#define SCREENLIVE_LAST_BLOCK_Y 87
/** \brief Coordonnée du premier bloc en haut à gauche (px). */
#define SCREENLIVE_FIRST_BLOCK_X 24
/** \brief Abscisse du premier bloc en haut à gauche (px). */
#define SCREENLIVE_FIRST_BLOCK_Y 16

/** \brief Abscisse du premier bloc de données inscrites dans la table (partie basse de l'écran). */
#define SCREENLIVE_FIRST_TABLE_DATA_Y 104

#define SCREEN_LIVE_MODE_BLOCK_X 48
#define SCREEN_LIVE_TEMPO_BLOCK_X 120

void FAT_screenLive_initCursor();
void FAT_screenLive_moveCursorRight();
void FAT_screenLive_moveCursorLeft();
void FAT_screenLive_movePageDown();
void FAT_screenLive_moveCursorAllDown();
void FAT_screenLive_moveCursorDown();
void FAT_screenLive_movePageUp();
void FAT_screenLive_moveCursorAllUp();
void FAT_screenLive_moveCursorUp();
void FAT_screenLive_switchCursorToPart (bool part);
void FAT_screenLive_commitCursorMove();
void FAT_screenLive_switchActivePart(bool part);

bool FAT_screenLive_getIsCursorInSequencer ();
u8 FAT_screenLive_getCurrentSelectedLine();
u8 FAT_screenLive_getCurrentSelectedColumn();
u8 FAT_screenLive_getCurrentTableSelectedLine();

#include "screen_live.h"

#endif
