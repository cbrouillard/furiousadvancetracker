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
* \file instrument_cursor.c
* \brief Gestion du curseur sur l'écran des instruments.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../../headers/screen_instrument_cursor.h"

/** \brief Positions des emplacements de paramètre dans l'écran PULSE. */
const u8 INST_PULSE_BLOCK_Y[SCREENINSTRUMENT_PULSE_NB_LINES_ON_SCREEN] = {31, 39, 47, 55, 79, 87, 95, 103, 127};
/** \brief Positions des emplacements de paramètre dans l'écran NOISE. */
const u8 INST_NOISE_BLOCK_Y[SCREENINSTRUMENT_NOISE_NB_LINES_ON_SCREEN] = {31, 39, 47, 55, 79, 87, 95, 127};
/** \brief Positions des emplacements de paramètre dans l'écran WAVE. */
const u8 INST_WAVE_BLOCK_Y[SCREENINSTRUMENT_WAVE_NB_LINES_ON_SCREEN] = {31, 55, 63, 71, 79, 87, 95, 119};
/** \brief Positions des emplacements de paramètre dans l'écran SAMPLE. */
const u8 INST_SAMPLE_BLOCK_Y[SCREENINSTRUMENT_SAMPLE_NB_LINES_ON_SCREEN] = {31, 55, 79, 87, 95, 103, 111, 119, 95};
/** \brief Positions des emplacements de paramètre dans l'écran OSC. */
const u8 INST_OSC_BLOCK_Y[SCREENINSTRUMENT_OSC_NB_LINES_ON_SCREEN] = {31, 39, 63, 71, 95};

/** \brief Position actuelle du cursor. */
u8 FAT_screenInstrument_cursorX;
/** \brief Position actuelle du cursor. */
u8 FAT_screenInstrument_cursorY;
/** \brief Ligne actuellement sélectionnée. s8 normal. Pas touche :D. */
s8 FAT_screenInstruments_currentSelectedLine;
s8 FAT_screenInstruments_getCurrentSelectedLine(){
  return FAT_screenInstruments_currentSelectedLine;
}
/** \brief Numéro de colonne actuellement sélectionné. */
u8 FAT_screenInstruments_currentSelectedColumn;
u8 FAT_screenInstruments_getCurrentSelectedColumn(){
  return FAT_screenInstruments_currentSelectedColumn;
}

/** \brief Position actuelle du curseur de tabulation. */
u8 FAT_screenInstrument_tabCursorX;
/** \brief Position actuelle du curseur de tabulation. */
u8 FAT_screenInstrument_tabCursorY;
/** \brief Objet sprite pour le curseur de tabulation. */
THandle FAT_screenInstrument_tabCursorObj;

/**
 * \brief Cache le curseur de tabulation.
 */
void FAT_screenInstrument_hideTabulationCursor() {
    hel_ObjSetVisible(FAT_screenInstrument_tabCursorObj, 0);
}

/**
 * \brief Affiche le curseur de tabulation.
 */
void FAT_screenInstrument_showTabulationCursor() {
    hel_ObjSetVisible(FAT_screenInstrument_tabCursorObj, 1);
}

/**
 * \brief Déplace le curseur de tabulation.
 *
 * Le type d'instrument détermine les possibilités de mouvements. *
 * @param instrumentType type de l'instrument actuellement en cours d'édition
 */
void FAT_screenInstrument_moveTabulationCursor(u8 instrumentType) {
    switch (instrumentType) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_PULSE_X;
            hel_ObjSetXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
        case INSTRUMENT_TYPE_WAVE:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_WAVE_X;
            hel_ObjSetXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
        case INSTRUMENT_TYPE_NOISE:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_NOISE_X;
            hel_ObjSetXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_SAMPLE_X;
            hel_ObjSetXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_OSCILLATOR_X;
            hel_ObjSetXY(FAT_screenInstrument_tabCursorObj, FAT_screenInstrument_tabCursorX, FAT_screenInstrument_tabCursorY);
            break;
    }
}

/**
 * \brief Initialisation du curseur de tabulation.
 *
 * Charge le sprite et le cache.
 */
