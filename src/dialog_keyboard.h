#ifndef _DIALOG_KEYBOARD_H_
#define	_DIALOG_KEYBOARD_H_

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

#define DIALOG_KEYBOARD_FIRST_LETTER_X 22
#define DIALOG_KEYBOARD_FIRST_LETTER_Y 38
#define DIALOG_KEYBOARD_WRITER_X 110
#define DIALOG_KEYBOARD_WRITER_Y 22

/** \brief Numéro de case ou l'affichage des notes démarre. */
#define SCREENFILESYSTEM_LINE_START_Y 2
/** \brief Nombre total de notes affichées sur l'écran. */
#define SCREENFILESYSTEM_NB_LINES_ON_SCREEN 16
/** \brief Numéro de case ou l'affichage des numéros de ligne démarre. */
#define SCREENFILESYSTEM_LINE_X 0
/** \brief Numéro de case ou l'affichage des noms des tracks démarre. */
#define SCREENFILESYSTEM_LINE_TRACKNAME_X 3

u8 keyboard_actualSelectedLetter = 0;
u8 keyboard_actualCol = 0;
u8 keyboard_actualLine = 0;
u8 willSaveTrackNumber = 0;

/**
 * \file dialog_keyboard.h
 * \brief Ce fichier contient toutes les fonctions utiles pour la gestion du clavier de saisie.
 */

/**
 * \brief Ferme la boite de dialogue et reinitialise la popup (qui est sur le même layer).
 */
void FAT_dialog_close() {
    FAT_popup_init();
    hel_IntrUpdateHandler(INT_TYPE_VBL, (void*) &VBLInterruptHandler);
    FAT_switchToScreen(FAT_currentScreen, SCREEN_DIALOG_ANY);
}

void FAT_dialog_keyboardSelectorCursor (){
    FAT_cursors_moveCursorKeyboard_select(
        DIALOG_KEYBOARD_FIRST_LETTER_X + (keyboard_actualCol*16),
        DIALOG_KEYBOARD_FIRST_LETTER_Y + (keyboard_actualLine*16));

    FAT_cursors_moveCursorKeyboard( DIALOG_KEYBOARD_WRITER_X + (keyboard_actualSelectedLetter * 8),
                                    DIALOG_KEYBOARD_WRITER_Y);
}

