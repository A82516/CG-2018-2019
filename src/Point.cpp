#include "../headers/Point.h"

Point::Point(float a,float b, float c){
	x = a;
	y = b;
	z = c;
}

float Point::getX(){
	return x;
}

float Point::getY(){
	return y;
}

float Point::getZ(){
	return z;
}

string Point::to_String(){
	stringstream ss;

	ss << to_string(x) << " " << to_string(y) << " " << to_string(z);

	return ss.str();
}

Point::~Point(){}
