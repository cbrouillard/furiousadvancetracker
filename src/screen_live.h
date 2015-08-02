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
 * \file screen_live.h
 * \brief Fichier contenant toutes les fonctions pour gérer l'écran LIVE.
 */

#ifndef _SCREEN_LIVE_H_
#define _SCREEN_LIVE_H_

/** \brief Le nombre maximal de ligne affichées à l'écran. */
#define SCREENLIVE_NB_LINES_ON_SCREEN 10
/** \brief Définition interface : numéro de la tile pour début de l'affichage (Y). */
#define SCREENLIVE_LINE_START_Y 2
/** \brief Définition interface : numéro de la tile pour début de l'affichage des lignes ! (X). */
#define SCREENLIVE_LINE_X 0
/** \brief Définition interface : taille que prend une ligne en tile (1). */
#define SCREENLIVE_LINE_SIZE_Y 1
/** \brief Définition interface : numéro de la tile pour début de l'affichage des séquences (X). */
#define SCREENLIVE_SEQUENCE_LINE_X 3

/** \brief Permet de savoir si la popup de déplacement est affichée au dessus de l'écran. */
bool FAT_screenLive_isPopuped = 0;

// prototypes
void FAT_screenLive_init();
void FAT_screenLive_checkButtons();
void FAT_screenLive_printInfos();
void FAT_screenLive_printAllScreenText();
void FAT_screenLive_pressOrHeldA_inSequencer();
void FAT_screenLive_pressOrHeldA_inDataTable();

bool FAT_screenLive_isCursorInSequencer = 1;

/** \brief Cette variable contient le numéro de la première ligne actuellement affichée. */
u8 FAT_screenLive_currentStartLine = 0;

#include "screen_live_cursor.h"
#include "cursors.h"

/**
 * \brief Affiche uniquement la valeur du tempo au bon endroit. 
 */
void FAT_screenLive_printTempo() {
    hel_BgTextPrintF(TEXT_LAYER, 15, 16, 0, "%3d", FAT_tracker.tempo);
}

/**
 * \brief Affiche uniquement la valeur du transpose au bon endroit. 
 */
void FAT_screenLive_printTranspose() {
    hel_BgTextPrintF(TEXT_LAYER, 10, 16, 0, "%.2x", FAT_tracker.transpose);
}

/**
 * \brief Affiche uniquement la valeur du mode live au bon endroit. 
 */
void FAT_screenLive_printLiveMode() {
    if (FAT_tracker.liveData.liveMode) {
        hel_BgTextPrint(TEXT_LAYER, 6, 16, 0, "MAN");
    } else {
        hel_BgTextPrintF(TEXT_LAYER, 6, 16, 0, "AUT");
    }
}

void FAT_screenLive_printVolumes() {
    hel_BgTextPrintF(TEXT_LAYER, 2, 13, 0, " %.2x %.2x %.2x %.2x %.2x %.2x",
            FAT_tracker.liveData.volume[0],
            FAT_tracker.liveData.volume[1],
            FAT_tracker.liveData.volume[2],
            FAT_tracker.liveData.volume[3],
            FAT_tracker.liveData.volume[4],
            FAT_tracker.liveData.volume[5]);
}

void FAT_screenLive_printTransposes() {
    hel_BgTextPrintF(TEXT_LAYER, 2, 14, 0, " %.2x %.2x %.2x %.2x %.2x %.2x",
            FAT_tracker.liveData.transpose[0],
            FAT_tracker.liveData.transpose[1],
            FAT_tracker.liveData.transpose[2],
            FAT_tracker.liveData.transpose[3],
            FAT_tracker.liveData.transpose[4],
            FAT_tracker.liveData.transpose[5]);
}

/**
 * \brief Imprime les numéros de lignes. 
 * 
 * L'impression démarre depuis la valeur de FAT_screenLive_currentStartLine jusqu'à FAT_screenLive_currentStartLine + SCREENSONG_NB_LINES_ON_SCREEN
 */
