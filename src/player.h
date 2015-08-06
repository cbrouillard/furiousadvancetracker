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
 * \file player.h
 * \brief Contient toutes les fonctions nécessaires pour la lecture "sonore" du projet en cours de composition.

 * DOC: Délai pour 1/16e de mesure = (60000 / bpm) / 4.<br/>
 * BPM 128 -> 1 note = 117,18<br/>
 * BPM 255 -> 1 note = 58,82<br/>
 */

#ifndef _PLAYER_H_
#define	_PLAYER_H_

#include "data.h"
#include "soundApi/soundApi.h"


/** \brief Définition d'une valeur pour ralentir le décompte du tempo. */
#define TEMPO_TIMER_HARDWARE_VALUE 70

/*
 * Toutes ces variables sont des repères pour le player. Afin de savoir quelle séquence/block/note jouer.
 * Attention. Les valeurs dans les tableaux représentent des NUMEROS DE LIGNES. 
 * Ce ne sont pas les ids des séquences/blocks/notes. 
 * Les 3 autres variables représentent, elles, des ids d'objets.
 */
/** \brief Repères pour le player: les valeurs dans les tableaux représentent des numéros de lignes (séquences). */
u8 actualSequencesForChannel[6];
/** \brief Repères pour le player: les valeurs dans les tableaux représentent des numéros de lignes (blocks). */
u8 actualBlocksForChannel[6];
/** \brief Repères pour le player: les valeurs dans les tableaux représentent des numéros de lignes (notes). */
u8 actualNotesForChannel[6];
/** \brief Id de la séquence en cours de lecture. */
u8 FAT_currentPlayedSequence = NULL_VALUE;
/** \brief Numéro du channel en cours de lecture. */
u8 FAT_currentPlayedChannel = NULL_VALUE;
/** \brief Id du block en cours de lecture. */
u8 FAT_currentPlayedBlock = NULL_VALUE;

bufferPlayer FAT_player_buffer[6];
u8 firstAvailableSequenceForChannel[6];

/** \brief Objet HAM pour référencer le sprite "curseur player" de taille 2. */
THandle FAT_cursor_player3_obj;
/** \brief Objet HAM pour référencer le sprite "curseur player" de taille 3. */
THandle FAT_cursor_player2_obj;
/** \brief Objet HAM pour référencer les sprites "curseur player" utilisés dans l'écran SONG. */
THandle FAT_cursor_playerSequences_obj[6];
/** \brief Les curseurs d'attente indiquant que le channel a été activé mais en attente de synchro avant de se lancer */
THandle FAT_cursor_playerLiveWait_obj[6];

/**
 * \brief Compteur pour le tempo.
 * 
 * Lorsque cette variable atteint une valeur donné, alors la lecture de la note suivante est demandée. Le compteur
 * est réinitialisé ensuite.
 * Dans le cas contraire, on attend sans jouer de note.
 */
u32 tempoReach = (60000 / 128) * 4;

u8 FAT_player_isPlayingFrom;

u8 FAT_live_waitForOtherChannel[6];

/**
 * \brief Function temporisée qui lit toutes les séquences. (callback)
 */
void FAT_player_playFromSequences();
/**
 * \brief Fonction temporisée qui lit tous les blocks d'une séquence. (callback)
 */
void FAT_player_playFromBlocks();
/**
 * \brief Fonction temporisée qui lit toutes les notes d'un block. (callback)
 */
void FAT_player_playFromNotes();

void FAT_player_live_showOrHideCursorWait(u8 channel);
void FAT_player_hideWaitCursors ();
void FAT_player_hideSequencesCursors();
void FAT_player_hideBlockCursor();
void FAT_player_hideNoteCursor();
void FAT_player_playNote(note* note, u8 channel);
void FAT_player_playNoteWithTsp(note* note, u8 channel, u8 transpose);
void FAT_player_playNoteWithTspAndVolume(note* note, u8 channel, u8 transpose, u8 volume);
void FAT_player_timerFunc();
void FAT_resetTempo ();

/**
 * \brief Initialisation du curseur player pour les notes.
 * 
 * S'occupe de créer les sprites et de les rendre invisibles. 
 */
