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
* \file cursors.c
* \brief Gestion des curseurs de l'application.
*/

#include <hel2.h>
#include <stdarg.h>

#include "../soundApi/soundApi.h"
#include "../headers/fat.h"

/**
 * \brief Initialisation du curseur taille 1.
 *
 * S'occupe de créer le sprite "curseur 1" en mode transparence. Le sprite est configuré
 * comme invisible par défaut.
 */
void FAT_initCursor1() {
    FAT_cursor1_obj = hel_ObjCreate(ResData(RES_CURSOR1_RAW), // Pointer to source graphic
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

    hel_ObjSetVisible(FAT_cursor1_obj, 0);
}

/**
 * \brief Initialisation du curseur taille 2.
 *
 * S'occupe de créer le sprite "curseur 2" en mode transparence. Le sprite est configuré
 * comme invisible par défaut.
 */
void FAT_initCursor2() {
    FAT_cursor2_obj = hel_ObjCreate(ResData(RES_CURSOR2_RAW), // Pointer to source graphic
                                    OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                    2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
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

    hel_ObjSetVisible(FAT_cursor2_obj, 0);
}

/**
 * \brief Initialisation du curseur taille 3.
 *
 * S'occupe de créer le sprite "curseur 3" en mode transparence. Le sprite est configuré
 * comme invisible par défaut.
 */
void FAT_initCursor3() {
    FAT_cursor3_obj = hel_ObjCreate(  ResData(RES_CURSOR3_RAW), // Pointer to source graphic
                                      OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                      2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
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

    hel_ObjSetVisible(FAT_cursor3_obj, 0);
}

/**
 * \brief Initialisation du curseur taille 8.
 *
 * S'occupe de créer le sprite "curseur 8" en mode transparence. Le sprite est configuré
 * comme invisible par défaut.
 */
void FAT_initCursor8() {
    FAT_cursor8_obj = hel_ObjCreate(  ResData(RES_CURSOR8_RAW), // Pointer to source graphic
                                                            OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                                            3,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
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

    hel_ObjSetVisible(FAT_cursor8_obj, 0);
}

/**
 * \brief Initialisation du curseur de changement d'onglet dans l'écran instrument.
 *
 * S'occupe de créer le sprite "curseur change" en mode transparence. Le sprite est configuré
 * comme invisible par défaut.
 */
void FAT_initCursorChange() {
    FAT_cursorChange_obj = hel_ObjCreate(  ResData(RES_CURSOR_CHANGE_RAW), // Pointer to source graphic
                                           OBJ_SHAPE_HORIZONTAL,       // Obj Shape
                                           2,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
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

    hel_ObjSetVisible(FAT_cursorChange_obj, 0);
}

/**
 * \brief Initialisation des curseurs du clavier de saisie.
 */
void FAT_initCursorsKeyboard (){
    FAT_cursorKeyboard_obj = hel_ObjCreate(ResData(RES_CURSOR_KEYBOARD_RAW), // Pointer to source graphic
                                           OBJ_SHAPE_SQUARE,       // Obj Shape
                                           1,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                           OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
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

    FAT_cursorKeyboard_select_obj = hel_ObjCreate(ResData(RES_CURSOR_KEYBOARD_SELECT_RAW), // Pointer to source graphic
                                           OBJ_SHAPE_SQUARE,       // Obj Shape
                                           1,                      // Obj Size, 1 means 16x16 pixels, if Shape is set to SQUARE
                                           OBJ_MODE_SEMITRANSPARENT,        // Obj Mode
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

    hel_ObjSetVisible(FAT_cursorKeyboard_obj, 0);
    hel_ObjSetVisible(FAT_cursorKeyboard_select_obj, 0);

}
