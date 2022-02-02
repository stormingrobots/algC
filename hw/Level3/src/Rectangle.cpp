#pragma once
#include "common.h"
#include "Rect.h"


Rectangle::Rectangle(POINT top, POINT bottom, const char* n = "Rectangle") : Shape(n) {
    resetSteps(top, bottom);
}

void Rectangle::setBaseMembers(POINT top, POINT bottom) {
        memcpy(&tl, &top, sizeof(tl));
        memcpy(&br, &bottom, sizeof(br));

        width = fabs(top.x - bottom.x);
        height = fabs(top.y - bottom.y);
    }

    void Rectangle::resetSteps(POINT top, POINT bottom) {
        setBaseMembers(top, bottom);
        calCenter();
        calPerimeter();
        calArea();
    }

    void Rectangle::calCenter() {
        center.x = tl.x + (width / 2);
        center.y = tl.y - (height / 2);
    }

    void Rectangle::calArea() {
        area = width * height;
    }

    void Rectangle::calPerimeter() {
        perimeter = (width + height) * 2;
    }

    // do scaling only here... 
    void Rectangle::transform(POINT newCenter, double xscale, double yscale) {
        POINT newTop, newBottom;

        xscale = (xscale > 1 ? xscale : -xscale);
        newTop.x = tl.x - xscale / 2;
        newBottom.x = br.x + xscale / 2;

        yscale = (yscale > 1 ? xscale : -xscale);
        newTop.y = tl.x + yscale / 2;
        newBottom.y = br.x - yscale / 2;

        resetSteps(newTop, newBottom);
    }
