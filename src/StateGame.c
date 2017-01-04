#pragma bank=2
#include "StateGame.h"
UINT8 bank_STATE_GAME = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\map.h"
#include "..\res\src\font.h"

#include "ZGBMain.h"
#include "Print.h"
#include "Scroll.h"
#include "SpriteManager.h"

extern UINT8 n_sprite_types;

void PrintTitles() {
	PRINT_POS(4, 4);
	Printf("CHICHARRONES");
	
	PRINT_POS(4, 7);
	Printf("ESPETITOS");
	
	PRINT_POS(4, 10);
	Printf("MORTADELA");
	
	PRINT_POS(4, 13);
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

	scroll_target = SpriteManagerAdd(SPRITE_PLAYER, 50, 50);

	InitScrollTiles(0, 2, tiles, 3);
	InitScroll(mapWidth, mapHeight, map, 0, 0, 3);
	SHOW_BKG;
	
// print song titles
	INIT_FONT(font, 3, PRINT_BKG);
	PrintTitles();
}

void Update_STATE_GAME() {
	
	
}