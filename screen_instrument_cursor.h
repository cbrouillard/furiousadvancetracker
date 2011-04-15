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
#ifndef _SCREEN_INSTRUMENT_CURSOR_H_
#define	_SCREEN_INSTRUMENT_CURSOR_H_

// Définit ou le curseur de tabluation se situe par défaut
#define SCREENINSTRUMENT_TABULATION_CURSOR_DEFAULT_X 5 
#define SCREENINSTRUMENT_TABULATION_CURSOR_DEFAULT_Y 5

#define SCREENINSTRUMENT_TABULATION_CURSOR_PULSE_X 5
#define SCREENINSTRUMENT_TABULATION_CURSOR_WAVE_X 53
#define SCREENINSTRUMENT_TABULATION_CURSOR_NOISE_X 101
#define SCREENINSTRUMENT_TABULATION_CURSOR_SAMPLE_X 149

#define SCREENINSTRUMENTS_FIRST_BLOCK_X 88
#define SCREENINSTRUMENTS_FIRST_BLOCK_Y 32
#define SCREENINSTRUMENTS_LAST_BLOCK_Y 120

#define SCREENINSTRUMENT_PULSE_NB_LINES_ON_SCREEN 9
#define SCREENINSTRUMENT_NOISE_NB_LINES_ON_SCREEN 8
#define SCREENINSTRUMENT_WAVE_NB_LINES_ON_SCREEN 7

u8 FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY;
u8 FAT_screenInstruments_currentSelectedLine, FAT_screenInstruments_currentSelectedColumn;

u8 FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY;
u8 FAT_screenInstrument_tabCursorObj;

const u8 INST_PULSE_BLOCK_Y[9] = {31, 39, 47, 55, 79, 87, 95, 103, 127};
const u8 INST_NOISE_BLOCK_Y[8] = {31, 39, 47, 55, 79, 87, 95, 127};
const u8 INST_WAVE_BLOCK_Y[7] = {31, 55, 63, 71, 79, 87, 111};

void FAT_screenInstrument_hideTabulationCursor() {
    ham_SetObjVisible(FAT_screenInstrument_tabCursorObj, 0);
}

void FAT_screenInstrument_showTabulationCursor() {
    ham_SetObjVisible(FAT_screenInstrument_tabCursorObj, 1);
}

void FAT_screenInstrument_moveTabulationCursor(u8 instrumentType) {
    switch (instrumentType) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_PULSE_X;
            ham_SetObjXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
        case INSTRUMENT_TYPE_WAVE:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_WAVE_X;
            ham_SetObjXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
        case INSTRUMENT_TYPE_NOISE:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_NOISE_X;
            ham_SetObjXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_SAMPLE_X;
            ham_SetObjXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
    }
}

void FAT_screenInstrument_tabCursorInit() {
    FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_DEFAULT_X;
    FAT_screenInstrument_tabCursorY = SCREENINSTRUMENT_TABULATION_CURSOR_DEFAULT_Y;

    FAT_screenInstrument_tabCursorObj = ham_CreateObj((void*) cursor_instrument_tabulation_Bitmap, OBJ_SIZE_64X32,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);

    ham_SetObjPrio(FAT_screenInstrument_tabCursorObj, 1);
    FAT_screenInstrument_hideTabulationCursor();
}

void FAT_screenInstrument_pulse_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 2:
        case 4:
            ham_SetObjXY(FAT_cursor1_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;

        case 3:
        case 5:
        case 6:
        case 7:
            ham_SetObjXY(FAT_cursor2_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
        case 8:
            ham_SetObjXY(FAT_cursor3_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
    }
}

void FAT_screenInstrument_wave_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 4:
            ham_SetObjXY(FAT_cursor1_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;

        case 2:
        case 3:
            ham_SetObjXY(FAT_cursor2_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
        case 5:
        case 6:
            ham_SetObjXY(FAT_cursor3_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
    }
}

void FAT_screenInstrument_noise_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            ham_SetObjXY(FAT_cursor1_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;

        case 5:
        case 6:
            ham_SetObjXY(FAT_cursor2_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
        case 7:
            ham_SetObjXY(FAT_cursor3_obj, FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
    }
}

void FAT_screenInstrument_sample_commitCursorMove() {

}

void FAT_screenInstrument_commitCursorMove(u8 type) {
    switch (type) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:

            FAT_screenInstrument_pulse_commitCursorMove();

            break;
        case INSTRUMENT_TYPE_WAVE:

            FAT_screenInstrument_wave_commitCursorMove();

            break;
        case INSTRUMENT_TYPE_NOISE:

            FAT_screenInstrument_noise_commitCursorMove();

            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:

            FAT_screenInstrument_sample_commitCursorMove();

            break;
    }
}

void FAT_screenInstrument_pulse_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 2:
        case 4:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 3:
        case 5:
        case 6:
        case 7:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 8:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;
    }
}

