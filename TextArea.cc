#include "TextArea.h"
#include <iostream>
using namespace std;

TextArea::TextArea(int x, int y, int width, int height, const string& id, const string& text, 
                   const RGB& fill, const RGB& border) {
    dimensions.x = x;
	dimensions.y = y;
	dimensions.width = width;
	dimensions.height = height;
	this->id = id;
	this->text=text;
	this->fill= fill;
	this->border = border; 
}

TextArea::TextArea(const Rectangle& rect, const string& id, const string& text, 
                   const RGB& fill, const RGB& border) {
    
    dimensions = rect;
	this->id = id;
	this->text=text;
	this->fill= fill;
	this->border = border;     
    
}

void TextArea::draw(Display* display, Window win, GC gc, int x, int y) const {
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    
    // border
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    
    // text 
    XSetForeground(display, gc, 0x000000);
    
    XDrawString(display, win, gc, x + 5, y + 20, text.c_str(), text.length());
    
    
}

bool TextArea::overlaps(const TextArea& ta) const {
    return dimensions.overlaps(ta.dimensions);
}

void TextArea::print() const {
    cout << "TextArea id: " << id << "\nPreferred location: " 
         << dimensions.x << ", " << dimensions.y 
         << "\nSize: " << dimensions.width << ", " << dimensions.height 
         << "\nText: " << text << "\n";
}

void TextArea::setText(const string& newText) {
    text = newText;
}

void TextArea::setHeight(int height) {
    dimensions.height = height;
}

