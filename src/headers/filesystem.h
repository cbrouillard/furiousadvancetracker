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
 * \file filesystem.h
 * \brief Ce fichier contient toutes les fonctions utiles pour la gestion des sauvgardes et chargement.
 */

#ifndef _FILESYSTEM_H_
#define	_FILESYSTEM_H_

#include "../soundApi/soundApi.h"
#include "../headers/data.h"

/**
 * \brief Addresse vers la mémoire SRAM (la mémoire pour la sauvegarde).
 */
#define GAMEPAK_RAM  ((u8*)0x0E000000)

/** \brief Nombre maximal de tracks enregistrable. */
#define MAX_TRACKS 16

#define DEFAULT_FIRST_DATA_OFFSET (MAX_TRACKS*4)+16

/** \brief Chaine de caractère pour les chansons non initialisées. */
const char* emptyName = "EMPTY   ";

void FAT_filesystem_checkFs();
char* FAT_filesystem_getTrackName(u8 trackNumber);
u8 FAT_filesystem_getTrackNbWork(u8 trackNumber);
u16 FAT_filesystem_findFirstFreeOffset();
void FAT_filesystem_setFirstFreeOffsetValue(u16 value);
u16 FAT_filesystem_hasJumpToApply (u16 offset, bool saveMode);
void FAT_filesystem_saveTrack(u8 trackNumber);
void FAT_filesystem_loadTrack(u8 trackNumber);
void FAT_filesystem_setTrackOffset(u8 trackNumber, u16 offset);
u16 FAT_filesystem_getTrackOffset(u8 trackNumber);
void FAT_filesystem_setTrackSize(u8 trackNumber, u16 size);
u16 FAT_filesystem_getTrackSize(u8 trackNumber);
char* FAT_filesystem_getSongNameBuffer ();

#endif	/* FILESYSTEM_H */
