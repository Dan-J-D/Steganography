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

#pragma once

void AddTextToImage(unsigned char* img, unsigned int img_size, unsigned char* data, unsigned int data_size);
/* HINT: free() after */
unsigned char* GetTextFromImage(unsigned char* img, unsigned int img_size, unsigned int* out_data_size);
