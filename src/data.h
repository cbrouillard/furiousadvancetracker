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
 * 
 * Ce fichier se contente de gérer les données en RAM. Voir filesystem.h pour les fonctions
 * d'écritures sur le fichier de sauvegarde ROM.
 */

#ifndef _DATA_H_
#define	_DATA_H_

/**
 * \def NB_MAX_SEQUENCES
 * \brief Nombre de séquences disponibles <b>au total</b> en mémoire. 0x80 = 128
 */
#define NB_MAX_SEQUENCES 64
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
 * \brief Définit le nombre maximal de voix disponibles. Les voix sont l'équivalent des 
 * synthé dans LSDJ.
 */
#define NB_MAX_VOICE 16

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
 * \brief Définit le nombre d'effet disponibles pour les notes.
 */
#define NB_NOTE_EFFECT 5
/**
 * \brief Définit le nombre d'effet disponibles pour les blocks.
 */
#define NB_BLOCK_EFFECT 1
/**
 * \brief Définit le nombre maximal de voix disponibles. Les voix sont l'équivalent des 
 * synthé dans LSDJ.
 */
#define NB_MAX_VOICE 16
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
 * \brief Valeur de volume maximum pour un instruemnt de type SAMPLE
 */
#define INSTRUMENT_SAMPLE_VOLUME_MAX 2
/**
 * \brief Valeur de vitesse maximale pour un sample. 1= vitesse normale, F = maximale. 0= stop
 */
#define INSTRUMENT_SAMPLE_SPEED_MAX 16
/**
 * \brief Valeur maximale pour le paramètre offset d'un instrument de type SAMPLE
 */
#define INSTRUMENT_SAMPLE_OFFSET_MAX 256
/**
 * \brief Tempo maximal.
 */
#define MAX_TEMPO 255
/**
 * \brief Valeur de transposition maximale.
 */
#define MAX_TRANSPOSE 256
/**
 * \brief Valeur maximum pour le paramètre "Key Repeat".
 */
#define MAX_KEYREPEAT 256
/**
 * \brief NULL_VALUE représente la valeur "interdite".
 * 
 * Au démarrage de l'appli, toutes les données dans FAT_tracker sont initialisées
 * avec NULL_VALUE.
 * <b>NE PAS TOUCHER !</b>
 */
#define NULL_VALUE 0xff

/**
 * \brief Tableau constant contenant toutes les notes sous formes de chaînes de caractères.
 */
const char* noteName[NB_NOTE] = {"C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "};
/**
 * \brief Tableau constant contenant tous les noms d'effets disponibles pour les notes.
 */
const char* noteEffectName[NB_NOTE_EFFECT] = {"HO", "KL", "OU", "SW", "VO"};
/**
 * \brief Mapping entre le nom de l'effet et son numéro dans la soundApi. Si le mapping 
 * a pour valeur NULL_VALUE, alors l'effet n'est pas géré par la soundAPI.
 */
const u8 noteEffectNum[NB_NOTE_EFFECT] = {NULL_VALUE, 0, 2, 1, 3};
/**
 * \brief Tableau constant contenant tous les noms d'effets disponibles pour les blocks.
 */
const char* blockEffectName[NB_BLOCK_EFFECT] = {"K "};

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
    // 0x 0000 000     0 
    // 0x numéro       1=note, 0=block
    u8 value; /*!< La valeur de la commande de 0 à FF. */
} effect;

/**
 * \brief Espace mémoire contenant le dernier effet écrit. Par défaut, l'effet est initialisé avec NULL_VALUE.
 */
effect ATTR_EWRAM FAT_data_lastEffectWritten;

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
note ATTR_EWRAM FAT_data_lastNoteWritten;
/**
 * \brief Espace mémoire dédié à la fonctionnalité simulator de l'écran INSTRUMENT.
 */
note ATTR_EWRAM FAT_data_simulator;
/**
 * \brief Presse-papier pour couper/coller une note.
 */
note ATTR_EWRAM FAT_data_noteClipboard;

/**
 * \struct COMPOSER
 * \brief Définit les données pour le compositeur (écran de composition).
 */
typedef struct COMPOSER {
    note notes[8]; /*!< Un compositeur contient un certain nombre de notes. */
    u8 channels[8]; /*!< Permet de surcharger le numéro de channel sur lequel jouer la note. Par défaut, celui de l'instrument assigné à la note. */
    u8 transpose; /*!< Définit la valeur de transposition pour le compositeur entier <b>NON IMPLEMENTE</b>. */
    u8 keyRepeat; /*!< Définit le temps à attendre entre chaque appui de note. */
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
u8 ATTR_EWRAM FAT_data_lastBlockWritten;
/**
 * \brief Presse-papier pour couper/coller des numéros de blocks.
 */
u8 ATTR_EWRAM FAT_data_blockClipboard;

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
    //effect effect[4]; 
} sequence;
/**
 * \brief Stocke le dernier numéro de séquence écrit.
 */
u8 ATTR_EWRAM FAT_data_lastSequenceWritten;
/**
 * \brief Presse-papier pour couper/coller des séquences.
 */
u8 ATTR_EWRAM FAT_data_sequenceClipboard;

/**
 * \struct CHANNEL
 * \brief Un channel représente une colonne de séquences: la GBA dispose de 6 channels.
 */
typedef struct CHANNEL {
    u8 sequences[NB_SEQUENCES_IN_ONE_CHANNEL]; /*!< Un channel possède sa collection de numéro de séquence.*/
} channel;

/**
 * \struc VOICE
 * \brief Une voix représente un synthé dans LSDJ. Une voice contient les paramètres qui feront 
 * sonner chaque instrument WAVE différement. Certaines voices sont définies en dur dans la soundApi.
 * Un instrument peut avoir 0 ou 1 voice attachée. Une voice peut être attachée à plusieurs instruments de type
 * WAVE.
 */
typedef struct VOICE {
    unsigned long value[8];
} voice;

/**
 * \struct INSTRUMENT
 * \brief L'instrument possède divers paramètres utiles pour modifier la sonorité d'une note: chaque note est 
 * attachée à un instrument.
 */
typedef struct INSTRUMENT {
    u8 type; /*!< Le type de l'instrument: PULSE1, PULSE2, WAVE, NOISE, SAMPLEA, SAMPLEB */
    u8 sweep; /*!< Valeur de "sweep". Le "sweep" n'est applicable que sur le channel 1. */
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
    u8 voiceAndBank; /*!< Ce paramètre agrége plusieurs autres paramètres dédiés aux instruments de type WAVE : "voice", "bank", "bankmode". */
    // voice -> voiceAndBank & 0x1f
    // bank -> (voiceAndBank & 0x20) >> 5
    // bankMode -> (voiceAndBank & 0x40) >> 6

    // 0x 0000   0000
    // 0x SAMPLE WAVE
    // wave -> volumeRatio & 0x0f
    // sample -> (volumeRatio & 0xf0) >> 4
    u8 volumeRatio; /*!< Stocke le volume pour un instrument de type WAVE. */
    u8 output; /*!< Stocke la sortie d'un son : gauche ou droite. 0 __ / 1 L_ / 2 R_ / 3 RL */

    u8 table; /*!< Numéro de table de commandes à appliquer pour chaque note assignée à cet instrument. */

    u8 kitNumber; /*!< Numéro du kit utilisé pour un instrument de type SAMPLE.*/
    u8 offset; /*!< Offset de départ pour la lecture d'un sample. 0 = début du sample, 0xff = fin. */
    // 0x 000 0    0000
    // 0x 000 LOOP SPEED
    // loop -> speedOrLooping >> 4
    // speed -> speedOrLooping & 0x0f
    u8 speedOrLooping; /*!< Contient les valeurs pour la vitesse et le mode looping d'un sample. */

    u8 voice; /*!< Lien vers une voix pour un instrument de type WAVE. de 0 a MAX_VOICE. NULL_VALUE = pas de lien.*/
} instrument;

/**
 * \struct LIVE
 * \brief Cette structure embarque toutes les données relatives au mode LIVE.
 */
