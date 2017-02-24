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
 * \file cursors.h
 * \brief Définitions de fonctions et variables utiles pour la gestion des objets curseurs.
 */

#ifndef _CURSORS_H_
#define _CURSORS_H_

void FAT_initCursor1();
void FAT_initCursor2();
void FAT_initCursor3();
void FAT_initCursor8();
void FAT_initCursorChange();
void FAT_initCursorsKeyboard();

void FAT_cursors_showCursor1();
void FAT_cursors_showCursor2();
void FAT_cursors_showCursor3();
void FAT_cursors_showCursor8();
void FAT_cursors_showCursorChange();
void FAT_cursors_showCursorKeyboard();
void FAT_cursors_showCursorKeyboard_select();

void FAT_cursors_hideCursor1();
void FAT_cursors_hideCursor2();
void FAT_cursors_hideCursor3();
void FAT_cursors_hideCursor8();
void FAT_cursors_hideCursorChange();
void FAT_cursors_hideCursorKeyboard();

void FAT_cursors_hideAllCursors();

void FAT_cursors_moveCursor1(u8 x, u8 y);
void FAT_cursors_moveCursor2(u8 x, u8 y);
void FAT_cursors_moveCursor3(u8 x, u8 y);
void FAT_cursors_moveCursor8(u8 x, u8 y);
void FAT_cursors_moveCursorChange(u8 x, u8 y);
void FAT_cursors_moveCursorKeyboard(u8 x, u8 y);
void FAT_cursors_moveCursorKeyboard_select(u8 x, u8 y);

#endif
