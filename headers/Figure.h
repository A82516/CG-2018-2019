

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#ifndef __FIGURES__H
#define __FIGURES__H

#include <vector>
#include "Point.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Transformation.h"



class Figure {
    GLuint buffer[1]; // 0 é para pontos
    int n_vertex;
    float rgb[3];
	vector<Transformation*> * transformacoes;

    public:
        Figure(vector<Point*> * v,vector<Transformation*> &trans);
        void draw();
        virtual ~Figure();
};

void cleanVector(vector<Point*> * limpar);


#endif
