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

SYSTEMTIME st;
int oldMs = 1;
int deltaMs = 1;
int fps = 0;


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
	char buffer3[10];
	Color color = { 200,100,255 };

	GetSystemTime(&st);
	deltaMs = oldMs - st.wMilliseconds;

	fps = 1000 / deltaMs;
	_itoa_s(fps, buffer3, 10);

	font.PrintS(gfx,"FPS: ",1200, 20 ,color);
	font.PrintS(gfx, buffer3, 1230, 20,  color);



	oldMs = st.wMilliseconds;


	gfx.DrawLine({ 1190,30 }, { 1279,30 }, { 150,50,150 });
	gfx.DrawLine({ 1190,30 }, { 1190,0 }, { 150,50,150 });
}

void Game::ComposeFrame()
{
	
	Color c;
	c.SetR(100);
	c.SetG(140);
	c.SetB(100);
	c.SetA(255);

	
	FpsWindow(gfx);


	if (bCount < 49) {
		cTemp =wnd.kbd.ReadChar();
		
		if (cTemp != 0) {
			if (cTemp ==8) {
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
	font.PrintS(gfx,b2,500,400,c);
	if (wnd.mouse.LeftIsPressed()&& !msgPrinted) {
		txtRect.Push(" L Mouse button is pressed ");
		char cr =13;
		txtRect.Push(&cr);
		msgPrinted= true;
	}
	if (!wnd.mouse.LeftIsPressed()) {
		msgPrinted = false;
	}
	
	
}
	
	
	
