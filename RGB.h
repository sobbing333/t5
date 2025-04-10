#ifndef RGB_H
#define RGB_H

#include "defs.h"
#include <iostream>

using namespace std;

class RGB {
private:
    int red;
    int green;
    int blue;
public:
    RGB(int red = 255, int green = 255, int blue = 255);

    void print() const;
    CuColour getColour() const;
    void setColour(CuColour col);
    
 
	static RGB WHITE() { return RGB(255, 255, 255); }
	static RGB BLACK() { return RGB(0, 0, 0); }
	static RGB RED()   { return RGB(255, 0, 0); }
	static RGB GREEN() { return RGB(0, 255, 0); }
	static RGB BLUE()  { return RGB(0, 0, 255); }
};

#endif
