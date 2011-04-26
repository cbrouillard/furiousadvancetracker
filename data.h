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
 * \file data.h
 * \brief Ce fichier contient toutes les définitions des types de données et autres structures.
 * 
 * Il contient également un set de fonctions utiles pour les modifications et récupérations
 * sur toutes les données techniques du tracker.
 */

#ifndef _DATA_H_
#define	_DATA_H_

/**
 * \def NB_MAX_SEQUENCES
 * \brief Nombre de séquences disponibles <b>au total</b> en mémoire. 0x80 = 128
 */
#define NB_MAX_SEQUENCES 0x80
/**
 * \brief Nombre de séquences référençables par canal. 0x40 = 64
 */
#define NB_SEQUENCES_IN_ONE_CHANNEL 0x40
/**
 * \brief Nombre de blocks disponibles <b>au total</b> en mémoire. 0x70 = 112
 */
#define NB_MAX_BLOCKS 0x70
/**
 * \brief Nombre d'instruments disponibles <b>au total</b> en mémoire. 0x3f = 63
 */
#define NB_MAX_INSTRUMENTS 0x3f
/**
 * \brief Nombre de tables disponibles <b>au total</b> en mémoire. 0xf = 15
 */
#define NB_MAX_TABLES 0xF
/**
 * \brief Nombre de notes dans un block (une mesure).
 */
#define NB_NOTES_IN_ONE_BLOCK 16
/**
 * \brief Nombre de blocks (mesures) dans une séquence (pattern).
 */
#define NB_BLOCKS_IN_SEQUENCE 16
/**
 * \brief Nombre d'effets référençables par table.
 */
#define NB_EFFECTS_IN_ONE_TABLE 16
/**
 * \brief Octave minimale pour une note.
 */
#define MIN_OCTAVE 3
/**
 * \brief Octave maximale pour une note.
 */
#define MAX_OCTAVE 8
/**
 * \brief Nombre total de notes disponibles: de C à B (notation anglo-saxonne).
 */
#define NB_NOTE 12
/**
 * \brief Taille maximale pour le nom d'une chanson.
 */
#define SONG_NAME_MAX_LETTERS 9

/**
 * \brief Type d'instrument PULSE 1
 */
#define INSTRUMENT_TYPE_PULSE 0
/**
 * \brief Type d'instrument PULSE 2
 */
#define INSTRUMENT_TYPE_PULSE2 1
/**
 * \brief Type d'instrument WAVE
 */
#define INSTRUMENT_TYPE_WAVE 2
/**
 * \brief Type d'instrument NOISE
 */
#define INSTRUMENT_TYPE_NOISE 3
/**
 * \brief Type d'instrument SAMPLE A
 */
#define INSTRUMENT_TYPE_SAMPLEA 4
/**
 * \brief Type d'instrument SAMPLE B
 */
#define INSTRUMENT_TYPE_SAMPLEB 5
/**
 * \brief Valeur de volume maximum pour un instrument de type PULSE.
 */
#define INSTRUMENT_PULSE_VOLUME_MAX 16
/**
 * \brief Valeur de "wave" maximum pour un instrument de type PULSE.
 */
#define INSTRUMENT_PULSE_WAVE_MAX 4
/**
 * \brief Valeur de "steptime" maximum pour un instrument de type PULSE.
 */
#define INSTRUMENT_PULSE_STEPTIME_MAX 8
/**
 * \brief Valeur de "soundlength" maximum pour un instrument de type PULSE.
 */
#define INSTRUMENT_PULSE_LENGTH_MAX 64
/**
 * \brief Valeur de "sweep" maximum pour un instrument de type PULSE.
 */
#define INSTRUMENT_PULSE_SWEEP_MAX 128
/**
 * \brief Valeur de volume maximum pour un instrument de type WAVE.
 */
#define INSTRUMENT_WAVE_VOLUME_MAX 5
/**
 * \brief Valeur de "soundlength" maximum pour un instrument de type WAVE.
 */
#define INSTRUMENT_WAVE_LENGTH_MAX 256
/**
 * \brief Nombre de voix disponibles pour un instrument de type WAVE.
 */
#define INSTRUMENT_WAVE_NB_VOICE 0x18
/**
 * \brief Tempo maximal.
 */
#define MAX_TEMPO 255
/**
 * \brief Valeur de transposition maximale.
 */
#define MAX_TRANSPOSE 256
/**
 * \brief NULL_VALUE représente la valeur "interdite".
 * 
 * Au démarrage de l'appli, toutes les données dans FAT_tracker sont initialisées
 * avec NULL_VALUE.
 * <b>NE PAS TOUCHER !</b>
 */
#define NULL_VALUE 0xff
/**
 * \brief Addresse vers la mémoire SRAM (la mémoire pour la sauvegarde).
 */
#define GAMEPAK_RAM  ((u8*)0x0E000000)
/**
 * \brief Pointeur vers la mémoire SRAM.
 */
u8 *pSaveMemory = GAMEPAK_RAM;
/**
 * \brief Tableau constant contenant toutes les notes sous formes de chaînes de caractères.
 */
const char* noteName[NB_NOTE] = {"C ", "C\"", "D ", "D\"", "E ", "F ", "F\"", "G ", "G\"", "A ", "A\"", "B "};

/**
 * \brief Nombre total de fréquences de notes.
 *
 * F(Hz)=4194304/(32*(2048-register value)). The minimum frequency is 64Hz and the maximum is 131Khz.
 * Voir <a href="http://jeanjacques.dialo.free.fr/frequenc.htm">http://jeanjacques.dialo.free.fr/frequenc.htm</a>
 */
#define NB_FREQUENCES 72

// prototypes
void FAT_data_initInstrumentIfNeeded(u8 instId, u8 channel);
bool FAT_data_smartAllocateSequence(u8 channelId, u8 line);
bool FAT_data_smartAllocateBlock(u8 sequence, u8 blockLine);

