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
 * \file screen_help.h
 * \brief Ce fichier le code pour afficher TOUS les écrans d'aide.
 *
 */

#ifndef _SCREEN_HELP_H_
#define	_SCREEN_HELP_H_

void FAT_screenHelp_init(u8 screenIdForHelp);
void FAT_screenHelp_checkButtons();

u8 FAT_getIsHelpActivated ();

#endif	/* SCREEN_HELP_H */
