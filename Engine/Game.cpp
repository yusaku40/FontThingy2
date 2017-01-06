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


///Globalsish////
Font font;
char buffer[50];
char b2[10];
int bCount = 0;
char cTemp;
tRect txtRect({ 1,619 },1270 ,100);
bool msgPrinted = false;

////PixelEdit TempGlobals
const int pixWsize = 32;
const int pixHsize = 32;
unsigned int pixels[pixWsize][pixHsize];




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

void FpsWindow(Graphics& gfx) {
	//fps system parts
	static int fps[20];  ///for averaging fps rahter than be flickery
	SYSTEMTIME st;
	char buffer3[10];
	Color color = { 200,100,255 };

	int tempSum =0;

	GetSystemTime(&st);
	static int oldMs;
	static int deltaMs;
	deltaMs = oldMs - st.wMilliseconds;


	//calculate average of fps///
	for (int i = 0; i < 19; i++) {
		fps[i + 1] = fps[i]; //move old measure down the stack
	}
	fps[0] = 1000 / deltaMs; //add new fps measure
	for (int i = 0; i < 20; i++) {
		tempSum = tempSum + fps[i];
	}
	_itoa_s(tempSum / 20, buffer3, 10);
	//tempSum = 0;
	///end calculate average fps///

	font.PrintS(gfx,"FPS: ",1200, 20 ,color);
	font.PrintS(gfx, buffer3, 1230, 20,  color);



	oldMs = st.wMilliseconds;


	gfx.DrawLine({ 1190,30 }, { 1279,30 }, { 150,50,150 });
	gfx.DrawLine({ 1190,30 }, { 1190,0 }, { 150,50,150 });
}

void pRain(Graphics& gfx) {
	static int pOff1;
	static int pOff2;
	static int pOff3;

	Color c(255, 0, 255);
	//fg rain
	if (pOff1 < 300) {

		int test = rand();
		int test2 = rand() / 255;
		

		gfx.DrawLine(10, 10 + pOff1, 10, 40 + pOff1, c);
		gfx.DrawLine(50, 20 + pOff1, 50, 50 + pOff1, c);
		gfx.DrawLine(70, 40 + pOff1, 70, 70 + pOff1, c);
		gfx.DrawLine(200, 10 + pOff1, 200, 40 + pOff1, c);
		pOff1 = pOff1 + 10;
	}
	else {
		pOff1 = 0;
	}
	//mid rain
	Color c2(200, 0, 200);
	if (pOff2 < 300) {
		gfx.DrawLine(20 , 10 + pOff2, 20 , 20 + pOff2, c2);
		gfx.DrawLine(80 , 10 + pOff2, 80 , 20 + pOff2, c2);
		gfx.DrawLine(90 , 10 + pOff2, 90 , 20 + pOff2, c2);
		gfx.DrawLine(150, 10 + pOff2, 150, 20 + pOff2, c2);
		pOff2 = pOff2 + 6;
	}
	else {
		pOff2 = 0;
	}

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
	//color selection stuff
	static unsigned char rTemp ;
	static unsigned char gTemp ;
	static unsigned char bTemp ;
	
	///Red Bar///////////
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

	////draw current color
	Color tColor(rTemp, gTemp, bTemp);
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

	
	Color c(150, 150, 150);


	gfx.DrawLine(StartX, StartY, StartX + blockWidth * pGridX, StartY, c);
	
	for (int i = 0; i <= pGridX; i++) {
		gfx.DrawLine(i*blockWidth+StartX, StartY, i * blockWidth + StartX, StartY + TotalHeight,c);
	}
	for (int i = 0; i <= pGridY; i++) {
		gfx.DrawLine(StartX, i * blockHeight + StartY,  StartX + TotalWidth, i * blockHeight + StartY, c);
	}

	if (wnd.mouse.LeftIsPressed()) {
		int tempX = wnd.mouse.GetPosX();
		int tempY = wnd.mouse.GetPosY();
		int gX = (tempX - StartX) / blockWidth;
		if (gX >= pGridX) gX = pGridX-1;
		int gY = (tempY - StartY) / blockHeight;
		if (gY < 0) gY = 0;
		if (gY >= pGridY) gY = pGridY - 1;
		pixels[gX][gY] = putColor.dword;	

		
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

void Game::ComposeFrame()
{
	Color test;
	FpsWindow(gfx);
	test = DrawColorPicker(gfx,wnd);
	font.PrintS(gfx, "spork", 200, 500, test);
	DrawGrid(gfx,wnd,test);
	
	
}
	
	
	
