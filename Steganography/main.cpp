#include <iostream>

#include "Steganography.h"

void test_TextToImage()
{
	unsigned char* data = (unsigned char*)malloc(400000);
	memset(data, (int)'a', 400000);
	AddTextToImage("C:\\Users\\dan\\source\\repos\\EncryptedSteganography\\Debug\\test.png", "C:\\Users\\dan\\source\\repos\\EncryptedSteganography\\Debug\\test_e.png", (unsigned char*)data, 400000);
}

void test_GetTextFromImage()
{
	unsigned int size = 0;
	unsigned char* data = GetTextFromImage("C:\\Users\\dan\\source\\repos\\EncryptedSteganography\\Debug\\test_e.png", &size);
	std::string str;
	str.insert(0, (char*)data, size);
	free(data);
	std::cout << str << std::endl << str.size() << std::endl;
}

int main()
{
	//test_TextToImage();
	test_GetTextFromImage();
}
