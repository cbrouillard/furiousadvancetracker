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
* \file blocks_cursor.c
* \brief Gestion du curseur sur l'écran blocks.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../../headers/fat.h"

/** \brief Position du curseur. */
u8 FAT_screenBlocks_cursorX;
/** \brief Position du curseur. */
u8 FAT_screenBlocks_cursorY;

/**
 * \brief Numéro de la ligne actuellement sélectionné.
 */
u8 FAT_screenBlocks_currentSelectedLine;
u8 FAT_screenBlocks_getCurrentSelectedLine(){
  return FAT_screenBlocks_currentSelectedLine;
};
/**
 * \brief Numéro de colonne actuellement sélectionné.
 */
u8 FAT_screenBlocks_currentSelectedColumn;
u8 FAT_screenBlocks_getCurrentSelectedColumn(){
  return FAT_screenBlocks_currentSelectedColumn;
};

/**
 * \brief Initialisation de la position du curseur.
 */
void FAT_screenBlocks_initCursor() {
    FAT_screenBlocks_cursorX = SCREENBLOCKS_FIRST_BLOCK_X - 1;
    FAT_screenBlocks_cursorY = SCREENBLOCKS_FIRST_BLOCK_Y - 1;

    FAT_screenBlocks_currentSelectedLine = 0;
    FAT_screenBlocks_currentSelectedColumn = 0;
}

/**
 * \brief Valide le changement de position du curseur dans la mémoire de la GBA.
 */
void FAT_screenBlocks_commitCursorMove() {
    FAT_cursors_moveCursor2 (FAT_screenBlocks_cursorX, FAT_screenBlocks_cursorY);
}

/**
 * \brief Déplace le curseur vers le bas.
 *
 * Attention, la validation du déplacement doit être effectuée avec FAT_screenBlocks_commitCursorMove() .
 */
void FAT_screenBlocks_moveCursorDown() {
    if (FAT_screenBlocks_currentSelectedLine < SCREENBLOCKS_NB_LINES_ON_SCREEN - 1) {
        if (!(FAT_screenBlocks_cursorY >= SCREENBLOCKS_LAST_BLOCK_Y - 1)) {
            FAT_screenBlocks_cursorY += SCREENBLOCKS_BLOCK_SIZE_Y;
            FAT_screenBlocks_currentSelectedLine ++;
            FAT_screenBlocks_printInfos();
        }
    } else {
        FAT_screenBlocks_cursorY = SCREENBLOCKS_FIRST_BLOCK_Y - 1;
        FAT_screenBlocks_currentSelectedLine = 0;
        FAT_screenBlocks_printInfos();
    }
}

/**
 * \brief Déplace le curseur vers le haut.
 *
 * Attention, la validation du déplacement doit être effectuée avec FAT_screenBlocks_commitCursorMove() .
 */
void FAT_screenBlocks_moveCursorUp() {

    if (FAT_screenBlocks_currentSelectedLine > 0) {
        if (!(FAT_screenBlocks_cursorY <= SCREENBLOCKS_FIRST_BLOCK_Y - 1)) {
            FAT_screenBlocks_cursorY -= SCREENBLOCKS_BLOCK_SIZE_Y;
            FAT_screenBlocks_currentSelectedLine --;
            FAT_screenBlocks_printInfos();
        }
    } else {
        FAT_screenBlocks_currentSelectedLine = SCREENBLOCKS_NB_LINES_ON_SCREEN - 1;
        FAT_screenBlocks_cursorY = (SCREENBLOCKS_FIRST_BLOCK_Y - 1) + (SCREENBLOCKS_BLOCK_SIZE_Y * 15);
        FAT_screenBlocks_printInfos();
    }

}

/**
 * \brief Déplace le curseur tout en haut (ligne 0).
 *
 * Attention, la validation du déplacement doit être effectuée avec FAT_screenBlocks_commitCursorMove().
 */
void FAT_screenBlocks_moveCursorAllUp (){
    FAT_screenBlocks_currentSelectedLine = 0;
    FAT_screenBlocks_cursorY = SCREENBLOCKS_FIRST_BLOCK_Y - 1;
    FAT_screenBlocks_printInfos();
}

/**
 * \brief Déplace le curseur tout en bas (ligne 16).
 *
 * Attention, la validation du déplacement doit être effectuée avec FAT_screenBlocks_commitCursorMove().
 */
void FAT_screenBlocks_moveCursorAllDown (){
    FAT_screenBlocks_currentSelectedLine = SCREENBLOCKS_NB_LINES_ON_SCREEN - 1;
    FAT_screenBlocks_cursorY = SCREENBLOCKS_LAST_BLOCK_Y;
    FAT_screenBlocks_printInfos();
}

/**
 * \brief Déplace le curseur vers la droite.
 *
 * Attention, la validation du déplacement doit être effectuée avec FAT_screenBlocks_commitCursorMove().
 */
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

/**
 * \brief Déplace le curseur vers la gauche.
 *
 * Attention, la validation du déplacement doit être effectuée avec FAT_screenBlocks_commitCursorMove().
 */
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
