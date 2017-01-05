#pragma bank=2
#include "StateMenu.h"
UINT8 bank_STATE_MENU = 2;

#include "..\res\src\menutiles.h"
#include "..\res\src\menumap.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

/* extern const unsigned char* exo_start_mod_Data[]; */

void Start_STATE_MENU() {
	InitScrollTiles(0, 2, menutiles, 3);
	InitScroll(menumapWidth, menumapHeight, menumap, 0, 0, 3);
	SHOW_BKG;
	
	/* PlayMusic(exo_start_mod_Data, 4, 0); */
}

void Update_STATE_MENU() {
		if(KEY_TICKED(J_START)) {
			SetState(STATE_GAME);
	}
}