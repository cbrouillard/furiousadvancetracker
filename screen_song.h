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
 * \file screen_song.h
 * \brief Ce fichier définit toutes les fonctions pour gérer l'écran SONG.
 */

#ifndef _SCREEN_SONG_H_
#define _SCREEN_SONG_H_

/** \brief Le nombre maximal de ligne affichées à l'écran. */
#define SCREENSONG_NB_LINES_ON_SCREEN 16
/** \brief Définition interface : numéro de la tile pour début de l'affichage (Y). */
#define SCREENSONG_LINE_START_Y 2
/** \brief Définition interface : numéro de la tile pour début de l'affichage des lignes ! (X). */
#define SCREENSONG_LINE_X 0
/** \brief Définition interface : taille que prend une ligne en tile (1). */
#define SCREENSONG_LINE_SIZE_Y 1
/** \brief Définition interface : numéro de la tile pour début de l'affichage des séquences (X). */
#define SCREENSONG_SEQUENCE_LINE_X 3

/** \brief Cette variable contient le numéro de la première ligne actuellement affichée. */
u8 FAT_screenSong_currentStartLine = 0;
/** 
 * \brief cette variable permet de savoir si l'écran song est actuellement sous la popup. 
 * \todo cette variable pourrait etre mutualisée pour tous les écrans ?
 */
bool FAT_screenSong_isPopuped = 0;

// prototypes
void FAT_screenSong_init();
void FAT_screenSong_mainFunc();
void FAT_screenSong_checkButtons();
void FAT_screenSong_printLineColumns();
void FAT_screenSong_printAllScreenText();
void FAT_screenSong_printChannelFollower();
void FAT_screenSong_printInfos();
void FAT_screenSong_pressOrHeldA();
void FAT_screenSong_pressB();
////////////////////////////////////////////////////

#include "screen_song_cursor.h"

/** \brief Stocke tous les noms des channels (afin de pouvoir les afficher). */
const char* CHANNEL_NAME[6] = {"PU1\0", "PU2\0", "WAV\0", "NOI\0", "SNA\0", "SNB\0"};

/**
 * \brief Fonction principale de l'écran (callback).
 */
void FAT_screenSong_mainFunc() {
    ham_CopyObjToOAM();
    hel_IntrAcknowledge(INT_TYPE_VBL);

    FAT_screenSong_checkButtons();

}

/**
 * \brief Cette fonction permet d'initialiser l'écran.
 */
void FAT_screenSong_init() {

    FAT_reinitScreen();


    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*) screen_song_Tiles, SIZEOF_16BIT(screen_song_Tiles), 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void *) screen_song_Map, 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    // affichage du numéro des lignes, des séquences, ...
    FAT_screenSong_printAllScreenText();
    FAT_screenSong_printChannelFollower();

    // démarrage du cycle pour l'écran
    //hel_IntrUpdateHandler(INT_TYPE_VBL, (void*) &FAT_screenSong_mainFunc);

    // affichage du curseur
    FAT_cursors_hideCursor2();
    FAT_screenSong_commitCursorMove();
    FAT_cursors_showCursor2();
}

/**
 * \brief Cette fonction se contente d'ecrire le nom des channels dans la 
 * boite rouge sur l'écran SONG. Ne devrait pas être appelé plusieurs fois.
 */
void FAT_screenSong_printChannelFollower() {
    mutex = 0;
    hel_BgTextPrintF(TEXT_LAYER, 22, 9, 0, "%s ---", CHANNEL_NAME[0]);
    hel_BgTextPrintF(TEXT_LAYER, 22, 10, 0, "%s ---", CHANNEL_NAME[1]);
    hel_BgTextPrintF(TEXT_LAYER, 22, 11, 0, "%s ---", CHANNEL_NAME[2]);
    hel_BgTextPrintF(TEXT_LAYER, 22, 12, 0, "%s ---", CHANNEL_NAME[3]);
    hel_BgTextPrintF(TEXT_LAYER, 22, 13, 0, "%s ---", CHANNEL_NAME[4]);
    hel_BgTextPrintF(TEXT_LAYER, 22, 14, 0, "%s ---", CHANNEL_NAME[5]);
    mutex = 1;
}

/**
 * \brief Affiche la note actuellement jouée dans la boite rouge de l'écran SONG.
 * @param channel le numéro de canal
 * @param noteName le nom de la note
 * @param noteOctave l'octave de la note
 */
