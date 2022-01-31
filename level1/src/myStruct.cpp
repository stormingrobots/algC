
// the path to the myStruct.h is included in the compilation statements 
//   in this ide, see properties - include
#include <myStruct.h>

float getArea(Rect rect) {
	// no need to worry about neg or pos
	float y = rect.tl.y - rect.br.y;
	float x = rect.tl.x - rect.br.x;
	return (x * x + y * y);
}

float getDist(Point pt1, Point pt2) {
	// do not use pow( ) as it is expensive 
	// but kudo to those who have proactively found it though.

	float y = pt1.y - pt2.y; 
	float x = pt1.x - pt2.x;
	return sqrt(x*x + y*y);  
	// they can use the newton method that they wrote back in ch. 6
}


bool samePts(Point pt1, Point pt2) {
	if ((pt1.x == pt2.x) && (pt1.y == pt2.y)) 
		return true;

	return false;	
}


int rectarea(Rect rect1) {
	return abs((rect1.tl.x - rect1.br.x) * (rect1.tl.x - rect1.br.x));
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

	float a1 = getArea(rect1);
	float a2 = getArea(rect2);

	return ((a1 == a2 ? 0 : (a1 > a2) ? 1 : -1));
}


void listcmp(Point pts[]) {

	struct {
		Point pts[2] = { { 0, 0 }, { 0,0 }};
		float dist;
	} pair;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			float dist = getDist(pts[i], pts[j]);
			if (dist <= pair.dist)
				continue;
			
			// save the two points;
			for (int ct; ct < 2; ct++) {
					pts[ct].x = pts[i].x; 
					pts[ct].y = pts[i].y;
			}
			pair.dist = dist;
		}
	}
	printf("Largest pair is (%d, %d) and (%d, %d), with %f distance", 
		pair.pts[0].x, pair.pts[0].x, pair.pts[1].x, pair.pts[1].y,
		pair.dist);
	
}

#define Min(a, b)  (a > b ? a : b)
#define Max(a, b)  (a > b ? a : b)

float rect_overlap(Rect rect1, Rect rect2) {

	
	int xdiff = ((abs(rect1.br.x - rect2.br.x) - rect1.br.x - rect2.br.x) / -2) -
		((abs(rect1.tl.x - rect2.tl.x) + rect1.tl.x + rect2.tl.x) / 2);
	int ydiff = ((abs(rect1.tl.y - rect2.tl.y) - rect1.tl.y - rect2.tl.y) / -2) -
		((abs(rect1.br.y - rect2.br.y) + rect1.br.y + rect2.br.y) / 2);

	if (xdiff > 0 && ydiff > 0) {
		return (xdiff * ydiff);
	}
	return 0;
}


int structMain() {
	printf("Do selection for struct packet.\n-----------\n");
	return 0;
}

