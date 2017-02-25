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

#ifndef _DIALOG_KEYBOARD_H_
#define	_DIALOG_KEYBOARD_H_

#define DIALOG_KEYBOARD_FIRST_LETTER_X 22
#define DIALOG_KEYBOARD_FIRST_LETTER_Y 38
#define DIALOG_KEYBOARD_WRITER_X 110
#define DIALOG_KEYBOARD_WRITER_Y 22

/** \brief Numéro de case ou l'affichage des notes démarre. */
#define SCREENFILESYSTEM_LINE_START_Y 2
/** \brief Nombre total de notes affichées sur l'écran. */
#define SCREENFILESYSTEM_NB_LINES_ON_SCREEN 16
/** \brief Numéro de case ou l'affichage des numéros de ligne démarre. */
#define SCREENFILESYSTEM_LINE_X 0
/** \brief Numéro de case ou l'affichage des noms des tracks démarre. */
#define SCREENFILESYSTEM_LINE_TRACKNAME_X 3

void FAT_dialog_close();
void FAT_dialog_keyboardSelectorCursor ();
void FAT_dialog_keyboardPrintActualName ();
void FAT_dialog_keyboardMainFunc();
void FAT_dialog_cheat_printLineColumns();
void FAT_dialog_cheat_printLastTracksName();
void FAT_dialog_keyboardShow (u8 fromTrackNum);

#endif
