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

#ifndef _CURSOR_H_
#define _CURSOR_H_

/** \brief Taille d'un bloc d'affichage séquence 16*8 en pixels. */
#define SCREENSONG_BLOCK_SIZE_X 16
/** \brief Taille d'un bloc d'affichage séquence 16*8 en pixels. */
#define SCREENSONG_BLOCK_SIZE_Y 8

// paramètre de l'interface
/** \brief Espace définit entre chaque colonne (px). */
#define SCREENSONG_WHITE_SPACE_X 8
/** \brief Coordonnée du dernier bloc en bas à droite de l'écran (px). */
#define SCREENSONG_LAST_BLOCK_X 143
/** \brief Absisse du dernier bloc en bas à droite de l'écran (px). */
#define SCREENSONG_LAST_BLOCK_Y 135
/** \brief Coordonnée du premier bloc en haut à gauche (px). */
#define SCREENSONG_FIRST_BLOCK_X 24
/** \brief Abscisse du premier bloc en haut à gauche (px). */
#define SCREENSONG_FIRST_BLOCK_Y 16

void FAT_screenSong_initCursor();
void FAT_screenSong_moveCursorRight();
void FAT_screenSong_moveCursorLeft();
void FAT_screenSong_movePageDown();
void FAT_screenSong_moveCursorAllDown();
void FAT_screenSong_moveCursorDown();
void FAT_screenSong_movePageUp();
void FAT_screenSong_moveCursorAllUp();
void FAT_screenSong_moveCursorUp();
void FAT_screenSong_commitCursorMove();

u8 FAT_screenSong_getCurrentSelectedLine();
u8 FAT_screenSong_getCurrentSelectedColumn();

#include "screen_song.h"

#endif
