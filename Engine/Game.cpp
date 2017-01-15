/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Utilies.h"
#include "Font.h"
#include <iostream>
#include <math.h>
#include "Sprite.h"
#include "Misc.h"
#include "Graphics2.h"


///Globalsish////
Sprite sprite;
Font font;
char buffer[50];
char b2[10];
int bCount = 0;
char cTemp;
tRect txtRect({ 1,619 },1270 ,100);
bool msgPrinted = false;

Color test;
Color RainBorder(180, 0, 210);

////PixelEdit TempGlobals
const int pixWsize = 32;
const int pixHsize = 32;
//unsigned int pixels[pixWsize][pixHsize];
Color pixels[pixWsize][pixHsize];
static bool f5Pressed = false;



Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
}





void KeyInTemp(MainWindow& wnd, Graphics& gfx) {
	Color c(150, 150, 150);

	if (bCount < 49) {
		cTemp = wnd.kbd.ReadChar();

		if (cTemp != 0) {
			if (cTemp == 8) {
				if (txtRect.vText.size()>0) {
					txtRect.vText.pop_back();
				}
			}
			else {
				txtRect.vText.push_back(cTemp);
				bCount++;
			}

		}
	}
	else {
		bCount = 0;

	}
	font.PrintRect(gfx, txtRect, c);

	_itoa_s(txtRect.vText.size(), b2, 10);
	font.PrintS(gfx, b2, 500, 400, c);
	if (wnd.mouse.LeftIsPressed() && !msgPrinted) {
		txtRect.Push(" L Mouse button is pressed ");
		txtRect.PushC(13);
		msgPrinted = true;
	}
	if (!wnd.mouse.LeftIsPressed()) {
		msgPrinted = false;
	}
	///temp placement????
	if (!f5Pressed) {
		if (wnd.kbd.KeyIsPressed(VK_F5)) {
			f5Pressed = true;
			for (int y = 0; y < pixHsize - 1; y++)
			{
				for (int x = 0; x < pixWsize; x++) {
					sprite.data[y * pixHsize + x] = pixels[x][y];
				}
			}
			sprite.SaveSprite();
		}
	}
	if (wnd.kbd.KeyIsEmpty()) {
		f5Pressed = false;
	}
}

