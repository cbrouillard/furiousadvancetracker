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
 * \file screen_notes.h
 * \brief Ce fichier contient toutes les fonctions utiles pour gérer l'écran NOTE.
 */

#ifndef _SCREEN_NOTES_H_
#define _SCREEN_NOTES_H_

/** \brief Numéro de case ou l'affichage des notes démarre. */
#define SCREENNOTES_LINE_START_Y 2
/** \brief Nombre total de notes affichées sur l'écran. */
#define SCREENNOTES_NB_LINES_ON_SCREEN 16
/** \brief Numéro de case ou l'affichage des numéros de ligne démarre. */
#define SCREENNOTES_LINE_X 0
/** \brief Numéro de case pour l'affichage des effets assignés aux notes. */
#define SCREENNOTES_EFFECT_LINE_X 10
/** \brief Taille d'une ligne. */
#define SCREENNOTES_LINE_SIZE_Y 1

/** \brief Numéro de case ou l'affichage des notes démarre. */
#define SCREENNOTES_NOTE_LINE_X 3

/** \brief Numéro de colonne représentant les notes. */
#define SCREENNOTES_COLUMN_ID_NOTES 0
/** \brief Numéro de colonne représentant les instruments. */
#define SCREENNOTES_COLUMN_ID_INST 1
/** \brief Numéro de colonne représentant les noms de commandes (effets). */
#define SCREENNOTES_COLUMN_ID_CMD_NAME 2
/** \brief Numéro de colonne représentant les valeurs de commandes (effets). */
#define SCREENNOTES_COLUMN_ID_CMD_PARAM 3

// prototypes
void FAT_screenNotes_init(u8 fromScreenId);
void FAT_screenNotes_printAllScreenText();
void FAT_screenNotes_checkButtons();
void FAT_screenNotes_printLineColumns();
void FAT_screenNotes_pressOrHeldA();
void FAT_screenNotes_pressB();
void FAT_screenNotes_printInfos();
void FAT_screenNotes_printBlockNumber();
void FAT_screenNotes_printAllNotes();
void FAT_screenNotes_printEffect(u8 line);
void FAT_screenNotes_printNote(u8 line);
void FAT_screenNotes_printLineColumns();

#include "cursors.h"
#include "fat.h"
#include "screen_notes_cursor.h"

#endif
