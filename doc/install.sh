#!/bin/bash

cd /tmp
echo "Downloading"
curl -O http://brouillard.me/shared/howto_FAT_install.zip

unzip howto_FAT_install.zip
cd howto_FAT_install/

echo "Installing SDK"
mkdir ~/GBA
cp -R ham libhel ~/GBA/
cp libstdc++-libc6.1-1.so.2 ~/GBA/

echo "Configuring SDK"
cd ~/GBA/ham
chmod +x tools/d2u-u2d tools/linux/elf_align tools/linux/gfx2gba tools/linux/interflip tools/linux/mb tools/linux/vba tools/linux/wav2gba
chmod +x system/lnkscript*
chmod +x gcc-arm/bin/*
chmod +x gcc-arm/arm-thumb-elf/bin/*

echo "Configuring home"
echo "export HAMDIR=\"~/GBA/ham\"" >> ~/.bashrc
source ~/.bashrc

echo "Export library (sudo ldconfig)"
sudo mv ~/GBA/libstdc++-libc6.1-1.so.2 /usr/lib/
sudo ldconfig

echo "Cloning source code"
git clone https://github.com/cbrouillard/furiousadvancetracker.git

echo "Done !"
echo "You now have to install VisualBoyAdvance, wine and make tools then :"
echo "cd ~/GBA/furiousadvancetracker"
echo "make run"
