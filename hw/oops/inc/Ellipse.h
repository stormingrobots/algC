#pragma once
#include "common.h"
#include "Shape.h"
#include <math.h>

class Ellipse : public Shape {

private:
    double rx=0, ry = 0;
    POINT focal1 = { 0,0 }, focal2 = { 0,0 };

protected:
    void resetSteps(POINT f1, POINT f2, const char*s);

    virtual void calCenter() {};
    virtual void calArea() {};
    virtual void calPerimeter() {};

public:
    static const double PI;

    //Ellipse(const char* s);
    Ellipse(POINT f1, POINT f2, const char* s) :focal1{ f1 }, focal2{ f2 }, Shape(s){};

    // do scaling only here... 
    virtual void transform(POINT newCenter, double xscale, double yscale) {};
    double get_rx() { return 42.0; };
    double get_ry() {};
    
};
