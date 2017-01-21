
#include "Utilies.h"
#include <string>

Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(int a, int b)
{
	this->x = a;
	this->y = b;
}

Vec2 Vec2::operator=(const Vec2 a)
{
	this->x = a.x;
	this->y = a.y;
	return Vec2();
}

/*Vec2 Vec2::operator+(const Vec2 a)
{
	this->x += a.x;
	this->y += a.y;

	return Vec2();
} */

Vec2 operator+(const Vec2 a, const Vec2 b) ///not part of class so its not a "unary" operator
{
	return{ a.x + b.x,a.y + b.y };
	//return Vec2();
}


void tLine::operator=(char* c)
{
	for (int i = 0; i < strlen(c); i++) {
		if (i < 50) {
			this->text[i] = c[i];
		}
	}
}

tRect::tRect(Vec2 lCorn, int width, int height)
{
	this->llCorner = lCorn;
	this->width = width;
	this->height = height;
	this->cWidth = (width / 10) - 1;
	this->cHeight = (height / 10) - 1;
	this->xPos = llCorner.x;
	this->yPos = llCorner.y;

}

void tRect::Push(const char * st)
{
	for (int i = 0; i < strlen(st); i++) {
		if (st[i] > 7 && st[i] < 127) {
			this->vText.push_back(st[i]);
		}
	}
}

void tRect::PushC(char ch)
{
	if (ch > 7 && ch < 127) {
		this->vText.push_back(ch);
	}
}

void clamp(int & i, int min, int max)
{
	if (i < min) i = min;
	if (i > max)i = max;
}

