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

#include "popup.h"

#define DIALOG_LAYER 0

#define DIALOG_SAVE 0
#define DIALOG_LOAD 1
#define DIALOG_NEW 4

void FAT_yesno_close();
void FAT_yesno_dialogSave_mainFunc();
void FAT_yesno_dialogLoad_mainFunc();
void FAT_yesno_dialogNewProject_mainFunc();
void FAT_onlyyes_dialog_mainFunc();
void FAT_yesno_dialogSave();
void FAT_yesno_dialogLoad();
void FAT_yesno_dialogNewProject();
void FAT_yesno_show(u8 idDialog, ...);

#endif	/* YESNO_DIALOG_H */
