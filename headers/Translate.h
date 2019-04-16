//
// Created by Diogo Sobral on 2019-04-15.
//

#ifndef TRANSLATE_H
#define TRANSLATE_H


#include "Transformation.h"

class Translate : public Transformation {
    float translate[3];

    public: Translate(float v[3]);
            Translate(Translate * t);
            ~Translate();
            Transformation* clone();
            void perform();

};


#endif //TRANSLATE_H
