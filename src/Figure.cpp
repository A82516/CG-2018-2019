//
// Created by Diogo Sobral on 2019-02-26.
//

#include "headers/Figure.h"
#include "Point.cpp"

void Figure::shpere_vertex(float radius,int slices,int stacks){
    int i=0;
    float alpha;
    float beta;
    Point *p1,*p2,*p3;

    for(int k = 0; k < stacks ; k++){
        for(i=0; i < slices;i++){
            alpha = 2*M_PI / slices;
            beta = M_PI / stacks;

            p1 = new Point(radius*cos(i*alpha)*cos(k*beta - (M_PI / 2)),radius*sin(k*beta - (M_PI / 2)),radius*sin(i*alpha)*cos(k*beta- (M_PI / 2)));
            p2 = new Point(radius*cos(i*alpha)*cos((k+1)*beta- (M_PI / 2)),radius*sin((k+1)*beta- (M_PI / 2)),radius*sin(i*alpha)*cos((k+1)*beta- (M_PI / 2)));
            p3 = new Point(radius*cos((i+1)*alpha)*cos(k*beta- (M_PI / 2)) ,radius*sin(k*beta- (M_PI / 2)) ,radius*sin((i+1)*alpha)*cos(k*beta- (M_PI / 2)));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point(radius*cos(i*alpha)*cos((k+1)*beta- (M_PI / 2)),radius*sin((k+1)*beta- (M_PI / 2)),radius*sin(i*alpha)*cos((k+1)*beta- (M_PI / 2)));
            p2 = new Point(radius*cos((i+1)*alpha)*cos((k+1)*beta- (M_PI / 2)) ,radius*sin((k+1)*beta- (M_PI / 2)) ,radius*sin((i+1)*alpha)*cos((k+1)*beta- (M_PI / 2)));
            p3 = new Point(radius*cos((i+1)*alpha)*cos(k*beta- (M_PI / 2)) ,radius*sin(k*beta- (M_PI / 2)) ,radius*sin((i+1)*alpha)*cos(k*beta- (M_PI / 2)));

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
    }
    glEnd();
}

void Figure::torus_vertex(float radius_outside,float radius_inside,int slices,int stacks){
    float teta, fi;
    Point *p1,*p2,*p3;

    for(int i = 0; i < stacks ; i++){
        for(int j = 0; j < slices ; j++){
            teta = (2 * M_PI) / slices;
            fi = (2 * M_PI) / stacks;


            p1 = new Point((radius_outside + radius_inside*cos(j*teta))*cos(i*fi),radius_inside*sin(j*teta),(radius_outside + radius_inside*cos(j*teta))*sin(i*fi));
            p2 = new Point((radius_outside + radius_inside*cos((j+1)*teta))*cos(i*fi),radius_inside*sin((j+1)*teta),(radius_outside + radius_inside*cos((j+1)*teta))*sin(i*fi));
            p3 = new Point((radius_outside + radius_inside*cos(j*teta))*cos((i+1)*fi),radius_inside*sin(j*teta),(radius_outside + radius_inside*cos(j*teta))*sin((i+1)*fi));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point((radius_outside + radius_inside*cos((j+1)*teta))*cos(i*fi),radius_inside*sin((j+1)*teta),(radius_outside + radius_inside*cos((j+1)*teta))*sin(i*fi));
            p2 = new Point((radius_outside + radius_inside*cos((j+1)*teta))*cos((i+1)*fi),radius_inside*sin((j+1)*teta),(radius_outside + radius_inside*cos((j+1)*teta))*sin((i+1)*fi));
            p3 = new Point((radius_outside + radius_inside*cos(j*teta))*cos((i+1)*fi),radius_inside*sin(j*teta),(radius_outside + radius_inside*cos(j*teta))*sin((i+1)*fi));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);
        }
    }
}

