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
#ifndef _CURSORS_H_
#define _CURSORS_H_

/**
 * On gere 2 types de curseurs.
 * 1. le curseur taille 2. Englobe 2 tile de 8x8
 * 2. le curseur taille 3. Englobe 3 tile de 8x8
 */

// Largeur des curseurs.
#define CURSOR2_SIZE_X 18
#define CURSOR2_SIZE_Y 10 

/**
 * ID sprite des curseurs.
 */
u8 FAT_cursor1_obj, FAT_cursor2_obj, FAT_cursor3_obj, FAT_cursorChange_obj;

/**
 * Initialisation du curseur taille 1.
 * S'occupe de créer le sprite (TRANSPARENCE) et de le rendre invisible. 
 */
void FAT_initCursor1() {
    FAT_cursor1_obj = ham_CreateObj((void*) cursor1_Bitmap, OBJ_SIZE_16X16,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursor1_obj, 0);
    ham_SetObjPrio(FAT_cursor1_obj, 1);
}

/**
 * Initialisation du curseur taille 2.
 * S'occupe de créer le sprite (TRANSPARENCE) et de le rendre invisible. 
 */
void FAT_initCursor2() {
    FAT_cursor2_obj = ham_CreateObj((void*) cursor2_Bitmap, OBJ_SIZE_32X16,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursor2_obj, 0);
    ham_SetObjPrio(FAT_cursor2_obj, 1);
}

/**
 * Initialisation du curseur taille 3.
 * S'occupe de créer le sprite (TRANSPARENCE) et de le rendre invisible. 
 */
void FAT_initCursor3() {
    FAT_cursor3_obj = ham_CreateObj((void*) cursor3_Bitmap, OBJ_SIZE_32X16,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursor3_obj, 0);
    ham_SetObjPrio(FAT_cursor3_obj, 1);
}

void FAT_initCursorChange() {
    FAT_cursorChange_obj = ham_CreateObj((void*) cursor_change_Bitmap, OBJ_SIZE_32X16,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursorChange_obj, 0);
    ham_SetObjPrio(FAT_cursorChange_obj, 1);
}

/**
 * Affiche le curseur 1. Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor1() {
    ham_SetObjVisible(FAT_cursor1_obj, 1);
}

/**
 * Affiche le curseur 2. Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor2() {
    ham_SetObjVisible(FAT_cursor2_obj, 1);
}

/**
 * Affiche le curseur 3. Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor3() {
    ham_SetObjVisible(FAT_cursor3_obj, 1);
}

/**
 * Cache le curseur 1. Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor1() {
    ham_SetObjVisible(FAT_cursor1_obj, 0);
}

/**
 * Cache le curseur 2. Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor2() {
    ham_SetObjVisible(FAT_cursor2_obj, 0);
}

/**
 * Cache le curseur 3. Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor3() {
    ham_SetObjVisible(FAT_cursor3_obj, 0);
}

void FAT_cursors_showCursorChange() {
    ham_SetObjVisible(FAT_cursorChange_obj, 1);
}

void FAT_cursors_hideCursorChange() {
    ham_SetObjVisible(FAT_cursorChange_obj, 0);
}

void FAT_cursors_moveCursorChange(u8 x, u8 y) {
    ham_SetObjXY(FAT_cursorChange_obj, x, y);
}

#endif
