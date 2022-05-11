//
// Created by Cason Nichols on 5/3/22.
//Compiled with g++

#include "Color.h"

Color::Color() {
    this->setRed(0.5);
    this->setBlue(0.5);
    this->setGreen(0.5);
}

Color::Color(double red, double green, double blue){
    this->setRed(red);
    this->setGreen(green);
    this->setBlue(blue);
}

//copy constructor
Color::Color(const Color& oldColor) {
    red = oldColor.red;
    green = oldColor.green;
    blue = oldColor.blue;
}

Color &Color::setRed(double red) {
    if(red > 1.0){
        this->red = 1.0;
    } else if(red < 0.0){
        this->red = 0.0;
    }else {
        this->red = red;
    }
    return (*this);
}

Color &Color::setGreen(double green) {
    if(green > 1.0){
        this->green = 1.0;
    } else if(green < 0.0){
        this->green = 0.0;
    }else {
        this->green = green;
    }
    return (*this);
}

Color &Color::setBlue(double blue) {
    if(blue > 1.0){
        this->blue = 1.0;
    } else if(blue < 0.0){
        this->blue = 0.0;
    }else {
        this->blue = blue;
    }
    return (*this);
}

double Color::getRed() const {
    return this->red;
}

double Color::getGreen() const {
    return this->green;
}

double Color::getBlue() const {
    return this->blue;
}

Color &Color::operator=(Color *other) {
    if(other != this){
        return *this;
    }
    this->setRed(other->getRed());
    this->setGreen(other->getGreen());
    this->setBlue(other->getBlue());
    return *this;
}

bool operator==(const Color &colorOne, const Color &colorTwo) {
    if(colorOne.getRed() == colorTwo.getRed()){
        if(colorOne.getBlue() == colorTwo.getBlue()){
            return colorOne.getGreen() == colorTwo.getGreen();
        }
        return false;
    }
    return false;
}

Color operator+(const Color &colorOne, const Color &colorTwo) {
    Color *temp = new Color();
    temp->setRed(colorOne.getRed() + colorTwo.getRed());
    if(temp->getRed() > 1.0){
        temp->setRed(1.0);
    }
    temp->setGreen(colorOne.getGreen() + colorTwo.getGreen());
    if(temp->getGreen() > 1.0){
        temp->setGreen(1.0);
    }
    temp->setBlue(colorOne.getBlue() + colorTwo.getBlue());
    if(temp->getBlue() > 1.0){
        temp->setRed(1.0);
    }

    return *temp;

}

Color operator-(const Color &colorOne, const Color &colorTwo) {
    Color *temp = new Color();
    temp->setRed(colorOne.getRed() - colorTwo.getRed());
    if(temp->getRed() < 0.0){
        temp->setRed(0.0);
    }
    temp->setGreen(colorOne.getGreen() - colorTwo.getGreen());
    if(temp->getGreen() < 0.0){
        temp->setGreen(0.0);
    }
    temp->setBlue(colorOne.getBlue() - colorTwo.getBlue());
    if(temp->getBlue() < 0.0){
        temp->setRed(0.0);
    }

    return *temp;
}

Color operator*(const Color &colorOne, const Color &colorTwo) {
    Color *temp = new Color();
    temp->setRed(colorOne.getRed() * colorTwo.getRed());
    if(temp->getRed() > 1.0){
        temp->setRed(1.0);
    }
    temp->setGreen(colorOne.getGreen() * colorTwo.getGreen());
    if(temp->getGreen() > 1.0){
        temp->setGreen(1.0);
    }
    temp->setBlue(colorOne.getBlue() * colorTwo.getBlue());
    if(temp->getBlue() > 1.0){
        temp->setRed(1.0);
    }

    return *temp;
}

bool operator!(const Color &colorOne) {
    if(colorOne.getRed() == 0 && colorOne.getBlue() == 0 && colorOne.getGreen() == 0){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Color& color) {
    os << "(" << color.getRed() << " " << color.getGreen() << " " << color.getBlue() << ")";
    return os;
}

istream &operator>>(istream & is, Color& color) {

    is >> color.red >> color.green >> color.blue;

    return is;


}