void FAT_player_initCursors() {
    memset(actualSequencesForChannel, NULL_VALUE, sizeof (u8)*6);
    memset(actualBlocksForChannel, 0, sizeof (u8)*6);
    memset(actualNotesForChannel, 0, sizeof (u8)*6);
    memset(firstAvailableSequenceForChannel, 0, sizeof (u8)*6);
    memset(FAT_live_waitForOtherChannel, 0, sizeof (u8)*6);

    FAT_cursor_player3_obj = hel_ObjCreate(    ResData(RES_CURSOR3_PLAYER_RAW), // Pointer to source graphic
                                               OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                               2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                               OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                               COLORS_16,              // Use 16 color mode
                                               0,                      // Palette number. Only neccessary in 16 color mode
                                               FALSE,                  // Don't use mosaic
                                               FALSE,                  // Don't flip the sprite horizontally
                                               FALSE,                  // Don't flip the object vertically
                                               3,                      // Priority against background. 0=higest
                                               FALSE,                  // Don't make the object double-sized
                                               0,                    // Destination horzintal screen coordinate in pixels
                                               0                      // Destination vertical screen coordinate in pixels
                                               );

    FAT_cursor_player2_obj = hel_ObjCreate(    ResData(RES_CURSOR2_PLAYER_RAW), // Pointer to source graphic
                                               OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                               2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                               OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                               COLORS_16,              // Use 16 color mode
                                               0,                      // Palette number. Only neccessary in 16 color mode
                                               FALSE,                  // Don't use mosaic
                                               FALSE,                  // Don't flip the sprite horizontally
                                               FALSE,                  // Don't flip the object vertically
                                               3,                      // Priority against background. 0=higest
                                               FALSE,                  // Don't make the object double-sized
                                               0,                    // Destination horzintal screen coordinate in pixels
                                               0                      // Destination vertical screen coordinate in pixels
                                               );

    FAT_cursor_playerLiveWait_obj[0] =  hel_ObjCreate( ResData(RES_CURSOR2_PLAYER_WAITING_RAW), // Pointer to source graphic
                                                       OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                       2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                       OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                                       COLORS_16,              // Use 16 color mode
                                                       0,                      // Palette number. Only neccessary in 16 color mode
                                                       FALSE,                  // Don't use mosaic
                                                       FALSE,                  // Don't flip the sprite horizontally
                                                       FALSE,                  // Don't flip the object vertically
                                                       3,                      // Priority against background. 0=higest
                                                       FALSE,                  // Don't make the object double-sized
                                                       0,                    // Destination horzintal screen coordinate in pixels
                                                       0                      // Destination vertical screen coordinate in pixels
                                                       );

    hel_ObjSetVisible(FAT_cursor_player3_obj, 0);
    hel_ObjSetVisible(FAT_cursor_player2_obj, 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[0], 0);

    // on clone les sprites pour la lecture des 6 séquences à la fois
    u8 i;
    for (i = 0; i < 6; i++) {
        FAT_cursor_playerSequences_obj[i] = hel_ObjClone(FAT_cursor_player2_obj, 0, 0);
        hel_ObjSetPrio(FAT_cursor_playerSequences_obj[i], 3);
    }

    for (i = 1; i < 6; i++) {
        FAT_cursor_playerLiveWait_obj[i] = hel_ObjClone(FAT_cursor_playerLiveWait_obj[0], 0, 0);
        hel_ObjSetPrio(FAT_cursor_playerLiveWait_obj[i], 3);
    }
}

/**
 * \brief Joue une note écrite dans le composer.
 * 
 * @param noteLine le numéro de ligne de la note dans le composer
 */
void FAT_player_playComposerNote(u8 noteLine) {
    note* note = &(FAT_tracker.composer.notes[noteLine]);

    if (note->freq != NULL_VALUE) {
        FAT_player_playNoteWithTsp(note, FAT_tracker.composer.channels[noteLine],
                FAT_tracker.composer.transpose);
    }
}

/**
 * \brief Joue une note sur un channel.
 * 
 * Cette méthode est un wrapper pour la méthode FAT_player_playNoteWithTsp.
 * Seule la valeur de transpose du projet est utilisée.
 * 
 * @param note l'objet NOTE à jouer
 * @param channel le channel sur lequel jouer la note
 */
void FAT_player_playNote(note* note, u8 channel) {
    FAT_player_playNoteWithTsp(note, channel, FAT_tracker.transpose);
}

void FAT_player_playNoteWithTsp(note* note, u8 channel, u8 transpose){
    FAT_player_playNoteWithTspAndVolume(note, channel, transpose, 0xff);
}

/**
 * \brief Joue une note sur un channel en ajoutant un transpose.
 * 
 * @param note l'objet NOTE à jouer
 * @param channel le numéro de channel sur lequel jouer la note
 * @param transpose la valeur de transpose, elle sera ajoutée à celle du projet
 */
