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
#ifndef _SCREEN_NOTES_H_
#define _SCREEN_NOTES_H_

#define SCREENNOTES_LINE_START_Y 2
#define SCREENNOTES_NB_LINES_ON_SCREEN 16
#define SCREENNOTES_LINE_X 0
#define SCREENNOTES_EFFECT_LINE_X 10
#define SCREENNOTES_LINE_SIZE_Y 1

#define SCREENNOTES_NOTE_LINE_X 3

#define SCREENNOTES_COLUMN_ID_NOTES 0
#define SCREENNOTES_COLUMN_ID_INST 1
#define SCREENNOTES_COLUMN_ID_CMD_NAME 2
#define SCREENNOTES_COLUMN_ID_CMD_PARAM 3

// prototypes
void FAT_screenNotes_init();
void FAT_screenNotes_checkButtons();
void FAT_screenNotes_printLineColumns();
void FAT_screenNotes_pressA();
void FAT_screenNotes_pressB();
void FAT_screenNotes_printInfos();

bool FAT_screenNotes_isPopuped = 0;
u8 FAT_screenNotes_currentBlockId;

#include "screen_notes_cursor.h"
#include "screen_song_cursor.h"
#include "data.h"
#include "cursors.h"

void FAT_screenNotes_mainFunc() {
    if (mutex) {
        speedCounter++;
        ham_CopyObjToOAM();
        FAT_screenNotes_checkButtons();
    }
}

void FAT_screenNotes_printLineColumns() {
    mutex = 0;
    u8 y = SCREENNOTES_LINE_START_Y;
    for (int c = 0; c < (SCREENNOTES_NB_LINES_ON_SCREEN); c++) {
        ham_DrawText(SCREENNOTES_LINE_X, y, FAT_FORMAT_LINE, c);
        y += SCREENNOTES_LINE_SIZE_Y;
    }
    mutex = 1;
}

void FAT_screenNotes_printInfos() {
    mutex = 0;
    ham_DrawText(18, 4, "LINE     %.2x", FAT_screenNotes_currentSelectedLine);
    //ham_DrawText(21, 4, "CHAN %2x", FAT_screenSong_currentSelectedColumn+1);
    mutex = 1;
}

void FAT_screenNotes_printNote(u8 line) {
    mutex = 0;
    if (!FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, line)) {
        note* actualNote = FAT_data_getNote(FAT_screenNotes_currentBlockId, line);

        ham_DrawText(SCREENNOTES_NOTE_LINE_X,
                line + SCREENNOTES_LINE_START_Y,
                "%s%1x %.2x\0", noteName[(actualNote->note & 0xf0) >> 4], actualNote->note & 0x0f, actualNote->instrument);
    } else {
        ham_DrawText(SCREENNOTES_NOTE_LINE_X,
                line + SCREENNOTES_LINE_START_Y, "      \0");
    }
    mutex = 1;
}

void FAT_screenNotes_printEffect(u8 line) {
    mutex = 0;
    if (!FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, line)) {

        effect* effect = FAT_data_note_getEffect(FAT_screenNotes_currentBlockId, line);

        ham_DrawText(SCREENNOTES_EFFECT_LINE_X, line + SCREENNOTES_LINE_START_Y,
                "%.2s%.2x\0", noteEffectName[(effect->name & 0xfe) >> 1], effect->value);
    } else {
        ham_DrawText(SCREENNOTES_EFFECT_LINE_X, line + SCREENNOTES_LINE_START_Y,
                "    ");
    }
    mutex = 1;
}

void FAT_screenNotes_printAllNotes() {
    mutex = 0;
    for (u8 b = 0; b < SCREENNOTES_NB_LINES_ON_SCREEN; b++) {
        FAT_screenNotes_printNote(b);
        FAT_screenNotes_printEffect(b);
    }
    mutex = 1;
}

void FAT_screenNotes_printBlockNumber() {
    mutex = 0;
    ham_DrawText(18, 3, "BLOCK    %.2x", FAT_screenNotes_currentBlockId);
    mutex = 1;
}

