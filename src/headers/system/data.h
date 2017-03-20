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

/** \brief Nombre de séquences disponibles <b>au total</b> en mémoire. 0x80 = 128 */
#define NB_MAX_SEQUENCES 64
/** \brief Nombre de séquences référençables par canal. 0x40 = 64 */
#define NB_SEQUENCES_IN_ONE_CHANNEL 0x40
/** \brief Nombre de blocks disponibles <b>au total</b> en mémoire. 0x70 = 112 */
#define NB_MAX_BLOCKS 0x70
/** \brief Nombre d'instruments disponibles <b>au total</b> en mémoire. 0x3f = 63 */
#define NB_MAX_INSTRUMENTS 0x3f
/** * \brief Nombre de tables disponibles <b>au total</b> en mémoire. 0xf = 15 */
#define NB_MAX_TABLES 0xF
/** \brief Nombre de notes dans un block (une mesure). */
#define NB_NOTES_IN_ONE_BLOCK 16
/** \brief Nombre de blocks (mesures) dans une séquence (pattern). */
#define NB_BLOCKS_IN_SEQUENCE 16
/** \brief Nombre d'effets référençables par table. */
#define NB_EFFECTS_IN_ONE_TABLE 16
/** \brief Définit le nombre maximal de voix disponibles. Les voix sont l'équivalent des
 * synthé dans LSDJ. */
#define NB_MAX_VOICE 16
/** \brief Octave minimale pour une note. */
#define MIN_OCTAVE 3
/** \brief Octave maximale pour une note. */
#define MAX_OCTAVE 8
/** \brief Nombre total de notes disponibles: de C à B (notation anglo-saxonne). */
#define NB_NOTE 12
/** \brief Définit le nombre d'effet disponibles pour les notes. */
#define NB_NOTE_EFFECT 17
/** \brief Définit le nombre d'effet disponibles pour les blocks. */
#define NB_BLOCK_EFFECT 1
/** \brief Définit le nombre maximal de voix disponibles. Les voix sont l'équivalent des
 * synthé dans LSDJ. */
#define NB_MAX_VOICE 16
/** \brief Définit le nombre de maximale de voix custom. */
#define NB_MAX_CUSTOM_VOICE 3
/** \brief Taille maximale pour le nom d'une chanson. */
#define SONG_NAME_MAX_LETTERS 9
/** \brief Type d'instrument PULSE 1 */
#define INSTRUMENT_TYPE_PULSE 0
/** \brief Type d'instrument PULSE 2 */
#define INSTRUMENT_TYPE_PULSE2 1
/** \brief Type d'instrument WAVE */
#define INSTRUMENT_TYPE_WAVE 2
/** \brief Type d'instrument NOISE */
#define INSTRUMENT_TYPE_NOISE 3
/** \brief Type d'instrument SAMPLE A */
#define INSTRUMENT_TYPE_SAMPLEA 4
/** \brief Type d'instrument SAMPLE B */
#define INSTRUMENT_TYPE_SAMPLEB 5
/** \brief Type d'instrument OSCILLATOR */
#define INSTRUMENT_TYPE_OSCILLATORA 6
/** \brief Type d'instrument OSCILLATORB */
#define INSTRUMENT_TYPE_OSCILLATORB 7
/** \brief Valeur de volume maximum pour un instrument de type PULSE. */
#define INSTRUMENT_PULSE_VOLUME_MAX 16
/** \brief Valeur de "wave" maximum pour un instrument de type PULSE. */
#define INSTRUMENT_PULSE_WAVE_MAX 4
/** \brief Valeur de "steptime" maximum pour un instrument de type PULSE. */
#define INSTRUMENT_PULSE_STEPTIME_MAX 8
/** \brief Valeur de "soundlength" maximum pour un instrument de type PULSE. */
#define INSTRUMENT_PULSE_LENGTH_MAX 64
/** \brief Valeur de "soundlength" maximum pour un instrument de type OSC. */
#define INSTRUMENT_OSC_LENGTH_MAX 255
/** \brief Valeur de "sweep" maximum pour un instrument de type PULSE. */
#define INSTRUMENT_PULSE_SWEEP_MAX 128
/** \brief Valeur de volume maximum pour un instrument de type WAVE. */
#define INSTRUMENT_WAVE_VOLUME_MAX 5
/** \brief Valeur de "soundlength" maximum pour un instrument de type WAVE. */
#define INSTRUMENT_WAVE_LENGTH_MAX 256
/** \brief Nombre de voix disponibles pour un instrument de type WAVE. */
#define INSTRUMENT_WAVE_NB_VOICE 0x18
/** \brief Valeur de volume maximum pour un instruemnt de type SAMPLE */
#define INSTRUMENT_SAMPLE_VOLUME_MAX 2
/** \brief Valeur de vitesse maximale pour un sample. 1= vitesse normale, F = maximale. 0= stop */
#define INSTRUMENT_SAMPLE_SPEED_MAX 16
/** \brief Valeur maximale pour le paramètre offset d'un instrument de type SAMPLE (%) */
#define INSTRUMENT_SAMPLE_OFFSET_MAX 100
/** \brief Tempo maximal. */
#define MAX_TEMPO 255
/** \brief Valeur de transposition maximale. */
#define MAX_TRANSPOSE 256
/** \brief Valeur maximum pour le paramètre "Key Repeat". */
#define MAX_KEYREPEAT 256
/**
 * \brief NULL_VALUE représente la valeur "interdite".
 *
 * Au démarrage de l'appli, toutes les données dans FAT_tracker sont initialisées
 * avec NULL_VALUE.
 * <b>NE PAS TOUCHER !</b>
 */
