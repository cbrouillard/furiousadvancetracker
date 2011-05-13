#!/bin/sh
VERSION="0-02"
echo "### Nettoyage"
make clean
rm *.elf *.gba *.s
echo "### Compilation"
make
echo "### Copie dans les daily_builds"
cp FuriousAdvanceTracker_v$VERSION.gba daily_builds/FuriousAdvanceTracker_v$VERSION-`date '+%d-%B-%Y'`.gba
echo "### Lancement de l'émulateur"
gvba FuriousAdvanceTracker_v$VERSION.gba
