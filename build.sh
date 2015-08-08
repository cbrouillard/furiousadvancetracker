#!/bin/sh
VERSION="1.0.0"

echo "### Nettoyage"
make clean
find . -name "*.o" -exec rm {} \;
find . -name "*.s" -exec rm {} \;
find . -name "*.gba" -exec rm {} \;
find . -name "*.elf" -exec rm {} \;
rm src/gfx/raw/* -rf

echo "### Compilation"
make gfx
make

echo "### Padbin pour execution du GBFS"
wine padbin.exe 256 FAT_v$VERSION.gba

echo "### Generation du SAMPLE filesystem"
rm *.gbfs
#objcopy -v -I binary -O elf32-little --rename-section .data=.rodata in_file out_file
wine gbfs.exe infos.gbfs samples/0nbkit
wine gbfs.exe default_samples.gbfs samples/0infos samples/*.snd
wine gbfs.exe tr606_samples.gbfs samples/tr-606-7/0infos samples/tr-606-7/*.snd
wine gbfs.exe battery_samples.gbfs samples/battery/0infos samples/battery/*.raw

echo "### Patch du GBA pour inclusion des samples"
cat FAT_v$VERSION.gba infos.gbfs default_samples.gbfs tr606_samples.gbfs battery_samples.gbfs > TMP.gba
mv TMP.gba FAT_v$VERSION.gba

echo "### Copie dans les daily_builds"
cp FAT_v$VERSION.gba daily_builds/FuriousAdvanceTracker_v$VERSION-`date '+%d-%B-%Y'`.gba

echo "### Lancement de l'émulateur"
vba  FAT_v$VERSION.gba

