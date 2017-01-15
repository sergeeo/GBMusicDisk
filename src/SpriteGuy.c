#pragma bank=2
#include "SpriteGuy.h"
#include "SpriteManager.h"
UINT8 bank_SPRITE_GUY = 2;

const UINT8 anim_walk[]= {2, 0, 1};

void Start_SPRITE_GUY(){
		SetSpriteAnim(THIS, anim_walk, 15);
}

void Update_SPRITE_GUY(){

}

void Destroy_SPRITE_GUY(){}