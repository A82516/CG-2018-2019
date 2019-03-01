//
// Created by Diogo Sobral on 2019-02-26.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#ifndef __FIGURES__H
#define __FIGURES__H

#include <vector>
#include "Point.h"
#include <iostream>
#include <vector>


class Figure {
    vector<Point*> * pontos;

    public:
        Figure();
        void shpere_vertex(float radius,int slices,int stacks);
        void cone_vertex(float radius,float height,int slices,int stacks);
        void plane_vertex();
        vector<Point*>* getPontos();
        void draw();

};


#endif //CG_TRABALHO_FIGURES_H