#define NULL_VALUE 0xff

/** \brief Tableau constant contenant toutes les notes sous formes de chaînes de caractères. */
extern const char* noteName[NB_NOTE];
/** \brief Tableau constant contenant tous les noms d'effets disponibles pour les notes. */
extern const char* noteEffectName[NB_NOTE_EFFECT];
/** \brief Mapping entre le nom de l'effet et son numéro dans la soundApi. Si le mapping
 * a pour valeur NULL_VALUE, alors l'effet n'est pas géré par la soundAPI. */
extern const u8 noteEffectNum[NB_NOTE_EFFECT];
/** Nom en toute lettres des effets */
extern const char* noteEffectHelp[NB_NOTE_EFFECT];
/** \brief Tableau constant contenant tous les noms d'effets disponibles pour les blocks. */
extern const char* blockEffectName[NB_BLOCK_EFFECT];

/**
 * \brief Nombre total de fréquences de notes.
 *
 * F(Hz)=4194304/(32*(2048-register value)). The minimum frequency is 64Hz and the maximum is 131Khz.
 * Voir <a href="http://jeanjacques.dialo.free.fr/frequenc.htm">http://jeanjacques.dialo.free.fr/frequenc.htm</a>
 */
#define NB_FREQUENCES 72

/**
* \struct WAVE
* \brief Définit une voice éditée dans l'editor de voix.
*/
typedef struct WAVE {
  /*!< Données de l'onde. */
  u32 data [4];
} wave;

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
    u8 type; /*!< Le type de l'instrument: PULSE1, PULSE2, WAVE, NOISE, SAMPLEA, SAMPLEB, OSCA, OSCB */
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
                                  la valeur du paramètre "polystep" pour les instruments de type NOISE et la valeur de l'oscForm pour l'OSCILLATOR */
    u8 soundlength; /*!< Stocke la durée du son: attention, ce paramètre ne sera appliqué que si loopmode = 1. */
    u8 loopmode; /*!< Mode de durée du son : 1=timed, 0=continuous .*/

    // 0x 0   0        0     0 0000
    // 0x NA  bankmode bank  voice
    u8 voiceAndBank; /*!< Ce paramètre agrége plusieurs autres paramètres dédiés aux instruments de type WAVE : "voice", "bank", "bankmode". */
    // voice (max=17) -> voiceAndBank & 0x1f
    // bank (max=1) -> (voiceAndBank & 0x20) >> 5
    // bankMode (max=1) -> (voiceAndBank & 0x40) >> 6

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
    u8 customVoice; /*!< Voix éditées par l'utilisateur. Max = NB_MAX_CUSTOM_VOICE - 1*/
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
    u8 greedPlay; /*!< Paramètre utile pour la selection de paquet de séquences lors du démarrage de la lecture */
    u8 bufferChangeInLive; /*!< Activation du buffer dans l'écran LIVE pour les changements de valeurs TEMPO, VOL et TSP. */
    channel channels[6]; /*!< Définition des channels: la GBA en dispose de 6. */
    sequence allSequences [NB_MAX_SEQUENCES]; /*!< Tableau (physique) contenant toutes les séquence. */
    block allBlocks [NB_MAX_BLOCKS]; /*!< Tableau (physique) contenant tous les blocks. */
    instrument allInstruments[NB_MAX_INSTRUMENTS]; /*!< Tableau (physique) contenant tous les instruments. */
    composer composer; /*!< Données pour l'écran de composition. */
    voice voices[NB_MAX_VOICE]; /*!< Les voix disponibles. Une voix = un synthé LSDJ. */
    table tables[NB_MAX_TABLES]; /*!< Tableau (physique) contenant toutes les tables. */
    livedata liveData;
    wave customVoice[NB_MAX_CUSTOM_VOICE];
    u8 sampleRate; // Le taux d'échantillonage (/1000), 16 par défaut pour 16000Hz.
} tracker;