void FAT_screenNotes_printAllScreenText() {
    FAT_screenNotes_printLineColumns();
    FAT_screenNotes_printAllNotes();
    FAT_screenNotes_printInfos();
}

void FAT_screenNotes_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[2].ti = ham_InitTileSet((void*) screen_notes_Tiles, SIZEOF_16BIT(screen_notes_Tiles), 1, 1);
    ham_bg[2].mi = ham_InitMapSet((void *) screen_notes_Map, 1024, 0, 0);
    ham_InitBg(2, 1, 3, 0);

    // affichage d'un peu de texte
    FAT_screenNotes_currentBlockId = FAT_data_getBlock(FAT_screenBlocks_currentSequenceId, FAT_screenBlocks_currentSelectedLine);
    if (FAT_screenNotes_currentBlockId == NULL_VALUE) {
        FAT_screenNotes_currentBlockId = 0;
    }
    FAT_screenNotes_printBlockNumber();
    FAT_screenNotes_printAllScreenText();

    // démarrage du cycle pour l'écran
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_screenNotes_mainFunc);

    // affichage du curseur
    FAT_cursors_hideCursor2();
    FAT_cursors_hideCursor3();
    FAT_screenNotes_commitCursorMove();
    if (FAT_screenNotes_currentSelectedColumn == 0) {
        FAT_cursors_showCursor3();
    } else {
        FAT_cursors_showCursor2();
    }
    FAT_cursors_moveCursorChange(INPUT_R_CURSOR_CHANGE_X, INPUT_R_CURSOR_CHANGE_Y);
}

