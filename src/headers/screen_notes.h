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
 * \file screen_notes.h
 * \brief Ce fichier contient toutes les fonctions utiles pour gérer l'écran NOTE. 
 */

#ifndef _SCREEN_NOTES_H_
#define _SCREEN_NOTES_H_

/** \brief Numéro de case ou l'affichage des notes démarre. */
#define SCREENNOTES_LINE_START_Y 2
/** \brief Nombre total de notes affichées sur l'écran. */
#define SCREENNOTES_NB_LINES_ON_SCREEN 16
/** \brief Numéro de case ou l'affichage des numéros de ligne démarre. */
#define SCREENNOTES_LINE_X 0
/** \brief Numéro de case pour l'affichage des effets assignés aux notes. */
#define SCREENNOTES_EFFECT_LINE_X 10
/** \brief Taille d'une ligne. */
#define SCREENNOTES_LINE_SIZE_Y 1

/** \brief Numéro de case ou l'affichage des notes démarre. */
#define SCREENNOTES_NOTE_LINE_X 3

/** \brief Numéro de colonne représentant les notes. */
#define SCREENNOTES_COLUMN_ID_NOTES 0
/** \brief Numéro de colonne représentant les instruments. */
#define SCREENNOTES_COLUMN_ID_INST 1
/** \brief Numéro de colonne représentant les noms de commandes (effets). */
#define SCREENNOTES_COLUMN_ID_CMD_NAME 2
/** \brief Numéro de colonne représentant les valeurs de commandes (effets). */
#define SCREENNOTES_COLUMN_ID_CMD_PARAM 3

// prototypes
void FAT_screenNotes_init(u8 fromScreenId);
void FAT_screenNotes_checkButtons();
void FAT_screenNotes_printLineColumns();
void FAT_screenNotes_pressOrHeldA();
void FAT_screenNotes_pressB();
void FAT_screenNotes_printInfos();

/** \brief Cette variable permet de savoir si la popup est affichée au dessus de l'écran. */
bool FAT_screenNotes_isPopuped = 0;
/** \brief Id de block en cours d'édition. */
u8 FAT_screenNotes_currentBlockId = NULL_VALUE;

#include "screen_notes_cursor.h"

/**
 * \brief Cette fonction se content d'imprimer le numéro de ligne sur la partie
 * gauche de l'interface. 
 */
void FAT_screenNotes_printLineColumns() {
    u8 y = SCREENNOTES_LINE_START_Y;
    int c;
    for (c = 0; c < (SCREENNOTES_NB_LINES_ON_SCREEN); c++) {
        hel_BgTextPrintF(TEXT_LAYER, SCREENNOTES_LINE_X, y, 0, FAT_FORMAT_LINE, c);
        y += SCREENNOTES_LINE_SIZE_Y;
    }
}

/**
 * \brief Affiche des informations dynamiques (le numéro de ligne actuellement 
 * séléctionné). 
 */
void FAT_screenNotes_printInfos() {
    hel_BgTextPrintF(TEXT_LAYER, 18, 4, 0, "Line     %.2x", FAT_screenNotes_currentSelectedLine);
    //ham_DrawText(21, 4, "CHAN %2x", FAT_screenSong_currentSelectedColumn+1);
}

/**
 * \brief Affiche une note (nom, octave et instrument) située à la ligne donnée
 * sur le block en cours d'édition.
 * 
 * @param line le numéro de ligne de la note
 */
void FAT_screenNotes_printNote(u8 line) {
    if (!FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, line)) {
        note* actualNote = FAT_data_getNote(FAT_screenNotes_currentBlockId, line);

        if (FAT_screenSong_currentSelectedColumn < INSTRUMENT_TYPE_SAMPLEA) {

            hel_BgTextPrintF(TEXT_LAYER, SCREENNOTES_NOTE_LINE_X,
                    line + SCREENNOTES_LINE_START_Y, 0,
                    "%s%1x %.2x\0", noteName[(actualNote->note & 0xf0) >> 4], actualNote->note & 0x0f, actualNote->instrument);
        } else {
            hel_BgTextPrintF(TEXT_LAYER, SCREENNOTES_NOTE_LINE_X,
                    line + SCREENNOTES_LINE_START_Y, 0,
                    "#%.2x %.2x\0", actualNote->freq, actualNote->instrument);
        }
    } else {
        hel_BgTextPrint(TEXT_LAYER, SCREENNOTES_NOTE_LINE_X,
                line + SCREENNOTES_LINE_START_Y, 0, "      ");
    }
}

