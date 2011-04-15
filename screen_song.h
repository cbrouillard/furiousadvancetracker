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
#ifndef _SCREEN_SONG_H_
#define _SCREEN_SONG_H_

// le nombre maximal de ligne affichées à l'écran
#define SCREENSONG_NB_LINES_ON_SCREEN 16
// définition interface : numéro de la tile pour début de l'affichage (Y)
#define SCREENSONG_LINE_START_Y 2
// définition interface : numéro de la tile pour début de l'affichage des lignes ! (X)
#define SCREENSONG_LINE_X 0
//// définition interface : taille que prend une ligne en tile (1)
#define SCREENSONG_LINE_SIZE_Y 1
// définition interface : numéro de la tile pour début de l'affichage des séquences (X)
#define SCREENSONG_SEQUENCE_LINE_X 3

// cette variable contient le numéro de la première ligne actuellement affichée
u8 FAT_screenSong_currentStartLine = 0;
// cette variable permet de savoir si l'écran song est actuellement sous la popup
// todo cette variable pourrait etre mutualisée pour tous les écrans ?
bool FAT_screenSong_isPopuped = 0;

// prototypes
void FAT_screenSong_init();
void FAT_screenSong_mainFunc();
void FAT_screenSong_checkButtons();
void FAT_screenSong_printLineColumns();
void FAT_screenSong_printAllScreenText();
void FAT_screenSong_printInfos();
void FAT_screenSong_pressA();
void FAT_screenSong_pressB();
////////////////////////////////////////////////////

#include "screen_song_cursor.h"

void FAT_screenSong_mainFunc() {
    speedCounter++;
    if (mutex) {
        ham_CopyObjToOAM();
        FAT_screenSong_checkButtons();
    }
}

void FAT_screenSong_init() {

    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[2].ti = ham_InitTileSet((void*) screen_song_Tiles, SIZEOF_16BIT(screen_song_Tiles), 1, 1);
    ham_bg[2].mi = ham_InitMapSet((void *) screen_song_Map, 1024, 0, 0);
    ham_InitBg(2, 1, 3, 0);

    FAT_screenSong_initCursor();

    // affichage du curseur
    FAT_cursors_showCursor2();

    // affichage du numéro des lignes, des séquences, ...
    FAT_screenSong_printAllScreenText();

    // démarrage du cycle pour l'écran
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_screenSong_mainFunc);
}

void FAT_screenSong_printInfos() {
    mutex = 0;
    ham_DrawText(21, 3, "%s", FAT_tracker.songName);
    ham_DrawText(21, 4, "LINE  %.2x", FAT_screenSong_currentSelectedLine);
    ham_DrawText(21, 5, "CHAN  %2x", FAT_screenSong_currentSelectedColumn + 1);
    mutex = 1;
}

void FAT_screenSong_printLineColumns() {
    u8 y = SCREENSONG_LINE_START_Y;
    mutex = 0;
    for (int c = FAT_screenSong_currentStartLine; c < (SCREENSONG_NB_LINES_ON_SCREEN + FAT_screenSong_currentStartLine); c++) {
        ham_DrawText(SCREENSONG_LINE_X, y, FAT_FORMAT_LINE, c);
        y += SCREENSONG_LINE_SIZE_Y;
    }
    mutex = 1;
}

void FAT_screenSong_printSequences() {
    u8 c;
    mutex = 0;
    for (u8 v = 0; v < SCREENSONG_NB_LINES_ON_SCREEN; v++) {

        for (c = 0; c < 6; c++) {
            if (FAT_tracker.channels[c].sequences[v + FAT_screenSong_currentStartLine] == NULL_VALUE) {
                ham_DrawText(SCREENSONG_SEQUENCE_LINE_X + (c * 3),
                        v + SCREENSONG_LINE_START_Y, "  ");
            } else {
                ham_DrawText(SCREENSONG_SEQUENCE_LINE_X + (c * 3),
                        v + SCREENSONG_LINE_START_Y, "%.2x ",
                        FAT_tracker.channels[c].sequences[v + FAT_screenSong_currentStartLine]);
            }
        }

    }
    mutex = 1;
}

