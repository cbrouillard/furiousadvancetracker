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
 * \file screen_composer.h
 * \brief Fichier réservé pour la gestion de l'écran COMPOSER.
 */

#ifndef _SCREEN_COMPOSER_H_
#define	_SCREEN_COMPOSER_H_

/** \brief Id de la colonne des notes. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_NOTES 0
/** \brief Id de la colonne des instrument. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_INST 1
/** \brief Id de la colonne du nom de la commande. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_CMD_NAME 2
/** \brief Id de la colonne de la valeur de la commande. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_CMD_PARAM 3
/** \brief Id de la colonne channel. Utile pour la gestion du curseur. */
#define SCREENCOMPOSER_COLUMN_ID_CHANNEL 4
/** \brief Nombre de lignes affichées dans le composer. */
#define SCREENCOMPOSER_NB_LINES_ON_SCREEN 8
/** \brief Définit le nombre de paramètre modifiables dans l'écran. */
#define SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN 2

/** \brief Numéro de case tile ou commence l'affichage des notes. */
#define SCREENCOMPOSER_NOTE_LINE_X 10
/** \brief Numéro de case tile ou commence l'affichage des notes. */
#define SCREENCOMPOSER_LINE_START_Y 7
/** \brief Numéro de touche L: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_L 0
/** \brief Numéro de touche R: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_R 1
/** \brief Numéro de touche A: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_A 2
/** \brief Numéro de touche B: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_B 3
/** \brief Numéro de touche UP: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_UP 4
/** \brief Numéro de touche RIGHT: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_RIGHT 5
/** \brief Numéro de touche DOWN: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_DOWN 6
/** \brief Numéro de touche LEFT: utile pour la lecture de la note associée. */
#define SCREENCOMPOSER_BTN_LEFT 7

/** \brief Permet de savoir si l'écran BLOCKS est actuellement "popupé". */
bool FAT_screenComposer_isPopuped = 0;
/** \brief Le compositeur est lockable : lorsqu'il est locké l'appui sur les touches déclenche la lecture des notes associés. */
u8 FAT_screenComposer_isLocked = 0;

// prototypes
void FAT_screenComposer_init();
void FAT_screenComposer_checkButtons();
void FAT_screenComposer_printInfos();
void FAT_screenComposer_printAllScreenText();
void FAT_screenComposer_printColumns();
void FAT_screenComposer_pressA();
void FAT_screenComposer_pressB();
void FAT_screenComposer_switchLocking();
void FAT_screenComposer_playAffectedNotes();

#include "screen_composer_cursor.h"

/**
 * \brief Fonction callback principale pour l'écran COMPOSER.
 */
void FAT_screenComposer_mainFunc() {
    if (mutex) {
        ham_CopyObjToOAM();
        if (iCanPressAKey) {
            FAT_screenComposer_checkButtons();
        }
    }
}

/**
 * \brief Affiche les informations "dynamiques" dans l'écran COMPOSER (numéro de ligne, ...). 
 */
void FAT_screenComposer_printInfos() {
    mutex = 0;
    ham_DrawText(19, 3, "COMPOSER %.1x", 0);
    ham_DrawText(19, 4, "LINE    %.2x",
            FAT_screenComposer_currentSelectedLine);
    //ham_DrawText(21, 4, "CHAN %2x", FAT_screenSong_currentSelectedColumn+1);

    ham_DrawText(1, 3, "TRANSPOSE  %.2x", FAT_tracker.composer.transpose);
    ham_DrawText(1, 4, "KEY REPEAT %.2x", FAT_tracker.composer.keyRepeat);
    mutex = 1;
}

/**
 * \brief Affiche une seule note sur la grille du COMPOSER. 
 * 
 * @param line le numéro de ligne à afficher
 */
void FAT_screenComposer_printNote(u8 line) {
    mutex = 0;
    if (!FAT_data_composer_isNoteEmpty(line)) {
        note* actualNote = FAT_data_composer_getNote(line);

        ham_DrawText(SCREENCOMPOSER_NOTE_LINE_X,
                line + SCREENCOMPOSER_LINE_START_Y,
                "%s%1x %.2x      %.1x\0",
                noteName[(actualNote->note & 0xf0) >> 4], actualNote->note & 0x0f, actualNote->instrument,
                //                FAT_data_getInstrumentType(actualNote->instrument) + 1
                FAT_tracker.composer.channels[line] + 1
                );
    } else {
        ham_DrawText(SCREENCOMPOSER_NOTE_LINE_X,
                line + SCREENCOMPOSER_LINE_START_Y, "             \0");
    }
    mutex = 1;
}