/**
 * \brief Affiche l'effet assigné à la note (nom et valeur): un effet peut être
 * assigné à une note vide.
 * 
 * @param line le numéro de ligne de la note
 */
void FAT_screenNotes_printEffect(u8 line) {
    if (!FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, line)) {

        effect* effect = FAT_data_note_getEffect(FAT_screenNotes_currentBlockId, line);
        u8 effectName = (effect->name & 0xfe) >> 1;
        switch (effectName){
            case EFFECT_KILL:
                hel_BgTextPrintF(TEXT_LAYER, SCREENNOTES_EFFECT_LINE_X, line + SCREENNOTES_LINE_START_Y, 0,
                                                "%.2s--\0", noteEffectName[effectName]);
                break;
            case EFFECT_OUTPUT:
                // 4 valeurs seulement
                hel_BgTextPrintF(TEXT_LAYER, SCREENNOTES_EFFECT_LINE_X, line + SCREENNOTES_LINE_START_Y, 0,
                                                "%.2s%s\0", noteEffectName[effectName], outputText[effect->value]);
                break;
            case EFFECT_SWEEP:
                hel_BgTextPrintF(TEXT_LAYER, SCREENNOTES_EFFECT_LINE_X, line + SCREENNOTES_LINE_START_Y, 0,
                                "%.2s%.2x\0", noteEffectName[effectName], effect->value);
                break;
            case EFFECT_VOLUME:
                // de 0 à F, FF = INST DEFINED.
                hel_BgTextPrintF(TEXT_LAYER, SCREENNOTES_EFFECT_LINE_X, line + SCREENNOTES_LINE_START_Y, 0,
                                "%.2s%.2x\0", noteEffectName[effectName], effect->value);
                break;
            case EFFECT_HOP:
                // pas de value.
                hel_BgTextPrintF(TEXT_LAYER, SCREENNOTES_EFFECT_LINE_X, line + SCREENNOTES_LINE_START_Y, 0,
                                                "%.2s%.2x\0", noteEffectName[effectName], effect->value);
                break;
        }

    } else {
        hel_BgTextPrint(TEXT_LAYER, SCREENNOTES_EFFECT_LINE_X, line + SCREENNOTES_LINE_START_Y, 0,
                "    ");
    }
}

/**
 * \brief Affiche toutes les notes et leurs effets.
 */
void FAT_screenNotes_printAllNotes() {
    u8 b;
    for (b = 0; b < SCREENNOTES_NB_LINES_ON_SCREEN; b++) {
        FAT_screenNotes_printNote(b);
        FAT_screenNotes_printEffect(b);
    }
}

/**
 * \brief Affiche le numéro de block actuellement en cours d'édition. 
 */
void FAT_screenNotes_printBlockNumber() {
    hel_BgTextPrintF(TEXT_LAYER, 18, 3, 0, "Block    %.2x", FAT_screenNotes_currentBlockId);
}

/**
 * \brief Affiche tous le texte sur l'écran (lignes, notes, infos). 
 */
void FAT_screenNotes_printAllScreenText() {
    FAT_screenNotes_printLineColumns();
    FAT_screenNotes_printAllNotes();
    FAT_screenNotes_printInfos();
    hel_BgTextPrintF(TEXT_LAYER, 18, 6, 0, "Tsp-Proj %2.x\nTempo   %.3d", FAT_tracker.transpose, FAT_tracker.tempo);
}

/**
 * \brief Initialisation de l'écran. 
 */
