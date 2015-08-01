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

#define DEFAULT_FIRST_DATA_OFFSET (MAX_TRACKS*4)+16

void FAT_filesystem_checkFs();
void FAT_filesystem_saveTrack(u8 trackNumber);
void FAT_filesystem_loadTrack(u8 trackNumber);
void FAT_filesystem_setTrackOffset(u8 trackNumber, u16 offset);
u16 FAT_filesystem_getTrackOffset(u8 trackNumber);
void FAT_filesystem_setTrackSize(u8 trackNumber, u16 size);
u16 FAT_filesystem_getTrackSize(u8 trackNumber);
void old_FAT_filesystem_saveRaw(u8 trackNumber);
void old_FAT_filesystem_loadRaw(u8 trackNumber);
u16 FAT_filesystem_findFirstFreeOffset();
void FAT_filesystem_setFirstFreeOffsetValue(u16 value);

/** \brief Chaine de caractère pour les chansons non initialisées. */
const char* emptyName = "EMPTY   ";

char songNameBuffer[9] = "FATSONG!\0";

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

    // init premier offset libre si besoin
    u16 firstFreeOffset = FAT_filesystem_findFirstFreeOffset();
    if (firstFreeOffset == 0x0000 || firstFreeOffset == 0xFFFF){
        FAT_filesystem_setFirstFreeOffsetValue(DEFAULT_FIRST_DATA_OFFSET);
    }
}

/**
 * \brief Donne le nom d'une chanson stockée dans le filesystem. 
 * 
 * @param trackNumber numéro de la chanson 
 * @return un pointeur sur l'espace mémoire contenant la chaine.
 */
char* FAT_filesystem_getTrackName(u8 trackNumber) {
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber*4)) {
        return (char*) emptyName;
    }

    offset += 3; // "SNG"

    // décompression du nom.
    u8 cpt = 0;
    u8 writerCpt = 0;
    u8 rleCount, car;
    while (cpt < 8){
        rleCount = gamepak[offset];
        car = gamepak[offset+1];
        writerCpt = 0;
        while (writerCpt < rleCount){
            songNameBuffer[cpt] = car;
            writerCpt++;
            cpt++;
        }
        offset+=2;
    }
    songNameBuffer[8] = '\0';

    return (char*)&songNameBuffer;
}

/**
 * \brief Donne le nombre de fois qu'une track a été enregistrée.
 * 
 * @param trackNumber le numéro de la chanson
 * @return un chiffre compris entre 0 et 0xff
 */
u8 FAT_filesystem_getTrackNbWork(u8 trackNumber) {
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber*4)) {
        return 0;
    }

    offset += 3; //" SNG"

    // on doit d'abord passer le "nom" avant d'accéder à l'info "nbwork"
    u8 cpt = 0;
    while (cpt < 8){
        cpt += gamepak[offset];
        offset += 2;
    }

    offset += 3; // pour passer le dernier "rleCount" et se positionner sur la donnée.

    return gamepak[offset];
}

/**
 * \brief Parcourt la table d'allocation des tracks et donne le premier offset physiquement
 * libre pour le stockage d'une track.
 * L'information est stockée juste apres les infos de taille et d'offsetting des tracks
 * 
*/
u16 FAT_filesystem_findFirstFreeOffset() {
    u16 firstPart = gamepak[ (MAX_TRACKS * 4)];
    u8 secondPart = gamepak[ (MAX_TRACKS * 4) + 1];

    return (firstPart << 8) | secondPart;
}

/**
 * \brief Set la valeur de prochain offset libre pour enregistrer des données.
 */