typedef struct LIVE {
    bool liveMode; /*!< Le live mode permet de définir le mode de défilement des séquences: 0 = automatique 1 = manuel*/
    u8 volume[6]; /*!< Tableau des valeurs de volumes affectées à chaque canal.*/
    u8 transpose[6]; /*!< Tableau des valeurs de transpose affectées à chaque canal.*/
} livedata;

/**
 * \struct FAT
 * \brief Structure principale: stocke l'intégralité d'une track en cours de composition.
 * 
 * Cette structure définit le tracker: toutes les données sont référencés dans cette espace.
 */
typedef struct FAT {
    char songName[SONG_NAME_MAX_LETTERS]; /*!< Nom de la track en cours de composition. */
    u8 nbWork; /*!< Stocke le nombre d'enregistrements pour ce projet. */
    u8 tempo; /*!< Tempo pour la track en cours de composition. */
    u8 transpose; /*!< Valeur de transposition pour la track en cours de composition. */
    u8 keyRepeat; /*!< Valeur permettant de régler la vélocité de l'interface. FF = lent 00 = rapide */
    u8 previewEnable; /*!< Paramètre pour l'activation de la preview dans l'écran NOTE. */
    channel channels[6]; /*!< Définition des channels: la GBA en dispose de 6. */
    sequence allSequences [NB_MAX_SEQUENCES]; /*!< Tableau (physique) contenant toutes les séquence. */
    block allBlocks [NB_MAX_BLOCKS]; /*!< Tableau (physique) contenant tous les blocks. */
    instrument allInstruments[NB_MAX_INSTRUMENTS]; /*!< Tableau (physique) contenant tous les instruments. */
    composer composer; /*!< Données pour l'écran de composition. */
    voice voices[NB_MAX_VOICE]; /*!< Les voix disponibles. Une voix = un synthé LSDJ. */
    table tables[NB_MAX_TABLES]; /*!< Tableau (physique) contenant toutes les tables. */
    livedata liveData;
} tracker;

/**
 * \struct PLAYERBUFFER
 * \brief Structure pour définir un buffer lors de la lecture du son.
 */
typedef struct PLAYERBUFFER {
    note* note;
    u8 transpose;
    bool haveToPlay;
} bufferPlayer;

/**
 * \brief Contient toutes les données déjà instanciées.
 * 
 * C'est cette variable qui est utilisée comme référence pour compression lors de la sauvegarde
 * et vice versa pour le chargement. 
 */
tracker ATTR_ALIGNED(8) ATTR_EWRAM FAT_tracker;

/**
 * \brief Espace mémoire déjà alloué (d'une vingtaine de kilo) permettant de servir de buffer pour
 * la compression d'une track avant enregistrement.
 *
 * C'est cette variable qui est utilisée (écrite sur la ram) lors de la sauvegarde
 * et vice versa pour le chargement.
 */
tracker ATTR_ALIGNED(8) ATTR_EWRAM FAT_compressed_tracker;

/**
 * \brief Stocke le numéro de la prochaine séquence disponible.
 */
u8 ATTR_EWRAM FAT_nextAvailableSequenceId = 0;
/**
 * \brief Stocke le numéro du prochain block disponible.
 */
u8 ATTR_EWRAM FAT_nextAvailableBlockId = 0;
/**
 * \brief Stocke le numéro du prochain instrument disponible.
 */
u8 ATTR_EWRAM FAT_nextAvailableInstrumentId = 0;
/**
 * \brief Stocke le dernier numéro d'instrument utilisé.
 */
u8 ATTR_EWRAM FAT_lastUsedInstrumentId = 0;

/** \brief Prototype. Définit dans player.h. */
void FAT_player_playNote(note* note, u8 channel);

/**
 * \brief Initialise les données du tracker. Utile lors de l'allumage de la console.
 */
void FAT_data_initData() {

    memset(&FAT_tracker, NULL_VALUE, sizeof (tracker));

    FAT_tracker.tempo = 128;
    FAT_tracker.transpose = 0;
    FAT_tracker.keyRepeat = 10;
    FAT_tracker.nbWork = 0;
    strcpy(FAT_tracker.songName, "FATSONG!\0");

    // init des variables du composer
    FAT_tracker.composer.transpose = 0;
    FAT_tracker.composer.keyRepeat = 0;

    // note par défaut
    FAT_data_lastNoteWritten.freq = 0;
    FAT_data_lastNoteWritten.instrument = 0;
    FAT_data_lastNoteWritten.note = 0x03;
    FAT_data_lastNoteWritten.effect.name = NULL_VALUE;
    FAT_data_simulator.freq = 0;
    FAT_data_simulator.instrument = 0;
    FAT_data_simulator.note = 0x03;
    FAT_data_simulator.effect.name = NULL_VALUE;

    // block par défaut
    FAT_data_lastBlockWritten = 0;
    FAT_data_lastSequenceWritten = 0;

    FAT_data_sequenceClipboard = NULL_VALUE;
    FAT_data_blockClipboard = NULL_VALUE;
    memset(&FAT_data_noteClipboard, NULL_VALUE, sizeof (note));
    memset(&FAT_data_lastEffectWritten, NULL_VALUE, sizeof (effect));

    memset(&FAT_tracker.liveData.volume, 0xff, sizeof (u8)*6);
    memset(&FAT_tracker.liveData.transpose, 0, sizeof (u8)*6);
}

/**
 * \brief Permet de savoir si la preview est activé lors de la pose d'une note. 
 * 
 * @return 1 si activé, 0 sinon
 */
