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

bool Sprite::SaveSprite()
{
	FILE* file;
	file=fopen(filename, "w+b");
	if (file == nullptr) return false;
	//fwrite(&data, sizeof(Color),XSize * YSize, file);
	fwrite(&data, sizeof(Color), 32*32, file);
	fclose(file);
	return true;

	
	/*std::ofstream file;
	file.open(filename, std::ios::out |std::ios::binary);
	file.seekp(0, std::ios::beg);
	file.write((char*)data.data(), data.size());
	file.close();
	return true;*/
}
