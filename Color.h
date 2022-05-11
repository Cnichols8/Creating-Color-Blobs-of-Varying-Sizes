//
// Created by Cason Nichols on 5/3/22.
//Compiled with g++
#include <iostream>
#include <iosfwd>

#ifndef ASSIGNMENT_3_COLOR_H
#define ASSIGNMENT_3_COLOR_H

using namespace std;

class Color {
    friend bool operator==(const Color& colorOne, const Color& colorTwo);
    friend Color operator+(const Color& colorOne, const Color& colorTwo);
    friend Color operator-(const Color& colorOne, const Color& colorTwo);
    friend Color operator*(const Color& colorOne, const Color& colorTwo);
    friend bool operator!(const Color& colorOne);
    friend ostream& operator<<(ostream& os, const Color& color);
    friend istream& operator>>(istream&, Color&);
private:
    double red, green, blue;
public:
    Color();
    Color(double red, double green, double blue);
    Color(const Color&);
    Color& setRed(double red);
    Color& setGreen(double green);
    Color& setBlue(double blue);
    Color& operator = (Color *other);
    double getRed() const;
    double getGreen() const;
    double getBlue() const;

};

#endif //ASSIGNMENT_3_COLOR_H
