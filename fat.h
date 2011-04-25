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
#ifndef _FAT_H_
#define _FAT_H_

// IDs des écrans
#define SCREEN_PROJECT_ID 0
#define SCREEN_LIVE_ID 1
#define SCREEN_COMPOSER_ID 2
#define SCREEN_SONG_ID 3
#define SCREEN_BLOCKS_ID 4
#define SCREEN_NOTES_ID 5
#define SCREEN_INSTRUMENTS_ID 6
#define SCREEN_EFFECTS_ID 7
#define NB_SCREEN 8;

#define TEXT_COLOR 245 // 159, 247

#define INPUT_R_CURSOR_CHANGE_X 216
#define INPUT_R_CURSOR_CHANGE_Y 24

/**
 * Cette variable sert à gérer les contextes conflictuels (notamment dans les
 * boucles affichant du texte à gogo). Si le mutex est à zéro alors aucun affichage
 * ne pourra avoir lieu.
 * Usage:
 * void printBeaucoupTexte() {
 * mutex = 0;
 * print
 * print
 * mutex = 1;
 * }
 * NE PAS TOUCHER !
 */
bool mutex = 1;


/**
 * Cette variable sert à compter le nombre de rafraichissement nécessaire avant
 * de prendre en considération les actions utilisateurs.
 * Valeurs optimales:
 * 4 pour la GBA hard
 * 5~7 pour l'émulateur
 */
u8 speedCounter = 0;
#define SLOWDOWN_COUNTER 4

// définition globale du format d'affichage des numéros de lignes
#define FAT_FORMAT_LINE "%.2x\0"

// stocke l'id de l'écran sur lequel l'utilisateur est
u8 FAT_currentScreen = SCREEN_SONG_ID;

// prototypes
void FAT_initSpritePalette();
void FAT_initScreenPalette();
void FAT_switchToScreen(u8 screenId);
void FAT_reinitScreen();
void FAT_forceClearTextLayer();
void FAT_waitVSync();
void FAT_blockCPU (u16 time);

#include "gfx.h"

#include "data.h"
#include "cursors.h"

void FAT_player_startPlayerFromSequences(u8 startLine);
void FAT_player_startPlayerFromBlocks(u8 sequenceId, u8 startLine, u8 channel);
void FAT_player_startPlayerFromNotes(u8 blockId, u8 startLine, u8 channel); 
void FAT_player_stopPlayer();
void FAT_player_playComposerNote (u8 noteLine);

bool FAT_isCurrentlyPlaying = 0;

#include "popup.h"
#include "screen_song.h"
#include "screen_project.h"
#include "screen_live.h"
#include "screen_composer.h"
#include "screen_blocks.h"
#include "screen_notes.h"
#include "screen_instrument.h"
#include "screen_effects.h"

#include "player.h"
/**
 * Initialisation de HAM et d'autres données propres à FAT. 
 */
void FAT_init() {
    // HAM !
    ham_Init();
    
    //ham_InitRAM (RAM_TYPE_SRAM_256K);
    //ham_ResetRAM ();
    
    ham_InitText(1);
    ham_SetBgMode(0);
    ham_SetTextCol(TEXT_COLOR, 0);

    ham_SetFxMode(FX_LAYER_SELECT(0, 0, 0, 0, 1, 0),
            FX_LAYER_SELECT(0, 0, 1, 1, 0, 0),
            FX_MODE_ALPHABLEND);
    ham_SetFxAlphaLevel(7, 7);

    // initialisation des palettes.
    FAT_initScreenPalette();
    FAT_initSpritePalette();

    // initialisation de l'écran "Popup" (la map de déplacement)
    FAT_popup_init();

    // initialisation des curseurs
    FAT_initCursor1();
    FAT_initCursor2();
    FAT_initCursor3();
    FAT_initCursorChange ();
    FAT_popup_initCursors();
    FAT_screenInstrument_tabCursorInit();
    
    FAT_player_initCursors();
    //FAT_cursors_initCursorsChannel ();
    
    // chargement des sprites pour l'écran instrument
    FAT_screenInstrument_initSpritesForInstrument ();

    FAT_screenSong_initCursor();
    FAT_screenBlocks_initCursor();
    FAT_screenNotes_initCursor();
    FAT_screenComposer_initCursor();
    
    // intialisation des données "tracker" stockées en RAM
    FAT_data_initData();
}

