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

/** \brief Nombre maximal de tracks enregistrable. */
#define MAX_TRACKS 16
/** \brief Nombre maximal de tracks enregistrable sans compression. */
#define MAX_TRACKS_WITHOUT_COMPRESSION 3

void FAT_filesystem_checkFs();
void FAT_filesystem_saveTrack(u8 trackNumber);
void FAT_filesystem_loadTrack(u8 trackNumber);
void FAT_filesystem_setTrackOffset(u8 trackNumber, u16 offset);
u16 FAT_filesystem_getTrackOffset(u8 trackNumber);
void FAT_filesystem_setTrackSize(u8 trackNumber, u16 size);
u16 FAT_filesystem_getTrackSize(u8 trackNumber);
void old_FAT_filesystem_saveRaw(u8 trackNumber);
void FAT_filesystem_loadRaw(u8 trackNumber);
u16 FAT_filesystem_findFirstFreeOffset();

/** \brief Chaine de caractère pour les chansons non initialisées. */
const char* emptyName = "EMPTY   ";
/** \brief Chaine de caractère pour les slots non disponibles. */
const char* noAvailable_tmp = "--------";

/**
 * \brief Cette fonction vérifie l'intégrité du filesystem.
 */
void FAT_filesystem_checkFs() {
    u8 track = 0;
    u16 offset, size;
    while (track < MAX_TRACKS) {
        offset = FAT_filesystem_getTrackOffset(track);
        size = FAT_filesystem_getTrackSize(track);

        if ((offset == 0xFFFF) 
                || (offset == 0x0000)) {
            FAT_filesystem_setTrackOffset(track, (track * 4));
            FAT_filesystem_setTrackSize(track, 0);
        }

        track++;
    }
}

/**
 * \brief Donne le nom d'une chanson stockée dans le filesystem. 
 * 
 * @param trackNumber numéro de la chanson 
 * @return un pointeur sur l'espace mémoire contenant la chaine.
 */
char* FAT_filesystem_getTrackName(u8 trackNumber) {
    if (trackNumber >= MAX_TRACKS_WITHOUT_COMPRESSION) {
        return (char*) noAvailable_tmp;
    }

    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {
        return (char*) emptyName;
    }

    return & (gamepak [ offset ]);
}

/**
 * \brief Donne le nombre de fois qu'une track a été enregistrée.
 * 
 * @param trackNumber le numéro de la chanson
 * @return un chiffre compris entre 0 et 0xff
 */
u8 FAT_filesystem_getTrackNbWork(u8 trackNumber) {
    if (trackNumber >= MAX_TRACKS_WITHOUT_COMPRESSION) {
        return 0;
    }

    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {
        return 0;
    }

    return gamepak [ offset + SONG_NAME_MAX_LETTERS ];
}

/**
 * \brief Parcourt la table d'allocation des tracks et donne le premier offset physiquement
 * libre pour le stockage d'une track.
 * 
 * \todo Pas de compression pour le moment, cette méthode est donc "stupide".
 */
u16 FAT_filesystem_findFirstFreeOffset() {
    return MAX_TRACKS * 4; // offset par défaut = fin de la table d'allocation
}

/**
 * \brief Donne l'offset de départ de stockage pour une chanson. Mode RAW.
 * 
 * @param trackNumber le numéro de chanson
 * @return un nombre compris entre 0x0000 et 0xffff
 */
u16 FAT_filesystem_findRawTrackOffset(u8 trackNumber) {
    return (MAX_TRACKS * 4) + (sizeof (FAT_tracker) * trackNumber);
}

/**
 * \brief Sauvegarde de la chanson AVEC compression.
 * 
 * @param trackNumber numéro du slot d'enregistrement
 */
void FAT_filesystem_saveTrack(u8 trackNumber) {
    FAT_tracker.nbWork++;

    u8* tracker = (u8*) &FAT_tracker;
    u8* buffer = (u8*) &FAT_compressed_tracker;

    u32 totalSize = SIZEOF_8BIT(FAT_tracker);
    u8 currentByte = 0;
    u8 previousByte = tracker[0];
    int cpt = 1; int rleCpt = 1; int bufferOffset = 0;
    while (cpt < totalSize){
        currentByte = tracker[cpt];
        if (currentByte != previousByte || rleCpt >= 0xff){
            buffer[bufferOffset] = rleCpt;
            buffer[bufferOffset + 1] = previousByte;

            bufferOffset += 2;
            previousByte = currentByte;
            rleCpt = 1;
        } else {
            rleCpt ++;
        }

        cpt++;
    }
    buffer[bufferOffset] = rleCpt;
    buffer[bufferOffset + 1] = previousByte;
    bufferOffset += 2;

    // bufferOffset contient la taille finale de la track compressée !
    u32 trackSize = bufferOffset;
    tracker = buffer;
    //FAT_filesystem_setTrackSize (trackNumber, size);

    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {
        // la track n'a jamais été initialisé. on cherche le prochain offset libre.
        //offset = FAT_filesystem_findFirstFreeOffset ();
        offset = FAT_filesystem_findRawTrackOffset(trackNumber);
        FAT_filesystem_setTrackOffset(trackNumber, offset);
    }

    int counter = 0;
    while (counter < trackSize) {
        gamepak[offset + counter] = tracker[counter];
        counter++;
    }

    FAT_filesystem_setTrackSize(trackNumber, trackSize);
    gamepak[offset + counter] = 0x5a;
}

