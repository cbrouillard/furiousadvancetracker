#################################
# HAM Makefile
#################################

#HAMDIR = /home/cyril/Coding/GBA/devkit/ham-271-linux-full
include $(HAMDIR)/system/master.mak

ADD_LIBS += $(GCCARM)/lib/libhel2_d.a

#
# Set the name of your desired GBA image name here
#
PROGNAME = FAT_v1.0.0

#
# Set a list of files you want to compile 
# Please let the libgbfs.o at last position. IMPORTANT !
# 
OFILES += main.o src/gfx/ResourceData.o src/soundApi/soundApi.o src/soundApi/libgbfs.o

######################################
# Standard Makefile targets start here
######################################

all : $(PROGNAME).$(EXT) clean

#
# Most Makefile targets are predefined for you, suchas
# vba, clean ... in the following file
#
include $(HAMDIR)/system/standard-targets.mak

######################################
# custom  Makefile targets start here
######################################
.PHONY gfx: makefile
	$(HAMDIR)/tools/linux/gfx2gba -c16 -t8 -m -fraw -b15 -osrc/gfx/raw -ptext.pal src/gfx/img/text.bmp
	$(HAMDIR)/tools/linux/gfx2gba -t8 -m -fraw -b15 -osrc/gfx/raw -pintro.pal src/gfx/img/screens/intro*.bmp
	$(HAMDIR)/tools/linux/gfx2gba -t8 -m -fraw -b15 -osrc/gfx/raw -pscreen.pal src/gfx/img/screens/screen_*.bmp
	wine $(HAMDIR)/tools/win32/katie.exe --output-asm-arm --output-h --output-h-filename src/gfx/ResourceData.h --output-asm-arm-filename src/gfx/ResourceData.s src/gfx/raw/*.*
	



