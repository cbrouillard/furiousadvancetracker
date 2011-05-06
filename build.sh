#!/bin/sh
VERSION="0-02"
echo "### Nettoyage"
make clean
rm *.elf *.gba *.s
echo "### Compilation"
make
echo "### Copie dans les dayly_builds"
cp FuriousAdvanceTracker_v$VERSION.gba dayly_build/FuriousAdvanceTracker_v$VERSION-`date '+%d-%B-%Y'`.gba
echo "### Lancement de l'émulateur"
gvba FuriousAdvanceTracker_v$VERSION.gba
