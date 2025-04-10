#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <X11/Xlib.h>
#include <string>
#include "defs.h"
#include "RGB.h"
using namespace std;

class TextArea {
private:
    Rectangle dimensions;
    string text;
    string id;
    RGB fill;
    RGB border;
public:
    
    TextArea(int x, int y, int width, int height, const string& id, const string& text, 
             const RGB& fill = RGB::WHITE(), const RGB& border = RGB::BLACK());
    
    TextArea(const Rectangle& rect, const string& id, const string& text, 
             const RGB& fill = RGB::WHITE(), const RGB& border = RGB::BLACK());
    
    
    void draw(Display* display, Window win, GC gc, int x, int y) const;
    
    bool overlaps(const TextArea& ta) const;
    
    void print() const;
    
    string getId() const { return id; }
    const Rectangle& getDimensions() const { return dimensions; }

    
    void setText(const string& newText);
    void setHeight(int height);
};

#endif

