# Steganography

Hide Text in a Plain Image

## Usage
```cpp
void AddTextToImage(unsigned char* img, unsigned int img_size, unsigned char* data, unsigned int data_size);
```
~ Load any image to unsigned char* of color info

~ Max Data Input in image is (Image Height * Image Width * 4(rgba))

```cpp
unsigned char* GetTextFromImage(unsigned char* img, unsigned int img_size, unsigned int* out_data_size);
```
~ **REMEMBER TO FREE OUTPUT**

## Example
Look in **Steganography/test/test.cpp** for an example.

## License
[Apache 2.0](https://raw.githubusercontent.com/Dan-J-D/Steganography/main/LISCENSE)
