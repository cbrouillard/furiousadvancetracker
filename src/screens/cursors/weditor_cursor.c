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
* \file weditor_cursor.c
* \brief Gestion du curseur sur l'écran d'édition voice.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../../headers/fat.h"

/** \brief Position du curseur. */
u8 FAT_screenWeditor_cursorY;

u8 FAT_screenWeditor_selectedLine;
u8 FAT_screenWeditor_getSelectedLine(){
    return FAT_screenWeditor_selectedLine;
}

void FAT_screenWeditor_initCursor(){
  FAT_screenWeditor_cursorY = 15;
  FAT_screenWeditor_selectedLine = 0;
}

void FAT_screenWeditor_moveCursorDown(){
  if (FAT_screenWeditor_selectedLine < 15) {
    FAT_screenWeditor_selectedLine ++;
    FAT_screenWeditor_cursorY = 15 + (8 * FAT_screenWeditor_selectedLine);
  }
}
void FAT_screenWeditor_moveCursorUp(){
  if (FAT_screenWeditor_selectedLine > 0) {
    FAT_screenWeditor_selectedLine --;
    FAT_screenWeditor_cursorY = 15 + (8 * FAT_screenWeditor_selectedLine);
  }
}
void FAT_screenWeditor_commitCursorMove(){
  FAT_cursors_moveCursor2 (23, FAT_screenWeditor_cursorY);
}
void FAT_screenWeditor_moveCursorAllUp (){
  FAT_screenWeditor_cursorY = 15;
  FAT_screenWeditor_selectedLine = 0;
}
void FAT_screenWeditor_moveCursorAllDown (){
  FAT_screenWeditor_selectedLine = 15;
  FAT_screenWeditor_cursorY = 15 + (8 * 15);
}
