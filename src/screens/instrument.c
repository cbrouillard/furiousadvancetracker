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
* \file instrument.c
* \brief Ecran instrument.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../headers/screen_instrument.h"

// Variables permettant de savoir l'état de l'écran (popup affichée, onglet affiché)
/** \brief Permet de savoir si la popup de déplacement est affichée au dessus de l'écran. */
bool FAT_screenInstrument_isPopuped = 0;
/** \brief Permet de savoir si l'utilisateur est en train de changer d'onglet (type d'instrument). */
u8 FAT_screenInstrument_isTabulating = 0;

// quel instrument est en cours d'édition ?
/** \brief L'id de l'instrument en cours d'édition. */
u8 FAT_screenInstrument_currentInstrumentId;

// sprites utiles à l'affichage de certaines données
/** \brief Sprite pour la direction de l'enveloppe: valeur 0. */
THandle FAT_instrument_envdir0_obj;
/** \brief Sprite pour la direction de l'enveloppe: valeur 1. */
THandle FAT_instrument_envdir1_obj;
/** \brief Sprite pour le paramètre waveduty: valeur 0. */
THandle FAT_instrument_waveduty0_obj;
/** \brief Sprite pour le paramètre waveduty: valeur 1. */
THandle FAT_instrument_waveduty1_obj;
/** \brief Sprite pour le paramètre waveduty: valeur 2. */
THandle FAT_instrument_waveduty2_obj;
/** \brief Sprite pour le paramètre waveduty: valeur 3. */
THandle FAT_instrument_waveduty3_obj;

THandle FAT_instrument_oscForm_sin_obj;
THandle FAT_instrument_oscForm_square_obj;
THandle FAT_instrument_oscForm_triangle_obj;
THandle FAT_instrument_oscForm_saw_obj;

/**
 * \brief Affiche le numéro de l'écran en cours d'édition dans le cadre en haut à droite.
 */
void FAT_screenInstrument_printInstrumentNumber() {
    hel_BgTextPrintF(TEXT_LAYER, 16, 3, 0, "Instrument %.2x", FAT_screenInstrument_currentInstrumentId);
}

/**
 * \brief Affiche toutes les valeurs des paramètres de l'instrument selon son type.
 *
 * @param type le type de l'instrument
 */
