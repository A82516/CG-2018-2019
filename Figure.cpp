//
// Created by Diogo Sobral on 2019-02-26.
//

#include "headers/Figure.h"

void Figure::shpere_vertex(float radius,int slices,int stacks){
    int i=0;
    float alpha = 2*M_PI / slices;
    float beta = M_PI / stacks;
    Point *p1,*p2,*p3;


    for(int k = -(stacks / 2) ; k < (stacks / 2); k++){

        for(i=0; i < slices;i++){
            alpha = 2*M_PI / slices;
            beta = M_PI / stacks;

            p1 = new Point(radius*cos(i*alpha)*cos(k*beta),radius*sin(k*beta),radius*sin(i*alpha)*cos(k*beta));
            p2 = new Point(radius*cos(i*alpha)*cos((k+1)*beta),radius*sin((k+1)*beta),radius*sin(i*alpha)*cos((k+1)*beta));
            p3 = new Point(radius*cos((i+1)*alpha)*cos(k*beta) ,radius*sin(k*beta) ,radius*sin((i+1)*alpha)*cos(k*beta));

            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);

            p1 = new Point(radius*cos(i*alpha)*cos((k+1)*beta),radius*sin((k+1)*beta),radius*sin(i*alpha)*cos((k+1)*beta));
            p2 = new Point(radius*cos((i+1)*alpha)*cos((k+1)*beta) ,radius*sin((k+1)*beta) ,radius*sin((i+1)*alpha)*cos((k+1)*beta));
            p3 = new Point(radius*cos((i+1)*alpha)*cos(k*beta) ,radius*sin(k*beta) ,radius*sin((i+1)*alpha)*cos(k*beta));

            pontos.push_back(p1);
            pontos.push_back(p2);
            pontos.push_back(p3);
        }
    }
}

vector<Point*> Figure::getPontos(){
    return pontos;
}

Figure::Figure(vector<Point *> v) : pontos(v){}