void FAT_player_playNoteWithTspAndVolume(note* note, u8 channel, u8 transpose, u8 volume) {
    if (note->freq != NULL_VALUE) {

        instrument* inst = &(FAT_tracker.allInstruments[note->instrument]);
        if (channel != 4 && channel != 5) {

            u16 sweepshifts = (inst->sweep & 0x70) >> 4;
            u16 sweeptime = (inst->sweep & 0x0F);
            u16 sweepdir = 1;
            if (sweeptime > 7) {
                sweeptime -= 8;
                sweepdir = 0;
            }

            volume = (volume > 0xf) ? 0xff : volume;
            switch (channel) {
                case 0: // PU1
                    snd_playSoundOnChannel1(
                            sweeptime, sweepdir, sweepshifts,
                            volume != 0xff ? volume : inst->envelope & 0x0f, (inst->envelope & 0x10) >> 4, (inst->envelope & 0xe0) >> 5, inst->wavedutyOrPolynomialStep,
                            inst->soundlength, inst->loopmode,
                            inst->output,
                            note->freq, transpose + FAT_tracker.transpose);
                    break;
                case 1: // PU2
                    snd_playSoundOnChannel2(
                            volume != 0xff ? volume : inst->envelope & 0x0f, (inst->envelope & 0x10) >> 4, (inst->envelope & 0xe0) >> 5,
                            inst->wavedutyOrPolynomialStep,
                            inst->soundlength, inst->loopmode,
                            inst->output,
                            note->freq, transpose + FAT_tracker.transpose);
                    break;

                case 2: // WAV
                    volume = (volume > 0x4) ? 0xff : volume;
                    snd_playSoundOnChannel3(volume != 0xff ? volume : inst->volumeRatio & 0x0f, inst->soundlength, inst->loopmode, inst->voiceAndBank & 0x1f,
                            (inst->voiceAndBank & 0x20) >> 5, (inst->voiceAndBank & 0x40) >> 6,
                            inst->output, note->freq, transpose + FAT_tracker.transpose);
                    break;
                case 3: // NOISE
                    snd_playSoundOnChannel4(volume != 0xff ? volume : inst->envelope & 0x0f, (inst->envelope & 0x10) >> 4, (inst->envelope & 0xe0) >> 5, inst->soundlength,
                            inst->loopmode, inst->output, note->note & 0x0f, inst->wavedutyOrPolynomialStep,
                            note->freq / NB_FREQUENCES, transpose + FAT_tracker.transpose);
                    break;
            }

        } else {
            if (channel == 4) {
                //snd_playSampleOnChannelAById(inst->kitNumber, note->freq);
                snd_playChannelASample(inst->kitNumber, note->freq, inst->volumeRatio >> 4,
                        inst->speedOrLooping & 0x0f, inst->speedOrLooping >> 4,
                        (inst->envelope & 0xe0) >> 5, inst->soundlength, inst->offset);
            } else if (channel == 5) {
                //snd_playSampleOnChannelBById(inst->kitNumber, note->freq);
                snd_playChannelBSample(inst->kitNumber, note->freq, inst->volumeRatio >> 4,
                        inst->speedOrLooping & 0x0f, inst->speedOrLooping >> 4,
                        (inst->envelope & 0xe0) >> 5, inst->soundlength, inst->offset);
            }

        }
    }

    if (note->effect.name != NULL_VALUE) {
        snd_tryToApplyEffect(channel, noteEffectNum[note->effect.name >> 1], note->effect.value);
    }
}

u8 FAT_player_searchFirstAvailableSequenceForChannel_returnLine (u8 channel, u8 startingLine){
    s8 i = startingLine;
    u8 firstLine = NULL_VALUE;

    // 1. je cherche en partant de la ligne courante.
    while (i < NB_SEQUENCES_IN_ONE_CHANNEL){
        if (FAT_tracker.channels[channel].sequences[i] != NULL_VALUE){
            firstLine = i; // j'ai trouvé un bloc valide !
            break;
        }
        i++;
    }

    // 2. si je n'ai pas trouvé, je cherche en partant de 0
    if (firstLine == NULL_VALUE){
        i = 0;
        while (i < startingLine){
            if (FAT_tracker.channels[channel].sequences[i] != NULL_VALUE){
                firstLine = i;
                break;
            }
            i++;
        }
    }

    // 3. si j'ai trouvé un bloc valide, on s'assure qu'il s'agit bien du premier
    if (firstLine != NULL_VALUE){
        i = firstLine;
        while (i >= 0){
            if (FAT_tracker.channels[channel].sequences[i] == NULL_VALUE){
                break;
            }
            firstLine = i;
            i--;
        }
    }

    return firstLine;
}

/**
 * \brief Lance la lecture de toute la track.
 */
