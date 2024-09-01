#include <iostream>

class Vector{
	public:
		float x,y;
};

class Point{
	public:
		Point addVector(Vector v);
		float x,y;
};

Point Point::addVector(Vector v){
	Point p2;
	p2.x = x + v.x;
	p2.y = y + v.y;
	return p2;
};

int main(int argc, char** args){
	Point p; //(1,0)
	p.x = 1;
	p.y = 0;

	Vector v; //(2,3)
	v.x = 2;
	v.y = 3;

	Point p2 = p.addVector(v);
	std::cout << "Result: (" << p2.x << ", " << p2.y << ")\n"; //expected output (3,3)
	return 0;
};
