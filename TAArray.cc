#include "TAArray.h"
#include <iostream>
using namespace std;

TAArray::TAArray() {
	size = 0;
    elements = new TextArea*[MAX_TA];
}

TAArray::~TAArray() {
    
    delete[] elements; // free up memory
}

bool TAArray::add(TextArea* ta) {
    if (size >= MAX_TA)
        return false;
    elements[size++] = ta; //adds element and increase size
    return true;
}

bool TAArray::add(TextArea* ta, int index) {
    if (size >= MAX_TA || index < 0 || index > size)
        return false;
    for (int i = size; i > index; --i) {
        elements[i] = elements[i - 1];
    }
    elements[index] = ta;
    size++; //update size
    return true;
}

TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size)
        return NULL;
    return elements[index];
}

TextArea* TAArray::get(const string& id) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) // found id
            return elements[i];
    }
    return NULL; // not found
}

TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= size)
        return NULL;
    TextArea* ta = elements[index];
    for (int i = index; i < size - 1; ++i) {
        elements[i] = elements[i+1];
    }
    --size;
    return ta;
}

TextArea* TAArray::remove(const string& id) {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) { // Found id
            return remove(i);
        }
    }
    return NULL; // not found
}

void TAArray::print() const {
    cout << "TAArray contains " << size << " TextAreas." << endl;
    for (int i = 0; i < size; ++i) {
        elements[i]->print();
    }
    cout << endl;
}

