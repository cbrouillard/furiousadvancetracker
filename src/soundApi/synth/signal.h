#ifndef _SYNTH_FM_
#define _SYNTH_FM_

#include "../luts/generic_sinlut.h"

#define NB_SYNTH_FM_FUNCTIONS 3

/** Fonction pour la synth FM **/
u32 snd_modulation_none (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi);
u32 snd_modulation_synthFM_n1 (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi);
u32 snd_modulation_synthAM (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi);

/** Function pointers **/
u32 (*snd_modulation_applyModulation[NB_SYNTH_FM_FUNCTIONS]) (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi);

void snd_synthFM_init (){
    snd_modulation_applyModulation[0] = snd_modulation_none;
    snd_modulation_applyModulation[1] = snd_modulation_synthFM_n1;
    snd_modulation_applyModulation[2] = snd_modulation_synthAM;
}

/** Implementations **/
u32 snd_modulation_none (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi){
    // nothing here
    return data;
}


u32 snd_modulation_synthFM_n1 (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi) {
    return  data
            + amp
            * snd_sin_lut [
                (LUT_GENERIC_SIZE * f) // LUT_SIZE = 2PI
                * ( 1 + snd_sin_lut[ t * param ] / 1000 )
                * t
                + phi
            ] ;
}

u32 snd_modulation_synthAM (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi){
    return data * (1 - amp * (snd_sin_lut[param * t]));
}

#endif
