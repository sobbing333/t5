#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#define MAX_TA 64

class TAArray {
private:
    TextArea** elements;
    int size;
public:
    TAArray();
    ~TAArray();
    
    
    bool add(TextArea* ta);
    bool add(TextArea* ta, int index);
    
    TextArea* get(int index) const;
    TextArea* get(const string& id) const;
    
    TextArea* remove(int index);
    TextArea* remove(const string& id);
    
    bool isFull() const{return size == MAX_TA;}
    int getSize() const {return size;}
    void print() const;
};

#endif

