//
// Created by Diogo Sobral on 2019-03-22.
//

#include "../headers/Transformation.h"


Transformation::Transformation(int type, float v[3]) {
    this->type = type;
    for(int i = 0; i < 3; i++){
        if (type == 0)
            translate[i] = v[i];
        else if (type == 1) scale[i] = v[i];
    }
}

Transformation::Transformation(int type, int *v, float angle) {
    this->type = type;
    this->angle = angle;
    for(int i = 0; i < 3; i++){
        if (type == 2)
            rotate[i] = v[i];
    }
}

Transformation::Transformation(Transformation *t) {
    this->type = t->type;
    this->angle = t->angle;

    for(int i = 0; i < 3; i++){
        translate[i] = t->translate[i];
        scale[i] = t->scale[i];
        rotate[i] = t->rotate[i];
    }
}

void Transformation::perform() {
    if (type == 0)
        glTranslatef(translate[0],translate[1],translate[2]);
    else if (type == 1)
        glScalef(scale[0],scale[1],scale[2]);
    else if (type == 2)
        glRotatef(angle,rotate[0],rotate[1],rotate[2]);
}

Transformation::~Transformation() {};

Transformation* Transformation::clone() {
    return new Transformation(this);
}
