
#include <iostream> 
#include <stdio.h>
#include <math.h>
#include "Rect.h"
#include "Triangle.h"
#include "Circle.h"

using namespace std;


ostream& operator<<(ostream& os, const POINT& p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

void printStuff(const Shape* s) {
    cout << s->getName() << '\n';
    cout << s->getArea() << '\n';
}


// Main function for the program
int main() {
  
    POINT tl = { 1.0, 30.0 };
    POINT br = { 10.0, 21.0 };

    POINT center = { 1,1 };

    // create ellipse object
    Circle circle(tl, br,  "El-circle");
 
    // create rectangle object
    Rectangle rec(tl, br,"Joe-rect");

    // create triangle object
    POINT points[] = { {1.0,2.0}, {10.0, 15.0}, {20.0, 2.0} };
    Triangle tri(points,  "El-triangle");
  
    Shape *shapes[3] = { &rec, &circle, &tri };

    // store the address of Rectangle
  
    center = rec.getCenter();
    printf("Rectangle at (%.2f,%.2f) with %.2f by %.2f: \n\tArea: %.2f; Perimeter: %.2f\n\n",
        center.x, center.y, rec.getWidth(), rec.getHeight(), rec.getArea(), rec.getPerimeter());

    center = circle.getCenter();
    printf("Circle at (%.2f,%.2f) with radius %.2f : \n\tArea: %.2f; Circumference: %.2f\n\n",
        center.x, center.y, circle.get_rx(), circle.getArea(), circle.getPerimeter());

    double sides[3];
    memcpy(sides, tri.getSides(), sizeof(sides));
    printf("Triangle %.2fx%.2fx%.2f : \n\tArea: %.2f; Perimeter: %.2f\n\n",
            sides[0], sides[1], sides[2],  tri.getArea(), tri.getPerimeter());

    int nShapes = sizeof(shapes) / sizeof(shapes[0]);
    for (int i=0; i < nShapes; i++) {
        printf("%-10s: Area = %-10.2f     Perimeter = %-10.2f\n", 
            shapes[i]->getName(), shapes[i]->getArea(), shapes[i]->getPerimeter());
    }
    /*
    for (const auto& s : shapes) {
        printStuff(s);
    }
    */
    return 0;
}