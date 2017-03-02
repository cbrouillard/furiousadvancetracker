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
 * \file screen_instrument_cursor.h
 * \brief Fichier dédié à la gestion du curseur pour l'écran INSTRUMENT.
 */

#ifndef _SCREEN_INSTRUMENT_CURSOR_H_
#define	_SCREEN_INSTRUMENT_CURSOR_H_

// Définit ou le curseur de tabluation se situe par défaut
/** \brief Position par défaut du curseur de tabulation. */
#define SCREENINSTRUMENT_TABULATION_CURSOR_DEFAULT_X 5
/** \brief Position par défaut du curseur de tabulation. */
#define SCREENINSTRUMENT_TABULATION_CURSOR_DEFAULT_Y 5
/** \brief Position du curseur de tabulation pour le type d'instrument PULSE. */
#define SCREENINSTRUMENT_TABULATION_CURSOR_PULSE_X 3
/** \brief Position du curseur de tabulation pour le type d'instrument WAVE. */
#define SCREENINSTRUMENT_TABULATION_CURSOR_WAVE_X 47
/** \brief Position du curseur de tabulation pour le type d'instrument NOISE. */
#define SCREENINSTRUMENT_TABULATION_CURSOR_NOISE_X 91
/** \brief Position du curseur de tabulation pour le type d'instrument SAMPLE. */
#define SCREENINSTRUMENT_TABULATION_CURSOR_SAMPLE_X 135
/** \brief Position du curseur de tabulation pour le type d'instrument OSC. */
#define SCREENINSTRUMENT_TABULATION_CURSOR_OSCILLATOR_X 179
/** \brief Position du premier emplacement dans l'écran instrument (ne tient pas compte du type). */
#define SCREENINSTRUMENTS_FIRST_BLOCK_X 88
/** \brief Position du premier emplacement dans l'écran instrument (ne tient pas compte du type). */
#define SCREENINSTRUMENTS_FIRST_BLOCK_Y 32
/** \brief Position du dernier emplacement dans l'écran instrument (ne tient pas compte du type). */
#define SCREENINSTRUMENTS_LAST_BLOCK_Y 120
/** \brief Nombre de lignes sur l'écran PULSE. */
#define SCREENINSTRUMENT_PULSE_NB_LINES_ON_SCREEN 9
/** \brief Nombre de lignes sur l'écran NOISE. */
#define SCREENINSTRUMENT_NOISE_NB_LINES_ON_SCREEN 8
/** \brief Nombre de lignes sur l'écran WAVE. */
#define SCREENINSTRUMENT_WAVE_NB_LINES_ON_SCREEN 9
/** \brief Nombre de lignes sur l'écran SAMPLE. */
#define SCREENINSTRUMENT_SAMPLE_NB_LINES_ON_SCREEN 8
/** \brief Nombre de lignes sur l'écran OSC. */
#define SCREENINSTRUMENT_OSC_NB_LINES_ON_SCREEN 7

void FAT_screenInstrument_hideTabulationCursor();
void FAT_screenInstrument_showTabulationCursor();
void FAT_screenInstrument_moveTabulationCursor(u8 instrumentType);
void FAT_screenInstrument_tabCursorInit();

void FAT_screenInstrument_pulse_commitCursorMove();
void FAT_screenInstrument_wave_commitCursorMove();
void FAT_screenInstrument_noise_commitCursorMove();
void FAT_screenInstrument_sample_commitCursorMove();
void FAT_screenInstrument_osc_commitCursorMove ();
void FAT_screenInstrument_commitCursorMove(u8 type);

void FAT_screenInstrument_pulse_displayGoodCursor();
void FAT_screenInstrument_noise_displayGoodCursor();
void FAT_screenInstrument_wave_displayGoodCursor();
void FAT_screenInstrument_sample_displayGoodCursor();
void FAT_screenInstrument_osc_displayGoodCursor();
void FAT_screenInstrument_displayGoodCursor(u8 type);

void FAT_screenInstrument_initCursor(u8 instrumentType);
void FAT_screenInstrument_moveCursorDown(u8 type);
void FAT_screenInstrument_moveCursorUp(u8 type);
void FAT_screenInstrument_moveCursorRight(u8 type);
void FAT_screenInstrument_moveCursorLeft(u8 type);

void FAT_screenInstrument_showSimulatorCursor (u8 type);
void FAT_screenInstrument_hideSimulatorCursor ();

s8 FAT_screenInstruments_getCurrentSelectedLine();
u8 FAT_screenInstruments_getCurrentSelectedColumn();

#endif	/* SCREEN_INSTRUMENT_CURSOR_H */
