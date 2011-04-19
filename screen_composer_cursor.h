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
#ifndef _SCREEN_COMPOSER_CURSOR_H_
#define	_SCREEN_COMPOSER_CURSOR_H_

u8 FAT_screenComposer_cursorX, FAT_screenComposer_cursorY;
u8 FAT_screenComposer_currentSelectedLine, FAT_screenComposer_currentSelectedColumn;

// taille d'un block 
#define SCREENCOMPOSER_BLOCK3_SIZE_X 24
#define SCREENCOMPOSER_BLOCK2_SIZE_X 16
#define SCREENCOMPOSER_BLOCK_SIZE_Y 8

// paramètre de l'interface
#define SCREENCOMPOSER_WHITE_SPACE_X 8
#define SCREENCOMPOSER_LAST_BLOCK_Y 111
#define SCREENCOMPOSER_FIRST_BLOCK_X 88
#define SCREENCOMPOSER_FIRST_BLOCK_Y 56

void FAT_screenComposer_initCursor();
void FAT_screenComposer_moveCursorRight();
void FAT_screenComposer_moveCursorLeft();
void FAT_screenComposer_moveCursorDown();
void FAT_screenComposer_moveCursorUp();
void FAT_screenComposer_commitCursorMove();

void FAT_screenComposer_initCursor() {
    FAT_screenComposer_cursorX = SCREENCOMPOSER_FIRST_BLOCK_X - 1;
    FAT_screenComposer_cursorY = SCREENCOMPOSER_FIRST_BLOCK_Y - 1;

    FAT_screenComposer_currentSelectedLine = 0;
    FAT_screenComposer_currentSelectedColumn = 0;
}

void FAT_screenComposer_commitCursorMove() {
    if (FAT_screenComposer_currentSelectedColumn == 0) {
        ham_SetObjXY(FAT_cursor3_obj, FAT_screenComposer_cursorX, FAT_screenComposer_cursorY);
    } else {
        ham_SetObjXY(FAT_cursor2_obj, FAT_screenComposer_cursorX, FAT_screenComposer_cursorY);
    }
}

void FAT_screenComposer_moveCursorDown() {
    if (FAT_screenComposer_currentSelectedLine < SCREENCOMPOSER_NB_LINES_ON_SCREEN) {
        if (!(FAT_screenComposer_cursorY >= SCREENCOMPOSER_LAST_BLOCK_Y - 1)) {
            FAT_screenComposer_cursorY += SCREENCOMPOSER_BLOCK_SIZE_Y;
            FAT_screenComposer_currentSelectedLine++;
            FAT_screenComposer_printInfos();
        }
    }
}

void FAT_screenComposer_moveCursorUp() {

    if (FAT_screenComposer_currentSelectedLine > 0) {
        if (!(FAT_screenComposer_cursorY <= SCREENCOMPOSER_FIRST_BLOCK_Y - 1)) {
            FAT_screenComposer_cursorY -= SCREENCOMPOSER_BLOCK_SIZE_Y;
            FAT_screenComposer_currentSelectedLine--;
            FAT_screenComposer_printInfos();
        }
    }

}

void FAT_screenComposer_moveCursorRight(){
    
    if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_NOTES){
        
        FAT_screenComposer_cursorX += SCREENCOMPOSER_BLOCK3_SIZE_X + SCREENCOMPOSER_WHITE_SPACE_X;
        FAT_screenComposer_currentSelectedColumn = SCREENCOMPOSER_COLUMN_ID_INST;
        FAT_cursors_hideCursor3();
        FAT_cursors_showCursor2();
    
    } else  if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_INST){
        
        FAT_screenComposer_cursorX += SCREENCOMPOSER_BLOCK2_SIZE_X + SCREENCOMPOSER_WHITE_SPACE_X;
        FAT_screenComposer_currentSelectedColumn = SCREENCOMPOSER_COLUMN_ID_CMD_NAME;
    
    } else if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_CMD_NAME){
        
        FAT_screenComposer_cursorX += SCREENCOMPOSER_BLOCK2_SIZE_X;
        FAT_screenComposer_currentSelectedColumn = SCREENCOMPOSER_COLUMN_ID_CMD_PARAM;
    }
    
}

void FAT_screenComposer_moveCursorLeft(){
    if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_INST){
        
        FAT_screenComposer_cursorX -= SCREENCOMPOSER_BLOCK3_SIZE_X + SCREENCOMPOSER_WHITE_SPACE_X;
        FAT_screenComposer_currentSelectedColumn = SCREENCOMPOSER_COLUMN_ID_NOTES;
        FAT_cursors_hideCursor2();
        FAT_cursors_showCursor3();
    
    } else  if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_CMD_NAME){
    
        FAT_screenComposer_cursorX -= SCREENCOMPOSER_BLOCK2_SIZE_X + SCREENCOMPOSER_WHITE_SPACE_X;
        FAT_screenComposer_currentSelectedColumn = SCREENCOMPOSER_COLUMN_ID_INST;
    
    } else if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_CMD_PARAM){
        FAT_screenComposer_cursorX -= SCREENCOMPOSER_BLOCK2_SIZE_X;
        FAT_screenComposer_currentSelectedColumn = SCREENCOMPOSER_COLUMN_ID_CMD_NAME;
    }
}



#endif	/* SCREEN_COMPOSER_CURSOR_H */