void FAT_screenSong_showActualPlayedNote(u8 channel, u8 name, u8 noteOctave, u8 freq) {
    mutex = 0;
    if (channel < INSTRUMENT_TYPE_SAMPLEA) {
        hel_BgTextPrintF(TEXT_LAYER, 26, channel + 9, 0, "%s%.1x", noteName[name], noteOctave);
    } else {
        hel_BgTextPrintF(TEXT_LAYER, 26, channel + 9, 0, "S%.2x", freq);
    }
    mutex = 1;
}

/**
 * \brief Affiche quelques infos (nom du projet, ligne actuellement sélectionnée et nom du channel)
 * sur l'écran. 
 */
void FAT_screenSong_printInfos() {
    mutex = 0;
    hel_BgTextPrintF(TEXT_LAYER, 21, 3, 0, "%s\nLine  %.2x\nChan %s", FAT_tracker.songName, FAT_screenSong_currentSelectedLine, CHANNEL_NAME[FAT_screenSong_currentSelectedColumn]);
    //hel_BgTextPrintF(TEXT_LAYER, 21, 4, "LINE  %.2x", FAT_screenSong_currentSelectedLine);
    //hel_BgTextPrintF(TEXT_LAYER, 21, 5, "CHAN %s", CHANNEL_NAME[FAT_screenSong_currentSelectedColumn]);
    mutex = 1;
}

/**
 * \brief Imprime les numéros de lignes. 
 * 
 * L'impression démarre depuis la valeur de FAT_screenSong_currentStartLine jusqu'à FAT_screenSong_currentStartLine + SCREENSONG_NB_LINES_ON_SCREEN
 */
void FAT_screenSong_printLineColumns() {
    u8 y = SCREENSONG_LINE_START_Y;
    mutex = 0;
    for (int c = FAT_screenSong_currentStartLine; c < (SCREENSONG_NB_LINES_ON_SCREEN + FAT_screenSong_currentStartLine); c++) {
        hel_BgTextPrintF(TEXT_LAYER, SCREENSONG_LINE_X, y, 0, FAT_FORMAT_LINE, c);
        y += SCREENSONG_LINE_SIZE_Y;
    }
    mutex = 1;
}

/**
 * \brief Affiche toutes les séquences actuellement visibles.  
 */
void FAT_screenSong_printSequences() {
    u8 c;
    mutex = 0;
    for (u8 v = 0; v < SCREENSONG_NB_LINES_ON_SCREEN; v++) {

        for (c = 0; c < 6; c++) {
            if (FAT_tracker.channels[c].sequences[v + FAT_screenSong_currentStartLine] == NULL_VALUE) {
                hel_BgTextPrint(TEXT_LAYER, SCREENSONG_SEQUENCE_LINE_X + (c * 3),
                        v + SCREENSONG_LINE_START_Y, 0, "  ");
            } else {
                hel_BgTextPrintF(TEXT_LAYER, SCREENSONG_SEQUENCE_LINE_X + (c * 3),
                        v + SCREENSONG_LINE_START_Y, 0, "%.2x ",
                        FAT_tracker.channels[c].sequences[v + FAT_screenSong_currentStartLine]);
            }
        }

    }
    mutex = 1;
}

/**
 * \brief Affiche une seule séquence. 
 *  
 * @param channel le numéro de channel sur lequel la séquence est inscrite
 * @param lineOnScreen le numéro de ligne à l'écran, compris entre 0 et SCREENSONG_NB_LINES_ON_SCREEN
 * @param realLine le vrai numéro de ligne dans le tracker ou la séquence a été inscrite
 */
void FAT_screenSong_printSequence(u8 channel, u8 lineOnScreen, u8 realLine) {
    mutex = 0;
    if (FAT_tracker.channels[channel].sequences[realLine] != NULL_VALUE) {
        hel_BgTextPrintF(TEXT_LAYER, SCREENSONG_SEQUENCE_LINE_X + (3 * channel),
                lineOnScreen + SCREENSONG_LINE_START_Y, 0,
                "%.2x\0", FAT_tracker.channels[channel].sequences[realLine]);
    } else {
        hel_BgTextPrint(TEXT_LAYER, SCREENSONG_SEQUENCE_LINE_X + (3 * channel),
                lineOnScreen + SCREENSONG_LINE_START_Y, 0, "  ");
    }
    mutex = 1;
}

