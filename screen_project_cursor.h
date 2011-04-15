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
#ifndef _SCREEN_PROJECT_CURSOR_H_
#define	_SCREEN_PROJECT_CURSOR_H_

#define SCREENPROJECT_FIRST_BLOCK_X 88
#define SCREENPROJECT_FIRST_BLOCK_Y 32
#define SCREENPROJECT_LAST_BLOCK_Y 120

#define SCREENPROJECT_NB_LINES_ON_SCREEN 4

u8 FAT_screenProject_cursorX, FAT_screenProject_cursorY;
u8 FAT_screenProject_currentSelectedLine, FAT_screenProject_currentSelectedColumn;

const u8 PROJECT_PULSE_BLOCK_Y[4] = {31, 39, 63, 71};

void FAT_screenProject_commitCursorMove() {
    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
            ham_SetObjXY(FAT_cursor3_obj, FAT_screenProject_cursorX, FAT_screenProject_cursorY);
        case 1:
        case 2:
        case 3:
            ham_SetObjXY(FAT_cursor2_obj, FAT_screenProject_cursorX, FAT_screenProject_cursorY);
            break;

    }
}

void FAT_screenProject_displayGoodCursor() {
    switch (FAT_screenProject_currentSelectedLine) {
        case 0:
            FAT_cursors_hideCursor2();
            FAT_cursors_showCursor3();
            break;
        case 1:
        case 2:
        case 3:
            FAT_cursors_hideCursor3();
            FAT_cursors_showCursor2();
            break;

    }
}

void FAT_screenProject_initCursor() {

    FAT_screenProject_cursorX = SCREENPROJECT_FIRST_BLOCK_X - 1;
    FAT_screenProject_cursorY = SCREENPROJECT_FIRST_BLOCK_Y - 1;

    FAT_screenProject_currentSelectedLine = 0;
    FAT_screenProject_currentSelectedColumn = 0;

    FAT_screenProject_commitCursorMove();
}

void FAT_screenProject_moveCursorDown() {

    if (FAT_screenProject_currentSelectedLine < SCREENPROJECT_NB_LINES_ON_SCREEN - 1) {
        if (!(FAT_screenProject_cursorY >= SCREENPROJECT_LAST_BLOCK_Y - 1)) {
            FAT_screenProject_currentSelectedLine++;
            FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
        }
    }
    FAT_screenProject_displayGoodCursor();

}

void FAT_screenProject_moveCursorUp() {
    if (FAT_screenProject_currentSelectedLine > 0) {
        if (!(FAT_screenProject_cursorY <= SCREENPROJECT_FIRST_BLOCK_Y - 1)) {
            FAT_screenProject_currentSelectedLine--;
            FAT_screenProject_cursorY = PROJECT_PULSE_BLOCK_Y[FAT_screenProject_currentSelectedLine];
        }
    }
    FAT_screenProject_displayGoodCursor();
}

#endif	/* SCREEN_PROJECT_CURSOR_H */

