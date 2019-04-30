

#ifndef _CAMERA_H
#define _CAMERA_H
#define _USE_MATH_DEFINES
#include <cmath>
#include "Point.h"

class Camera {
    Point * position;
    Point * lookup;
    Point * up;
    float alpha;
    float beta;
    float radius;
    float speed;

    public:
        Camera();
        Point * getPosition();
        Point * getLookup();
        Point * getUp();
        void updateCamera(float a,float b);
        ~Camera();
        void move(unsigned char c, int xx, int yy);

    private:
        void updateLookup();
        void updateUp();


};


#endif //GENERATOR_CAMERA_H