void FAT_player_startPlayerFromSequences(u8 startLine) {

    // initialisation des séquences au démarrage
    memset(actualBlocksForChannel, 0, sizeof (u8)*6);
    memset(actualNotesForChannel, 0, sizeof (u8)*6);
    memset(firstAvailableSequenceForChannel, 0, sizeof (u8)*6);

    // détermine pour chaque channel, quelle est la premiere sequence jouable.
    u8 i;
    for (i = 0; i<6; i++){
        firstAvailableSequenceForChannel[i] = FAT_player_searchFirstAvailableSequenceForChannel_returnLine(i, startLine);
    }
    memcpy(actualSequencesForChannel, firstAvailableSequenceForChannel, sizeof (u8)*6);

    FAT_resetTempo ();
    FAT_isCurrentlyPlaying = 1;
    FAT_live_nbChannelPlaying = 6; // pour passage dans l'écran LIVE.
    FAT_player_isPlayingFrom = SCREEN_SONG_ID;

    for (i = 0;i<6;i++){
        FAT_player_moveOrHideCursor(i);
    }

    R_TIM3COUNT = 0xffff;
    R_TIM3CNT = 0x00C3;
    hel_IntrStartHandler(INT_TYPE_TIM3, (void*) &FAT_player_timerFunc);
}

void FAT_player_startPlayerFromLive_oneChannel(u8 line, u8 channel){
    // initialisation seulement si d'autres colonnes n'ont pas déjà été lancées !
    if (!FAT_isCurrentlyPlaying){
        memset(actualSequencesForChannel, NULL_VALUE, sizeof (u8)*6);
        memset(actualBlocksForChannel, 0, sizeof (u8)*6);
        memset(actualNotesForChannel, 0, sizeof (u8)*6);
        memset(firstAvailableSequenceForChannel, 0, sizeof (u8)*6);

        // les autres channels vont devoir attendre celui la !
        memset (FAT_live_waitForOtherChannel, 1, sizeof(u8)*6);
        FAT_live_waitForOtherChannel[channel] = 0;

        FAT_resetTempo ();

        FAT_isCurrentlyPlaying = 1;
        FAT_live_nbChannelPlaying = 0;
        FAT_player_isPlayingFrom = SCREEN_LIVE_ID;
    }

    // positionnement du player sur le channel
    firstAvailableSequenceForChannel[channel] = FAT_player_searchFirstAvailableSequenceForChannel_returnLine(channel, line);
    actualSequencesForChannel[channel] = firstAvailableSequenceForChannel[channel];
    actualBlocksForChannel[channel] = 0;
    actualNotesForChannel[channel] = 0;
    FAT_live_nbChannelPlaying ++;

    if (FAT_live_waitForOtherChannel[channel] == 0){
        FAT_player_moveOrHideCursor(channel);

        R_TIM3COUNT = 0xffff;
        R_TIM3CNT = 0x00C3;
        hel_IntrStartHandler(INT_TYPE_TIM3, (void*) &FAT_player_timerFunc);
    }
}

/**
 * \brief Démarrer la lecture d'une séquence (lit tous les blocks de la séquence).
 * 
 * @param sequenceId l'id de la séquence à jouer
 * @param startLine le numéro de ligne de départ
 * @param channel le numéro de channel sur lequel on joue
 */
void FAT_player_startPlayerFromBlocks(u8 sequenceId, u8 startLine, u8 channel) {

    // initialisation 
    memset(actualSequencesForChannel, NULL_VALUE, sizeof (u8)*6);
    memset(actualBlocksForChannel, 0, sizeof (u8)*6);
    memset(actualNotesForChannel, 0, sizeof (u8)*6);
    actualBlocksForChannel[channel] = startLine;
    FAT_currentPlayedSequence = sequenceId;
    FAT_currentPlayedChannel = channel;

    FAT_resetTempo (); //- TEMPO_TIMER_HARDWARE_VALUE;
    FAT_isCurrentlyPlaying = 1;
    FAT_player_isPlayingFrom = SCREEN_BLOCKS_ID;

    R_TIM3COUNT = 0xffff;
    R_TIM3CNT = 0x00C3;
    hel_IntrStartHandler(INT_TYPE_TIM3, (void*) &FAT_player_timerFunc);

}

/**
 * \brief Démarre la lecture d'un block entier.
 *  
 * @param blockId l'id du block à jouer
 * @param startLine la ligne de départ (TODO retirer ce paramètre on devrait jouer depuis 0 tous le temps)
 * @param channel le numéro de channel sur lequel on joue
 */
