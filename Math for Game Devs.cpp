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
		Vector operator/(float s) const;

		Vector Normalized() const;
};

Vector Vector::Normalized() const{
	Vector normalized;
	normalized = (*this)/Length();
	return normalized;
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
		Point () {}
		Point(float X, float Y){
			x = X;
			y = Y;
		}
		Point addVector(Vector v);
		float x,y;
};

Vector Vector::operator*(float s) const{
	Vector scaled;
	scaled.x = x * s;
	scaled.y = y * s;
	return scaled;
};

Vector Vector::operator/(float s) const{
	Vector scaled;
	scaled.x = x / s;
	scaled.y = y / s;
	return scaled;
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
	Point i(3,4);
	Point p(1,2);
	Vector pi = i-p;
	Vector normalized = pi.Normalized();
	std::cout << "Pac-man's view vector: (" << normalized.x << ", " << normalized.y << ")\n";
	std::cout << "Pac-man's view vector length: " << normalized.Length() << "\n";
	return 0;
};