/**
 * \struct EFFECT
 * \brief Définit une commande.
 * 
 * La structure EFFECT permet de stocker une commande : son nom et sa valeur.
 */
typedef struct EFFECT {
    u8 name; /*!< Un numéro permettant de pointer vers un tableau de char* afin d'afficher le nom. */
    u8 value; /*!< La valeur de la commande de 0 à FF. */
} effect;

/**
 * \struct TABLE
 * \brief Définit une table d'effets: soit une liste de commandes.
 * 
 * Une table possède un nombre défini de commandes.
 */
typedef struct TABLE {
    effect effects[NB_EFFECTS_IN_ONE_TABLE]; /*!< Le tableau des commandes enregistrées dans cette table. */
} table;

/**
 * \struct NOTE
 * \brief Définit une note.
 */
typedef struct NOTE {
    u8 note; /*!< Cette variable contient le nom de la note et son octave. */
    // 0x 0000  0000
    // 0x name  octave
    // récupérer le nom -> (note & 0xf0) >> 4
    // récupérer l'octave -> note & 0x0f
    u8 freq; /*!< Le numéro de fréquence assigné à la note. Cf: const u16 freqs[NB_FREQUENCES]*/
    u8 instrument; /*!< Le numéro d'instrument assigné à la note. */
    effect effect; /*!< L'effet (ou commande) assigné à la note. */
} note;
/**
 * \brief Espace mémoire contenant la dernière note écrite. Par défaut, cette note est initialisée
 * à "C 3".
 */
note FAT_data_lastNoteWritten;
/**
 * \brief Presse-papier pour couper/coller une note.
 */
note FAT_data_noteClipboard;

/**
 * \struct COMPOSER
 * \brief Définit les données pour le compositeur (écran de composition).
 */
typedef struct COMPOSER {
    note notes[8]; /*!< Un compositeur contient un certain nombre de notes. */
    u8 transpose; /*!< Définit la valeur de transposition pour le compositeur entier <b>NON IMPLEMENTE</b>. */
} composer;

/**
 * \struct BLOCK
 * \brief Un block représente une mesure et contient un nombre de notes définies.
 */
typedef struct BLOCK {
    note notes[NB_NOTES_IN_ONE_BLOCK]; /*!< Un tableau contenant les notes. */
    effect effect; /*!< Chaque block peut se voir attribuer un effet. Cet effet sera calculé sur chacune des notes présente dans le block. */
} block;
/**
 * \brief Cette variable permet de stocker le dernier numéro de block écrit.
 */
u8 FAT_data_lastBlockWritten;
/**
 * \brief Presse-papier pour couper/coller des numéros de blocks.
 */
u8 FAT_data_blockClipboard;

/**
 * \struct SEQUENCE
 * \brief Une séquence contient un certain nombre de blocks.
 */
typedef struct SEQUENCE {
    u8 blocks[NB_BLOCKS_IN_SEQUENCE]; /*!< Un tableau contenant des numéros de blocks. */
    u8 transpose[NB_BLOCKS_IN_SEQUENCE]; /*!< Chaque block peut être transposé: on stocke la valeur de transpose ici.
                                          * On ne peut pas la stocker dans BLOCK, car cela ne permettrait qu'une seule
                                          * transposition par block. Ici, un block peut être transposé avec telle valeur dans
                                          * une séquence et telle autre valeur dans une autre séquence. De même, au sein de la
                                          * même séquence, on peut ainsi transposer différemment chacun des blocks présent.
                                          */
} sequence;
/**
 * \brief Stocke le dernier numéro de séquence écrit.
 */
u8 FAT_data_lastSequenceWritten;
/**
 * \brief Presse-papier pour couper/coller des séquences.
 */
u8 FAT_data_sequenceClipboard;

/**
 * \struct CHANNEL
 * \brief Un channel représente une colonne de séquences: la GBA dispose de 6 channels.
 */
typedef struct CHANNEL {
    u8 sequences[NB_SEQUENCES_IN_ONE_CHANNEL]; /*!< Un channel possède sa collection de numéro de séquence.*/
} channel;

/**
 * \struct INSTRUMENT
 * \brief L'instrument possède divers paramètres utiles pour modifier la sonorité d'une note: chaque note est 
 * attachée à un instrument.
 */
typedef struct INSTRUMENT {
    u8 type;/*!< Le type de l'instrument: PULSE1, PULSE2, WAVE, NOISE, SAMPLEA, SAMPLEB */
    u8 sweep;/*!< Valeur de "sweep". Le "sweep" n'est applicable que sur le channel 1. */
    //u8 volume; // max = F = 4bits
    //u8 envdirection; // max = 1
    //u8 envsteptime; // max = 7
    u8 envelope; /*!< Valeur d'enveloppe. L'enveloppe contient trois paramètres: "steptime", "envdir", "volume". */
    // 0x 000          0    0000
    // 0x steptime     dir  volume
    // steptime -> (envelope & 0xE0) >> 5
    // dir -> (envelope & 0x10) >> 4
    // volume -> (envelope & 0x0f)
    u8 wavedutyOrPolynomialStep; /*!< Contient la valeur du paramètre "wave" pour les instruments de type PULSE <b>OU</b> 
                                  la valeur du paramètre "polystep" pour les instruments de type NOISE */
    u8 soundlength; /*!< Stocke la durée du son: attention, ce paramètre ne sera appliqué que si loopmode = 1. */
    u8 loopmode; /*!< Mode de durée du son : 1=timed, 0=continuous .*/

    // regrouper ces 3 variables en 1 u8
    //u8 voice; // max = 17
    //u8 bank; // max = 1
    //u8 bankMode; // max = 1
    // 0x 0   0        0     0 0000
    // 0x NA  bankmode bank  voice
    u8 voiceAndBank;/*!< Ce paramètre agrége plusieurs autres paramètres dédiés aux instruments de type WAVE : "voice", "bank", "bankmode". */
    // voice -> voiceAndBank & 0x1f
    // bank -> (voiceAndBank & 0x20) >> 5
    // bankMode -> (voiceAndBank & 0x40) >> 6

    // supprimer cette variable -> volume existe !
    u8 volumeRatio; /*!< Stocke le volume pour un instrument de type WAVE. */

    u8 table; /*!< Numéro de table de commandes à appliquer pour chaque note assignée à cet instrument. */
} instrument;
/**
 * \struct FAT
 * \brief Structure principale: stocke l'intégralité d'une track en cours de composition.
 * 
 * Cette structure définit le tracker: toutes les données sont référencés dans cette espace.
 */
