#include "Sprite.h"
#include <stdlib.h>

#pragma pack(1)

Sprite::Sprite()
{
	this->XSize = 32;
	this->YSize = 32;
	memcpy(name, "test", 15);
	memcpy(filename,"test.spr",20);
	data = (Color*)calloc(XSize*YSize, sizeof(Color));
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

bool Sprite::SaveSprite(Color buf[], size_t size)
{
	FILE* file;
	file=fopen(filename, "wb");
	if (file == nullptr) return false;
	fwrite(buf, size, 1, file);
	
	fclose(file);
	return true;


}
