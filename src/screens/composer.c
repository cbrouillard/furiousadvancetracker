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
* \file composer.c
* \brief Ecran composer.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../headers/screen_composer.h"

/** \brief Permet de savoir si l'écran BLOCKS est actuellement "popupé". */
bool FAT_screenComposer_isPopuped = 0;
/** \brief Le compositeur est lockable : lorsqu'il est locké l'appui sur les touches déclenche la lecture des notes associés. */
u8 FAT_screenComposer_isLocked = 0;

/**
 * \brief Affiche les informations "dynamiques" dans l'écran COMPOSER (numéro de ligne, ...).
 */
void FAT_screenComposer_printInfos() {
    tracker* FAT_tracker = FAT_data_getTracker ();
    hel_BgTextPrintF(TEXT_LAYER, 18, 3, 0, "Composer  %.1x", 0);
    hel_BgTextPrintF(TEXT_LAYER, 18, 4, 0, "Line     %.2x",
            FAT_screenComposer_currentSelectedLine);

    hel_BgTextPrintF(TEXT_LAYER, 1, 3, 0, "Transpose  %.2x", FAT_tracker->composer.transpose);
    hel_BgTextPrintF(TEXT_LAYER, 1, 4, 0, "Key Repeat %.2x", FAT_tracker->composer.keyRepeat);
}

/**
 * \brief Affiche une seule note sur la grille du COMPOSER.
 *
 * @param line le numéro de ligne à afficher
 */
void FAT_screenComposer_printNote(u8 line) {
    if (!FAT_data_composer_isNoteEmpty(line)) {
        tracker* FAT_tracker = FAT_data_getTracker ();
        note* actualNote = FAT_data_composer_getNote(line);

        if (FAT_data_composer_getChannel(line) > INSTRUMENT_TYPE_NOISE) {

            hel_BgTextPrintF(TEXT_LAYER, SCREENCOMPOSER_NOTE_LINE_X,
                    line + SCREENCOMPOSER_LINE_START_Y, 0,
                    "S%.2x %.2x      %.1x\0",
                    actualNote->freq, actualNote->instrument,
                    FAT_tracker->composer.channels[line] + 1
                    );

        } else {

            hel_BgTextPrintF(TEXT_LAYER, SCREENCOMPOSER_NOTE_LINE_X,
                    line + SCREENCOMPOSER_LINE_START_Y, 0,
                    "%s%1x %.2x      %.1x\0",
                    noteName[(actualNote->note & 0xf0) >> 4], actualNote->note & 0x0f, actualNote->instrument,
                    FAT_tracker->composer.channels[line] + 1
                    );
        }
    } else {
        hel_BgTextPrint(TEXT_LAYER, SCREENCOMPOSER_NOTE_LINE_X,
                line + SCREENCOMPOSER_LINE_START_Y, 0, "             ");
    }
}

/**
 * \brief Affiche toutes les notes du COMPOSER.
 */
void FAT_screenComposer_printAllNote() {
    u8 b;
    for (b = 0; b < SCREENCOMPOSER_NB_LINES_ON_SCREEN; b++) {
        FAT_screenComposer_printNote(b);
    }
}

/**
 * \brief Affiche l'information de locking: si le COMPOSER est UNLOCKED, alors on peut
 * éditer les notes. Dans le cas contraire, les notes sont jouées lors de l'appui sur les bouttons.
 */
void FAT_screenComposer_printLocking() {
    if (FAT_screenComposer_isLocked) {
        hel_BgTextPrint(TEXT_LAYER, 7, 16, 0, "MODE   LOCKED");
    } else {
        hel_BgTextPrint(TEXT_LAYER, 7, 16, 0, "MODE UNLOCKED");
    }
}

/**
 * \brief Fonction wrapping qui permet d'afficher des choses intéressantes à l'écran.
 */
void FAT_screenComposer_printAllScreenText() {
    FAT_screenComposer_printInfos();
    FAT_screenComposer_printAllNote();
}