typedef struct FAT {
    channel channels[6];/*!< Définition des channels: la GBA en dispose de 6. */
    sequence allSequences [NB_MAX_SEQUENCES]; /*!< Tableau (physique) contenant toutes les séquence. */
    block allBlocks [NB_MAX_BLOCKS];/*!< Tableau (physique) contenant tous les blocks. */
    instrument allInstruments[NB_MAX_INSTRUMENTS];/*!< Tableau (physique) contenant tous les instruments. */
    composer composer; /*!< Données pour l'écran de composition. */

    u8 tempo;/*!< Tempo pour la track en cours de composition. */
    u8 transpose;/*!< Valeur de transposition pour la track en cours de composition. */
    char songName[SONG_NAME_MAX_LETTERS];/*!< Nom de la track en cours de composition. */

    table tables[NB_MAX_TABLES];/*!< Tableau (physique) contenant toutes les tables. */
} tracker;

/**
 * \brief Contient toutes les données déjà instanciées.
 * 
 * C'est cette variable qui est utilisée (écrite sur la ram) lors de la sauvegarde
 * et vice versa pour le chargement. 
 */
tracker FAT_tracker;

/**
 * \brief Stocke le numéro de la prochaine séquence disponible.
 */
u8 FAT_nextAvailableSequenceId = 0;
/**
 * \brief Stocke le numéro du prochain block disponible.
 */
u8 FAT_nextAvailableBlockId = 0;
/**
 * \brief Stocke le numéro du prochain instrument disponible.
 */
u8 FAT_nextAvailableInstrumentId = 0;
/**
 * \brief Stocke le dernier numéro d'instrument utilisé.
 */
u8 FAT_lastUsedInstrumentId = 0;

/**
 * \brief Initialise les données du tracker. Utile lors de l'allumage de la console.
 */
void FAT_data_initData() {
    memset(&FAT_tracker, NULL_VALUE, sizeof (tracker));
    FAT_tracker.tempo = 128;
    FAT_tracker.transpose = 0;
    strcpy(FAT_tracker.songName, "SONGNAME\0");

    // note par défaut
    FAT_data_lastNoteWritten.freq = 0;
    FAT_data_lastNoteWritten.instrument = 0;
    FAT_data_lastNoteWritten.note = 0x03;

    // block par défaut
    FAT_data_lastBlockWritten = 0;
    FAT_data_lastSequenceWritten = 0;

    FAT_data_sequenceClipboard = NULL_VALUE;
    FAT_data_blockClipboard = NULL_VALUE;
    memset(&FAT_data_noteClipboard, NULL_VALUE, sizeof (note));
}

/**
 * \brief Efface une séquence dans le tableau "SONG".
 * 
 * Attention ! cette méthode n'efface pas le contenu de la séquence. Seulement,
 * la référence dans le tableau !
 * @param channelId le numéro du channel (de 0 à 5)
 * @param line le numéro de ligne ou se situe la séquence dans le tableau
 */
void FAT_data_cutSequence(u8 channelId, u8 line) {
    FAT_data_sequenceClipboard = FAT_tracker.channels[channelId].sequences[line];
    FAT_tracker.channels[channelId].sequences[line] = NULL_VALUE;
}
/**
 * \brief Colle la séquence actuellement stockée dans le clipboard.
 * 
 * @param channelId le numéro du channel (de 0 à 5)
 * @param line le numéro de ligne ou se situe la séquence dans le tableau
 */
void FAT_data_pasteSequence(u8 channelId, u8 line) {
    FAT_tracker.channels[channelId].sequences[line] = FAT_data_sequenceClipboard;
}
/**
 * \brief Clone une séquence: change le numéro de la séquence pointée.
 * 
 * Le nouveau numéro est le suivant disponible. La fonction copie égalements les éventuels
 * ids de blocks se trouvant dans la séquence à cloner (elle ne clone pas les blocks).
 * 
 * @param channelId le numéro du channel (de 0 à 5)
 * @param line le numéro de ligne ou se situe la séquence dans le tableau
 */
void FAT_data_cloneSequence(u8 channelId, u8 line) {
    u8 seqIdTemp = FAT_tracker.channels[channelId].sequences[line];
    if (FAT_data_smartAllocateSequence(channelId, line) && seqIdTemp != NULL_VALUE) {
        // copie de tout le contenu de la séquence dans la nouvelle
        memcpy(& (FAT_tracker.allSequences[FAT_tracker.channels[channelId].sequences[line]]),
                & (FAT_tracker.allSequences[seqIdTemp]), sizeof (sequence));
    }
}

/**
 * \brief Colle la séquence dans le presse-papier en changeant le numéro.
 * 
 * Le numéro est déterminé automatiquement: c'est le premier numéro de séquence vide.
 * 
 * @param channelId le numéro du channel (de 0 à 5)
 * @param line le numéro de ligne ou se situe la séquence dans le tableau
 */
void FAT_data_pasteSequenceWithNewNumber(u8 channelId, u8 line) {
    if (FAT_data_smartAllocateSequence(channelId, line) && FAT_data_sequenceClipboard != NULL_VALUE) {
        // copie de tout le contenu de la séquence dans la nouvelle
        memcpy(& (FAT_tracker.allSequences[FAT_tracker.channels[channelId].sequences[line]]),
                & (FAT_tracker.allSequences[FAT_data_sequenceClipboard]), sizeof (sequence));
    }
}

