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

/**
 * \brief Definit le background utilisé pour afficher la popup. BG0
 */
#define POPUP_LAYER 0

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

/** \brief Id Sprite pour l'objet curseur de sélection dans l'écran POPUP. */
THandle FAT_popup_cursorSelectionObj;
/** \brief Id Sprite pour l'objet curseur d'affichage de l'écran courant. */
THandle FAT_popup_cursorActualScreenObj;
/** \brief Position actuelle du curseur de selection. */
u8 FAT_popup_cursorSelectionX;
/** \brief Position actuelle du curseur de selection. */
u8 FAT_popup_cursorSelectionY;
/** \brief Position actuelle du curseur indiquant l'écran courant. */
u8 FAT_popup_cursorActualScreenX;
/** \brief Position actuelle du curseur indiquant l'écran courant. */
u8 FAT_popup_cursorActualScreenY;

/** \brief Cette variable contient l'id de l'écran sélectionné. */
u8 FAT_popup_selectedIcon = SCREEN_SONG_ID;

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

/**
 * \brief Récupère l'id de l'écran sélectionné.
 * 
 * Méthode un peu inutile ... héritage de l'objet. 
 * 
 * @return id de l'écran sélectionné
 */
u8 FAT_popup_getSelectedIcon() {
    return FAT_popup_selectedIcon;
}

/**
 * \brief Déplace le curseur d'indication "écran actuel" à sa place.
 * 
 * Le positionnement est calculé en fonction de l'id de l'écran et de la taille
 * des icônes de l'interface. 
 */
void FAT_popup_moveSelectedScreenCursor() {
    FAT_popup_cursorActualScreenX = FAT_popup_cursorSelectionX + (POPUP_ICON_SIZE_X / 2) - 2;
    hel_ObjSetXY(FAT_popup_cursorActualScreenObj, FAT_popup_cursorActualScreenX, FAT_popup_cursorActualScreenY);
}

/**
 * \brief Cette fonction permet de tester les actions utilisateurs sur la popup.
 */
void FAT_popup_checkButtons() {
    if (hel_PadQuery()->Pressed.Right) {
        FAT_popup_moveSelectionCursorRight();
    }

    if (hel_PadQuery()->Pressed.Left) {
        FAT_popup_moveSelectionCursorLeft();
    }

    FAT_popup_commitSelectionCursorMove();
}

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
    ham_bg[POPUP_LAYER].mi = ham_InitMapSet((void*)ResData(RES_SCREEN_POPUP_MAP), 1024, 0, 0);
    ham_InitBg(POPUP_LAYER, 1, 0, 0);

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

/**
 * \brief Cache les curseurs (tous). 
 */
void FAT_popup_hideCursors() {
    hel_ObjSetVisible(FAT_popup_cursorSelectionObj, 0);
    hel_ObjSetVisible(FAT_popup_cursorActualScreenObj, 0);
}

/**
 * \brief Affiche les curseurs (tous). 
 */
void FAT_popup_showCursors() {
    hel_ObjSetVisible(FAT_popup_cursorSelectionObj, 1);
    hel_ObjSetVisible(FAT_popup_cursorActualScreenObj, 1);
}

/**
 * \brief Affiche l'écran popup. Cette méthode affiche également les curseurs. 
 */
void FAT_popup_show() {
    ham_SetBgVisible(POPUP_LAYER, 1);
    FAT_popup_showCursors();
}

/**
 * \brief Cache l'écran popup. Cette méthode cache aussi les curseurs. 
 */
void FAT_popup_hide() {
    FAT_popup_hideCursors();
    ham_SetBgVisible(POPUP_LAYER, 0);
}

/**
 * \brief Déplace les coordonnées du curseur vers l'icône située à sa droite. 
 * 
 * Attention, cette méthode ne fait que changer le positionnement en mémoire: 
 * le sprite n'est pas déplacée à l'écran. Pour déplacer l'affichage du sprite, faites
 * appel à la méthode FAT_popup_commitSelectionCursorMove().
 */
void FAT_popup_moveSelectionCursorRight() {
    if (!(FAT_popup_cursorSelectionX >= POPUP_LAST_ICON_X - 1)) {
        FAT_popup_cursorSelectionX += POPUP_ICON_SIZE_X + POPUP_ICON_WHITE_SPACE;
        FAT_popup_selectedIcon++;
    }
}

/**
 * \brief Déplace les coordonnées du curseur vers l'icône située à sa gauche. 
 * 
 * Attention, cette méthode ne fait que changer le positionnement en mémoire: 
 * le sprite n'est pas déplacée à l'écran. Pour déplacer l'affichage du sprite, faites
 * appel à la méthode FAT_popup_commitSelectionCursorMove().
 */
void FAT_popup_moveSelectionCursorLeft() {
    if (!(FAT_popup_cursorSelectionX <= POPUP_FIRST_ICON_X)) {
        FAT_popup_cursorSelectionX -= POPUP_ICON_SIZE_X + POPUP_ICON_WHITE_SPACE;
        FAT_popup_selectedIcon--;
    }
}

/**
 * \brief Commit tous les changements effectués sur les sprites (positionnement, bitmap) 
 * pour affichage physique à l'écran. 
 */
void FAT_popup_commitSelectionCursorMove() {
    hel_ObjSetXY(FAT_popup_cursorSelectionObj, FAT_popup_cursorSelectionX, FAT_popup_cursorSelectionY);
}


#endif
