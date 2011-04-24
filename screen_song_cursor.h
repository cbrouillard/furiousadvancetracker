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
#ifndef _CURSOR_H_
#define _CURSOR_H_

// taille d'un bloc d'affichage séquence 16*8 en pixels
#define SCREENSONG_BLOCK_SIZE_X 16
#define SCREENSONG_BLOCK_SIZE_Y 8

// paramètre de l'interface
// espace définit entre chaque colonne (px)
#define SCREENSONG_WHITE_SPACE_X 8
// coordonnée du dernier bloc en bas à droite de l'écran (px)
#define SCREENSONG_LAST_BLOCK_X 143
// absisse du dernier bloc en bas à droite de l'écran (px)
#define SCREENSONG_LAST_BLOCK_Y 135
// coordonnée du premier bloc en haut à gauche (px)
#define SCREENSONG_FIRST_BLOCK_X 24
// abscisse du premier bloc en haut à gauche (px)
#define SCREENSONG_FIRST_BLOCK_Y 16

u8 FAT_screenSong_cursorX, FAT_screenSong_cursorY;
u8 FAT_screenSong_currentSelectedLine, FAT_screenSong_currentSelectedColumn;

// prototypes
void FAT_screenSong_initCursor();
void FAT_screenSong_moveCursorRight();
void FAT_screenSong_moveCursorLeft();
void FAT_screenSong_moveCursorDown();
void FAT_screenSong_moveCursorUp();
void FAT_screenSong_commitCursorMove();

void FAT_screenSong_initCursor() {
    FAT_screenSong_cursorX = SCREENSONG_FIRST_BLOCK_X - 1;
    FAT_screenSong_cursorY = SCREENSONG_FIRST_BLOCK_Y - 1;
    FAT_screenSong_currentSelectedLine = 0;
    FAT_screenSong_currentStartLine = 0;
    FAT_screenSong_currentSelectedColumn = 0;
    
};

void FAT_screenSong_moveCursorRight() {
    if (!(FAT_screenSong_cursorX >= SCREENSONG_LAST_BLOCK_X - 1)) {
        FAT_screenSong_cursorX += SCREENSONG_BLOCK_SIZE_X + SCREENSONG_WHITE_SPACE_X;
        FAT_screenSong_currentSelectedColumn++;
        FAT_screenSong_printInfos();
    }
}

void FAT_screenSong_moveCursorLeft() {
    if (!(FAT_screenSong_cursorX <= SCREENSONG_FIRST_BLOCK_X)) {
        FAT_screenSong_cursorX -= SCREENSONG_BLOCK_SIZE_X + SCREENSONG_WHITE_SPACE_X;
        FAT_screenSong_currentSelectedColumn--;
        FAT_screenSong_printInfos();
    }
}

void FAT_screenSong_movePageDown() {
    if (FAT_screenSong_currentSelectedLine < NB_MAX_SEQUENCES - SCREENSONG_NB_LINES_ON_SCREEN) {
        FAT_screenSong_currentStartLine += SCREENSONG_NB_LINES_ON_SCREEN;
        FAT_screenSong_currentSelectedLine += SCREENSONG_NB_LINES_ON_SCREEN;
        FAT_screenSong_printAllScreenText();
    }
}

void FAT_screenSong_moveCursorAllDown() {
    FAT_screenSong_cursorY = SCREENSONG_LAST_BLOCK_Y;
    FAT_screenSong_currentStartLine = NB_MAX_SEQUENCES - SCREENSONG_NB_LINES_ON_SCREEN;
    FAT_screenSong_currentSelectedLine = NB_MAX_SEQUENCES;
    FAT_screenSong_printAllScreenText();
}

void FAT_screenSong_moveCursorDown() {
    if (FAT_screenSong_currentSelectedLine < NB_MAX_SEQUENCES) {
        if (FAT_screenSong_cursorY >= SCREENSONG_LAST_BLOCK_Y - 1) {
            if (FAT_screenSong_currentStartLine < NB_MAX_SEQUENCES - SCREENSONG_NB_LINES_ON_SCREEN) {
                // on n'avance pas mais on change de ligne
                FAT_screenSong_currentStartLine++;
                FAT_screenSong_currentSelectedLine++;
                FAT_screenSong_printAllScreenText();
            }
        } else {
            FAT_screenSong_cursorY += SCREENSONG_BLOCK_SIZE_Y;
            FAT_screenSong_currentSelectedLine++;
            FAT_screenSong_printInfos();
        }
    }
}

void FAT_screenSong_movePageUp() {
    if (FAT_screenSong_currentSelectedLine >= SCREENSONG_NB_LINES_ON_SCREEN
            && FAT_screenSong_currentStartLine >= SCREENSONG_NB_LINES_ON_SCREEN) {
        FAT_screenSong_currentStartLine -= SCREENSONG_NB_LINES_ON_SCREEN;
        FAT_screenSong_currentSelectedLine -= SCREENSONG_NB_LINES_ON_SCREEN;
        FAT_screenSong_printAllScreenText();
    }
}

void FAT_screenSong_moveCursorAllUp() {
    FAT_screenSong_cursorY = SCREENSONG_FIRST_BLOCK_Y-1;
    FAT_screenSong_currentStartLine = 0;
    FAT_screenSong_currentSelectedLine = 0;
    FAT_screenSong_printAllScreenText();
}

void FAT_screenSong_moveCursorUp() {

    if (FAT_screenSong_currentSelectedLine > 0) {
        if (FAT_screenSong_cursorY <= SCREENSONG_FIRST_BLOCK_Y - 1) {
            if (FAT_screenSong_currentStartLine > 0) {
                // on ne recule pas mais on change de ligne
                FAT_screenSong_currentStartLine--;
                FAT_screenSong_currentSelectedLine--;
                FAT_screenSong_printAllScreenText();
            }
        } else {
            FAT_screenSong_cursorY -= SCREENSONG_BLOCK_SIZE_Y;
            FAT_screenSong_currentSelectedLine--;
            FAT_screenSong_printInfos();
        }
    }

}

void FAT_screenSong_commitCursorMove() {
    ham_SetObjXY(FAT_cursor2_obj, FAT_screenSong_cursorX, FAT_screenSong_cursorY);
}

#endif
