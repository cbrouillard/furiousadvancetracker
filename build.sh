#!/bin/sh
VERSION="0.3.0"
echo "### Nettoyage"
make clean
rm *.elf *.gba *.s
echo "### Compilation"
make
echo "### Padbin pour execution du GBFS"
wine padbin.exe 256 FuriousAdvanceTracker_v$VERSION.gba
echo "### Generation du SAMPLE filesystem"
wine gbfs.exe default_samples.gbfs samples/0infos.txt samples/*.wav
echo "### Patch du GBA pour inclusion des samples"
cat FuriousAdvanceTracker_v$VERSION.gba default_samples.gbfs > TMP.gba
mv TMP.gba FuriousAdvanceTracker_v$VERSION.gba
echo "### Copie dans les daily_builds"
cp FuriousAdvanceTracker_v$VERSION.gba daily_builds/FuriousAdvanceTracker_v$VERSION-`date '+%d-%B-%Y'`.gba
echo "### Lancement de l'émulateur"
gvba FuriousAdvanceTracker_v$VERSION.gba