/**
 * \brief Chargement de la chanson AVEC compression.
 * 
 * @param trackNumber numéro du slot d'enregistrement
 */
void FAT_filesystem_loadTrack(u8 trackNumber) {

}

/**
 * \brief Modifie l'offset de départ d'une chanson.
 *  
 * @param trackNumber le numéro de la chanson (et du slot)
 * @param offset la nouvelle valeur de l'offset
 */
void FAT_filesystem_setTrackOffset(u8 trackNumber, u16 offset) {
    gamepak[ trackNumber * 4 ] = offset >> 8;
    gamepak[ (trackNumber * 4) + 1 ] = offset & 0x00ff;
}

/**
 * \brief Récupère l'offset de départ d'une chanson.
 *  
 * @param trackNumber le numéro de la chanson (et du slot)
 * @param offset la nouvelle valeur de l'offset
 */
u16 FAT_filesystem_getTrackOffset(u8 trackNumber) {
    u16 firstPart = gamepak[ trackNumber * 4 ];
    u8 secondPart = gamepak[ (trackNumber * 4) + 1 ];

    return (firstPart << 8) | secondPart;
}

/**
 * \brief Remplit la valeur de la taille de la chanson.
 * 
 * @param trackNumber numéro de la track
 * @param size taille de 0x0000 à 0xFFFF
 */
void FAT_filesystem_setTrackSize(u8 trackNumber, u16 size) {
    gamepak[ (trackNumber * 4) + 2 ] = size >> 8;
    gamepak[ (trackNumber * 4) + 3 ] = size & 0x00ff;
}

/**
 * \brief Récupère la taille actuelle de la chanson.
 * @param trackNumber le numéro de la chanson
 * 
 * @return un nombre compris entre 0x0000 et 0xFFFF
 */
u16 FAT_filesystem_getTrackSize(u8 trackNumber) {
    u16 firstPart = gamepak[ (trackNumber * 4) + 2];
    u8 secondPart = gamepak[ (trackNumber * 4) + 3];

    return (firstPart << 8) | secondPart;
}

/**
 * \brief Donne la taille de la chanson en vérifiant certaines conditions liées au 
 * mode RAW.
 * 
 * @param trackNumber le numéro de la chanson
 * @return la taille compris entre 0x0000 et 0xFFFF
 */
u16 FAT_filesystem_getTrackSizeChecked(u8 trackNumber) {
    if (trackNumber >= MAX_TRACKS_WITHOUT_COMPRESSION) {
        return 0;
    }

    u16 size = FAT_filesystem_getTrackSize(trackNumber);
    if (size == 0xFFFF) {
        return 0;
    }

    return size;
}

/**
 * \brief Fonction de sauvegarde d'un track. Mode RAW. Pas de compression.
 * \deprecated
 */
void old_FAT_filesystem_saveRaw(u8 trackNumber) {
    FAT_tracker.nbWork++;

    u8* tracker = (u8*) & FAT_tracker;

    //u32 trackSize = FAT_filesystem_getTrackSize(trackNumber);
    u32 trackSize = SIZEOF_8BIT(FAT_tracker);
    //FAT_filesystem_setTrackSize (trackNumber, size);

    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {
        // la track n'a jamais été initialisé. on cherche le prochain offset libre.
        //offset = FAT_filesystem_findFirstFreeOffset ();
        offset = FAT_filesystem_findRawTrackOffset(trackNumber);
        FAT_filesystem_setTrackOffset(trackNumber, offset);
    }

    int counter = 0;
    while (counter < trackSize) {
        gamepak[offset + counter] = tracker[counter];
        counter++;
    }

    FAT_filesystem_setTrackSize(trackNumber, trackSize);

    gamepak[offset + counter] = 0x5a;
}

/**
 *  \brief Fonction de chargement d'une track. Mode RAW. Pas de compression.
 * 
 */
void FAT_filesystem_loadRaw(u8 trackNumber) {
    u8* tracker = (u8*) & FAT_tracker;
    u32 trackSize = FAT_filesystem_getTrackSize(trackNumber);
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {
        // la track n'a jamais été initialisé.
        // on se contente de réinitialiser la mémoire
        FAT_data_initData();
    } else {
        int counter = 0;
        while (counter < trackSize) {
            tracker[counter] = gamepak[offset + counter];
            counter++;
        }
    }
}


#endif	/* FILESYSTEM_H */