/**
 * \brief Efface un block dans une séquence donnée.
 * 
 * Attention, cette méthode n'efface pas le contenu du block, seulement la 
 * référence dans la séquence.
 * @param sequence le numéro de la séquence de 0 à NB_MAX_SEQUENCES
 * @param blockLine le numéro de ligne du block à effacer dans la séquence
 */
void FAT_data_cutBlock(u8 sequence, u8 blockLine) {
    FAT_data_blockClipboard = FAT_tracker.allSequences[sequence].blocks[blockLine];
    FAT_tracker.allSequences[sequence].blocks[blockLine] = NULL_VALUE;
}

void FAT_data_pasteBlock(u8 sequence, u8 blockLine) {
    FAT_tracker.allSequences[sequence].blocks[blockLine] = FAT_data_blockClipboard;
}

void FAT_data_copyBlock(u8 sequence, u8 blockLine) {
    u8 blockIdTemp = FAT_tracker.allSequences[sequence].blocks[blockLine];
    if (FAT_data_smartAllocateBlock(sequence, blockLine) && blockIdTemp != NULL_VALUE) {
        // copie de tout le contenu de la séquence dans la nouvelle
        memcpy(& (FAT_tracker.allBlocks[FAT_tracker.allSequences[sequence].blocks[blockLine]]),
                & (FAT_tracker.allBlocks[blockIdTemp]), sizeof (block));
    }
}

void FAT_data_pasteBlockWithNewNumber(u8 sequence, u8 blockLine) {
    if (FAT_data_smartAllocateBlock(sequence, blockLine) && FAT_data_blockClipboard != NULL_VALUE) {
        // copie de tout le contenu de la séquence dans la nouvelle
        memcpy(& (FAT_tracker.allBlocks[FAT_tracker.allSequences[sequence].blocks[blockLine]]),
                & (FAT_tracker.allBlocks[FAT_data_blockClipboard]), sizeof (block));
    }
}

/**
 * Efface une note donnée dans un block. 
 * Attention cette méthode EFFACE POUR DE VRAI la note ! Elle est cependant
 * copiée dans l'espace mémoire "lastNoteWritten"
 * TODO reserver un espace mémoire spécial pour cette note
 * @param block le numéro de block
 * @param noteLine le numéro de ligne de la note dans le block
 */
void FAT_data_cutNote(u8 block, u8 noteLine) {
    memcpy(&FAT_data_noteClipboard, &(FAT_tracker.allBlocks[block].notes[noteLine]), sizeof (note));
    FAT_tracker.allBlocks[block].notes[noteLine].freq = NULL_VALUE;
}

void FAT_data_composer_cutNote(u8 line) {
    memcpy(&FAT_data_noteClipboard, &(FAT_tracker.composer.notes[line]), sizeof (note));
    FAT_tracker.composer.notes[line].freq = NULL_VALUE;
}

void FAT_data_pasteNote(u8 block, u8 noteLine) {
    memcpy(&(FAT_tracker.allBlocks[block].notes[noteLine]), &FAT_data_noteClipboard, sizeof (note));
}

void FAT_data_composer_pasteNote(u8 line) {
    memcpy(&(FAT_tracker.composer.notes[line]), &FAT_data_noteClipboard, sizeof (note));
}

/**
 * Permet de savoir si une séquence est allouable (disponible). 
 * @param channelId le canal de 0 à 5
 * @param line le numéro de ligne de la séquence dans le tableau SONG
 * @return vrai si la séquence est disponible (non déjà utilisée)
 */
bool FAT_data_isSequenceAllocatable(u8 channelId, u8 line) {
    return FAT_tracker.channels[channelId].sequences[line] == NULL_VALUE;
}

/**
 * Permet de savoir si un block est allouable (disponible)
 * @param sequence le numéro de séquence
 * @param blockLine le numéro de ligne du block dans la séquence
 * @return vrai si le block est disponible (non déjà utilisé)
 */
bool FAT_data_isBlockAllocatable(u8 sequence, u8 blockLine) {
    return FAT_tracker.allSequences[sequence].blocks[blockLine] == NULL_VALUE;
}

/**
 * Cette méthode indique si une note est déjà présente un emplacement donné.
 * @param block le numéro de block concerné
 * @param noteLine le numéro de ligne de la note dans le block
 * @return vrai si aucune note n'est présente à cet endroit.
 */
bool FAT_data_isNoteEmpty(u8 block, u8 noteLine) {
    return FAT_tracker.allBlocks[block].notes[noteLine].freq == NULL_VALUE;
}

/**
 * Retourne un id séquence. 
 * @param channelId le canal
 * @param sequenceLine le numéro de ligne de la séquence dans le tableau SONG
 * @return l'id de la séquence de 0 à NB_MAX_SEQUENCES ou NULL_VALUE si la séquence n'est pas allouée
 */
u8 FAT_data_getSequence(u8 channelId, u8 sequenceLine) {
    return FAT_tracker.channels[channelId].sequences[sequenceLine];
}

/**
 * Retourne un id block.
 * @param sequence le numéro de séquence
 * @param blockLine le numéro de ligne du block dans la séquence
 * @return l'id du block de 0 à NB_MAX_BLOCKS ou NULL_VALUE si le block n'est pas alloué
 */
u8 FAT_data_getBlock(u8 sequence, u8 blockLine) {
    return FAT_tracker.allSequences[sequence].blocks[blockLine];
}

/**
 * Retourne un pointeur sur une variable de type "note". Ce pointeur donne 
 * accès à toute les données présentes dans une note. Cf struct note
 * @param block le numéro du block
 * @param noteLine le numéro de la ligne dans le block
 * @return le pointeur sur une variable note
 */
note* FAT_data_getNote(u8 block, u8 noteLine) {
    return &FAT_tracker.allBlocks[block].notes[noteLine];
}

