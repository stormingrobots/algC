
#include <Shape.h>
#include <Rect.h>
#include <Ellipse.h>
#include <Circle.h>

void joe(const  Shape& s) {
	cout << s.getArea() << '\n';
}


int main(int argc, char *argv[]) {

	Rectangle r( POINT{1,2},POINT{4,5},"Joe" );
	Ellipse e(POINT{ 1,2 }, POINT{ 4,5 },"El");
	Circle c(POINT{ 1,2 }, "Circ2");

	//c.get_rx();
	c.getArea();


	return 0;
}