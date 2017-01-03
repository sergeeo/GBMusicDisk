#pragma bank=2
#include "StateMenu.h"
UINT8 bank_STATE_MENU = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\start.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

/* extern const unsigned char* exo_start_mod_Data[]; */

void Start_STATE_MENU() {
	InitScrollTiles(0, 2, tiles, 3);
	InitScroll(startWidth, startHeight, start, 0, 0, 3);
	SHOW_BKG;
	
	/* PlayMusic(exo_start_mod_Data, 4, 0); */
}

void Update_STATE_MENU() {
		if(KEY_TICKED(J_START)) {
			SetState(STATE_GAME);
	}
}