void FAT_dialog_keyboardPrintActualName (){
    hel_BgTextPrintF(TEXT_LAYER, 14, 3, 0, "%.8s", songNameBuffer);
}

 /**
  * \brief Fonction principale de la boite de dialog KEYBOARD
  */
 void FAT_dialog_keyboardMainFunc() {
     hel_ObjTransmit();

     hel_PadCapture();

     if (hel_PadQuery()->Pressed.L || hel_PadQuery()->Pressed.Select) {
         FAT_dialog_close();
         hel_BgTextPrint(TEXT_LAYER, 24, 16, 0, "Cancel");
     } else if (hel_PadQuery()->Pressed.R || hel_PadQuery()->Pressed.Start) {
         // copie de la valeur dans tracker
         songNameBuffer[9] = '\0';
         strcpy (FAT_tracker.songName, songNameBuffer);

         // fin du dialogue
         FAT_cursors_hideAllCursors();
         hel_IntrUpdateHandler(INT_TYPE_VBL, (void*) &VBLInterruptHandler);

         // ouverture du dialogue suivant. (confirmation)
         FAT_yesno_show(DIALOG_SAVE, willSaveTrackNumber);
     }

     if (hel_PadQuery()->Pressed.Right) {
        if (keyboard_actualCol < 12 && ! (keyboard_actualLine > 1 && keyboard_actualCol > 8)){
            keyboard_actualCol ++;
            FAT_dialog_keyboardSelectorCursor ();
        }
     }

     if (hel_PadQuery()->Pressed.Left) {
        if (keyboard_actualCol > 0){
            keyboard_actualCol --;
            FAT_dialog_keyboardSelectorCursor ();
        }
     }

     if (hel_PadQuery()->Pressed.Down) {
        if (keyboard_actualLine < 3){
            if (keyboard_actualCol > 9 && keyboard_actualLine >= 1){
                keyboard_actualCol = 9;
            }

            keyboard_actualLine ++;
            FAT_dialog_keyboardSelectorCursor ();
        }
     }

     if (hel_PadQuery()->Pressed.Up) {
        if (keyboard_actualLine > 0){
            keyboard_actualLine --;
            FAT_dialog_keyboardSelectorCursor ();
        }
     }

     if (hel_PadQuery()->Pressed.B){
        songNameBuffer[keyboard_actualSelectedLetter] = ' ';
        if (keyboard_actualSelectedLetter > 0){
            keyboard_actualSelectedLetter --;
        }
        FAT_dialog_keyboardPrintActualName();
        FAT_dialog_keyboardSelectorCursor ();
     }

     if (hel_PadQuery()->Pressed.A){
        // quelle lettre ou chiffre ou car ?
        if (keyboard_actualLine < 2){
            //lettre
            songNameBuffer[keyboard_actualSelectedLetter] = 65 + ( (keyboard_actualLine*13) + keyboard_actualCol );
            keyboard_actualSelectedLetter ++;

        } else if (keyboard_actualLine == 2){
            // chiffre
            songNameBuffer[keyboard_actualSelectedLetter] = 48 + keyboard_actualCol;
            keyboard_actualSelectedLetter ++;

        } else {
            // car spécial
            // voici du code bourrin. miam.
            switch (keyboard_actualCol){
                case 0:
                    songNameBuffer[keyboard_actualSelectedLetter] = 40;
                    break;
                case 1:
                    songNameBuffer[keyboard_actualSelectedLetter] = ')';
                    break;
                case 2:
                    songNameBuffer[keyboard_actualSelectedLetter] = '\"';
                    break;
                case 3:
                    songNameBuffer[keyboard_actualSelectedLetter] = '-';
                    break;
                case 4:
                    songNameBuffer[keyboard_actualSelectedLetter] = '/';
                    break;
                case 5:
                    songNameBuffer[keyboard_actualSelectedLetter] = '!';
                    break;
                case 6:
                    songNameBuffer[keyboard_actualSelectedLetter] = '?';
                    break;
                case 7:
                    songNameBuffer[keyboard_actualSelectedLetter] = '.';
                    break;
                case 8:
                    songNameBuffer[keyboard_actualSelectedLetter] = '$';
                    break;
                case 9:
                    songNameBuffer[keyboard_actualSelectedLetter] = ' ';
                    break;
            }
            keyboard_actualSelectedLetter ++;
        }

        if (keyboard_actualSelectedLetter >= 8){
            keyboard_actualSelectedLetter = 0;
        }
        FAT_dialog_keyboardPrintActualName();
        FAT_dialog_keyboardSelectorCursor ();
     }
 }

 /**
  * \brief Cette fonction se content d'imprimer le numéro de ligne sur la partie
  * gauche de l'interface.
  */
 void FAT_dialog_cheat_printLineColumns() {
     u8 y = SCREENFILESYSTEM_LINE_START_Y;
     int c;
     for (c = 0; c < (SCREENFILESYSTEM_NB_LINES_ON_SCREEN); c++) {
         hel_BgTextPrintF(TEXT_LAYER, SCREENFILESYSTEM_LINE_X, y, 0, FAT_FORMAT_LINE, c);
         y += 1;
     }
 }

 /**
  * \brief Affiche tous les noms des chansons déjà enregistrées.
  */
 void FAT_dialog_cheat_printLastTracksName() {
     u8 track = 14;
     u8 y = SCREENFILESYSTEM_LINE_START_Y + 14;
     while (track < MAX_TRACKS) {
         hel_BgTextPrintF(TEXT_LAYER, SCREENFILESYSTEM_LINE_TRACKNAME_X, y, 0, "%.8s %.2x", FAT_filesystem_getTrackName(track),
                 FAT_filesystem_getTrackNbWork(track));
         track++;
         y++;
     }

 }

void FAT_dialog_keyboardShow (u8 fromTrackNum){
    willSaveTrackNumber = fromTrackNum;

    FAT_forceClearTextLayer();

    if (ham_bg[DIALOG_LAYER].ti) {
        ham_DeInitTileSet(ham_bg[DIALOG_LAYER].ti);
        ham_DeInitMapSet(ham_bg[DIALOG_LAYER].mi);
    }

    FAT_cursors_hideAllCursors();

    ham_bg[DIALOG_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_DIALOG_KEYBOARD_RAW), RES_SCREEN_DIALOG_KEYBOARD_RAW_SIZE16, 1, 1);
    ham_bg[DIALOG_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_DIALOG_KEYBOARD_MAP), 640, 0, 0);
    ham_InitBg(DIALOG_LAYER, 1, 1, 0);

    hel_IntrUpdateHandler(INT_TYPE_VBL, (void*) &FAT_dialog_keyboardMainFunc);

    keyboard_actualSelectedLetter = 0; // todo. Pas forcément.
    keyboard_actualCol = 0;
    keyboard_actualLine = 0;

    // Affichage du curseur de selection
    FAT_dialog_keyboardSelectorCursor ();
    FAT_cursors_showCursorKeyboard_select();
    FAT_cursors_showCursorKeyboard();

    FAT_dialog_keyboardPrintActualName();

    // fake transparency dialog :D
    FAT_dialog_cheat_printLineColumns();
    FAT_dialog_cheat_printLastTracksName();

}

#endif
