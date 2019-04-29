
#include <vector>
#include "Point.h"
#include "Patch.h"
#include "Translate.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef GENERATOR_POLYGON_H
#define GENERATOR_POLYGON_H


class Polygon {
    vector<Point*> * pontos;
    vector<Point*> * normal;

public:
    Polygon();
    Polygon(vector<Point*> * v);
    vector<Point*> * getPontos();
    vector<Point*> * getNormais();
    void shpere_vertex(float radius,int slices,int stacks);
    Point * getNormalCone(float edge [3], Point * p, float tangAlpha);
    void cone_vertex(float radius,float height,int slices,int stacks);
    void plane_vertex(float size);
    void torus_vertex(float radius_outside,float radius_inside,int slices,int stacks);
    void box_vertex(float x,float y,float z,int partitions);
    void cylinder_vertex(float radius, float height,int slices,int stacks);
    Point * dUBezier(Patch * patch, float u, float v, float res[3]);
    Point * dVBezier(Patch * patch, float u, float v, float res[3]);
    Point * brezierValue(float u, Point * p0,Point * p1,Point * p2,Point * p3);
    Point * brezierPatch(float u, float v,Patch * patch);
    void brezierPoints(vector<Patch *> * patches, int tessellation);
    virtual ~Polygon();

};

void vector_between_normalized(float p1[3],float p2[3],float res[3]);
float quadratic_equation(float middle,float p[3]);
float dist_2_P(float p1 [3],float p2 [3]);
void sumMatrix(float matrix [4][3],float res [3]);
void mulVect(float a,float res[3]);


#endif //GENERATOR_POLYGON_H