void FAT_screenInstrument_printAllText(u8 type) {
    tracker* FAT_tracker = FAT_data_getTracker ();
    note* FAT_data_simulator = FAT_data_getSimulator();

    switch (type) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            hel_BgTextPrintF(TEXT_LAYER, 1, 4, 0, "Volume    %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0x0f);
            hel_BgTextPrint(TEXT_LAYER, 1, 5, 0, "Direction");
            FAT_screenInstrument_showEnvdir((FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0x10) >> 4,
                    88, 40);
            hel_BgTextPrintF(TEXT_LAYER, 1, 6, 0, "Steptime  %.1x", (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0xe0) >> 5);
            hel_BgTextPrint(TEXT_LAYER, 1, 7, 0, "Wave");
            FAT_screenInstrument_showWaveduty(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].wavedutyOrPolynomialStep,
                    88, 56);
            hel_BgTextPrintF(TEXT_LAYER, 1, 10, 0, "Timed     %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(TEXT_LAYER, 1, 11, 0, "Length    %.2x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(TEXT_LAYER, 1, 11, 0, "Length    NA");
            }
            FAT_screenInstrument_showOutput(1, 12, FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].output);
            hel_BgTextPrintF(TEXT_LAYER, 1, 13, 0, "Sweep     %.2x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].sweep);
            hel_BgTextPrintF(TEXT_LAYER, 1, 16, 0, "Test it!  %s%1x\0",
                    noteName[(FAT_data_simulator->note & 0xf0) >> 4], FAT_data_simulator->note & 0x0f);
            break;
        case INSTRUMENT_TYPE_WAVE:
            hel_BgTextPrintF(TEXT_LAYER, 1, 4, 0, "Volume    %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].volumeRatio & 0x0f);
            hel_BgTextPrintF(TEXT_LAYER, 1, 7, 0, "Timed     %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(TEXT_LAYER, 1, 8, 0, "Length    %.2x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(TEXT_LAYER, 1, 8, 0, "Length    NA");
            }

            hel_BgTextPrintF(TEXT_LAYER, 1, 9, 0, "Voice     %.2x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].voiceAndBank & 0x1f);
            hel_BgTextPrintF(TEXT_LAYER, 1, 10, 0, "Bank      %.1x", (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].voiceAndBank & 0x20) >> 5);

            if ((FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].voiceAndBank & 0x40) >> 6 == 0) {
                hel_BgTextPrint(TEXT_LAYER, 1, 11, 0, "Bankmode  SIN");
            } else {
                hel_BgTextPrintF(TEXT_LAYER, 1, 11, 0, "Bankmode  DUA");
            }
            FAT_screenInstrument_showOutput(1, 12, FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].output);
            hel_BgTextPrintF(TEXT_LAYER, 1, 15, 0, "Test it!  %s%1x\0",
                    noteName[(FAT_data_simulator->note & 0xf0) >> 4], FAT_data_simulator->note & 0x0f);
            break;
        case INSTRUMENT_TYPE_NOISE:
            hel_BgTextPrintF(TEXT_LAYER, 1, 4, 0, "Volume    %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0x0f);
            hel_BgTextPrint(TEXT_LAYER, 1, 5, 0, "Direction");
            FAT_screenInstrument_showEnvdir((FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0x10) >> 4,
                    88, 40);
            hel_BgTextPrintF(TEXT_LAYER, 1, 6, 0, "Steptime  %.1x", (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].envelope & 0xe0) >> 5);
            hel_BgTextPrintF(TEXT_LAYER, 1, 7, 0, "Polystep  %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].wavedutyOrPolynomialStep);

            hel_BgTextPrintF(TEXT_LAYER, 1, 10, 0, "Timed     %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(TEXT_LAYER, 1, 11, 0, "Length    %.2x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(TEXT_LAYER, 1, 11, 0, "Length    NA");
            }
            FAT_screenInstrument_showOutput(1, 12, FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].output);
            hel_BgTextPrintF(TEXT_LAYER, 1, 16, 0, "Test it!  %s%1x\0",
                    noteName[(FAT_data_simulator->note & 0xf0) >> 4], FAT_data_simulator->note & 0x0f);
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            hel_BgTextPrintF(TEXT_LAYER, 16, 4, 0, "Nb samples %.2x", snd_countSamplesInKitById(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].kitNumber));
            //ham_DrawText(16, 5, "NB KITS    %.2x", snd_countAvailableKits ());

            hel_BgTextPrintF(TEXT_LAYER, 1, 4, 0, "Name %s", snd_getKitNameById(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].kitNumber));
            hel_BgTextPrintF(TEXT_LAYER, 1, 7, 0, "Volume    %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].volumeRatio >> 4);
            hel_BgTextPrintF(TEXT_LAYER, 1, 10, 0, "Speed     %.1xx", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].speedOrLooping & 0x0f);
            if (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].speedOrLooping >> 4) {
                hel_BgTextPrintF(TEXT_LAYER, 1, 11, 0, "Loop      %s", "YES");
            } else {
                hel_BgTextPrintF(TEXT_LAYER, 1, 11, 0, "Loop      %s", "NOP");
            }
            hel_BgTextPrintF(TEXT_LAYER, 1, 12, 0, "Timed     %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(TEXT_LAYER, 1, 13, 0, "Length(%) %.3d", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(TEXT_LAYER, 1, 13, 0, "Length    N/A");
            }
            hel_BgTextPrintF(TEXT_LAYER, 1, 14, 0, "Offset(%) %.2d", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].offset);
            FAT_screenInstrument_showOutput(1, 15, FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].output);

            hel_BgTextPrintF(TEXT_LAYER, 16, 12, 0, "Test it!  #%.2x\0", FAT_data_simulator->freq);

            break;

        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            hel_BgTextPrintF(TEXT_LAYER, 1, 4, 0, "OSC Shape");
            FAT_screenInstrument_showOscForm (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].wavedutyOrPolynomialStep,
                                                                  88, 32);
            hel_BgTextPrintF(TEXT_LAYER, 1, 5, 0, "Amplitude NA");
            hel_BgTextPrintF(TEXT_LAYER, 1, 8, 0, "Timed     %.1x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode);
            if (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].loopmode) {
                hel_BgTextPrintF(TEXT_LAYER, 1, 9, 0, "Length    %.2x", FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].soundlength);
            } else {
                hel_BgTextPrint(TEXT_LAYER, 1, 9, 0, "Length    NA");
            }

            hel_BgTextPrintF(TEXT_LAYER, 1, 12, 0, "Test it!  #%.2x\0", FAT_data_simulator->freq);
            break;
    }
}

/**
 * \brief Initialisation de l'écran instrument.
 */
