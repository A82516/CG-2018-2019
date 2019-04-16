//
// Created by Diogo Sobral on 2019-04-15.
//

#include "../headers/Translate.h"

Translate::Translate(float v[3]) : Transformation() {
    for(int i = 0; i < 3; i++){
        this->translate[i] = v[i];
    }
}

Translate::Translate(Translate * t) : Transformation() {
    for(int i = 0; i < 3; i++){
        translate[i] = t->translate[i];
    }
}

Translate::~Translate() {};

Transformation* Translate::clone() {
    return new Translate(this);
}


void Translate::perform() {
    glTranslatef(translate[0],translate[1],translate[2]);
}