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
 * \file popup.h
 * \brief Ce fichier contient toutes les méthodes utiles pour la gestion de l'écran "popup" (la barre des tâches permettant
 * de changer d'écran).
 */

#ifndef _POPUP_H_
#define _POPUP_H_

/** \brief Définit la position par défaut du curseur de sélection. */
#define POPUP_CURSOR_DEFAULT_X 94
/** \brief Définit la position par défaut du curseur de sélection. */
#define POPUP_CURSOR_DEFAULT_Y 64
/** \brief Définit la position par défaut du curseur d'affichage de l'écran actuellement sélectionné. */
#define ACTUAL_SCREEN_CURSOR_DEFAULT_X 103
/** \brief Définit la position par défaut du curseur d'affichage de l'écran actuellement sélectionné. */
#define ACTUAL_SCREEN_CURSOR_DEFAULT_Y 60

/**
 * \brief Définit la taille d'une icone dans la popup.
 *
 * On ne se déplace que de droite à gauche, donc seul X est nécessaire.
 */
#define POPUP_ICON_SIZE_X 24
/**
 * \brief Définit la taille de l'espace blanc qui existe entre chaque icône.
 */
#define POPUP_ICON_WHITE_SPACE 4

/** \brief Définit les bornes d'affichages pour l'affichage du curseur. */
#define POPUP_FIRST_ICON_X 11
/** \brief Définit les bornes d'affichages pour l'affichage du curseur. */
#define POPUP_LAST_ICON_X 206

// prototypes
void FAT_popup_init();
void FAT_popup_show();
void FAT_popup_hide();
void FAT_popup_initCursors();
void FAT_popup_hideCursors();
void FAT_popup_showCursors();
void FAT_popup_checkButtons();
void FAT_popup_moveSelectionCursorRight();
void FAT_popup_moveSelectionCursorLeft();
void FAT_popup_commitSelectionCursorMove();
u8 FAT_popup_getSelectedIcon();
void FAT_popup_setSelectedIcon (u8 value);
void FAT_popup_moveSelectedScreenCursor();

#endif
