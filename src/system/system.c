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
* \file system.c
* \brief Code contenant les routines systèmes (init, ...)
*/

#include <hel2.h>
#include <stdarg.h>

#include "../headers/fat.h"

u8 ATTR_EWRAM ATTR_ALIGNED(4) g_BgTextSystemMemory[HEL_SUBSYSTEM_BGTEXT_REQUIREDMEMORY];
u16 ATTR_EWRAM g_CharLUT[256];
// attention, table ASCII uniquement sinon ça fout la grouille.
const unsigned char CHARORDER[] =
        " BCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmn"\
    "opqrstuvwxyz0123456789,.-;:A#^+*@"\
    "!\"~$%&/()=?|\\<>[]{}¹²³°";

u8 ATTR_EWRAM ATTR_ALIGNED(4) g_ObjSystemBuffer[HEL_SUBSYSTEM_OBJ_REQUIREDMEMORY];

// Reserve memory for the Map-System. This buffer
// is used to manage internal states of the Map-System.
// You can achieve a little performance increase when you
// store it in IWRAM, but keep in mind, IWRAM is very limited!
// The recommended memory location is EWRAM.
u8 ATTR_EWRAM ATTR_ALIGNED(4) g_MapSystemBuffer[HEL_SUBSYSTEM_MAP_REQUIREDMEMORY];

/**
 * \brief Initialisation de HEL/HAM et d'autres données propres à FAT.
 *
 * Initialisations:
 * - HEL/HAM (init, text, bgMode, textCol, fx)
 * - les palettes pour FAT (screen et sprite)
 * - la popup de déplacement
 * - les curseurs
 * - les sprites
 * - les données du projet
 */
void FAT_init() {
    // HAM !
    ham_Init();
    hel_SysSetPrefetch(FALSE);

    FAT_filesystem_checkFs();

    hel_BgSetMode(0);

    hel_MapInit(g_MapSystemBuffer);
    hel_BgTextInit((void*) g_BgTextSystemMemory);
    hel_ObjInit(g_ObjSystemBuffer);

    hel_PadInit();
    hel_PadSetRepeatDelay(PAD_BUTTON_R | PAD_BUTTON_L | PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_UP | PAD_BUTTON_DOWN | PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_START, 1);
    hel_PadSetRepeatRate(PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_UP | PAD_BUTTON_DOWN, 10);
    hel_PadSetRepeatRate(PAD_BUTTON_R | PAD_BUTTON_L | PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_START, 0);

    // initialisation des palettes.
    FAT_initSpritePalette();
    FAT_initScreenPalette();

    // Initialize the tileset and an empty
    // mapset using regular HAMlib functions
    //ham_bg[TEXT_LAYER].ti = ham_InitTileSet(ResData(RES_TEXT_RAW), RES_TEXT_RAW_SIZE16, 1, 1);
    ham_bg[TEXT_LAYER].ti = ham_InitTileSet((void*) ResData(RES_TEXT_RAW), RES_TEXT_RAW_SIZE16, 1, 1);
    ham_bg[TEXT_LAYER].mi = ham_InitMapEmptySet((u8) 640, 0);

    hel_BgTextCreate(
            TEXT_LAYER, // BgNo
            1, // Width of one character specified in tiles
            1, // Height of one character specified in tiles
            //ResData(RES_CHARSET8X8_MAP), // Pointer to character map
            ResData(RES_TEXT_MAP),
            CHARORDER, // Pointer to array that reflects the order of characters on source graphic
            g_CharLUT, // Pointer to buffer that receives the generated lookup table
            BGTEXT_FLAGS_GENERATELUT); // Flags that control creation and print behaviour

    ham_InitBg(TEXT_LAYER, TRUE, 0, FALSE);

    // initialisation de l'écran "Popup" (la map de déplacement)
    FAT_popup_init();

    hel_IntrStartHandler(INT_TYPE_VBL, (void*) &VBLInterruptHandler);

    // initialisation des curseurs
    FAT_initCursor1();
    FAT_initCursor2();
    FAT_initCursor3();
    FAT_initCursor8();
    FAT_initCursorChange();
    FAT_initCursorsKeyboard();

    FAT_popup_initCursors();

    FAT_screenInstrument_tabCursorInit();

    // Initialisation du lecteur
    FAT_player_firstInit();

    // chargement des sprites pour l'écran instrument
    FAT_screenInstrument_initSpritesForInstrument();

    FAT_screenSong_initCursor();
    FAT_screenLive_initCursor();
    FAT_screenNotes_initCursor();
    FAT_screenBlocks_initCursor();
    FAT_screenComposer_initCursor();
    FAT_screenFilesystem_initCursor();

    // intialisation des données "tracker" stockées en RAM
    FAT_data_initData();
}

/**
 * \brief La palette pour les sprites est différente: cette fonction la charge au bon endroit.
 */
void FAT_initSpritePalette() {
    hel_PalObjLoad16(ResData16(RES_SPRITES_PAL), 0);
}

/**
 * \brief Charge la palette pour les écrans: les sprites sont exclus.
 */
void FAT_initScreenPalette() {
    hel_PalBgLoad256(ResData16(RES_SCREEN_PAL));
}