/**
 * Remplit automatiquement un id séquence avec la valeur d'un compteur.
 * Attention, pour le moment cette méthode est stupide et ne vérifie pas si 
 * la valeur du compteur ne correspond pas déjà à une séquence déjà allouée (manuellement)
 * TODO rendre cette méthode plus intelligente
 * @param channelId le canal
 * @param line le numéro de ligne de la séquence dans le tableau SONG
 */
void FAT_data_allocateSequenceToNextAvailableId(u8 channelId, u8 line) {
    if (FAT_nextAvailableSequenceId < NB_MAX_SEQUENCES) {
        FAT_tracker.channels[channelId].sequences[line] = FAT_nextAvailableSequenceId;
        FAT_nextAvailableSequenceId++;
    }
}

bool FAT_data_allocateSequence(u8 channelId, u8 line) {
    if (FAT_data_isSequenceAllocatable(channelId, line)) {
        FAT_tracker.channels[channelId].sequences[line] = FAT_data_lastSequenceWritten;
        return 1;
    }

    return 0;
}

/**
 * Remplit automatiquement un id block avec la valeur d'un compteur.
 * Attention, pour le moment cette méthode est stupide et ne vérifie pas si 
 * la valeur du compteur ne correspond pas déjà à un block déjà alloué (manuellement) 
 * TODO rendre cette méthode plus intelligente
 * @param sequence le numéro de la séquence
 * @param blockLine le numéro de ligne du block dans la séquence
 */
void FAT_data_allocateBlockToNextAvailableId(u8 sequence, u8 blockLine) {
    if (FAT_nextAvailableBlockId < NB_MAX_BLOCKS) {
        FAT_tracker.allSequences[sequence].blocks[blockLine] = FAT_nextAvailableBlockId;
        FAT_nextAvailableBlockId++;
    }
}

/**
 * Méthode intelligente pour l'allocation d'un block dans une séquence.
 * - si le block est vide, alors on pose le même block que le dernier posé
 * - si le block n'est pas vide alors on ne fait rien (on pourra afficher un message plus tard)
 * @param instId
 * @param channel
 * @return 1 si un nouveau block a été écrit, 0 si rien n'a été fait
 */
bool FAT_data_allocateBlock(u8 sequence, u8 blockLine) {
    if (FAT_data_isBlockAllocatable(sequence, blockLine)) {
        FAT_tracker.allSequences[sequence].blocks[blockLine] = FAT_data_lastBlockWritten;
        return 1;
    }

    return 0;
}

bool FAT_data_isBlockEmpty(u8 blockId) {
    u8 note = 0;
    while (note < NB_NOTES_IN_ONE_BLOCK) {
        if (FAT_tracker.allBlocks[blockId].notes[note].freq != NULL_VALUE) {
            return 0;
        }
        note++;
    }

    return 1;
}

bool FAT_data_block_isTransposeEmpty(u8 sequence, u8 line) {
    return FAT_tracker.allSequences[sequence].transpose[line] == NULL_VALUE;
}

u8 FAT_data_block_getTranspose(u8 sequence, u8 line) {
    return FAT_tracker.allSequences[sequence].transpose[line];
}

void FAT_data_block_allocateTranspose(u8 sequence, u8 line) {
    if (FAT_data_block_isTransposeEmpty(sequence, line)) {
        FAT_tracker.allSequences[sequence].transpose[line] = 0;
    }
}

bool FAT_data_isSequenceEmpty(u8 sequenceId) {
    u8 block = 0;
    while (block < NB_BLOCKS_IN_SEQUENCE) {
        if (FAT_tracker.allSequences[sequenceId].blocks[block] != NULL_VALUE) {
            return 0;
        }
        block++;
    }

    return 1;
}

bool FAT_data_isInstrumentFree(u8 inst) {
    return FAT_tracker.allInstruments[inst].sweep == NULL_VALUE;
}

/**
 * Méthode intelligente permettant de déterminer un nouveau block vide.
 * @param sequence
 * @param blockLine
 * @return 
 */
bool FAT_data_smartAllocateBlock(u8 sequence, u8 blockLine) {
    u8 block = FAT_data_lastBlockWritten + 1;
    while (block < NB_MAX_BLOCKS) {
        // si le block est vide alors on alloue
        if (FAT_data_isBlockEmpty(block)) {
            FAT_tracker.allSequences[sequence].blocks[blockLine] = block;
            FAT_data_lastBlockWritten = block;
            return 1;
        }
        block++;
    }
    return 0;
}

bool FAT_data_smartAllocateSequence(u8 channelId, u8 line) {

    u8 seq = FAT_data_lastSequenceWritten + 1;
    while (seq < NB_MAX_SEQUENCES) {
        if (FAT_data_isSequenceEmpty(seq)) {
            FAT_tracker.channels[channelId].sequences[line] = seq;
            FAT_data_lastSequenceWritten = seq;
            return 1;
        }
        seq++;
    }

    return 0;
}

/**
 * Ajoute la note par défaut (C 1 - 64Hz) sur une ligne dans un block. La note sera attribué
 * à l'instrument numéro "FAT_lastUsedInstrumentId". Si cet instrument est nouveau 
 * il sera automatiquement initialisé.
 * @param block
 * @param noteLine
 */
void FAT_data_addDefaultNote(u8 block, u8 noteLine, u8 channel) {
    FAT_tracker.allBlocks[block].notes[noteLine].freq = FAT_data_lastNoteWritten.freq;

    FAT_tracker.allBlocks[block].notes[noteLine].instrument = FAT_data_lastNoteWritten.instrument;
    FAT_tracker.allBlocks[block].notes[noteLine].note = FAT_data_lastNoteWritten.note;
    //FAT_tracker.allBlocks[block].notes[noteLine].name = FAT_data_lastNoteWritten.name;
    //FAT_tracker.allBlocks[block].notes[noteLine].octave = FAT_data_lastNoteWritten.octave;

    FAT_data_initInstrumentIfNeeded(FAT_tracker.allBlocks[block].notes[noteLine].instrument, channel);
}

