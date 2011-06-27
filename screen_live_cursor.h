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

/** \brief Position actuelle du curseur de sélection sur l'écran. */
u8 FAT_screenLive_cursorX; 
/** \brief Position actuelle du curseur de sélection sur l'écran. */
u8 FAT_screenLive_cursorY;
/** \brief Numéro de ligne actuellement sélectionnée. */
u8 FAT_screenLive_currentSelectedLine; 
/** \brief Numéro de colonne actuellement sélectionnée. */
u8 FAT_screenLive_currentSelectedColumn;

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
    
};

/**
 * \brief Déplace le curseur vers la droite. 
 */
void FAT_screenLive_moveCursorRight() {
    if (!(FAT_screenLive_cursorX >= SCREENLIVE_LAST_BLOCK_X - 1)) {
        FAT_screenLive_cursorX += SCREENLIVE_BLOCK_SIZE_X + SCREENLIVE_WHITE_SPACE_X;
        FAT_screenLive_currentSelectedColumn++;
        FAT_screenLive_printInfos();
    }
}

/**
 * \brief Déplace le curseur vers la gauche. 
 */
void FAT_screenLive_moveCursorLeft() {
    if (!(FAT_screenLive_cursorX <= SCREENLIVE_FIRST_BLOCK_X)) {
        FAT_screenLive_cursorX -= SCREENLIVE_BLOCK_SIZE_X + SCREENLIVE_WHITE_SPACE_X;
        FAT_screenLive_currentSelectedColumn--;
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
    FAT_screenLive_cursorY = SCREENLIVE_FIRST_BLOCK_Y-1;
    FAT_screenLive_currentStartLine = 0;
    FAT_screenLive_currentSelectedLine = 0;
    FAT_screenLive_printAllScreenText();
}

/**
 * \brief Déplace le curseur vers le haut. 
 */
void FAT_screenLive_moveCursorUp() {

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

}

/**
 * \brief Valide le déplacement du curseur sur l'écran. 
 */
void FAT_screenLive_commitCursorMove() {
    ham_SetObjXY(FAT_cursor2_obj, FAT_screenLive_cursorX, FAT_screenLive_cursorY);
}

#endif
