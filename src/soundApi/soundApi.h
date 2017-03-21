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
 * \file soundApi.h
 * \brief Définition des fonctions implémentées par la soundApi GBA.
 *
 * Quelques règles à suivre :
 *
 * - toutes les fonctions sont préfixées par "snd_" comme ca pas de risque de conflit.
 * - les fonctions non testées sont préfixées par "tmp_snd_", une fois testée -> on change en "snd_".
 * - un petit commentaire au dessus de la fonction pour documenter.
 **/
#ifndef _SOUND_API_
#define _SOUND_API_

#define EFFECT_CHORD 0 // CH [OK, TO TEST]
#define EFFECT_CUSTOMVOICE 1 // CV [OK]
#define EFFECT_DELAY 2 // DL
#define EFFECT_ENVELOPE 3 // EN
#define EFFECT_HOP 4 // HO [OK, TO TEST]
#define EFFECT_KILL 5 // KL [TO CONFIGURE]
#define EFFECT_OUTPUT 6 // OU [OK]
#define EFFECT_RETRIG 7 // RT
#define EFFECT_SLIDE 8 // SL
#define EFFECT_SAMPLERATE 9 // SR [OK]
#define EFFECT_SWEEP 10 // SW [OK]
#define EFFECT_TABLE 11 // TA
#define EFFECT_TEMPO 12 // TM [OK]
#define EFFECT_TRANSPOSE 13 // TS
#define EFFECT_VIBRATO 14 // VB
#define EFFECT_VOLUME 15 // VO [OK]
#define EFFECT_WAVEFORM 16 // WA

#include "system/register.h"
#include "kits/gbfs.h"
#include "oscillator/oscillator.h"

#ifndef LUT_PRECISION
#define LUT_PRECISION 128
#endif

typedef const GBFS_FILE kit;

extern volatile bool playSnASample;
extern volatile bool playSnBSample;

/**
 * \brief Initialise le mode audio sur la Gameboy: active les 4 canaux.
 **/
void snd_init_soundApi(u8 sampleRate);

void snd_setSampleRate (u8 sampleRate);

/**
 * \brief Précharge les kits présents dans la cartouche.
 */
void snd_init_kits();

/**
 *
 * \brief Joue un son sur le channel 1.
 *
 * \param sweeptime Temps de sweep de 0 à 7
 * \param sweepdir Direction du sweep 1 increase, 0 decrease
 * \param sweepshifts L'effet sweep de 0 à 7
 * \param volume De 0 à F
 * \param envdir Direction de l'enveloppe 1 increase, 0 decrease
 * \param envsteptime Pas de l'enveloppe de 0 à 7
 * \param waveduty Forme de l'onde 0, 1, 2 ou 3
 * \param soundlength Durée du son 0 à 3f (attention valeur inversée: 3f = court) ACTIF seulement si loopmode = 1
 * \param loopmode Timed 1, continuous 0
 * \param output sortie du son 0 PAS DE SON / 1 GAUCHE / 2 DROITE / 3 GAUCHE ET DROITE
 * \param sfreq Le numéro de fréquence de la note jouée. de 0 à 72 cf: const u8 freqs[NB_FREQUENCES]
 * \param transpose La valeur de transposition de 0 à FF
 **/
void snd_playSoundOnChannel1(
        u16 sweeptime, u16 sweepdir, u16 sweepshifts, u16 volume,
        u16 envdir, u16 envsteptime, u16 waveduty, u16 soundlength,
        u16 loopmode, u8 output, u8 sfreq, u8 transpose);

void snd_applyFrequencyOn (u8 channel, u8 sfreq);

/**
 * \brief Joue un son sur le channel 1.
 *
 * \param sweep Combinaison de tous les paramètres sweep (sweeptime, sweepdir, sweepshifts) de 0 à FF.
 * \param envelope Combinaison de tous les paramètres pour l'enveloppe (volume, envdir, envsteptime, waveduty) de 0 à FFFF
 * \param mode Timed 1, continuous 0
 * \param length Durée du son 0 à 3f (attention valeur inversée: 3f = court) ACTIF seulement si loopmode = 1
 * \param noteFreq Le numéro de fréquence de la note jouée. de 0 à 72 cf: const u8 freqs[NB_FREQUENCES]
 * \param transpose La valeur de transposition de 0 à FF.
 *
 * Cette méthode est plus simple que snd_playSoundOnChannel1 mais produit le même résultat.
 */
void snd_simple_playSoundOnChannel1(u8 sweep, u16 envelope, u8 mode,
        u8 length, u16 noteFreq, u8 transpose);

/**
 * \brief Joue un son sur le channel 2
 *
 * @param volume de 0 à F
 * @param envdir direction de l'enveloppe 1 increase, 0 decrease
 * @param envsteptime pas de l'enveloppe de 0 à 7
 * @param waveduty forme de l'onde 0, 1, 2 ou 3
 * @param soundlength durée du son 0 à 3f (attention valeur inversée: 3f = court) ACTIF seulement si loopmode = 1
 * @param loopmode continuous 0, timed 1
 * @param output sortie du son 0 PAS DE SON / 1 GAUCHE / 2 DROITE / 3 GAUCHE ET DROITE
 * @param sfreq le numéro de fréquence de la note jouée. de 0 à 72 cf: const u8 freqs[NB_FREQUENCES]
 * @param transpose le paramètre de transposition
 */
