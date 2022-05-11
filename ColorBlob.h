//
// Created by Cason Nichols on 5/3/22.
//Compiled with g++
#include <iostream>
#include "Color.h"
#ifndef ASSIGNMENT_3_COLORBLOB_H
#define ASSIGNMENT_3_COLORBLOB_H

using namespace std;

class ColorBlob{

    friend bool operator==(const ColorBlob&, const ColorBlob&);
    friend ostream& operator<<(ostream&, const ColorBlob&);
    friend istream& operator>>(istream&, ColorBlob&);
    friend ColorBlob operator+(const ColorBlob &cBlobOne, const ColorBlob &cBlobTwo);
    friend ColorBlob operator-(const ColorBlob &cBlobOne, const ColorBlob &cBlobTwo);
    friend ColorBlob operator*(const ColorBlob &cBlobOne, const Color &c);
    friend bool operator!(const ColorBlob &cBlob);

public:// delegating constructor
    ColorBlob();   // default constructor
    ColorBlob(int,int, Color color);   // constructor with parameters
    ColorBlob(const ColorBlob&);          //copy constructor
    ~ColorBlob();                      //destructor
    ColorBlob(ColorBlob&&) noexcept;            //move constructor
    ColorBlob& operator=(const ColorBlob&);//copy assignment operator
    ColorBlob& operator=(ColorBlob&&) noexcept;//move operator


private:
    int width;
    int height;
    Color** data;
};

#endif //ASSIGNMENT_3_COLORBLOB_H
