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
 * \file screen_instrument.h
 * \brief Ce fichier contient toutes les fonctions relatives à la gestion des instruments.
 */

#ifndef _SCREEN_INSTRUMENT_H_
#define	_SCREEN_INSTRUMENT_H_

void FAT_screenInstrument_printInstrumentNumber();
void FAT_screenInstrument_printAllText(u8 type);
void FAT_screenInstrument_init();
void FAT_screenInstrument_switchScreen(u8 type);
void FAT_screenInstrument_changeInstrumentType(s8 move);
void FAT_screenInstrument_checkButtons();
void FAT_screenInstrument_initSpritesForInstrument();
void FAT_screenInstrument_hideAllEnvdirSprites();
void FAT_screenInstrument_hideAllWavedutySprite();
void FAT_screenInstrument_hideAllOscSprite();
void FAT_screenInstrument_showEnvdir(u8 envdirValue, u8 spriteX, u8 spriteY);
void FAT_screenInstrument_showOutput(u8 x, u8 y, u8 output);
void FAT_screenInstrument_showWaveduty(u8 wavedutyValue, u8 spriteX, u8 spriteY);
void FAT_screenInstrument_showOscForm(u8 oscFormValue, u8 spriteX, u8 spriteY);
s8 FAT_screenInstrument_giveMeAddedValue();
void FAT_screenInstrument_pulse_pressA();
void FAT_screenInstrument_wave_pressA();
void FAT_screenInstrument_noise_pressA();
void FAT_screenInstrument_sample_pressA();
void FAT_screenInstrument_osc_pressA();
void FAT_screenInstrument_pressOrHeldA();

#include "cursors.h"
#include "data.h"
#include "fat.h"
#include "screen_instrument_cursor.h"

#endif	/* SCREEN_INSTRUMENT_H */
