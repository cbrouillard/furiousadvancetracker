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
 * \file screen_filesystem.h
 * \brief Ce fichier contient toutes les fonctions utiles pour la gestion de l'écran filesystem.
 */

#ifndef _SCREEN_FILESYSTEM_H_
#define _SCREEN_FILESYSTEM_H_

#define FILESYSTEM_MODE_SAVE 0
#define FILESYSTEM_MODE_LOAD 1

/** \brief Numéro de case ou l'affichage des notes démarre. */
#define SCREENFILESYSTEM_LINE_START_Y 2
/** \brief Nombre total de notes affichées sur l'écran. */
#define SCREENFILESYSTEM_NB_LINES_ON_SCREEN 16
/** \brief Numéro de case ou l'affichage des numéros de ligne démarre. */
#define SCREENFILESYSTEM_LINE_X 0
/** \brief Numéro de case ou l'affichage des noms des tracks démarre. */
#define SCREENFILESYSTEM_LINE_TRACKNAME_X 3

void FAT_screenFilesystem_setMode(u8 modeId);
void FAT_screenFilesystem_printMode();
void FAT_screenFilesystem_printLineColumns();
void FAT_screenFilesystem_printAllTracksName();
void FAT_screenFilesystem_printInfos();
void FAT_screenFilesystem_init();
void FAT_screenFilesystem_checkButtons();
void FAT_screenFilesystem_pressOrHeldA();

#include "screen_filesystem_cursor.h"

#endif
