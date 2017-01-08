#pragma once
#include <vector>
#include <fstream>
#include <iostream>
class Sprite {
public:
	Sprite();
	Sprite(int xsize, int ysize);
	Sprite(int xsize, int ysize, const char* name);
	Sprite LoadSprite(const char* filename);
	bool SaveSprite();

	char filename[20] = { "test.spr" };
	char name[15];
	std::vector<int> data;


private:
	int Xsize;
	int YSize;

};