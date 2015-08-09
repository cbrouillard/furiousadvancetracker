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

# Packaging des samples déjà inclus.
wine gbfs.exe devmess.gbfs samples/dev-mess/0infos samples/dev-mess/*.snd
wine gbfs.exe littlescale-md.gbfs samples/littlescale-md/0infos samples/littlescale-md/*.snd
wine gbfs.exe c64-drums.gbfs samples/c64-drums/0infos samples/c64-drums/*.snd
wine gbfs.exe battery.gbfs samples/battery/0infos samples/battery/*.snd
wine gbfs.exe rhythms.gbfs samples/rhythm/0infos samples/rhythm/*.snd
wine gbfs.exe tr606.gbfs samples/tr-606-7/0infos samples/tr-606-7/*.snd


echo "### Patch du GBA pour inclusion des samples"
cat FAT_v$VERSION.gba infos.gbfs devmess.gbfs littlescale-md.gbfs c64-drums.gbfs battery.gbfs rhythms.gbfs tr606.gbfs > TMP.gba
mv TMP.gba FAT_v$VERSION.gba

echo "### Copie dans les daily_builds"
cp FAT_v$VERSION.gba daily_builds/FuriousAdvanceTracker_v$VERSION-`date '+%d-%B-%Y'`.gba

echo "### Lancement de l'émulateur"
vba  FAT_v$VERSION.gba

