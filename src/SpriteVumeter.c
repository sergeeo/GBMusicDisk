#pragma bank=2
#include "SpriteVumeter.h"
UINT8 bank_SPRITE_VUMETER = 2;

#include "SpriteManager.h"

/* #define HI_VOL 3
#define MED_VOL 2
#define LOW_VOL 1 */

#define VUMETER_POSITION1 24
#define VUMETER_POSITION2 56
#define VUMETER_POSITION3 88
#define VUMETER_POSITION4 120

// Para agregar nuevas animaciones hay que decir en InitSprites (ZGBMAIN) cuantos frames ha de cargar
const UINT8 meteractive[] = {4, 3, 2, 1, 0};
const UINT8 meterzero[] = {1, 0};

UINT8 current_volume = 0;

void Start_SPRITE_VUMETER() {
	THIS->anim_speed =40u;
}

void Update_SPRITE_VUMETER() {
	
	if (THIS->x==VUMETER_POSITION1){
	current_volume=((NR12_REG>>5) & 0x3);
	}
	if (THIS->x==VUMETER_POSITION2){
	current_volume=((NR22_REG>>5) & 0x3);
	}
	if (THIS->x==VUMETER_POSITION3){
	current_volume=((NR32_REG>>5) & 0x3);
	}
	if (THIS->x==VUMETER_POSITION4){
	current_volume=((NR42_REG>>5) & 0x3);
	}
	
	if (current_volume>=1) {
		SetSpriteAnim(THIS, meteractive, 15);	
	}
	if (current_volume==0) {
		SetSpriteAnim(THIS, meterzero, 15);	
	}
}

void Destroy_SPRITE_VUMETER() {
}