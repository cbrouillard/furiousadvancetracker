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

#include <hel2.h>

#include "../soundApi.h"

#include "../luts/osc_sinluts.h"
#include "../luts/osc_squareluts.h"
#include "../luts/osc_triangleluts.h"
#include "../luts/osc_sawluts.h"

/**
   \brief Utilisé pour déterminer la forme d'oscillator à jouer.
*/
const u32** snd_oscShapes[4] = {
   snd_osc_sine, snd_osc_square,
   snd_osc_triangle, snd_osc_saw
};

/**
vu32 oscSamplerCounterA = 0;
vu32 oscSamplerCounterB = 0;
vu32 oscTimeCounterA = 0;
vu32 oscTimeCounterB = 0;
volatile u32 snd_oscA_length;
volatile u32 snd_oscB_length;
u32* snd_oscA;
u32* snd_oscB;
**/

u8 shapeA, shapeB;
u8 freqNA, freqNB;

u8 oscLengthA, oscLengthB;
u8 loopmodeA, loopmodeB;

volatile bool playSnAOsc = 0;
volatile bool playSnBOsc = 0;

void snd_playOscillatorA (u8 shape, u8 freqN, u8 loopmode, u8 soundlength){
  // stop
  R_DMA1CNT = 0;
  R_DMA1SRC = 0;
  R_TIM1CNT=0;
  playSnASample = 0;
  playSnAOsc = 0;

  // Controls variables
  shapeA = shape;
  freqNA = freqN;
  loopmodeA = loopmode;
  oscLengthA = loopmode ? soundlength : 0xff;

  // WITH DMA !!
  R_DMA1SRC=(unsigned long) snd_oscShapes[shape][freqN]; //dma1 source
  R_DMA1DST=0x040000a0; //write to FIFO A address
  R_DMA1CNT=0xb600; //dma control: DMA enabled+ start on FIFO+32bit+repeat+increment source&dest

  R_TIM1COUNT=0xffff - LUT_PRECISION - 1; //0xffff-the number of samples to play
  R_TIM1CNT=0xC3; //enable timer1

  // Timer playback pour les samples
  R_TIM0CNT = 0;
  // 65536-round(2^24/16000)
  R_TIM0COUNT = 0xFBE8; // + ((snBSpeed * 100) - 100); //16khz playback freq
  R_TIM0CNT = 0x0080; //enable timer0

  // go
  playSnAOsc = 1;
}

void snd_playOscillatorB (u8 shape, u8 freqN, u8 loopmode, u8 soundlength){
  // stop
  R_DMA2CNT = 0;
  R_DMA2SRC = 0;
  R_TIM2CNT=0;
  playSnBSample = 0;
  playSnBOsc = 0;

  shapeB = shape;
  freqNB = freqN;
  loopmodeB = loopmode;
  oscLengthB = loopmode ? soundlength : 0xff;

  // WITH DMA !!
  R_DMA2SRC=(unsigned long) snd_oscShapes[shape][freqN]; //dma1 source
  R_DMA2DST=0x040000a4; //write to FIFO B address
  R_DMA2CNT=0xb600; //dma control: DMA enabled+ start on FIFO+32bit+repeat+increment source&dest

  R_TIM2COUNT=0xffff - LUT_PRECISION - 1; //0xffff-the number of samples to play
  R_TIM2CNT=0xC3; //enable timer1

  // Timer playback pour les samples
  R_TIM0CNT = 0;
  // 65536-round(2^24/16000)
  R_TIM0COUNT = 0xFBE8; // + ((snBSpeed * 100) - 100); //16khz playback freq
  R_TIM0CNT = 0x0080; //enable timer0

  // go
  playSnBOsc = 1;
}

// deprecated
/**
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

// deprecated
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
*/

// deprecated
/*void snd_playOscillatorA (u8 shape, u8 freqN, u8 loopmode, u8 soundlength){
   playSnASample = 0;
   playSnAOsc = 0;

   oscTimeCounterA = 0;
   oscSamplerCounterA = 0;
   snd_oscA_length = loopmode ? soundlength << 4 : NULL_VALUE;
   snd_oscA = (u32*) snd_oscShapes[shape][freqN];

   // go
   playSnAOsc = 1;
}*/
