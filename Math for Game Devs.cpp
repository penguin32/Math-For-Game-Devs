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

					//this ampersand & over hear means "pass by reference"
					//instead of making a copy of that vector, when function runs
					//it will actually use the vector thats passed into it.
		Vector operator+(const Vector& v) const;
		Vector operator-(const Vector& v) const;
					//const here means, not to change the reference that is passed in.
					//dont have to make a copy of the vector when you pass them

		//Wierd I have to declare these vector overload here unlike the subtraction operator,
		//Vector operator-(Point a, Point b){...
		//	I think its because its a kind of operation where it happens to be a Vector against a Scalar,
		//	and not a Vector on Vector action.
		Vector operator*(float s) const;
		Vector operator/(float s) const;

		Vector Normalized() const;
};

Vector Vector::operator+(const Vector& v) const{
	Vector r;
	r.x = x + v.x;
	r.y = y + v.y;
	return r;
}

Vector Vector::operator-(const Vector& v) const{
	return Vector(x-v.x,y-v.y);
}
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
	Vector r(4,0); //right vector
	Vector d(0,-5);//down vector
	Vector v = r + d;
	std::cout << "Pac-man's new velocity: (" << v.x << ", " << v.y << ")" << std::endl;
	return 0;
};
