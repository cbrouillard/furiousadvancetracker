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
 * \file screen_song.h
 * \brief Ce fichier définit toutes les fonctions pour gérer l'écran SONG.
 */

#ifndef _SCREEN_SONG_H_
#define _SCREEN_SONG_H_

/** \brief Le nombre maximal de ligne affichées à l'écran. */
#define SCREENSONG_NB_LINES_ON_SCREEN 16
/** \brief Définition interface : numéro de la tile pour début de l'affichage (Y). */
#define SCREENSONG_LINE_START_Y 2
/** \brief Définition interface : numéro de la tile pour début de l'affichage des lignes ! (X). */
#define SCREENSONG_LINE_X 0
/** \brief Définition interface : taille que prend une ligne en tile (1). */
#define SCREENSONG_LINE_SIZE_Y 1
/** \brief Définition interface : numéro de la tile pour début de l'affichage des séquences (X). */
#define SCREENSONG_SEQUENCE_LINE_X 3

/** \brief Stocke tous les noms des channels (afin de pouvoir les afficher). */
extern const char* CHANNEL_NAME[6];

void FAT_screenSong_init();
void FAT_screenSong_printInfos();
void FAT_screenSong_printLineColumns();
void FAT_screenSong_printSequences();
void FAT_screenSong_printSequence(u8 channel, u8 lineOnScreen, u8 realLine);
void FAT_screenSong_printAllScreenText();
void FAT_screenSong_checkButtons();
void FAT_screenSong_pressB();
void FAT_screenSong_pressOrHeldA();

u8 FAT_screenSong_getCurrentStartLine ();
void FAT_screenSong_setCurrentStartLine (u8 value);
void FAT_screenSong_incCurrentStartLine(u8 add);
void FAT_screenSong_decCurrentStartLine(u8 remove);

#include "cursors.h"
#include "fat.h"
#include "screen_song_cursor.h"

#endif
