#!/bin/bash
VERSION="1.1.1"

cleanAll () {
echo "### Nettoyage"
make clean
find . -name "*.o" -exec rm {} \;
find . -name "*.s" -exec rm {} \;
find . -name "*.gba" -exec rm {} \;
find . -name "*.elf" -exec rm {} \;
rm src/gfx/raw/* -rf
}

cleanAll

echo "### Compilation"
make gfx
make

#cd src/soundApi/luts
#gcc -o generator gen.c -lm
#./generator > /dev/null
#cd -

echo "### Padbin pour execution du GBFS"
wine padbin.exe 256 FAT_v$VERSION.gba

cp FAT_v$VERSION.gba FAT_default.gba

echo "### Generation du SAMPLE filesystem"
rm -f *.gbfs kits/*.gbfs
#objcopy -v -I binary -O elf32-little --rename-section .data=.rodata in_file out_file
wine gbfs.exe kits/infos.gbfs samples/0nbkit > /dev/null

# Packaging des samples déjà inclus.
wine gbfs.exe kits/devmess.gbfs samples/dev-mess/0infos samples/dev-mess/*.snd > /dev/null
wine gbfs.exe kits/littlescale-md.gbfs samples/littlescale-md/0infos samples/littlescale-md/*.snd > /dev/null
wine gbfs.exe kits/c64-drums.gbfs samples/c64-drums/0infos samples/c64-drums/*.snd > /dev/null
wine gbfs.exe kits/ym-drums.gbfs samples/ym-drums/0infos samples/ym-drums/*.snd > /dev/null
wine gbfs.exe kits/battery.gbfs samples/battery/0infos samples/battery/*.snd > /dev/null
wine gbfs.exe kits/rhythms.gbfs samples/rhythm/0infos samples/rhythm/*.snd > /dev/null
wine gbfs.exe kits/tr606.gbfs samples/tr-606-7/0infos samples/tr-606-7/*.snd > /dev/null


echo "### Patch du GBA pour inclusion des samples"
cat FAT_v$VERSION.gba kits/infos.gbfs kits/devmess.gbfs kits/littlescale-md.gbfs kits/c64-drums.gbfs kits/ym-drums.gbfs kits/battery.gbfs kits/rhythms.gbfs kits/tr606.gbfs > TMP.gba
mv TMP.gba FAT_v$VERSION.gba

echo "### Copie dans les daily_builds"
cp FAT_v$VERSION.gba daily_builds/FuriousAdvanceTracker_v$VERSION-`date '+%d-%B-%Y'`.gba

echo "### Lancement de l'émulateur"
vba  FAT_v$VERSION.gba

cleanAll
