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
 * \file screen_composer_cursor.h
 * \brief Ce fichier permet de gérer le curseur sur l'écran COMPOSER.
 */

#ifndef _SCREEN_COMPOSER_CURSOR_H_
#define	_SCREEN_COMPOSER_CURSOR_H_

#include "screen_composer.h"

/** \brief Taille d'un block mesurant 3 cases (en pixels). */
#define SCREENCOMPOSER_BLOCK3_SIZE_X 24
/** \brief Taille d'un block mesurant 2 cases (en pixels). */
#define SCREENCOMPOSER_BLOCK2_SIZE_X 16
/** \brief Taille d'un block mesurant 1 cases (en pixels). */
#define SCREENCOMPOSER_BLOCK1_SIZE_X 8
/** \brief Taille d'un block en hauteur (en pixels). */
#define SCREENCOMPOSER_BLOCK_SIZE_Y 8

// paramètre de l'interface
/** \brief Taille de l'espace blanc entre chaque block sur X. */
#define SCREENCOMPOSER_WHITE_SPACE_X 8
/** \brief Position Y du dernier block (en pixels). */
#define SCREENCOMPOSER_LAST_BLOCK_Y 111
/** \brief Position X du premier block (en pixels). */
#define SCREENCOMPOSER_FIRST_BLOCK_X 80
/** \brief Position Y du premier block (en pixels). */
#define SCREENCOMPOSER_FIRST_BLOCK_Y 56
/** \brief Position des blocks de paramètres. */
#define SCREENCOMPOSER_PARAMETER_BLOCK_X 95

const u8 screenComposer_parametersCursorsPositions [SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN] = {23, 31};

void FAT_screenComposer_initCursor();
void FAT_screenComposer_moveCursorRight();
void FAT_screenComposer_moveCursorLeft();
void FAT_screenComposer_moveCursorDown();
void FAT_screenComposer_moveCursorUp();
void FAT_screenComposer_commitCursorMove();

u8 FAT_screenComposer_getCurrentSelectedLine ();
u8 FAT_screenComposer_getCurrentSelectedColumn ();

#endif	/* SCREEN_COMPOSER_CURSOR_H */