bool FAT_data_isPreviewEnabled() {
    return FAT_tracker.previewEnable != 0;
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
 * \brief Coupe un block depuis une séquence donnée. Le numéro de block est stocké 
 * dans le presse-papier.
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

/**
 * \brief Colle un block depuis le presse-papier dans une séquence donnée.
 * 
 * @param sequence le numéro de la séquence de 0 à NB_MAX_SEQUENCES
 * @param blockLine le numéro de ligne du block à effacer dans la séquence
 */
void FAT_data_pasteBlock(u8 sequence, u8 blockLine) {
    FAT_tracker.allSequences[sequence].blocks[blockLine] = FAT_data_blockClipboard;
}

/**
 * \brief Clone le block: change le numéro du block pointé.
 * 
 * Cette méthode permet de changer le numéro d'un block tout en conservant son
 * contenu. Le nouveau numéro est le premier numéro de block vide disponible.
 * 
 * @param sequence le numéro de la séquence de 0 à NB_MAX_SEQUENCES
 * @param blockLine le numéro de ligne du block à effacer dans la séquence
 */
void FAT_data_cloneBlock(u8 sequence, u8 blockLine) {
    u8 blockIdTemp = FAT_tracker.allSequences[sequence].blocks[blockLine];
    if (FAT_data_smartAllocateBlock(sequence, blockLine) && blockIdTemp != NULL_VALUE) {
        // copie de tout le contenu de la séquence dans la nouvelle
        memcpy(& (FAT_tracker.allBlocks[FAT_tracker.allSequences[sequence].blocks[blockLine]]),
                & (FAT_tracker.allBlocks[blockIdTemp]), sizeof (block));
    }
}

/**
 * \brief Colle un block depuis le presse-papier en changeant le numéro.
 * 
 * Le nouveau numéro est le premier numéro de block vide disponible.
 * 
 * @param sequence
 * @param blockLine
 */
void FAT_data_pasteBlockWithNewNumber(u8 sequence, u8 blockLine) {
    if (FAT_data_smartAllocateBlock(sequence, blockLine) && FAT_data_blockClipboard != NULL_VALUE) {
        // copie de tout le contenu de la séquence dans la nouvelle
        memcpy(& (FAT_tracker.allBlocks[FAT_tracker.allSequences[sequence].blocks[blockLine]]),
                & (FAT_tracker.allBlocks[FAT_data_blockClipboard]), sizeof (block));
    }
}

/**
 * \brief Supprime la valeur de transpose pour un block désigné.
 * 
 * @param sequence l'id de la séquence
 * @param blockLine le numéro de ligne du block dans la séquence
 */
void FAT_data_removeBlockTranspose(u8 sequence, u8 blockLine) {
    FAT_tracker.allSequences[sequence].transpose[blockLine] = NULL_VALUE;
}

/**
 * \brief Coupe une note donnée dans un block et la place dans le presse-papier.
 * 
 * Attention cette méthode EFFACE POUR DE VRAI la note ! Elle est cependant
 * copiée dans le presse-papier avant suppression.
 * @param block le numéro de block
 * @param noteLine le numéro de ligne de la note dans le block
 */
void FAT_data_cutNote(u8 block, u8 noteLine) {
    memcpy(&FAT_data_noteClipboard, &(FAT_tracker.allBlocks[block].notes[noteLine]), sizeof (note));
    FAT_tracker.allBlocks[block].notes[noteLine].freq = NULL_VALUE;
}

/**
 * \brief Coupe une note donnée dans le composer et la place dans le presse-papier.
 * 
 * Attention cette méthode EFFACE POUR DE VRAI la note ! Elle est cependant
 * copiée dans le presse-papier avant suppression.
 * @param line le numéro de ligne de la note dans le composer
 */
void FAT_data_composer_cutNote(u8 line) {
    memcpy(&FAT_data_noteClipboard, &(FAT_tracker.composer.notes[line]), sizeof (note));
    FAT_tracker.composer.notes[line].freq = NULL_VALUE;
}

/**
 * \brief Colle une note depuis le presse-papier dans un block.
 * 
 * @param block le numéro de block
 * @param noteLine la ligne de la note dans le block
 */
void FAT_data_pasteNote(u8 block, u8 noteLine) {
    memcpy(&(FAT_tracker.allBlocks[block].notes[noteLine]), &FAT_data_noteClipboard, sizeof (note));
}

/**
 * \brief Colle une note depuis le presse-papier dans le composer.
 *  
 * @param line le numéro de ligne de la note dans le composer
 */
void FAT_data_composer_pasteNote(u8 line) {
    memcpy(&(FAT_tracker.composer.notes[line]), &FAT_data_noteClipboard, sizeof (note));
}

/**
 * \brief Permet de savoir si une séquence est allouable (séquence vide). 
 * 
 * @param channelId le channel de 0 à 5
 * @param line le numéro de ligne de la séquence dans le tableau SONG
 * @return vrai si la séquence est disponible (non déjà utilisée)
 */
bool FAT_data_isSequenceAllocatable(u8 channelId, u8 line) {
    return FAT_tracker.channels[channelId].sequences[line] == NULL_VALUE;
}

/**
 * \brief Permet de savoir si un block est allouable (block vide)
 * 
 * @param sequence le numéro de séquence
 * @param blockLine le numéro de ligne du block dans la séquence
 * @return vrai si le block est disponible (non déjà utilisé)
 */
bool FAT_data_isBlockAllocatable(u8 sequence, u8 blockLine) {
    return FAT_tracker.allSequences[sequence].blocks[blockLine] == NULL_VALUE;
}

/**
 * \brief Cette méthode indique si une note est déjà présente un emplacement donné.
 * 
 * @param block le numéro de block concerné
 * @param noteLine le numéro de ligne de la note dans le block
 * @return vrai si aucune note n'est présente à cet endroit.
 */
bool FAT_data_isNoteEmpty(u8 block, u8 noteLine) {
    return FAT_tracker.allBlocks[block].notes[noteLine].freq == NULL_VALUE;
}

/**
 * \brief Retourne un id séquence. 
 * 
 * @param channelId le canal
 * @param sequenceLine le numéro de ligne de la séquence dans le tableau SONG
 * @return l'id de la séquence de 0 à NB_MAX_SEQUENCES ou NULL_VALUE si la séquence n'est pas allouée
 */
u8 FAT_data_getSequence(u8 channelId, u8 sequenceLine) {
    return FAT_tracker.channels[channelId].sequences[sequenceLine];
}

/**
 * \brief Retourne un id block.
 * 
 * @param sequence le numéro de séquence
 * @param blockLine le numéro de ligne du block dans la séquence
 * @return l'id du block de 0 à NB_MAX_BLOCKS ou NULL_VALUE si le block n'est pas alloué
 */
u8 FAT_data_getBlock(u8 sequence, u8 blockLine) {
    return FAT_tracker.allSequences[sequence].blocks[blockLine];
}

/**
 * \brief Retourne un pointeur sur une variable de type "note". Ce pointeur donne 
 * accès à toute les données présentes dans une note. 
 * 
 * Cf NOTE
 * 
 * @param block le numéro du block
 * @param noteLine le numéro de la ligne dans le block
 * @return le pointeur sur une variable note
 */
note* FAT_data_getNote(u8 block, u8 noteLine) {
    return &FAT_tracker.allBlocks[block].notes[noteLine];
}

/**
 * \brief Remplit automatiquement un id séquence avec la valeur d'un compteur.
 * 
 * Attention, pour le moment cette méthode est stupide et ne vérifie pas si 
 * la valeur du compteur ne correspond pas déjà à une séquence déjà allouée (manuellement)
 * 
 * @param channelId le canal
 * @param line le numéro de ligne de la séquence dans le tableau SONG
 */
void FAT_data_allocateSequenceToNextAvailableId(u8 channelId, u8 line) {
    if (FAT_nextAvailableSequenceId < NB_MAX_SEQUENCES) {
        FAT_tracker.channels[channelId].sequences[line] = FAT_nextAvailableSequenceId;
        FAT_nextAvailableSequenceId++;
    }
}

/**
 * \brief Alloue une séquence.
 * 
 * Si la séquence est allouable, alors on y place par défaut le dernier numéro
 * de séquence écrit.
 * 
 * @param channelId le numéro de channel (0 à 5)
 * @param line le numéro de ligne de la séquence dans le tableau
 * @return 1 si la séquence a été allouée, 0 si échec
 */
bool FAT_data_allocateSequence(u8 channelId, u8 line) {
    if (FAT_data_isSequenceAllocatable(channelId, line)) {
        FAT_tracker.channels[channelId].sequences[line] = FAT_data_lastSequenceWritten;
        return 1;
    }

    return 0;
}

/**
 * \brief Remplit automatiquement un id block avec la valeur d'un compteur.
 * 
 * Attention, pour le moment cette méthode est stupide et ne vérifie pas si 
 * la valeur du compteur ne correspond pas déjà à un block déjà alloué (manuellement) 
 *
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
 * \brief Méthode intelligente pour l'allocation d'un block dans une séquence.
 * 
 * - si le block est vide, alors on pose le même block que le dernier posé
 * - si le block n'est pas vide alors on ne fait rien (on pourra afficher un message plus tard)
 *
 * @param sequence le numéro de séquence
 * @param blockLine le numéro de ligne du block dans la séquence
 * @return 1 si un nouveau block a été écrit, 0 si rien n'a été fait
 */
bool FAT_data_allocateBlock(u8 sequence, u8 blockLine) {
    if (FAT_data_isBlockAllocatable(sequence, blockLine)) {
        FAT_tracker.allSequences[sequence].blocks[blockLine] = FAT_data_lastBlockWritten;
        return 1;
    }

    return 0;
}

/**
 * \brief Indique si un block est vide ou pas.
 *  
 * @param blockId l'id de block à vérifier
 * @return 1 si vide, 0 si au moins une note est trouvée
 */
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

/**
 * \brief Indique si le paramètre de transpose d'un block est renseigné.
 *  
 * @param sequence le numéro de séquence
 * @param line la ligne du block dans la séquence
 * @return 1 si vide, 0 si initialisé
 */
bool FAT_data_block_isTransposeEmpty(u8 sequence, u8 line) {
    return FAT_tracker.allSequences[sequence].transpose[line] == NULL_VALUE;
}

/**
 * \brief Donne la valeur du paramètre transpose pour un block.
 * 
 * @param sequence le numéro de séquence
 * @param line la ligne du block dans la séquence
 * @return la valeur du parametre transpose pour le block désigné
 */
u8 FAT_data_block_getTranspose(u8 sequence, u8 line) {
    return FAT_tracker.allSequences[sequence].transpose[line];
}

/**
 * \brief Alloue une valeur de paramètre pour la transposition d'un block: 0 par défaut.
 * 
 * @param sequence le numéro de séquence concernée
 * @param line le numéro de ligne du block dans la séquence
 */
void FAT_data_block_allocateTranspose(u8 sequence, u8 line) {
    if (FAT_data_block_isTransposeEmpty(sequence, line)) {
        FAT_tracker.allSequences[sequence].transpose[line] = 0;
    }
}

/**
 * \brief Permet de savoir si un séquence est vide ou non (sans block).
 *  
 * @param sequenceId l'id de la séquence à tester
 * @return 0 si la séquence n'est pas vide, 1 si elle est vide
 */
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

/**
 * \brief Permet de savoir si un instrument est disponible (non initialisé).
 * 
 * @param inst le numéro d'instrument à tester
 * @return 1 si l'instrument est disponible, 0 sinon
 */
bool FAT_data_isInstrumentFree(u8 inst) {
    return FAT_tracker.allInstruments[inst].sweep == NULL_VALUE;
}

/**
 * \brief Retourne le type d'instrument (le channel sur lequel il sera spécialisé).
 *  
 * @param inst l'id de l'instrument
 * @return le type d'instrument demandé
 */
u8 FAT_data_getInstrumentType(u8 inst) {
    return FAT_tracker.allInstruments[inst].type;
}

/**
 * \brief Méthode intelligente permettant d'allouer un nouveau numéro de block vide.
 * 
 * @param sequence le numéro de séquence
 * @param blockLine le numéro de ligne du block
 * @return 1 si le block a été alloué, 0 sinon
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

/**
 * \brief Méthode intelligente permettant d'allouer une nouveau numéro de séquence.
 *  
 * @param channelId le numéro du channel (0 à 5)
 * @param line le numéro de ligne sur laquelle écrire la séquence
 * @return 1 si la séquence a été allouée, 0 sinon
 */
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
 * \brief Ajoute la note par défaut sur une ligne dans un block.
 * 
 * @param block le numéro de block
 * @param noteLine le numéro de ligne de la note à ajouter
 */
void FAT_data_addDefaultNote(u8 block, u8 noteLine, u8 channel) {
    FAT_data_initInstrumentIfNeeded(FAT_data_lastNoteWritten.instrument, channel);

    if (channel >= INSTRUMENT_TYPE_SAMPLEA) {
        u8 nbAvailableSamples = snd_countSamplesInKitById(FAT_tracker.allInstruments[FAT_data_lastNoteWritten.instrument].kitNumber);
        if (FAT_data_lastNoteWritten.freq >= nbAvailableSamples) {
            FAT_data_lastNoteWritten.freq = nbAvailableSamples - 1;
        }
    }

    FAT_tracker.allBlocks[block].notes[noteLine].freq = FAT_data_lastNoteWritten.freq;
    FAT_tracker.allBlocks[block].notes[noteLine].instrument = FAT_data_lastNoteWritten.instrument;
    FAT_tracker.allBlocks[block].notes[noteLine].note = FAT_data_lastNoteWritten.note;

}

/**
 * \brief Initialise un instrument avec des valeurs par défaut uniquement si cet instrument
 * est nouveau et n'a jamais été initialisé auparavant. 
 * 
 * Attention, pour déterminer si un instru doit être initialisé, cette méthode
 * se sert d'une donnée (sweep) et teste si celle-ci est égale à NULL_VALUE. 
 * @param instId l'id de l'instrument à initialiser
 */
void FAT_data_initInstrumentIfNeeded(u8 instId, u8 channel) {
    if (FAT_tracker.allInstruments[instId].sweep == NULL_VALUE) {
        FAT_tracker.allInstruments[instId].sweep = 0;
        FAT_tracker.allInstruments[instId].envelope = 0x0a;
        FAT_tracker.allInstruments[instId].volumeRatio = 0x13;
        FAT_tracker.allInstruments[instId].wavedutyOrPolynomialStep = 0;
        FAT_tracker.allInstruments[instId].soundlength = 0;
        FAT_tracker.allInstruments[instId].loopmode = 0;
        FAT_tracker.allInstruments[instId].voiceAndBank = 0;
        FAT_tracker.allInstruments[instId].output = 3; //LR
        FAT_tracker.allInstruments[instId].voice = NULL_VALUE;

        FAT_tracker.allInstruments[instId].kitNumber = 0;
        FAT_tracker.allInstruments[instId].offset = 0;
        FAT_tracker.allInstruments[instId].speedOrLooping = 0x01;

        FAT_tracker.allInstruments[instId].table = 0;

        FAT_tracker.allInstruments[instId].type = channel;
    }
}

/**
 * \brief Modifie le numéro d'une séquence. 
 * 
 * Cette méthode ajoute la valeur de "addedValue". Passer +1 comme valeur ajoute, -1 pour retirer.
 * 
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

/**
 * \brief Modifie la valeur de transposition pour un block donné.
 *  
 * @param sequence le numéro de séquence
 * @param line le numéro de ligne du block dans la séquence
 * @param addedValue la valeur à ajouter/retrancher (+1 ajouter, -1 retrancher)
 */
void FAT_data_block_changeTransposeValue(u8 sequence, u8 line, s8 addedValue) {
    //    if (
    //            (addedValue < 0 && FAT_tracker.allBlocks[blockId].transpose > (-addedValue - 1)) ||
    //            (addedValue > 0 && FAT_tracker.allBlocks[blockId].transpose < NB_MAX_TRANSPOSE - addedValue)
    //            ) {
    FAT_tracker.allSequences[sequence].transpose[line] += addedValue;
    //}
}

/**
 * \brief Modifie le numéro d'un block. 
 * 
 * Cette méthode ajoute la valeur de "addedValue". Passer +1 comme valeur ajoute, -1 pour retirer. 
 * 
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
 * \brief Permet de déterminer si un effet est assigné à un block ou pas.
 *  
 * @param sequence l'id de la séquence dans lequel le block est installé
 * @param blockLine 
 */
bool FAT_data_block_isEffectEmpty(u8 sequence, u8 blockLine) {
    //return FAT_tracker.allSequences[sequence].effect[blockLine].name == NULL_VALUE;
    return 1;
}

/**
 * \brief Retourne un pointeur sur un effet définit pour un block dans une séquence.
 *  
 * @param sequence le numéro de séquence concernée
 * @param line la ligne du block dans la séquence
 * @return un pointeur sur un objet EFFECT
 */
effect* FAT_data_block_getEffect(u8 sequence, u8 line) {
    //return &(FAT_tracker.allSequences[sequence].effect[line]);
    return 0;
}

/**
 * \brief Joue un apercu d'une note insérée dans un block.
 *  
 * @param block l'id du block
 * @param line le numéro de ligne de la note dans le block
 */
void FAT_data_note_previewNote(u8 block, u8 line) {
    // copie en mémoire de l'instruemnt -> on doit modifier certaines données pour la preview comme la durée.
    u8 instId = FAT_tracker.allBlocks[block].notes[line].instrument;

    // se souvenir des vrais paramètres
    u8 mem_loopMode = FAT_tracker.allInstruments[instId].loopmode;
    u8 mem_soundLength = FAT_tracker.allInstruments[instId].soundlength;

    FAT_tracker.allInstruments[instId].loopmode = 1;
    FAT_tracker.allInstruments[instId].soundlength = 0x20;

    FAT_player_playNote(&FAT_tracker.allBlocks[block].notes[line], FAT_tracker.allInstruments[instId].type);

    FAT_tracker.allInstruments[instId].loopmode = mem_loopMode;
    FAT_tracker.allInstruments[instId].soundlength = mem_soundLength;
}

/**
 * \brief Modifie la valeur d'une note. 
 * 
 * Cette méthode permet de changer l'intitulé de la not et donc sa fréquence.
 * ex. si j'ai un C 3 et que j'utilise cette méthode avec "addedValue=1" 
 * alors ma note sera modifiée en "C#3".
 * 
 * @param channel le numéro de chan en cours d'édition
 * @param block le numéro de block
 * @param noteLine le numéro de ligne de la note dans le block
 * @param addedValue la valeur à ajouter/retirer (1 ou -1 généralement)
 */
void FAT_data_note_changeValue(u8 channel, u8 block, u8 noteLine, s8 addedValue) {
    u8 noteName = FAT_tracker.allBlocks[block].notes[noteLine].note >> 4;
    u8 noteOctave = FAT_tracker.allBlocks[block].notes[noteLine].note & 0x0f;

    instrument* inst = &(FAT_tracker.allInstruments[FAT_tracker.allBlocks[block].notes[noteLine].instrument]);
    if (channel >= INSTRUMENT_TYPE_SAMPLEA) {
        u8 nbMaxSample = snd_countSamplesInKitById(inst->kitNumber);
        //if (FAT_tracker.allBlocks[block].notes[noteLine].freq >= nbMaxSample){
        //    FAT_tracker.allBlocks[block].notes[noteLine].freq = nbMaxSample;
        /*< \todo changer l'intitulé noteName et noteOctave pour affichage correct. */
        //}
        if ((addedValue > 0 && FAT_tracker.allBlocks[block].notes[noteLine].freq < nbMaxSample - 1) ||
                (addedValue < 0 && FAT_tracker.allBlocks[block].notes[noteLine].freq > 0)) {
            FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue;
        }
    } else {

        if (addedValue < 0) {

            if (noteName > 0) {

                noteName += addedValue;

            } else if (noteOctave > MIN_OCTAVE) {
                // on change d'octave si possible et on passe à la note maximale.
                // C 4 passe à B 3
                noteName = NB_NOTE - 1;
                noteOctave -= 1;
            }

            if (FAT_tracker.allBlocks[block].notes[noteLine].freq > 0) {
                FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue;
            }

        } else if (addedValue > 0) {
            if (noteName < NB_NOTE - 1) {

                noteName += addedValue;

            } else if (noteOctave < MAX_OCTAVE) {
                // on passe à l'octave suivant 
                // B 4 -> C 5
                noteName = 0;
                noteOctave += 1;
            }

            if (FAT_tracker.allBlocks[block].notes[noteLine].freq < NB_FREQUENCES) {
                FAT_tracker.allBlocks[block].notes[noteLine].freq += addedValue;
            }
        }
    }

    FAT_tracker.allBlocks[block].notes[noteLine].note = (noteName << 4) + noteOctave;

    FAT_data_lastNoteWritten.freq = FAT_tracker.allBlocks[block].notes[noteLine].freq;
    FAT_data_lastNoteWritten.note = FAT_tracker.allBlocks[block].notes[noteLine].note;

};

/**
 * \brief Modifie l'octave d'une note.
 * 
 * Cette méthode permet de changer l'octave de la note et donc sa fréquence.
 * ex. si j'ai un C 3 et que j'utilise cette méthode avec "addedValue=1" 
 * alors ma note sera modifiée en "C 4".
 * 
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
 * \brief Modifie le numéro d'un instrument pour une note donnée. 
 * 
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

/**
 * \brief Modifie le nom d'un effet assigné à une note.
 *  
 * @param block le numéro de block dans lequel la note est inscrite
 * @param noteLine le numéro de ligne de la note dans le block
 * @param addedValue la valeur à ajouter/retrancher
 */
void FAT_data_note_changeEffectName(u8 block, u8 line, s8 addedValue) {
    u8 effectName = (FAT_tracker.allBlocks[block].notes[line].effect.name & 0xfe) >> 1;
    if (
            (addedValue < 0 && effectName > (-addedValue - 1)) ||
            (addedValue > 0 && effectName < NB_NOTE_EFFECT - addedValue)

            ) {
        effectName += addedValue;
        FAT_tracker.allBlocks[block].notes[line].effect.name = (effectName << 1) | 1;
        FAT_data_lastEffectWritten.name = FAT_tracker.allBlocks[block].notes[line].effect.name;
    }
}

/**
 * \brief Modifie la valeur d'un effet assigné à une note.
 *  
 * @param block le numéro de block dans lequel la note est inscrite
 * @param noteLine le numéro de ligne de la note dans le block
 * @param addedValue la valeur à ajouter/retrancher
 */
void FAT_data_note_changeEffectValue(u8 block, u8 line, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.allBlocks[block].notes[line].effect.value > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.allBlocks[block].notes[line].effect.value <= 0xff - addedValue)

            ) {
        FAT_tracker.allBlocks[block].notes[line].effect.value += addedValue;
        FAT_data_lastEffectWritten.value = FAT_tracker.allBlocks[block].notes[line].effect.value;
    }
}

