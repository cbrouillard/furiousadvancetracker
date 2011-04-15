/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
*/
#include <mygba.h>

#include "soundApi/soundApi.h"
#include "fat.h"

int main() {

    FAT_init ();
    snd_init_soundApi();
    
    FAT_showIntro ();
    
    FAT_screenSong_init ();
       
    while(1) {}
    return 0;
}


