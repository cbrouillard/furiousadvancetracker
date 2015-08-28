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
/*
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
 */

#include <hel2.h>
#include <stdlib.h>
#include <stdio.h>

#include "sine.h"
#include "soundApi.h"

#define NULL_VALUE 0xff

#define NB_FREQUENCES 72
const u16 freqs[NB_FREQUENCES] = {
      44, 156,   262,  363,  457,  547,  631,  710,  786,  854,  923,  986,
    1046, 1102, 1155, 1205, 1253, 1297, 1339, 1379, 1417, 1452, 1486, 1517,
    1546, 1575, 1602, 1627, 1650, 1673, 1694, 1714, 1732, 1750, 1767, 1783,
    1798, 1812, 1825, 1837, 1849, 1860, 1871, 1881, 1890, 1899, 1907, 1915,
    1923, 1930, 1936, 1943, 1949, 1954, 1959, 1964, 1969, 1974, 1978, 1982,
    1985, 1988, 1992, 1995, 1998, 2001, 2004, 2006, 2009, 2011, 2013, 2015};

const unsigned long voices[] = {
    /*?*/
    0x02468ace, 0xfdb97531, 0x02468ace, 0xfdb97531,
    0x2064a8ec, 0xdf9b5713, 0x2064a8ec, 0xdf9b5713,

    /*double saw*/
    0x01234567, 0x89abcdef, 0x01234567, 0x89abcdef,
    0x10325476, 0x98badcfe, 0x10325476, 0x98badcfe,

    /*?*/
    0x88808fff, 0x88808880, 0x00080888, 0x80008000,
    0x8808f8ff, 0x88088808, 0x00808088, 0x08000800,

    /*?*/
    0x34455667, 0x899aabbc, 0x34455667, 0x899aabbc,
    0x43546576, 0x98a9bacd, 0x43546576, 0x98a9bacb,

    /*?*/
    0x23345667, 0x899abcde, 0x23345667, 0x899abcde,
    0x32436576, 0x98a9cded, 0x32436576, 0x98a9cded,

    /*?*/
    0xacddda48, 0x3602cf16, 0x2c04e52c, 0xacddda48,
    0xcaddad84, 0x6320fc61, 0xc2405ec2, 0xcaddad84,

    /*triangular*/
    0x10325476, 0x67452301, 0xefcdab89, 0x98badcfe,
    0x01234567, 0x76543210, 0xfedcba98, 0x89abcdef,

    /*?*/
    0x01234567, 0x89abcdef, 0xffffffff, 0xfedcba98,
    0x10325376, 0x98badcfe, 0xffffffff, 0xefcdab89,

    /*?*/
    0xf0eeca86, 0x0a468ace, 0xffeeca86, 0x0a468ace,
    0x0feeac68, 0xa064a8ec, 0xffeeac68, 0xa064a8ec,

    /*?*/
    0x7ec9cea7, 0xcfe8ab72, 0x8d757203, 0x85136317,
    0xe79cec7a, 0xfc8eba27, 0xd8572730, 0x58313671,

    /*?*/
    0xfedcba98, 0x76543210, 0x76543210, 0x44002200,
    0xefcdab89, 0x67452301, 0x67452301, 0x44002200,

    /*?*/
    0x02468ace, 0xffffffff, 0xeca86420, 0x00448844,
    0x2064a8ec, 0xffffffff, 0xce8a4602, 0x00448844

};

#define MAX_KITS 32
kit* kits[MAX_KITS];

vu32 snASampleOffset = 1;
vu32 snBSampleOffset = 1;

/** Variables pour gérer la vitesse de lecture des samples */
vu8 snASpeed = 1;
vu8 snBSpeed = 1;

/** Variables pour gérer le loop sur les samples */
volatile bool snALoop = 0;
volatile bool snBLoop = 0;

u32 snASmpSize;
u32 snBSmpSize;

const vu32* snASample;
const vu32* snBSample;

volatile bool playSnASample = 0;
volatile bool playSnBSample = 0;

void snd_timerFunc_sample();