void FAT_screenNotes_checkButtons() {
    if (F_CTRLINPUT_SELECT_PRESSED) {
        if (!FAT_screenNotes_isPopuped) {
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenNotes_isPopuped = 1;
        }

        if (speedCounter >= SLOWDOWN_COUNTER) {
            FAT_popup_checkButtons();
            speedCounter = 0;
        }

    } else {
        if (FAT_screenNotes_isPopuped) {
            FAT_popup_hide();
            if (FAT_screenNotes_currentSelectedColumn == 0) {
                FAT_cursors_showCursor3();
            } else {
                FAT_cursors_showCursor2();
            }
            FAT_screenNotes_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_NOTES_ID) {
                FAT_cursors_hideCursor3();
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (speedCounter >= SLOWDOWN_COUNTER) {

            if (F_CTRLINPUT_A_PRESSED) {

                FAT_screenNotes_pressA();

            } else {

                if (F_CTRLINPUT_R_PRESSED) {

                    FAT_cursors_showCursorChange();

                    if (F_CTRLINPUT_RIGHT_PRESSED) {
                        if (FAT_screenNotes_currentBlockId < NB_MAX_BLOCKS - 1) {
                            FAT_screenNotes_currentBlockId++;
                            FAT_screenNotes_printBlockNumber();
                            FAT_screenNotes_printAllScreenText();
                        }
                    }

                    if (F_CTRLINPUT_LEFT_PRESSED) {
                        if (FAT_screenNotes_currentBlockId > 0) {
                            FAT_screenNotes_currentBlockId--;
                            FAT_screenNotes_printBlockNumber();
                            FAT_screenNotes_printAllScreenText();
                        }
                    }

                    if (F_CTRLINPUT_DOWN_PRESSED) {
                        // TODO passer au block suivant dans la séquence
                    }

                    if (F_CTRLINPUT_UP_PRESSED) {
                        // TODO passer au block précédent dans la séquence
                    }

                } else {

                    FAT_cursors_hideCursorChange();

                    if (F_CTRLINPUT_B_PRESSED) {
                        FAT_screenNotes_pressB();
                    }

                    if (F_CTRLINPUT_START_PRESSED) {
                        if (!FAT_isCurrentlyPlaying) {
                            FAT_player_startPlayerFromNotes(FAT_screenNotes_currentBlockId,
                                    FAT_screenNotes_currentSelectedLine, FAT_screenSong_currentSelectedColumn);
                        } else {
                            FAT_player_stopPlayer();
                        }
                    }

                    if (F_CTRLINPUT_RIGHT_PRESSED) {
                        FAT_screenNotes_moveCursorRight();
                    }

                    if (F_CTRLINPUT_LEFT_PRESSED) {
                        FAT_screenNotes_moveCursorLeft();
                    }

                    if (F_CTRLINPUT_DOWN_PRESSED) {
                        FAT_screenNotes_moveCursorDown();
                    }

                    if (F_CTRLINPUT_UP_PRESSED) {

                        FAT_screenNotes_moveCursorUp();
                    }

                    FAT_screenNotes_commitCursorMove();
                }
            }

            speedCounter = 0;
        }
    }
}

void FAT_screenNotes_pressB() {
    switch (FAT_screenNotes_currentSelectedColumn) {
        case SCREENNOTES_COLUMN_ID_NOTES:
        case SCREENNOTES_COLUMN_ID_INST:
            if (FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {
                FAT_data_pasteNote(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            } else {
                FAT_data_cutNote(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            }
            FAT_screenNotes_printNote(FAT_screenNotes_currentSelectedLine);
            break;
        case SCREENNOTES_COLUMN_ID_CMD_NAME:
        case SCREENNOTES_COLUMN_ID_CMD_PARAM:
            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenBlocks_currentSelectedLine)){
                FAT_data_note_pasteEffect (FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            } else {
                FAT_data_note_cutEffect (FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            }
            FAT_screenNotes_printEffect(FAT_screenNotes_currentSelectedLine);
            break;
    }
}

void FAT_screenNotes_pressA() {
    switch (FAT_screenNotes_currentSelectedColumn) {
        case SCREENNOTES_COLUMN_ID_NOTES:
            if (FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_addDefaultNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, FAT_screenSong_currentSelectedColumn);

            }

            if (F_CTRLINPUT_RIGHT_PRESSED) {
                FAT_data_note_changeValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1); // ajout de 1
            }

            if (F_CTRLINPUT_LEFT_PRESSED) {
                FAT_data_note_changeValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1); // retrait de 1
            }

            if (F_CTRLINPUT_UP_PRESSED) {
                FAT_data_note_changeOctave(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);
            }

            if (F_CTRLINPUT_DOWN_PRESSED) {
                FAT_data_note_changeOctave(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);
            }

            break;

        case SCREENNOTES_COLUMN_ID_INST:

            if (F_CTRLINPUT_L_PRESSED) {
                FAT_data_note_smartChangeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
            } else {

                if (F_CTRLINPUT_RIGHT_PRESSED) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, 1);
                }

                if (F_CTRLINPUT_LEFT_PRESSED) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, -1);
                }

                if (F_CTRLINPUT_UP_PRESSED) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, 16);
                }

                if (F_CTRLINPUT_DOWN_PRESSED) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, -16);
                }
            }
            break;

        case SCREENNOTES_COLUMN_ID_CMD_NAME:

            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_note_addDefaultEffect(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);

            }

            if (F_CTRLINPUT_RIGHT_PRESSED) {
                FAT_data_note_changeEffectName(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);
            }

            if (F_CTRLINPUT_LEFT_PRESSED) {
                FAT_data_note_changeEffectName(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);
            }

            break;

        case SCREENNOTES_COLUMN_ID_CMD_PARAM:

            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_note_addDefaultEffect(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);

            }

            if (F_CTRLINPUT_RIGHT_PRESSED) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);
            }

            if (F_CTRLINPUT_LEFT_PRESSED) {
                 FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);
            }

            if (F_CTRLINPUT_UP_PRESSED) {
                 FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 16);
            }

            if (F_CTRLINPUT_DOWN_PRESSED) {
                 FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -16);
            }

            break;
    }

    FAT_screenNotes_printNote(FAT_screenNotes_currentSelectedLine);
    FAT_screenNotes_printEffect(FAT_screenNotes_currentSelectedLine);

}

#endif
