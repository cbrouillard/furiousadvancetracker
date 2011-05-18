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

/**
 * \brief Addresse vers la mémoire SRAM (la mémoire pour la sauvegarde).
 */
#define GAMEPAK_RAM  ((u8*)0x0E000000)
/**
 * \brief Pointeur vers la mémoire SRAM.
 */
u8 *gamepak = GAMEPAK_RAM;

/**
 *  \brief La clé RLE (Run-Length Encoding) est une valeur d'octet traité spécialement 
 * par la système de sauvegarde. Elle sert à délimiter les mot de l'algorithme d'encoding.
 * En cas de présence dans les valeurs, alors on force l'encoding:
 * ex (bien qu'on n'obtienne pas de compression avec celui-ci):
 * RLE_KEY 0x05 0xFF RLE_KEY 0x01 RLE_KEY 0x45 0x76 0xFF RLE_KEY 0x02 0x01
 * donne
 * 0xFF 0xFF 0xFF 0xFF 0xFF 0x8A 0x45 0x76 0xFF 0x01 0x01
 */
#define RLE_KEY 0x8A

/** \brief Nombre maximal de tracks enregistrable. */
#define MAX_TRACKS 16
/** \brief Nombre maximal de tracks enregistrable sans compression. */
#define MAX_TRACKS_WITHOUT_COMPRESSION 3

void FAT_filesystem_checkFs ();
void FAT_filesystem_saveTrack (u8 trackNumber);
void FAT_filesystem_loadTrack (u8 trackNumber);
void FAT_filesystem_setTrackOffset (u8 trackNumber, u16 offset);
u16 FAT_filesystem_getTrackOffset (u8 trackNumber);
void FAT_filesystem_setTrackSize (u8 trackNumber, u16 size);
u16 FAT_filesystem_getTrackSize (u8 trackNumber);
void FAT_filesystem_saveRaw(u8 trackNumber);
void FAT_filesystem_loadRaw(u8 trackNumber);
u16 FAT_filesystem_findFirstFreeOffset ();

const char* emptyName = "EMPTY   ";
const char* noAvailable_tmp = "XXXXX   ";

/**
 * \brief Cette fonction vérifie l'intégrité du filesystem.
 */
void FAT_filesystem_checkFs (){
    u8 track = 0;
    u16 offset, size;
    while (track < MAX_TRACKS){
        offset = FAT_filesystem_getTrackOffset(track);
        size = FAT_filesystem_getTrackSize(track);
        
        if (offset == 0xFFFF && size == 0xFFFF){
            FAT_filesystem_setTrackOffset (track, (track*4));
        }
        
        track ++;
    }
}

char* FAT_filesystem_getTrackName (u8 trackNumber){
    if (trackNumber >= MAX_TRACKS_WITHOUT_COMPRESSION) {
        return (char*) noAvailable_tmp;
    }
    
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);
    
    if (offset == (trackNumber*4)) {
        return (char*) emptyName;
    }
    
    return & (gamepak [ offset ]);
}

/**
 * \brief Parcourt la table d'allocation des tracks et donne le premier offset physiquement
 * libre pour le stockage d'une track.
 */
u16 FAT_filesystem_findFirstFreeOffset (){
    return MAX_TRACKS * 4; // offset par défaut = fin de la table d'allocation
}

u16 FAT_filesystem_findRawTrackOffset (u8 trackNumber){
    return (MAX_TRACKS * 4) + (sizeof(FAT_tracker) * trackNumber);
}

void FAT_filesystem_saveTrack (u8 trackNumber){
    
}

void FAT_filesystem_loadTrack (u8 trackNumber){
    
}

void FAT_filesystem_setTrackOffset (u8 trackNumber, u16 offset){
    gamepak[ trackNumber * 4 ] = offset >> 8;
    gamepak[ (trackNumber * 4) + 1 ] = offset & 0x00ff;
}

u16 FAT_filesystem_getTrackOffset (u8 trackNumber){
    u16 firstPart = gamepak[ trackNumber * 4 ];
    u8 secondPart = gamepak[ (trackNumber * 4) + 1 ];
    
    return (firstPart << 8) | secondPart;
}

void FAT_filesystem_setTrackSize (u8 trackNumber, u16 size){
    gamepak[ (trackNumber * 4) + 2] =  size >> 8;
    gamepak[ (trackNumber * 4) + 3] = size & 0x00ff;
}

u16 FAT_filesystem_getTrackSize (u8 trackNumber){
    u16 firstPart = gamepak[ (trackNumber * 4) + 2];
    u8 secondPart = gamepak[ (trackNumber * 4) + 3];
    
    return (firstPart << 8) | secondPart;
}

u16 FAT_filesystem_getTrackSizeChecked (u8 trackNumber){
    if (trackNumber >= MAX_TRACKS_WITHOUT_COMPRESSION) {
        return 0;
    }
    
    u16 size = FAT_filesystem_getTrackSize(trackNumber);
    if (size == 0xFFFF){
        return 0;
    }
    
    return size;
}

/**
 * \brief Fonction de sauvegarde d'un track. Mode RAW. Pas de compression.
 * 
 */
void FAT_filesystem_saveRaw(u8 trackNumber) {
    mutex = 0;
    u8* tracker = (u8*) & FAT_tracker;
    
    //u32 trackSize = FAT_filesystem_getTrackSize(trackNumber);
    u32 trackSize = SIZEOF_8BIT(FAT_tracker);
    //FAT_filesystem_setTrackSize (trackNumber, size);
    
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);
    
    if (offset == (trackNumber * 4)) {
        // la track n'a jamais été initialisé. on cherche le prochain offset libre.
        //offset = FAT_filesystem_findFirstFreeOffset ();
        offset = FAT_filesystem_findRawTrackOffset (trackNumber);
        FAT_filesystem_setTrackOffset(trackNumber, offset);
    }
    
    int counter = 0;
    while (counter < trackSize) {
        gamepak[offset + counter] = tracker[counter];
        counter++;
    }
    
    FAT_filesystem_setTrackSize(trackNumber, trackSize);
    
    gamepak[offset + counter] = 0x5a;
    mutex = 1;
}

/**
 *  \brief Fonction de chargement d'une track. Mode RAW. Pas de compression.
 * 
 */
void FAT_filesystem_loadRaw(u8 trackNumber) {
    mutex = 0;
    u8* tracker = (u8*) & FAT_tracker;
    u32 trackSize = FAT_filesystem_getTrackSize(trackNumber);
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);
    int counter = 0;
    while (counter < trackSize) {
        tracker[counter] = gamepak[offset + counter];
        counter++;
    }
    mutex = 1;
}


#endif	/* FILESYSTEM_H */

