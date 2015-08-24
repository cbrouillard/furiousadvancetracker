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
#ifndef _PLAYER_CURSORS_H_
#define	_PLAYER_CURSORS_H_

void FAT_player_initCursors();
void FAT_player_live_showOrHideCursorWait(u8 channel);
void FAT_player_hideWaitCursors ();
void FAT_player_hideSequencesCursors();
void FAT_player_hideBlockCursor();
void FAT_player_hideNoteCursor();

/**
 * \brief Initialisation du curseur player pour les notes.
 *
 * S'occupe de créer les sprites et de les rendre invisibles.
 */
void FAT_player_initCursors() {

    FAT_cursor_player3_obj = hel_ObjCreate(    ResData(RES_CURSOR3_PLAYER_RAW), // Pointer to source graphic
                                               OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                               2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                               OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                               COLORS_16,              // Use 16 color mode
                                               0,                      // Palette number. Only neccessary in 16 color mode
                                               FALSE,                  // Don't use mosaic
                                               FALSE,                  // Don't flip the sprite horizontally
                                               FALSE,                  // Don't flip the object vertically
                                               3,                      // Priority against background. 0=higest
                                               FALSE,                  // Don't make the object double-sized
                                               0,                    // Destination horzintal screen coordinate in pixels
                                               0                      // Destination vertical screen coordinate in pixels
                                               );

    FAT_cursor_player2_obj = hel_ObjCreate(    ResData(RES_CURSOR2_PLAYER_RAW), // Pointer to source graphic
                                               OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                               2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                               OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                               COLORS_16,              // Use 16 color mode
                                               0,                      // Palette number. Only neccessary in 16 color mode
                                               FALSE,                  // Don't use mosaic
                                               FALSE,                  // Don't flip the sprite horizontally
                                               FALSE,                  // Don't flip the object vertically
                                               3,                      // Priority against background. 0=higest
                                               FALSE,                  // Don't make the object double-sized
                                               0,                    // Destination horzintal screen coordinate in pixels
                                               0                      // Destination vertical screen coordinate in pixels
                                               );

    FAT_cursor_playerLiveWait_obj[0] =  hel_ObjCreate( ResData(RES_CURSOR2_PLAYER_WAITING_RAW), // Pointer to source graphic
                                                       OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                       2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                       OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                                       COLORS_16,              // Use 16 color mode
                                                       0,                      // Palette number. Only neccessary in 16 color mode
                                                       FALSE,                  // Don't use mosaic
                                                       FALSE,                  // Don't flip the sprite horizontally
                                                       FALSE,                  // Don't flip the object vertically
                                                       3,                      // Priority against background. 0=higest
                                                       FALSE,                  // Don't make the object double-sized
                                                       0,                    // Destination horzintal screen coordinate in pixels
                                                       0                      // Destination vertical screen coordinate in pixels
                                                       );

    hel_ObjSetVisible(FAT_cursor_player3_obj, 0);
    hel_ObjSetVisible(FAT_cursor_player2_obj, 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[0], 0);

    // on clone les sprites pour la lecture des 6 séquences à la fois
    u8 i;
    for (i = 0; i < 6; i++) {
        FAT_cursor_playerSequences_obj[i] = hel_ObjClone(FAT_cursor_player2_obj, 0, 0);
        hel_ObjSetPrio(FAT_cursor_playerSequences_obj[i], 3);
    }

    for (i = 1; i < 6; i++) {
        FAT_cursor_playerLiveWait_obj[i] = hel_ObjClone(FAT_cursor_playerLiveWait_obj[0], 0, 0);
        hel_ObjSetPrio(FAT_cursor_playerLiveWait_obj[i], 3);
    }
}

/**
 * \brief Cache tous les curseurs utilisés lors de la lecture.
 */
void FAT_player_hideAllCursors() {
    FAT_player_hideNoteCursor();
    FAT_player_hideBlockCursor();
    FAT_player_hideWaitCursors ();
    FAT_player_hideSequencesCursors();
}

/**
 * \brief Cache les curseurs utilisés lors de la lecture dans l'écran SONG.
 */
void FAT_player_hideSequencesCursors() {
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[0], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[1], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[2], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[3], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[4], 0);
    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[5], 0);
}

void FAT_player_hideWaitCursors (){
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[0], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[1], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[2], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[3], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[4], 0);
    hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[5], 0);
}

/**
 * \brief Cache les curseurs utilisés lors de la lecture dans l'écran BLOCK.
 */
void FAT_player_hideBlockCursor() {
    hel_ObjSetVisible(FAT_cursor_player2_obj, 0);
}

/**
 * \brief Cache les curseurs utilisés lors de la lecture dans l'écran NOTE.
 */