Color DrawColorPicker(Graphics& gfx,MainWindow& wnd) {
	int Xpos=20;
	int Ypos=20;
	int t=30; // thickness of bar
	Color c;
	Color bColor(200, 200, 200); // Border Color
	//mouse stuff
	int mX = 0;
	int mY = 0;
	////stuff from drawgrid
	const int StartX = 350;
	const int StartY = 30;
	const int pGridX = 32;	//grid size in blocks aka "pixels"
	const int pGridY = 32;	//grid size in blocks aka "pixels"
	const int blockWidth = 20;
	const int blockHeight = 20;
	
	//color selection stuff
	static unsigned char rTemp ;
	static unsigned char gTemp ;
	static unsigned char bTemp ;
	
	////Red Bar///////////
	//draw border in contrasting color
	gfx.DrawLine(Xpos, Ypos, Xpos + 256, Ypos, bColor);
	gfx.DrawLine(Xpos, Ypos-1, Xpos + 256, Ypos-1, bColor);
	gfx.DrawLine(Xpos, Ypos + t, Xpos + 256, Ypos + t, bColor);
	gfx.DrawLine(Xpos, Ypos + t + 1, Xpos + 256, Ypos + t + 1, bColor);
	gfx.DrawLine(Xpos, Ypos, Xpos , Ypos + t, bColor);
	gfx.DrawLine(Xpos - 1, Ypos, Xpos -1, Ypos + t, bColor);
	gfx.DrawLine(Xpos + 256, Ypos, Xpos + 256, Ypos + t, bColor);
	gfx.DrawLine(Xpos + 257, Ypos, Xpos + 257, Ypos + t, bColor);


	for (int a = 0; a < 256; a++) {
		c.SetR(a);

		gfx.DrawLine(Xpos + a, Ypos, Xpos + a, Ypos + t, c);
	}
	
	

	////Green Bar/////////
	Xpos = 20;
	Ypos = Ypos+35;
	c.SetR(0);
	//draw border in contrasting color
	
	gfx.DrawLine(Xpos, Ypos, Xpos + 256, Ypos, bColor);
	gfx.DrawLine(Xpos, Ypos - 1, Xpos + 256, Ypos - 1, bColor);
	gfx.DrawLine(Xpos, Ypos + t, Xpos + 256, Ypos + t, bColor);
	gfx.DrawLine(Xpos, Ypos + t + 1, Xpos + 256, Ypos + t + 1, bColor);
	gfx.DrawLine(Xpos, Ypos, Xpos, Ypos + t, bColor);
	gfx.DrawLine(Xpos - 1, Ypos, Xpos - 1, Ypos + t, bColor);
	gfx.DrawLine(Xpos + 256, Ypos, Xpos + 256, Ypos + t, bColor);
	gfx.DrawLine(Xpos + 257, Ypos, Xpos + 257, Ypos + t, bColor);


	for (int a = 0; a < 256; a++) {
		c.SetG(a);

		gfx.DrawLine(Xpos + a, Ypos, Xpos + a, Ypos + t, c);
	}

	////Blue bar/////////
	Xpos = 20;
	Ypos = Ypos + 35;
	c.SetR(0);
	c.SetG(0);
	//draw border in contrasting color

	gfx.DrawLine(Xpos, Ypos, Xpos + 256, Ypos, bColor);
	gfx.DrawLine(Xpos, Ypos - 1, Xpos + 256, Ypos - 1, bColor);
	gfx.DrawLine(Xpos, Ypos + t, Xpos + 256, Ypos + t, bColor);
	gfx.DrawLine(Xpos, Ypos + t + 1, Xpos + 256, Ypos + t + 1, bColor);
	gfx.DrawLine(Xpos, Ypos, Xpos, Ypos + t, bColor);
	gfx.DrawLine(Xpos - 1, Ypos, Xpos - 1, Ypos + t, bColor);
	gfx.DrawLine(Xpos + 256, Ypos, Xpos + 256, Ypos + t, bColor);
	gfx.DrawLine(Xpos + 257, Ypos, Xpos + 257, Ypos + t, bColor);


	for (int a = 0; a < 256; a++) {
		c.SetB(a);

		gfx.DrawLine(Xpos + a, Ypos, Xpos + a, Ypos + t, c);
	}
	
	/////////////////Get Mouse Click for color////////////////////
	if(wnd.mouse.LeftIsPressed()){
		mX = wnd.mouse.GetPosX();
		mY = wnd.mouse.GetPosY();
		if (mY > 20 && mY < 20 + t && mX >= 20 && mX < 20 + 256) { //check red
			rTemp = (mX - 20);
		}
		if (mY > 55 && mY < 55 + t && mX >= 20 && mX < 20 + 256) { //check green
			gTemp = (mX - 20);
		}
		if (mY > 90 && mY < 90 + t && mX >= 20 && mX < 20 + 256) { //check Blue
			bTemp = (mX - 20);
		}

	}

	Color tColor(rTemp, gTemp, bTemp);

	if (wnd.mouse.LeftIsPressed() && wnd.kbd.KeyIsPressed(VK_SPACE)) {
		int tempX = wnd.mouse.GetPosX();
		int tempY = wnd.mouse.GetPosY();
		int gX = (tempX - StartX) / blockWidth;
		if (gX >= pGridX) gX = pGridX - 1;
		int gY = (tempY - StartY) / blockHeight;
		if (gY < 0) gY = 0;
		if (gY >= pGridY) gY = pGridY - 1;
		tColor = pixels[gX][gY];
		rTemp = tColor.GetR();
		gTemp = tColor.GetG();
		bTemp = tColor.GetB();
	}


	//rgb values
	//R
	char bufferRgb[10];
	font.PrintS(gfx, "Red: ", 20, 200, bColor);
	_itoa_s((int)rTemp, bufferRgb, 10);
	font.PrintS(gfx, bufferRgb, 60, 200, bColor);

	//G
	font.PrintS(gfx, "Green: ", 20, 212, bColor);
	_itoa_s((int)gTemp, bufferRgb, 10);
	font.PrintS(gfx, bufferRgb, 80, 212, bColor);

	//B
	font.PrintS(gfx, "Blue: ", 20, 224, bColor);
	_itoa_s((int)bTemp, bufferRgb, 10);
	font.PrintS(gfx, bufferRgb, 80, 224, bColor);

	////draw current color
	for (int i = 0; i < 20;i++){
		gfx.DrawLine(300, i + 60, 320, i + 60, tColor);
		
	}
	return tColor;
}