/**
 * \struct PLAYERBUFFER
 * \brief Structure pour définir un buffer lors de la lecture du son.
 */
typedef struct PLAYERBUFFER {
    note* note;
    u8 transpose;
    bool haveToPlay;
    u8 volume; // en cas de commande "VOLUME", 0xff si on ne veut pas appliquer
    u8 sweep; // pour la commande "SWEEP". 0xff = non apply
    u8 output; // pour la commande "OUTPUT". 0xff = non apply
    u8 customVoice; // pour la commande "CUSTOMVOICE". 0xff = non apply
} bufferPlayer;


extern tracker ATTR_ALIGNED(8) ATTR_EWRAM FAT_tracker;
extern tracker ATTR_ALIGNED(8) ATTR_EWRAM FAT_compressed_tracker;

void FAT_player_playNote(note* note, u8 channel, u8 forceVolume);

void FAT_data_initData();
bool FAT_data_isPreviewEnabled();
u8 FAT_data_isCurrentlySimulating();
note* FAT_data_getSimulator ();

void FAT_data_cutSequence(u8 channelId, u8 line);
void FAT_data_pasteSequence(u8 channelId, u8 line);
void FAT_data_cloneSequence(u8 channelId, u8 line);
void FAT_data_pasteSequenceWithNewNumber(u8 channelId, u8 line);

void FAT_data_cutBlock(u8 sequence, u8 blockLine);
void FAT_data_pasteBlock(u8 sequence, u8 blockLine);
void FAT_data_cloneBlock(u8 sequence, u8 blockLine);
void FAT_data_pasteBlockWithNewNumber(u8 sequence, u8 blockLine);
void FAT_data_removeBlockTranspose(u8 sequence, u8 blockLine);

void FAT_data_cutNote(u8 block, u8 noteLine);
void FAT_data_composer_cutNote(u8 line);
void FAT_data_pasteNote(u8 block, u8 noteLine);
void FAT_data_composer_pasteNote(u8 line);

bool FAT_data_isSequenceAllocatable(u8 channelId, u8 line);
bool FAT_data_isBlockAllocatable(u8 sequence, u8 blockLine);
bool FAT_data_isNoteEmpty(u8 block, u8 noteLine);

u8 FAT_data_getSequence(u8 channelId, u8 sequenceLine);
u8 FAT_data_getBlock(u8 sequence, u8 blockLine);
note* FAT_data_getNote(u8 block, u8 noteLine);