void FAT_screenInstrument_tabCursorInit() {
    FAT_screenInstrument_tabCursorX = SCREENINSTRUMENT_TABULATION_CURSOR_DEFAULT_X;
    FAT_screenInstrument_tabCursorY = SCREENINSTRUMENT_TABULATION_CURSOR_DEFAULT_Y;

    FAT_screenInstrument_tabCursorObj = hel_ObjCreate(        ResData(RES_CURSOR_INSTRUMENT_TABULATION_RAW), // Pointer to source graphic
                                                              OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                              3,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                              OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                                              COLORS_16,              // Use 16 color mode
                                                              0,                      // Palette number. Only neccessary in 16 color mode
                                                              FALSE,                  // Don't use mosaic
                                                              FALSE,                  // Don't flip the sprite horizontally
                                                              FALSE,                  // Don't flip the object vertically
                                                              1,                      // Priority against background. 0=higest
                                                              FALSE,                  // Don't make the object double-sized
                                                              FAT_screenInstrument_tabCursorX,                    // Destination horzintal screen coordinate in pixels
                                                              FAT_screenInstrument_tabCursorY                      // Destination vertical screen coordinate in pixels
                                                              );
    FAT_screenInstrument_hideTabulationCursor();
}

/**
 * \brief Validation du déplacement du curseur d'édition sur l'écran PULSE.
 */
void FAT_screenInstrument_pulse_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 2:
        case 4:
            FAT_cursors_moveCursor1 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;

        case 3:
        case 5:
        case 6:
        case 7:
            FAT_cursors_moveCursor2 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
        case 8:
            FAT_cursors_moveCursor3 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
    }
}

/**
 * \brief Validation du déplacement du curseur d'édition sur l'écran WAVE.
 */
void FAT_screenInstrument_wave_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 4:
            FAT_cursors_moveCursor1 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;

        case 2:
        case 3:
        case 6:
            FAT_cursors_moveCursor2 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
        case 5:
        case 7:
            FAT_cursors_moveCursor3 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
    }
}

/**
 * \brief Validation du déplacement du curseur d'édition sur l'écran NOISE.
 */
void FAT_screenInstrument_noise_commitCursorMove() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            FAT_cursors_moveCursor1 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;

        case 5:
        case 6:
            FAT_cursors_moveCursor2 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
        case 7:
            FAT_cursors_moveCursor3 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
    }
}

/**
 * \brief Validation du déplacement du curseur d'édition sur l'écran SAMPLEs.
 * \todo Position en dur pour la ligne 1
 */
void FAT_screenInstrument_sample_commitCursorMove() {
    if (FAT_screenInstruments_currentSelectedColumn == 0){
        switch (FAT_screenInstruments_currentSelectedLine) {
            case 0:
                FAT_cursors_moveCursor8 (48, FAT_screenInstrument_cursorY + 1);
                break;
            case 1:
            case 4:
                FAT_cursors_moveCursor1 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
                break;

            case 2:
            case 6:
            case 7:
                FAT_cursors_moveCursor2 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
                break;

            case 3:
            case 5:
                FAT_cursors_moveCursor3 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
                break;
        }
    } else {
        FAT_cursors_moveCursor3 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
    }
}

void FAT_screenInstrument_osc_commitCursorMove () {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0:
        case 1:
        case 3:
            FAT_cursors_moveCursor2 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
        case 2:
            FAT_cursors_moveCursor1 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
        case 4:
            FAT_cursors_moveCursor3 (FAT_screenInstrument_cursorX, FAT_screenInstrument_cursorY);
            break;
    }
}

/**
 * \brief Validation du déplacement du curseur d'édition (fonction wrapper).
 *
 * @param type type de l'instrument sur lequel on veut déplacer le curseur
 */
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
        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            FAT_screenInstrument_osc_commitCursorMove();

            break;
    }
}

/**
 * \brief Affiche le bon curseur (taille) selon sa position sur l'écran PULSE.
 */
void FAT_screenInstrument_pulse_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case -1:
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
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

/**
 * \brief Affiche le bon curseur (taille) selon sa position sur l'écran NOISE.
 */
