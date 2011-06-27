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
 * \file screen_live.h
 * \brief Fichier contenant toutes les fonctions pour gérer l'écran LIVE.
 */

#ifndef _SCREEN_LIVE_H_
#define _SCREEN_LIVE_H_

/** \brief Le nombre maximal de ligne affichées à l'écran. */
#define SCREENLIVE_NB_LINES_ON_SCREEN 10
/** \brief Définition interface : numéro de la tile pour début de l'affichage (Y). */
#define SCREENLIVE_LINE_START_Y 2
/** \brief Définition interface : numéro de la tile pour début de l'affichage des lignes ! (X). */
#define SCREENLIVE_LINE_X 0
/** \brief Définition interface : taille que prend une ligne en tile (1). */
#define SCREENLIVE_LINE_SIZE_Y 1
/** \brief Définition interface : numéro de la tile pour début de l'affichage des séquences (X). */
#define SCREENLIVE_SEQUENCE_LINE_X 3

/** \brief Permet de savoir si la popup de déplacement est affichée au dessus de l'écran. */
bool FAT_screenLive_isPopuped = 0;

/** \brief Cette variable contient le numéro de la première ligne actuellement affichée. */
u8 FAT_screenLive_currentStartLine = 0;

// prototypes
void FAT_screenLive_init();
void FAT_screenLive_checkButtons();
void FAT_screenLive_printInfos();
void FAT_screenLive_printAllScreenText();

#include "screen_live_cursor.h"

/**
 * \brief Affiche quelques infos (nom du projet, ligne actuellement sélectionnée et nom du channel)
 * sur l'écran. 
 */
void FAT_screenLive_printInfos() {
    mutex = 0;
    ham_DrawText(24, 3, "LIVE!");
    ham_DrawText(24, 5, "LMODE");
    ham_DrawText(24, 8, "TEMPO");
    ham_DrawText(24, 11, "TRNSP");
    mutex = 1;
}

/**
 * \brief Imprime les numéros de lignes. 
 * 
 * L'impression démarre depuis la valeur de FAT_screenLive_currentStartLine jusqu'à FAT_screenLive_currentStartLine + screenLive_NB_LINES_ON_SCREEN
 */
void FAT_screenLive_printLineColumns() {
    u8 y = SCREENLIVE_LINE_START_Y;
    mutex = 0;
    for (int c = FAT_screenLive_currentStartLine; c < (SCREENLIVE_NB_LINES_ON_SCREEN + FAT_screenLive_currentStartLine); c++) {
        ham_DrawText(SCREENLIVE_LINE_X, y, FAT_FORMAT_LINE, c);
        y += SCREENLIVE_LINE_SIZE_Y;
    }
    mutex = 1;
}

/**
 * \brief Affiche une seule séquence. 
 *  
 * @param channel le numéro de channel sur lequel la séquence est inscrite
 * @param lineOnScreen le numéro de ligne à l'écran, compris entre 0 et screenLive_NB_LINES_ON_SCREEN
 * @param realLine le vrai numéro de ligne dans le tracker ou la séquence a été inscrite
 */
void FAT_screenLive_printSequence(u8 channel, u8 lineOnScreen, u8 realLine) {
    mutex = 0;
    if (FAT_tracker.channels[channel].sequences[realLine] != NULL_VALUE) {
        ham_DrawText(SCREENLIVE_SEQUENCE_LINE_X + (3 * channel),
                lineOnScreen + SCREENLIVE_LINE_START_Y,
                "%.2x\0", FAT_tracker.channels[channel].sequences[realLine]);
    } else {
        ham_DrawText(SCREENLIVE_SEQUENCE_LINE_X + (3 * channel),
                lineOnScreen + SCREENLIVE_LINE_START_Y, "  ");
    }
    mutex = 1;
}

/**
 * \brief Affiche toutes les séquences actuellement visibles.  
 */
void FAT_screenLive_printSequences() {
    u8 c;
    mutex = 0;
    for (u8 v = 0; v < SCREENLIVE_NB_LINES_ON_SCREEN; v++) {

        for (c = 0; c < 6; c++) {
            if (FAT_tracker.channels[c].sequences[v + FAT_screenLive_currentStartLine] == NULL_VALUE) {
                ham_DrawText(SCREENLIVE_SEQUENCE_LINE_X + (c * 3),
                        v + SCREENLIVE_LINE_START_Y, "  ");
            } else {
                ham_DrawText(SCREENLIVE_SEQUENCE_LINE_X + (c * 3),
                        v + SCREENLIVE_LINE_START_Y, "%.2x ",
                        FAT_tracker.channels[c].sequences[v + FAT_screenLive_currentStartLine]);
            }
        }

    }
    mutex = 1;
}

/**
 * \brief Affiche tout le texte à l'écran (numéros de lignes, séquences et infos).
 */
void FAT_screenLive_printAllScreenText() {
    FAT_screenLive_printLineColumns();
    FAT_screenLive_printSequences();
    FAT_screenLive_printInfos();
}

/**
 * \brief Initialisation de l'écran. 
 */
void FAT_screenLive_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_live_Tiles, SIZEOF_16BIT(screen_live_Tiles), 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_live_Map, 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);
    
    FAT_screenLive_printAllScreenText();
    
    // affichage du curseur
    FAT_cursors_hideCursor2();
    FAT_screenLive_commitCursorMove();
    FAT_cursors_showCursor2();

}

/**
 * \brief Teste les actions utilisateurs. 
 */
void FAT_screenLive_checkButtons() {
    if (F_CTRLINPUT_SELECT_PRESSED) {
        if (!FAT_screenLive_isPopuped) {
            // TODO hide project cursor
            FAT_popup_show();
            FAT_screenLive_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenLive_isPopuped) {
            FAT_popup_hide();
            // TODO show project cursor
            FAT_screenLive_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_LIVE_ID) {
                // TODO hide project cursor
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (F_CTRLINPUT_RIGHT_PRESSED) {
            iCanPressAKey = 0;
            FAT_screenLive_moveCursorRight();
        }

        if (F_CTRLINPUT_LEFT_PRESSED) {
            iCanPressAKey = 0;
            FAT_screenLive_moveCursorLeft();
        }

        if (F_CTRLINPUT_DOWN_PRESSED) {
            iCanPressAKey = 0;
            if (F_CTRLINPUT_R_PRESSED) {
                    FAT_screenLive_movePageDown();
                } else if (F_CTRLINPUT_L_PRESSED) {
                    FAT_screenLive_moveCursorAllDown();
                } else {
                    FAT_screenLive_moveCursorDown();
                }
        }

        if (F_CTRLINPUT_UP_PRESSED) {
            iCanPressAKey = 0;
            if (F_CTRLINPUT_R_PRESSED) {
                    FAT_screenLive_movePageUp();
                } else if (F_CTRLINPUT_L_PRESSED) {
                    FAT_screenLive_moveCursorAllUp();
                } else {
                    FAT_screenLive_moveCursorUp();
                }
        }

        if (F_CTRLINPUT_A_PRESSED) {
            iCanPressAKey = 0;

        }

        FAT_screenLive_commitCursorMove();
        FAT_keys_waitForAnotherKeyTouch();
    }
}


#endif
