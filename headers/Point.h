#ifndef __POINT_H__
#define __POINT_H__

#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Point{

	float x;
	float y;
	float z;

	public:
		Point(float x,float y,float z);
		float getX();
		float getY();
		float getZ();
		string to_String();
		virtual ~Point();
};

#endif
