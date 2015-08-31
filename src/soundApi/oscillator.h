#ifndef _SOUND_API_OSC_
#define _SOUND_API_OSC_

#define SAMPLERATE 16000

#include "luts/osc_sinluts.h"
#include "luts/osc_squareluts.h"

vu32 oscCounterA = 0;
vu32 oscCounterB = 0;

/**
 * Avance a travers la LUT d'un oscillator. 
*/
void snd_processOscillatorA();

void snd_initOscillator (){
    oscCounterA = 0;
}

void snd_processOscillatorA() {
    if (playSnASample) {
        REG_SOUNDCNT_H &= ~(1 << 0xB);
        if (!(oscCounterA & 3)){
            SND_REG_SGFIFOA = snd_osc_sine_C0[oscCounterA >> 2];
        }

        oscCounterA += 1;
        if (oscCounterA > (LUT_PRECISION-1)){
            oscCounterA = 0;
        }
    }

}

#endif
