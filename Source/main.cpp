// Imports
#include "image.h"

int main(int argc, char** argv)
{
	// Read in the image
	Image test("test.jpg");

	// Write with a new extension
	test.write("new.png");

	// Copy the image data
	Image copy = test;

	// Alter a section of the image
	for (int i = 0; i < copy.getWidth() * copy.getChannels(); ++i)
	{
		copy.getData()[i] = 255;
	}

	copy.write("copy.jpg");

	// Create a 100 x 100 x 3 blank image
	Image blank(100, 100, 3);
	blank.write("blank.jpg");
	return 0;
}