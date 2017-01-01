#pragma once

#include "Graphics.h"
#include "Utilies.h"



class Line {
public:
	Line();
	Line(Vec2 a, Vec2 b);
	Vec2 vtx1, vtx2;
};

class Glyph2 {
public:
	Glyph2(int lcount);
	int linecount;
	Line lines[20];


};

class GlyphVector {
public:
	GlyphVector(int lcount);
	int linecount;
	Vec2 points[10];

};

class Font {
public:				//public methods
	Font();
	
	bool PrintGlyph(Graphics& gRef, int glyph,int startX,int startY,Color color);
	void PrintS(Graphics& gfx, const char* text, int X, int Y, Color color);
	void PrintS(Graphics & gfx, tRect & trect,  Color color); //overload for text Rectangle testing

	void PrintRect(Graphics & gfx, tRect& tr,Color c);

private:			//private vars
	

public:				//public vars
	


};

