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

//operator overload function
Vector operator-(Point a, Point b){
	Vector v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	return v;
};

Point Point::addVector(Vector v){
	Point p2;
	p2.x = x + v.x;
	p2.y = y + v.y;
	return p2;
};

int main(int argc, char** args){
	Point p; //(0,-1) Pacman's position
	p.x = 0;
	p.y = -1;

	Point i; //(1,1) Inky's position
	i.x = 1;
	i.y = 1;

	Vector v;
	v = p - i;

	std::cout << "Result: (" << v.x << ", " << v.y << ")\n"; //expected output (-1,-2)
	return 0;
};
