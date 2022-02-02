#pragma once
#include "Ellipse.h"

class Circle : public Ellipse{

private: 
	double radius = 0;

public: 
	Circle(POINT center, const char* s = "Circle") : Ellipse(center,center,s),Shape(s) {
		//resetSteps(center, center, s);
		radius = get_rx();
	}
};