void FAT_player_startPlayerFromNotes(u8 blockId, u8 startLine, u8 channel) {

    memset(actualSequencesForChannel, NULL_VALUE, sizeof (u8)*6);
    memset(actualBlocksForChannel, NULL_VALUE, sizeof (u8)*6);
    memset(actualNotesForChannel, 0, sizeof (u8)*6);
    actualNotesForChannel[channel] = startLine;
    FAT_currentPlayedBlock = blockId;
    FAT_currentPlayedChannel = channel;

    FAT_resetTempo (); //- TEMPO_TIMER_HARDWARE_VALUE;
    FAT_isCurrentlyPlaying = 1;
    FAT_player_isPlayingFrom = SCREEN_NOTES_ID;

    R_TIM3COUNT = 0xffff;
    R_TIM3CNT = 0x00C3;
    hel_IntrStartHandler(INT_TYPE_TIM3, (void*) &FAT_player_timerFunc);

}

void FAT_player_timerFunc() {
    if (tempoReach > 0) {
        tempoReach--;
    }
    hel_IntrAcknowledge(INT_TYPE_TIM3);
}

// DEJA DOCUMENTEE

void FAT_player_playFromSequences() {
    if (tempoReach <= 0) {

        u8 i;
        for (i = 0; i < 6; i++) {
            FAT_player_buffer[i].haveToPlay = 0;
            if (FAT_isChannelCurrentlyPlaying(i)){
                FAT_currentPlayedSequence = FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]];
                if (FAT_currentPlayedSequence != NULL_VALUE) {
                    // lire la séquence actuelle
                    sequence* seq = &FAT_tracker.allSequences[FAT_currentPlayedSequence];

                    FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[i]];
                    if (FAT_currentPlayedBlock != NULL_VALUE) {
                        block* block = &FAT_tracker.allBlocks[FAT_currentPlayedBlock];

                        // TODO un effet à appliquer sur la note ?
                        FAT_player_buffer[i].note = &(block->notes[actualNotesForChannel[i]]);
                        FAT_player_buffer[i].transpose =  seq->transpose[actualBlocksForChannel[i]];
                        FAT_player_buffer[i].haveToPlay = 1;

                        actualNotesForChannel[i]++;
                        if (actualNotesForChannel[i] >= NB_NOTES_IN_ONE_BLOCK) {
                            actualNotesForChannel[i] = 0;
                            actualBlocksForChannel[i]++;
                            if (actualBlocksForChannel[i] >= NB_BLOCKS_IN_SEQUENCE
                                    || seq->blocks[actualBlocksForChannel[i]] == NULL_VALUE) {
                                actualBlocksForChannel[i] = 0;
                                actualSequencesForChannel[i]++;
                                if (actualSequencesForChannel[i] > NB_MAX_SEQUENCES
                                        || FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]] == NULL_VALUE
                                        || FAT_data_isSequenceEmpty(FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]])) {

                                    actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];

                                }
                            }
                            // Déplacement des curseurs de lecture
                            FAT_player_moveOrHideCursor(i);//, &(block->notes[actualNotesForChannel[i]]));
                        }
                    } else {
                        actualBlocksForChannel[i] = 0;
                        actualSequencesForChannel[i]++;
                        if (actualSequencesForChannel[i] > NB_MAX_SEQUENCES) {
                            actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                        }
                        FAT_player_moveOrHideCursor(i);
                    }

                } else {
                    actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                    FAT_player_moveOrHideCursor(i);
                }
            }

        }

        for (i = 0; i < 6; i++) {
            if (FAT_player_buffer[i].haveToPlay){
                FAT_player_playNoteWithTsp(
                   FAT_player_buffer[i].note , i, FAT_player_buffer[i].transpose);
                /*FAT_screenSong_showActualPlayedNote(i,
                                                    (FAT_player_buffer[i].note->note & 0xf0) >> 4,
                                                    FAT_player_buffer[i].note->note & 0x0f,
                                                    FAT_player_buffer[i].note->freq);*/
            }
        }

        FAT_resetTempo ();
    }
}

void FAT_player_liveSynchro(){
    u8 j;
    for (j=0;j<6;j++){
        if(FAT_isChannelCurrentlyPlaying(j)){
            FAT_live_waitForOtherChannel[j] = 0;
            FAT_player_moveOrHideCursor(j);
        }
    }
}

