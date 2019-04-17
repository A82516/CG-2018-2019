#include "../headers/Rotate.h"
#include <math.h>
#include <cstdio>

Rotate::Rotate(float time, int v[3]) : Transformation() {
    for(int i = 0; i < 3; i++){
        this->axis[i] = v[i];
    }
    this->time = time;
}

Rotate::Rotate(Rotate * t) : Transformation() {
    for(int i = 0; i < 3; i++){
        axis[i] = t->axis[i];
    }
    time = t->time;
}

Rotate::~Rotate(){};

Transformation* Rotate::clone() {
    return new Rotate(this);
}


void Rotate::perform() {
    float i, angle = 360*modf((glutGet(GLUT_ELAPSED_TIME)/ (double) (time * 1000)), &i);
    glRotatef(angle, axis[0], axis[1], axis[2]);
}