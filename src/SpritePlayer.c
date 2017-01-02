#pragma bank=2
#include "SpritePlayer.h"
UINT8 bank_SPRITE_PLAYER = 2;

#include "SpriteManager.h"
#include "Keys.h"

#define SPRITE_X 30
#define SPRITE_YMIN 20
#define SPRITE_YMAX 110
#define MAXPOSITIONS 4

UINT8 cursor_positions[MAXPOSITIONS] = {SPRITE_YMIN, 50, 80, SPRITE_YMAX};
UINT8 ycounter = 0;

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
}

void Destroy_SPRITE_PLAYER() {
}