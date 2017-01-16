#pragma bank=2
#include "SpriteGuy.h"
#include "SpriteManager.h"
UINT8 bank_SPRITE_GUY = 2;

const UINT8 anim_walk[]= {5, 0, 1, 2, 3, 4};

void Start_SPRITE_GUY(){
		SetSpriteAnim(THIS, anim_walk, 15);
}

void Update_SPRITE_GUY(){
	if(THIS->x < 160) {
		THIS->x = THIS->x + 1;
	}

}

void Destroy_SPRITE_GUY(){}