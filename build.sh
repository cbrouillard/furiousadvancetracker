#!/bin/sh
VERSION="0.3.0"
echo "### Nettoyage"
make clean
rm *.elf *.gba *.s
rm soundApi/*.o
echo "### Compilation"
make
echo "### Padbin pour execution du GBFS"
wine padbin.exe 256 FuriousAdvanceTracker_v$VERSION.gba
echo "### Generation du SAMPLE filesystem"
rm *.gbfs
#objcopy -v -I binary -O elf32-little --rename-section .data=.rodata in_file out_file
wine gbfs.exe infos.gbfs samples/0nbkit
wine gbfs.exe default_samples.gbfs samples/0infos samples/*.snd
wine gbfs.exe battery_samples.gbfs samples/battery/0infos samples/battery/*.raw
echo "### Patch du GBA pour inclusion des samples"
cat FuriousAdvanceTracker_v$VERSION.gba infos.gbfs default_samples.gbfs battery_samples.gbfs > TMP.gba
mv TMP.gba FuriousAdvanceTracker_v$VERSION.gba
echo "### Copie dans les daily_builds"
cp FuriousAdvanceTracker_v$VERSION.gba daily_builds/FuriousAdvanceTracker_v$VERSION-`date '+%d-%B-%Y'`.gba
echo "### Lancement de l'émulateur"
gvba FuriousAdvanceTracker_v$VERSION.gba