void snd_loadWav(u8 inst) {
    REG_DMA3SAD = (u32) & voices[inst << 2];
    REG_DMA3DAD = (u32) & REG_WAVE_RAM0;
    REG_DMA3CNT_L = 4;
    REG_DMA3CNT_H = 0x8400;
    REG_SOUND3CNT_L ^= 0x0040;
}

u8 snd_calculateTransposedFrequency(u8 freq, u8 transpose) {
    freq += transpose;
    if (freq >= NB_FREQUENCES) {
        freq = 0; // ok pour l'instant ca ira
    }
    return freq;
}

void snd_init_soundApi() {

    // activation de la puce sonore
    REG_SOUNDCNT_X = 0x80;

    // volume à fond, activation stéréo des 4 canaux
    // activation des directsound A et B en mode timer 0 et 1
    REG_SOUNDCNT_L = 0xff77;
    REG_SOUNDCNT_H = 0xbb0e;

    REG_SOUND3CNT_L = SOUND3BANK32 | SOUND3SETBANK1;

    snd_loadWav(0);
}

void snd_changeChannelOutput(u8 channelNumber, u8 outputValue) {
    /**0 __ / 1 L_ / 2 R_ / 3 RL*/
    switch (outputValue) {
        case 0:
            REG_SOUNDCNT_L &= ~(1 << (8 + channelNumber));
            REG_SOUNDCNT_L &= ~(1 << (12 + channelNumber));
            break;
        case 1:
            REG_SOUNDCNT_L |= (1 << (12 + channelNumber));
            REG_SOUNDCNT_L &= ~(1 << (8 + channelNumber));
            break;
        case 2:
            REG_SOUNDCNT_L |= (1 << (8 + channelNumber));
            REG_SOUNDCNT_L &= ~(1 << (12 + channelNumber));
            break;
        case 3:
            REG_SOUNDCNT_L |= (1 << (12 + channelNumber));
            REG_SOUNDCNT_L |= (1 << (8 + channelNumber));
            break;
    }
}

void snd_playSoundOnChannel1(
        u16 sweeptime, u16 sweepdir, u16 sweepshifts, u16 volume,
        u16 envdirection, u16 envsteptime, u16 waveduty, u16 soundlength,
        u16 loopmode, u8 output, u8 sfreq, u8 transpose) {

    snd_changeChannelOutput(0, output);

    if (loopmode == 0) {
        soundlength = 0;
    }

    if (transpose) {
        sfreq = snd_calculateTransposedFrequency(sfreq, transpose);
    }

    REG_SOUND1CNT_L = (sweeptime << 4) | (sweepdir << 3) | sweepshifts;
    REG_SOUND1CNT_H = (volume << 12) | (envdirection << 11) | (envsteptime << 8) | (waveduty << 6) | soundlength;

    REG_SOUND1CNT_X = SOUND1INIT | (loopmode << 14) | freqs[sfreq];
    REG_SOUND1CNT_X = (REG_SOUND1CNT_X & 0xf800) | (loopmode << 14) | freqs[sfreq];
}

void snd_playSoundOnChannel2(u16 volume,
        u16 envdir, u16 envsteptime, u16 waveduty, u16 soundlength,
        u16 loopmode, u8 output, u8 sfreq, u8 transpose) {

    snd_changeChannelOutput(1, output);

    if (loopmode == 0) {
        soundlength = 0;
    }

    if (transpose) {
        sfreq = snd_calculateTransposedFrequency(sfreq, transpose);
    }

    REG_SOUND2CNT_L = (volume << 12) | (envdir << 11) | (envsteptime << 8) | (waveduty << 6) | soundlength;

    REG_SOUND2CNT_H = SOUND2INIT | (loopmode << 14) | freqs[sfreq];
    REG_SOUND2CNT_H = (REG_SOUND2CNT_H & 0xf800) | (loopmode << 14) | freqs[sfreq];
}

void snd_modifyWaveCanalVolume(u16 volume) {
    switch (volume) {
        case 0:
            REG_SOUND3CNT_H = SOUND3OUTPUT0;
            break;
        case 1:
            REG_SOUND3CNT_H = SOUND3OUTPUT14;
            break;
        case 2:
            REG_SOUND3CNT_H = SOUND3OUTPUT12;
            break;
        case 3:
            REG_SOUND3CNT_H = SOUND3OUTPUT34;
            break;
        case 4:
            REG_SOUND3CNT_H = SOUND3OUTPUT1;
            break;
    }
}

