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

#include "../headers/fat.h"

/** \brief ID technique HAM pour le cursor de taille 1. */
THandle FAT_cursor1_obj;
/** \brief ID technique HAM pour le cursor de taille 2. */
THandle FAT_cursor2_obj;
/** \brief ID technique HAM pour le cursor de taille 3. */
THandle FAT_cursor3_obj;
/** \brief ID technique HAM pour le cursor de taille 8. */
THandle FAT_cursor8_obj;
/** \brief ID technique HAM pour le cursor de changement d'onglet (partie instrument). */
THandle FAT_cursorChange_obj;
/** \brief ID technique HAM pour le cursor de clavier. */
THandle FAT_cursorKeyboard_obj;
/** \brief ID technique HAM pour le cursor de sélection sur le clavier. */
THandle FAT_cursorKeyboard_select_obj;

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

/**
 * \brief Affiche le curseur 1.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor1() {
    hel_ObjSetVisible(FAT_cursor1_obj, 1);
}

/**
 * \brief Affiche le curseur 2.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor2() {
    hel_ObjSetVisible(FAT_cursor2_obj, 1);
}

/**
 * \brief Affiche le curseur 3.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor3() {
    hel_ObjSetVisible(FAT_cursor3_obj, 1);
}

/**
 * \brief Affiche le curseur 8.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor8() {
    hel_ObjSetVisible(FAT_cursor8_obj, 1);
}

/**
 * \brief Affiche le curseur de changement d'onglet.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursorChange() {
    hel_ObjSetVisible(FAT_cursorChange_obj, 1);
}

/**
 * \brief Affiche le curseur de sélection du clavier.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursorKeyboard() {
    hel_ObjSetVisible(FAT_cursorKeyboard_obj, 1);
}

/**
 * \brief Affiche le curseur de sélection du clavier.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursorKeyboard_select() {
    hel_ObjSetVisible(FAT_cursorKeyboard_select_obj, 1);
}

/**
 * \brief Cache le curseur 1.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor1() {
    hel_ObjSetVisible(FAT_cursor1_obj, 0);
}

/**
 * \brief Cache le curseur 2.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor2() {
    hel_ObjSetVisible(FAT_cursor2_obj, 0);
}

/**
 * \brief Cache le curseur 3.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor3() {
    hel_ObjSetVisible(FAT_cursor3_obj, 0);
}

/**
 * \brief Cache le curseur 8.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor8() {
    hel_ObjSetVisible(FAT_cursor8_obj, 0);
}

/**
 * \brief Cache le curseur clavier.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursorKeyboard() {
    hel_ObjSetVisible(FAT_cursorKeyboard_obj, 0);
}

/**
 * \brief Cache le curseur sélection clavier.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursorKeyboard_select() {
    hel_ObjSetVisible(FAT_cursorKeyboard_select_obj, 0);
}

/**
 * \brief Cache le curseur de changement d'onglet.
 *
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursorChange() {
    hel_ObjSetVisible(FAT_cursorChange_obj, 0);
}

/**
 * \brief Cache tous les curseurs.
 */
void FAT_cursors_hideAllCursors(){
    FAT_cursors_hideCursor1();
    FAT_cursors_hideCursor2();
    FAT_cursors_hideCursor3();
    FAT_cursors_hideCursor8();
    FAT_cursors_hideCursorChange();
    FAT_cursors_hideCursorKeyboard();
    FAT_cursors_hideCursorKeyboard_select();
}

/**
 * \brief Déplace le curseur de changement d'onglet.
 *
 * \param x abscisse (en px)
 * \param y ordonnée (en px)
 */
void FAT_cursors_moveCursorChange(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursorChange_obj, x, y);
}

/**
 * \brief Déplace le curseur de taille 1.
 *
 * \param x abscisse (en px)
 * \param y ordonnée (en px)
 */
void FAT_cursors_moveCursor1(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursor1_obj, x, y);
}

/**
 * \brief Déplace le curseur de taille 2.
 *
 * \param x abscisse (en px)
 * \param y ordonnée (en px)
 */
void FAT_cursors_moveCursor2(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursor2_obj, x, y);
}

/**
 * \brief Déplace le curseur de taille 3.
 *
 * \param x abscisse (en px)
 * \param y ordonnée (en px)
 */
void FAT_cursors_moveCursor3(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursor3_obj, x, y);
}

/**
 * \brief Déplace le curseur de taille 8.
 *
 * \param x abscisse (en px)
 * \param y ordonnée (en px)
 */
void FAT_cursors_moveCursor8(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursor8_obj, x, y);
}

/**
 * \brief Déplace le curseur clavier.
 *
 * \param x abscisse (en px)
 * \param y ordonnée (en px)
 */
void FAT_cursors_moveCursorKeyboard(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursorKeyboard_obj, x,y);
}

/**
 * \brief Déplace le curseur de sélection clavier.
 *
 * \param x abscisse (en px)
 * \param y ordonnée (en px)
 */
void FAT_cursors_moveCursorKeyboard_select(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursorKeyboard_select_obj, x,y);
}
