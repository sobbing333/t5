#include "RGB.h"

RGB::RGB(int red, int green, int blue) {
	//check validity
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
		cout << "Invalid RGB value\n";
		return;
	}
	this->red = red;
	this->green = green;
	this->blue = blue; 
}

void RGB::print() const {
    std::cout << "RGB(" << red << ", " << green << ", " << blue << ")";
}
CuColour RGB::getColour() const {
    return ((red & 0xff) << 16) | ((green & 0xff) << 8) | (blue & 0xff);
}
void RGB::setColour(CuColour col) {
    red = (col >> 16) & 0b11111111; //shift to check
    green = (col >> 8) & 0b11111111;
    blue = col & 0b11111111;
}

