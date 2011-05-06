#!/bin/sh
make clean
rm *.elf *.gba *.s
make
gvba FuriousAdvanceTracker_v0-02.gba