/**
 * \brief Colle un effet préalablement stocké en mémoire.
 * 
 * @param block le numéro de block dans lequel la note est inscrite
 * @param line le numéro de ligne de la note
 */
void FAT_data_note_pasteEffect(u8 block, u8 line) {
    FAT_tracker.allBlocks[block].notes[line].effect.name = ((FAT_data_lastEffectWritten.name & 0xfe) >> 1) | 1;
    FAT_tracker.allBlocks[block].notes[line].effect.value = FAT_data_lastEffectWritten.value;
}

/**
 * \brief Coupe un effet et le stocke dans une mémoire spéciale.
 * 
 * @param block le numéro de block dans lequel la note est inscrite
 * @param line le numéro de ligne de la note
 */
void FAT_data_note_cutEffect(u8 block, u8 line) {
    FAT_data_lastEffectWritten.name = FAT_tracker.allBlocks[block].notes[line].effect.name;
    FAT_data_lastEffectWritten.value = FAT_tracker.allBlocks[block].notes[line].effect.value;
    memset(&FAT_tracker.allBlocks[block].notes[line].effect, NULL_VALUE, sizeof (effect));
}

/**
 * \brief Cette méthode permet de changer le numéro d'un instrument alloué à une note par un nouveau disponible.
 * 
 * @param currentChannel le channel (de 0 à 5) utile pour l'initialisation de l'instrument
 * @param block le numéro de block
 * @param noteLine le numéro de ligne de la note dans le block
 * @return 1 si un nouveau numéro a été trouvé, 0 sinon
 */
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

