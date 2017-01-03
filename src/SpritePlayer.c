#pragma bank=2
#include "SpritePlayer.h"
UINT8 bank_SPRITE_PLAYER = 2;

#include "SpriteManager.h"
#include "Keys.h"

#define SPRITE_X 30
#define SPRITE_YMIN 24
#define SPRITE_YMAX 96
#define MAXPOSITIONS 4

UINT8 cursor_positions[MAXPOSITIONS] = {SPRITE_YMIN, 50, 72, SPRITE_YMAX};
UINT8 ycounter = 0;

const UINT8 anim_idle[] = {8, 0, 1, 2, 1, 0, 3, 4, 3};


void Start_SPRITE_PLAYER() {
	THIS->x=SPRITE_X;
	THIS->y=SPRITE_YMIN;
}

void Update_SPRITE_PLAYER() {
	if(KEY_TICKED(J_DOWN) && THIS->y != SPRITE_YMAX) {
		ycounter++;
	}
	if(KEY_TICKED(J_UP) && THIS->y != SPRITE_YMIN) {
		ycounter--;
	}
	
	// evitar pernambuco en el array
	if(ycounter<MAXPOSITIONS)
	{
		THIS->y = cursor_positions[ycounter];
	}
	if(keys == 0) {
		SetSpriteAnim(THIS, anim_idle, 15);
	}
}

void Destroy_SPRITE_PLAYER() {
}