void FAT_screenLive_printLineColumns() {
    u8 y = SCREENLIVE_LINE_START_Y;
    int c;
    for (c = FAT_screenLive_currentStartLine; c < (SCREENLIVE_NB_LINES_ON_SCREEN + FAT_screenLive_currentStartLine); c++) {
        hel_BgTextPrintF(TEXT_LAYER, SCREENLIVE_LINE_X, y, 0, FAT_FORMAT_LINE, c);
        y += SCREENLIVE_LINE_SIZE_Y;
    }
}

/**
 * \brief Affiche quelques infos (nom du projet, ligne actuellement sélectionnée et nom du channel)
 * sur l'écran. 
 */
void FAT_screenLive_printInfos() {
    hel_BgTextPrintF(TEXT_LAYER, 21, 3, 0, "%s", FAT_tracker.songName);
    hel_BgTextPrintF(TEXT_LAYER, 21, 4, 0, "Line  %.2x", FAT_screenLive_currentSelectedLine);
    hel_BgTextPrintF(TEXT_LAYER, 21, 5, 0, "Chan %s", CHANNEL_NAME[FAT_screenLive_currentSelectedColumn]);
    hel_BgTextPrintF(TEXT_LAYER, 21, 6, 0, "TSP   %2.x", FAT_tracker.transpose);

    FAT_screenLive_printLiveMode();
    FAT_screenLive_printTempo();
}

/**
 * \brief Affiche une seule séquence. 
 *  
 * @param channel le numéro de channel sur lequel la séquence est inscrite
 * @param lineOnScreen le numéro de ligne à l'écran, compris entre 0 et screenLive_NB_LINES_ON_SCREEN
 * @param realLine le vrai numéro de ligne dans le tracker ou la séquence a été inscrite
 */
void FAT_screenLive_printSequence(u8 channel, u8 lineOnScreen, u8 realLine) {
    if (FAT_tracker.channels[channel].sequences[realLine] != NULL_VALUE) {
        hel_BgTextPrintF(TEXT_LAYER, SCREENLIVE_SEQUENCE_LINE_X + (3 * channel),
                lineOnScreen + SCREENLIVE_LINE_START_Y, 0,
                "%.2x\0", FAT_tracker.channels[channel].sequences[realLine]);
    } else {
        hel_BgTextPrint(TEXT_LAYER, SCREENLIVE_SEQUENCE_LINE_X + (3 * channel),
                lineOnScreen + SCREENLIVE_LINE_START_Y, 0, "  ");
    }
}

/**
 * \brief Affiche toutes les séquences actuellement visibles.  
 */
void FAT_screenLive_printSequences() {
    u8 c;
    u8 v;
    for (v = 0; v < SCREENLIVE_NB_LINES_ON_SCREEN; v++) {

        for (c = 0; c < 6; c++) {
            if (FAT_tracker.channels[c].sequences[v + FAT_screenLive_currentStartLine] == NULL_VALUE) {
                hel_BgTextPrint(TEXT_LAYER, SCREENLIVE_SEQUENCE_LINE_X + (c * 3),
                        v + SCREENLIVE_LINE_START_Y, 0, "  ");
            } else {
                hel_BgTextPrintF(TEXT_LAYER, SCREENLIVE_SEQUENCE_LINE_X + (c * 3),
                        v + SCREENLIVE_LINE_START_Y, 0, "%.2x ",
                        FAT_tracker.channels[c].sequences[v + FAT_screenLive_currentStartLine]);
            }
        }

    }
}

/**
 * \brief Affiche tout le texte à l'écran (numéros de lignes, séquences et infos).
 */
void FAT_screenLive_printAllScreenText() {
    FAT_screenLive_printLineColumns();
    FAT_screenLive_printSequences();
    FAT_screenLive_printInfos();
}

/**
 * \brief Initialisation de l'écran. 
 */