void FAT_filesystem_setFirstFreeOffsetValue(u16 value){
    gamepak[ (MAX_TRACKS * 4)] = value >> 8;
    gamepak[ (MAX_TRACKS * 4) + 1] = value & 0x00ff;
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
 * \brief Regarde si un jump s'applique à l'offset courant. Si un jump s'applique, alors le nouvel offset est calculé et renvoyé.
 *
 * @param offset l'offset courant à vérifier
 * @param saveMode 1=save, 0=load
 * @return le nouvel offset en cas de jump ou l'offset non modifié.
 */
u16 FAT_filesystem_hasJumpToApply (u16 offset, bool saveMode) {
    // si la valeur actuelle dans la sauvegarde est un 'L', alors il faut peuetre s'inquiéter :D
    if (gamepak[offset] == 'L'){
        // est ce que la suite est 'NK' ? Si oui il va falloir peut-être jumper (s'il y a une autre track apres ce LNK).
        if (gamepak[offset + 1] == 'N' && gamepak[offset + 2] == 'K'){
            if (gamepak[offset +5] == 0x5a &&
                gamepak[offset +6] == 'S' &&
                gamepak[offset +7] == 'N' &&
                gamepak[offset +8] == 'G'){

                    // Ok c'est sur, on ne peut plus continuer ici, il faut sauter.
                    u16 jump = (gamepak[offset +3] << 8) | gamepak[offset +4];
                    if (jump == 0xFFFF && saveMode){
                        // jump non renseigné
                        jump = FAT_filesystem_findFirstFreeOffset (); // todo potentiels bugs.
                        // écriture du jump
                        gamepak[offset +3] = jump >> 8;
                        gamepak[offset +4] = jump & 0x00ff;
                    }
                    offset = jump;
                    // cool. On a sauté. Ca n'arrive pas souvent (sic). On écrit un FOL.
                    if (saveMode){
                        gamepak[offset] = 'F';
                        gamepak[offset+1] = 'O';
                        gamepak[offset+2] = 'L';
                    }
                    offset += 3; // header OK.
            }
        }
    }
    return offset;
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
    //FAT_filesystem_setTrackSize (trackNumber, size);

    u16 offset = FAT_filesystem_getTrackOffset(trackNumber);

    if (offset == (trackNumber * 4)) {
        // la track n'a jamais été sauvegardé. on prend l'info "premier offset libre" dans la table d'alloc
        offset = FAT_filesystem_findFirstFreeOffset ();
        FAT_filesystem_setTrackOffset(trackNumber, offset);
    }

    // Ecriture de la track dans la mémoire
    gamepak[offset]     = 'S';
    gamepak[offset+1]   = 'N';
    gamepak[offset+2]   = 'G';
    offset += 3; // header

    int counter = 0;
    while (counter < trackSize) {

        // y a t'il un jump à appliquer ?
        offset = FAT_filesystem_hasJumpToApply (offset, 1);

        gamepak[offset] = buffer[counter];
        counter++;
        offset++;
    }

    FAT_filesystem_setTrackSize(trackNumber, trackSize);
    gamepak[offset]       = 'L';
    gamepak[offset +1]    = 'N';
    gamepak[offset +2]    = 'K';
    gamepak[offset +3]    = 0xff;
    gamepak[offset +4]    = 0xff;
    gamepak[offset +5]    = 0x5a;

    FAT_filesystem_setFirstFreeOffsetValue(offset +6);
}

/**
 * \brief Chargement de la chanson AVEC compression.
 * 
 * @param trackNumber numéro du slot d'enregistrement
 */
void FAT_filesystem_loadTrack(u8 trackNumber) {

    u8* tracker = (u8*) &FAT_tracker;
    u8* buffer = (u8*) &FAT_compressed_tracker;

    u32 trackSize = FAT_filesystem_getTrackSize(trackNumber);
    u16 offset = FAT_filesystem_getTrackOffset(trackNumber) + 3; // on saute le "SNG"

    // pour faire propre.
    FAT_data_initData();

    if (offset != (trackNumber * 4)) {
        int counter = 0;

        // remplissage du buffer de gestion des données compressées
        while (counter < trackSize) {

            // y a t'il un saut dans les données ?
            offset = FAT_filesystem_hasJumpToApply(offset, 0);

            buffer[counter] = gamepak[offset];
            counter++;
            offset++;
        }

        // décompression des données dans "*tracker"
        counter = 0;
        u8 currentRLE = 0;
        u8 currentByte = 0;
        u8 dataCpt = 0;
        u32 writerCpt = 0;
        while (counter < trackSize){

            currentRLE = buffer[counter]; // nb
            currentByte = buffer[counter +1]; // data
            dataCpt = 0;
            while (dataCpt < currentRLE){
                tracker[writerCpt] = currentByte;
                dataCpt ++;
                writerCpt ++;
            }

            counter += 2;
        }
    }
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
u16 old_FAT_filesystem_getTrackSizeChecked(u8 trackNumber) {
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
void old_FAT_filesystem_loadRaw(u8 trackNumber) {
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

