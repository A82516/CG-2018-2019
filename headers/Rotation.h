//
// Created by Diogo Sobral on 2019-04-15.
//

#ifndef GENERATOR_ROTATION_H
#define GENERATOR_ROTATION_H

#include "Transformation.h"

class Rotation : public Transformation {
    int rotate[3];
    float angle;

public: Rotation(int v[3], float angle);
        Rotation(Rotation * t);
        ~Rotation();
        Transformation* clone();
        void perform();

};


#endif //GENERATOR_ROTATION_H
