#pragma once
#include "Utilies.h"
#include "Colors.h"
#include "Graphics.h"

class tPortals {
public:
	int OutSizeX;
	int OutSizeY;
	int InSizeX;
	int InSizeY;
	Vec2 TLcorner;
	Vec2 TRcorner;
	Vec2 BLcorner;
	Vec2 BRcorner;
	Color bgColor;
	Color fgColor;
	Color bdColor;

	


private:

};

class SimplePortal {
public:
	SimplePortal(Graphics gfx,  int x1, int y1, int x2, int y2,Color bColor);


private:
	int X1;
	int Y1;
	int X2;
	int Y2;
	int WidthIn;
	int HeightIn;
	int Left;
	int Right;
	int Top;
	int Bot; //bottom
	Color BorderColor;

};