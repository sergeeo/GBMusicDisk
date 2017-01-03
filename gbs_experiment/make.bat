lcc -Wa-l -c -o main.o main.c
lcc -Wa-l -c -o player.o player.s
lcc -Wa-l -Wf-bo2 -c -o bkg.o bkg.c
lcc -Wl-yt1 -Wl-yo4 -Wl-yp0x143=0xc0 -o Player.gb main.o player.o bkg.o

del *.lst
del *.map
del *.o

pause