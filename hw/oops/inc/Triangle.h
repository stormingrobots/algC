#pragma once

#include <common.h>
#include <Shape.h>


class Triangle : public Shape {

private:
    POINT pts[3];
    double sides[3] = { 0,0,0 };
    
    void  resetSteps(POINT p[3], const char* n);

    void calSides();

    double dist(POINT p1, POINT p2);

    void calCenter();

    virtual void calArea();

    virtual void calPerimeter();

public:
    // given 3 points
    Triangle(POINT p[3], const char* s);
    
    // do scaling ONLY... 
    virtual void transform(POINT newCenter, double xscale, double yscale);

    const double* getSides();

};
