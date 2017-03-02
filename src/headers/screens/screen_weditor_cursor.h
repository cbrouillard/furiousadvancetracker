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
 * \file screen_weditor_cursor.h
 * \brief Fichier de gestion du curseur pour l'écran d'dition voice.
 */

#ifndef _SCREEN_WEDITOR_CURSOR_H_
#define	_SCREEN_WEDITOR_CURSOR_H_

void FAT_screenWeditor_initCursor();
void FAT_screenWeditor_moveCursorDown();
void FAT_screenWeditor_moveCursorUp();
void FAT_screenWeditor_commitCursorMove();
void FAT_screenWeditor_moveCursorAllUp ();
void FAT_screenWeditor_moveCursorAllDown ();

u8 FAT_screenWeditor_getSelectedLine();

#endif