void FAT_screenInstrument_init() {
    tracker* FAT_tracker = FAT_data_getTracker ();
    // quel instrument est en cours d'édition ?
    note* FAT_screenInstrument_currentNote = FAT_data_getNote(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
    FAT_screenInstrument_currentInstrumentId = FAT_screenInstrument_currentNote->instrument;
    if (FAT_screenInstrument_currentInstrumentId == NULL_VALUE) {

        FAT_screenInstrument_currentInstrumentId = 0;
    }
    FAT_data_initInstrumentIfNeeded(FAT_screenInstrument_currentInstrumentId, FAT_screenSong_currentSelectedColumn);

    // initialisation des curseurs
    FAT_screenInstrument_initCursor(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);

    // initialisation du fond (interface)
    FAT_screenInstrument_switchScreen(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);

    // initialisation des autre curseurs
    FAT_cursors_moveCursorChange(INPUT_R_CURSOR_CHANGE_X, INPUT_R_CURSOR_CHANGE_Y);

    FAT_player_hideAllCursors ();
}

/**
 * \brief Utilisez cette méthode pour changer d'écran selon le type d'instrument
 * édité.
 *
 * @param type le type d'instru à éditer cf. #define INSTRUMENT_TYPE_*
 */
void FAT_screenInstrument_switchScreen(u8 type) {
    FAT_reinitScreen();

    FAT_cursors_hideAllCursors();
    FAT_screenInstrument_hideAllEnvdirSprites();
    FAT_screenInstrument_hideAllWavedutySprite();
    FAT_screenInstrument_hideAllOscSprite ();

    switch (type) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_INSTRUMENT_PULSE_RAW), RES_SCREEN_INSTRUMENT_PULSE_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_INSTRUMENT_PULSE_MAP), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case INSTRUMENT_TYPE_WAVE:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_INSTRUMENT_WAVE_RAW), RES_SCREEN_INSTRUMENT_WAVE_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_INSTRUMENT_WAVE_MAP), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case INSTRUMENT_TYPE_NOISE:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_INSTRUMENT_NOISE_RAW), RES_SCREEN_INSTRUMENT_NOISE_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_INSTRUMENT_NOISE_MAP), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_INSTRUMENT_SAMPLE_RAW), RES_SCREEN_INSTRUMENT_SAMPLE_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_INSTRUMENT_SAMPLE_MAP), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);

            break;
        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_INSTRUMENT_OSC_RAW), RES_SCREEN_INSTRUMENT_OSC_RAW_SIZE16, 1, 1);
            ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_INSTRUMENT_OSC_MAP), 640, 0, 0);
            FAT_screenInstrument_printInstrumentNumber();
            FAT_screenInstrument_printAllText(type);
            FAT_screenInstrument_initCursor(type);
            FAT_screenInstrument_displayGoodCursor(type);
            break;
    }
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);
}

/**
 * \brief Cette fonction permet de changer le type de l'instrument en cours d'édition.
 *
 * Elle gère le déplacement du sprite onglet et permet le switchscreen.
 * @param move +1 -> type vers la droite, -1 type vers la gauche
 */
void FAT_screenInstrument_changeInstrumentType(s8 move) {
    tracker* FAT_tracker = FAT_data_getTracker ();
    u8 currentType = FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type;

    switch (currentType) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            if (move > 0) {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, INSTRUMENT_TYPE_WAVE);
            }
            break;
        case INSTRUMENT_TYPE_WAVE:
            if (move > 0) {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, INSTRUMENT_TYPE_NOISE);
            } else {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, INSTRUMENT_TYPE_PULSE);
            }
            break;
        case INSTRUMENT_TYPE_NOISE:
            if (move > 0) {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, INSTRUMENT_TYPE_SAMPLEA);
            } else {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, INSTRUMENT_TYPE_WAVE);
            }
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            if (move > 0){
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, INSTRUMENT_TYPE_OSCILLATORA);
            }else {
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, INSTRUMENT_TYPE_NOISE);
            }
            break;
        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            if (move < 0){
                FAT_data_instrument_changeType(FAT_screenInstrument_currentInstrumentId, INSTRUMENT_TYPE_SAMPLEA);
            }
            break;
    }

    FAT_screenInstrument_moveTabulationCursor(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}

/**
 * \brief Tester l'appui sur les boutons.
 *
 * <b>TODO cette méthode est trop grosse et difficilement maintenable. A refactorer. </b>
 */
