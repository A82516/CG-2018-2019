

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <stdlib.h>
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
#include "Material.h"



class Figure {
    GLuint buffer[2]; // 0 é para pontos
    int n_vertex;
	vector<Transformation*> * transformacoes;
	vector<Material*> * materials;

    public:
        Figure(vector<Point*> * v,vector<Transformation*> &trans,vector<Point*>* normal,vector<Material*> *  mat );
        void draw();
        virtual ~Figure();
};

void cleanVector(vector<Point*> * limpar);


#endif
