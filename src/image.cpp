#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

// Imports
#include "./image.h"
#include "./stb_image.h"
#include "./stb_image_write.h"
#include <iostream>

// Constructor
Image::Image(const char* filename)
{
	if (read(filename))
	{
		std::cout << "Reading: " << filename << "\n";
		size = width * height * channels;
	}
	else
	{
		std::cout << "Failed to read: " << filename << "\n";
	}
}

Image::Image(int width, int height, int channels) : width(width), height(height), channels(channels)
{
	size = width * height * channels;
	data = new uint8_t[size];
}

// Copy constructor
Image::Image(const Image& img) : Image(img.width, img.height, img.channels)
{
	memcpy(data, img.data, size);
}

// Deconstructor
Image::~Image()
{
	stbi_image_free(data);
}

// Load the image
bool Image::read(const char* filename) 
{
	data = stbi_load(filename, &width, &height, &channels, 0);
	return data != NULL;
}

// Accessor - Width
int Image::getWidth()
{
	return width;
}

// Accessor - Height
int Image::getHeight()
{
	return height;
}

// Accessor - Channels
int Image::getChannels()
{
	return channels;
}

// Accessor - Data
uint8_t* Image::getData()
{
	return data;
}

// Write the image
bool Image::write(const char* filename) 
{
	ImageType type = getFileType(filename);
	int success{};

	switch (type)
	{
	case PNG:
		success = stbi_write_png(filename, width, height, channels, data, width * channels);
		break;
	case JPG:
		success = stbi_write_jpg(filename, width, height, channels, data, 100);
		break;
	case BMP:
		success = stbi_write_bmp(filename, width, height, channels, data);
		break;
	case TGA:
		success = stbi_write_tga(filename, width, height, channels, data);
		break;
	default:
		break;
	}
	return success != 0;
}

// Get the image extension
ImageType Image::getFileType(const char * filename)
{
	const char* ext = strrchr(filename, '.');
	if (ext != nullptr)
	{
		if (strcmp(ext, ".png") == 0)
		{
			return PNG;
		}
		else if (strcmp(ext, ".jpg") == 0)
		{
			return JPG;
		}
		else if (strcmp(ext, ".bmp") == 0)
		{
			return BMP;
		}
		else if (strcmp(ext, ".tga") == 0)
		{
			return TGA;
		}
	}
	return PNG;
}
