#pragma once

void AddTextToImage(unsigned char* img, unsigned int img_size, unsigned char* data, unsigned int data_size);
/* HINT: free() after */
unsigned char* GetTextFromImage(unsigned char* img, unsigned int img_size, unsigned int* out_data_size);
