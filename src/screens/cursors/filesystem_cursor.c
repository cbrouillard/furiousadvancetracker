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
* \file filesystem_cursor.c
* \brief Gestion du curseur sur l'écran filesystem.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../../headers/fat.h"

/** \brief Position actuelle du curseur d'action. */
u8 FAT_screenFilesystem_action_cursorX;
/** \brief Position actuelle du curseur. */
u8 FAT_screenFilesystem_cursorY;
/** \brief Numéro de ligne actuellement sélectionnée. */
u8 FAT_screenFilesystem_currentSelectedLine;
u8 FAT_screenFilesystem_getCurrentSelectedLine(){
  return FAT_screenFilesystem_currentSelectedLine;
}

/**
 * \brief Initialisation du curseur (position uniquement), remise à zéro de la ligne
 * sélectionnée.
 */
void FAT_screenFilesystem_initCursor() {
    FAT_screenFilesystem_cursorY = SCREENFILESYSTEM_FIRST_BLOCK_Y - 1;
    FAT_screenFilesystem_currentSelectedLine = 0;
}

/**
 * \brief Cette fonction permet de valider le déplacement du curseur sur l'écran.
 */
void FAT_screenFilesystem_commitCursorMove() {
    FAT_cursors_moveCursor8 (SCREENFILESYSTEM_FIRST_BLOCK_X, FAT_screenFilesystem_cursorY+1);
    FAT_cursors_moveCursor2 (SCREENFILESYSTEM_FIRST_ACTION_X, FAT_screenFilesystem_cursorY);
}

/**
 * \brief Déplace le curseur vers le bas.
 */
void FAT_screenFilesystem_moveCursorDown() {
    if (FAT_screenFilesystem_currentSelectedLine < SCREENFILESYSTEM_NB_LINES_ON_SCREEN - 1) {
        if (!(FAT_screenFilesystem_cursorY >= SCREENFILESYSTEM_LAST_BLOCK_Y - 1)) {
            FAT_screenFilesystem_cursorY += SCREENFILESYSTEM_BLOCK_SIZE_Y;
            FAT_screenFilesystem_currentSelectedLine++;
            FAT_screenFilesystem_printInfos();
        }
    } else {
        FAT_screenFilesystem_cursorY = SCREENFILESYSTEM_FIRST_BLOCK_Y - 1;
        FAT_screenFilesystem_currentSelectedLine = 0;
        FAT_screenFilesystem_printInfos();
    }
}

/**
 * \brief Déplace le curseur vers le haut.
 */
void FAT_screenFilesystem_moveCursorUp() {

    if (FAT_screenFilesystem_currentSelectedLine > 0) {
        if (!(FAT_screenFilesystem_cursorY <= SCREENFILESYSTEM_FIRST_BLOCK_Y - 1)) {
            FAT_screenFilesystem_cursorY -= SCREENFILESYSTEM_BLOCK_SIZE_Y;
            FAT_screenFilesystem_currentSelectedLine--;
            FAT_screenFilesystem_printInfos();
        }
    } else {
        FAT_screenFilesystem_cursorY = (SCREENFILESYSTEM_FIRST_BLOCK_Y - 1) + (SCREENFILESYSTEM_BLOCK_SIZE_Y *15);
        FAT_screenFilesystem_currentSelectedLine = 0xf;
        FAT_screenFilesystem_printInfos();
    }

}