/**
 * \brief Affiche tout le texte à l'écran (numéros de lignes, séquences et infos).
 */
void FAT_screenSong_printAllScreenText() {
    FAT_screenSong_printLineColumns();
    FAT_screenSong_printSequences();
    FAT_screenSong_printInfos();
}

/**
 * \brief Cette fonction s'occupe de tester les interactions utilisateurs. 
 */
void FAT_screenSong_checkButtons() {

    hel_PadCapture();

    if (hel_PadQuery()->Held.Select) {
        if (!FAT_screenSong_isPopuped) {
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenSong_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenSong_isPopuped) {
            FAT_popup_hide();
            FAT_cursors_showCursor2();
            FAT_screenSong_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_SONG_ID) {
                FAT_cursors_hideCursor2();
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (hel_PadQuery()->Pressed.A || hel_PadQuery()->Held.A) {

            FAT_screenSong_pressOrHeldA();

        } else {

            if (hel_PadQuery()->Pressed.Start) {
                if (!FAT_isCurrentlyPlaying) {
                    FAT_player_startPlayerFromSequences(FAT_screenSong_currentSelectedLine);
                } else {
                    FAT_player_stopPlayer();
                }
            }

            if (hel_PadQuery()->Pressed.R && hel_PadQuery()->Pressed.L) {
                FAT_showHelp(SCREEN_SONG_ID);
            }

            if (hel_PadQuery()->Pressed.B) {
                FAT_screenSong_pressB();
            }

            if (hel_PadQuery()->Pressed.Right) {
                FAT_screenSong_moveCursorRight();
            }

            if (hel_PadQuery()->Pressed.Left) {
                FAT_screenSong_moveCursorLeft();
            }

            if (hel_PadQuery()->Pressed.Down) {
                if (hel_PadQuery()->Held.R) {
                    FAT_screenSong_movePageDown();
                } else if (hel_PadQuery()->Held.L) {
                    FAT_screenSong_moveCursorAllDown();
                } else {
                    FAT_screenSong_moveCursorDown();
                }
            }

            if (hel_PadQuery()->Pressed.Up) {
                if (hel_PadQuery()->Held.R) {
                    FAT_screenSong_movePageUp();
                } else if (hel_PadQuery()->Held.L) {
                    FAT_screenSong_moveCursorAllUp();
                } else {
                    FAT_screenSong_moveCursorUp();
                }
            }
            FAT_screenSong_commitCursorMove();
        }

    }

}

/**
 * \brief Cette fonction est dédiée à l'interaction avec la touche B. 
 */
void FAT_screenSong_pressB() {
    if (hel_PadQuery()->Held.L) {

        if (FAT_data_isSequenceAllocatable(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine)) {
            // espace vide
            FAT_data_pasteSequenceWithNewNumber(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        } else {
            FAT_data_cloneSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        }

    } else {

        if (FAT_data_isSequenceAllocatable(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine)) {
            // espace vide
            FAT_data_pasteSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        } else {
            FAT_data_cutSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine);
        }
    }

    FAT_screenSong_printSequence(FAT_screenSong_currentSelectedColumn, FAT_screenSong_currentSelectedLine - FAT_screenSong_currentStartLine, FAT_screenSong_currentSelectedLine);
}

/**
 * \brief Cette fonction est dédiée à l'interaction avec la touche A. 
 */
void FAT_screenSong_pressOrHeldA() {
    if (hel_PadQuery()->Held.L) {
        FAT_data_smartAllocateSequence(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine);
    } else {
        FAT_data_allocateSequence(
                FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine);
    }

    if (hel_PadQuery()->Pressed.Right) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, 1); // ajout de 1
    }

    if (hel_PadQuery()->Pressed.Left) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, -1); // retrait de 1
    }

    if (hel_PadQuery()->Pressed.Up) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, 16);
    }

    if (hel_PadQuery()->Pressed.Down) {
        FAT_data_sequence_changeValue(FAT_screenSong_currentSelectedColumn,
                FAT_screenSong_currentSelectedLine, -16);
    }

    FAT_screenSong_printSequence(
            FAT_screenSong_currentSelectedColumn,
            FAT_screenSong_currentSelectedLine - FAT_screenSong_currentStartLine,
            FAT_screenSong_currentSelectedLine);
}

#endif

