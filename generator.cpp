//
// Created by Diogo Sobral on 2019-02-26.
//

#include "headers/Point.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>



void shpere_vertex(float radius,int slices,int stacks,vector<Point*>&vertices){
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

            vertices.push_back(p1);
            vertices.push_back(p2);
            vertices.push_back(p3);

            p1 = new Point(radius*cos(i*alpha)*cos((k+1)*beta),radius*sin((k+1)*beta),radius*sin(i*alpha)*cos((k+1)*beta));
            p2 = new Point(radius*cos((i+1)*alpha)*cos((k+1)*beta) ,radius*sin((k+1)*beta) ,radius*sin((i+1)*alpha)*cos((k+1)*beta));
            p3 = new Point(radius*cos((i+1)*alpha)*cos(k*beta) ,radius*sin(k*beta) ,radius*sin((i+1)*alpha)*cos(k*beta));

            vertices.push_back(p1);
            vertices.push_back(p2);
            vertices.push_back(p3);
        }
    }
}

void write_file(string path,vector<Point*> &vertices){

    ofstream outputFile;
    outputFile.open(path);

    vector<Point*>::iterator it;
    for(it = vertices.begin(); it != vertices.end(); it++){
        outputFile << (*(*it)).to_String() << endl;
        delete((*it));
    }

    outputFile.close();
}

int main(){

    vector<Point*> vec;
    shpere_vertex(1,10,10,vec);
    write_file("/Users/Ambrosiny/Desktop/Universidade/3ano/CG/trabalho/shpere.3d",vec);
}