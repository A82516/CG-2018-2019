//
// Created by Diogo Sobral on 2019-04-16.
//

#include <vector>
#include "Point.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef GENERATOR_POLYGON_H
#define GENERATOR_POLYGON_H


class Polygon {
    vector<Point*> * pontos;

public:
    Polygon();
    Polygon(vector<Point*> * v);
    vector<Point*> * getPontos();
    void shpere_vertex(float radius,int slices,int stacks);
    void cone_vertex(float radius,float height,int slices,int stacks);
    void plane_vertex(float size);
    void torus_vertex(float radius_outside,float radius_inside,int slices,int stacks);
    void box_vertex(float x,float y,float z,int partitions);
    void cylinder_vertex(float radius, float height,int slices,int stacks);
    virtual ~Polygon();

};


#endif //GENERATOR_POLYGON_H
