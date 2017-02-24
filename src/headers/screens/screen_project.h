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
 * \file screen_project.h
 * \brief Ce fichier contient toutes les fonctions utiles pour la gestion de l'écran
 * project.
 */

#ifndef _SCREEN_PROJECT_H_
#define _SCREEN_PROJECT_H_

void FAT_screenProject_printInfos();
void FAT_screenProject_printProject();
void FAT_screenProject_init();
void FAT_screenProject_checkButtons();
void FAT_screenProject_pressOrHeldA();

#include "screen_project_cursor.h"

#endif