void FAT_player_hideNoteCursor() {
    hel_ObjSetVisible(FAT_cursor_player3_obj, 0);
}


void FAT_player_live_showOrHideCursorWait(u8 channel){
    if (FAT_currentScreen == SCREEN_LIVE_ID){
        if (FAT_isChannelCurrentlyPlaying(channel) && actualSequencesForChannel[channel] < NB_MAX_SEQUENCES
            && actualSequencesForChannel[channel] >= FAT_screenLive_currentStartLine && !isHelpActivated
            && FAT_live_waitForOtherChannel[channel] == 1){
            // affichage
            u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);
            if (yPosition < 140){
                hel_ObjSetXY(FAT_cursor_playerLiveWait_obj[channel],
                        23 + (channel * (8 + 16)),
                        yPosition);
                hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[channel], 1);
            } else {
                hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[channel], 0);
            }
        } else {
            hel_ObjSetVisible(FAT_cursor_playerLiveWait_obj[channel], 0);
        }

    }
}

/**
 * \brief Déplace ou cache les curseurs de lecture en fonction de l'état du player.
 *
 * @param channel le numéro de channel sur lequel on joue du son
 */
void FAT_player_moveOrHideCursor(u8 channel) {

    switch (FAT_currentScreen) {
        case SCREEN_SONG_ID: // on est dans l'écran SONG !
            FAT_player_hideBlockCursor();
            FAT_player_hideNoteCursor();
            if (actualSequencesForChannel[channel] != NULL_VALUE && actualSequencesForChannel[channel] < NB_MAX_SEQUENCES
                    && actualSequencesForChannel[channel] >= FAT_screenSong_currentStartLine && !isHelpActivated) {
                // la lecture a été lancée depuis l'écran SONG
                // on dispose du numéro de ligne actuellement jouée dans actualSequencesForChannel[channel]
                u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);
                if (yPosition < 140){
                    hel_ObjSetXY(FAT_cursor_playerSequences_obj[channel],
                            23 + (channel * (8 + 16)),
                            yPosition);
                    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 1);
                } else {
                    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
                }

            } else {
                hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
            }


            break;
        case SCREEN_LIVE_ID:
            // TODO duplication moche.
            FAT_player_hideBlockCursor();
            FAT_player_hideNoteCursor();
            if (actualSequencesForChannel[channel] != NULL_VALUE && actualSequencesForChannel[channel] < NB_MAX_SEQUENCES
                    && actualSequencesForChannel[channel] >= FAT_screenLive_currentStartLine && !isHelpActivated) {
                // la lecture a été lancée depuis l'écran SONG
                // on dispose du numéro de ligne actuellement jouée dans actualSequencesForChannel[channel]
                u8 yPosition = 15 + ((actualSequencesForChannel[channel] - FAT_screenSong_currentStartLine)*8);

                if (yPosition < 90){
                    hel_ObjSetXY(FAT_cursor_playerSequences_obj[channel],
                            23 + (channel * (8 + 16)),
                            15 + ((actualSequencesForChannel[channel] - FAT_screenLive_currentStartLine)*8));

                    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 1);
                } else {
                    hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
                }

            } else {
                hel_ObjSetVisible(FAT_cursor_playerSequences_obj[channel], 0);
            }
            break;
        case SCREEN_BLOCKS_ID: // on est dans l'écran BLOCKS
            FAT_player_hideSequencesCursors();
            FAT_player_hideNoteCursor();
            if (actualBlocksForChannel[channel] != NULL_VALUE &&
                    FAT_currentPlayedSequence == FAT_screenBlocks_currentSequenceId && !isHelpActivated) {
                hel_ObjSetXY(FAT_cursor_player2_obj, 23, 15 + (actualBlocksForChannel[channel]*8));
                hel_ObjSetVisible(FAT_cursor_player2_obj, 1);
            } else {
                FAT_player_hideBlockCursor();
            }

            break;
        case SCREEN_NOTES_ID: // on est dans l'écran NOTES
            FAT_player_hideSequencesCursors();
            FAT_player_hideBlockCursor();
            if (actualNotesForChannel[channel] != NULL_VALUE
                    && FAT_currentPlayedBlock == FAT_screenNotes_currentBlockId && !isHelpActivated) {
                hel_ObjSetXY(FAT_cursor_player3_obj, 23, 15 + (actualNotesForChannel[channel]*8));
                hel_ObjSetVisible(FAT_cursor_player3_obj, 1);
            } else {
                FAT_player_hideNoteCursor();
            }
            break;
        default: // on cache tous les curseurs de lecture
            FAT_player_hideAllCursors();
            break;
    }

}

#endif
