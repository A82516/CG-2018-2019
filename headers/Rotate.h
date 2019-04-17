#ifndef ROTATE_H
#define ROTATE_H


#include "Transformation.h"

class Rotate : public Transformation {
    int axis[3];
    float time;

public: Rotate(float time, int v[3]);
    Rotate(Rotate * t);
    ~Rotate();
    Transformation* clone();
    void perform();

};

#endif