/**
 * \brief Fonction appelée à l'initialisation afin d'imprimer le numéro des lignes sur l'écran.
 */
void FAT_screenComposer_printColumns() {
    hel_BgTextPrint(TEXT_LAYER, 7, 7, 0, " L");
    hel_BgTextPrint(TEXT_LAYER, 7, 8, 0, " R");
    hel_BgTextPrint(TEXT_LAYER, 7, 9, 0, " A");
    hel_BgTextPrint(TEXT_LAYER, 7, 10, 0, " B");
    hel_BgTextPrint(TEXT_LAYER, 7, 11, 0, "UP");
    hel_BgTextPrint(TEXT_LAYER, 7, 12, 0, "RT");
    hel_BgTextPrint(TEXT_LAYER, 7, 13, 0, "DW");
    hel_BgTextPrint(TEXT_LAYER, 7, 14, 0, "LF");
}

/**
 * \brief Fonction d'initialisation.
 */
void FAT_screenComposer_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_COMPOSER_RAW), RES_SCREEN_COMPOSER_RAW_SIZE16, 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_COMPOSER_MAP), 640, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    FAT_screenComposer_isLocked = 0;

    // affichage d'un peu de texte
    FAT_screenComposer_printColumns();
    FAT_screenComposer_printAllScreenText();
    FAT_screenComposer_printLocking();

    // démarrage du cycle pour l'écran
    //hel_IntrUpdateHandler(INT_TYPE_VBL, (void*) &FAT_screenComposer_mainFunc);

    // curseur
    FAT_player_hideAllCursors ();
    FAT_cursors_hideCursor2();
    FAT_cursors_hideCursor3();
    FAT_cursors_hideCursor1();
    if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_NOTES && FAT_screenComposer_currentSelectedLine > 1) {
        FAT_cursors_showCursor3();
    } else if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_CHANNEL && FAT_screenComposer_currentSelectedLine > 1) {
        FAT_cursors_showCursor1();
    } else {
        FAT_cursors_showCursor2();
    }
    FAT_screenComposer_commitCursorMove();
}

/**
 * \brief Permet de tester l'appui sur les boutons et de réagir en conséquence.
 */
void FAT_screenComposer_checkButtons() {
    hel_PadCapture();

    if ( FAT_data_isCurrentlySimulating() == TRUE && !FAT_isCurrentlyPlaying && (
                        hel_PadQuery()->Pressed.Start ||
                        hel_PadQuery()->Pressed.Select ||
                        hel_PadQuery()->Pressed.A ||
                        hel_PadQuery()->Pressed.B ||
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
        if (!FAT_screenComposer_isPopuped) {
            FAT_cursors_hideCursor3();
            FAT_cursors_hideCursor2();
            FAT_cursors_hideCursor1();
            FAT_popup_show();
            FAT_screenComposer_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenComposer_isPopuped) {
            FAT_popup_hide();
            if (!FAT_screenComposer_isLocked) {
                if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_NOTES) {
                    FAT_cursors_showCursor3();
                } else if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_CHANNEL) {
                    FAT_cursors_showCursor1();
                } else {
                    FAT_cursors_showCursor2();
                }

            }
            FAT_screenComposer_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_COMPOSER_ID) {
                FAT_cursors_hideCursor3();
                FAT_cursors_hideCursor2();
                FAT_cursors_hideCursor1();
                FAT_switchToScreen(FAT_popup_getSelectedIcon(), SCREEN_COMPOSER_ID);
            }
        }

        if (FAT_screenComposer_isLocked) {

            FAT_screenComposer_playAffectedNotes();

        } else {
            if (hel_PadQuery()->Held.A || hel_PadQuery()->Pressed.A) {
                FAT_screenComposer_pressOrHeldA();
            } else {

                if (hel_PadQuery()->Pressed.B) {
                    FAT_screenComposer_pressB();
                }

                if (hel_PadQuery()->Pressed.R && hel_PadQuery()->Pressed.L) {
                    FAT_showHelp(SCREEN_COMPOSER_ID);
                }

                if (hel_PadQuery()->Pressed.Start) {
                    // lock/unlock le compositeur
                    FAT_screenComposer_switchLocking();
                }

                if (hel_PadQuery()->Pressed.Right) {
                    FAT_screenComposer_moveCursorRight();
                }

                if (hel_PadQuery()->Pressed.Left) {
                    FAT_screenComposer_moveCursorLeft();
                }

                if (hel_PadQuery()->Pressed.Down) {
                    FAT_screenComposer_moveCursorDown();
                }

                if (hel_PadQuery()->Pressed.Up) {
                    FAT_screenComposer_moveCursorUp();

                }
                FAT_screenComposer_commitCursorMove();
            }

        }
    }
}

