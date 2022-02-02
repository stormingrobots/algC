#pragma once

#include "common.h"
#include "Triangle.h"


Triangle::Triangle(POINT p[3], const char* s = "Triangle") : Shape(s) {
	resetSteps(p, s);
}

void Triangle::resetSteps(POINT p[3], const char* n = "Triangle") {
	memcpy(pts, p, sizeof(pts));
	calSides();
	calCenter();
	calArea();
	calPerimeter();
}

void Triangle::calSides() {
	sides[0] = dist(pts[0], pts[1]);
	sides[1] = dist(pts[1], pts[2]);
	sides[2] = dist(pts[0], pts[2]);
}

double Triangle::dist(POINT p1, POINT p2) {

	return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
		(p1.y - p2.y) * (p1.y - p2.y));

}

void Triangle::calCenter() {
	// will need to calculate later... 
	// will need to calculate the origin of the circle this triangle is in.      
}

void Triangle::calArea() {
	area = 0.5 * fabs(pts[0].x * (pts[1].y - pts[2].y) +
		pts[1].x * (pts[2].y - pts[0].y) +
		pts[2].x * (pts[0].y - pts[1].y));
}

void Triangle::calPerimeter() {
	perimeter = dist(pts[0], pts[1]) + dist(pts[1], pts[2]) + dist(pts[0], pts[2]);
}


// do scaling ONLY... 
void Triangle::transform(POINT newCenter, double xscale, double yscale) {

	POINT newPts[3] = { 0,0,0 };

	memcpy(&center, &newCenter, sizeof(center));
	// reset  origin, center tl, br
	//   ... calculate the newSides .. 
	resetSteps(newPts);
}


const double* Triangle::getSides() {
	return (sides);
}
