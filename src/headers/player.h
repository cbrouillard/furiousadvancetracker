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

 * DOC: Délai pour 1/16e de mesure = (60000 / bpm) * 4.<br/>
 * BPM 128 -> 1 note = 117,18<br/>
 * BPM 255 -> 1 note = 58,82<br/>
 */

#ifndef _PLAYER_H_
#define	_PLAYER_H_

#include "../soundApi/soundApi.h"
#include "data.h"
#include "player_cursors.h"

void FAT_player_firstInit ();
void FAT_player_playComposerNote(u8 noteLine);
u8 FAT_player_searchFirstAvailableSequenceForChannel_returnLine (u8 channel, u8 startingLine);

void FAT_player_playFromSequences();
void FAT_player_playFromBlocks();
void FAT_player_playFromNotes();
void FAT_player_playFromLive();
void FAT_player_startPlayerFromLive_oneChannel(u8 line, u8 channel);
void FAT_player_continueToPlay();

bool FAT_isChannelCurrentlyPlaying (u8 channel);

void FAT_player_stopPlayer_onlyOneColumn(u8 channel);
void FAT_player_stopPlayer();

void FAT_player_playNote(note* note, u8 channel, u8 forceVolume);
void FAT_player_playNoteWithCustomParams(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);

/** POINTEURISEES **/
void FAT_player_playNoteWithCustomParams_chan1(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan2(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan3(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan4(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan5(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
void FAT_player_playNoteWithCustomParams_chan6(note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
// pointeurs (cf player.c)
   // void (*FAT_player_playNoteWithCustomParams_chanX[6]) (note* note, u8 channel, u8 transpose, u8 volume, u8 sweep, u8 output);
/**/

void FAT_player_timerFunc();
void FAT_resetTempo ();
void FAT_player_firstInit ();

void FAT_player_progressInSong(u8 channel, sequence* seq);
void FAT_player_progressInSequence (sequence* seq);
void FAT_player_progressInBlock ();
void FAT_player_liveSynchro();

u8 FAT_player_live_getWaitForOtherChannel (u8 n);
u8 FAT_player_getActualBlocksForChannel (u8 n);
u8 FAT_player_getActualNoteForChannel (u8 n);
u8 FAT_player_getCurrentPlayedSequence ();
u8 FAT_player_getCurrentPlayedBlock ();

#endif	/* PLAYER_H */
