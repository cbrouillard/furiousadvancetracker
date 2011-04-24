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
#ifndef _SCREEN_NOTES_CURSOR_H_
#define	_SCREEN_NOTES_CURSOR_H_

u8 FAT_screenNotes_cursorX, FAT_screenNotes_cursorY;
u8 FAT_screenNotes_currentSelectedLine, FAT_screenNotes_currentSelectedColumn;

// taille d'un block 
#define SCREENNOTES_BLOCK3_SIZE_X 24
#define SCREENNOTES_BLOCK2_SIZE_X 16
#define SCREENNOTES_BLOCK_SIZE_Y 8

// paramètre de l'interface
#define SCREENNOTES_WHITE_SPACE_X 8
#define SCREENNOTES_LAST_BLOCK_X 143
#define SCREENNOTES_LAST_BLOCK_Y 135
#define SCREENNOTES_FIRST_BLOCK_X 24
#define SCREENNOTES_FIRST_BLOCK_Y 16

void FAT_screenNotes_initCursor();
void FAT_screenNotes_moveCursorRight();
void FAT_screenNotes_moveCursorLeft();
void FAT_screenNotes_moveCursorDown();
void FAT_screenNotes_moveCursorUp();
void FAT_screenNotes_commitCursorMove();

void FAT_screenNotes_initCursor() {
    FAT_screenNotes_cursorX = SCREENNOTES_FIRST_BLOCK_X - 1;
    FAT_screenNotes_cursorY = SCREENNOTES_FIRST_BLOCK_Y - 1;

    FAT_screenNotes_currentSelectedLine = 0;
    FAT_screenNotes_currentSelectedColumn = 0;
}

void FAT_screenNotes_commitCursorMove() {
    if (FAT_screenNotes_currentSelectedColumn == 0) {
        ham_SetObjXY(FAT_cursor3_obj, FAT_screenNotes_cursorX, FAT_screenNotes_cursorY);
    } else {
        ham_SetObjXY(FAT_cursor2_obj, FAT_screenNotes_cursorX, FAT_screenNotes_cursorY);
    }
}

void FAT_screenNotes_moveCursorDown() {
    if (FAT_screenNotes_currentSelectedLine < SCREENNOTES_NB_LINES_ON_SCREEN) {
        if (!(FAT_screenNotes_cursorY >= SCREENNOTES_LAST_BLOCK_Y - 1)) {
            FAT_screenNotes_cursorY += SCREENNOTES_BLOCK_SIZE_Y;
            FAT_screenNotes_currentSelectedLine++;
            FAT_screenNotes_printInfos();
        }
    }
}

void FAT_screenNotes_moveCursorUp() {

    if (FAT_screenNotes_currentSelectedLine > 0) {
        if (!(FAT_screenNotes_cursorY <= SCREENNOTES_FIRST_BLOCK_Y - 1)) {
            FAT_screenNotes_cursorY -= SCREENNOTES_BLOCK_SIZE_Y;
            FAT_screenNotes_currentSelectedLine--;
            FAT_screenNotes_printInfos();
        }
    }

}

void FAT_screenNotes_moveCursorRight(){
    
    if (FAT_screenNotes_currentSelectedColumn == SCREENNOTES_COLUMN_ID_NOTES){
        
        FAT_screenNotes_cursorX += SCREENNOTES_BLOCK3_SIZE_X + SCREENNOTES_WHITE_SPACE_X;
        FAT_screenNotes_currentSelectedColumn = SCREENNOTES_COLUMN_ID_INST;
        FAT_cursors_hideCursor3();
        FAT_cursors_showCursor2();
    
    } else  if (FAT_screenNotes_currentSelectedColumn == SCREENNOTES_COLUMN_ID_INST){
        
        FAT_screenNotes_cursorX += SCREENNOTES_BLOCK2_SIZE_X + SCREENNOTES_WHITE_SPACE_X;
        FAT_screenNotes_currentSelectedColumn = SCREENNOTES_COLUMN_ID_CMD_NAME;
    
    } else if (FAT_screenNotes_currentSelectedColumn == SCREENNOTES_COLUMN_ID_CMD_NAME){
        
        FAT_screenNotes_cursorX += SCREENNOTES_BLOCK2_SIZE_X;
        FAT_screenNotes_currentSelectedColumn = SCREENNOTES_COLUMN_ID_CMD_PARAM;
    }
    
}

void FAT_screenNotes_moveCursorLeft(){
    if (FAT_screenNotes_currentSelectedColumn == SCREENNOTES_COLUMN_ID_INST){
        
        FAT_screenNotes_cursorX -= SCREENNOTES_BLOCK3_SIZE_X + SCREENNOTES_WHITE_SPACE_X;
        FAT_screenNotes_currentSelectedColumn = SCREENNOTES_COLUMN_ID_NOTES;
        FAT_cursors_hideCursor2();
        FAT_cursors_showCursor3();
    
    } else  if (FAT_screenNotes_currentSelectedColumn == SCREENNOTES_COLUMN_ID_CMD_NAME){
    
        FAT_screenNotes_cursorX -= SCREENNOTES_BLOCK2_SIZE_X + SCREENNOTES_WHITE_SPACE_X;
        FAT_screenNotes_currentSelectedColumn = SCREENNOTES_COLUMN_ID_INST;
    
    } else if (FAT_screenNotes_currentSelectedColumn == SCREENNOTES_COLUMN_ID_CMD_PARAM){
        FAT_screenNotes_cursorX -= SCREENNOTES_BLOCK2_SIZE_X;
        FAT_screenNotes_currentSelectedColumn = SCREENNOTES_COLUMN_ID_CMD_NAME;
    }
}

#endif	/* SCREEN_NOTES_CURSOR_H */

