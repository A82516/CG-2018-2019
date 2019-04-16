//
// Created by Diogo Sobral on 2019-03-22.
//
#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


class Transformation {

    public:
        Transformation();
        //Transformation(int type, float v[3]);
        //Transformation(int type, int v[3], float angle);
        //Transformation(Transformation *t);
        virtual ~Transformation();
        virtual Transformation* clone();
        virtual void perform();

};


#endif //GENERATOR_TRANSFORMATION_H
