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
#ifndef _SOUND_API_
#define _SOUND_API_

#include "register.h"

/**

Quelques règles à suivre :

- toutes les fonctions sont préfixées par "snd_" comme ca pas de risque de conflit.
- les fonctions non testées sont préfixées par "tmp_snd_", une fois testée -> on change en "snd_".
- un petit commentaire au dessus de la fonction pour documenter.

 **/

/**
Initialise le mode audio sur la Gameboy: active les 4 canaux.
 **/
void snd_init_soundApi();

/**
 * Joue un son sur le channel 1.
 * sweeptime: temps de sweep de 0 à 7
 * sweepdir: direction du sweep 1 increase, 0 decrease
 * sweepshifts: l'effet sweep de 0 à 7
 * volume: de 0 à F
 * envdir: direction de l'enveloppe 1 increase, 0 decrease
 * envsteptime: pas de l'enveloppe de 0 à 7
 * waveduty: forme de l'onde 0, 1, 2 ou 3
 * soundlength: durée du son 0 à 3f (attention valeur inversée: 3f = court) ACTIF seulement si loopmode = 1
 * loopmode: timed 1, continuous 0
 * sfreq: la fréquence de la note jouée. de 0 à 2047
 **/
void snd_playSoundOnChannel1(
        u16 sweeptime, u16 sweepdir, u16 sweepshifts, u16 volume,
        u16 envdir, u16 envsteptime, u16 waveduty, u16 soundlength,
        u16 loopmode, u16 sfreq, u8 transpose);

void snd_simple_playSoundOnChannel1 (u8 sweep, u16 envelope, u8 mode,
        u8 length, u16 noteFreq, u8 transpose);

/**
 * Joue un son sur le channel 2 
 * volume: de 0 à F
 * envdir: direction de l'enveloppe 1 increase, 0 decrease
 * envsteptime: pas de l'enveloppe de 0 à 7
 * waveduty: forme de l'onde 0, 1, 2 ou 3
 * soundlength: durée du son 0 à 3f (attention valeur inversée: 3f = court) ACTIF seulement si loopmode = 1
 * loopmode: continuous 0, timed 1
 * sfreq: la fréquence de la note jouée. de 0 à 2047
 */
void snd_playSoundOnChannel2(u16 volume,
        u16 envdir, u16 envsteptime, u16 waveduty, u16 soundlength,
        u16 loopmode, u16 sfreq, u8 transpose);

void snd_simple_playSoundOnChannel2 (u16 envelope, 
        u8 mode, u8 length, u8 noteFreq, u8 transpose);

/**
 * Joue un son sur le channel 3 
 * volume: 0 à 3
 * soundlength: durée du son de 0 a FF (valeur inversée: FF = très court)
 * loopmode: timed = 1, continuous = 0
 * voice: numéro de la voix à jouer (A REFACTORER passer un unsigned long *)
 * bank: numéro de la bank à jouer 0 ou 1 (appliqué seulement si bankMode = 0)
 * bankMode : single 0, dual 1
 * freq: la fréquence de la note
 */
void snd_playSoundOnChannel3 (u16 volume, u16 soundLength, u16 loopmode, u16 voice, 
        u16 bank, u16 bankMode, u16 freq, u8 transpose);

void snd_simple_playSoundOnChannel3 ();

/**
 * Joue un son sur le channel 3
 * volume: de 0 à F
 * envdir: direction de l'enveloppe 1 increase, 0 decrease
 * envsteptime: pas de l'enveloppe de 0 à 7
 * waveduty: forme de l'onde 0, 1, 2 ou 3
 * soundlength: durée du son 0 à 3f (attention valeur inversée: 3f = court) ACTIF seulement si loopmode = 1
 * loopmode: timed 1, continuous 0
 * shiftFreq:
 * stepping:
 * freqRatio: 
 */
void snd_playSoundOnChannel4 (u16 volume, u16 envdir, u16 envsteptime, u16 soundlength,
        u16 loopmode, u16 shiftFreq, u16 stepping, u16 freqRatio, u8 transpose);

void snd_simple_playSoundOnChannel4 (u16 envelope, u8 mode, u8 length);

/**
 * Eteint tout les sons en cours de lecture. 
 */
void snd_stopAllSounds();

#endif