/**
 * \brief Fonction spécialisée dans la gestion de la touche A.
 */
void FAT_screenComposer_pressOrHeldA() {

    if (FAT_screenComposer_currentSelectedLine >= SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN) {
        u8 realLine = FAT_screenComposer_currentSelectedLine - SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN;
        switch (FAT_screenComposer_currentSelectedColumn) {
            case SCREENCOMPOSER_COLUMN_ID_NOTES:
                if (FAT_data_composer_isNoteEmpty(realLine)) {
                    // espace libre
                    FAT_data_composer_addDefaultNote(realLine);
                }

                if (hel_PadQuery()->Pressed.Right) {
                    FAT_data_composer_changeValue(realLine, 1); // ajout de 1

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_composer_previewNote(realLine);
                    }
                }

                if (hel_PadQuery()->Pressed.Left) {
                    FAT_data_composer_changeValue(realLine, -1);

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                        FAT_data_composer_previewNote(realLine);
                    }
                }

                if (hel_PadQuery()->Pressed.Up) {
					if (FAT_data_composer_getChannel(realLine) <= INSTRUMENT_TYPE_NOISE){
                        FAT_data_composer_changeOctave(realLine, 1); // ajout de 1
                        if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                            FAT_data_composer_previewNote(realLine);
                        }
					}
                }

                if (hel_PadQuery()->Pressed.Down) {
					if (FAT_data_composer_getChannel(realLine) <= INSTRUMENT_TYPE_NOISE) {
                        FAT_data_composer_changeOctave(realLine, -1);
                        if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying) {
                            FAT_data_composer_previewNote(realLine);
                        }
					}
                }

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && hel_PadQuery()->Pressed.A) {
                    FAT_data_composer_previewNote(realLine);
                }

                break;
            case SCREENCOMPOSER_COLUMN_ID_INST:
                if (hel_PadQuery()->Held.L) {
                    FAT_data_composer_smartChangeInstrument(realLine);
                } else {

                    if (hel_PadQuery()->Pressed.Right) {
                        FAT_data_composer_changeInstrument(realLine, 1);
                    }

                    if (hel_PadQuery()->Pressed.Left) {
                        FAT_data_composer_changeInstrument(realLine, -1);
                    }

                    if (hel_PadQuery()->Pressed.Up) {
                        FAT_data_composer_changeInstrument(realLine, 16);
                    }

                    if (hel_PadQuery()->Pressed.Down) {
                        FAT_data_composer_changeInstrument(realLine, -16);
                    }

                    if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && hel_PadQuery()->Pressed.A) {
                        FAT_data_composer_previewNote(realLine);
                    }
                }
                break;
            case SCREENCOMPOSER_COLUMN_ID_CMD_NAME:

                break;
            case SCREENCOMPOSER_COLUMN_ID_CMD_PARAM:

                break;
            case SCREENCOMPOSER_COLUMN_ID_CHANNEL:

                if (hel_PadQuery()->Held.L) {
                    FAT_data_composer_resetAffectedChannel(realLine);
                } else {

                    if (hel_PadQuery()->Pressed.Right) {
                        FAT_data_composer_changeAffectedChannelValue(realLine, 1);
                    }

                    if (hel_PadQuery()->Pressed.Left) {
                        FAT_data_composer_changeAffectedChannelValue(realLine, -1);
                    }
                }

                if (FAT_data_isPreviewEnabled() && !FAT_isCurrentlyPlaying && hel_PadQuery()->Pressed.A) {
                    FAT_data_composer_previewNote(realLine);
                }

                break;

        }

        FAT_screenComposer_printNote(realLine);
    } else {
        // on joue avec les paramètres
        switch (FAT_screenComposer_currentSelectedLine) {
            case 0: // param transpose
                if (hel_PadQuery()->Pressed.Right) {
                    FAT_data_composer_changeTranspose(0, 1);
                }
                if (hel_PadQuery()->Pressed.Up) {
                    FAT_data_composer_changeTranspose(0, 16);
                }
                if (hel_PadQuery()->Pressed.Left) {
                    FAT_data_composer_changeTranspose(0, -1);
                }
                if (hel_PadQuery()->Pressed.Down) {
                    FAT_data_composer_changeTranspose(0, -16);
                }
                break;
            case 1: // param key repeat
                if (hel_PadQuery()->Pressed.Right) {
                    FAT_data_composer_changeKeyRepeat(0, 1);
                }
                if (hel_PadQuery()->Pressed.Up) {
                    FAT_data_composer_changeKeyRepeat(0, 16);
                }
                if (hel_PadQuery()->Pressed.Left) {
                    FAT_data_composer_changeKeyRepeat(0, -1);
                }
                if (hel_PadQuery()->Pressed.Down) {
                    FAT_data_composer_changeKeyRepeat(0, -16);
                }
                break;
        }

        FAT_screenComposer_printInfos();
    }
}