/**
 * \brief Permet de déterminer si un effet a été assigné à la note.
 *  
 * @param block l'id du block dans lequel la note est inscrite
 * @param line le numéro de ligne de la note
 * @return 1 si l'effet est vide, 0 sinon
 */
bool FAT_data_note_isEffectEmpty(u8 block, u8 line) {
    return FAT_tracker.allBlocks[block].notes[line].effect.name == NULL_VALUE;
}

/**
 * \brief Récupère l'effet actuellement assigné à une note.
 * 
 * @param block l'id du block dans lequel la note est inscrite
 * @param line le numéro de ligne de la note
 * @return un pointeur sur un objet EFFECT
 */
effect* FAT_data_note_getEffect(u8 block, u8 line) {
    return &(FAT_tracker.allBlocks[block].notes[line].effect);
}

/**
 * \brief Inscrit l'effet par défaut et l'assigne à la note voulue.
 *  
 * @param block l'id du block concerné
 * @param line le numéro de ligne de la note dans le block
 */
void FAT_data_note_addDefaultEffect(u8 block, u8 line) {
    if (FAT_data_lastEffectWritten.name == NULL_VALUE) {
        FAT_data_lastEffectWritten.name = 1; // 1 = type note et numéro 0 dans le tableau
        FAT_data_lastEffectWritten.value = 0;
    }

    FAT_tracker.allBlocks[block].notes[line].effect.name = FAT_data_lastEffectWritten.name;
    FAT_tracker.allBlocks[block].notes[line].effect.value = FAT_data_lastEffectWritten.value;
}

/**
 * \brief Change le type d'un instrument.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param newType le nouveau type de l'instrument PULSE1, PULSE2, WAVE, NOISE, SAMPLEA, SAMPLEB
 */
