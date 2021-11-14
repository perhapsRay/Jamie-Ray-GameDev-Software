#pragma once

extern const int MAXLEVELWIDTH;
extern const int MAXLEVELHEIGHT;
extern const int BUFFSIZE;
extern char currentMap[20][100];
extern unsigned int newPlayerPositionX;
extern unsigned int newPlayerPositionY;

bool handleCollisions(int y, int x);
void gotoScreenPosition(short C, short R);