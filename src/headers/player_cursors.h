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
#ifndef _PLAYER_CURSORS_H_
#define	_PLAYER_CURSORS_H_

#include "../gfx/ResourceData.h"
#include "../soundApi/soundApi.h"
#include "fat.h"

void FAT_player_initCursors();
void FAT_player_hideAllCursors();
void FAT_player_live_showOrHideCursorWait(u8 channel);
void FAT_player_hideWaitCursors ();
void FAT_player_hideSequencesCursors();
void FAT_player_hideBlockCursor();
void FAT_player_hideNoteCursor();
void FAT_player_moveOrHideCursor(u8 channel);
void FAT_player_hidePlayerSequenceCursor (u8 n);

#endif
