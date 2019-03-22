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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h"
#include "Transformation.h"



class Figure {
    vector<Point*> * pontos;
	vector<Transformation*> * transformacoes;
	vector<Point*> * cores;

    public:
        Figure();
        Figure(vector<Point*> * v);
        Figure(vector<Point*> * v,vector<Transformation*> &trans);
        void shpere_vertex(float radius,int slices,int stacks);
        void cone_vertex(float radius,float height,int slices,int stacks);
        void plane_vertex(float size);
        void torus_vertex(float radius_outside,float radius_inside,int slices,int stacks);
        void box_vertex(float x,float y,float z,int partitions);
		void cylinder_vertex(float radius, float height,int slices,int stacks);
        vector<Point*>* getPontos();
        void draw();
        virtual ~Figure();

};

void cleanVector(vector<Point*> * limpar);
void rgbToDecimal(float v[6][3],int y,float dest[3]);


#endif