/**
 * \brief Fonction spécialisée dans la gestion de la touche B.
 */
void FAT_screenComposer_pressB() {
    if (FAT_screenComposer_currentSelectedLine >= SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN) {
        u8 realLine = FAT_screenComposer_currentSelectedLine - SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN;
        if (FAT_data_composer_isNoteEmpty(realLine)) {
            FAT_data_composer_pasteNote(realLine);
        } else {
            FAT_data_composer_cutNote(realLine);
        }

        FAT_screenComposer_printNote(realLine);
    }
}

/**
 * \brief Permet de passer du mode UNLOCKED à LOCKED et vice-versa.
 */
void FAT_screenComposer_switchLocking() {
    FAT_screenComposer_isLocked ^= 1;
    FAT_screenComposer_printLocking();

    if (FAT_screenComposer_isLocked) {
        FAT_cursors_hideCursor2();
        FAT_cursors_hideCursor3();
        FAT_cursors_hideCursor1();
    } else {
        if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_NOTES) {
            FAT_cursors_showCursor3();
        } else if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_CHANNEL) {
            FAT_cursors_showCursor1();
        } else {
            FAT_cursors_showCursor2();
        }
    }
}

/**
 * \brief Joue la note affecté à un bouton. <b>ATTENTION!</b>, cette fonction
 * teste elle même l'appui sur les touches.
 */
void FAT_screenComposer_playAffectedNotes() {
    if (hel_PadQuery()->Pressed.Start) {
        FAT_screenComposer_switchLocking();
    }

    if (hel_PadQuery()->Pressed.A) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_A);
    }

    if (hel_PadQuery()->Pressed.B) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_B);
    }

    if (hel_PadQuery()->Pressed.R) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_R);
    }

    if (hel_PadQuery()->Pressed.L) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_L);
    }

    if (hel_PadQuery()->Pressed.Up) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_UP);
    }

    if (hel_PadQuery()->Pressed.Right) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_RIGHT);
    }

    if (hel_PadQuery()->Pressed.Down) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_DOWN);
    }

    if (hel_PadQuery()->Pressed.Left) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_LEFT);
    }
}