/**
 * Initialise un instrument avec des valeurs par défaut uniquement si cet instrument
 * est nouveau et n'a jamais été initialisé auparavant. 
 * Attention, pour déterminer si un instru doit être initialisé, cette méthode
 * se sert d'une donnée (sweepdir) et teste si celle-ci est égale à NULL_VALUE. 
 * @param instId l'id de l'instrument à initialiser
 */
void FAT_data_initInstrumentIfNeeded(u8 instId, u8 channel) {
    if (FAT_tracker.allInstruments[instId].sweep == NULL_VALUE) {
        FAT_tracker.allInstruments[instId].sweep = 0;
        //FAT_tracker.allInstruments[instId].volume = 0xa;
        //FAT_tracker.allInstruments[instId].envdirection = 0;
        //FAT_tracker.allInstruments[instId].envsteptime = 0;
        FAT_tracker.allInstruments[instId].envelope = 0x0a;
        FAT_tracker.allInstruments[instId].volumeRatio = 3;
        FAT_tracker.allInstruments[instId].wavedutyOrPolynomialStep = 0;
        FAT_tracker.allInstruments[instId].soundlength = 0;
        FAT_tracker.allInstruments[instId].loopmode = 0;
        //FAT_tracker.allInstruments[instId].voice = 0;
        //FAT_tracker.allInstruments[instId].bank = 0;
        //FAT_tracker.allInstruments[instId].bankMode = 0;
        FAT_tracker.allInstruments[instId].voiceAndBank = 0;

        FAT_tracker.allInstruments[instId].type = channel;
    }
}

/**
 * Modifie le numéro d'une séquence. Cette méthode ajoute la valeur de "addedValue".
 * Passer +1 comme valeur ajoute, -1 pour retirer.
 * @param channelId le canal
 * @param line le numéro de ligne de la séquence à modifier
 * @param addedValue la valeur à ajouter/retirer
 */
void FAT_data_sequence_changeValue(u8 channelId, u8 line, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.channels[channelId].sequences[line] > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.channels[channelId].sequences[line] < NB_MAX_SEQUENCES - addedValue)
            ) {
        FAT_tracker.channels[channelId].sequences[line] += addedValue;
        FAT_data_lastSequenceWritten = FAT_tracker.channels[channelId].sequences[line];
    }
}

void FAT_data_block_changeTransposeValue(u8 sequence, u8 line, s8 addedValue) {
    //    if (
    //            (addedValue < 0 && FAT_tracker.allBlocks[blockId].transpose > (-addedValue - 1)) ||
    //            (addedValue > 0 && FAT_tracker.allBlocks[blockId].transpose < NB_MAX_TRANSPOSE - addedValue)
    //            ) {
    FAT_tracker.allSequences[sequence].transpose[line] += addedValue;
    //}
}

/**
 * Modifie le numéro d'un block. Cette méthode ajoute la valeur de "addedValue".
 * Passer +1 comme valeur ajoute, -1 pour retirer. 
 * @param sequence numéro de séquence
 * @param blockLine le numéro de ligne du block à modifier
 * @param addedValue la valeur à ajouter/retirer
 */
void FAT_data_block_changeValue(u8 sequence, u8 blockLine, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.allSequences[sequence].blocks[blockLine] > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.allSequences[sequence].blocks[blockLine] < NB_MAX_BLOCKS - addedValue)
            ) {
        FAT_tracker.allSequences[sequence].blocks[blockLine] += addedValue;
        FAT_data_lastBlockWritten = FAT_tracker.allSequences[sequence].blocks[blockLine];
    }
}

/**
 * Modifie la valeur d'une note. Cette méthode permet de changer l'intitulé de la note
 * et donc sa fréquence.ex. si j'ai un C 3 et que j'utilise cette méthode avec "addedValue=1" 
 * alors ma note sera modifiée en "C#3".
 * TODO cette méthode ne permet pas de passer à l'octave supérieure pour enchainer les 
 * gammes.
 * @param block le numéro de block
 * @param noteLine le numéro de ligne de la note dans le block
 * @param addedValue la valeur à ajouter/retirer (1 ou -1 généralement)
 */
void FAT_data_note_changeValue(u8 block, u8 noteLine, s8 addedValue) {
    u8 noteName = (FAT_tracker.allBlocks[block].notes[noteLine].note & 0xf0) >> 4;
    u8 noteOctave = FAT_tracker.allBlocks[block].notes[noteLine].note & 0x0f;
    if (
            (addedValue < 0 && noteName > 0) ||
            (addedValue > 0 && noteName < NB_NOTE - 1)

            ) {
        FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue;
        noteName += addedValue;
        FAT_tracker.allBlocks[block].notes[noteLine].note = (noteName << 4) + noteOctave;

        FAT_data_lastNoteWritten.freq = FAT_tracker.allBlocks[block].notes[noteLine].freq;
        FAT_data_lastNoteWritten.note = FAT_tracker.allBlocks[block].notes[noteLine].note;
    }
};

/**
 * Modifie l'octave d'une note. Cette méthode permet de changer l'octave de la note
 * et donc sa fréquence.ex. si j'ai un C 3 et que j'utilise cette méthode avec "addedValue=1" 
 * alors ma note sera modifiée en "C 4".
 * @param block le numéro de block
 * @param noteLine le numéro de ligne de la note dans le block
 * @param addedValue la valeur à ajouter/retirer (1 ou -1 généralement)
 */
void FAT_data_note_changeOctave(u8 block, u8 noteLine, s8 addedValue) {
    u8 noteOctave = FAT_tracker.allBlocks[block].notes[noteLine].note & 0x0f;
    if (
            (addedValue < 0 && noteOctave > MIN_OCTAVE) ||
            (addedValue > 0 && noteOctave < MAX_OCTAVE)

            ) {
        FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue * NB_NOTE;
        FAT_tracker.allBlocks[block].notes[noteLine].note += addedValue;

        FAT_data_lastNoteWritten.freq = FAT_tracker.allBlocks[block].notes[noteLine].freq;
        FAT_data_lastNoteWritten.note = FAT_tracker.allBlocks[block].notes[noteLine].note;
    }
}

