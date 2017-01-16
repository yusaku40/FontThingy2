#include "Portals.h"
#include <new>



SimplePortal::SimplePortal(char* Name, int x1, int y1, int x2, int y2, Color bColor,Color tColor)
{
	size_t len = strlen(Name);
	name = new char[len + 1];
	strcpy_s((char*)name,len + 1,Name);
	
	X1 = x1; Y1 = y1; X2 = x2; Y2 = y2; //copy in location
	this->BorderColor = bColor; //remove if uneccessary
	this->TitleColor = tColor; 
	
	///calculate internal size
	WidthIn = X2 - X1 - 4; ///subtract border width
	HeightIn = Y2 - Y1 - 4;

	///Set internal limits/offsets
	Left = X1 + 2;
	Right = X2 - 2;
	Top = Y1 + 22;
	Bot = Y2 - 2;

	

}
void SimplePortal::DrawBorder(Graphics& gfx) {
	///draw border
	gfx.DrawFRect(X1, Y1, X2 - X1 + 2, 20, BorderColor);//draw title bar
	DrawFatRect(gfx, X1, Y1+20, X2, Y2, BorderColor); ///draw window border in color bColor
	int tCenter = X1 + ((X2 - X1) / 2)- (strlen(name) / 2) * 10;
	font.PrintS(gfx, name, tCenter, Y1 + 12, TitleColor);
}

bool SimplePortal::DrawPixel(Graphics & gfx, Vec2 loc, Color c)
{
	Vec2 modLoc = { loc.x + Left,loc.y + Top }; // adapt location to current portal

	if (modLoc.x<Left || modLoc.x>Right || modLoc.y<Top || modLoc.y>Bot) return false;
	
	gfx.PutPixel(modLoc.x , modLoc.y , c);

	return true;
}

bool SimplePortal::DrawLine( Graphics& gfx,Vec2 loc1,Vec2 loc2 , Color c)
{
		int dX = loc2.x - loc1.x;
		int dY = loc2.y - loc1.y;
		if (dX == 0 && dY == 0) {
			DrawPixel(gfx,loc1, c);
		}
		else if (abs(dY) > abs(dX))
		{
			if (dY < 0)
			{
				int temp = loc1.x;
				loc1.x = loc2.x;
				loc2.x = temp;
				temp = loc1.y;
				loc1.y = loc2.y;
				loc2.y = temp;
			}
			float m = (float)dX / (float)dY;
			float b = loc1.x - (m *loc1.y);
			for (int y = loc1.y; y <= loc2.y; y = y + 1)
			{
				int x = (int)(m*y + b + 0.5f);
				DrawPixel(gfx, { x,y }, c);
			}
		}
		else
		{
			if (dX < 0)
			{
				int temp = loc1.x;
				loc1.x = loc2.x;
				loc2.x = temp;
				temp = loc1.y;
				loc1.y = loc2.y;
				loc2.y = temp;
			}
			float m = (float)dY / (float)dX;
			float b = loc1.y - m * loc1.x;
			for (int x = loc1.x; x <= loc2.x; x = x + 1)
			{
				int y = (int)(m*x + b + 0.5f);
				DrawPixel(gfx, { x,y }, c);
			}
		}
	

	return true;
}

bool SimplePortal::MovePortal(Vec2 mov)
{
	X1 = X1 + mov.x;
	X2 = X2 + mov.x;
	Y1 = Y1 + mov.y;
	Y2 = Y2 + mov.y;
	Left = Left + mov.x;
	Right = Right + mov.x;
	Top = Top + mov.y;
	Bot = Bot + mov.y;

	return true;
}