void DrawGrid(Graphics& gfx,MainWindow& wnd,Color putColor) {
	const int pGridX = 32;	//grid size in blocks aka "pixels"
	const int pGridY = 32;	//grid size in blocks aka "pixels"
	const int StartX = 350;
	const int StartY = 30;
	const int blockWidth = 20;
	const int blockHeight = 20;
	int TotalHeight = pGridY * blockHeight;
	int TotalWidth = pGridX * blockWidth;
	///mouse stuff
	
	
	Color c(150, 150, 150);


	gfx.DrawLine(StartX, StartY, StartX + blockWidth * pGridX, StartY, c);
	
	for (int i = 0; i <= pGridX; i++) {
		gfx.DrawLine(i*blockWidth+StartX, StartY, i * blockWidth + StartX, StartY + TotalHeight,c);
	}
	for (int i = 0; i <= pGridY; i++) {
		gfx.DrawLine(StartX, i * blockHeight + StartY,  StartX + TotalWidth, i * blockHeight + StartY, c);
	}

	
	if (wnd.mouse.LeftIsPressed()&& wnd.kbd.KeyIsPressed(VK_SPACE)) {
		int tempX = wnd.mouse.GetPosX();
		int tempY = wnd.mouse.GetPosY();
		int gX = (tempX - StartX) / blockWidth;
		if (gX >= pGridX) gX = pGridX-1;
		int gY = (tempY - StartY) / blockHeight;
		if (gY < 0) gY = 0;
		if (gY >= pGridY) gY = pGridY - 1;
		putColor = pixels[gX][gY];
	}

	//put current color into array
	if (wnd.mouse.LeftIsPressed()) {
		int tempX = wnd.mouse.GetPosX();
		int tempY = wnd.mouse.GetPosY();
		int gX = (tempX - StartX) / blockWidth;
		if (gX >= pGridX) gX = pGridX - 1;
		int gY = (tempY - StartY) / blockHeight;
		if (gY < 0) gY = 0;
		if (gY >= pGridY) gY = pGridY - 1;
		pixels[gX][gY] = putColor;
	}

	//test print Mouse X and Y
	char buffer[16];
	_itoa_s(wnd.mouse.GetPosX(), buffer, 10);
	font.PrintS(gfx, buffer, 10, 500, c);
	_itoa_s(wnd.mouse.GetPosY(), buffer, 10);
	font.PrintS(gfx, buffer, 10, 520, c);



	//drawpixel
	for (int x = 0; x < pGridX; x++) {
		for (int y = 0; y < pGridY; y++) {
			gfx.DrawFRect(StartX + (x * blockWidth)+1, StartY + (y * blockHeight) +1, (blockWidth - 2), (blockHeight - 2), pixels[x][y]);
		}
	}

	///draw at normal res for reference
	const int Xoff = 50;
	const int Yoff = 500;
	for (int x = 0; x < pGridX; x++) {
		for (int y = 0; y < pGridY; y++) {
			gfx.PutPixel(x + Xoff, y + Yoff, pixels[x][y]);
		}
	}
}

void testDrawSprite(Graphics& gfx) {
	Color c(150, 150, 150);
	int fsize = 32 * 32;
	Color* cBuf;
	cBuf =(Color *) calloc(fsize, sizeof(Color));

	
	//std::ifstream file;
	FILE* file;
	//file.open("test.spr", std::ios::in | std::ios::binary);
	file=fopen("test.spr", "rb");
	if (file == nullptr) return; //fail if can't open file
	fseek(file, 80, SEEK_SET);
	fread((Color *)cBuf, sizeof(Color), 32 * 32,file);
	
	///getcount and output
	
	/*std::streampos begin, end;
	begin = file.tellg();
	file.seekg(0, std::ios::end);
	end = file.tellg();
	int fsize = (int)begin - (int)end; //fsize = 32 * 32 * 8 bytes! should be 32 * 32 * 4bytes!
	*/
	char sizeBuf[20];
	_itoa_s(fsize, sizeBuf, 10);
	font.PrintS(gfx, sizeBuf, 10, 400, c);
	
	//std::vector<char> vPix;
	//vPix.reserve(fsize);
	//char bufTemp[32 * 32 * 4];
	//file.seekg(0, std::ios::beg);
	//file.read(bufTemp, fsize);
	
	int xOff = 120;
	int yOff = 300;
	
	/* std::vector<char> data{
		std::istreambuf_iterator<char>{ std::ifstream("filename", std::ios::binary) },
		std::istreambuf_iterator<char>{}
	};*/ //investigate this
	

	for (int i = 0; i < (int)fsize; i+=4) {
		
		int y = i / 32;
		int x = i-(y*32);
		y = y + yOff;
		x = x + xOff;
		gfx.PutPixel(x, y, cBuf[i]);
	} 
	fclose(file);
	free(cBuf);

	//file.close();
	//sprite.data
}

void Game::ComposeFrame()
{
	
	//FpsWindow(gfx,font);
	//test = DrawColorPicker(gfx,wnd);
	font.PrintS(gfx, "spork", 200, 500, test);
	DrawFatRect(gfx, 300, 100, 400, 200, RainBorder);
	//DrawGrid(gfx,wnd,test);

	//testDrawSprite(gfx);
	
	
}
	
	
	
