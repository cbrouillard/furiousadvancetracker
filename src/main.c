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
 * @mainpage FuriousAdvanceTracker
 *
 * FAT (FuriousAdvanceTracker) est un logiciel concu pour la composition musicale sur Gameboy Advance.
 * <b>FAT est actuellement en version de test (il n'est pas encore complet).</b><br/>
 * FAT est un <a href="http://fr.wikipedia.org/wiki/Tracker_%28musique%29">tracker</a> dont l'interface
 * s'inspire très profondément de <a href="http://www.littlesounddj.com">LSDJ</a> (LittleSoundDJ),
 * un logiciel très connu utilisable sur Gameboy. Malgré cela, FAT se démarque en ajoutant des fonctionnalités
 * inédites pour la composition de chiptunes sur GBA.
 *
 * - la GameboyAdvance dispose de 6 canaux sonores. FAT les exploite tous (plus ou moins complétement).
 * - FAT est orienté live. Un écran spécial est même prévu pour improviser des lignes mélodiques en live.
 * - et plein d'autres idées qui s'ajouteront probablement au fur et à mesure !
 *
 * FAT est gratuit et libre ! Vous pouvez le télécharger, l'utiliser avec un émulateur ou le "graver"
 * sur une cartouche GBA. Si vous remarquer un bug ou un comportement bizarre, faites un rapport de bug :
 * c'est simple, rapide, et surtout cela permet de faire évoluer le logiciel plus efficacement.<br/>
 *
 * <b>Vous êtes actuellement en train de lire une documentation technique réservée aux développeurs. Si vous n'êtes
 * pas développeur et souhaitez simplement tester FAT, alors VOUS N'ETES PAS AU BON ENDROIT !. Si vous souhaitez tester, retournez sur
 * <a href="http://www.furiousadvancetracker.com">www.furiousadvancetracker.com</a> et téléchargez le manuel utilisateur au format PDF. Merci !</b>
 *
 */

/**
* TODO :
* - implement effects (see: soundApi.h)
* - implement "Clear song data" and "Clear instr data" (as LSDJ)
* - implement this $$$ synth FM/AM
* - rework the CustomWave editor screen (move accross the sliders)
*/


/**
 * \file main.c
 * \brief Fichier code source principal avec la fonction main et l'inclusion de fat.h.
 */
#include <hel2.h>
#include <stdarg.h>

#include "soundApi/soundApi.h"
#include "headers/fat.h"

/**
 * \brief Fonction main. Si vous lisez le code source, il est judicieux de commencer par comprendre cette fonction.
 */
int main() {

    FAT_init();

    snd_init_kits();
    snd_init_soundApi(FAT_tracker.sampleRate);

    FAT_showIntro();

    FAT_screenSong_init();

    // Boucle infinie branchée sur la gestion des boutons de tous les écrans.
    FAT_mainLoop();

    return 0;
}
