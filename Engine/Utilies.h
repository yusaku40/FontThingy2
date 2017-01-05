#pragma once
#include <vector>

class Vec2 {
public:
	Vec2();
	Vec2(int a, int b);
	int x;
	int y;
	
};

class tLine {
public:
	void operator=(char* c);
	char text[50];
private:
	
};

class tRect {
public:
	tRect(Vec2 lCorn, int width, int height);
	void Push(const char* st); //push a text string into textRec
	void PushC(char ch);		//push a single char to textRectangle

	int width;
	int height;
	int cWidth;
	int cHeight;
	std::vector<char> vText;
	int xPos;
	int yPos;
	Vec2 llCorner;
private:
	

};