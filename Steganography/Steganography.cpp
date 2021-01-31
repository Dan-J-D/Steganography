/*
Source: https://github.com/Dan-J-D/Steganography

Copyright 2021 Daniel Doych

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Steganography.h"

#define get_bit(num, bit) ((num >> bit) & 1)
#define clear_bit(num, bit) (num &= ~(1 << bit))
#define toggle_bit(num, bit) (num ^= 1 << bit)
#define set_bit(num, bit, val) if(get_bit(num, bit) != val) toggle_bit(num, bit)

void add_data(unsigned char* img, unsigned int img_size, unsigned char* data, unsigned int data_size)
{
	int s = img_size;
	for (int i = 0; i < 4; i++)
		for (int x = 0; x < 8; x++)
			set_bit(img[(int)((i * 8 + x) % s)], (int)((i * 8 + x) / s), get_bit(((unsigned char*)&data_size)[i], x));

	for (int i = 0; i < data_size; i++)
		for (int x = 0; x < 8; x++)
			set_bit(img[(int)((4 * 8 + (i * 8) + x) % s)], (int)((4 * 8 + i * 8 + x) / s), get_bit(data[i], x));
}

void get_size(unsigned char* img, unsigned int img_size, unsigned int& size)
{
	int s = img_size;
	size = 0;
	for (int i = 0; i < 4; i++)
		for (int x = 0; x < 8; x++)
			set_bit(((unsigned char*)&size)[i], x, get_bit(img[(int)((i * 8 + x) % s)], (int)((i * 8 + x) / s)));
}

void get_data(unsigned char* img, unsigned int img_size, unsigned char* out_data, unsigned int data_size)
{
	int s = img_size;
	for (int i = 0; i < data_size; i++)
		for (int x = 0; x < 8; x++)
			set_bit(out_data[i], x, get_bit(img[(int)((4 * 8 + (i * 8) + x) % s)], (int)((4 * 8 + i * 8 + x) / s)));
}

void AddTextToImage(unsigned char* img, unsigned int img_size, unsigned char* data, unsigned int data_size)
{
	add_data(img, img_size, data, data_size);
}

unsigned char* GetTextFromImage(unsigned char* img, unsigned int img_size, unsigned int* out_data_size)
{
	get_size(img, img_size, *out_data_size);
	unsigned char* data = (unsigned char*)malloc(*out_data_size);
	get_data(img, img_size, data, *out_data_size);
	return data;
}
