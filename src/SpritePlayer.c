#pragma bank=2
#include "SpritePlayer.h"
UINT8 bank_SPRITE_PLAYER = 2;

#include "SpriteManager.h"
#include "Keys.h"

#define SPRITE_X 12
#define SPRITE_YMIN 28
#define SPRITE_Y2 52
#define SPRITE_Y3 76
#define SPRITE_YMAX 100
#define MAXPOSITIONS 4

UINT8 cursor_positions[MAXPOSITIONS] = {SPRITE_YMIN, SPRITE_Y2, SPRITE_Y3, SPRITE_YMAX};
UINT8 ycounter = 0;

// Para agregar nuevas animaciones hay que decir en InitSprites (ZGBMAIN) cuantos frames ha de cargar
const UINT8 anim_one[] = {24, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 0, 0, 0, 0};
const UINT8 anim_two[] = {10, 4, 5, 4, 5, 4 , 5, 6, 7, 8, 5};
const UINT8 anim_three[] = {7, 9, 10, 11, 12, 13, 14, 15};
const UINT8 anim_four[] = {11, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

extern const unsigned char* tune1_mod_Data[];
extern const unsigned char* tune2_mod_Data[];
extern const unsigned char* tune3_mod_Data[];
extern const unsigned char* tune4_mod_Data[];

void ChangeMusic(){
	switch(THIS->y) {
	case SPRITE_YMIN:PlayMusic(tune1_mod_Data, 4, 1); break;
	case SPRITE_Y2:PlayMusic(tune2_mod_Data, 4, 1); break;
	case SPRITE_Y3:PlayMusic(tune3_mod_Data, 4, 1); break;
	case SPRITE_YMAX:PlayMusic(tune4_mod_Data, 4, 1); break;
	}
}

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
	if(KEY_TICKED(J_A) || KEY_TICKED(J_B)) {
		ChangeMusic();
	}
	
	// evitar pernambuco en el array
	if(ycounter<MAXPOSITIONS)
	{
		THIS->y = cursor_positions[ycounter];
	}
	
	if(THIS->y == SPRITE_YMIN) {
		THIS->anim_speed = 4u;
		SetSpriteAnim(THIS, anim_one, 15);
	}
	if(THIS->y == SPRITE_Y2) {
		THIS->anim_speed = 8u;
		SetSpriteAnim(THIS, anim_two, 15);
	}
	if(THIS->y == SPRITE_Y3) {
		THIS->anim_speed = 8u;
		SetSpriteAnim(THIS, anim_three, 15);		
	}
		if(THIS->y == SPRITE_YMAX) {
		THIS->anim_speed = 6u;
		SetSpriteAnim(THIS, anim_four, 15);
	}

}

void Destroy_SPRITE_PLAYER() {
}