void snd_playSoundOnChannel3(u16 volume, u16 soundLength, u16 loopmode, u16 voice,
        u16 bank, u16 bankMode, u8 output, u8 freq, u8 transpose) {

    snd_changeChannelOutput(2, output);

    REG_SOUND3CNT_L = SOUND3PLAY;
    REG_SOUND3CNT_X = SOUND3INIT;
    REG_SOUND3CNT_H = SOUND3OUTPUT1;

    if (transpose) {
        freq = snd_calculateTransposedFrequency(freq, transpose);
    }

    REG_SOUND3CNT_H = soundLength;
    //REG_SOUNDCNT_L|=0x4400;
    if (bankMode == 0) { // SINGLE MODE 
        REG_SOUND3CNT_L &= ~SOUND3PLAY; //stop sound
        snd_loadWav(voice);
        snd_loadWav(voice + 2);

        REG_SOUND3CNT_L = SOUND3PLAY | SOUND3BANK32;
    } else { // DUAL MODE
        snd_loadWav(voice);
        //REG_SOUND3CNT_L |= SOUND3BANK64;
    }

    if (bank == 1) {
        REG_SOUND3CNT_L |= SOUND3SETBANK1;
    } else {
        //REG_SOUND3CNT_L &= 0xffbf;
    }

    snd_modifyWaveCanalVolume(volume);
    REG_SOUND3CNT_H |= soundLength;

    if (loopmode == 0) {
        REG_SOUND3CNT_X = freqs[freq] | SOUND3PLAYLOOP | SOUND3INIT;
    } else {
        REG_SOUND3CNT_X = freqs[freq] | SOUND3PLAYONCE | SOUND3INIT;
    }

}

void snd_playSoundOnChannel4(u16 volume, u16 envdir, u16 envsteptime, u16 soundlength,
        u16 loopmode, u8 output, u16 shiftFreq, u16 stepping, u8 freqRatio, u8 transpose) {

    snd_changeChannelOutput(3, output);

    REG_SOUND4CNT_L = (volume << 12) | (envdir << 11) | (envsteptime << 8) | soundlength;

    REG_SOUND4CNT_H = SOUND4INIT | (loopmode << 14) | (shiftFreq << 4) | (stepping << 3) | freqRatio;
    REG_SOUND4CNT_H = (REG_SOUND4CNT_H & 0xF800) | (loopmode << 14) | (shiftFreq << 4) | (stepping << 3) | freqRatio;
}

void snd_stopAllSounds() {
    REG_SOUNDCNT_X = 0x0;

    playSnASample = 0;
    playSnBSample = 0;

    snd_init_soundApi();
}

void snd_effect_kill(u8 channelId, u8 value) {
    switch (channelId) {
        case 0:
            REG_SOUND1CNT_H &= value == 0 ? 0x3f : value;
            REG_SOUND1CNT_H |= (1 << 14);
            break;
        case 1:
            REG_SOUND2CNT_H &= value == 0 ? 0x3f : value;
            REG_SOUND2CNT_H |= (1 << 14);
            break;
        case 2:
            REG_SOUND3CNT_H &= value == 0 ? 0xff : value;
            break;
        case 3:
            REG_SOUND4CNT_L &= value == 0 ? 0x3f : value;
            REG_SOUND4CNT_H |= (1 << 14);
            break;
        case 4:
            playSnASample = 0;
            break;
        case 5:
            playSnBSample = 0;
            break;
    }
}

void snd_tryToApplyEffect(u8 channelId, u8 effectNumber, u8 effectValue) {
    switch (effectNumber) {
        case EFFECT_KILL:
            snd_effect_kill(channelId, effectValue);
            break;
    }
}

/// GESTION DES SAMPLES
u8 snd_availableKits = 0;

const u8 snd_countAvailableKits() {
    if (!snd_availableKits) {
        kit* table = snd_loadKit(0);
        if (table) {
            char buffer[4];
            strncpy(buffer, gbfs_get_nth_obj(table, 0, NULL, NULL), 3);
            snd_availableKits = atoi(buffer);
        } else {
            snd_availableKits = 0;
        }
    }

    return snd_availableKits;
}

