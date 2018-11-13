#################################
# HAM Makefile
#################################

include $(HAMDIR)/system/master.mak
CFLAGS   += -Werror

# FOR DEBUGGING
#CFLAGS   += -DHEL_DEBUG
#CFLAGS   += -DHEL_DEBUG_CALLSTACKTRACE
#ADD_LIBS += $(GCCARM)/lib/libhel2_dcs.a
###

ADD_LIBS += $(GCCARM)/lib/libhel2.a

#
# Set the name of your desired GBA image name here
#
PROGNAME = FAT_v1.4.0

#
# Set a list of files you want to compile
# Please let the libgbfs.o at last position. IMPORTANT !
#
OFILES += src/main.o \
	src/system/system.o src/system/data/data.o src/system/filesystem.o src/system/player.o \
 	src/sprites/cursors.o src/sprites/player_cursors.o \
 	src/screens/project.o src/screens/filesystem.o \
	src/screens/blocks.o src/screens/composer.o src/screens/effects.o \
	src/screens/help.o src/screens/instrument.o src/screens/live.o \
	src/screens/song.o src/screens/notes.o src/screens/weditor.o \
	src/screens/cursors/blocks_cursor.o src/screens/cursors/composer_cursor.o  \
	src/screens/cursors/filesystem_cursor.o src/screens/cursors/instrument_cursor.o \
	src/screens/cursors/live_cursor.o src/screens/cursors/notes_cursor.o \
	src/screens/cursors/project_cursor.o src/screens/cursors/song_cursor.o \
	src/screens/cursors/weditor_cursor.o \
	src/dialogs/keyboard.o src/dialogs/yesno.o src/dialogs/popup.o \
	src/gfx/ResourceData.o \
	src/soundApi/soundApi.o src/soundApi/oscillator/oscillator.o \
	src/soundApi/kits/libgbfs.o

######################################
# Standard Makefile targets start here
######################################

all :	$(PROGNAME).$(EXT) clean

#
# Most Makefile targets are predefined for you, suchas
# vba, clean ... in the following file
#
include $(HAMDIR)/system/standard-targets.mak

######################################
# custom  Makefile targets start here
######################################
.PHONY gfx: makefile
	mkdir -p src/gfx/raw/app src/gfx/raw/intro
	wine $(HAMDIR)/tools/win32/gfx2gba.exe -t8 -m -fraw -osrc/gfx/raw/intro -pintro.pal src/gfx/img/screens/intro.bmp
	wine $(HAMDIR)/tools/win32/gfx2gba.exe -t8 -m -fraw -osrc/gfx/raw/app -pscreen.pal src/gfx/img/screens/screen*.bmp src/gfx/img/text.bmp
	wine $(HAMDIR)/tools/win32/gfx2gba.exe -t8 -D -c16 -fraw -osrc/gfx/raw/app -psprites.pal src/gfx/img/sprites/*.bmp
	wine $(HAMDIR)/tools/win32/katie.exe --output-asm-arm --output-h --output-h-filename src/gfx/ResourceData.h --output-asm-arm-filename src/gfx/ResourceData.s src/gfx/raw/intro/*.* src/gfx/raw/app/*.*

clear: makefile
	find . -name "*.o" -exec rm {} \;
	find . -name "*.i" -exec rm {} \;
	find . -name "*.s" -exec rm {} \;
	find . -name "*.gba" -exec rm {} \;
	find . -name "*.elf" -exec rm {} \;
	rm src/gfx/raw/* -rf

release: clear gfx all
	wine padbin.exe 256 $(PROGNAME).$(EXT)
	rm -f *.gbfs kits/*.gbfsrm -f *.gbfs kits/*.gbfs
	wine gbfs.exe kits/infos.gbfs samples/0nbkit > /dev/null
	wine gbfs.exe kits/infosNoKits.gbfs samples/0nbkitNoKits > /dev/null
	wine gbfs.exe kits/devmess.gbfs samples/dev-mess/0infos samples/dev-mess/*.snd > /dev/null
	wine gbfs.exe kits/littlescale-md.gbfs samples/littlescale-md/0infos samples/littlescale-md/*.snd > /dev/null
	wine gbfs.exe kits/c64-drums.gbfs samples/c64-drums/0infos samples/c64-drums/*.snd > /dev/null
	wine gbfs.exe kits/ym-drums.gbfs samples/ym-drums/0infos samples/ym-drums/*.snd > /dev/null
	wine gbfs.exe kits/battery.gbfs samples/battery/0infos samples/battery/*.snd > /dev/null
	wine gbfs.exe kits/rhythms.gbfs samples/rhythm/0infos samples/rhythm/*.snd > /dev/null
	wine gbfs.exe kits/tr606.gbfs samples/tr-606-7/0infos samples/tr-606-7/*.snd > /dev/null
	cp $(PROGNAME).$(EXT) $(PROGNAME)_buildable.$(EXT)
	cat $(PROGNAME).$(EXT) kits/infosNoKits.gbfs > $(PROGNAME)_default.$(EXT)
	cat $(PROGNAME).$(EXT) kits/infos.gbfs kits/devmess.gbfs kits/littlescale-md.gbfs kits/c64-drums.gbfs kits/ym-drums.gbfs kits/battery.gbfs kits/rhythms.gbfs kits/tr606.gbfs > TMP.gba
	mv TMP.gba $(PROGNAME).$(EXT)
	./gbafix $(PROGNAME).$(EXT) -tFAT
	mkdir -p daily_builds
	cp $(PROGNAME).$(EXT) daily_builds/$(PROGNAME)-`date '+%d-%B-%Y'`.$(EXT)
	find . -name "*.o" -exec rm {} \;
	find . -name "*.i" -exec rm {} \;
	find . -name "*.s" -exec rm {} \;
	find . -name "*.elf" -exec rm {} \;
	rm src/gfx/raw/* -rf
	echo "`tput setaf 2`FAT had been successfully built.`tput sgr 0`"
	echo "`tput setaf 2`Run it with vba $(PROGNAME).$(EXT)`tput sgr 0`"

run: release
	vba $(PROGNAME).$(EXT)

test: release
	chmod +x test/*.sh
	test/01firstTest.sh $(PROGNAME).$(EXT)
	test/02chordeffect.sh $(PROGNAME).$(EXT)

manual: makefile
	manual/buildPDF.sh

doxygen: manual
		doxygen Doxyfile
