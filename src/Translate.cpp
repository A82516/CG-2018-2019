//
// Created by Diogo Sobral on 2019-04-15.
//

#include "../headers/Translate.h"

Translate::Translate() : Transformation() {
    control_points = new vector<Point*>();
}

Translate::Translate(Translate * t) : Transformation() {
    control_points = new vector<Point*>();
    vector<Point *>::iterator it1;
    for(it1 = (t->control_points)->begin(); it1 != (t->control_points)->end(); it1++){
        Point * p = (*it1);
        control_points->push_back(new Point (p->getX(),p->getY(),p->getZ()));
    }
}

Translate::~Translate() {};

Transformation* Translate::clone() {
    return new Translate(this);
}

void Translate::addPoint(Point *p) {
    control_points->push_back(p);
}


void Translate::perform() {
    // só tens que mexer aqui
}