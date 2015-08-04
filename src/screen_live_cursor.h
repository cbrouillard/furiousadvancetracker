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
 * \file screen_song_cursor.h
 * \brief Ce fichier contient toutes les définitions de fonctions utiles pour la gestion
 * du curseur sur l'écran SONG.
 */

#ifndef _SCREENLIVECURSOR_H_
#define _SCREENLIVECURSOR_H_

/** \brief Position actuelle du curseur de sélection sur l'écran. */
u8 FAT_screenLive_cursorX;
/** \brief Position actuelle du curseur de sélection sur l'écran. */
u8 FAT_screenLive_cursorY;
/** \brief Numéro de ligne actuellement sélectionnée. */
u8 FAT_screenLive_currentSelectedLine;
/** \brief Numéro de colonne actuellement sélectionnée. */
u8 FAT_screenLive_currentSelectedColumn;
/** \brief Numéro de colonne dans la table des données (hors séquenceur!) actuellement sélectionnée. */
u8 FAT_screenLive_currentTableSelectedLine;

#include "screen_live.h"

/** \brief Taille d'un bloc d'affichage séquence 16*8 en pixels. */
#define SCREENLIVE_BLOCK_SIZE_X 16
/** \brief Taille d'un bloc d'affichage séquence 16*8 en pixels. */
#define SCREENLIVE_BLOCK_SIZE_Y 8

// paramètre de l'interface
/** \brief Espace définit entre chaque colonne (px). */
#define SCREENLIVE_WHITE_SPACE_X 8
/** \brief Coordonnée du dernier bloc en bas à droite de l'écran (px). */
#define SCREENLIVE_LAST_BLOCK_X 143
/** \brief Absisse du dernier bloc en bas à droite de l'écran (px). */
#define SCREENLIVE_LAST_BLOCK_Y 87
/** \brief Coordonnée du premier bloc en haut à gauche (px). */
#define SCREENLIVE_FIRST_BLOCK_X 24
/** \brief Abscisse du premier bloc en haut à gauche (px). */
#define SCREENLIVE_FIRST_BLOCK_Y 16

/** \brief Abscisse du premier bloc de données inscrites dans la table (partie basse de l'écran). */
#define SCREENLIVE_FIRST_TABLE_DATA_Y 104

#define SCREEN_LIVE_MODE_BLOCK_X 48
#define SCREEN_LIVE_TEMPO_BLOCK_X 120

// prototypes
void FAT_screenLive_initCursor();
void FAT_screenLive_moveCursorRight();
void FAT_screenLive_moveCursorLeft();
void FAT_screenLive_moveCursorDown();
void FAT_screenLive_moveCursorUp();
void FAT_screenLive_commitCursorMove();

/**
 * \brief Initialisation du curseur (seulement la position) et remise à zéro
 * des valeurs de ligne et colonne sélectionnées. 
 */
void FAT_screenLive_initCursor() {
    FAT_screenLive_cursorX = SCREENLIVE_FIRST_BLOCK_X - 1;
    FAT_screenLive_cursorY = SCREENLIVE_FIRST_BLOCK_Y - 1;
    FAT_screenLive_currentSelectedLine = 0;
    FAT_screenLive_currentStartLine = 0;
    FAT_screenLive_currentSelectedColumn = 0;
    FAT_screenLive_currentTableSelectedLine = 0;

};

/**
 * \brief Déplace le curseur vers la droite. 
 */
void FAT_screenLive_moveCursorRight() {
    if (!(FAT_screenLive_cursorX >= SCREENLIVE_LAST_BLOCK_X - 1)) {

        if (!FAT_screenLive_isCursorInSequencer && FAT_screenLive_currentTableSelectedLine == 2){
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

        if (!FAT_screenLive_isCursorInSequencer && FAT_screenLive_currentTableSelectedLine == 2){
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
        FAT_screenLive_currentStartLine += SCREENLIVE_NB_LINES_ON_SCREEN;
        FAT_screenLive_currentSelectedLine += SCREENLIVE_NB_LINES_ON_SCREEN;
        FAT_screenLive_printAllScreenText();
    }
}

/**
 * \brief Déplace le curseur tout en bas du tableau. 
 */
void FAT_screenLive_moveCursorAllDown() {
    FAT_screenLive_cursorY = SCREENLIVE_LAST_BLOCK_Y;
    FAT_screenLive_currentStartLine = NB_SEQUENCES_IN_ONE_CHANNEL - SCREENLIVE_NB_LINES_ON_SCREEN;
    FAT_screenLive_currentSelectedLine = NB_SEQUENCES_IN_ONE_CHANNEL - 1;
    FAT_screenLive_printAllScreenText();
}

/**
 * \brief Déplace le curseur vers le bas. 
 */
void FAT_screenLive_moveCursorDown() {
    if (FAT_screenLive_isCursorInSequencer){
        if (FAT_screenLive_currentSelectedLine < NB_SEQUENCES_IN_ONE_CHANNEL) {
            if (FAT_screenLive_cursorY >= SCREENLIVE_LAST_BLOCK_Y - 1) {
                if (FAT_screenLive_currentStartLine < NB_SEQUENCES_IN_ONE_CHANNEL - SCREENLIVE_NB_LINES_ON_SCREEN) {
                    // on n'avance pas mais on change de ligne
                    FAT_screenLive_currentStartLine++;
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
            && FAT_screenLive_currentStartLine >= SCREENLIVE_NB_LINES_ON_SCREEN) {
        FAT_screenLive_currentStartLine -= SCREENLIVE_NB_LINES_ON_SCREEN;
        FAT_screenLive_currentSelectedLine -= SCREENLIVE_NB_LINES_ON_SCREEN;
        FAT_screenLive_printAllScreenText();
    }
}

/**
 * \brief Déplace le curseur tout en haut du tableau. 
 */
void FAT_screenLive_moveCursorAllUp() {
    FAT_screenLive_cursorY = SCREENLIVE_FIRST_BLOCK_Y - 1;
    FAT_screenLive_currentStartLine = 0;
    FAT_screenLive_currentSelectedLine = 0;
    FAT_screenLive_printAllScreenText();
}

/**
 * \brief Déplace le curseur vers le haut. 
 */
void FAT_screenLive_moveCursorUp() {
    if (FAT_screenLive_isCursorInSequencer){
        if (FAT_screenLive_currentSelectedLine > 0) {
            if (FAT_screenLive_cursorY <= SCREENLIVE_FIRST_BLOCK_Y - 1) {
                if (FAT_screenLive_currentStartLine > 0) {
                    // on ne recule pas mais on change de ligne
                    FAT_screenLive_currentStartLine--;
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
    if (part == 1){
        // sequenceur.
        FAT_screenLive_cursorY = SCREENLIVE_FIRST_BLOCK_Y - 1 + (8* (FAT_screenLive_currentSelectedLine-FAT_screenLive_currentStartLine));
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
    if (FAT_screenLive_isCursorInSequencer){
        hel_ObjSetXY(FAT_cursor2_obj, FAT_screenLive_cursorX, FAT_screenLive_cursorY);
    } else {
        if (FAT_screenLive_currentTableSelectedLine == 2) {
            hel_ObjSetXY(FAT_cursor3_obj, FAT_screenLive_cursorX, FAT_screenLive_cursorY);
        }else {
            hel_ObjSetXY(FAT_cursor2_obj, FAT_screenLive_cursorX, FAT_screenLive_cursorY);
        }
    }
}

#endif
