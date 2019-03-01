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

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point(radius*cos(i*alpha)*cos((k+1)*beta),radius*sin((k+1)*beta),radius*sin(i*alpha)*cos((k+1)*beta));
            p2 = new Point(radius*cos((i+1)*alpha)*cos((k+1)*beta) ,radius*sin((k+1)*beta) ,radius*sin((i+1)*alpha)*cos((k+1)*beta));
            p3 = new Point(radius*cos((i+1)*alpha)*cos(k*beta) ,radius*sin(k*beta) ,radius*sin((i+1)*alpha)*cos(k*beta));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);
        }
    }
}

vector<Point*>* Figure::getPontos(){
    vector<Point*> * fim = new vector<Point*>((*pontos));
    return fim;
}

Figure::Figure(){
    pontos = new vector<Point*>();
}

void Figure::cone_vertex(float radius,float height,int slices,int stacks){
    float angle, height_act = 0, height_next = 0, radius_act = 0, radius_next = 0;
    int k = 0,i;

    Point *p1,*p2,*p3;

    //base
    for(i = 0; i < slices; i++){
        angle = i * ((2*M_PI) / slices);
        p1 = new Point(radius*cos(angle + ((2*M_PI) / slices)),0,radius*sin(angle + ((2*M_PI) / slices)));
        p2 = new Point(0,0,0);
        p3 = new Point(radius*cos(angle),0,radius*sin(angle));

        pontos->push_back(p1);
        pontos->push_back(p2);
        pontos->push_back(p3);
    }

    for(i = 0; i < slices; i++){
        for(k = 0; k < stacks - 1; k++){
            height_act = k * (height / stacks);
            height_next = (k+1) * (height / stacks);
            radius_act = (radius * (height - height_act)) / height;
            radius_next = (radius * (height - height_next)) / height;
            angle = i * ((2*M_PI) / slices);

            p1 = new Point(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));
            p2 = new Point(radius_act*cos(angle),height_act,radius_act*sin(angle));
            p3 = new Point(radius_next*cos(angle),height_next,radius_next*sin(angle));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point(radius_next*cos(angle),height_next,radius_next*sin(angle));
            p2 = new Point(radius_next*cos(angle + ((2*M_PI) / slices)),height_next,radius_next*sin(angle + ((2*M_PI) / slices)));
            p3 = new Point(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);
        }
    }

    for(i = 0; i < slices; i++){
        height_act = k * (height / stacks);
        radius_act = (radius * (height - height_act)) / height;
        angle = i * ((2*M_PI) / slices);

        p1 = new Point(0,height,0);
        p2 = new Point(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));
        p3 = new Point(radius_act*cos(angle),height_act,radius_act*sin(angle));

        pontos->push_back(p1);
        pontos->push_back(p2);
        pontos->push_back(p3);
    }
}

void Figure::plane_vertex() {
    Point *p1,*p2,*p3;

    p1 = new Point(2,0,2);
    p2 = new Point(2,0,-2);
    p3 = new Point(-2,0,-2);

    pontos->push_back(p1);
    pontos->push_back(p2);
    pontos->push_back(p3);


    p1 = new Point(2,0,2);
    p2 = new Point(-2,0,-2);
    p3 = new Point(-2,0,2);

    pontos->push_back(p1);
    pontos->push_back(p2);
    pontos->push_back(p3);

    p1 = new Point(2,0,2);
    p2 = new Point(-2,0,-2);
    p3 = new Point(2,0,-2);

    pontos->push_back(p1);
    pontos->push_back(p2);
    pontos->push_back(p3);

    p1 = new Point(2,0,2);
    p2 = new Point(-2,0,2);
    p3 = new Point(-2,0,-2);

    pontos->push_back(p1);
    pontos->push_back(p2);
    pontos->push_back(p3);
}

void Figure::draw() {
    glBegin(GL_TRIANGLES);

    vector<Point*>::iterator it;
    for(it = pontos->begin(); it != pontos->end(); it++){
        Point * p = (*it);
        glVertex3f(p->getX(),p->getY(),p->getZ());
        cout << p->to_String() << endl;
    }
    glEnd();
}