void snd_init_kits() {
    R_TIM0COUNT = 0xffff;
    R_TIM0CNT = 0x00C3;
    hel_IntrStartHandler(INT_TYPE_TIM0, (void*) &snd_timerFunc_sample);

    snd_countAvailableKits();
    u8 cpt = 0;

    kit* kit = find_first_gbfs_file(find_first_gbfs_file);
    if (kit) {
        while (cpt < snd_availableKits && cpt < MAX_KITS) {
            kit = skip_gbfs_file(kit);
            kits[cpt] = kit;
            cpt++;
        }
    }
}

kit* snd_loadKit(u8 numKit) {
    u8 cpt = 0;
    const GBFS_FILE* kit = find_first_gbfs_file(find_first_gbfs_file);
    while (cpt < numKit) {
        kit = skip_gbfs_file(kit);
        cpt++;
    }

    return kit;
}

u8 snd_countSamplesInKit(kit* dat) {
    return gbfs_count_objs(dat) - 1; // -1 car le fichier info ne doit pas être compté.
}

u8 snd_countSamplesInKitById(u8 kitId) {
    kit* kit = kits[kitId];
    if (kit) {
        return snd_countSamplesInKit(kit);
    }

    return 0;
}

void snd_getKitName(kit* dat, u8 kitId, char* buffer) {
    if (dat) {
        strncpy(buffer, gbfs_get_nth_obj(dat, 0, NULL, NULL), 8);
    } else {
        sprintf(buffer, "KIT %d", kitId);
    }
}

char* snd_getKitNameById(u8 kitId) {

    static char kitName[9];

    kit* kit = kits[kitId];
    snd_getKitName(kit, kitId, kitName);

    return kitName;
}

char* snd_getSampleNameById(u8 kitId, u8 sampleId) {
    static char sampleName[4];
    char buffer[24];

    kit* kit = kits[kitId];
    if (kit) {
        u32* sample = (u32*) gbfs_get_nth_obj(kit, sampleId + 1, buffer, NULL);
        if (sample) {

            //strncpy(sampleName, buffer, 3);
            sampleName[0] = buffer[0];
            sampleName[1] = buffer[1];
            sampleName[2] = buffer[2];

        } else {
            sprintf(sampleName, "---");
        }

    } else {
        sprintf(sampleName, "---");
    }

    sampleName[3] = '\0';
    return sampleName;
}

void snd_resetFIFOA() {
    REG_SOUNDCNT_H |= 1 << 0xB;
}

void snd_resetFIFOB() {
    REG_SOUNDCNT_H |= 1 << 0xF;
}

void snd_processSampleA_ok() {
    if (playSnASample) {
        REG_SOUNDCNT_H &= ~(1 << 0xB);
        if (!(snASampleOffset & 3)) {
            SND_REG_SGFIFOA = snASample[snASampleOffset >> 2]; // u32
        }
        snASampleOffset+=snASpeed;
        //HEL_DEBUG_MSG ("o: %d s: %d", snASampleOffset, snASmpSize);
        if (snASampleOffset > snASmpSize) {
            //sample finished!
            playSnASample = snALoop; // si loop = 0 on arrete, sinon c'est reparti.
            snASampleOffset = 0;
            snd_resetFIFOA();
        }


    }

}


vu8 oscCounter = 0;
vu32 bufferOscA = 0;

#define SAMPLERATE 16384

vu32 bufferOsc = 0;
vu32 phase = 0;
vu8 val = 0;
vu32 snd_processOscillator (u8 amplitude, u16 freq) {

    phase = phase + ((SIN_LUT_SIZE * freq) / SAMPLERATE);
    if (phase > SIN_PHASE_MAX){
        phase = phase - SIN_PHASE_MAX;
    }
    val = amplitude * sinLUT[phase] + 128;
    bufferOsc = val;

    phase = phase + ((SIN_LUT_SIZE * freq) / SAMPLERATE);
    if (phase > SIN_PHASE_MAX){
        phase = phase - SIN_PHASE_MAX;
    }
    val = amplitude * sinLUT[phase] + 128;
    bufferOsc |= (val << 8);

    phase = phase + ((SIN_LUT_SIZE * freq) / SAMPLERATE);
    if (phase > SIN_PHASE_MAX){
        phase = phase - SIN_PHASE_MAX;
    }
    val = amplitude * sinLUT[phase] + 128;
    bufferOsc |= (val << 16);

    phase = phase + ((SIN_LUT_SIZE * freq) / SAMPLERATE);
    if (phase > SIN_PHASE_MAX){
        phase = phase - SIN_PHASE_MAX;
    }
    val = amplitude * sinLUT[phase] + 128;
    bufferOsc |= (val << 24);

    return bufferOsc;
}

