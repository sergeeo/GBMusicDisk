#pragma bank=2
#include "StateGame.h"
UINT8 bank_STATE_GAME = 2;

#include "..\res\src\gametiles.h"
#include "..\res\src\gamemap.h"
#include "..\res\src\font.h"

#include "ZGBMain.h"
#include "Print.h"
#include "Scroll.h"
#include "SpriteManager.h"

#define VUMETER_POSITION1 24
#define VUMETER_POSITION2 56
#define VUMETER_POSITION3 88
#define VUMETER_POSITION4 120

extern UINT8 n_sprite_types;

void PrintTitles() {
	PRINT_POS(4, 3);
	Printf("CHICHARRONES");
	
	PRINT_POS(4, 6);
	Printf("ESPETITOS");
	
	PRINT_POS(4, 9);
	Printf("MORTADELA");
	
	PRINT_POS(4, 12);
	Printf("HAMBURGUELA");
}

void Start_STATE_GAME() {
	
	UINT8 i;

// load of sprites

	SPRITES_8x16;
	for(i = 0; i != n_sprite_types; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;
	SpriteManagerAdd(SPRITE_VUMETER, VUMETER_POSITION1, 110);
	SpriteManagerAdd(SPRITE_VUMETER, VUMETER_POSITION2, 110);
	SpriteManagerAdd(SPRITE_VUMETER, VUMETER_POSITION3, 110);
	SpriteManagerAdd(SPRITE_VUMETER, VUMETER_POSITION4, 110);
	scroll_target = SpriteManagerAdd(SPRITE_PLAYER, 50, 50);

	InitScrollTiles(0, 2, gametiles, 5);
	InitScroll(gamemapWidth, gamemapHeight, gamemap, 0, 0, 5);
	SHOW_BKG;
	
// print song titles
	INIT_FONT(font, 3, PRINT_BKG);
	PrintTitles();
}

void Update_STATE_GAME() {
	
	
}