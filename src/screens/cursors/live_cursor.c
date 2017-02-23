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
* \file live_cursor.c
* \brief Gestion du curseur sur l'écran live.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../../headers/screen_live_cursor.h"

/** \brief Position actuelle du curseur de sélection sur l'écran. */
u8 FAT_screenLive_cursorX;
/** \brief Position actuelle du curseur de sélection sur l'écran. */
u8 FAT_screenLive_cursorY;
/** \brief Numéro de ligne actuellement sélectionnée. */
u8 FAT_screenLive_currentSelectedLine;
u8 FAT_screenLive_getCurrentSelectedLine(){
  return FAT_screenLive_currentSelectedLine;
}
/** \brief Numéro de colonne actuellement sélectionnée. */
u8 FAT_screenLive_currentSelectedColumn;
u8 FAT_screenLive_getCurrentSelectedColumn(){
  return FAT_screenLive_currentSelectedColumn;
}
/** \brief Numéro de colonne dans la table des données (hors séquenceur!) actuellement sélectionnée. */
u8 FAT_screenLive_currentTableSelectedLine;
u8 FAT_screenLive_getCurrentTableSelectedLine(){
  return FAT_screenLive_currentTableSelectedLine;
}

bool FAT_screenLive_isCursorInSequencer = 1;
bool FAT_screenLive_getIsCursorInSequencer (){
  return FAT_screenLive_isCursorInSequencer;
}

/**
 * \brief Change la partie active de l'écran.
 * @param part la partie vers laquelle switcher: 0 = table, 1 = sequenceur
 */
void FAT_screenLive_switchActivePart(bool part) {
    FAT_screenLive_isCursorInSequencer = part;
    FAT_screenLive_currentTableSelectedLine = 0;
    FAT_screenLive_switchCursorToPart(part);
    FAT_screenLive_commitCursorMove();
}

/**
 * \brief Initialisation du curseur (seulement la position) et remise à zéro
 * des valeurs de ligne et colonne sélectionnées.
 */
void FAT_screenLive_initCursor() {
    FAT_screenLive_cursorX = SCREENLIVE_FIRST_BLOCK_X - 1;
    FAT_screenLive_cursorY = SCREENLIVE_FIRST_BLOCK_Y - 1;
    FAT_screenLive_currentSelectedLine = 0;
    FAT_screenLive_setCurrentStartLine (0);
    FAT_screenLive_currentSelectedColumn = 0;
    FAT_screenLive_currentTableSelectedLine = 0;

};

/**
 * \brief Déplace le curseur vers la droite.
 */
void FAT_screenLive_moveCursorRight() {
    if (!(FAT_screenLive_cursorX >= SCREENLIVE_LAST_BLOCK_X - 1)) {

        if (!FAT_screenLive_getIsCursorInSequencer() && FAT_screenLive_currentTableSelectedLine == 2){
            if (FAT_screenLive_currentSelectedColumn == 1){
                FAT_screenLive_cursorX = SCREEN_LIVE_TEMPO_BLOCK_X - 1;
                FAT_screenLive_currentSelectedColumn = 4;
            }
        }else {
            FAT_screenLive_cursorX += SCREENLIVE_BLOCK_SIZE_X + SCREENLIVE_WHITE_SPACE_X;
            FAT_screenLive_currentSelectedColumn++;

        }
        FAT_screenLive_printInfos();
    }
}

/**
 * \brief Déplace le curseur vers la gauche.
 */
void FAT_screenLive_moveCursorLeft() {
    if (!(FAT_screenLive_cursorX <= SCREENLIVE_FIRST_BLOCK_X)) {

        if (!FAT_screenLive_getIsCursorInSequencer() && FAT_screenLive_currentTableSelectedLine == 2){
            if (FAT_screenLive_currentSelectedColumn == 4){
                FAT_screenLive_cursorX = SCREEN_LIVE_MODE_BLOCK_X - 1;
                FAT_screenLive_currentSelectedColumn = 1;
            }
        }else{
            FAT_screenLive_cursorX -= SCREENLIVE_BLOCK_SIZE_X + SCREENLIVE_WHITE_SPACE_X;
            FAT_screenLive_currentSelectedColumn--;
        }
        FAT_screenLive_printInfos();
    }
}

/**
 * \brief Déplace le curseur d'une page vers le bas.
 */
void FAT_screenLive_movePageDown() {
    if (FAT_screenLive_currentSelectedLine < NB_SEQUENCES_IN_ONE_CHANNEL - SCREENLIVE_NB_LINES_ON_SCREEN) {
        FAT_screenLive_incCurrentStartLine (SCREENLIVE_NB_LINES_ON_SCREEN);
        FAT_screenLive_currentSelectedLine += SCREENLIVE_NB_LINES_ON_SCREEN;
        FAT_screenLive_printAllScreenText();
    }
}

/**
 * \brief Déplace le curseur tout en bas du tableau.
 */
void FAT_screenLive_moveCursorAllDown() {
    FAT_screenLive_cursorY = SCREENLIVE_LAST_BLOCK_Y;
    FAT_screenLive_setCurrentStartLine(NB_SEQUENCES_IN_ONE_CHANNEL - SCREENLIVE_NB_LINES_ON_SCREEN);
    FAT_screenLive_currentSelectedLine = NB_SEQUENCES_IN_ONE_CHANNEL - 1;
    FAT_screenLive_printAllScreenText();
}

/**
 * \brief Déplace le curseur vers le bas.
 */