void snd_processSampleA() {
    if (playSnASample) {

        if (!(oscCounter & 3)){
            REG_SOUNDCNT_H &= ~(1 << 0xB);
            SND_REG_SGFIFOA = snd_processOscillator (1, 40);
        }

        oscCounter += 1;
    }

}


void snd_processSampleB() {
    if (playSnBSample) {
        REG_SOUNDCNT_H &= ~(1 << 0xF);
        if (!(snBSampleOffset & 3)) {
            SND_REG_SGFIFOB = snBSample[snBSampleOffset >> 2]; // u32
        }
        
        snBSampleOffset += snBSpeed;
        
        //HEL_DEBUG_MSG ("o: %d s: %d", snBSampleOffset, snBSmpSize);
        if (snBSampleOffset > snBSmpSize) {
            //sample finished!
            playSnBSample = snBLoop;
            snBSampleOffset = 0;
            snd_resetFIFOB();
        }
    }
}

void snd_timerFunc_sample() {
    snd_processSampleA();
    snd_processSampleB();
    hel_IntrAcknowledge(INT_TYPE_TIM0);
}

void snd_playChannelASample(u8 kitId, u8 sampleNumber,
        u8 volume, u8 speed, bool looping, bool timedMode, u8 length, u8 offset, u8 output) {

    kit* kit = kits[kitId];
    if (kit) {

        playSnASample = 0;
        snASample = gbfs_get_nth_obj(kit, sampleNumber + 1, NULL, &snASmpSize);

        if (snASample) {
            if (!volume){
                REG_SOUNDCNT_H &= ~(1 << 0x2);
            } else {
                REG_SOUNDCNT_H |= 1 << 0x2;
            }

            // output
            u8 mem = output >> 1;
            if (mem){
                REG_SOUNDCNT_H |= 1 << 0x9;
            }else{
                REG_SOUNDCNT_H &= ~(1 << 0x9);
            }
            mem = output & 0x1;
            if (mem){
                REG_SOUNDCNT_H |= 1 << 0x8;
            } else {
                REG_SOUNDCNT_H &= ~(1 << 0x8);
            }

            snASpeed = speed;
            snALoop = looping;
            snASampleOffset = snASmpSize * offset / 100;
            if (timedMode){
                snASmpSize = snASmpSize * length / 100;
            }
            playSnASample = 1;
        }

    }

}

void snd_playChannelBSample(u8 kitId, u8 sampleNumber,
        u8 volume, u8 speed, bool looping, bool timedMode, u8 length, u8 offset, u8 output) {
    kit* kit = kits[kitId];
    if (kit) {

        playSnBSample = 0;
        snBSample = gbfs_get_nth_obj(kit, sampleNumber + 1, NULL, &snBSmpSize);

        if (snBSample) {
            if (!volume){
                REG_SOUNDCNT_H &= ~(1 << 0x3);
            } else {
                REG_SOUNDCNT_H |= 1 << 0x3;
            }

            // output
            u8 mem = output >> 1;
            if (mem){
                REG_SOUNDCNT_H |= 1 << 0xD;
            }else{
                REG_SOUNDCNT_H &= ~(1 << 0xD);
            }
            mem = output & 0x1;
            if (mem){
                REG_SOUNDCNT_H |= 1 << 0xC;
            } else {
                REG_SOUNDCNT_H &= ~(1 << 0xC);
            }

            snBSpeed = speed;
            snBLoop = looping;
            snBSampleOffset = snBSmpSize * offset / 100;
            if (timedMode){
                snBSmpSize = snBSmpSize * length / 100;
            }
            playSnBSample = 1;
        }

    }

}


