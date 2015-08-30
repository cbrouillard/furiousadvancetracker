#ifndef _SOUND_API_OSC_
#define _SOUND_API_OSC_

#define SAMPLERATE 16000

#include "oscillator/osc_sinluts.h"
#include "oscillator/osc_squareluts.h"

vu32 sampleCounter = 0;


vu32 oscillatorCounter = 0;
vu32 bufferOsc = 0;
vu32 phase = 0;
volatile int bufferFreq = 0;
vu32 val = 0;

void snd_processOscillatorA();
void snd_processOscillator_sine ();

void snd_initOscillator (){
    sampleCounter = 0;
    bufferOsc = 0;
    phase = 0;
    val = 0;
    bufferFreq = 0;
    oscillatorCounter = 0;
}

void snd_processOscillator_square () {
    phase = phase + bufferFreq;
    if (phase > SIN_PHASE_MAX){
        phase = phase - SIN_PHASE_MAX;
    }
    if (phase < 128){
        val = 0;
    } else {
        val = 64;
    }
    bufferOsc = val;

    phase = phase + bufferFreq;
    if (phase > SIN_PHASE_MAX){
        phase = phase - SIN_PHASE_MAX;
    }
    if (phase < 128){
        val = 0;
    } else {
        val = 64;
    }
    bufferOsc |= (val << 8);

    phase = phase + bufferFreq;
    if (phase > SIN_PHASE_MAX){
        phase = phase - SIN_PHASE_MAX;
    }
    if (phase < 128){
        val = 0;
    } else {
        val = 64;
    }
    bufferOsc |= (val << 16);

    phase = phase + bufferFreq;
    if (phase > SIN_PHASE_MAX){
        phase = phase - SIN_PHASE_MAX;
    }
    if (phase < 128){
        val = 0;
    } else {
        val = 64;
    }
    bufferOsc |= (val << 24);
}

void snd_processOscillatorA() {
    if (playSnASample) {
        REG_SOUNDCNT_H &= ~(1 << 0xB);
        if (!(sampleCounter & 3)){
            SND_REG_SGFIFOA = snd_osc_square_A0[sampleCounter >> 2];
        }

        sampleCounter += 1;
        if (sampleCounter > (LUT_PRECISION-1)){
            sampleCounter = 0;
        }
    }

}

#endif
