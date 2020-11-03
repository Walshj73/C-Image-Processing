#pragma once

// Imports
#include <stdint.h>
#include <cstdio>

// Extension type
enum ImageType
{
	PNG, JPG, BMP, TGA
};

class Image
{
private:
	uint8_t* data = NULL;
	size_t size = 0;
	int width;
	int height;
	int channels;

public:
	// Constructors & Deconstructor
	Image(const char* filename);
	Image(int width, int height, int channels);
	Image(const Image& img);
	~Image();

	// Accessors
	int getWidth();
	int getHeight();
	int getChannels();
	uint8_t* getData();

	// Read & Write functions
	bool read(const char* filename);
	bool write(const char* filename);
	ImageType getFileType(const char* filename);
};