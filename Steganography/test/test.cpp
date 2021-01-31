#include <iostream>
#include <fstream>

#include "lodepng.hpp"
#include "../Steganography.h"

void test_TextToImage()
{
	/* Filling Buffer with all 'a' */
	static int data_size = 4000;
	unsigned char* data = (unsigned char*)malloc(data_size);
	memset(data, (int)'a', data_size);

	/* Load Image to Buffer */
	std::vector<unsigned char> img;
	unsigned int w, h;
	lodepng::decode(img, w, h, "test.png");

	/* Add Text To Image Max bytes (Image Width * Image Height * 4) */
	AddTextToImage(img.data(), img.size(), (unsigned char*)data, data_size);

	/* Save Image From Buffer */
	lodepng::encode("test_e.png", img, w, h);

	/* Free Data Buffer */
	free(data);
}

void test_GetTextFromImage()
{
	/* Load Image */
	std::vector<unsigned char> img;
	unsigned int w, h = 0;
	lodepng::decode(img, w, h, "test_e.png");

	/* Get Text From Image */
	unsigned int size = 0;
	unsigned char* data = GetTextFromImage(img.data(), img.size(), &size);

	// using 'fwrite' for faster printing of large data also no '0'(NULL terminating character) at end of string
	fwrite(data, 1, size, stdout);
	std::cout << std::endl << size << std::endl;
}

int main()
{
	test_TextToImage();
	test_GetTextFromImage();
}