void snd_playSoundOnChannel2(u16 volume,
        u16 envdir, u16 envsteptime, u16 waveduty, u16 soundlength,
        u16 loopmode, u8 output, u8 sfreq, u8 transpose);

/**
 * \brief Méthode simplifiée pour jouer un son sur le channel 2. <b>NON IMPLEMENTE!</b>
 *
 * @param envelope
 * @param mode
 * @param length
 * @param noteFreq
 * @param transpose
 */
void snd_simple_playSoundOnChannel2(u16 envelope,
        u8 mode, u8 length, u8 noteFreq, u8 transpose);

/**
 * \brief Joue un son sur le channel 3
 *
 * @param volume 0 à 4
 * @param soundLength durée du son de 0 a FF (valeur inversée: FF = très court)
 * @param loopmode timed = 1, continuous = 0
 * @param voice numéro de la voix à jouer
 * @param customVoice données de la voix custom à jouer. S'applique si !=0 et prend le pas sur voice.
 * @param bank numéro de la bank à jouer 0 ou 1 (appliqué seulement si bankMode = 1)
 * @param bankMode single 0, dual 1
 * \param output sortie du son 0 PAS DE SON / 1 GAUCHE / 2 DROITE / 3 GAUCHE ET DROITE
 * @param freq le numéro de fréquence de la note jouée. de 0 à 72 cf: const u16 freqs[NB_FREQUENCES]
 * @param transpose le paramètre de transposition
 */
void snd_playSoundOnChannel3(u16 volume, u16 soundLength, u16 loopmode, u16 voice, u32* customVoice,
        u16 bank, u16 bankMode, u8 output, u8 freq, u8 transpose);

/**
 * \brief Méthode simplifiée pour jouer un son sur le channel 3. <b>NON IMPLEMENTE!</b>
 */
void snd_simple_playSoundOnChannel3();

/**
 * \brief Joue un son sur le channel 4
 *
 * @param volume de 0 à F
 * @param envdir direction de l'enveloppe 1 increase, 0 decrease
 * @param envsteptime pas de l'enveloppe de 0 à 7
 * @param soundlength durée du son 0 à 3f (attention valeur inversée: 3f = court) ACTIF seulement si loopmode = 1
 * @param loopmode timed 1, continuous 0
 * \param output sortie du son 0 PAS DE SON / 1 GAUCHE / 2 DROITE / 3 GAUCHE ET DROITE
 * @param shiftFreq
 * @param stepping
 * @param freqRatio
 * @param transpose
 */
void snd_playSoundOnChannel4(u16 volume, u16 envdir, u16 envsteptime, u16 soundlength,
        u16 loopmode, u8 output, u16 shiftFreq, u16 stepping, u8 freqRatio, u8 transpose);

/**
 * \brief Méthode simplifiée pour jouer un son sur le channel 4. <b>NON IMPLEMENTE!</b>
 */
void snd_simple_playSoundOnChannel4(u16 envelope, u8 mode, u8 length);

/**
 * \brief Eteint tout les sons en cours de lecture.
 */
void snd_stopAllSounds();

/**
 * \brief Cette fonction essaie d'appliquer en effet en dehors du contexte "note": la commande sera appliquée
 * sans jouer de note.
 *
 * @param channelId le numéro de channel sur lequel appliquer l'effet
 * @param effectNumber le numéro d'effet à appliquer
 * @param effectValue la valeur de l'effet
 */
void snd_tryToApplyEffect(u8 channelId, u8 effectNumber, u8 effectValue);

/**
 * \brief Charge un kit par son numéro.
 * @param numKit le numéro du kit à charger.
 * @return un pointeur vers les données du kit ou NULL (0x0) si non trouvé.
 */
kit* snd_loadKit(u8 numKit);

/**
 * \brief Compte le nombre de kits inclus dans la cartouche. Cette fonction est "double".
 * Elle effectue le calcul la première fois qu'elle est appelée est place le résultat dans un cache.
 * Ce cache est simplement retourné lors des autres appels (le nombre de kits ne peut pas changer une fois
 * la GBA allumée).
 */
const u8 snd_countAvailableKits();

/**
 * \brief Compte le nombre de samples trouvés dans un kit donné.
 * @param dat le pointeur vers les données du kit.
 * @return le nombre de samples (uniquement les fichiers wav) présent dans le kit
 */
u8 snd_countSamplesInKit(kit* dat);

/**
 * \brief Joue un sample sur le canal directsound A. Attention, il est nécessaire d'avoir
 * un contexte GBFS afin d'utiliser cette fonction.
 * @param dat le contexte géré par GBFS
 * @param sampleNumber le numéro de sample à jouer dans le contexte GBFS
 */
void snd_playSampleOnChannelA(kit* dat, u8 sampleNumber);
void snd_playSampleOnChannelAById(u8 kitId, u8 sampleNumber);

