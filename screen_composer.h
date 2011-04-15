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
#ifndef _SCREEN_COMPOSER_H_
#define	_SCREEN_COMPOSER_H_

bool FAT_screenComposer_isPopuped = 0;

// prototypes
void FAT_screenComposer_init();
void FAT_screenComposer_checkButtons();

void FAT_screenComposer_mainFunc() {
    if (mutex) {
        speedCounter++;
        ham_CopyObjToOAM();
        FAT_screenComposer_checkButtons();
    }
}

void FAT_screenComposer_init() {
    FAT_reinitScreen();

    // initialisation du fond (interface)
    ham_bg[2].ti = ham_InitTileSet((void*) screen_composer_Tiles, SIZEOF_16BIT(screen_composer_Tiles), 1, 1);
    ham_bg[2].mi = ham_InitMapSet((void *) screen_composer_Map, 1024, 0, 0);
    ham_InitBg(2, 1, 3, 0);

    // affichage d'un peu de texte

    // démarrage du cycle pour l'écran
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_screenComposer_mainFunc);
}

void FAT_screenComposer_checkButtons() {
    if (F_CTRLINPUT_SELECT_PRESSED) {
        if (!FAT_screenComposer_isPopuped) {
            // TODO hide project cursor
            FAT_popup_show();
            FAT_screenComposer_isPopuped = 1;
        }

        if (speedCounter >= SLOWDOWN_COUNTER) {
            FAT_popup_checkButtons();
            speedCounter = 0;
        }

    } else {
        if (FAT_screenComposer_isPopuped) {
            FAT_popup_hide();
            // TODO show project cursor
            FAT_screenComposer_isPopuped = 0;

            if (FAT_popup_getSelectedIcon() != SCREEN_COMPOSER_ID) {
                // TODO hide project cursor
                FAT_switchToScreen(FAT_popup_getSelectedIcon());
            }
        }

        if (speedCounter >= SLOWDOWN_COUNTER) {
            if (F_CTRLINPUT_RIGHT_PRESSED) {
            }

            if (F_CTRLINPUT_LEFT_PRESSED) {
            }

            if (F_CTRLINPUT_DOWN_PRESSED) {
            }

            if (F_CTRLINPUT_UP_PRESSED) {
            }

            if (F_CTRLINPUT_A_PRESSED) {

            }

            // TODO commit project cursor move
            speedCounter = 0;
        }
    }
}

#endif	/* SCREEN_COMPOSER_H */

