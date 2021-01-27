#include "lodepng.hpp"
#include "Steganography.h"

#define get_bit(num, bit) ((num >> bit) & 1)
#define clear_bit(num, bit) (num &= ~(1 << bit))
#define toggle_bit(num, bit) (num ^= 1 << bit)
#define set_bit(num, bit, val) if(get_bit(num, bit) != val) toggle_bit(num, bit)

void add_data(std::vector<unsigned char>& img, unsigned char* data, unsigned int size)
{
	int s = img.size();
	for (int i = 0; i < 4; i++)
		for (int x = 0; x < 8; x++)
			set_bit(img[(int)((i * 8 + x) % s)], (int)((i * 8 + x) / s), get_bit(((unsigned char*)&size)[i], x));

	for (int i = 0; i < size; i++)
		for (int x = 0; x < 8; x++)
			set_bit(img[(int)((4 * 8 + (i * 8) + x) % s)], (int)((4 * 8 + i * 8 + x) / s), get_bit(data[i], x));
}

void get_size(std::vector<unsigned char>& img, unsigned int& size)
{
	int s = img.size();
	size = 0;
	for (int i = 0; i < 4; i++)
		for (int x = 0; x < 8; x++)
			set_bit(((unsigned char*)&size)[i], x, get_bit(img[(int)((i * 8 + x) % s)], (int)((i * 8 + x) / s)));
}

void get_data(std::vector<unsigned char>& img, unsigned char* out, unsigned int size)
{
	int s = img.size();
	for (int i = 0; i < size; i++)
		for (int x = 0; x < 8; x++)
			set_bit(out[i], x, get_bit(img[(int)((4 * 8 + (i * 8) + x) % s)], (int)((4 * 8 + i * 8 + x) / s)));
}

void AddTextToImage(std::string filename, std::string out_filename, unsigned char* data, unsigned int size)
{
	std::vector<unsigned char> img;
	unsigned int w, h;
	if (lodepng::decode(img, w, h, filename) != 0) throw 0;
	add_data(img, data, size);
	lodepng::encode(out_filename, img, w, h);
}

unsigned char* GetTextFromImage(std::string filename, unsigned int* size)
{
	std::vector<unsigned char> img;
	unsigned int w, h = 0;
	if(lodepng::decode(img, w, h, filename) != 0) throw 0;
	get_size(img, *size);
	unsigned char* data = (unsigned char*)malloc(*size);
	get_data(img, data, *size);
	return data;
}