/**
 * \brief Affiche toutes les notes du COMPOSER. 
 */
void FAT_screenComposer_printAllNote() {
    mutex = 0;
    for (u8 b = 0; b < SCREENCOMPOSER_NB_LINES_ON_SCREEN; b++) {
        FAT_screenComposer_printNote(b);
    }
    mutex = 1;
}

/**
 * \brief Affiche l'information de locking: si le COMPOSER est UNLOCKED, alors on peut
 * éditer les notes. Dans le cas contraire, les notes sont jouées lors de l'appui sur les bouttons. 
 */
void FAT_screenComposer_printLocking() {
    if (FAT_screenComposer_isLocked) {
        ham_DrawText(7, 16, "MODE   LOCKED");
    } else {
        ham_DrawText(7, 16, "MODE UNLOCKED");
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
    mutex = 0;
    ham_DrawText(7, 7, " L");
    ham_DrawText(7, 8, " R");
    ham_DrawText(7, 9, " A");
    ham_DrawText(7, 10, " B");
    ham_DrawText(7, 11, "UP");
    ham_DrawText(7, 12, "RT");
    ham_DrawText(7, 13, "DW");
    ham_DrawText(7, 14, "LF");
    mutex = 1;
}

/**
 * \brief Fonction d'initialisation.
 */
void FAT_screenComposer_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_composer_Tiles, SIZEOF_16BIT(screen_composer_Tiles), 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_composer_Map, 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    FAT_screenComposer_isLocked = 0;

    // affichage d'un peu de texte
    FAT_screenComposer_printColumns();
    FAT_screenComposer_printAllScreenText();
    FAT_screenComposer_printLocking();

    // démarrage du cycle pour l'écran
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_screenComposer_mainFunc);

    // curseur
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
    if (F_CTRLINPUT_SELECT_PRESSED) {
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
                } else if (FAT_screenComposer_currentSelectedColumn == SCREENCOMPOSER_COLUMN_ID_CHANNEL){
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
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (FAT_screenComposer_isLocked) {

            FAT_screenComposer_playAffectedNotes();

        } else {
            if (F_CTRLINPUT_A_PRESSED) {
                FAT_screenComposer_pressA();
            } else {

                if (F_CTRLINPUT_B_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_screenComposer_pressB();
                }

                if (F_CTRLINPUT_R_PRESSED && F_CTRLINPUT_L_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_showHelp(SCREEN_COMPOSER_ID);
                }

                if (F_CTRLINPUT_START_PRESSED) {
                    // lock/unlock le compositeur
                    iCanPressAKey = 0;
                    FAT_screenComposer_switchLocking();
                }

                if (F_CTRLINPUT_RIGHT_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_screenComposer_moveCursorRight();
                }

                if (F_CTRLINPUT_LEFT_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_screenComposer_moveCursorLeft();
                }

                if (F_CTRLINPUT_DOWN_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_screenComposer_moveCursorDown();
                }

                if (F_CTRLINPUT_UP_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_screenComposer_moveCursorUp();

                }
                FAT_screenComposer_commitCursorMove();
            }

            FAT_keys_waitForAnotherKeyTouch();
        }
    }
}

/**
 * \brief Fonction spécialisée dans la gestion de la touche A. 
 */
