#include "main_shape1.cpp"
#pragma once


class rectangle : public shape
{
private:
    int length;
    int height;

public:
    rectangle(int x, int y, int length, int height, int color = 230)
        : shape(x, y, color), 
        length(length), height(height)
    {}

    float area() const 
    {
        return length * height;
    }
};