void FAT_initIntroPalette() {
    ham_LoadBGPal((void*) intro_Palette, 256);
}

/**
 * Méthode pour afficher un simple écran "titre" avec une boucle infinie en
 * attente du bouton "START". 
 */
void FAT_showIntro() {
    FAT_reinitScreen();

    FAT_initIntroPalette();

    ham_bg[2].ti = ham_InitTileSet((void*) screen_intro_Tiles, SIZEOF_16BIT(screen_intro_Tiles), 1, 1);
    ham_bg[2].mi = ham_InitMapSet((void *) screen_intro_Map, 1024, 0, 0);
    ham_InitBg(2, 1, 3, 0);

    ham_DrawText(0, 1, "SIZE %d octets", (sizeof(tracker)));
    
    while (!F_CTRLINPUT_START_PRESSED) {
    }

    ham_InitBg(2, 0, 3, 0);
    FAT_initScreenPalette();
}

/**
 * Méthode qui permet de réinitialiser le BG2 proprement. 
 * NE PAS TOUCHER !  
 */
void FAT_reinitScreen() {
    if (ham_bg[2].ti) {
        //        ham_InitBg(2, 0, 3, 0);
        ham_DeInitTileSet(ham_bg[2].ti);
        ham_DeInitMapSet(ham_bg[2].mi);
    }
    FAT_forceClearTextLayer();
}

/**
 * TODO refactorme
 * Méthode à réfactorer : effacer l'écran texte en affichant des espaces partout. 
 */
void FAT_forceClearTextLayer() {
    for (u8 l = 1; l < 20; l++) {
        ham_DrawText(0, l, "                              ");
    }
}

/*
 * La palette pour l'écran d'introduction est différente (plus complete).
 */
void FAT_initSpritePalette() {
    ham_LoadObjPal((void*) sprite_Palette, 256);
}

void FAT_initScreenPalette() {
    ham_LoadBGPal((void*) screen_Palette, 256);
}

/**
 * Cette méthode permet de changer d'écran.
 * @param screenId l'id de l'écran que l'on souhaite afficher.
 */
void FAT_switchToScreen(u8 screenId) {
    FAT_currentScreen = screenId;
    switch (screenId) {
        case SCREEN_PROJECT_ID:
            FAT_screenProject_init();
            break;
        case SCREEN_LIVE_ID:
            FAT_screenLive_init();
            break;
        case SCREEN_SONG_ID:
            FAT_screenSong_init();
            break;
        case SCREEN_BLOCKS_ID:
            FAT_screenBlocks_init();
            break;
        case SCREEN_NOTES_ID:
            FAT_screenNotes_init();
            break;
        case SCREEN_EFFECTS_ID:
            FAT_screenEffects_init();
            break;
        case SCREEN_COMPOSER_ID:
            FAT_screenComposer_init();
            break;
        case SCREEN_INSTRUMENTS_ID:
            FAT_screenInstrument_init();
            break;
    }

    FAT_popup_setCurrentScreen(screenId);
}

void FAT_waitVSync() {
    while (F_VCNT_CURRENT_SCANLINE < 160) {
    }
}

void FAT_wait(u32 nbFrames) {
    u32 i = 0;
    while (i++ < nbFrames)
        FAT_waitVSync();
}

void FAT_blockCPU (u16 time){
    u16 i = 0;
    while (i++ < time){
        // CPU bloqué
    }
}

#endif

