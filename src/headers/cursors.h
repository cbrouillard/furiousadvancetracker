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
THandle FAT_cursor1_obj;
/**
 * ID technique HAM pour le cursor de taille 2.
 */
THandle FAT_cursor2_obj;
/**
 * ID technique HAM pour le cursor de taille 3.
 */
THandle FAT_cursor3_obj;
/**
 * ID technique HAM pour le cursor de taille 8.
 */
THandle FAT_cursor8_obj;
/**
 * ID technique HAM pour le cursor de changement d'onglet (partie instrument).
 */
THandle FAT_cursorChange_obj;

THandle FAT_cursorKeyboard_obj;
THandle FAT_cursorKeyboard_select_obj;

/** \brief Objet HAM pour référencer le sprite "curseur player" de taille 2. */
THandle FAT_cursor_player3_obj;
/** \brief Objet HAM pour référencer le sprite "curseur player" de taille 3. */
THandle FAT_cursor_player2_obj;
/** \brief Objet HAM pour référencer les sprites "curseur player" utilisés dans l'écran SONG. */
THandle FAT_cursor_playerSequences_obj[6];
/** \brief Les curseurs d'attente indiquant que le channel a été activé mais en attente de synchro avant de se lancer */
THandle FAT_cursor_playerLiveWait_obj[6];

void FAT_initCursor1();
void FAT_initCursor2();
void FAT_initCursor3();
void FAT_initCursor8();
void FAT_initCursorChange();
void FAT_initCursorsKeyboard ();

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

void FAT_cursors_showCursorKeyboard() {
    hel_ObjSetVisible(FAT_cursorKeyboard_obj, 1);
}

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

void FAT_cursors_hideCursorKeyboard() {
    hel_ObjSetVisible(FAT_cursorKeyboard_obj, 0);
}

void FAT_cursors_hideCursorKeyboard_select() {
    hel_ObjSetVisible(FAT_cursorKeyboard_select_obj, 0);
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

void FAT_cursors_moveCursorKeyboard(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursorKeyboard_obj, x,y);
}

void FAT_cursors_moveCursorKeyboard_select(u8 x, u8 y) {
    hel_ObjSetXY(FAT_cursorKeyboard_select_obj, x,y);
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
#endif
