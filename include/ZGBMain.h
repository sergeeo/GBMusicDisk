#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#include "main.h"

typedef enum {
	STATE_GAME,
	STATE_MENU,

	N_STATES
} STATE;

typedef enum {
	SPRITE_PLAYER,
	SPRITE_VUMETER,
	SPRITE_GUY,

	N_SPRITE_TYPES
} SPRITE_TYPE;

#endif