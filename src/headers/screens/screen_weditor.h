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
 * \file screen_weditor.h
 * \brief Fichier réservé pour la gestion de l'écran edition de wave.
 */

#ifndef _SCREEN_WEDITOR_H_
#define _SCREEN_WEDITOR_H_

void FAT_screenWeditor_init();
void FAT_screenWeditor_checkButtons ();
void FAT_screenWeditor_initWaveEditorSprites ();
void FAT_screenWeditor_hideAllEditorSprites ();

#include "screen_weditor_cursor.h"

#endif
