//
// Created by Cason Nichols on 5/3/22.
// Compiled with g++

#include "ColorBlob.h"

//default constructor
ColorBlob::ColorBlob() {
    this->width = 2;
    this->height = 2;

    data = new Color *[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new Color[width];
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; ++j) {
            data[i][j] = new Color();
        }
    }
}

//constructor with parameters
ColorBlob::ColorBlob(int row, int col, Color color) {

    this->height = row;
    this->width = col;

    data = new Color *[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new Color[width];
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] = color;
        }
    }
}

//copy constructor
ColorBlob::ColorBlob(const ColorBlob &c) {

    this->height = c.height;
    this->width = c.width;

    data = new Color *[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new Color[height];
    }
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            this->data[i][j] = c.data[i][j];
        }
    }
}

//destructor;
ColorBlob::~ColorBlob() {
    for (int i = 0; i < width; i++) {
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
}

//copy assignment operator
ColorBlob &ColorBlob::operator=(const ColorBlob &c) {
    if (&c != this) {
        delete[] data;
        height = c.height;
        width = c.width;
        data = new Color *[height];
        for (int i = 0; i < height; ++i) {
            data[i] = new Color[height];
        }
        for (int i = 0; i < this->height; ++i) {
            for (int j = 0; j < this->width; ++j) {
                this->data[i][j] = c.data[i][j];
            }
        }
    }
    return *this;
}

//move constructor
ColorBlob::ColorBlob(ColorBlob &&c) noexcept {
    this->height = c.height;
    this->width = c.width;
    this->data = c.data;
    c.height = 0;
    c.width = 0;
    c.data = nullptr;
}

//move operator
ColorBlob &ColorBlob::operator=(ColorBlob &&another) noexcept {
    height = another.height;
    width = another.width;

    data = new Color *[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new Color[height];
    }
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            this->data[i][j] = another.data[i][j];
            another.data[i][j] = nullptr;
        }
    }
    another.height = 0;
    another.width = 0;
    return (*this);
}

bool operator==(const ColorBlob &a, const ColorBlob &b) {
    if (a.height != b.height)return 0;
    if (a.width != b.width)return 0;

    for (int i = 0; i < a.height; i++) {
        for (int j = 0; j < a.width; j++) {
            if (a.data != b.data) return 0;
        }
    }
    return 1;
}

ostream &operator<<(ostream &os, const ColorBlob &c) {
    for (int i = 0; i < c.height; i++) {
        for (int j = 0; j < c.width; j++) {
            os << "[" << i << "]" << "[" << j << "]: " << c.data[i][j] << "\n";
        }
    }
    return os;
}

istream &operator>>(istream &is, ColorBlob &c) {
    for (int i = 0; i < c.height; i++) {
        for (int j = 0; j < c.width; j++) {
            cout << "[" << i << "]" << "[" << j << "]: " << endl;
            is >> c.data[i][j];
        }
    }
    return is;
}

ColorBlob operator+(const ColorBlob &cBlobOne, const ColorBlob &cBlobTwo) {
    int minH, minW;
    if (cBlobOne.height > cBlobTwo.height) {
        minH = cBlobTwo.height;
    } else {
        minH = cBlobOne.height;
    }
    if (cBlobOne.width > cBlobTwo.width) {
        minW = cBlobTwo.width;
    } else {
        minW = cBlobOne.width;
    }

    Color temp;
    ColorBlob newColorBlob = *new ColorBlob(minH, minW, temp);
    for (int i = 0; i < minH; ++i) {
        for (int j = 0; j < minW; ++j) {
            newColorBlob.data[i][j] = cBlobOne.data[i][j] + cBlobTwo.data[i][j];
        }
    }
    return newColorBlob;
}

ColorBlob operator-(const ColorBlob &cBlobOne, const ColorBlob &cBlobTwo) {
    int minH, minW;
    if (cBlobOne.height > cBlobTwo.height) {
        minH = cBlobTwo.height;
    } else {
        minH = cBlobOne.height;
    }
    if (cBlobOne.width > cBlobTwo.width) {
        minW = cBlobTwo.width;
    } else {
        minW = cBlobOne.width;
    }

    Color temp;
    ColorBlob newColorBlob = *new ColorBlob(minH, minW, temp);
    for (int i = 0; i < minH; ++i) {
        for (int j = 0; j < minW; ++j) {
            newColorBlob.data[i][j] = cBlobOne.data[i][j] - cBlobTwo.data[i][j];
        }
    }
    return newColorBlob;
}

ColorBlob operator*(const ColorBlob &cBlobOne, const Color &c) {
    int minH = cBlobOne.height;
    int minW = cBlobOne.width;

    Color temp;
    ColorBlob newColorBlob = *new ColorBlob(minH, minW, temp);
    for (int i = 0; i < newColorBlob.height; ++i) {
        for (int j = 0; j < newColorBlob.width; ++j) {
            newColorBlob.data[i][j] = cBlobOne.data[i][j] * c;
        }
    }
    return newColorBlob;
}

bool operator!(const ColorBlob &cBlob) {
    for (int i = 0; i < cBlob.height; i++) {
        for (int j = 0; j < cBlob.width; j++) {
            if (!(!cBlob.data[i][j])) {
                return true;
            }
        }
    }
    return true;
}
