#pragma once
#include "Utilies.h"
#include "Colors.h"
#include "Graphics.h"
#include "Graphics2.h"
#include "Font.h"

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
	SimplePortal(char* Name, int x1, int y1, int x2, int y2,Color bColor,Color tColor);
	void DrawBorder(Graphics & gfx);
	bool DrawPixel(Graphics& gfx, Vec2 loc, Color c);
	bool DrawLine( Graphics& gfx,Vec2 loc1, Vec2 loc2, Color c);
	bool MovePortal(Vec2 mov);

	int WidthIn;
	int HeightIn;
	
private:
	char* name;
	Font font;
	int X1;
	int Y1;
	int X2;
	int Y2;
	int Left;
	int Right;
	int Top;
	int Bot; //bottom
	Color BorderColor;
	Color TitleColor;

};