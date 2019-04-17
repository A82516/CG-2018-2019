//
// Created by Diogo Sobral on 2019-04-15.
//

#ifndef TRANSLATE_H
#define TRANSLATE_H


#include "Transformation.h"
#include "Point.h"
#include <vector>

class Translate : public Transformation {
    vector<Point *> * control_points;

    public: Translate();
            void addPoint(Point * p);
            Translate(Translate * t);
            ~Translate();
            Transformation* clone();
            void perform();

};


#endif //TRANSLATE_H