void FAT_player_playFromLive(){
    if (tempoReach <= 0) {

        bool willHaveToSyncAfterNote = 0;
        u8 i;
        for (i = 0; i < 6; i++) {
            FAT_player_buffer[i].haveToPlay = 0;
            if (FAT_isChannelCurrentlyPlaying(i) && FAT_live_waitForOtherChannel[i] == 0){

                FAT_currentPlayedSequence = FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]];

                if (FAT_currentPlayedSequence != NULL_VALUE) {
                    // lire la séquence actuelle
                    sequence* seq = &FAT_tracker.allSequences[FAT_currentPlayedSequence];

                    FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[i]];
                    if (FAT_currentPlayedBlock != NULL_VALUE) {
                        block* block = &FAT_tracker.allBlocks[FAT_currentPlayedBlock];

                        // TODO un effet à appliquer sur la note ?
                        FAT_player_buffer[i].note = &(block->notes[actualNotesForChannel[i]]);
                        FAT_player_buffer[i].transpose =  seq->transpose[actualBlocksForChannel[i]];
                        FAT_player_buffer[i].haveToPlay = 1;

                        actualNotesForChannel[i]++;
                        if (actualNotesForChannel[i] >= NB_NOTES_IN_ONE_BLOCK) {
                            actualNotesForChannel[i] = 0;
                            actualBlocksForChannel[i]++;
                            if (actualBlocksForChannel[i] >= NB_BLOCKS_IN_SEQUENCE
                                    || seq->blocks[actualBlocksForChannel[i]] == NULL_VALUE) {
                                actualBlocksForChannel[i] = 0;

                                if (!FAT_tracker.liveData.liveMode){ // mode auto?
                                    actualSequencesForChannel[i]++;
                                    if (actualSequencesForChannel[i] > NB_MAX_SEQUENCES
                                            || FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]] == NULL_VALUE
                                            || FAT_data_isSequenceEmpty(FAT_tracker.channels[i].sequences[actualSequencesForChannel[i]])) {

                                        actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                                        // si pas de séquences dispo -> NULL_VALUE
                                    }
                                }
                                willHaveToSyncAfterNote = 1;
                                // Déplacement des curseurs de lecture
                                FAT_player_moveOrHideCursor(i);
                            }
                        }
                    } else {
                        actualBlocksForChannel[i] = 0;

                        if (!FAT_tracker.liveData.liveMode){ // mode auto?
                            actualSequencesForChannel[i]++;
                            if (actualSequencesForChannel[i] > NB_MAX_SEQUENCES) {
                                actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                            }
                            FAT_player_moveOrHideCursor(i);
                        }

                        willHaveToSyncAfterNote = 1;
                    }

                } else if (!FAT_tracker.liveData.liveMode){ // mode auto?
                    actualSequencesForChannel[i] = firstAvailableSequenceForChannel[i];
                    willHaveToSyncAfterNote = 1;
                    FAT_player_moveOrHideCursor(i);
                }
            }

            FAT_player_live_showOrHideCursorWait (i);

        }

        for (i = 0; i < 6; i++) {
            if (FAT_player_buffer[i].haveToPlay){
                FAT_player_playNoteWithTspAndVolume(
                   FAT_player_buffer[i].note , i,
                   FAT_player_buffer[i].transpose + FAT_tracker.liveData.transpose[i],
                   FAT_tracker.liveData.volume[i]);

                //snd_effect_volume(i, FAT_tracker.liveData.volume[i]);
            }
        }

        if (willHaveToSyncAfterNote){
            FAT_player_liveSynchro();
        }

        FAT_resetTempo ();
    }
}

// DEJA DOCUMENTEE

void FAT_player_playFromBlocks() {

    if (tempoReach <= 0) {
        if (FAT_currentPlayedSequence != NULL_VALUE) {
            // lire la séquence actuelle
            sequence* seq = &FAT_tracker.allSequences[FAT_currentPlayedSequence];

            FAT_currentPlayedBlock = seq->blocks[actualBlocksForChannel[FAT_currentPlayedChannel]];
            if (FAT_currentPlayedBlock != NULL_VALUE) {
                block* block = &FAT_tracker.allBlocks[FAT_currentPlayedBlock];

                // Déplacement des curseurs de lecture
                FAT_player_moveOrHideCursor(FAT_currentPlayedChannel);//, &(block->notes[actualNotesForChannel[FAT_currentPlayedChannel]]));

                // TODO BUFFERISER
                // TODO un effet à appliquer sur la note ?
                FAT_player_playNoteWithTsp(&(block->notes[actualNotesForChannel[FAT_currentPlayedChannel]]), FAT_currentPlayedChannel,
                        seq->transpose[actualBlocksForChannel[FAT_currentPlayedChannel]]);

                actualNotesForChannel[FAT_currentPlayedChannel]++;
                if (actualNotesForChannel[FAT_currentPlayedChannel] >= NB_NOTES_IN_ONE_BLOCK) {
                    actualNotesForChannel[FAT_currentPlayedChannel] = 0;
                    actualBlocksForChannel[FAT_currentPlayedChannel]++;
                    if (actualBlocksForChannel[FAT_currentPlayedChannel] >= NB_BLOCKS_IN_SEQUENCE
                            || seq->blocks[actualBlocksForChannel[FAT_currentPlayedChannel]] == NULL_VALUE) {
                        actualBlocksForChannel[FAT_currentPlayedChannel] = 0;
                    }
                }
            } else {
                actualBlocksForChannel[FAT_currentPlayedChannel] = 0;
            }

        }

        FAT_resetTempo ();
    }

}