/**
 * \brief Joue un sample sur le canal A en appliquant quelques paramètres supplémentaires.
 *
 * @param kitId le numéro de kit contenant le sample de 0 à MAX_KITS
 * @param sampleNumber le numéro de sample dans le kit de 0 à 255
 * @param volume le ratio de volume à appliquer 0 = 50% 1 = 100%
 * @param speed la vitesse d'execution du sample de 0 à F  1 = normal, 0 = 50%, F = très rapide (16x)
 * @param looping si looping est à 1, la lecture du sample sera répétée à l'infini
 * @param timedMode permet d'activer le mode timing 1 = actif 0 = inactif
 * @param length si timedMode = 1 alors ce paramètre permet de spécifier la longeur du sample 0 = 0% 64 = 100%
 * @param offset permet de spécifier a partir de quel moment le sample démarre de 0 = début à 99 = fin
 * @param output droite, gauche ou les deux. Voire rien.
 */
void snd_playChannelASample(u8 kitId, u8 sampleNumber, u8 volume, u8 speed, bool looping, bool timedMode, u8 length, u8 offset, u8 output);

/**
 * \brief Joue un son oscillator sur le canal A en appliquant quelques paramètres.
 *
 * @param shape forme de l'onde (sin, square, triangle, saw)
 * @param freqN le numéro de fréquence à jouer
 * @param loopmode permet d'activer le mode timing 1 = actif 0 = inactif
 * @param soundlength si timedMode = 1 alors ce paramètre permet de spécifier la longeur du sample 0 = 0% 64 = 100%
 * @param volume 1 = volume normal (fort) 0 = volume faible
 * @param output droite, gauche ou les deux. Voire rien.
 */
void snd_playOscillatorA (u8 shape, u8 freqN, u8 loopmode, u8 soundlength, u8 volume, u8 output);

/**
 * \brief Joue un son oscillator sur le canal B en appliquant quelques paramètres.
 *
 * @param shape forme de l'onde (sin, square, triangle, saw)
 * @param freqN le numéro de fréquence à jouer
 * @param loopmode permet d'activer le mode timing 1 = actif 0 = inactif
 * @param soundlength si timedMode = 1 alors ce paramètre permet de spécifier la longeur du sample 0 = 0% 64 = 100%
 * @param volume 1 = volume normal (fort) 0 = volume faible
 * @param output droite, gauche ou les deux. Voire rien.
 */
void snd_playOscillatorB (u8 shape, u8 freqN, u8 loopmode, u8 soundlength, u8 volume, u8 output);

/**
 * \brief Joue un sample sur le canal directsound B. Attention, il est nécessaire d'avoir
 * un contexte GBFS afin d'utiliser cette fonction.
 * @param dat le contexte géré par GBFS
 * @param sampleNumber le numéro de sample à jouer dans le contexte GBFS
 */
void snd_playSampleOnChannelB(kit* dat, u8 sampleNumber);
void snd_playSampleOnChannelBById(u8 kitId, u8 sampleNumber);

/**
 * \brief Joue un sample sur le canal B en appliquant quelques paramètres supplémentaires.
 *
 * @param kitId le numéro de kit contenant le sample de 0 à MAX_KITS
 * @param sampleNumber le numéro de sample dans le kit de 0 à 255
 * @param volume le ratio de volume à appliquer 0 = 50% 1 = 100%
 * @param speed la vitesse d'execution du sample de 0 à F  1 = normal, 0 = 50%, F = très rapide (16x)
 * @param looping si looping est à 1, la lecture du sample sera répétée à l'infini
 * @param timedMode permet d'activer le mode timing 1 = actif 0 = inactif
 * @param length si timedMode = 1 alors ce paramètre permet de spécifier la longeur du sample 0 = 0% 64 = 100%
 * @param offset permet de spécifier a partir de quel moment le sample démarre de 0 = début à 99 = fin
 * @param output droite, gauche ou les deux. Voire rien.
 */
void snd_playChannelBSample(u8 kitId, u8 sampleNumber, u8 volume, u8 speed, bool looping, bool timedMode, u8 length, u8 offset, u8 output);

/**
 * \brief Renvoie le nom du kit en donnant l'id de celui-ci (de 0 à 255).
 * @param kitId le numéro du kit voulu
 */
char* snd_getKitNameById(u8 kitId);

/**
 * \brief Récupère le nom d'un sample donné (3 caractères).
 * \param kitId le numéro du kit
 * \param sampleId le numéro du sample
 */
char* snd_getSampleNameById(u8 kitId, u8 sampleId);

/**
 * \brief Compte le nombre de samples présents dans un kit (défini par son numéro).
 * Attention, le chiffre retourné ne compte pas le fichier info.txt inclus dans le kit.
 * \param kitId le numéro du kit à inspecter
 */
u8 snd_countSamplesInKitById(u8 kitId);

void snd_effect_kill(u8 channelId, u8 value);

void snd_fifoA_setOutput (u8 output);
void snd_fifoB_setOutput (u8 output);
void snd_fifoA_setVolume (u8 volume);
void snd_fifoB_setVolume (u8 volume);

extern const unsigned long voices[];

#endif
