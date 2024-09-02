#include <cmath>
#include <iostream>

class Vector{
	public:
		float x, y;
		Vector() {}// I don't know what is this.
		Vector(float X, float Y){ //Constructor, set in value to what is pass in the parameter.
			x = X;
			y = Y;
		};
		float Length() const;
		float LengthSqr() const;

		//Wierd I have to declare these vector overload here unlike the subtraction operator,
		//Vector operator-(Point a, Point b){...
		//	I think its because its a kind of operation where it happens to be a Vector against a Scalar,
		//	and not a Vector on Vector action.
		Vector operator*(float s) const;
		Vector operator/(float s) const:
};

float Vector::Length() const{
	float length;
	length = sqrt(x*x+y*y);
	return length;
};

float Vector::LengthSqr() const{ //length but squared, D^2 = x^2 + y^2 in our pythagorean class.
	float length;
	length = x*x+y*y;
	return length;
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

	Point c; //(2,-1)
	c.x = 2;
	c.y = -1;

	Vector cp;
	Vector ip;

	cp = p - c;
	ip = p - i;

	float length_sqr_cp = cp.LengthSqr();
	float length_sqr_ip = ip.LengthSqr();

	std::cout << "Length: " << length_sqr_cp << "\n";
	std::cout << "Length: " << length_sqr_ip << "\n";
	return 0;
};
