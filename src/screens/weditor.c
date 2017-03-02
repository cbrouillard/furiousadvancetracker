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
* \file weditor.c
* \brief Ecran edition voice.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../headers/fat.h"

/**
 * \brief Permet de savoir si l'écran BLOCKS est actuellement "popupé".
 */
bool FAT_screenWeditor_isPopuped = 0;
u8 FAT_screenWeditor_currentVoice = 0;

THandle FAT_screenWeditor_spinner[16];

void FAT_screenWeditor_printCurrentVoiceData (){
  wave* customVoice = &(FAT_tracker.customVoice[FAT_screenWeditor_currentVoice]);

  u8 line = 2;
  u8 i;
  for (i = 0; i < 4; i++){
    hel_BgTextPrintF(TEXT_LAYER, 0, line, 0, "%0.2d %0.2x", line - 2, customVoice->data[i] & 0x000000ff); line++;
    hel_BgTextPrintF(TEXT_LAYER, 0, line, 0, "%0.2d %0.2x", line - 2, (customVoice->data[i] & 0x0000ff00) >> 8);line++;
    hel_BgTextPrintF(TEXT_LAYER, 0, line, 0, "%0.2d %0.2x", line - 2, (customVoice->data[i] & 0x00ff0000) >> 16);line++;
    hel_BgTextPrintF(TEXT_LAYER, 0, line, 0, "%0.2d %0.2x", line - 2, (customVoice->data[i] & 0xff000000) >> 24);line++;
  }

}

void FAT_screenWeditor_setOneSpinnerPosition (u8 n, u8 value){
  u8 ratioX = value * 0.44;
  hel_ObjSetXY(FAT_screenWeditor_spinner[n], 40 + ratioX, 15 + (8*n));
  hel_ObjSetVisible(FAT_screenWeditor_spinner[n], 1);
}

void FAT_screenWeditor_setSpinnersPositions (){
  u8 i, j;
  wave* customVoice = &(FAT_tracker.customVoice[FAT_screenWeditor_currentVoice]);
  j = 0;
  for (i = 0; i < 16; i++){
    FAT_screenWeditor_setOneSpinnerPosition (i++, (customVoice->data[j] & 0x000000ff));
    FAT_screenWeditor_setOneSpinnerPosition (i++, ((customVoice->data[j] & 0x0000ff00) >> 8));
    FAT_screenWeditor_setOneSpinnerPosition (i++, ((customVoice->data[j] & 0x00ff0000) >> 16));
    FAT_screenWeditor_setOneSpinnerPosition (i, ((customVoice->data[j] & 0xff000000) >> 24));
    j++;
  }

}

void FAT_screenWeditor_printAllText (){
    hel_BgTextPrintF(TEXT_LAYER, 21, 3, 0, "Inst  %.2x", FAT_screenInstrument_getCurrentInstrumentId ());
    hel_BgTextPrintF(TEXT_LAYER, 21, 4, 0, "Wave   %1.x", FAT_screenWeditor_currentVoice);

    FAT_screenWeditor_printCurrentVoiceData ();
    FAT_screenWeditor_setSpinnersPositions ();
}

void FAT_screenWeditor_init() {

  FAT_reinitScreen();

  // initialisation du fond (interface)
  ham_bg[SCREEN_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_WAVE_RAW), RES_SCREEN_WAVE_RAW_SIZE16, 1, 1);
  hel_MapCreate(SCREEN_LAYER, 32, 20, ResData(RES_SCREEN_WAVE_MAP), sizeof(u16), MAP_FLAGS_DEFAULT);
  FAT_forceClearTextLayer();

  FAT_player_hideAllCursors ();
  FAT_cursors_hideCursor3();

  u8 currentInstrumentId = FAT_screenInstrument_getCurrentInstrumentId ();

  if (FAT_tracker.allInstruments[currentInstrumentId].customVoice != NULL_VALUE) {
      FAT_screenWeditor_currentVoice = FAT_tracker.allInstruments[currentInstrumentId].customVoice & 0x0f;
  } else {
      FAT_screenWeditor_currentVoice = 0;
      FAT_data_wave_initIfNeeded (0, currentInstrumentId);
  }

  FAT_screenWeditor_printAllText ();
}

void FAT_screenWeditor_checkButtons (){
  hel_PadCapture();

  if (hel_PadQuery()->Held.Select) {
      if (!FAT_screenWeditor_isPopuped) {
          FAT_cursors_hideCursor2();
          FAT_cursors_hideCursorChange();
          FAT_popup_show();
          FAT_screenWeditor_isPopuped = 1;
      }

      FAT_popup_checkButtons();

  } else {
      if (FAT_screenWeditor_isPopuped) {
          FAT_popup_hide();
          FAT_screenWeditor_isPopuped = 0;

          FAT_switchToScreen(FAT_popup_getSelectedIcon(), SCREEN_WEDITOR_ID);

      }

  }
}

void FAT_screenWeditor_initWaveEditorSprites (){
  u8 i;
  for (i = 0; i < 16; i++){
    FAT_screenWeditor_spinner[i] = hel_ObjCreate(ResData(RES_CURSOR1_RAW), // Pointer to source graphic
                                                          OBJ_SHAPE_SQUARE,       // Obj Shape
                                                          1,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                          OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                                          COLORS_16,              // Use 16 color mode
                                                          0,                      // Palette number. Only neccessary in 16 color mode
                                                          FALSE,                  // Don't use mosaic
                                                          FALSE,                  // Don't flip the sprite horizontally
                                                          FALSE,                  // Don't flip the object vertically
                                                          1,                      // Priority against background. 0=higest
                                                          FALSE,                  // Don't make the object double-sized
                                                          0,                    // Destination horzintal screen coordinate in pixels
                                                          0                      // Destination vertical screen coordinate in pixels
                                                          );

    hel_ObjSetVisible(FAT_screenWeditor_spinner[i], 0);
  }
}
