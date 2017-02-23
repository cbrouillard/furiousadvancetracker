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
 * \file screen_live.h
 * \brief Fichier contenant toutes les fonctions pour gérer l'écran LIVE.
 */

#ifndef _SCREEN_LIVE_H_
#define _SCREEN_LIVE_H_

/** \brief Le nombre maximal de ligne affichées à l'écran. */
#define SCREENLIVE_NB_LINES_ON_SCREEN 10
/** \brief Définition interface : numéro de la tile pour début de l'affichage (Y). */
#define SCREENLIVE_LINE_START_Y 2
/** \brief Définition interface : numéro de la tile pour début de l'affichage des lignes ! (X). */
#define SCREENLIVE_LINE_X 0
/** \brief Définition interface : taille que prend une ligne en tile (1). */
#define SCREENLIVE_LINE_SIZE_Y 1
/** \brief Définition interface : numéro de la tile pour début de l'affichage des séquences (X). */
#define SCREENLIVE_SEQUENCE_LINE_X 3

void FAT_screenLive_printTempo();
void FAT_screenLive_printTranspose();
void FAT_screenLive_printLiveMode();
void FAT_screenLive_printVolumes();
void FAT_screenLive_printTransposes();
void FAT_screenLive_printLineColumns();
void FAT_screenLive_printInfos();
void FAT_screenLive_printSequence(u8 channel, u8 lineOnScreen, u8 realLine);
void FAT_screenLive_printSequences();
void FAT_screenLive_printAllScreenText();
void FAT_screenLive_init();
void FAT_screenLive_applyBufferIfNeeded();
void FAT_screenLive_checkButtons();
void FAT_screenLive_pressOrHeldA_inSequencer();
void FAT_screenLive_pressOrHeldA_inDataTable();
void FAT_screenLive_changeVolume (u8 channel, s8 addedValue);
void FAT_screenLive_changeTranspose (u8 channel, s8 addedValue);
void FAT_screenLive_changeAllVolumes (s8 addedValue);
void FAT_screenLive_changeAllTransposes (s8 addedValue);
void FAT_screenLive_setAllVolumes (u8 value);
u8 FAT_screenLive_getCurrentStartLine ();
void FAT_screenLive_setCurrentStartLine (u8 value);
void FAT_screenLive_incCurrentStartLine(u8 add);
void FAT_screenLive_decCurrentStartLine(u8 remove);

#include "cursors.h"
#include "fat.h"
#include "screen_live_cursor.h"

#endif