void FAT_screenInstrument_checkButtons() {
    tracker* FAT_tracker = FAT_data_getTracker ();
    hel_PadCapture();

    if ( FAT_data_isCurrentlySimulating() == TRUE && !FAT_isCurrentlyPlaying && (
                    hel_PadQuery()->Pressed.Start ||
                    hel_PadQuery()->Pressed.Select ||
                    hel_PadQuery()->Pressed.A ||
                    hel_PadQuery()->Pressed.Up ||
                    hel_PadQuery()->Pressed.Down ||
                    hel_PadQuery()->Pressed.Right ||
                    hel_PadQuery()->Pressed.Left ||
                    hel_PadQuery()->Pressed.R ||
                    hel_PadQuery()->Pressed.L)
                    ) {
        FAT_player_stopPlayer();
        FAT_data_instrument_setCurrentlySimulating (FALSE);
    }

    if (hel_PadQuery()->Held.Select) {
        if (!FAT_screenInstrument_isPopuped) {
            FAT_screenInstrument_hideAllWavedutySprite();
            FAT_cursors_hideAllCursors();
            FAT_popup_show();
            FAT_screenInstrument_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenInstrument_isPopuped) {
            FAT_popup_hide();
            FAT_screenInstrument_displayGoodCursor(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
            FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
            FAT_screenInstrument_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_INSTRUMENTS_ID) {
                FAT_screenInstrument_hideAllEnvdirSprites();
                FAT_screenInstrument_hideAllWavedutySprite();
                FAT_screenInstrument_hideAllOscSprite ();
                FAT_cursors_hideAllCursors();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), SCREEN_INSTRUMENTS_ID);
            }
        }

        if (hel_PadQuery()->Held.L || FAT_screenInstruments_currentSelectedLine == -1) {
            if (!FAT_screenInstrument_isTabulating) {
                FAT_screenInstrument_isTabulating = 1;
                FAT_screenInstrument_showTabulationCursor();
            }

            if (hel_PadQuery()->Pressed.Left) {
                FAT_screenInstrument_changeInstrumentType(-1);
            }

            if (hel_PadQuery()->Pressed.Right) {
                FAT_screenInstrument_changeInstrumentType(1);
            }

            if (hel_PadQuery()->Pressed.Down) {
                FAT_screenInstrument_moveCursorDown(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
            }

            if (hel_PadQuery()->Pressed.Up) {
                FAT_screenInstrument_moveCursorUp(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
            }

        } else {
            if (FAT_screenInstrument_isTabulating && FAT_screenInstruments_currentSelectedLine == 0) {
                // relachement du L
                FAT_screenInstrument_isTabulating = 0;
                FAT_screenInstrument_switchScreen(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                FAT_screenInstrument_hideTabulationCursor();
            }

            if (hel_PadQuery()->Held.R) {
                FAT_cursors_showCursorChange();

                if (hel_PadQuery()->Pressed.Right) {
                    if (FAT_screenInstrument_currentInstrumentId < NB_MAX_INSTRUMENTS - 1) {
                        u8 type = FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type;
                        FAT_screenInstrument_currentInstrumentId++;
                        FAT_data_initInstrumentIfNeeded(FAT_screenInstrument_currentInstrumentId, type);
                        FAT_screenInstrument_switchScreen(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        FAT_screenInstrument_printInstrumentNumber();
                        FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                    }
                }

                if (hel_PadQuery()->Pressed.Left) {
                    if (FAT_screenInstrument_currentInstrumentId > 0) {
                        u8 type = FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type;
                        FAT_screenInstrument_currentInstrumentId--;
                        FAT_data_initInstrumentIfNeeded(FAT_screenInstrument_currentInstrumentId, type);
                        FAT_screenInstrument_switchScreen(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        FAT_screenInstrument_printInstrumentNumber();
                        FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                    }
                }

            } else {

                FAT_cursors_hideCursorChange();

                if (hel_PadQuery()->Pressed.A || hel_PadQuery()->Held.A) {
                    FAT_screenInstrument_pressOrHeldA();

                } else {

                    if (hel_PadQuery()->Pressed.Start) {
                        if (!FAT_isCurrentlyPlaying) {
                            FAT_player_startPlayerFromNotes(FAT_screenNotes_currentBlockId,
                                    0, FAT_screenSong_currentSelectedColumn);
                        } else {
                            FAT_player_stopPlayer();
                        }
                    }

                    if (hel_PadQuery()->Pressed.B) {
                        FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
                    }
                    if (hel_PadQuery()->Held.B) {
                        FAT_screenInstrument_showSimulatorCursor (FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        s8 addedValue = FAT_screenInstrument_giveMeAddedValue();
                        FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
                        FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                    } else {
                        FAT_screenInstrument_hideSimulatorCursor ();

                        if (hel_PadQuery()->Pressed.Right) {
                            FAT_screenInstrument_moveCursorRight(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        }

                        if (hel_PadQuery()->Pressed.Left) {
                            FAT_screenInstrument_moveCursorLeft(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        }

                        if (hel_PadQuery()->Pressed.Down) {
                            FAT_screenInstrument_moveCursorDown(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        }

                        if (hel_PadQuery()->Pressed.Up) {
                            FAT_screenInstrument_moveCursorUp(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
                        }
                    }
                }
            }
        }

        if (hel_PadQuery()->Pressed.R && hel_PadQuery()->Pressed.L) {
            FAT_screenInstrument_hideTabulationCursor();
            FAT_showHelp(SCREEN_INSTRUMENTS_ID);
        }

        FAT_screenInstrument_commitCursorMove(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
    }
}

/**
 * \brief Cette méthode charge les sprites utilisés dans l'écran de gestion des instruments.
 *
 * Attention, ne faire appel à cette méthode qu'une seule fois !
 */
void FAT_screenInstrument_initSpritesForInstrument() {

    FAT_instrument_envdir0_obj = hel_ObjCreate(   ResData(RES_ENVDIR_0_RAW), // Pointer to source graphic
                                                  OBJ_SHAPE_SQUARE,       // Obj Shape
                                                  0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                  OBJ_MODE_NORMAL,        // Obj Mode
                                                  COLORS_16,              // Use 16 color mode
                                                  0,                      // Palette number. Only neccessary in 16 color mode
                                                  FALSE,                  // Don't use mosaic
                                                  FALSE,                  // Don't flip the sprite horizontally
                                                  FALSE,                  // Don't flip the object vertically
                                                  0,                      // Priority against background. 0=higest
                                                  FALSE,                  // Don't make the object double-sized
                                                  0,                    // Destination horzintal screen coordinate in pixels
                                                  0                      // Destination vertical screen coordinate in pixels
                                                  );

    FAT_instrument_envdir1_obj = hel_ObjCreate(   ResData(RES_ENVDIR_1_RAW), // Pointer to source graphic
                                                  OBJ_SHAPE_SQUARE,       // Obj Shape
                                                  0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                  OBJ_MODE_NORMAL,        // Obj Mode
                                                  COLORS_16,              // Use 16 color mode
                                                  0,                      // Palette number. Only neccessary in 16 color mode
                                                  FALSE,                  // Don't use mosaic
                                                  FALSE,                  // Don't flip the sprite horizontally
                                                  FALSE,                  // Don't flip the object vertically
                                                  0,                      // Priority against background. 0=higest
                                                  FALSE,                  // Don't make the object double-sized
                                                  0,                    // Destination horzintal screen coordinate in pixels
                                                  0                      // Destination vertical screen coordinate in pixels
                                                  );

    FAT_instrument_waveduty0_obj = hel_ObjCreate(ResData(RES_WAVEDUTY_0_RAW), // Pointer to source graphic
                                                 OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                 0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                 OBJ_MODE_NORMAL,        // Obj Mode
                                                 COLORS_16,              // Use 16 color mode
                                                 0,                      // Palette number. Only neccessary in 16 color mode
                                                 FALSE,                  // Don't use mosaic
                                                 FALSE,                  // Don't flip the sprite horizontally
                                                 FALSE,                  // Don't flip the object vertically
                                                 0,                      // Priority against background. 0=higest
                                                 FALSE,                  // Don't make the object double-sized
                                                 0,                    // Destination horzintal screen coordinate in pixels
                                                 0                      // Destination vertical screen coordinate in pixels
                                                 );

    FAT_instrument_waveduty1_obj = hel_ObjCreate(ResData(RES_WAVEDUTY_1_RAW), // Pointer to source graphic
                                                 OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                 0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                 OBJ_MODE_NORMAL,        // Obj Mode
                                                 COLORS_16,              // Use 16 color mode
                                                 0,                      // Palette number. Only neccessary in 16 color mode
                                                 FALSE,                  // Don't use mosaic
                                                 FALSE,                  // Don't flip the sprite horizontally
                                                 FALSE,                  // Don't flip the object vertically
                                                 0,                      // Priority against background. 0=higest
                                                 FALSE,                  // Don't make the object double-sized
                                                 0,                    // Destination horzintal screen coordinate in pixels
                                                 0                      // Destination vertical screen coordinate in pixels
                                                 );

    FAT_instrument_waveduty2_obj = hel_ObjCreate(ResData(RES_WAVEDUTY_2_RAW), // Pointer to source graphic
                                                 OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                 0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                 OBJ_MODE_NORMAL,        // Obj Mode
                                                 COLORS_16,              // Use 16 color mode
                                                 0,                      // Palette number. Only neccessary in 16 color mode
                                                 FALSE,                  // Don't use mosaic
                                                 FALSE,                  // Don't flip the sprite horizontally
                                                 FALSE,                  // Don't flip the object vertically
                                                 0,                      // Priority against background. 0=higest
                                                 FALSE,                  // Don't make the object double-sized
                                                 0,                    // Destination horzintal screen coordinate in pixels
                                                 0                      // Destination vertical screen coordinate in pixels
                                                 );

    FAT_instrument_waveduty3_obj = hel_ObjCreate(ResData(RES_WAVEDUTY_3_RAW), // Pointer to source graphic
                                                 OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                 0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                 OBJ_MODE_NORMAL,        // Obj Mode
                                                 COLORS_16,              // Use 16 color mode
                                                 0,                      // Palette number. Only neccessary in 16 color mode
                                                 FALSE,                  // Don't use mosaic
                                                 FALSE,                  // Don't flip the sprite horizontally
                                                 FALSE,                  // Don't flip the object vertically
                                                 0,                      // Priority against background. 0=higest
                                                 FALSE,                  // Don't make the object double-sized
                                                 0,                    // Destination horzintal screen coordinate in pixels
                                                 0                      // Destination vertical screen coordinate in pixels
                                                 );
    FAT_instrument_oscForm_sin_obj = hel_ObjCreate(ResData(RES_OSC_SIN_RAW), // Pointer to source graphic
                                                  OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                  0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                  OBJ_MODE_NORMAL,        // Obj Mode
                                                  COLORS_16,              // Use 16 color mode
                                                  0,                      // Palette number. Only neccessary in 16 color mode
                                                  FALSE,                  // Don't use mosaic
                                                  FALSE,                  // Don't flip the sprite horizontally
                                                  FALSE,                  // Don't flip the object vertically
                                                  0,                      // Priority against background. 0=higest
                                                  FALSE,                  // Don't make the object double-sized
                                                  0,                    // Destination horzintal screen coordinate in pixels
                                                  0                      // Destination vertical screen coordinate in pixels
                                                  );

    FAT_instrument_oscForm_square_obj = hel_ObjCreate(ResData(RES_OSC_SQUARE_RAW), // Pointer to source graphic
                                                  OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                  0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                  OBJ_MODE_NORMAL,        // Obj Mode
                                                  COLORS_16,              // Use 16 color mode
                                                  0,                      // Palette number. Only neccessary in 16 color mode
                                                  FALSE,                  // Don't use mosaic
                                                  FALSE,                  // Don't flip the sprite horizontally
                                                  FALSE,                  // Don't flip the object vertically
                                                  0,                      // Priority against background. 0=higest
                                                  FALSE,                  // Don't make the object double-sized
                                                  0,                    // Destination horzintal screen coordinate in pixels
                                                  0                      // Destination vertical screen coordinate in pixels
                                                  );

    FAT_instrument_oscForm_triangle_obj = hel_ObjCreate(ResData(RES_OSC_TRIANGLE_RAW), // Pointer to source graphic
                                                  OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                  0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                  OBJ_MODE_NORMAL,        // Obj Mode
                                                  COLORS_16,              // Use 16 color mode
                                                  0,                      // Palette number. Only neccessary in 16 color mode
                                                  FALSE,                  // Don't use mosaic
                                                  FALSE,                  // Don't flip the sprite horizontally
                                                  FALSE,                  // Don't flip the object vertically
                                                  0,                      // Priority against background. 0=higest
                                                  FALSE,                  // Don't make the object double-sized
                                                  0,                    // Destination horzintal screen coordinate in pixels
                                                  0                      // Destination vertical screen coordinate in pixels
                                                  );

    FAT_instrument_oscForm_saw_obj = hel_ObjCreate(ResData(RES_OSC_SAW_RAW), // Pointer to source graphic
                                                      OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                      0,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                      OBJ_MODE_NORMAL,        // Obj Mode
                                                      COLORS_16,              // Use 16 color mode
                                                      0,                      // Palette number. Only neccessary in 16 color mode
                                                      FALSE,                  // Don't use mosaic
                                                      FALSE,                  // Don't flip the sprite horizontally
                                                      FALSE,                  // Don't flip the object vertically
                                                      0,                      // Priority against background. 0=higest
                                                      FALSE,                  // Don't make the object double-sized
                                                      0,                    // Destination horzintal screen coordinate in pixels
                                                      0                      // Destination vertical screen coordinate in pixels
                                                      );

    FAT_screenInstrument_hideAllEnvdirSprites();
    FAT_screenInstrument_hideAllWavedutySprite();
    FAT_screenInstrument_hideAllOscSprite();
}

/**
 * \brief Cache tous les sprites relatifs à l'affiche de la direction de l'enveloppe.
 */
void FAT_screenInstrument_hideAllEnvdirSprites() {

    hel_ObjSetVisible(FAT_instrument_envdir0_obj, 0);
    hel_ObjSetVisible(FAT_instrument_envdir1_obj, 0);
}

/**
 * \brief Cache tous les sprites relatifs à l'affiche du paramètre waveduty.
 */
void FAT_screenInstrument_hideAllWavedutySprite() {

    hel_ObjSetVisible(FAT_instrument_waveduty0_obj, 0);
    hel_ObjSetVisible(FAT_instrument_waveduty1_obj, 0);
    hel_ObjSetVisible(FAT_instrument_waveduty2_obj, 0);
    hel_ObjSetVisible(FAT_instrument_waveduty3_obj, 0);
}

void FAT_screenInstrument_hideAllOscSprite(){
    hel_ObjSetVisible(FAT_instrument_oscForm_sin_obj, 0);
    hel_ObjSetVisible(FAT_instrument_oscForm_square_obj, 0);
    hel_ObjSetVisible(FAT_instrument_oscForm_triangle_obj, 0);
    hel_ObjSetVisible(FAT_instrument_oscForm_saw_obj, 0);
}

/**
 * \brief Affiche le bon sprite pour la valeur de la direction de l'enveloppe.
 *
 * @param envdirValue la valeur du paramètre
 * @param spriteX position en X pour l'affichage
 * @param spriteY position en Y pour l'affichage
 */
void FAT_screenInstrument_showEnvdir(u8 envdirValue, u8 spriteX, u8 spriteY) {
    FAT_screenInstrument_hideAllEnvdirSprites();
    if (envdirValue == 1) {
        hel_ObjSetXY(FAT_instrument_envdir1_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_envdir1_obj, 1);
    } else {

        hel_ObjSetXY(FAT_instrument_envdir0_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_envdir0_obj, 1);
    }

}

/**
 * \brief Affiche la valeur de l'output.
 *
 * @param x la position du texte (en tiles)
 * @param y la position du texte (en tiles)
 * @param output la valeur de paramètre (0,1,2 ou 3)
 */
void FAT_screenInstrument_showOutput(u8 x, u8 y, u8 output) {

    hel_BgTextPrintF(TEXT_LAYER, x, y, 0, "Output    %.2s", outputText[output]);
}

/**
 * \brief Affiche le bon sprite pour la valeur du waveduty.
 *
 * @param wavedutyValue la valeur du paramètre
 * @param spriteX position en X pour l'affichage
 * @param spriteY position en Y pour l'affichage
 */
void FAT_screenInstrument_showWaveduty(u8 wavedutyValue, u8 spriteX, u8 spriteY) {
    FAT_screenInstrument_hideAllWavedutySprite();

    if (wavedutyValue == 0) {
        hel_ObjSetXY(FAT_instrument_waveduty0_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_waveduty0_obj, 1);
    } else if (wavedutyValue == 1) {
        hel_ObjSetXY(FAT_instrument_waveduty1_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_waveduty1_obj, 1);
    } else if (wavedutyValue == 2) {
        hel_ObjSetXY(FAT_instrument_waveduty2_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_waveduty2_obj, 1);
    } else if (wavedutyValue == 3) {
        hel_ObjSetXY(FAT_instrument_waveduty3_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_waveduty3_obj, 1);
    }
}

/**
 * \brief Affiche le bon sprite pour la valeur du waveduty.
 *
 * @param wavedutyValue la valeur du paramètre
 * @param spriteX position en X pour l'affichage
 * @param spriteY position en Y pour l'affichage
 */
void FAT_screenInstrument_showOscForm(u8 oscFormValue, u8 spriteX, u8 spriteY) {
    FAT_screenInstrument_hideAllOscSprite();

    if (oscFormValue == 0) {
        hel_ObjSetXY(FAT_instrument_oscForm_sin_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_oscForm_sin_obj, 1);
    } else if (oscFormValue == 1) {
        hel_ObjSetXY(FAT_instrument_oscForm_square_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_oscForm_square_obj, 1);
    } else if (oscFormValue == 2) {
        hel_ObjSetXY(FAT_instrument_oscForm_triangle_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_oscForm_triangle_obj, 1);
    } else if (oscFormValue == 3) {
        hel_ObjSetXY(FAT_instrument_oscForm_saw_obj, spriteX, spriteY);
        hel_ObjSetVisible(FAT_instrument_oscForm_saw_obj, 1);
    }
}

/**
 * \brief Fonction outil permettant de demander une valeur en fonction d'une touche appuyée.
 *
 * @return Droite: 1, Gauche: -1, Haut: 16, Bas: -16
 */
s8 FAT_screenInstrument_giveMeAddedValue() {
    s8 addedValue = 0;
    if (hel_PadQuery()->Pressed.Right) {
        addedValue = 1;
    }

    if (hel_PadQuery()->Pressed.Left) {
        addedValue = -1;
    }

    if (hel_PadQuery()->Pressed.Up) {
        addedValue = 16;
    }

    if (hel_PadQuery()->Pressed.Down) {
        addedValue = -16;
    }

    return addedValue;
}

/**
 * \brief Cette fonction permet de gérer l'appui sur la touche A pour un instrument de type PULSE.
 */
void FAT_screenInstrument_pulse_pressA() {
    tracker* FAT_tracker = FAT_data_getTracker ();

    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0: // VOLUME
            FAT_data_instrumentPulse_changeVolume(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 1: // ENVELOPE DIRECTION
            FAT_data_instrumentPulse_changeEnvelopeDirection(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 2: // STEPTIME
            FAT_data_instrumentPulse_changeSteptime(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 3: // WAVEDUTY
            FAT_data_instrumentPulse_changeWaveduty(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 4: // TIMED
            FAT_data_instrumentPulse_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 5: // LENGTH
            FAT_data_instrumentPulse_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 6: // OUTPUT
            FAT_data_instrumentPulse_changeOutput(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 7: // SWEEP
            FAT_data_instrumentPulse_changeSweep(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 8: // SIMULATOR
            FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
            if (hel_PadQuery()->Pressed.A){
                FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
            }

            break;
    }

    FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}

/**
 * \brief Cette fonction permet de gérer l'appui sur la touche A pour un instrument de type WAVE.
 */
void FAT_screenInstrument_wave_pressA() {
    tracker* FAT_tracker = FAT_data_getTracker ();

    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0: // VOLUME RATIO
            FAT_data_instrumentWave_changeVolume(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 1: // TIMED
            FAT_data_instrumentWave_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 2: // LENGTH
            FAT_data_instrumentWave_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 3: // VOICE
            FAT_data_instrumentWave_changeVoice(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 4: // BANK
            FAT_data_instrumentWave_changeBank(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 5: // BANKMODE
            FAT_data_instrumentWave_changeBankmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 6: // OUTPUT
            FAT_data_instrumentWave_changeOutput(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 7: // SIMULATOR
            FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
            if (hel_PadQuery()->Pressed.A){
                FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
            }

            break;
    }

    FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}

/**
 * \brief Cette fonction permet de gérer l'appui sur la touche A pour un instrument de type NOISE.
 */
void FAT_screenInstrument_noise_pressA() {
    tracker* FAT_tracker = FAT_data_getTracker ();

    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0: // VOLUME
            FAT_data_instrumentNoise_changeVolume(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 1: // ENVELOPE DIRECTION
            FAT_data_instrumentNoise_changeEnvelopeDirection(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 2: // STEPTIME
            FAT_data_instrumentNoise_changeSteptime(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 3: // WAVEDUTY
            FAT_data_instrumentNoise_changePolystep(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 4: // TIMED
            FAT_data_instrumentNoise_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 5: // LENGTH
            FAT_data_instrumentNoise_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 6: // OUTPUT
            FAT_data_instrumentNoise_changeOutput(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 7: // SIMULATOR
            FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
            if (hel_PadQuery()->Pressed.A){
                FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
            }

            break;
    }

    FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}

/**
 * \brief Cette fonction permet de gérer l'appui sur la touche A pour un instrument de type SAMPLE.
 */
void FAT_screenInstrument_sample_pressA() {
    tracker* FAT_tracker = FAT_data_getTracker ();

    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    if (FAT_screenInstruments_currentSelectedColumn == 0){
        switch (FAT_screenInstruments_currentSelectedLine) {
            case 0: // KIT COLLECTION
                FAT_data_instrumentSample_changeKitNumber(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 1: // VOLUME
                FAT_data_instrumentSample_changeVolume(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 2: // SPEED
                FAT_data_instrumentSample_changeSpeed(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 3: // LOOP
                FAT_data_instrumentSample_changeLooping(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 4: //TIMED
                FAT_data_instrumentSample_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 5: // LENGTH
                FAT_data_instrumentSample_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 6: // OFFSET
                FAT_data_instrumentSample_changeOffset(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
            case 7: // OUTPUT
                FAT_data_instrumentSample_changeOutput(FAT_screenInstrument_currentInstrumentId, addedValue);
                break;
        }
    } else{
        FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
        if (hel_PadQuery()->Pressed.A){
            FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
        }
    }

    FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}

void FAT_screenInstrument_osc_pressA() {
    tracker* FAT_tracker = FAT_data_getTracker ();

    s8 addedValue = FAT_screenInstrument_giveMeAddedValue();

    switch (FAT_screenInstruments_currentSelectedLine) {
        case 0: // SHAPE
            FAT_data_instrumentOsc_changeShape(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 1: // AMPLITUDE
            break;
        case 2: // TIMED
            FAT_data_instrumentOsc_changeLoopmode(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 3: // LENGTH
            FAT_data_instrumentOsc_changeSoundLength(FAT_screenInstrument_currentInstrumentId, addedValue);
            break;
        case 4: // SIMULATOR
            FAT_data_instrument_changeSimulator(FAT_screenInstrument_currentInstrumentId, addedValue);
            if (hel_PadQuery()->Pressed.A){
                FAT_data_instrument_playSimulator(FAT_screenInstrument_currentInstrumentId);
            }
            break;
    }

    FAT_screenInstrument_printAllText(FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type);
}

/**
 * \brief Fonction wrapper pour gérer l'appui sur la touche A.
 */
void FAT_screenInstrument_pressOrHeldA() {
    tracker* FAT_tracker = FAT_data_getTracker ();

    u8 currentType = FAT_tracker->allInstruments[FAT_screenInstrument_currentInstrumentId].type;

    switch (currentType) {
        case INSTRUMENT_TYPE_PULSE:
        case INSTRUMENT_TYPE_PULSE2:
            FAT_screenInstrument_pulse_pressA();
            break;
        case INSTRUMENT_TYPE_WAVE:
            FAT_screenInstrument_wave_pressA();
            break;
        case INSTRUMENT_TYPE_NOISE:
            FAT_screenInstrument_noise_pressA();
            break;
        case INSTRUMENT_TYPE_SAMPLEA:
        case INSTRUMENT_TYPE_SAMPLEB:
            FAT_screenInstrument_sample_pressA();
            break;
        case INSTRUMENT_TYPE_OSCILLATORA:
        case INSTRUMENT_TYPE_OSCILLATORB:
            FAT_screenInstrument_osc_pressA();
            break;
    }

}
