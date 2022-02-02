#pragma once
#include "common.h"
#include "Shape.h"

class Rectangle : public Shape {

private:
    POINT tl, br; 
    double width, height;                            

    void setBaseMembers(POINT top, POINT bottom) {};
    void resetSteps(POINT top, POINT bottom) {};
    void calCenter() {};
    void calArea() {};
    void calPerimeter() {};

public:
    Rectangle() = delete;
    Rectangle(POINT top, POINT bottom, const char* n) : tl{ top }, br{ bottom },Shape(n) {
        width = abs(br.x - tl.x);
        height = abs(br.y - tl.y);
        calCenter();
        calArea();
        calPerimeter();
    };
    // do scaling only here... 
    virtual void transform(POINT newCenter, double xscale, double yscale) {}
    double getHeight() { return height; }
    double getWidth() { return width; }
};
