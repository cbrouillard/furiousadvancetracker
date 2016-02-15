#ifndef _SOUND_API_OSC_
#define _SOUND_API_OSC_

#include "luts/osc_sinluts.h"
#include "luts/osc_squareluts.h"
#include "luts/osc_triangleluts.h"
#include "luts/osc_sawluts.h"

#include "signalModulation.h"

/**
    \brief Utilisé pour déterminer la forme d'oscillator à jouer.
*/
const u32** snd_oscShapes[4] = {
    snd_osc_sine, snd_osc_square,
    snd_osc_triangle, snd_osc_saw
};

vu32 oscSamplerCounterA = 0;
vu32 oscSamplerCounterB = 0;
vu32 oscTimeCounterA = 0;
vu32 oscTimeCounterB = 0;

u32* snd_oscA;
u32* snd_oscB;

volatile bool playSnAOsc = 0;
volatile bool playSnBOsc = 0;

volatile u32 snd_oscA_length;
volatile u32 snd_oscB_length;

/**
 * Avance a travers la LUT d'un oscillator. 
*/
void snd_processOscillatorA();
void snd_processOscillatorB();

void snd_processOscillatorA() {
    if (playSnAOsc) {
        REG_SOUNDCNT_H &= ~(1 << 0xB);
        if (!(oscSamplerCounterA & 3)){
            SND_REG_SGFIFOA = (*snd_modulation_applyModulation[0]) (snd_oscA[oscSamplerCounterA >> 2], 1, 130, oscSamplerCounterA >> 2, 5, 0);
            oscTimeCounterA ++;
        }

        oscSamplerCounterA ++;
        if (oscSamplerCounterA > (LUT_PRECISION-1)){
            oscSamplerCounterA = 0;
        }

        if (snd_oscA_length != NULL_VALUE){
            if (oscTimeCounterA > snd_oscA_length){
                playSnAOsc = 0;
            }
        }
    }
}

void snd_processOscillatorB() {
    if (playSnBOsc) {
        REG_SOUNDCNT_H &= ~(1 << 0xF);
        if (!(oscSamplerCounterB & 3)){
            SND_REG_SGFIFOB = (*snd_modulation_applyModulation[0]) (snd_oscB[oscSamplerCounterB >> 2], 1, 130, oscTimeCounterB, 500, 0);;
            oscTimeCounterB ++;
        }

        oscSamplerCounterB ++;
        if (oscSamplerCounterB > (LUT_PRECISION-1)){
            oscSamplerCounterB = 0;
        }

        if (snd_oscB_length != NULL_VALUE){
            if (oscTimeCounterB > snd_oscB_length){
                playSnBOsc = 0;
            }
        }
    }

}

#endif
