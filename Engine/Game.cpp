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
///Globalsish////
Font font;
char buffer[50];
char b2[10];
int bCount = 0;
char cTemp;


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

void Game::ComposeFrame()
{
	
	Color c;
	c.SetR(100);
	c.SetG(50);
	c.SetB(100);
	c.SetA(255);

	
	

	if (bCount < 49) {
		cTemp =wnd.kbd.ReadChar();
		if (cTemp != 0) {
			buffer[bCount] = cTemp;
			bCount++;
		}	
	}
	else {
		bCount = 0;
		for (int i = 0; i < 50; i++) {
			buffer[i] = 0;
		}
	}
	font.PrintS(gfx, buffer, 50, 300, c);
	_itoa_s(strlen(buffer), b2, 10);
	font.PrintS(gfx,b2,20,400,c);
}
	
	
	
