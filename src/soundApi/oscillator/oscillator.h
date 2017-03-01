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
 * \file oscillator.c
 * \brief Définition des fonctions pour la gestion des oscillateur.
 */

#ifndef _SOUND_API_OSC_
#define _SOUND_API_OSC_

#include "../soundApi.h"

extern const u32** snd_oscShapes[4];

extern u8 shapeA;
extern u8 shapeB;
extern u8 freqNA;
extern u8 freqNB;

extern u8 oscLengthA;
extern u8 loopmodeA;
extern u8 oscLengthB;
extern u8 loopmodeB;

extern volatile bool playSnAOsc;
extern volatile bool playSnBOsc;

void snd_playOscillatorA (u8 shape, u8 freqN, u8 loopmode, u8 soundlength, u8 volume, u8 output);
void snd_playOscillatorB (u8 shape, u8 freqN, u8 loopmode, u8 soundlength, u8 volume, u8 output);

#endif