void FAT_screenLive_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_LIVE_RAW), RES_SCREEN_LIVE_RAW_SIZE16, 1, 1);
    ham_bg[SCREEN_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_LIVE_MAP), 1024, 0, 0);
    ham_InitBg(SCREEN_LAYER, 1, 3, 0);

    FAT_screenLive_printAllScreenText();
    FAT_screenLive_printVolumes();
    FAT_screenLive_printTransposes();

    // partie identique à l'écran SONG (imprime uniquement les notes actuellement jouées dans l'encart rouge. Rien de plus)
    FAT_screenSong_printChannelFollower();

    // affichage du curseur
    FAT_cursors_hideCursor2();
    FAT_screenLive_commitCursorMove();
    FAT_cursors_showCursor2();
}

/**
 * \brief Change la partie active de l'écran.
 * @param part la partie vers laquelle switcher: 0 = table, 1 = sequenceur
 */
void FAT_screenLive_switchActivePart(bool part) {
    FAT_screenLive_isCursorInSequencer = part;

    FAT_screenLive_switchCursorToPart(part);
    FAT_screenLive_commitCursorMove();
}

/**
 * \brief Teste les actions utilisateurs. 
 */
void FAT_screenLive_checkButtons() {
    hel_PadCapture();

    if (hel_PadQuery()->Held.Select) {
        if (!FAT_screenLive_isPopuped) {
            FAT_cursors_hideCursor2();
            FAT_popup_show();
            FAT_screenLive_isPopuped = 1;
        }

        FAT_popup_checkButtons();

    } else {
        if (FAT_screenLive_isPopuped) {
            FAT_popup_hide();
            FAT_cursors_showCursor2();
            FAT_screenLive_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_LIVE_ID) {
                // TODO hide project cursor
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (hel_PadQuery()->Pressed.R && hel_PadQuery()->Pressed.L) {
            FAT_showHelp(SCREEN_LIVE_ID);
        }

        if (hel_PadQuery()->Pressed.A || hel_PadQuery()->Held.A) {
            if (FAT_screenLive_isCursorInSequencer){
                FAT_screenLive_pressOrHeldA_inSequencer();
            } else {
                FAT_screenLive_pressOrHeldA_inDataTable();
            }
        } else {
            if (hel_PadQuery()->Pressed.Right) {
                FAT_screenLive_moveCursorRight();
            }

            if (hel_PadQuery()->Pressed.Left) {
                FAT_screenLive_moveCursorLeft();
            }

            if (hel_PadQuery()->Pressed.Down) {
                if (hel_PadQuery()->Held.R) {
                    //FAT_screenLive_movePageDown();
                    // changer de portion d'écran -> du séquenceur vers la table
                    FAT_screenLive_switchActivePart(0);

                } else if (hel_PadQuery()->Held.L) {
                    FAT_screenLive_moveCursorAllDown();
                } else {
                    FAT_screenLive_moveCursorDown();
                }
            }

            if (hel_PadQuery()->Pressed.Up) {
                if (hel_PadQuery()->Held.R) {
                    //FAT_screenLive_movePageUp();
                    // changer de portion d'écran -> de la table vers le sequenceur
                    FAT_screenLive_switchActivePart(1);

                } else if (hel_PadQuery()->Held.L) {
                    FAT_screenLive_moveCursorAllUp();
                } else {
                    FAT_screenLive_moveCursorUp();
                }
            }
        }

        if (hel_PadQuery()->Pressed.Start) {
            if(!FAT_tracker.liveData.liveMode || hel_PadQuery()->Held.R){
                // tout se lance en maintenant à partir de la ligne sélectionnée.
                if (!FAT_isCurrentlyPlaying) {
                    FAT_player_startPlayerFromSequences(FAT_screenLive_currentSelectedLine);
                } else {
                    FAT_player_stopPlayer();
                }
            }else {
                if (!FAT_isCurrentlyPlaying) {
                    // seule la colonne sélectionnée se lance à partir de la ligne courante.
                    FAT_player_startPlayerFromLive_oneChannel(FAT_screenLive_currentSelectedLine, FAT_screenLive_currentSelectedColumn);
                } else {
                    // si le channel joue actuellement, on l'arrete.
                    if (FAT_isChannelCurrentlyPlaying (FAT_screenLive_currentSelectedColumn)){
                        FAT_player_stopPlayer_onlyOneColumn(FAT_screenLive_currentSelectedColumn);
                    } else {
                        // sinon on le démmarre
                        FAT_player_startPlayerFromLive_oneChannel(FAT_screenLive_currentSelectedLine, FAT_screenLive_currentSelectedColumn);
                    }
                }
            }
        }

        FAT_screenLive_commitCursorMove();
    }
}

void FAT_screenLive_pressOrHeldA_inSequencer(){

}

void FAT_screenLive_pressOrHeldA_inDataTable(){
    switch (FAT_screenLive_currentTableSelectedLine){
        case 0:
            // volume colonne
            if (hel_PadQuery()->Pressed.Right && FAT_tracker.liveData.volume[FAT_screenLive_currentSelectedColumn] < 0xff) {
                FAT_tracker.liveData.volume[FAT_screenLive_currentSelectedColumn] ++;
            }

            if (hel_PadQuery()->Pressed.Left && FAT_tracker.liveData.volume[FAT_screenLive_currentSelectedColumn] > 0x00) {
                FAT_tracker.liveData.volume[FAT_screenLive_currentSelectedColumn] --;
            }

            if (hel_PadQuery()->Pressed.Up && FAT_tracker.liveData.volume[FAT_screenLive_currentSelectedColumn] < 0xf0) {
                FAT_tracker.liveData.volume[FAT_screenLive_currentSelectedColumn] += 0x10;
            }

            if (hel_PadQuery()->Pressed.Down && FAT_tracker.liveData.volume[FAT_screenLive_currentSelectedColumn] > 0x0f) {
                FAT_tracker.liveData.volume[FAT_screenLive_currentSelectedColumn] -= 0x10;
            }

            FAT_screenLive_printVolumes();
            break;
        case 1:
            // tsp column
            if (hel_PadQuery()->Pressed.Right && FAT_tracker.liveData.transpose[FAT_screenLive_currentSelectedColumn] < 0xff) {
                FAT_tracker.liveData.transpose[FAT_screenLive_currentSelectedColumn] ++;
            }

            if (hel_PadQuery()->Pressed.Left && FAT_tracker.liveData.transpose[FAT_screenLive_currentSelectedColumn] > 0x00) {
                FAT_tracker.liveData.transpose[FAT_screenLive_currentSelectedColumn] --;
            }

            if (hel_PadQuery()->Pressed.Up && FAT_tracker.liveData.transpose[FAT_screenLive_currentSelectedColumn] < 0xf0) {
                FAT_tracker.liveData.transpose[FAT_screenLive_currentSelectedColumn] += 0x10;
            }

            if (hel_PadQuery()->Pressed.Down && FAT_tracker.liveData.transpose[FAT_screenLive_currentSelectedColumn] > 0x0f) {
                FAT_tracker.liveData.transpose[FAT_screenLive_currentSelectedColumn] -= 0x10;
            }

            FAT_screenLive_printTransposes();
            break;
        case 2:
            // mode, tempo
            if (FAT_screenLive_currentSelectedColumn == 1){
                if (hel_PadQuery()->Pressed.Right) {
                    FAT_tracker.liveData.liveMode = 0;
                }

                if (hel_PadQuery()->Pressed.Left) {
                    FAT_tracker.liveData.liveMode = 1;
                }

                FAT_screenLive_printLiveMode();
            } else if (FAT_screenLive_currentSelectedColumn == 4){
                if (hel_PadQuery()->Pressed.Right && FAT_tracker.tempo < MAX_TEMPO) {
                    FAT_tracker.tempo ++;
                }

                if (hel_PadQuery()->Pressed.Left && FAT_tracker.tempo > 0x00) {
                    FAT_tracker.tempo --;
                }

                if (hel_PadQuery()->Pressed.Up && FAT_tracker.tempo < MAX_TEMPO-10) {
                    FAT_tracker.tempo += 10;
                }

                if (hel_PadQuery()->Pressed.Down && FAT_tracker.tempo > 10) {
                    FAT_tracker.tempo -= 10;
                }

                FAT_screenLive_printTempo();
            }
            break;
    }
}

#endif
