#pragma once
#include <common.h>


class Shape {

private: 
    static const int maxNameLen=20;  // wierd !!! 
   // static const double xyz = 50.0;

protected:
    POINT center;
    double area = 0.0;
    double perimeter = 0.0;
    char name[maxNameLen] = { 0 };

    virtual void calArea() = 0;
    virtual void calPerimeter() = 0;

public:
    Shape() = delete;
    Shape(const char *s)  { strncpy(name, s, sizeof(name)); }
    double getArea() const   { return area; }
    double getPerimeter() const { return perimeter; }
    POINT getCenter() const { return center; }
    const char* getName() const{ return name; }

    void setName(const char* n)  { strcpy(name, n); }
    virtual void calCenter() = 0; 
    virtual void transform(POINT, double, double) = 0;  // new origin, x-scale, y-scale
};



