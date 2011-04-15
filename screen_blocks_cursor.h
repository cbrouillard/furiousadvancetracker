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
#ifndef _SCREEN_BLOCKS_CURSOR_H_
#define	_SCREEN_BLOCKS_CURSOR_H_

u8 FAT_screenBlocks_cursorX, FAT_screenBlocks_cursorY;

u8 FAT_screenBlocks_currentSelectedLine, FAT_screenBlocks_currentSelectedColumn;

// taille d'un block 
#define SCREENBLOCKS_BLOCK_SIZE_X 16
#define SCREENBLOCKS_BLOCK_SIZE_Y 8

// paramètre de l'interface
#define SCREENBLOCKS_WHITE_SPACE_X 8
#define SCREENBLOCKS_LAST_BLOCK_X 143
#define SCREENBLOCKS_LAST_BLOCK_Y 135
#define SCREENBLOCKS_FIRST_BLOCK_X 24
#define SCREENBLOCKS_FIRST_BLOCK_Y 16

void FAT_screenBlocks_initCursor();
void FAT_screenBlocks_moveCursorRight();
void FAT_screenBlocks_moveCursorLeft();
void FAT_screenBlocks_moveCursorDown();
void FAT_screenBlocks_moveCursorUp();
void FAT_screenBlocks_commitCursorMove();

void FAT_screenBlocks_initCursor() {
    FAT_screenBlocks_cursorX = SCREENBLOCKS_FIRST_BLOCK_X - 1;
    FAT_screenBlocks_cursorY = SCREENBLOCKS_FIRST_BLOCK_Y - 1;

    FAT_screenBlocks_currentSelectedLine = 0;
    FAT_screenBlocks_currentSelectedColumn = 0;

    FAT_screenBlocks_commitCursorMove();
}

void FAT_screenBlocks_commitCursorMove() {
    ham_SetObjXY(FAT_cursor2_obj, FAT_screenBlocks_cursorX, FAT_screenBlocks_cursorY);
}

void FAT_screenBlocks_moveCursorDown() {
    if (FAT_screenBlocks_currentSelectedLine < SCREENBLOCKS_NB_LINES_ON_SCREEN) {
        if (!(FAT_screenBlocks_cursorY >= SCREENBLOCKS_LAST_BLOCK_Y - 1)) {
            FAT_screenBlocks_cursorY += SCREENBLOCKS_BLOCK_SIZE_Y;
            FAT_screenBlocks_currentSelectedLine++;
            FAT_screenBlocks_printInfos();
        }
    }
}

void FAT_screenBlocks_moveCursorUp() {

    if (FAT_screenBlocks_currentSelectedLine > 0) {
        if (!(FAT_screenBlocks_cursorY <= SCREENBLOCKS_FIRST_BLOCK_Y - 1)) {
            FAT_screenBlocks_cursorY -= SCREENBLOCKS_BLOCK_SIZE_Y;
            FAT_screenBlocks_currentSelectedLine--;
            FAT_screenBlocks_printInfos();
        }
    }

}

void FAT_screenBlocks_moveCursorAllUp (){
    FAT_screenBlocks_currentSelectedLine = 0;
    FAT_screenBlocks_cursorY = SCREENBLOCKS_FIRST_BLOCK_Y - 1;
    FAT_screenBlocks_printInfos();
}

void FAT_screenBlocks_moveCursorAllDown (){
    FAT_screenBlocks_currentSelectedLine = SCREENBLOCKS_NB_LINES_ON_SCREEN - 1;
    FAT_screenBlocks_cursorY = SCREENBLOCKS_LAST_BLOCK_Y;
    FAT_screenBlocks_printInfos();
}

void FAT_screenBlocks_moveCursorRight(){
    
    if (FAT_screenBlocks_currentSelectedColumn == SCREENBLOCKS_COLUMN_ID_BLK){
        
        FAT_screenBlocks_cursorX += SCREENBLOCKS_BLOCK_SIZE_X + SCREENBLOCKS_WHITE_SPACE_X;
        FAT_screenBlocks_currentSelectedColumn = SCREENBLOCKS_COLUMN_ID_TSP;
    
    } else  if (FAT_screenBlocks_currentSelectedColumn == SCREENBLOCKS_COLUMN_ID_TSP){
        
        FAT_screenBlocks_cursorX += SCREENBLOCKS_BLOCK_SIZE_X + SCREENBLOCKS_WHITE_SPACE_X;
        FAT_screenBlocks_currentSelectedColumn = SCREENBLOCKS_COLUMN_ID_CMD_NAME;
    
    } else if (FAT_screenBlocks_currentSelectedColumn == SCREENBLOCKS_COLUMN_ID_CMD_NAME){
        
        FAT_screenBlocks_cursorX += SCREENBLOCKS_BLOCK_SIZE_X;
        FAT_screenBlocks_currentSelectedColumn = SCREENBLOCKS_COLUMN_ID_CMD_PARAM;
    }
    
}

void FAT_screenBlocks_moveCursorLeft(){
    if (FAT_screenBlocks_currentSelectedColumn == SCREENBLOCKS_COLUMN_ID_TSP){
        
        FAT_screenBlocks_cursorX -= SCREENBLOCKS_BLOCK_SIZE_X + SCREENBLOCKS_WHITE_SPACE_X;
        FAT_screenBlocks_currentSelectedColumn = SCREENBLOCKS_COLUMN_ID_BLK;
    
    } else  if (FAT_screenBlocks_currentSelectedColumn == SCREENBLOCKS_COLUMN_ID_CMD_NAME){
    
        FAT_screenBlocks_cursorX -= SCREENBLOCKS_BLOCK_SIZE_X + SCREENBLOCKS_WHITE_SPACE_X;
        FAT_screenBlocks_currentSelectedColumn = SCREENBLOCKS_COLUMN_ID_TSP;
    
    } else if (FAT_screenBlocks_currentSelectedColumn == SCREENBLOCKS_COLUMN_ID_CMD_PARAM){
        FAT_screenBlocks_cursorX -= SCREENBLOCKS_BLOCK_SIZE_X;
        FAT_screenBlocks_currentSelectedColumn = SCREENBLOCKS_COLUMN_ID_CMD_NAME;
    }
}

#endif	/* SCREEN_BLOCKS_CURSOR_H */

