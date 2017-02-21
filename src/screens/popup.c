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
* \file popup.c
* \brief Gestion de la popup de sélection d'écran.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../soundApi/soundApi.h"
#include "../headers/fat.h"

/**
 * \brief Initialisation de l'écran popup.
 *
 * Chargement dans la mémoire GBA de l'écran.
 * La popup est cachée par défaut. Les données sont chargées dans le layer POPUP_LAYER, elles le restent
 * jusqu'à extinction du programme.
 */
void FAT_popup_init() {
    if (ham_bg[POPUP_LAYER].ti) {
        ham_DeInitTileSet(ham_bg[POPUP_LAYER].ti);
        ham_DeInitMapSet(ham_bg[POPUP_LAYER].mi);
    }

    ham_bg[POPUP_LAYER].ti = ham_InitTileSet((void*)ResData(RES_SCREEN_POPUP_RAW), RES_SCREEN_POPUP_RAW_SIZE16, 1, 1);
    ham_bg[POPUP_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_POPUP_MAP), 640, 0, 0);
    ham_InitBg(POPUP_LAYER, 1, 0, 0);

    hel_BgSetPrio (POPUP_LAYER, 0);

    FAT_popup_hide();
}

/**
 * \brief Initialisation des curseurs spécifiques à l'écran popup.
 *
 * Chargement des bitmaps + positionnement aux valeurs
 * par défauts. La méthode les cache ensuite.
 */
void FAT_popup_initCursors() {
    FAT_popup_cursorSelectionX = POPUP_CURSOR_DEFAULT_X;
    FAT_popup_cursorSelectionY = POPUP_CURSOR_DEFAULT_Y;

    FAT_popup_cursorActualScreenX = ACTUAL_SCREEN_CURSOR_DEFAULT_X;
    FAT_popup_cursorActualScreenY = ACTUAL_SCREEN_CURSOR_DEFAULT_Y;

    FAT_popup_cursorSelectionObj = hel_ObjCreate(   ResData(RES_CURSOR_POPUP_RAW), // Pointer to source graphic
                                                    OBJ_SHAPE_VERTICAL,       // Obj Shape
                                                    3,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                                    OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
                                                    COLORS_16,              // Use 16 color mode
                                                    0,                      // Palette number. Only neccessary in 16 color mode
                                                    FALSE,                  // Don't use mosaic
                                                    FALSE,                  // Don't flip the sprite horizontally
                                                    FALSE,                  // Don't flip the object vertically
                                                    0,                      // Priority against background. 0=higest
                                                    FALSE,                  // Don't make the object double-sized
                                                    FAT_popup_cursorSelectionX,                    // Destination horzintal screen coordinate in pixels
                                                    FAT_popup_cursorSelectionY                      // Destination vertical screen coordinate in pixels
                                                    );

    FAT_popup_cursorActualScreenObj = hel_ObjCreate(   ResData(RES_ACTUAL_SCREEN_POPUP_RAW), // Pointer to source graphic
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
                                                       FAT_popup_cursorActualScreenX,                    // Destination horzintal screen coordinate in pixels
                                                       FAT_popup_cursorActualScreenY                      // Destination vertical screen coordinate in pixels
                                                       );

    // cachés par défaut
    FAT_popup_hideCursors();
}
