#ifndef _SYNTH_FM_
#define _SYNTH_FM_

#define NB_SYNTH_FM_FUNCTIONS 2

/** Fonction pour la synth FM **/
u32 snd_modulation_none (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi);
u32 snd_modulation_synthFM_n1 (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi);

/** Function pointers **/
u32 (*snd_modulation_applyModulation[NB_SYNTH_FM_FUNCTIONS]) (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi);

void snd_synthFM_init (){
    snd_modulation_applyModulation[0] = snd_modulation_none;
    snd_modulation_applyModulation[1] = snd_modulation_synthFM_n1;
}

/** Implementations **/
u32 snd_modulation_none (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi){
    // nothing here
    return data;
}


u32 snd_modulation_synthFM_n1 (u32 data, u32 amp, u32 f, u32 t, u32 param, u32 phi) {
    return  data
            + amp // Amp
            * snd_sin_lut [
                LUT_SIZE * f // 130 = f, LUT_SIZE = 2PI
                * ( 1 + snd_sin_lut[ t * param ] / 100 ) // 500 = param
                * t // t
                + phi // phi
            ] ;
}

#endif
