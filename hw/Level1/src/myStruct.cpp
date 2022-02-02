
// the path to the myStruct.h is included in the compilation statements 
//   in this ide, see properties - include
#include <myStruct.h>

double getArea(Rect rect) {
	// no need to worry about neg or pos
	double y = rect.tl.y - rect.br.y;
	double x = rect.tl.x - rect.br.x;
	return (x * x + y * y);
}

double getDist(Point pt1, Point pt2) {
	// do not use pow( ) as it is expensive 
	// but kudo to those who have proactively found it though.

	double y = pt1.y - pt2.y; 
	double x = pt1.x - pt2.x;
	return sqrt(x*x + y*y);  
	// they can use the newton method that they wrote back in ch. 6
}


bool samePts(Point pt1, Point pt2) {
	if ((pt1.x == pt2.x) && (pt1.y == pt2.y)) 
		return true;

	return false;	
}


double rectarea(Rect rect1) {
	return fabs((rect1.tl.x - rect1.br.x) * (rect1.tl.x - rect1.br.x));
}



// is pt inside rect?
bool ptin(Rect rect, Point pt) {
	if (rect.tl.x < pt.x && rect.br.x > pt.x  && 
		rect.tl.y > pt.y && rect.br.y < pt.y) {
		return true;
	}
	return false;
}

//  is rect2 inside rect1? 
bool rectIn(Rect rect1, Rect rect2) {
	if (rect1.tl.y <= rect2.tl.y && rect1.tl.x >= rect2.tl.x && 
		rect2.br.x >= rect1.br.x && rect2.br.y <= rect1.br.y) {
		return true;
	}
	return false;
}

// which rect is larger
// return
// O : rect1 == rect2 
// 1 : rect1 > rect2 
// -1 : rect1 < rect2 
int rectLarger(Rect rect1, Rect rect2) {

	double a1 = getArea(rect1);
	double a2 = getArea(rect2);

	return ((a1 == a2 ? 0 : (a1 > a2) ? 1 : -1));
}


void listcmp(Point pts[]) {

	struct {
		Point pts[2] = { { 0, 0 }, { 0,0 }};
		double dist;
	} pair;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			double dist = getDist(pts[i], pts[j]);
			if (dist <= pair.dist)
				continue;
			
			// save the two points;
			for (int ct=0; ct < 2; ct++) {
					pts[ct].x = pts[i].x; 
					pts[ct].y = pts[i].y;
			}
			pair.dist = dist;
		}
	}
	printf("Largest pair is (%lf, %lf) and (%lf, %lf), with %lf distance", 
		pair.pts[0].x, pair.pts[0].x, pair.pts[1].x, pair.pts[1].y,
		pair.dist);
	
}


double rect_overlap(Rect rect1, Rect rect2) {

	
	double xdiff = ((fabs(rect1.br.x - rect2.br.x) - rect1.br.x - rect2.br.x) / -2) -
		((fabs(rect1.tl.x - rect2.tl.x) + rect1.tl.x + rect2.tl.x) / 2);
	double ydiff = ((fabs(rect1.tl.y - rect2.tl.y) - rect1.tl.y - rect2.tl.y) / -2) -
		((fabs(rect1.br.y - rect2.br.y) + rect1.br.y + rect2.br.y) / 2);

	if (xdiff > 0 && ydiff > 0) {
		return (xdiff * ydiff);
	}
	return 0;
}


void structMain() {
	printf("Do selection for struct packet.\n-----------\n");
	return;
}