// DEJA DOCUMENTEE

void FAT_player_playFromNotes() {
    if (tempoReach <= 0) {
        if (FAT_currentPlayedBlock != NULL_VALUE) {
            block* block = &FAT_tracker.allBlocks[FAT_currentPlayedBlock];

            // Déplacement des curseurs de lecture
            FAT_player_moveOrHideCursor(FAT_currentPlayedChannel);//, &(block->notes[actualNotesForChannel[FAT_currentPlayedChannel]]));

            // TODO BUFFERISER
            // TODO un effet à appliquer sur la note ?
            FAT_player_playNote(&(block->notes[actualNotesForChannel[FAT_currentPlayedChannel]]),
                    FAT_currentPlayedChannel);

            actualNotesForChannel[FAT_currentPlayedChannel]++;
            if (actualNotesForChannel[FAT_currentPlayedChannel] >= NB_NOTES_IN_ONE_BLOCK) {
                actualNotesForChannel[FAT_currentPlayedChannel] = 0;
            }
        }

        FAT_resetTempo ();

    }

}

void FAT_player_continueToPlay() {
    switch (FAT_player_isPlayingFrom) {
        case SCREEN_SONG_ID:
            FAT_player_playFromSequences();
            break;
        case SCREEN_LIVE_ID:
            FAT_player_playFromLive();
            break;
        case SCREEN_BLOCKS_ID:
            FAT_player_playFromBlocks();
            break;
        case SCREEN_NOTES_ID:
            FAT_player_playFromNotes();
            break;
    }
}

/**
 * \brief Arrete la lecture d'un channel. Si c'est le dernier, stop le player completement.
 */
void FAT_player_stopPlayer_onlyOneColumn(u8 channel){
    actualSequencesForChannel[channel] = NULL_VALUE;
    actualBlocksForChannel[channel] = 0;
    actualNotesForChannel[channel] = 0;
    firstAvailableSequenceForChannel[channel] = 0;
    FAT_live_waitForOtherChannel[channel] = 1;

    FAT_live_nbChannelPlaying --;

    // TODO et si un channel attend ?
    if (FAT_live_nbChannelPlaying == 0){
        FAT_player_stopPlayer();
    } else {
        snd_effect_kill (channel, 0x00);
        hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
    }
}

bool FAT_isChannelCurrentlyPlaying (u8 channel){
    return actualSequencesForChannel[channel] != NULL_VALUE;
}

/**
 * \brief Arrète la lecture de la track.
 */
void FAT_player_stopPlayer() {

    hel_IntrStopHandler(INT_TYPE_TIM3);

    // stop le son
    snd_stopAllSounds();

    // cache tous les curseurs de lecture
    FAT_player_hideAllCursors();

    // la lecture est terminée.
    FAT_isCurrentlyPlaying = 0;
    FAT_player_isPlayingFrom = 0;

    // réinit propre.
    memset(actualSequencesForChannel, NULL_VALUE, sizeof (u8)*6);
    memset (FAT_live_waitForOtherChannel, 0, sizeof(u8)*6);
}

/**
 * \brief Cache tous les curseurs utilisés lors de la lecture. 
 */
void FAT_player_hideAllCursors() {
    FAT_player_hideNoteCursor();
    FAT_player_hideBlockCursor();
    FAT_player_hideWaitCursors ();
    FAT_player_hideSequencesCursors();
}

/**
 * \brief Cache les curseurs utilisés lors de la lecture dans l'écran SONG. 
 */
void FAT_player_hideSequencesCursors() {
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[0], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[1], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[2], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[3], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[4], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[5], 0);
}

void FAT_player_hideWaitCursors (){
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[0], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[1], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[2], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[3], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[4], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[5], 0);
}

/**
 * \brief Cache les curseurs utilisés lors de la lecture dans l'écran BLOCK. 
 */
void FAT_player_hideBlockCursor() {
    hel_ObjSetVisible(FAT_cursor_player2_obj, 0);
}

/**
 * \brief Cache les curseurs utilisés lors de la lecture dans l'écran NOTE. 
 */
void FAT_player_hideNoteCursor() {
    hel_ObjSetVisible(FAT_cursor_player3_obj, 0);
}


