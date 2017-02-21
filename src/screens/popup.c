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