/**
 * Modifie le numéro d'un instrument pour une note donnée. 
 * @param block le numéro de block
 * @param noteLine le numéro de ligne de la note dans le block
 * @param addedValue la valeur à ajouter/retirer (1 ou -1 généralement voire 16/-16)
 */
void FAT_data_note_changeInstrument(u8 currentChannel, u8 block, u8 noteLine, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.allBlocks[block].notes[noteLine].instrument > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.allBlocks[block].notes[noteLine].instrument <= NB_MAX_INSTRUMENTS - addedValue)

            ) {
        FAT_tracker.allBlocks[block].notes[noteLine].instrument += addedValue;
        FAT_data_lastNoteWritten.instrument = FAT_tracker.allBlocks[block].notes[noteLine].instrument;

        FAT_data_initInstrumentIfNeeded(FAT_tracker.allBlocks[block].notes[noteLine].instrument,
                currentChannel);
    }
}

bool FAT_data_note_smartChangeInstrument(u8 currentChannel, u8 block, u8 noteLine) {
    u8 inst = 0;
    while (inst < NB_MAX_INSTRUMENTS) {
        if (FAT_data_isInstrumentFree(inst)) {
            FAT_tracker.allBlocks[block].notes[noteLine].instrument = inst;
            FAT_data_lastNoteWritten.instrument = inst;

            FAT_data_initInstrumentIfNeeded(inst,
                    currentChannel);

            return 1;
        }
        inst++;
    }

    return 0;
}

void FAT_data_instrument_changeType(u8 instrumentId, u8 newType) {
    FAT_tracker.allInstruments[instrumentId].type = newType;
}

void FAT_data_instrumentPulse_changeVolume(u8 instrumentId, s8 value) {
    u8 volume = FAT_tracker.allInstruments[instrumentId].envelope & 0x0f;
    u8 steptime = (FAT_tracker.allInstruments[instrumentId].envelope & 0xE0);
    u8 dir = (FAT_tracker.allInstruments[instrumentId].envelope & 0x10);
    if (
            (value < 0 && volume > (-value - 1)) ||
            (value > 0 && volume < INSTRUMENT_PULSE_VOLUME_MAX - value)

            ) {
        volume += value;
        FAT_tracker.allInstruments[instrumentId].envelope = steptime | dir | volume;
    }
}

void FAT_data_instrumentNoise_changeVolume(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeVolume(instrumentId, value);
}

void FAT_data_instrumentWave_changeVolume(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].volumeRatio > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].volumeRatio < INSTRUMENT_WAVE_VOLUME_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].volumeRatio += value;
    }
}

void FAT_data_instrumentPulse_changeEnvelopeDirection(u8 instrumentId, s8 value) {
    u8 volume = FAT_tracker.allInstruments[instrumentId].envelope & 0x0f;
    u8 steptime = (FAT_tracker.allInstruments[instrumentId].envelope & 0xE0);
    u8 dir = (FAT_tracker.allInstruments[instrumentId].envelope & 0x10) >> 4;
    if (value < 0) {
        dir = 0;
    } else if (value > 0) {
        dir = 1;
    }
    FAT_tracker.allInstruments[instrumentId].envelope = steptime | (dir << 4) | volume;
}

void FAT_data_instrumentNoise_changeEnvelopeDirection(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeEnvelopeDirection(instrumentId, value);
}

void FAT_data_instrumentPulse_changeSteptime(u8 instrumentId, s8 value) {
    u8 volume = FAT_tracker.allInstruments[instrumentId].envelope & 0x0f;
    u8 steptime = (FAT_tracker.allInstruments[instrumentId].envelope & 0xE0) >> 5;
    u8 dir = (FAT_tracker.allInstruments[instrumentId].envelope & 0x10);
    if (
            (value < 0 && steptime > (-value - 1)) ||
            (value > 0 && steptime < INSTRUMENT_PULSE_STEPTIME_MAX - value)

            ) {
        steptime += value;
        FAT_tracker.allInstruments[instrumentId].envelope = (steptime << 5) | dir | volume;
    }
}

void FAT_data_instrumentNoise_changeSteptime(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeSteptime(instrumentId, value);
}

void FAT_data_instrumentPulse_changeWaveduty(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep < INSTRUMENT_PULSE_WAVE_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep += value;
    }
}

void FAT_data_instrumentNoise_changePolystep(u8 instrumentId, s8 value) {
    if (value < 0) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep = 0;
    } else if (value > 0) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep = 1;
    }
}

void FAT_data_instrumentPulse_changeOutput(u8 instrumentId, s8 value) {

}

void FAT_data_instrumentNoise_changeOutput(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeOutput(instrumentId, value);
}

void FAT_data_instrumentPulse_changeSoundLength(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].soundlength > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].soundlength < INSTRUMENT_PULSE_LENGTH_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].soundlength += value;
    }
}

void FAT_data_instrumentNoise_changeSoundLength(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeSoundLength(instrumentId, value);
}

void FAT_data_instrumentWave_changeSoundLength(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].soundlength > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].soundlength < INSTRUMENT_WAVE_LENGTH_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].soundlength += value;
    }
}

void FAT_data_instrumentPulse_changeSweep(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].sweep > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].sweep < INSTRUMENT_PULSE_SWEEP_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].sweep += value;
    }
}

void FAT_data_instrumentPulse_changeLoopmode(u8 instrumentId, s8 value) {
    if (value < 0) {
        FAT_tracker.allInstruments[instrumentId].loopmode = 0;
    } else if (value > 0) {
        FAT_tracker.allInstruments[instrumentId].loopmode = 1;
    }
}

void FAT_data_instrumentWave_changeLoopmode(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}