void FAT_data_allocateSequenceToNextAvailableId(u8 channelId, u8 line);
bool FAT_data_allocateSequence(u8 channelId, u8 line);
bool FAT_data_smartAllocateSequence(u8 channelId, u8 line);
void FAT_data_allocateBlockToNextAvailableId(u8 sequence, u8 blockLine);
bool FAT_data_allocateBlock(u8 sequence, u8 blockLine);
bool FAT_data_smartAllocateBlock(u8 sequence, u8 blockLine);

bool FAT_data_isBlockEmpty(u8 blockId);
bool FAT_data_isSequenceEmpty(u8 sequenceId);
bool FAT_data_isInstrumentFree(u8 inst);
bool FAT_data_block_isTransposeEmpty(u8 sequence, u8 line);

u8 FAT_data_block_getTranspose(u8 sequence, u8 line);
void FAT_data_block_allocateTranspose(u8 sequence, u8 line);
void FAT_data_block_changeTransposeValue(u8 sequence, u8 line, s8 addedValue);
void FAT_data_block_changeValue(u8 sequence, u8 blockLine, s8 addedValue);
bool FAT_data_block_isEffectEmpty(u8 sequence, u8 blockLine);
effect* FAT_data_block_getEffect(u8 sequence, u8 line);

void FAT_data_sequence_changeValue(u8 channelId, u8 line, s8 addedValue);

void FAT_data_initInstrumentIfNeeded(u8 instId, u8 channel);
u8 FAT_data_getInstrumentType(u8 inst);

void FAT_data_addDefaultNote(u8 block, u8 noteLine, u8 channel);
void FAT_data_note_previewNote(u8 block, u8 line);
void FAT_data_note_changeValue(u8 channel, u8 block, u8 noteLine, s8 addedValue);
void FAT_data_note_changeOctave(u8 block, u8 noteLine, s8 addedValue);
void FAT_data_note_changeInstrument(u8 currentChannel, u8 block, u8 noteLine, s8 addedValue);
void FAT_data_note_filterEffectValue (effect* effect);
void FAT_data_note_changeEffectName(u8 block, u8 line, s8 addedValue);
void FAT_data_note_changeEffectValue_limited (effect* effect, s8 addedValue, u8 limit);
void FAT_data_note_changeEffectValue_generic (effect* effect, s8 addedValue);
void FAT_data_note_changeEffectValue(u8 block, u8 line, s8 addedValue);
void FAT_data_note_pasteEffect(u8 block, u8 line);
void FAT_data_note_cutEffect(u8 block, u8 line);
bool FAT_data_note_smartChangeInstrument(u8 currentChannel, u8 block, u8 noteLine);
bool FAT_data_note_isEffectEmpty(u8 block, u8 line);
effect* FAT_data_note_getEffect(u8 block, u8 line);
void FAT_data_note_addDefaultEffect(u8 block, u8 line);