void FAT_screenSong_printSequence(u8 channel, u8 lineOnScreen, u8 realLine) {
    mutex = 0;
    if (FAT_tracker.channels[channel].sequences[realLine] != NULL_VALUE) {
        ham_DrawText(SCREENSONG_SEQUENCE_LINE_X + (3 * channel),
                lineOnScreen + SCREENSONG_LINE_START_Y,
                "%.2x\0", FAT_tracker.channels[channel].sequences[realLine]);
    } else {
        ham_DrawText(SCREENSONG_SEQUENCE_LINE_X + (3 * channel),
                lineOnScreen + SCREENSONG_LINE_START_Y, "  ");
    }
    mutex = 1;
}

void FAT_screenSong_printAllScreenText() {
    FAT_screenSong_printLineColumns();
    FAT_screenSong_printSequences();
    FAT_screenSong_printInfos();
}

void FAT_screenSong_checkButtons() {

    if (F_CTRLINPUT_SELECT_PRESSED) {
        if (!FAT_screenSong_isPopuped) {
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenSong_isPopuped = 1;
        }

        if (speedCounter >= SLOWDOWN_COUNTER) {
            FAT_popup_checkButtons();
            speedCounter = 0;
        }

    } else {
        if (FAT_screenSong_isPopuped) {
            FAT_popup_hide();
            FAT_cursors_showCursor2();
            FAT_screenSong_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_SONG_ID) {
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (speedCounter >= SLOWDOWN_COUNTER) {
            if (F_CTRLINPUT_A_PRESSED) {

                FAT_screenSong_pressA();

            } else {

                if (F_CTRLINPUT_START_PRESSED) {
                    if (!FAT_isCurrentlyPlaying) {
                        FAT_player_startPlayerFromSequences(FAT_screenSong_currentSelectedLine);
                    } else {
                        FAT_player_stopPlayer();
                    }
                }

                if (F_CTRLINPUT_B_PRESSED) {
                    FAT_screenSong_pressB();
                }

                if (F_CTRLINPUT_RIGHT_PRESSED) {
                    FAT_screenSong_moveCursorRight();
                }

                if (F_CTRLINPUT_LEFT_PRESSED) {
                    FAT_screenSong_moveCursorLeft();
                }

                if (F_CTRLINPUT_DOWN_PRESSED) {
                    if (F_CTRLINPUT_R_PRESSED) {
                        FAT_screenSong_movePageDown();
                    } else if (F_CTRLINPUT_L_PRESSED) {
                        FAT_screenSong_moveCursorAllDown();
                    } else {
                        FAT_screenSong_moveCursorDown();
                    }
                }

                if (F_CTRLINPUT_UP_PRESSED) {
                    if (F_CTRLINPUT_R_PRESSED) {
                        FAT_screenSong_movePageUp();
                    } else if (F_CTRLINPUT_L_PRESSED) {
                        FAT_screenSong_moveCursorAllUp();
                    } else {
                        FAT_screenSong_moveCursorUp();
                    }
                }
                FAT_screenSong_commitCursorMove();
            }
            speedCounter = 0;
        }
    }

}

void FAT_screenSong_pressB() {
    if (F_CTRLINPUT_L_PRESSED) {

        if (FAT_data_isSequenceAllocatable(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine)) {
            // espace vide
            FAT_data_pasteSequenceWithNewNumber(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        } else {
            FAT_data_copySequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        }

    } else {

        if (FAT_data_isSequenceAllocatable(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine)) {
            // espace vide
            FAT_data_pasteSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        } else {
            FAT_data_cutSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        }
    }

    FAT_screenSong_printSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine - FAT_screenSong_currentStartLine, FAT_screenSong_currentSelectedLine);
}

void FAT_screenSong_pressA() {
    if (F_CTRLINPUT_L_PRESSED) {
        FAT_data_smartAllocateSequence(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine);
    } else {
        FAT_data_allocateSequence(
                FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine);
    }

    if (F_CTRLINPUT_RIGHT_PRESSED) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, 1); // ajout de 1
    }

    if (F_CTRLINPUT_LEFT_PRESSED) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, -1); // retrait de 1
    }

    if (F_CTRLINPUT_UP_PRESSED) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, 16);
    }

    if (F_CTRLINPUT_DOWN_PRESSED) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, -16);
    }

    FAT_screenSong_printSequence(
            FAT_screenSong_currentSelectedColumn,
            FAT_screenSong_currentSelectedLine - FAT_screenSong_currentStartLine,
            FAT_screenSong_currentSelectedLine);
}

#endif