void FAT_data_instrument_changeType(u8 instrumentId, u8 newType) {
    FAT_tracker.allInstruments[instrumentId].type = newType;
}

/**
 * \brief Change la valeur de la note dans le simulator tout instrument confondus.
 *  
 * @param addedValue la valeur à ajouter/retrancher
 */
void FAT_data_instrument_changeSimulator(u8 inst, s8 addedValue) {
    FAT_data_simulator.instrument = inst;

    u8 noteName = (FAT_data_simulator.note & 0xf0) >> 4;
    u8 noteOctave = FAT_data_simulator.note & 0x0f;
    if (addedValue == 16 || addedValue == -16) {
        // octave
        if (addedValue == 16) addedValue = 1;
        if (addedValue == -16) addedValue = -1;
        if (
                (addedValue < 0 && noteOctave > MIN_OCTAVE) ||
                (addedValue > 0 && noteOctave < MAX_OCTAVE)

                ) {
            FAT_data_simulator.freq += addedValue * NB_NOTE;
            FAT_data_simulator.note += addedValue;
        }
    } else {
        // note
        if (
                (addedValue < 0 && noteName > 0) ||
                (addedValue > 0 && noteName < NB_NOTE - 1)

                ) {
            FAT_data_simulator.freq += addedValue;
            noteName += addedValue;
            FAT_data_simulator.note = (noteName << 4) + noteOctave;
        }
    }
}

/**
 * \brief Joue la note présente dans le simulator en fonction de l'instrument en cours d'édition.
 *  
 * @param inst l'instrument a utiliser
 */
void FAT_data_instrument_playSimulator(u8 inst) {
    u8 mem_loopMode = FAT_tracker.allInstruments[inst].loopmode;
    FAT_tracker.allInstruments[inst].loopmode = 1;
    FAT_player_playNote(&FAT_data_simulator, FAT_tracker.allInstruments[inst].type);
    FAT_tracker.allInstruments[inst].loopmode = mem_loopMode;
}

/**
 * \brief Permet de changer le volume d'un instrumement de type PULSE.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value valeur à ajouter ou retrancher
 */
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

/**
 * \brief Change le volume pour un instrument de type NOISE.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentNoise_changeVolume(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeVolume(instrumentId, value);
}

/**
 * \brief Change le volume pour un instrument de type WAVE.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentWave_changeVolume(u8 instrumentId, s8 value) {
    u8 volumeRatio = FAT_tracker.allInstruments[instrumentId].volumeRatio & 0x0f;
    u8 sampleRatio = (FAT_tracker.allInstruments[instrumentId].volumeRatio & 0xf0);
    if (
            (value < 0 && volumeRatio > (-value - 1)) ||
            (value > 0 && volumeRatio < INSTRUMENT_WAVE_VOLUME_MAX - value)

            ) {
        volumeRatio += value;
        FAT_tracker.allInstruments[instrumentId].volumeRatio = sampleRatio | volumeRatio;
    }
}

/**
 * \brief Change le numéro de kit affecté
 * 
 * @param instrumentId
 * @param addedValue
 */
void FAT_data_instrumentSample_changeKitNumber(u8 instrumentId, s8 value) {
    u8 kitNumber = FAT_tracker.allInstruments[instrumentId].kitNumber;
    u8 nbKits = snd_countAvailableKits();

    if (
            (value < 0 && kitNumber > (-value - 1)) ||
            (value > 0 && kitNumber < nbKits - value)

            ) {
        kitNumber += value;
        FAT_tracker.allInstruments[instrumentId].kitNumber = kitNumber;
    }

}

/**
 * \brief Change le volume pour un instrument de type SAMPLE.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentSample_changeVolume(u8 instrumentId, s8 value) {
    u8 volumeRatio = (FAT_tracker.allInstruments[instrumentId].volumeRatio & 0xf0) >> 4;
    u8 waveRatio = FAT_tracker.allInstruments[instrumentId].volumeRatio & 0x0f;

    if (
            (value < 0 && volumeRatio > (-value - 1)) ||
            (value > 0 && volumeRatio < INSTRUMENT_SAMPLE_VOLUME_MAX - value)

            ) {
        volumeRatio += value;
        FAT_tracker.allInstruments[instrumentId].volumeRatio = (volumeRatio << 4) | waveRatio;
    }
}

/**
 * \brief Change le paramètre "envdir" (direction de l'enveloppe) pour un instrument de type PULSE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
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

/**
 * \brief Change le paramètre "envdir" (direction de l'enveloppe) pour un instrument de type NOISE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentNoise_changeEnvelopeDirection(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeEnvelopeDirection(instrumentId, value);
}

/**
 * \brief Change le paramètre "steptime" (pas de l'enveloppe) pour un instrument de type PULSE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
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

/**
 * \brief Change le paramètre "steptime" (pas de l'enveloppe) pour un instrument de type NOISE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentNoise_changeSteptime(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeSteptime(instrumentId, value);
}

/**
 * \brief Change le paramètre "waveduty" (forme de l'onde) pour un instrument de type PULSE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentPulse_changeWaveduty(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep < INSTRUMENT_PULSE_WAVE_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep += value;
    }
}

/**
 * \brief Change le paramètre "polystep" (polynomial step) pour un instrument de type NOISE.
 * 
 * cf <a href="http://belogic.com/gba/channel4.shtml">http://belogic.com/gba/channel4.shtml</a>
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentNoise_changePolystep(u8 instrumentId, s8 value) {
    if (value < 0) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep = 0;
    } else if (value > 0) {
        FAT_tracker.allInstruments[instrumentId].wavedutyOrPolynomialStep = 1;
    }
}

/**
 * \brief Change le paramètre "output" (sortie droite/gauche) pour un instrument de type PULSE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentPulse_changeOutput(u8 instrumentId, s8 value) {
    switch (value) {
        case -1: // touche LEFT
            FAT_tracker.allInstruments[instrumentId].output = 1;
            break;
        case 1: // touche DROITE
            FAT_tracker.allInstruments[instrumentId].output = 2;
            break;
        case -16: // touche BAS
            FAT_tracker.allInstruments[instrumentId].output = 0;
            break;
        case 16: // touche HAUT
            FAT_tracker.allInstruments[instrumentId].output = 3;
            break;
    }
}

/**
 * \brief Change le paramètre "output" (sortie droite/gauche) pour un instrument de type NOISE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentNoise_changeOutput(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeOutput(instrumentId, value);
}

/**
 * \brief Change le paramètre "output" (sortie droite/gauche) pour un instrument de type WAVE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentWave_changeOutput(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeOutput(instrumentId, value);
}

/**
 * \brief Change le paramètre "output" (sortie droite/gauche) pour un instrument de type SAMPLE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentSample_changeOutput(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeOutput(instrumentId, value);
}

/**
 * \brief Change le paramètre "soundlength" (durée du son) pour un instrument de type PULSE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentPulse_changeSoundLength(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].soundlength > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].soundlength < INSTRUMENT_PULSE_LENGTH_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].soundlength += value;
    }
}

/**
 * \brief Change le paramètre "soundlength" (durée du son) pour un instrument de type NOISE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentNoise_changeSoundLength(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeSoundLength(instrumentId, value);
}

/**
 * \brief Change le paramètre "soundlength" (durée du son) pour un instrument de type WAVE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentWave_changeSoundLength(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].soundlength > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].soundlength < INSTRUMENT_WAVE_LENGTH_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].soundlength += value;
    }
}

/**
 * \brief Change le paramètre "soundlength" (durée du son) pour un instrument de type SAMPLE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentSample_changeSoundLength(u8 instrumentId, s8 value) {
    FAT_data_instrumentWave_changeSoundLength(instrumentId, value);
}

/**
 * \brief Change le paramètre "sweep" (effet sweep) pour un instrument de type PULSE.
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentPulse_changeSweep(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].sweep > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].sweep < INSTRUMENT_PULSE_SWEEP_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].sweep += value;
    }
}

/**
 * \brief Change le paramètre "loopmode" (mode son) pour un instrument de type PULSE.
 * 
 * 0 = continuous, 1 = timed
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentPulse_changeLoopmode(u8 instrumentId, s8 value) {
    if (value < 0) {
        FAT_tracker.allInstruments[instrumentId].loopmode = 0;
    } else if (value > 0) {
        FAT_tracker.allInstruments[instrumentId].loopmode = 1;
    }
}

/**
 * \brief Change le paramètre "loopmode" (mode son) pour un instrument de type WAVE.
 * 
 * 0 = continuous, 1 = timed
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentWave_changeLoopmode(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}

/**
 * \brief Change le paramètre "loopmode" (mode son) pour un instrument de type NOISE.
 * 
 * 0 = continuous, 1 = timed
 *  
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentNoise_changeLoopmode(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}

/**
 * \brief Change le paramètre "loopmode" pour un instrument de type SAMPLE.
 *  
 * @param instrumentId id de l'instrument à modifier
 * @param value la valeur à ajouter/retrancher
 */