void FAT_data_instrument_changeType(u8 instrumentId, u8 newType);
void FAT_data_instrument_changeSimulator(u8 inst, s8 addedValue);
void FAT_data_instrument_setCurrentlySimulating (u8 val);
u8 FAT_data_instrument_isCurrentlySimulating ();
void FAT_data_instrument_playSimulator(u8 inst);
void FAT_data_instrumentPulse_changeVolume(u8 instrumentId, s8 value);
void FAT_data_instrumentNoise_changeVolume(u8 instrumentId, s8 value);
void FAT_data_instrumentWave_changeVolume(u8 instrumentId, s8 value);
void FAT_data_instrumentSample_changeKitNumber(u8 instrumentId, s8 value);
void FAT_data_instrumentSample_changeVolume(u8 instrumentId, s8 value);
void FAT_data_instrumentPulse_changeEnvelopeDirection(u8 instrumentId, s8 value);
void FAT_data_instrumentNoise_changeEnvelopeDirection(u8 instrumentId, s8 value);
void FAT_data_instrumentPulse_changeSteptime(u8 instrumentId, s8 value);
void FAT_data_instrumentNoise_changeSteptime(u8 instrumentId, s8 value);
void FAT_data_instrumentPulse_changeWaveduty(u8 instrumentId, s8 value);
void FAT_data_instrumentOsc_changeShape (u8 instrumentId, s8 value);
void FAT_data_instrumentNoise_changePolystep(u8 instrumentId, s8 value);
void FAT_data_instrumentPulse_changeOutput(u8 instrumentId, s8 value);
void FAT_data_instrumentNoise_changeOutput(u8 instrumentId, s8 value);
void FAT_data_instrumentWave_changeOutput(u8 instrumentId, s8 value);
void FAT_data_instrumentSample_changeOutput(u8 instrumentId, s8 value);
void FAT_data_instrumentPulse_changeSoundLength(u8 instrumentId, s8 value);
void FAT_data_instrumentNoise_changeSoundLength(u8 instrumentId, s8 value);
void FAT_data_instrumentOsc_changeSoundLength (u8 instrumentId, s8 value);
void FAT_data_instrumentWave_changeSoundLength(u8 instrumentId, s8 value);
void FAT_data_instrumentSample_changeSoundLength(u8 instrumentId, s8 value);
void FAT_data_instrumentPulse_changeSweep(u8 instrumentId, s8 value);
void FAT_data_instrumentPulse_changeLoopmode(u8 instrumentId, s8 value);
void FAT_data_instrumentWave_changeLoopmode(u8 instrumentId, s8 value);
void FAT_data_instrumentNoise_changeLoopmode(u8 instrumentId, s8 value);
void FAT_data_instrumentOsc_changeLoopmode (u8 instrumentId, s8 value);
void FAT_data_instrumentSample_changeLoopmode(u8 instrumentId, s8 value);
void FAT_data_instrumentWave_changeVoice(u8 instrumentId, s8 value);
void FAT_data_instrumentWave_changeBank(u8 instrumentId, s8 value);
void FAT_data_instrumentWave_changeBankmode(u8 instrumentId, s8 value);
void FAT_data_instrumentSample_changeSpeed(u8 instrumentId, s8 value);
void FAT_data_instrumentSample_changeLooping(u8 instrumentId, s8 value);
void FAT_data_instrumentSample_changeOffset(u8 instrumentId, s8 value);
void FAT_data_instrumentWave_changeCustomWave (u8 instrumentId, s8 value);

void FAT_data_project_changeTempo(s8 addedValue);
void FAT_data_project_changeTranspose(s8 addedValue);
void FAT_data_project_changeKeyRepeat(s8 addedValue);
void FAT_data_project_changePreview(s8 addedValue);
void FAT_data_project_changeGreedPlay (s8 addedValue);
void FAT_data_project_changeBufferingInLive (s8 addedValue);
void FAT_data_project_changeSampleRate (s8 addedValue);

bool FAT_data_composer_isNoteEmpty(u8 line);
void FAT_data_composer_previewNote(u8 line);
void FAT_data_composer_addDefaultNote(u8 line);
note* FAT_data_composer_getNote(u8 line);
u8 FAT_data_composer_getChannel(u8 line);
void FAT_data_composer_changeValue(u8 line, s8 addedValue);
void FAT_data_composer_changeOctave(u8 line, s8 addedValue);
bool FAT_data_composer_smartChangeInstrument(u8 line);
void FAT_data_composer_changeInstrument(u8 line, s8 addedValue);
void FAT_data_composer_changeTranspose(u8 composer, s8 value);
void FAT_data_composer_changeKeyRepeat(u8 composer, s8 value);
void FAT_data_composer_resetAffectedChannel(u8 line);
void FAT_data_composer_changeAffectedChannelValue(u8 line, s8 addedValue);

void FAT_data_wave_initIfNeeded (u8 customVoiceId, u8 instrumentId);
void FAT_data_wave_changeValue (u8 customVoiceId, u8 dataNumber, u8 part, s8 addedValue);

#endif	/* DATA_H */
