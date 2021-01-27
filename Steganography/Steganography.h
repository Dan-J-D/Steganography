#pragma once

#include <string>

void AddTextToImage(std::string filename, std::string out_filename, unsigned char* data, unsigned int size);
/* HINT: free() after */
unsigned char* GetTextFromImage(std::string filename, unsigned int* size);
