#include "Sprite.h"

Sprite::Sprite()
{
	this->Xsize = 32;
	this->YSize = 32;
	memcpy(name, "test", 15);
	memcpy(filename,"test.spr",20);
}

Sprite::Sprite(int xsize, int ysize)
{
}

Sprite::Sprite(int xsize, int ysize, const char * name)
{
}

Sprite Sprite::LoadSprite(const char * filename)
{
	return Sprite();
}

bool Sprite::SaveSprite()
{
	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::trunc |std::ios::binary);
	for (size_t i = 0; i < data.size(); i++) {
		file.write((char*)&data[i], sizeof(int));
	}
	file.close();
	return true;
}
