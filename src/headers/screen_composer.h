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
 * \file screen_composer.h
 * \brief Fichier réservé pour la gestion de l'écran COMPOSER.
 */

#ifndef _SCREEN_COMPOSER_H_
#define	_SCREEN_COMPOSER_H_

/** \brief Id de la colonne des notes. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_NOTES 0
/** \brief Id de la colonne des instrument. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_INST 1
/** \brief Id de la colonne du nom de la commande. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_CMD_NAME 2
/** \brief Id de la colonne de la valeur de la commande. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_CMD_PARAM 3
/** \brief Id de la colonne channel. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_CHANNEL 4
/** \brief Nombre de lignes affichées dans le composer. */
#define SCREENCOMPOSER_NB_LINES_ON_SCREEN 8
/** \brief Définit le nombre de paramètre modifiables dans l'écran. */
#define SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN 2

/** \brief Numéro de case tile ou commence l'affichage des notes. */
#define SCREENCOMPOSER_NOTE_LINE_X 10
/** \brief Numéro de case tile ou commence l'affichage des notes. */
#define SCREENCOMPOSER_LINE_START_Y 7
/** \brief Numéro de touche L: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_L 0
/** \brief Numéro de touche R: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_R 1
/** \brief Numéro de touche A: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_A 2
/** \brief Numéro de touche B: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_B 3
/** \brief Numéro de touche UP: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_UP 4
/** \brief Numéro de touche RIGHT: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_RIGHT 5
/** \brief Numéro de touche DOWN: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_DOWN 6
/** \brief Numéro de touche LEFT: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_LEFT 7

void FAT_screenComposer_printInfos();
void FAT_screenComposer_printNote(u8 line);
void FAT_screenComposer_printAllNote();
void FAT_screenComposer_printLocking();
void FAT_screenComposer_printAllScreenText();
void FAT_screenComposer_printColumns();
void FAT_screenComposer_init();
void FAT_screenComposer_checkButtons();
void FAT_screenComposer_pressOrHeldA();
void FAT_screenComposer_pressB();
void FAT_screenComposer_switchLocking();
void FAT_screenComposer_playAffectedNotes();

#include "cursors.h"
#include "fat.h"
#include "screen_composer_cursor.h"

#endif	/* SCREEN_COMPOSER_H */
