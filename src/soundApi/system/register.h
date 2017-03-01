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

/**
 * \file register.h
 * \brief Définit un certain nombres d'addresses hexadécimales en vu d'accéder à certains registres et espaces mémoires.
 */
#ifndef _SOUND_API_REGISTER_
#define _SOUND_API_REGISTER_

#define	REG_BASE	0x04000000

// Registres globaux
#define	REG_SOUNDCNT_L	(*((u16 volatile *) (REG_BASE + 0x080)))
#define	REG_SOUNDCNT_H	(*((u16 volatile *) (REG_BASE + 0x082)))
#define	REG_SOUNDCNT_X	(*((u16 volatile *) (REG_BASE + 0x084)))

#define SOUNDINIT			0x8000

// Channel 1
#define	REG_SOUND1CNT_L	(*((u16 volatile *) (REG_BASE + 0x060)))
#define	REG_SOUND1CNT_H	(*((u16 volatile *) (REG_BASE + 0x062)))
#define	REG_SOUND1CNT_X	(*((u16 volatile *) (REG_BASE + 0x064)))

#define SOUND1INIT			0x8000

// Channel 2
#define	REG_SOUND2CNT_L	(*((u16 volatile *) (REG_BASE + 0x068)))
#define	REG_SOUND2CNT_H	(*((u16 volatile *) (REG_BASE + 0x06C)))

#define SOUND2INIT			0x8000

// Channel 3
#define	REG_SOUND3CNT_L	(*((u16 volatile *) (REG_BASE + 0x070)))
#define	REG_SOUND3CNT_H	(*((u16 volatile *) (REG_BASE + 0x072)))
#define	REG_SOUND3CNT_X	(*((u16 volatile *) (REG_BASE + 0x074)))

#define SOUND3INIT			0x8000
#define SOUND3PLAYONCE		0x4000	// Play sound once
#define SOUND3PLAYLOOP		0x0000	// Play sound looped

#define SOUND3OUTPUT0		0x0000	// Mute output
#define SOUND3OUTPUT1		0x2000	// Output unmodified
#define SOUND3OUTPUT12		0x4000	// Output 1/2 
#define SOUND3OUTPUT14		0x6000	// Output 1/4 
#define SOUND3OUTPUT34		0x8000  // Output 3/4
#define SOUND3PLAY			0x0080	// Output sound

// Channel 4
#define	REG_SOUND4CNT_L	(*((u16 volatile *) (REG_BASE + 0x078)))
#define	REG_SOUND4CNT_H	(*((u16 volatile *) (REG_BASE + 0x07C)))

#define REG_WAVE_RAM0  *(u32 volatile*)0x4000090
#define SOUND3SETBANK0		0x0000
#define SOUND3SETBANK1		0x0040

#define SOUND3BANK32		0x0000	
#define SOUND3BANK64		0x0020	

#define SOUND4INIT			0x8000

// DMA (mémoire)
#define REG_DMA3SAD     (*((u32 volatile *) (REG_BASE + 0x0D4)))
#define REG_DMA3DAD     (*((u32 volatile *) (REG_BASE + 0x0D8)))
#define REG_DMA3CNT_L   (*((u16 volatile *) (REG_BASE + 0x0DC)))
#define REG_DMA3CNT_H   (*((u16 volatile *) (REG_BASE + 0x0DE)))

#define ECRAN           (*((u16 volatile *) (0x6000000)));

#define SND_REG_TM0CNT      *(u32*)0x4000100	//Timer 0
#define SND_REG_TM0CNT_L	*(u16*)0x4000100	//Timer 0 count value
#define SND_REG_TM0CNT_H    *(u16*)0x4000102	//Timer 0 Control
#define SND_REG_SGFIFOA    *(vu32*)0x40000A0

#define SND_REG_TM1CNT     *(u32*)0x4000104		//Timer 2
#define SND_REG_TM1CNT_L   *(u16*)0x4000104		//Timer 2 count value
#define SND_REG_TM1CNT_H   *(u16*)0x4000106		//Timer 2 control
#define SND_REG_SGFIFOB    *(vu32*)0x40000A4

#endif