void FAT_screenNotes_init(u8 fromScreenId) {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_NOTES_RAW), RES_SCREEN_NOTES_RAW_SIZE16, 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_NOTES_MAP), 640, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    // dans quelle block nous situons nous ?
    switch (fromScreenId){
        case SCREEN_BLOCKS_ID:
            FAT_screenNotes_currentBlockId = FAT_data_getBlock(FAT_screenBlocks_currentSequenceId, FAT_screenBlocks_currentSelectedLine);
            break;
    }
    if (FAT_screenNotes_currentBlockId == NULL_VALUE) {
        FAT_screenNotes_currentBlockId = 0;
    }
    FAT_screenNotes_printBlockNumber();
    FAT_screenNotes_printAllScreenText();

    // affichage du curseur
    FAT_player_hideAllCursors ();
    FAT_cursors_hideCursor2();
    FAT_cursors_hideCursor3();
    FAT_screenNotes_commitCursorMove();
    if (FAT_screenNotes_currentSelectedColumn == 0) {
        FAT_cursors_showCursor3();
    } else {
        FAT_cursors_showCursor2();
    }
    FAT_cursors_moveCursorChange(INPUT_R_CURSOR_CHANGE_X, INPUT_R_CURSOR_CHANGE_Y);
}

/**
 * \brief Test des actions utilisateurs sur les touches. 
 */
void FAT_screenNotes_checkButtons() {
    hel_PadCapture();
    
    if (hel_PadQuery()->Held.Select) {
        if (!FAT_screenNotes_isPopuped) {
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenNotes_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenNotes_isPopuped) {
            FAT_popup_hide();
            if (FAT_screenNotes_currentSelectedColumn == 0) {
                FAT_cursors_showCursor3();
            } else {
                FAT_cursors_showCursor2();
            }
            FAT_screenNotes_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_NOTES_ID) {
                FAT_cursors_hideCursor3();
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), SCREEN_NOTES_ID);
            }
        }


        if (hel_PadQuery()->Held.A || hel_PadQuery()->Pressed.A) {
            FAT_screenNotes_pressOrHeldA();

        } else {

            if (hel_PadQuery()->Held.R) {
                FAT_cursors_showCursorChange();

                if (hel_PadQuery()->Pressed.Right) {
                    if (FAT_screenNotes_currentBlockId < NB_MAX_BLOCKS - 1) {
                        FAT_screenNotes_currentBlockId++;
                        FAT_screenNotes_printBlockNumber();
                        FAT_screenNotes_printAllScreenText();
                    }
                }

                if (hel_PadQuery()->Pressed.Left) {
                    if (FAT_screenNotes_currentBlockId > 0) {
                        FAT_screenNotes_currentBlockId--;
                        FAT_screenNotes_printBlockNumber();
                        FAT_screenNotes_printAllScreenText();
                    }
                }

                if (hel_PadQuery()->Pressed.Down) {
                    // TODO passer au block suivant dans la séquence
                }

                if (hel_PadQuery()->Pressed.Up) {
                    // TODO passer au block précédent dans la séquence
                }

            } else {

                FAT_cursors_hideCursorChange();

                if (hel_PadQuery()->Pressed.B) {
                    FAT_screenNotes_pressB();
                }

                if (hel_PadQuery()->Pressed.Start) {
                    if (!FAT_isCurrentlyPlaying) {
                        FAT_player_startPlayerFromNotes(FAT_screenNotes_currentBlockId,
                                0, FAT_screenSong_currentSelectedColumn);
                    } else {
                        FAT_player_stopPlayer();
                    }
                }

                if (hel_PadQuery()->Pressed.Right) {
                    FAT_screenNotes_moveCursorRight();
                }

                if (hel_PadQuery()->Pressed.Left) {
                    FAT_screenNotes_moveCursorLeft();
                }

                if (hel_PadQuery()->Pressed.Down) {
                    if (hel_PadQuery()->Held.L) {
                        FAT_screenNotes_moveCursorAllDown();
                    } else {
                        FAT_screenNotes_moveCursorDown();
                    }
                }

                if (hel_PadQuery()->Pressed.Up) {
                    if (hel_PadQuery()->Held.L) {
                        FAT_screenNotes_moveCursorAllUp();
                    } else {
                        FAT_screenNotes_moveCursorUp();
                    }
                }

                FAT_screenNotes_commitCursorMove();
            }

            if (hel_PadQuery()->Pressed.R && hel_PadQuery()->Pressed.L) {
                FAT_showHelp(SCREEN_NOTES_ID);
            }
        }
    }
}

/**
 * \brief Cette fonction est dédiée aux interactions avec la touche B. 
 */
