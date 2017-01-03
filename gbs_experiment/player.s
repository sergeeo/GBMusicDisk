.area _Functions (ABS)
	.org	0x10000
	
        .include "global.s"		 ;import definitions
        .globl 	_scroll	
        .globl  _InitGBSPlayer   
        .globl  _UpdateGBS 
	
_scroll:    ;test function, it works in C
	LDH     a, (.SCX)
	inc     a
	LDH     (.SCX), a
	ret     

_InitGBSPlayer:
    jp    0x5ec     ; Initialize 

_UpdateGBS:
    jp    0x544     ; Update
	
.area _Music (ABS)
	.org	0x500
	.include "music.s"