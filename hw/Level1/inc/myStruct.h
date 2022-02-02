#pragma once


// for the students, tell them to add their common.h to
// their current folder, and use "common.h"

#include <common.h> 

struct Point { double x; double y; };

//IMPORTANT: use proper field names
struct Rect { Point tl; Point br; };

double getArea(Rect rect);

double getDist(Point pt1, Point pt2);

bool samePts(Point pt1, Point pt2);

double rectarea(Rect rect1);


// is pt inside rect?
bool ptin(Rect rect, Point pt);

//  is rect2 inside rect1? 
bool rectIn(Rect rect1, Rect rect2);

int rectLarger(Rect rect1, Rect rect2);

void listcmp(Point *pts);
double rect_overlap(Rect rect1, Rect rect2);

void structMain();