void FAT_player_live_showOrHideCursorWait(u8 channel){
    if (FAT_currentScreen == SCREEN_LIVE_ID){
        if (FAT_isChannelCurrentlyPlaying(channel)
            && actualSequencesForChannel[channel] >= FAT_screenLive_currentStartLine && !isHelpActivated
            && FAT_live_waitForOtherChannel[channel] == 1){
            // affichage
            u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);
            if (yPosition < 140){
                hel_ObjSetXY(FAT_cursor_playerLiveWait_obj[channel],
                        23 + (channel * (8 + 16)),
                        yPosition);
                hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[channel], 1);
            } else {
                hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[channel], 0);
            }
        } else {
            hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[channel], 0);
        }

    }
}

/**
 * \brief Déplace ou cache les curseurs de lecture en fonction de l'état du player.
 * 
 * @param channel le numéro de channel sur lequel on joue du son
 */
void FAT_player_moveOrHideCursor(u8 channel) {

    switch (FAT_currentScreen) {
        case SCREEN_SONG_ID: // on est dans l'écran SONG !
            FAT_player_hideBlockCursor();
            FAT_player_hideNoteCursor();
            if (actualSequencesForChannel[channel] != NULL_VALUE
                    && actualSequencesForChannel[channel] >= FAT_screenSong_currentStartLine && !isHelpActivated) {
                // la lecture a été lancée depuis l'écran SONG
                // on dispose du numéro de ligne actuellement jouée dans actualSequencesForChannel[channel]
                u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);
                if (yPosition < 140){
                    hel_ObjSetXY(FAT_cursor_playerSequences_obj[channel],
                            23 + (channel * (8 + 16)),
                            yPosition);
                    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 1);
                } else {
                    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
                }

                /*if (note->freq != NULL_VALUE) {
                    FAT_screenSong_showActualPlayedNote(channel, (note->note & 0xf0) >> 4, note->note & 0x0f, note->freq);
                }*/

            } else {
                hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
            }


            break;
        case SCREEN_LIVE_ID:
            // TODO duplication moche.
            FAT_player_hideBlockCursor();
            FAT_player_hideNoteCursor();
            if (actualSequencesForChannel[channel] != NULL_VALUE
                    && actualSequencesForChannel[channel] >= FAT_screenLive_currentStartLine && !isHelpActivated) {
                // la lecture a été lancée depuis l'écran SONG
                // on dispose du numéro de ligne actuellement jouée dans actualSequencesForChannel[channel]
                u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);

                if (yPosition < 90){
                    hel_ObjSetXY(FAT_cursor_playerSequences_obj[channel],
                            23 + (channel * (8 + 16)),
                            15 + ((actualSequencesForChannel[channel] - FAT_screenLive_currentStartLine)*8));

                    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 1);
                } else {
                    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
                }

                /*if (note->freq != NULL_VALUE) {
                    // la meme chose que pour SONG. On peut laisser comme ça.
                    FAT_screenSong_showActualPlayedNote(channel, (note->note & 0xf0) >> 4, note->note & 0x0f, note->freq);
                }*/

            } else {
                hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
            }
            break;
        case SCREEN_BLOCKS_ID: // on est dans l'écran BLOCKS
            FAT_player_hideSequencesCursors();
            FAT_player_hideNoteCursor();
            if (actualBlocksForChannel[channel] != NULL_VALUE &&
                    FAT_currentPlayedSequence == FAT_screenBlocks_currentSequenceId && !isHelpActivated) {
                hel_ObjSetXY(FAT_cursor_player2_obj, 23, 15 + (actualBlocksForChannel[channel]*8));
                hel_ObjSetVisible(FAT_cursor_player2_obj, 1);
            } else {
                FAT_player_hideBlockCursor();
            }

            break;
        case SCREEN_NOTES_ID: // on est dans l'écran NOTES
            FAT_player_hideSequencesCursors();
            FAT_player_hideBlockCursor();
            if (actualNotesForChannel[channel] != NULL_VALUE
                    && FAT_currentPlayedBlock == FAT_screenNotes_currentBlockId && !isHelpActivated) {
                hel_ObjSetXY(FAT_cursor_player3_obj, 23, 15 + (actualNotesForChannel[channel]*8));
                hel_ObjSetVisible(FAT_cursor_player3_obj, 1);
            } else {
                FAT_player_hideNoteCursor();
            }
            break;
        default: // on cache tous les curseurs de lecture
            FAT_player_hideAllCursors();
            break;
    }

}

void FAT_resetTempo (){
    tempoReach = (60000 / FAT_tracker.tempo) * 4; // timer trop rapide. Pour le moment je laisse comme ça, ça fonctionne.
}

#endif	/* PLAYER_H */