void FAT_screenLive_moveCursorDown() {
    if (FAT_screenLive_getIsCursorInSequencer()){
        if (FAT_screenLive_currentSelectedLine < NB_SEQUENCES_IN_ONE_CHANNEL) {
            if (FAT_screenLive_cursorY >= SCREENLIVE_LAST_BLOCK_Y - 1) {
                if (FAT_screenLive_getCurrentStartLine() < NB_SEQUENCES_IN_ONE_CHANNEL - SCREENLIVE_NB_LINES_ON_SCREEN) {
                    // on n'avance pas mais on change de ligne
                    FAT_screenLive_incCurrentStartLine(1);
                    FAT_screenLive_currentSelectedLine++;
                    FAT_screenLive_printAllScreenText();
                }
            } else {
                FAT_screenLive_cursorY += SCREENLIVE_BLOCK_SIZE_Y;
                FAT_screenLive_currentSelectedLine++;
                FAT_screenLive_printInfos();
            }
        }
    } else {
        if (FAT_screenLive_currentTableSelectedLine < 2){
            FAT_screenLive_currentTableSelectedLine ++;
            if (FAT_screenLive_currentTableSelectedLine == 2){
                FAT_cursors_hideCursor2();
                FAT_cursors_showCursor3();

                FAT_screenLive_cursorY += SCREENLIVE_BLOCK_SIZE_Y * 2;

                if (FAT_screenLive_currentSelectedColumn<3){
                    FAT_screenLive_cursorX = SCREEN_LIVE_MODE_BLOCK_X - 1;
                    FAT_screenLive_currentSelectedColumn = 1;
                } else {
                    FAT_screenLive_cursorX = SCREEN_LIVE_TEMPO_BLOCK_X - 1;
                    FAT_screenLive_currentSelectedColumn = 4;
                }

                // pour éviter une désynchro sur le numéro de la colonne (visuellement on est sur la 2)
                FAT_screenLive_printInfos();

            }else{
                FAT_screenLive_cursorY += SCREENLIVE_BLOCK_SIZE_Y;
            }
        }
    }
}

/**
 * \brief Déplace le curseur d'une page vers le haut.
 */
void FAT_screenLive_movePageUp() {
    if (FAT_screenLive_currentSelectedLine >= SCREENLIVE_NB_LINES_ON_SCREEN
            && FAT_screenLive_getCurrentStartLine() >= SCREENLIVE_NB_LINES_ON_SCREEN) {
        FAT_screenLive_decCurrentStartLine(SCREENLIVE_NB_LINES_ON_SCREEN);
        FAT_screenLive_currentSelectedLine -= SCREENLIVE_NB_LINES_ON_SCREEN;
        FAT_screenLive_printAllScreenText();
    }
}

/**
 * \brief Déplace le curseur tout en haut du tableau.
 */
void FAT_screenLive_moveCursorAllUp() {
    FAT_screenLive_cursorY = SCREENLIVE_FIRST_BLOCK_Y - 1;
    FAT_screenLive_setCurrentStartLine(0);
    FAT_screenLive_currentSelectedLine = 0;
    FAT_screenLive_printAllScreenText();
}

/**
 * \brief Déplace le curseur vers le haut.
 */
void FAT_screenLive_moveCursorUp() {
    if (FAT_screenLive_getIsCursorInSequencer()){
        if (FAT_screenLive_currentSelectedLine > 0) {
            if (FAT_screenLive_cursorY <= SCREENLIVE_FIRST_BLOCK_Y - 1) {
                if (FAT_screenLive_getCurrentStartLine() > 0) {
                    // on ne recule pas mais on change de ligne
                    FAT_screenLive_decCurrentStartLine(1);
                    FAT_screenLive_currentSelectedLine--;
                    FAT_screenLive_printAllScreenText();
                }
            } else {
                FAT_screenLive_cursorY -= SCREENLIVE_BLOCK_SIZE_Y;
                FAT_screenLive_currentSelectedLine--;
                FAT_screenLive_printInfos();
            }
        }
    } else {
        if (FAT_screenLive_currentTableSelectedLine > 0){
            if (FAT_screenLive_currentTableSelectedLine == 2){

                FAT_cursors_hideCursor3();
                FAT_cursors_showCursor2();

                FAT_screenLive_cursorY -= SCREENLIVE_BLOCK_SIZE_Y * 2;

            }else{
                FAT_screenLive_cursorY -= SCREENLIVE_BLOCK_SIZE_Y;
            }
            FAT_screenLive_currentTableSelectedLine --;
        }
    }

}

/**
 * \brief Change la position du curseur sur la partie active de l'écran.
 * @param part la partie vers laquelle switcher: 0 = table, 1 = sequenceur
 */
void FAT_screenLive_switchCursorToPart (bool part){
    FAT_cursors_hideCursor3();
    FAT_cursors_showCursor2();
    if (part == 1){
        // sequenceur.
        FAT_screenLive_cursorY = SCREENLIVE_FIRST_BLOCK_Y - 1 + (8* (FAT_screenLive_currentSelectedLine-FAT_screenLive_getCurrentStartLine()));
    } else {
        // table
        FAT_screenLive_cursorY = SCREENLIVE_FIRST_TABLE_DATA_Y - 1;
    }
    return;
}

/**
 * \brief Valide le déplacement du curseur sur l'écran.
 */
void FAT_screenLive_commitCursorMove() {
    if (FAT_screenLive_getIsCursorInSequencer()){
        FAT_cursors_moveCursor2 (FAT_screenLive_cursorX, FAT_screenLive_cursorY);
    } else {
        if (FAT_screenLive_currentTableSelectedLine == 2) {
            FAT_cursors_moveCursor3 (FAT_screenLive_cursorX, FAT_screenLive_cursorY);
        }else {
            FAT_cursors_moveCursor2 (FAT_screenLive_cursorX, FAT_screenLive_cursorY);
        }
    }
}