void FAT_screenNotes_pressB() {
    switch (FAT_screenNotes_currentSelectedColumn) {
        case SCREENNOTES_COLUMN_ID_NOTES:
        case SCREENNOTES_COLUMN_ID_INST:
            if (FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {
                FAT_data_pasteNote(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            } else {
                FAT_data_cutNote(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            }
            FAT_screenNotes_printNote(FAT_screenNotes_currentSelectedLine);
            break;
        case SCREENNOTES_COLUMN_ID_CMD_NAME:
        case SCREENNOTES_COLUMN_ID_CMD_PARAM:
            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {
                FAT_data_note_pasteEffect(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            } else {
                FAT_data_note_cutEffect(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine);
            }
            FAT_screenNotes_printEffect(FAT_screenNotes_currentSelectedLine);
            break;
    }
}

/**
 * \brief Cette fonction est dédiée aux interactions avec la touche A. 
 */
void FAT_screenNotes_pressOrHeldA() {
    switch (FAT_screenNotes_currentSelectedColumn) {
        case SCREENNOTES_COLUMN_ID_NOTES:
            if (FAT_data_isNoteEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_addDefaultNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, FAT_screenSong_currentSelectedColumn);

            }

            if (hel_PadQuery()->Pressed.Right) {
                FAT_data_note_changeValue(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1); // ajout de 1

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                    FAT_screenNotes_currentSelectedLine);
                }
            }

            if (hel_PadQuery()->Pressed.Left) {
                FAT_data_note_changeValue(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1); // retrait de 1

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                    FAT_screenNotes_currentSelectedLine);
                }
            }


            if (hel_PadQuery()->Pressed.Up && (FAT_screenSong_currentSelectedColumn < INSTRUMENT_TYPE_SAMPLEA)) {
                FAT_data_note_changeOctave(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                    FAT_screenNotes_currentSelectedLine);
                }
            }

            if (hel_PadQuery()->Pressed.Down && (FAT_screenSong_currentSelectedColumn < INSTRUMENT_TYPE_SAMPLEA)) {
                FAT_data_note_changeOctave(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                    FAT_screenNotes_currentSelectedLine);
                }
            }

            if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && hel_PadQuery()->Pressed.A) {
                FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
            }

            break;

        case SCREENNOTES_COLUMN_ID_INST:

            if (hel_PadQuery()->Held.L) {
                FAT_data_note_smartChangeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
            } else {

                if (hel_PadQuery()->Pressed.Right) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, 1);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                                    FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                                    FAT_screenNotes_currentSelectedLine);
                    }
                }

                if (hel_PadQuery()->Pressed.Left) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, -1);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
                    }
                }

                if (hel_PadQuery()->Pressed.Up) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, 16);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
                    }
                }

                if (hel_PadQuery()->Pressed.Down) {
                    FAT_data_note_changeInstrument(FAT_screenSong_currentSelectedColumn, FAT_screenNotes_currentBlockId,
                            FAT_screenNotes_currentSelectedLine, -16);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
                    }
                }
            }

            if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && hel_PadQuery()->Pressed.A) {
                FAT_data_note_previewNote(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);
            }

            break;

        case SCREENNOTES_COLUMN_ID_CMD_NAME:

            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_note_addDefaultEffect(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);

            }

            if (hel_PadQuery()->Pressed.Right) {
                FAT_data_note_changeEffectName(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);
            }

            if (hel_PadQuery()->Pressed.Left) {
                FAT_data_note_changeEffectName(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);
            }

            break;

        case SCREENNOTES_COLUMN_ID_CMD_PARAM:

            if (FAT_data_note_isEffectEmpty(FAT_screenNotes_currentBlockId, FAT_screenNotes_currentSelectedLine)) {

                FAT_data_note_addDefaultEffect(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine);

            }

            if (hel_PadQuery()->Pressed.Right) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 1);
            }

            if (hel_PadQuery()->Pressed.Left) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -1);
            }

            if (hel_PadQuery()->Pressed.Up) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, 16);
            }

            if (hel_PadQuery()->Pressed.Down) {
                FAT_data_note_changeEffectValue(FAT_screenNotes_currentBlockId,
                        FAT_screenNotes_currentSelectedLine, -16);
            }

            break;
    }

    FAT_screenNotes_printNote(FAT_screenNotes_currentSelectedLine);
    FAT_screenNotes_printEffect(FAT_screenNotes_currentSelectedLine);

}

#endif