void Figure::box_vertex(float x,float y,float z,int partitions){
    float dx,dy,dz,sX,sY,sZ;

    dx = x / partitions;
    dy = y / partitions;
    dz = z / partitions;

    sX = -x/2;
    sY = -y/2;
    sZ = -z/2;

    int i,j;
    for(i = 0; i < partitions; i++){
        for(j = 0; j < partitions; j++){
            //Face Frente
            pontos->push_back(new Point(x/2,i*dy + sY,j*dz + sZ));
            pontos->push_back(new Point(x/2,(i+1)*dy + sY,j*dz + sZ));
            pontos->push_back(new Point(x/2,i*dy + sY,(j+1)*dz + sZ));

            pontos->push_back(new Point(x/2,(i+1)*dy + sY,j*dz + sZ));
            pontos->push_back(new Point(x/2,(i+1)*dy + sY,(j+1)*dz + sZ));
            pontos->push_back(new Point(x/2,i*dy + sY,(j+1)*dz + sZ));

            //Face trás
            pontos->push_back(new Point(-x/2,i*dy + sY,j*dz + sZ));
            pontos->push_back(new Point(-x/2,i*dy + sY,(j+1)*dz + sZ));
            pontos->push_back(new Point(-x/2,(i+1)*dy + sY,j*dz + sZ));

            pontos->push_back(new Point(-x/2,i*dy + sY,(j+1)*dz + sZ));
            pontos->push_back(new Point(-x/2,(i+1)*dy + sY,(j+1)*dz + sZ));
            pontos->push_back(new Point(-x/2,(i+1)*dy + sY,j*dz + sZ));

            //Face lateral frente
            pontos->push_back(new Point(j*dx + sX,i*dy + sY,z/2));
            pontos->push_back(new Point((j+1)*dx + sX,i*dy + sY,z/2));
            pontos->push_back(new Point(j*dx + sX,(i+1)*dy + sY,z/2));

            pontos->push_back(new Point((j+1)*dx + sX,i*dy + sY,z/2));
            pontos->push_back(new Point((j+1)*dx + sX,(i+1)*dy + sY,z/2));
            pontos->push_back(new Point(j*dx + sX,(i+1)*dy + sY,z/2));

            //Face lateral trás
            pontos->push_back(new Point((j+1)*dx + sX,i*dy + sY,-z/2));
            pontos->push_back(new Point(j*dx + sX,i*dy + sY,-z/2));
            pontos->push_back(new Point(j*dx + sX,(i+1)*dy + sY,-z/2));

            pontos->push_back(new Point(j*dx + sX,(i+1)*dy + sY,-z/2));
            pontos->push_back(new Point((j+1)*dx + sX,(i+1)*dy + sY,-z/2));
            pontos->push_back(new Point((j+1)*dx + sX,i*dy + sY,-z/2));

            //Face cima
            pontos->push_back(new Point(j*dx + sX,y/2,i*dz + sZ));
            pontos->push_back(new Point(j*dx + sX,y/2,(i+1)*dz + sZ));
            pontos->push_back(new Point((j+1)*dx + sX,y/2,(i+1)*dz + sZ));

            pontos->push_back(new Point((j+1)*dx + sX,y/2,i*dz + sZ));
            pontos->push_back(new Point(j*dx + sX,y/2,i*dz + sZ));
            pontos->push_back(new Point((j+1)*dx + sX,y/2,(i+1)*dz + sZ));

            //Face baixo
            pontos->push_back(new Point((j+1)*dx + sX,-y/2,(i+1)*dz + sZ));
            pontos->push_back(new Point(j*dx + sX,-y/2,(i+1)*dz + sZ));
            pontos->push_back(new Point(j*dx + sX,-y/2,i*dz + sZ));

            pontos->push_back(new Point(j*dx + sX,-y/2,i*dz + sZ));
            pontos->push_back(new Point((j+1)*dx + sX,-y/2,i*dz + sZ));
            pontos->push_back(new Point((j+1)*dx + sX,-y/2,(i+1)*dz + sZ));
        }
    }
}


void cleanVector(vector<Point*> * limpar){
    vector<Point*>::iterator it;
    for(it = limpar->begin(); it != limpar->end(); it++){
        delete((*it));
    }
    delete(limpar);
}