void FAT_screenInstrument_noise_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case -1:
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
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

/**
 * \brief Affiche le bon curseur (taille) selon sa position sur l'écran WAVE.
 */
void FAT_screenInstrument_wave_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case -1:
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 0:
        case 1:
        case 4:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;

        case 2:
        case 3:
        case 6:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 5:
        case 7:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;
    }
}

/**
 * \brief Affiche le bon curseur (taille) selon sa position sur l'écran SAMPLE.
 */
void FAT_screenInstrument_sample_displayGoodCursor() {

    if (FAT_screenInstruments_currentSelectedColumn == 0){
        switch (FAT_screenInstruments_currentSelectedLine) {
            case -1:
                FAT_cursors_hideCursor1();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor3();
                FAT_cursors_hideCursor8();
                break;
            case 0:
                FAT_cursors_showCursor8();
                FAT_cursors_hideCursor1();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor3();
                break;
            case 1:
            case 4:
                FAT_cursors_showCursor1();
                FAT_cursors_hideCursor8();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor3();
                break;
            case 2:
            case 6:
            case 7:
                FAT_cursors_showCursor2();
                FAT_cursors_hideCursor8();
                FAT_cursors_hideCursor1();
                FAT_cursors_hideCursor3();
                break;
            case 3:
            case 5:
                FAT_cursors_showCursor3();
                FAT_cursors_hideCursor1();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor8();
                break;
        }
    } else {
        FAT_cursors_showCursor3();
        FAT_cursors_hideCursor8();
        FAT_cursors_hideCursor1();
        FAT_cursors_hideCursor2();
    }
}

void FAT_screenInstrument_osc_displayGoodCursor() {
    switch (FAT_screenInstruments_currentSelectedLine) {
        case -1:
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 0:
        case 1:
        case 3:
            FAT_cursors_showCursor2();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor3();
            break;
        case 2:
            FAT_cursors_showCursor1();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor3();
            break;
        case 4:
            FAT_cursors_showCursor3();
            FAT_cursors_hideCursor1();
            FAT_cursors_hideCursor2();
            break;

    }
}

/**
 * \brief Affiche le bon curseur (taille) selon sa position (fonction wrapper).
 * @param type le type d'instrument en cours d'édition
 */
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
        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            FAT_screenInstrument_osc_displayGoodCursor();
            break;
    }
}

/**
 * \brief Initialisation du curseur d'édition.
 * @param instrumentType le type d'instrument à éditer
 */
void FAT_screenInstrument_initCursor(u8 instrumentType) {

    FAT_screenInstrument_moveTabulationCursor(instrumentType);
    FAT_screenInstrument_hideTabulationCursor();

    FAT_screenInstrument_cursorX = SCREENINSTRUMENTS_FIRST_BLOCK_X - 1;
    FAT_screenInstrument_cursorY = SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1;

    FAT_screenInstruments_currentSelectedLine = 0;
    FAT_screenInstruments_currentSelectedColumn = 0;

    FAT_screenInstrument_commitCursorMove(instrumentType);
}

/**
 * \brief Déplace le curseur vers le bas en fonction du type d'instrument édité.
 * @param type le type d'instrument
 */
