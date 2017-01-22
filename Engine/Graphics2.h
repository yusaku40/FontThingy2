#pragma once
#include "Graphics.h"
#include "Font.h"
#include "Utilies.h"

void DrawFatRect(Graphics & gfx, int x1, int y1, int x2, int y2, Color c);

void DrawSpriteS(Graphics& gfx, int x, int y);
void DrawSpriteS(Graphics& gfx, Vec2 pos);