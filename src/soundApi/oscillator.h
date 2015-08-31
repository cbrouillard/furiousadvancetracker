#ifndef _SOUND_API_OSC_
#define _SOUND_API_OSC_

#include "luts/osc_sinluts.h"
#include "luts/osc_squareluts.h"

/**
    \brief Utilisé pour déterminer la forme d'oscillator à jouer.
*/
const u32** snd_oscShapes[4] = {
    snd_osc_sine, snd_osc_square,
    snd_osc_sine, snd_osc_square
};

vu32 oscCounterA = 0;
vu32 oscCounterB = 0;

u32* snd_oscA;

volatile bool playSnAOsc = 0;
volatile bool playSnBOsc = 0;

/**
 * Avance a travers la LUT d'un oscillator. 
*/
void snd_processOscillatorA();

void snd_processOscillatorA() {
    if (playSnAOsc) {
        REG_SOUNDCNT_H &= ~(1 << 0xB);
        if (!(oscCounterA & 3)){
            SND_REG_SGFIFOA = snd_oscA[oscCounterA >> 2];
        }

        oscCounterA += 1;
        if (oscCounterA > (LUT_PRECISION-1)){
            oscCounterA = 0;
        }
    }

}

#endif