void FAT_data_instrumentSample_changeLoopmode(u8 instrumentId, s8 value) {
    FAT_data_instrumentPulse_changeLoopmode(instrumentId, value);
}

/**
 * \brief Change le paramètre "voice" (les patterns stockés dans les banks) pour un instrument de 
 * type WAVE.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter ou retrancher
 */
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

/**
 * \brief Change le paramètre "bank" (le numéro de la bank à jouer) pour un instrument de 
 * type WAVE.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value -1 bank = 0, +1 bank = 1
 */
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

/**
 * \brief Change le paramètre "bankmode" (le mode bank) pour un instrument de 
 * type WAVE.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value -1 bankmode = SINGLE, +1 bank = DUAL
 */
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

/**
 * \brief Change la valeur du paramètre "speed" pour un instrument de type SAMPLE.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter / retrancher
 */
void FAT_data_instrumentSample_changeSpeed(u8 instrumentId, s8 value) {
    u8 speed = FAT_tracker.allInstruments[instrumentId].speedOrLooping & 0x0f;
    u8 looping = FAT_tracker.allInstruments[instrumentId].speedOrLooping & 0xf0;
    if (
            (value < 0 && speed > (-value - 1)) ||
            (value > 0 && speed < INSTRUMENT_SAMPLE_SPEED_MAX - value)

            ) {
        speed += value;
        FAT_tracker.allInstruments[instrumentId].speedOrLooping = looping | speed;
    }
}

/**
 * \brief Modifie la valeur du paramètre "loop" pour un instrument de type SAMPLE. Si le loop est à 1,
 * alors le sample sera joué de façon infini par le système.
 * 
 * @param instrumentId l'id de l'instrument à modifier
 * @param value la valeur à ajouter/retrancher
 */
void FAT_data_instrumentSample_changeLooping(u8 instrumentId, s8 value) {
    u8 speed = FAT_tracker.allInstruments[instrumentId].speedOrLooping & 0x0f;
    u8 looping = FAT_tracker.allInstruments[instrumentId].speedOrLooping >> 4;

    if (value < 0) {
        looping = 0;
    } else if (value > 0) {
        looping = 1;
    }

    FAT_tracker.allInstruments[instrumentId].speedOrLooping = (looping << 4) | speed;
}

/**
 * \brief Modifie le paramètre offset pour un instrument de type SAMPLE. 
 * 
 * @param instrumentId l'id de l'instrument à modifier 
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_instrumentSample_changeOffset(u8 instrumentId, s8 value) {
    if (
            (value < 0 && FAT_tracker.allInstruments[instrumentId].offset > (-value - 1)) ||
            (value > 0 && FAT_tracker.allInstruments[instrumentId].offset < INSTRUMENT_SAMPLE_OFFSET_MAX - value)

            ) {
        FAT_tracker.allInstruments[instrumentId].offset += value;
    }
}

/**
 * \brief Modifie le tempo pour le projet en cours.
 *  
 * @param addedValue la valeur à ajouter ou retrancher
 */
void FAT_data_project_changeTempo(s8 addedValue) {
    if (
            (addedValue > 0 && FAT_tracker.tempo <= MAX_TEMPO - addedValue) ||
            (addedValue < 0 && FAT_tracker.tempo > (-addedValue - 1))) {
        FAT_tracker.tempo += addedValue;
    }
}

/**
 * \brief Change la valeur du transpose pour le projet entier.
 * 
 * @param addedValue la valeur à ajouter ou retrancher
 */
void FAT_data_project_changeTranspose(s8 addedValue) {
    if (
            (addedValue > 0 && FAT_tracker.transpose < MAX_TRANSPOSE - addedValue) ||
            (addedValue < 0 && FAT_tracker.transpose > (-addedValue - 1))) {
        FAT_tracker.transpose += addedValue;
    }
}

/**
 * \brief Permet de savoir si une note a été écrite sur le composer.
 * 
 * @param line la ligne à vérifier sur le composer
 * @return 1 si la ligne est vide, 0 sinon
 */
bool FAT_data_composer_isNoteEmpty(u8 line) {
    return FAT_tracker.composer.notes[line].freq == NULL_VALUE;
}

/**
 * \brief Joue un apercu de la note posée sur une ligne donnée du composer.
 * 
 * @param line la ligne à jouer
 */
void FAT_data_composer_previewNote(u8 line) {
    // copie en mémoire de l'instruemnt -> on doit modifier certaines données pour la preview comme la durée.
    u8 instId = FAT_tracker.composer.notes[line].instrument;

    // se souvenir des vrais paramètres
    u8 mem_loopMode = FAT_tracker.allInstruments[instId].loopmode;
    u8 mem_soundLength = FAT_tracker.allInstruments[instId].soundlength;

    FAT_tracker.allInstruments[instId].loopmode = 1;
    FAT_tracker.allInstruments[instId].soundlength = 0x20;

    FAT_player_playNote(&FAT_tracker.composer.notes[line], FAT_tracker.composer.channels[line]);

    FAT_tracker.allInstruments[instId].loopmode = mem_loopMode;
    FAT_tracker.allInstruments[instId].soundlength = mem_soundLength;
}

/**
 * \brief Ajoute la dernière note connue sur le composer.
 *  
 * @param line le numéro de ligne sur le composer
 */
void FAT_data_composer_addDefaultNote(u8 line) {

    FAT_tracker.composer.notes[line].freq = FAT_data_lastNoteWritten.freq;

    FAT_tracker.composer.notes[line].instrument = FAT_data_lastNoteWritten.instrument;
    FAT_tracker.composer.notes[line].note = FAT_data_lastNoteWritten.note;
    //FAT_tracker.composer.notes[line].name = FAT_data_lastNoteWritten.name;
    //FAT_tracker.composer.notes[line].octave = FAT_data_lastNoteWritten.octave;

    FAT_data_initInstrumentIfNeeded(FAT_tracker.composer.notes[line].instrument, 0);
    FAT_tracker.composer.channels[line] = FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument].type;

}

/**
 * \brief Retourne un pointeur sur un objet de type NOTE sur le composer. 
 * 
 * @param line le numéro de ligne de la note dans le composer
 * @return un pointeur sur un objet NOTE
 */
note* FAT_data_composer_getNote(u8 line) {
    return & (FAT_tracker.composer.notes[line]);
}

/**
 * \brief Retourne le channel sur lequel sera jouée la note sur la ligne donnée.
 * 
 * @param line le numéro de ligne sur lequel la note est posée
 * @return le numéro de channel entre 0 et 5
 */
u8 FAT_data_composer_getChannel(u8 line) {
    return FAT_tracker.composer.channels[line];
}

/**
 * \brief Change l'intitulé d'une note dans le composer.
 * 
 * Cette méthode permet de changer l'intitulé de la note et donc sa fréquence.
 * ex. si j'ai un C 3 et que j'utilise cette méthode avec "addedValue=1" 
 * alors ma note sera modifiée en "C#3".
 * 
 * <b>TODO cette méthode ne permet pas de passer à l'octave supérieure pour enchainer les 
 * gammes.</b>
 * 
 * @param line le numéro de la ligne dans le composer
 * @param addedValue la valeur à ajouter ou retrancher
 */
