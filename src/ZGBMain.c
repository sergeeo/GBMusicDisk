#include "ZGBMain.h"

#include "StateMenu.h"
#include "StateGame.h"

#include "SpritePlayer.h"
#include "SpriteVumeter.h"
#include "SpriteGuy.h"

#include "../res/src/player.h"
#include "../res/src/guy.h"
#include "../res/src/vumeter.h"

#define VUMETER_POSITION1 24
#define VUMETER_POSITION2 56
#define VUMETER_POSITION3 88
#define VUMETER_POSITION4 120

UINT8 next_state = STATE_MENU;

SET_N_STATES(N_STATES);
SET_N_SPRITE_TYPES(N_SPRITE_TYPES);

void InitStates() {
	INIT_STATE(STATE_MENU);
	INIT_STATE(STATE_GAME);
}

void InitSprites() {
	INIT_SPRITE(SPRITE_PLAYER, player, 5, FRAME_16x16, 27);
	INIT_SPRITE(SPRITE_VUMETER, vumeter, 5, FRAME_16x16, 4);
	INIT_SPRITE(SPRITE_GUY, guy, 3, FRAME_16x16, 5);
}

#include "Math.h"
UINT8 GetTileReplacement(UINT8* tile_ptr, UINT8* tile) {
	if(current_state == STATE_GAME) {
		if(U_LESS_THAN(255 - (UINT16)*tile_ptr, N_SPRITE_TYPES)) {
			*tile = 0;
			return 255 - (UINT16)*tile_ptr;
		}

		*tile = *tile_ptr;
	}

	return 255u;
}