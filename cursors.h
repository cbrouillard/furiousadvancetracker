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
 * \file cursors.h
 * \brief Définitions de fonctions et variables utiles pour la gestion des objets curseurs. 
 */

#ifndef _CURSORS_H_
#define _CURSORS_H_

/**
 * ID technique HAM pour le cursor de taille 1.
 */
u8 FAT_cursor1_obj;
/**
 * ID technique HAM pour le cursor de taille 2.
 */
u8 FAT_cursor2_obj;
/**
 * ID technique HAM pour le cursor de taille 3.
 */
u8 FAT_cursor3_obj;
/**
 * ID technique HAM pour le cursor de taille 8.
 */
u8 FAT_cursor8_obj;
/**
 * ID technique HAM pour le cursor de changement d'onglet (partie instrument).
 */
u8 FAT_cursorChange_obj;

/**
 * \brief Initialisation du curseur taille 1.
 * 
 * S'occupe de créer le sprite "curseur 1" en mode transparence. Le sprite est configuré
 * comme invisible par défaut. 
 */
void FAT_initCursor1() {
    FAT_cursor1_obj = ham_CreateObj((void*) cursor1_Bitmap, OBJ_SIZE_16X16,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursor1_obj, 0);
    ham_SetObjPrio(FAT_cursor1_obj, 1);
}

/**
 * \brief Initialisation du curseur taille 2.
 * 
 * S'occupe de créer le sprite "curseur 2" en mode transparence. Le sprite est configuré
 * comme invisible par défaut. 
 */
void FAT_initCursor2() {
    FAT_cursor2_obj = ham_CreateObj((void*) cursor2_Bitmap, OBJ_SIZE_32X16,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursor2_obj, 0);
    ham_SetObjPrio(FAT_cursor2_obj, 1);
}

/**
 * \brief Initialisation du curseur taille 3.
 * 
 * S'occupe de créer le sprite "curseur 3" en mode transparence. Le sprite est configuré
 * comme invisible par défaut. 
 */
void FAT_initCursor3() {
    FAT_cursor3_obj = ham_CreateObj((void*) cursor3_Bitmap, OBJ_SIZE_32X16,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursor3_obj, 0);
    ham_SetObjPrio(FAT_cursor3_obj, 1);
}

/**
 * \brief Initialisation du curseur taille 8.
 * 
 * S'occupe de créer le sprite "curseur 8" en mode transparence. Le sprite est configuré
 * comme invisible par défaut. 
 */
void FAT_initCursor8() {
    FAT_cursor8_obj = ham_CreateObj((void*) cursor8_Bitmap, OBJ_SIZE_64X32,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursor8_obj, 0);
    ham_SetObjPrio(FAT_cursor8_obj, 1);
}

/**
 * \brief Initialisation du curseur de changement d'onglet dans l'écran instrument.
 * 
 * S'occupe de créer le sprite "curseur change" en mode transparence. Le sprite est configuré
 * comme invisible par défaut.  
 */
void FAT_initCursorChange() {
    FAT_cursorChange_obj = ham_CreateObj((void*) cursor_change_Bitmap, OBJ_SIZE_32X16,
            OBJ_MODE_SEMITRANSPARENT, 1, 0, 0, 0, 0, 0, 0, 0, 0);

    ham_SetObjVisible(FAT_cursorChange_obj, 0);
    ham_SetObjPrio(FAT_cursorChange_obj, 1);
}

/**
 * \brief Affiche le curseur 1.
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor1() {
    ham_SetObjVisible(FAT_cursor1_obj, 1);
}

/**
 * \brief Affiche le curseur 2.
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor2() {
    ham_SetObjVisible(FAT_cursor2_obj, 1);
}

/**
 * \brief Affiche le curseur 3.
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor3() {
    ham_SetObjVisible(FAT_cursor3_obj, 1);
}

/**
 * \brief Affiche le curseur 8.
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursor8() {
    ham_SetObjVisible(FAT_cursor8_obj, 1);
}

/**
 * \brief Cache le curseur 1. 
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor1() {
    ham_SetObjVisible(FAT_cursor1_obj, 0);
}

/**
 * \brief Cache le curseur 2. 
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor2() {
    ham_SetObjVisible(FAT_cursor2_obj, 0);
}

/**
 * \brief Cache le curseur 3. 
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor3() {
    ham_SetObjVisible(FAT_cursor3_obj, 0);
}

/**
 * \brief Cache le curseur 8. 
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursor8() {
    ham_SetObjVisible(FAT_cursor8_obj, 0);
}


/**
 * \brief Affiche le curseur de changement d'onglet. 
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera visible
 * au prochain commit.
 */
void FAT_cursors_showCursorChange() {
    ham_SetObjVisible(FAT_cursorChange_obj, 1);
}

/**
 * \brief Cache le curseur de changement d'onglet. 
 * 
 * Attention ! cette fonction ne s'occupe pas de commiter
 * l'affichage dans la mémoire GBA: seulement indiquer que le sprite sera invisible
 * au prochain commit.
 */
void FAT_cursors_hideCursorChange() {
    ham_SetObjVisible(FAT_cursorChange_obj, 0);
}

/**
 * \brief Déplace le curseur de changement d'onglet.
 * 
 * \param x abscisse (en px) 
 * \param y ordonnée (en px)
 */
void FAT_cursors_moveCursorChange(u8 x, u8 y) {
    ham_SetObjXY(FAT_cursorChange_obj, x, y);
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
}
#endif