void FAT_data_composer_changeValue(u8 line, s8 addedValue) {
    u8 noteName = (FAT_tracker.composer.notes[line].note & 0xf0) >> 4;
    u8 noteOctave = FAT_tracker.composer.notes[line].note & 0x0f;

    u8 channel = FAT_data_composer_getChannel(line);
    instrument* inst = &(FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument]);

    if (channel >= INSTRUMENT_TYPE_SAMPLEA) {
        u8 nbMaxSample = snd_countSamplesInKitById(inst->kitNumber);
        if (FAT_tracker.composer.notes[line].freq >= nbMaxSample) {
            FAT_tracker.composer.notes[line].freq = nbMaxSample - 1;
            /*< \todo changer l'intitulé noteName et noteOctave pour affichage correct. */
        }
        if ((addedValue > 0 && FAT_tracker.composer.notes[line].freq < nbMaxSample - 1) ||
                (addedValue < 0 && FAT_tracker.composer.notes[line].freq > 0)) {
            FAT_tracker.composer.notes[line].freq += addedValue;
        }
    } else {

        if (addedValue < 0) {

            if (noteName > 0) {

                noteName += addedValue;

            } else if (noteOctave > MIN_OCTAVE) {
                // on change d'octave si possible et on passe à la note maximale.
                // C 4 passe à B 3
                noteName = NB_NOTE - 1;
                noteOctave -= 1;
            }

            if (FAT_tracker.composer.notes[line].freq > 0) {
                FAT_tracker.composer.notes[line].freq += addedValue;
            }

        } else if (addedValue > 0) {
            if (noteName < NB_NOTE - 1) {

                noteName += addedValue;

            } else if (noteOctave < MAX_OCTAVE) {
                // on passe à l'octave suivant 
                // B 4 -> C 5
                noteName = 0;
                noteOctave += 1;
            }

            if (FAT_tracker.composer.notes[line].freq < NB_FREQUENCES) {
                FAT_tracker.composer.notes[line].freq += addedValue;
            }
        }

    }

    FAT_tracker.composer.notes[line].note = (noteName << 4) + noteOctave;

    FAT_data_lastNoteWritten.freq = FAT_tracker.composer.notes[line].freq;
    FAT_data_lastNoteWritten.note = FAT_tracker.composer.notes[line].note;
}

/**
 * \brief Modifie l'octave d'une note.
 * 
 * Cette méthode permet de changer l'octave de la note et donc sa fréquence.
 * ex. si j'ai un C 3 et que j'utilise cette méthode avec "addedValue=1" 
 * alors ma note sera modifiée en "C 4".
 * 
 * @param line le numéro de ligne de la note dans le composer
 * @param addedValue la valeur à ajouter/retirer (1 ou -1 généralement)
 */
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

/**
 * \brief Permet de changer le numéro d'instrument assigné à une note dans le composer
 * en cherchant le premier numéro disponible.
 * 
 * @param line le numéro de ligne de la note dans le composer
 * @return 1 si un instrument a été trouvé et assigné, 0 sinon
 */
bool FAT_data_composer_smartChangeInstrument(u8 line) {
    u8 inst = 0;
    while (inst < NB_MAX_INSTRUMENTS) {
        if (FAT_data_isInstrumentFree(inst)) {
            FAT_tracker.composer.notes[line].instrument = inst;
            FAT_data_lastNoteWritten.instrument = inst;

            FAT_data_initInstrumentIfNeeded(inst,
                    0);
            FAT_tracker.composer.channels[line] =
                    FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument].type;

            return 1;
        }
        inst++;
    }

    return 0;
}

/**
 * \brief Change le numéro d'instrument assigné à une note dans le composer.
 *  
 * @param line numéro de ligne de la note dans le composer
 * @param addedValue valeur à ajouter ou retrancher
 */
void FAT_data_composer_changeInstrument(u8 line, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.composer.notes[line].instrument > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.composer.notes[line].instrument < NB_MAX_INSTRUMENTS - addedValue)

            ) {
        FAT_tracker.composer.notes[line].instrument += addedValue;
        FAT_data_lastNoteWritten.instrument = FAT_tracker.composer.notes[line].instrument;

        FAT_data_initInstrumentIfNeeded(FAT_tracker.composer.notes[line].instrument,
                0);
        FAT_tracker.composer.channels[line] =
                FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument].type;
    }
}

/**
 * \brief Modifie la valeur du transpose affecté à un composer.
 * 
 * @param composer le numéro du composer (unused pour le moment)
 * @param value la value à ajouter ou retrancher
 */
void FAT_data_composer_changeTranspose(u8 composer, s8 value) {
    if (
            (value < 0 && FAT_tracker.composer.transpose > (-value - 1)) ||
            (value > 0 && FAT_tracker.composer.transpose < MAX_TRANSPOSE - value)

            ) {
        FAT_tracker.composer.transpose += value;
    }
}

/**
 * \brief Modifie la valeur du paramètre "key repeat" sur le composer.
 *  
 * @param composer le numéro du composer (unused pour le moment)
 * @param value la valeur à ajouter ou retrancher
 */
void FAT_data_composer_changeKeyRepeat(u8 composer, s8 value) {
    if (
            (value < 0 && FAT_tracker.composer.keyRepeat > (-value - 1)) ||
            (value > 0 && FAT_tracker.composer.keyRepeat < MAX_KEYREPEAT - value)

            ) {
        FAT_tracker.composer.keyRepeat += value;
    }
}

/**
 * \brief Reset la valeur par défaut pour le channel affecté à la note (récupère le numéro de
 * channel de l'instrument assigné).
 *  
 * @param line le numéro de ligne dans le COMPOSER
 */
void FAT_data_composer_resetAffectedChannel(u8 line) {
    FAT_tracker.composer.channels[line] =
            FAT_tracker.allInstruments[FAT_tracker.composer.notes[line].instrument].type;
}

/**
 * \brief Change le numéro de channel affecté à la note (permet de surcharger la valeur
 * par défaut de l'instrument et de faire des choses bizarres dans le composer).
 * 
 * @param line le numéro de ligne dans le composer
 * @param addedValue la valeur à ajouter/retrancher
 */
void FAT_data_composer_changeAffectedChannelValue(u8 line, s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.composer.channels[line] > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.composer.channels[line] < 6 - addedValue)

            ) {
        FAT_tracker.composer.channels[line] += addedValue;
    }
}

/**
 * \brief Modifie la valeur du paramètre "key repeat" pour le projet.
 * 
 * @param addedValue la valeur a ajouter ou retrancher
 */
void FAT_data_project_changeKeyRepeat(s8 addedValue) {
    if (
            (addedValue < 0 && FAT_tracker.keyRepeat > (-addedValue - 1)) ||
            (addedValue > 0 && FAT_tracker.keyRepeat < MAX_KEYREPEAT - addedValue)

            ) {
        FAT_tracker.keyRepeat += addedValue;
        hel_PadSetRepeatRate(PAD_BUTTON_R | PAD_BUTTON_L | PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_UP | PAD_BUTTON_DOWN | PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_START, FAT_tracker.keyRepeat);
        hel_PadSetRepeatDelay(PAD_BUTTON_R | PAD_BUTTON_L | PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_UP | PAD_BUTTON_DOWN | PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_START, FAT_tracker.keyRepeat > 9 ? FAT_tracker.keyRepeat - 9 : 1);
    }
}

/**
 * \brief Permet d'activer/désactiver la fonction preview.
 * 
 * @param addedValue si &lt; 0, alors désactivation, sinon activation 
 */
void FAT_data_project_changePreview(s8 addedValue) {
    if (addedValue < 0) {
        FAT_tracker.previewEnable = 0;
    } else if (addedValue > 0) {
        FAT_tracker.previewEnable = 1;
    }
}


#endif	/* DATA_H */

