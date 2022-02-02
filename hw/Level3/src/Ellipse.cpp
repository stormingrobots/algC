#pragma once
#include "common.h"
#include "Ellipse.h"
#include <math.h>

const double Ellipse::PI = 3.14159;

Ellipse::Ellipse(const char* s) : Shape(s) {
    setName(s);
}

Ellipse::Ellipse(POINT tl, POINT br, const char* s = "Circle") : Shape(s) {
    resetSteps(tl, br, s);
}

void  Ellipse::resetSteps(POINT topL, POINT botR,  const char* n = "Circle") {
    
    memcpy(&tl, &topL, sizeof(tl));
    memcpy(&br, &botR, sizeof(br));
    rx = fabs(tl.x - br.x) / 2; 
    ry = fabs(tl.y - br.y) / 2;
        calCenter();
        calArea();
        calPerimeter();
    }

    void Ellipse::calCenter() {
        center.x = tl.x + rx;
        center.y = tl.y - ry;
    }

    void Ellipse::calArea() {
        area = PI * rx * ry;
    }

    void Ellipse::calPerimeter() {
        perimeter = 2 * PI * sqrt((rx * rx + ry * ry) / 2);
    }

    double Ellipse::get_rx() {
        return rx; 
    }
   
    double Ellipse::get_ry() {
        return ry;
    }
    // do scaling only here... 
    void Ellipse::transform(POINT newCenter, double xscale, double yscale) {
        POINT newTop, newBottom;

        xscale = (xscale > 1 ? xscale : -xscale);
        newTop.x = tl.x - xscale / 2;
        newBottom.x = br.x + xscale / 2;

        yscale = (yscale > 1 ? xscale : -xscale);
        newTop.y = tl.x + yscale / 2;
        newBottom.y = br.x - yscale / 2;

        resetSteps(newTop, newBottom);
    }
