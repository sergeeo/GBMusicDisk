/* #pragma bank=2
#include "SpriteVumeter.h"
UINT8 bank_SPRITE_VUMETER = 2;

#include "SpriteManager.h"

#define SPRITE_X 12
#define SPRITE_Y 12
#define HI_VOL 13
#define MED_VOL 7
#define LOW_VOL 3

// Para agregar nuevas animaciones hay que decir en InitSprites (ZGBMAIN) cuantos frames ha de cargar
const UINT8 vol_low[] = {1, 0};
const UINT8 vol_lmed[] = {1, 1};
const UINT8 vol_med[] = {1, 2};
const UINT8 vol_high[] = {1, 3};

UINT8 current_volume = 0;

void Start_SPRITE_VUMETER() {
	THIS->x=SPRITE_X;
	THIS->y=SPRITE_Y;
}

void Update_SPRITE_VUMETER() {
	
	current_volume=((NR12_REG>>5) & 0x3);
	
	if (current_volume>=HI_VOL) {
		SetSpriteAnim(THIS, vol_high, 15);	
	}
	if (current_volume>=MED_VOL) {
		SetSpriteAnim(THIS, vol_med, 15);	
	}
	if (current_volume>=LOW_VOL) {
		SetSpriteAnim(THIS, vol_lmed, 15);	
	}
	if (current_volume<LOW_VOL) {
		SetSpriteAnim(THIS, vol_low, 15);	
	}
}

void Destroy_SPRITE_VUMETER() {
} */