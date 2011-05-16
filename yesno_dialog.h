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
 * \file yesno_dialog.h 
 * \brief Ce fichier définit toutes les fonctions utiles pour gérer toutes les boites
 * de dialogue de type "OUI ou NON". (L = NON, R = OUI).
 */

#ifndef _YESNO_DIALOG_H_
#define	_YESNO_DIALOG_H_

#include "fat.h"


#define DIALOG_LAYER 0

#define DIALOG_SAVE 0
#define DIALOG_LOAD 1


/**
 * \brief Fonction principale de la boite de dialog SAVE
 */
void FAT_yesno_dialogSave_mainFunc() {
    if (mutex) {
        ham_CopyObjToOAM();
        if (iCanPressAKey) {
            
            if (F_CTRLINPUT_L_PRESSED){
                FAT_yesno_close();
            }
            
            else if (F_CTRLINPUT_R_PRESSED){
                FAT_yesno_close();
                FAT_data_project_save();
                ham_DrawText(23, 16, "SAVED  !");
            }
        }
    }
}

/**
 * \brief Fonction principale de la boite de dialog LOAD
 */
void FAT_yesno_dialogLoad_mainFunc() {
    if (mutex) {
        ham_CopyObjToOAM();
        if (iCanPressAKey) {
            
            if (F_CTRLINPUT_L_PRESSED){
                FAT_yesno_close();
            }
            
            else if (F_CTRLINPUT_R_PRESSED){
                FAT_yesno_close();
                FAT_data_project_load();
                ham_DrawText(23, 16, "LOADED !");
            }
        }
    }
}

/**
 * \brief Ferme la boite de dialogue et reinitialise la popup (qui est sur le même layer). 
 */
void FAT_yesno_close (){
    ham_StopIntHandler(INT_TYPE_VBL);
    FAT_popup_init();
    FAT_switchToScreen(FAT_currentScreen);
}

void FAT_yesno_dialogSave (){
 
    ham_bg[DIALOG_LAYER].ti = ham_InitTileSet((void*) screen_dialog_save_Tiles, SIZEOF_16BIT(screen_dialog_save_Tiles), 1, 1);
    ham_bg[DIALOG_LAYER].mi = ham_InitMapSet((void *) screen_dialog_save_Map, 1024, 0, 0);
    ham_InitBg(DIALOG_LAYER, 1, 0, 0);
    
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_yesno_dialogSave_mainFunc);
    
}

void FAT_yesno_dialogLoad (){
 
    ham_bg[DIALOG_LAYER].ti = ham_InitTileSet((void*) screen_dialog_load_Tiles, SIZEOF_16BIT(screen_dialog_load_Tiles), 1, 1);
    ham_bg[DIALOG_LAYER].mi = ham_InitMapSet((void *) screen_dialog_load_Map, 1024, 0, 0);
    ham_InitBg(DIALOG_LAYER, 1, 0, 0);
    
    ham_StopIntHandler(INT_TYPE_VBL);
    ham_StartIntHandler(INT_TYPE_VBL, (void*) &FAT_yesno_dialogLoad_mainFunc);
    
}

void FAT_yesno_show (u8 idDialog){
    if (ham_bg[POPUP_LAYER].ti) {
        //        ham_InitBg(2, 0, 3, 0);
        ham_DeInitTileSet(ham_bg[POPUP_LAYER].ti);
        ham_DeInitMapSet(ham_bg[POPUP_LAYER].mi);
    }
    
    switch (idDialog){
        case DIALOG_SAVE:
            FAT_yesno_dialogSave();
            break;
        case DIALOG_LOAD:
            FAT_yesno_dialogLoad();
            break;
    }
}

#endif	/* YESNO_DIALOG_H */

