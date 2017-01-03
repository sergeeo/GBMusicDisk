#include <gb/gb.h>

void InitGBSPlayer(); //in gbs 
void UpdateGBS(); //in gbs  
int Load_BKG(); //in c

void main() {
	SWITCH_ROM_MBC1(2);
	Load_BKG();
	InitGBSPlayer();
    while (1) {
		SCX_REG++;
		UpdateGBS();
		wait_vbl_done();
	}	
}