//
// Created by Diogo Sobral on 2019-04-15.
//

#include "../headers/Rotation.h"

Rotation::Rotation(int v[3], float angle) : Transformation() {
    this->angle = angle;
    for(int i = 0; i < 3; i++){
        rotate[i] = v[i];
    }
}

Rotation::Rotation(Rotation * t) : Transformation() {
    this->angle = t->angle;
    for(int i = 0; i < 3; i++){
        rotate[i] = t->rotate[i];
    }
}

Rotation::~Rotation() {};

Transformation* Rotation::clone() {
    return new Rotation(this);
}


void Rotation::perform() {
    glRotatef(angle,rotate[0],rotate[1],rotate[2]);
}