void FAT_data_instrumentNoise_changeLoopmode(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}

void FAT_data_instrumentWave_changeVoice(u8 instrumentId, s8 value) {
    u8 voice = FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x1f;
    u8 bank = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x20);
    u8 bankMode = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x40);
    if (
            (value < 0 && voice > (-value - 1)) ||
            (value > 0 && voice < INSTRUMENT_WAVE_NB_VOICE - value)

            ) {
        voice += value;
        FAT_tracker.allInstruments[instrumentId].voiceAndBank = bankMode | bank | voice;
    }
}

void FAT_data_instrumentWave_changeBank(u8 instrumentId, s8 value) {
    u8 voice = FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x1f;
    u8 bank = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x20) >> 5;
    u8 bankMode = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x40);
    if (value < 0) {
        bank = 0;
    } else if (value > 0) {
        bank = 1;
    }
    FAT_tracker.allInstruments[instrumentId].voiceAndBank = bankMode | (bank << 5) | voice;
}

void FAT_data_instrumentWave_changeBankmode(u8 instrumentId, s8 value) {
    u8 voice = FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x1f;
    u8 bank = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x20);
    u8 bankMode = (FAT_tracker.allInstruments[instrumentId].voiceAndBank & 0x40) >> 6;
    if (value < 0) {
        bankMode = 0;
    } else if (value > 0) {
        bankMode = 1;
    }

    FAT_tracker.allInstruments[instrumentId].voiceAndBank = (bankMode << 6) | bank | voice;
}

void FAT_data_project_changeTempo(s8 addedValue) {
    if (
            (addedValue > 0 && FAT_tracker.tempo <= MAX_TEMPO - addedValue) ||
            (addedValue < 0 && FAT_tracker.tempo > (-addedValue - 1))) {
        FAT_tracker.tempo += addedValue;
    }
}

void FAT_data_project_changeTranspose(s8 addedValue) {
    if (
            (addedValue > 0 && FAT_tracker.transpose < MAX_TRANSPOSE - addedValue) ||
            (addedValue < 0 && FAT_tracker.transpose > (-addedValue - 1))) {
        FAT_tracker.transpose += addedValue;
    }
}

bool FAT_data_composer_isNoteEmpty(u8 line) {
    return FAT_tracker.composer.notes[line].freq == NULL_VALUE;
}

void FAT_data_composer_addDefaultNote(u8 line) {

    FAT_tracker.composer.notes[line].freq = FAT_data_lastNoteWritten.freq;

    FAT_tracker.composer.notes[line].instrument = FAT_data_lastNoteWritten.instrument;
    FAT_tracker.composer.notes[line].note = FAT_data_lastNoteWritten.note;
    //FAT_tracker.composer.notes[line].name = FAT_data_lastNoteWritten.name;
    //FAT_tracker.composer.notes[line].octave = FAT_data_lastNoteWritten.octave;

    FAT_data_initInstrumentIfNeeded(FAT_tracker.composer.notes[line].instrument, 0);

}

note* FAT_data_composer_getNote(u8 line) {
    return & (FAT_tracker.composer.notes[line]);
}

void FAT_data_composer_changeValue(u8 line, s8 addedValue) {
    u8 noteName = (FAT_tracker.composer.notes[line].note & 0xf0) >> 4;
    u8 noteOctave = FAT_tracker.composer.notes[line].note & 0x0f;
    if (
            (addedValue < 0 && noteName > 0) ||
            (addedValue > 0 && noteName < NB_NOTE - 1)

            ) {
        FAT_tracker.composer.notes[line].freq += addedValue;
        noteName += addedValue;
        FAT_tracker.composer.notes[line].note = (noteName << 4) + noteOctave;

        FAT_data_lastNoteWritten.freq = FAT_tracker.composer.notes[line].freq;
        FAT_data_lastNoteWritten.note = FAT_tracker.composer.notes[line].note;
    }
}

void FAT_data_composer_changeOctave(u8 line, s8 addedValue) {
    u8 noteOctave = FAT_tracker.composer.notes[line].note & 0x0f;
    if (
            (addedValue < 0 && noteOctave > MIN_OCTAVE) ||
            (addedValue > 0 && noteOctave < MAX_OCTAVE)

            ) {
        FAT_tracker.composer.notes[line].freq += addedValue * NB_NOTE;
        FAT_tracker.composer.notes[line].note += addedValue;

        FAT_data_lastNoteWritten.freq = FAT_tracker.composer.notes[line].freq;
        FAT_data_lastNoteWritten.note = FAT_tracker.composer.notes[line].note;
    }
}

bool FAT_data_composer_smartChangeInstrument(u8 line) {
    u8 inst = 0;
    while (inst < NB_MAX_INSTRUMENTS) {
        if (FAT_data_isInstrumentFree(inst)) {
            FAT_tracker.composer.notes[line].instrument = inst;
            FAT_data_lastNoteWritten.instrument = inst;

            FAT_data_initInstrumentIfNeeded(inst,
                    0);

            return 1;
        }
        inst++;
    }

    return 0;
}

void FAT_data_composer_changeInstrument(u8 line, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.composer.notes[line].instrument > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.composer.notes[line].instrument < NB_MAX_INSTRUMENTS - addedValue)

            ) {
        FAT_tracker.composer.notes[line].instrument += addedValue;
        FAT_data_lastNoteWritten.instrument = FAT_tracker.composer.notes[line].instrument;

        FAT_data_initInstrumentIfNeeded(FAT_tracker.composer.notes[line].instrument,
                0);
    }
}

void FAT_data_project_save() {
    memcpy(pSaveMemory, &FAT_tracker, sizeof (FAT_tracker));
    ham_DrawText(23, 16, "SAVED  !");
}

void FAT_data_project_load() {
    memcpy(&FAT_tracker, pSaveMemory, sizeof (FAT_tracker));
    ham_DrawText(23, 16, "LOADED !");
}

#endif	/* DATA_H */

