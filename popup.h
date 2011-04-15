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
#ifndef _POPUP_H_
#define _POPUP_H_

/**
 * Definit le background utilisé pour afficher la popup. BG0
 */
#define POPUP_LAYER 0

// Définit ou le curseur de sélection se situe par défaut
#define POPUP_CURSOR_DEFAULT_X 94 
#define POPUP_CURSOR_DEFAULT_Y 64
// Définit ou le curseur d'affichage de l'écran courrant se situe par défaut
#define ACTUAL_SCREEN_CURSOR_DEFAULT_X 103
#define ACTUAL_SCREEN_CURSOR_DEFAULT_Y 60

/** 
 * Définit la taille d'une icone dans la popup. On ne se déplace que de droite 
 * à gauche, donc seul X est nécessaire
 */
#define POPUP_ICON_SIZE_X 24
#define POPUP_ICON_WHITE_SPACE 4

// Définit les bornes d'affichages pour l'affichage du curseur.
#define POPUP_FIRST_ICON_X 11
#define POPUP_LAST_ICON_X 206

// ID Sprite pour les objets curseurs spécifique à l'écran popup
u8 FAT_popup_cursorSelectionObj, FAT_popup_cursorActualScreenObj;
// position actuelle du curseur de selection
u8 FAT_popup_cursorSelectionX, FAT_popup_cursorSelectionY;
// position actuelle du curseur indiquant l'écran courant
u8 FAT_popup_cursorActualScreenX, FAT_popup_cursorActualScreenY;

// Cette variable contient l'id de l'écran sélectionné
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
 * Récupère l'écran sélectionné.
 * @return id écran
 */
u8 FAT_popup_getSelectedIcon() {
    return FAT_popup_selectedIcon;
}

/**
 * Déplace le curseur d'indication "écran actuel" à sa place.
 * Le positionnement est calculé en fonction de l'id de l'écran et de la taille
 * des icônes de l'interface. 
 * @param screenId
 */
void FAT_popup_setCurrentScreen(u8 screenId) {
    FAT_popup_cursorActualScreenX = FAT_popup_cursorSelectionX + (POPUP_ICON_SIZE_X / 2) - 2;
    ham_SetObjXY(FAT_popup_cursorActualScreenObj, FAT_popup_cursorActualScreenX, FAT_popup_cursorActualScreenY);
}

/**
 * Cette fonction permet de tester les actions utilisateurs sur la popup.
 */
void FAT_popup_checkButtons() {
    if (F_CTRLINPUT_RIGHT_PRESSED) {
        FAT_popup_moveSelectionCursorRight();
    }

    if (F_CTRLINPUT_LEFT_PRESSED) {
        FAT_popup_moveSelectionCursorLeft();
    }

    FAT_popup_commitSelectionCursorMove();
}

/**
 * Initialisation de l'écran popup. Chargement dans la mémoire GBA de l'écran.
 * La popup est cachée par défaut. Les données sont chargées dans le layer POPUP_LAYER, elles le restent
 * jusqu'à extinction du programme. 
 */
void FAT_popup_init() {
    map_fragment_info_ptr popup;

    // initialisation de la popup de déplacement (cachée)
    ham_bg[POPUP_LAYER].ti = ham_InitTileSet((void*) popup_Tiles, SIZEOF_16BIT(popup_Tiles), 1, 1);
    ham_bg[POPUP_LAYER].mi = ham_InitMapEmptySet(0, 0);
    popup = ham_InitMapFragment((void*) popup_Map, 30, 20, 0, 0, 30, 20, 0);
    ham_InsertMapFragment(popup, POPUP_LAYER, 0, 0);
    ham_InitBg(POPUP_LAYER, 1, 0, 0);
    FAT_popup_hide();
}

/**
 * Initialisation des curseurs spécifiques à l'écran popup. Chargement des bitmaps + positionnement aux valeurs
 * par défauts. La méthode les cache ensuite. 
 */
void FAT_popup_initCursors() {
    FAT_popup_cursorSelectionX = POPUP_CURSOR_DEFAULT_X;
    FAT_popup_cursorSelectionY = POPUP_CURSOR_DEFAULT_Y;

    FAT_popup_cursorActualScreenX = ACTUAL_SCREEN_CURSOR_DEFAULT_X;
    FAT_popup_cursorActualScreenY = ACTUAL_SCREEN_CURSOR_DEFAULT_Y;

    FAT_popup_cursorSelectionObj = ham_CreateObj((void*) cursor_popup_Bitmap, OBJ_SIZE_32X64,
            OBJ_MODE_NORMAL, 1, 0, 0, 0, 0, 0, 0, FAT_popup_cursorSelectionX, FAT_popup_cursorSelectionY);

    FAT_popup_cursorActualScreenObj = ham_CreateObj((void*) actual_screen_popup_Bitmap, OBJ_SIZE_8X8,
            OBJ_MODE_NORMAL, 1, 0, 0, 0, 0, 0, 0, FAT_popup_cursorActualScreenX, FAT_popup_cursorActualScreenY);

    // cachés par défaut                    
    FAT_popup_hideCursors();
}

/**
 * Cache les curseurs (tous). 
 */
void FAT_popup_hideCursors() {
    ham_SetObjVisible(FAT_popup_cursorSelectionObj, 0);
    ham_SetObjVisible(FAT_popup_cursorActualScreenObj, 0);
}

/**
 * Affiche les curseurs (tous). 
 */
void FAT_popup_showCursors() {
    ham_SetObjVisible(FAT_popup_cursorSelectionObj, 1);
    ham_SetObjVisible(FAT_popup_cursorActualScreenObj, 1);
}

/**
 * Affiche l'écran popup. Cette méthode affiche également les curseurs. 
 */
void FAT_popup_show() {
    ham_SetBgVisible(0, 1);
    FAT_popup_showCursors();
}

/**
 * Cache l'écran popup. Cette méthode cache aussi les curseurs. 
 */
void FAT_popup_hide() {
    ham_SetBgVisible(0, 0);
    FAT_popup_hideCursors();
}

/**
 * Déplace les coordonnées du curseur vers l'icône située à sa droite. 
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
 * Déplace les coordonnées du curseur vers l'icône située à sa gauche. 
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
 * Commit tous les changements effectués sur les sprites (positionnement, bitmap) 
 * pour affichage physique à l'écran. 
 */
void FAT_popup_commitSelectionCursorMove() {
    ham_SetObjXY(FAT_popup_cursorSelectionObj, FAT_popup_cursorSelectionX, FAT_popup_cursorSelectionY);
}


#endif