void FAT_screenInstrument_noise_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 5:
        case 6:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 7:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;
    }
}

void FAT_screenInstrument_wave_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 4:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;

        case 2:
        case 3:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 5:
        case 6:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;
    }
}

void FAT_screenInstrument_sample_displayGoodCursor() {

}

void FAT_screenInstrument_displayGoodCursor(u8 type) {
    switch (type) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            FAT_screenInstrument_pulse_displayGoodCursor();
            break;
        case INSTRUMENT_TYPE_WAVE:
            FAT_screenInstrument_wave_displayGoodCursor();
            break;
        case INSTRUMENT_TYPE_NOISE:
            FAT_screenInstrument_noise_displayGoodCursor();
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            FAT_screenInstrument_sample_displayGoodCursor();
            break;
    }
}

void FAT_screenInstrument_initCursor(u8 instrumentType) {

    FAT_screenInstrument_moveTabulationCursor(instrumentType);
    FAT_screenInstrument_hideTabulationCursor();

    FAT_screenInstrument_cursorX = SCREENINSTRUMENTS_FIRST_BLOCK_X - 1;
    FAT_screenInstrument_cursorY = SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1;

    FAT_screenInstruments_currentSelectedLine = 0;
    FAT_screenInstruments_currentSelectedColumn = 0;

    FAT_screenInstrument_commitCursorMove(instrumentType);
}

void FAT_screenInstrument_moveCursorDown(u8 type) {
    switch (type) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:

            if (FAT_screenInstruments_currentSelectedLine < SCREENINSTRUMENT_PULSE_NB_LINES_ON_SCREEN - 1) {
                if (!(FAT_screenInstrument_cursorY >= SCREENINSTRUMENTS_LAST_BLOCK_Y - 1)) {
                    FAT_screenInstruments_currentSelectedLine++;
                    FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }
            }

            FAT_screenInstrument_displayGoodCursor(type);

            break;
        case INSTRUMENT_TYPE_WAVE:
            
            if (FAT_screenInstruments_currentSelectedLine < SCREENINSTRUMENT_WAVE_NB_LINES_ON_SCREEN - 1) {
                if (!(FAT_screenInstrument_cursorY >= SCREENINSTRUMENTS_LAST_BLOCK_Y - 1)) {
                    FAT_screenInstruments_currentSelectedLine++;
                    FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }
            }

            FAT_screenInstrument_displayGoodCursor(type);
            
            break;
        case INSTRUMENT_TYPE_NOISE:

            if (FAT_screenInstruments_currentSelectedLine < SCREENINSTRUMENT_NOISE_NB_LINES_ON_SCREEN - 1) {
                if (!(FAT_screenInstrument_cursorY >= SCREENINSTRUMENTS_LAST_BLOCK_Y - 1)) {
                    FAT_screenInstruments_currentSelectedLine++;
                    FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }
            }

            FAT_screenInstrument_displayGoodCursor(type);

            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            break;
    }
}

void FAT_screenInstrument_moveCursorUp(u8 type) {
    switch (type) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:

            if (FAT_screenInstruments_currentSelectedLine > 0) {
                if (!(FAT_screenInstrument_cursorY <= SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1)) {
                    FAT_screenInstruments_currentSelectedLine--;
                    FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }
            }

            FAT_screenInstrument_displayGoodCursor(type);

            break;
        case INSTRUMENT_TYPE_WAVE:
            
            if (FAT_screenInstruments_currentSelectedLine > 0) {
                if (!(FAT_screenInstrument_cursorY <= SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1)) {
                    FAT_screenInstruments_currentSelectedLine--;
                    FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }
            }

            FAT_screenInstrument_displayGoodCursor(type);
            
            break;
        case INSTRUMENT_TYPE_NOISE:

            if (FAT_screenInstruments_currentSelectedLine > 0) {
                if (!(FAT_screenInstrument_cursorY <= SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1)) {
                    FAT_screenInstruments_currentSelectedLine--;
                    FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }
            }

            FAT_screenInstrument_displayGoodCursor(type);

            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            break;
    }
}

void FAT_screenInstrument_moveCursorRight(u8 type) {
    switch (type) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            break;
        case INSTRUMENT_TYPE_WAVE:
            break;
        case INSTRUMENT_TYPE_NOISE:
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            break;
    }
}

void FAT_screenInstrument_moveCursorLeft(u8 type) {
    switch (type) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            break;
        case INSTRUMENT_TYPE_WAVE:
            break;
        case INSTRUMENT_TYPE_NOISE:
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            break;
    }
}

#endif	/* SCREEN_INSTRUMENT_CURSOR_H */