void FAT_screenInstrument_moveCursorDown(u8 type) {
    if (FAT_screenInstruments_currentSelectedLine == -1){
            // retour dans les options
            FAT_screenInstruments_currentSelectedLine = 0;
    } else {

        switch (type) {
            case INSTRUMENT_TYPE_PULSE:
            case INSTRUMENT_TYPE_PULSE2:

                if (FAT_screenInstruments_currentSelectedLine < SCREENINSTRUMENT_PULSE_NB_LINES_ON_SCREEN - 1) {
                    if (!(FAT_screenInstrument_cursorY >= SCREENINSTRUMENTS_LAST_BLOCK_Y - 1)) {
                        FAT_screenInstruments_currentSelectedLine++;
                        FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 0;
                    FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case INSTRUMENT_TYPE_WAVE:

                if (FAT_screenInstruments_currentSelectedLine < SCREENINSTRUMENT_WAVE_NB_LINES_ON_SCREEN - 1) {
                    if (!(FAT_screenInstrument_cursorY >= SCREENINSTRUMENTS_LAST_BLOCK_Y - 1)) {
                        FAT_screenInstruments_currentSelectedLine++;
                        FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 0;
                    FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case INSTRUMENT_TYPE_NOISE:

                if (FAT_screenInstruments_currentSelectedLine < SCREENINSTRUMENT_NOISE_NB_LINES_ON_SCREEN - 1) {
                    if (!(FAT_screenInstrument_cursorY >= SCREENINSTRUMENTS_LAST_BLOCK_Y - 1)) {
                        FAT_screenInstruments_currentSelectedLine++;
                        FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 0;
                    FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case INSTRUMENT_TYPE_SAMPLEA:
            case INSTRUMENT_TYPE_SAMPLEB:

                if (FAT_screenInstruments_currentSelectedColumn == 0){
                    if (FAT_screenInstruments_currentSelectedLine < SCREENINSTRUMENT_SAMPLE_NB_LINES_ON_SCREEN - 2) {
                        if (!(FAT_screenInstrument_cursorY >= SCREENINSTRUMENTS_LAST_BLOCK_Y - 1)) {
                            FAT_screenInstruments_currentSelectedLine++;
                            FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                        }
                    } else {
                        FAT_screenInstruments_currentSelectedLine = 0;
                        FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                }

                FAT_screenInstrument_displayGoodCursor(type);
                break;

            case INSTRUMENT_TYPE_OSCILLATORA:
            case INSTRUMENT_TYPE_OSCILLATORB:
                if (FAT_screenInstruments_currentSelectedLine < SCREENINSTRUMENT_OSC_NB_LINES_ON_SCREEN - 1) {
                    if (!(FAT_screenInstrument_cursorY >= SCREENINSTRUMENTS_LAST_BLOCK_Y - 1)) {
                        FAT_screenInstruments_currentSelectedLine++;
                        FAT_screenInstrument_cursorY = INST_OSC_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = 0;
                    FAT_screenInstrument_cursorY = INST_OSC_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
        }
    }
}

/**
 * \brief Déplace le curseur vers le haut en fonction du type d'instrument édité.
 * @param type le type d'instrument
 */
void FAT_screenInstrument_moveCursorUp(u8 type) {

    if (FAT_screenInstruments_currentSelectedLine == 0){
        // on va vers les onglets de type
        FAT_screenInstruments_currentSelectedLine = -1;
        FAT_screenInstrument_displayGoodCursor(type);
    } else {

        if (FAT_screenInstruments_currentSelectedLine == -1){
            FAT_screenInstruments_currentSelectedLine = 0;
        }

        switch (type) {
            case INSTRUMENT_TYPE_PULSE:
            case INSTRUMENT_TYPE_PULSE2:

                if (FAT_screenInstruments_currentSelectedLine > 0) {
                    if (!(FAT_screenInstrument_cursorY <= SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1)) {
                        FAT_screenInstruments_currentSelectedLine--;
                        FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = SCREENINSTRUMENT_PULSE_NB_LINES_ON_SCREEN -1;
                    FAT_screenInstrument_cursorY = INST_PULSE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case INSTRUMENT_TYPE_WAVE:

                if (FAT_screenInstruments_currentSelectedLine > 0) {
                    if (!(FAT_screenInstrument_cursorY <= SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1)) {
                        FAT_screenInstruments_currentSelectedLine--;
                        FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = SCREENINSTRUMENT_WAVE_NB_LINES_ON_SCREEN -1;
                    FAT_screenInstrument_cursorY = INST_WAVE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case INSTRUMENT_TYPE_NOISE:

                if (FAT_screenInstruments_currentSelectedLine > 0) {
                    if (!(FAT_screenInstrument_cursorY <= SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1)) {
                        FAT_screenInstruments_currentSelectedLine--;
                        FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = SCREENINSTRUMENT_NOISE_NB_LINES_ON_SCREEN -1;
                    FAT_screenInstrument_cursorY = INST_NOISE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
            case INSTRUMENT_TYPE_SAMPLEA:
            case INSTRUMENT_TYPE_SAMPLEB:

                if (FAT_screenInstruments_currentSelectedColumn == 0){
                    if (FAT_screenInstruments_currentSelectedLine > 0) {
                        if (!(FAT_screenInstrument_cursorY <= SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1)) {
                            FAT_screenInstruments_currentSelectedLine--;
                            FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                        }
                    } else {
                        FAT_screenInstruments_currentSelectedLine = SCREENINSTRUMENT_SAMPLE_NB_LINES_ON_SCREEN -2; // ignoring right col
                        FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;

            case INSTRUMENT_TYPE_OSCILLATORA:
            case INSTRUMENT_TYPE_OSCILLATORB:
                if (FAT_screenInstruments_currentSelectedLine > 0) {
                    if (!(FAT_screenInstrument_cursorY <= SCREENINSTRUMENTS_FIRST_BLOCK_Y - 1)) {
                        FAT_screenInstruments_currentSelectedLine--;
                        FAT_screenInstrument_cursorY = INST_OSC_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                    }
                } else {
                    FAT_screenInstruments_currentSelectedLine = SCREENINSTRUMENT_OSC_NB_LINES_ON_SCREEN -1;
                    FAT_screenInstrument_cursorY = INST_OSC_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
                }

                FAT_screenInstrument_displayGoodCursor(type);

                break;
        }
    }
}

/**
 * \brief Déplace le curseur vers la droite en fonction du type d'instrument édité.
 * @param type le type d'instrument
 */
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
            FAT_screenInstruments_currentSelectedColumn = 1;
            FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[8];
            FAT_screenInstrument_cursorX = 207;

            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            break;
    }
}

/**
 * \brief Déplace le curseur vers la gauche en fonction du type d'instrument édité.
 * @param type le type d'instrument
 */
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
            FAT_screenInstruments_currentSelectedColumn = 0;
            FAT_screenInstrument_cursorY = INST_SAMPLE_BLOCK_Y[FAT_screenInstruments_currentSelectedLine];
            FAT_screenInstrument_cursorX = SCREENINSTRUMENTS_FIRST_BLOCK_X - 1;

            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            break;
    }
}

void FAT_screenInstrument_showSimulatorCursor (u8 type){
    switch (type) {
       case INSTRUMENT_TYPE_PULSE:
       case INSTRUMENT_TYPE_PULSE2:
            FAT_cursors_moveCursor3  (SCREENINSTRUMENTS_FIRST_BLOCK_X - 1,INST_PULSE_BLOCK_Y[SCREENINSTRUMENT_PULSE_NB_LINES_ON_SCREEN - 1]);
            break;
       case INSTRUMENT_TYPE_WAVE:
            FAT_cursors_moveCursor3  (SCREENINSTRUMENTS_FIRST_BLOCK_X - 1,INST_WAVE_BLOCK_Y[SCREENINSTRUMENT_WAVE_NB_LINES_ON_SCREEN - 1]);
            break;
       case INSTRUMENT_TYPE_NOISE:
            FAT_cursors_moveCursor3  (SCREENINSTRUMENTS_FIRST_BLOCK_X - 1,INST_NOISE_BLOCK_Y[SCREENINSTRUMENT_NOISE_NB_LINES_ON_SCREEN - 1]);
            break;
       case INSTRUMENT_TYPE_SAMPLEA:
       case INSTRUMENT_TYPE_SAMPLEB:
            FAT_cursors_moveCursor3  (207,INST_SAMPLE_BLOCK_Y[SCREENINSTRUMENT_SAMPLE_NB_LINES_ON_SCREEN - 1]);
            break;
       case INSTRUMENT_TYPE_OSCILLATORA:
       case INSTRUMENT_TYPE_OSCILLATORB:
            FAT_cursors_moveCursor3 (SCREENINSTRUMENTS_FIRST_BLOCK_X - 1,INST_OSC_BLOCK_Y[SCREENINSTRUMENT_OSC_NB_LINES_ON_SCREEN - 1]);
           break;
    }

    FAT_cursors_showCursor3();
}

void FAT_screenInstrument_hideSimulatorCursor (){
    FAT_cursors_hideCursor3();
}