void FAT_screenComposer_pressA() {

    if (FAT_screenComposer_currentSelectedLine >= SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN) {
        u8 realLine = FAT_screenComposer_currentSelectedLine - SCREENCOMPOSER_NB_PARAMETERS_ON_SCREEN;
        switch (FAT_screenComposer_currentSelectedColumn) {
            case SCREENCOMPOSER_COLUMN_ID_NOTES:
                if (FAT_data_composer_isNoteEmpty(realLine)) {
                    // espace libre
                    FAT_data_composer_addDefaultNote(realLine);
                }

                if (F_CTRLINPUT_RIGHT_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeValue(realLine, 1); // ajout de 1
                }

                if (F_CTRLINPUT_LEFT_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeValue(realLine, -1);
                }

                if (F_CTRLINPUT_UP_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeOctave(realLine, 1); // ajout de 1
                }

                if (F_CTRLINPUT_DOWN_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeOctave(realLine, -1);
                }

                if (FAT_data_isPreviewEnabled()) {
                    FAT_data_composer_previewNote(realLine);
                }

                break;
            case SCREENCOMPOSER_COLUMN_ID_INST:
                if (F_CTRLINPUT_L_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_smartChangeInstrument(realLine);
                } else {

                    if (F_CTRLINPUT_RIGHT_PRESSED) {
                        iCanPressAKey = 0;
                        FAT_data_composer_changeInstrument(realLine, 1);
                    }

                    if (F_CTRLINPUT_LEFT_PRESSED) {
                        iCanPressAKey = 0;
                        FAT_data_composer_changeInstrument(realLine, -1);
                    }

                    if (F_CTRLINPUT_UP_PRESSED) {
                        iCanPressAKey = 0;
                        FAT_data_composer_changeInstrument(realLine, 16);
                    }

                    if (F_CTRLINPUT_DOWN_PRESSED) {
                        iCanPressAKey = 0;
                        FAT_data_composer_changeInstrument(realLine, -16);
                    }

                    if (FAT_data_isPreviewEnabled()) {
                        FAT_data_composer_previewNote(realLine);
                    }
                }
                break;
            case SCREENCOMPOSER_COLUMN_ID_CMD_NAME:

                break;
            case SCREENCOMPOSER_COLUMN_ID_CMD_PARAM:

                break;
            case SCREENCOMPOSER_COLUMN_ID_CHANNEL:

                if (F_CTRLINPUT_L_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_resetAffectedChannel(realLine);
                } else {

                    if (F_CTRLINPUT_RIGHT_PRESSED) {
                        iCanPressAKey = 0;
                        FAT_data_composer_changeAffectedChannelValue(realLine, 1);
                    }

                    if (F_CTRLINPUT_LEFT_PRESSED) {
                        iCanPressAKey = 0;
                        FAT_data_composer_changeAffectedChannelValue(realLine, -1);
                    }
                }

                if (FAT_data_isPreviewEnabled()) {
                    FAT_data_composer_previewNote(realLine);
                }

                break;

        }

        FAT_screenComposer_printNote(realLine);
    } else {
        // on joue avec les paramètres
        switch (FAT_screenComposer_currentSelectedLine) {
            case 0: // param transpose
                if (F_CTRLINPUT_RIGHT_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeTranspose(0, 1);
                }
                if (F_CTRLINPUT_UP_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeTranspose(0, 16);
                }
                if (F_CTRLINPUT_LEFT_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeTranspose(0, -1);
                }
                if (F_CTRLINPUT_DOWN_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeTranspose(0, -16);
                }
                break;
            case 1: // param key repeat
                if (F_CTRLINPUT_RIGHT_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeKeyRepeat(0, 1);
                }
                if (F_CTRLINPUT_UP_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeKeyRepeat(0, 16);
                }
                if (F_CTRLINPUT_LEFT_PRESSED) {
                    iCanPressAKey = 0;
                    FAT_data_composer_changeKeyRepeat(0, -1);
                }
                if (F_CTRLINPUT_DOWN_PRESSED) {
                    iCanPressAKey = 0;
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
    if (FAT_tracker.composer.keyRepeat) {
        iCanPressAKey = 0;
    }

    if (F_CTRLINPUT_START_PRESSED) {
        iCanPressAKey = 0;
        FAT_screenComposer_switchLocking();
    }

    if (F_CTRLINPUT_A_PRESSED) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_A);
    }

    if (F_CTRLINPUT_B_PRESSED) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_B);
    }

    if (F_CTRLINPUT_R_PRESSED) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_R);
    }

    if (F_CTRLINPUT_L_PRESSED) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_L);
    }

    if (F_CTRLINPUT_UP_PRESSED) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_UP);
    }

    if (F_CTRLINPUT_RIGHT_PRESSED) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_RIGHT);
    }

    if (F_CTRLINPUT_DOWN_PRESSED) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_DOWN);
    }

    if (F_CTRLINPUT_LEFT_PRESSED) {
        FAT_player_playComposerNote(SCREENCOMPOSER_BTN_LEFT);
    }

    if (FAT_tracker.composer.keyRepeat || iCanPressAKey == 0) {
        FAT_keys_waitForAnotherKeyTouch();
    }
}

#endif	/* SCREEN_COMPOSER_H */

