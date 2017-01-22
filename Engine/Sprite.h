#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include"Colors.h"

class Sprite {
public:
	Sprite();
	Sprite(int xsize, int ysize);
	Sprite(int xsize, int ysize, const char* name);
	Sprite LoadSprite(const char* filename);
	bool SaveSprite(Color buf[], size_t size);

	char filename[20] = { "test.spr" };
	char name[15];
	Color * data;
	//std::vector<int> data;


private:
	int XSize;
	int YSize;

};