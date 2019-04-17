//
// Created by Diogo Sobral on 2019-04-16.
//

#include "../headers/Polygon.h"


void Polygon::shpere_vertex(float radius,int slices,int stacks){
    int i=0;
    float alpha,d_alpha;
    float beta,d_beta;
    Point *p1,*p2,*p3;

    for(int k = 0; k < stacks ; k++){
        for(i=0; i < slices;i++){
            alpha = i*(2*M_PI / slices);
            beta = k*(M_PI / stacks) - (M_PI / 2);
            d_alpha =(2*M_PI / slices);
            d_beta = (M_PI / stacks);

            p1 = new Point(radius*cos(alpha)*cos(beta ),radius*sin(beta ),radius*sin(alpha)*cos(beta));
            p2 = new Point(radius*cos(alpha)*cos(beta + d_beta),radius*sin(beta + d_beta),radius*sin(alpha)*cos(beta + d_beta));
            p3 = new Point(radius*cos(alpha + d_alpha)*cos(beta) ,radius*sin(beta) ,radius*sin(alpha + d_alpha)*cos(beta));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point(radius*cos(alpha)*cos(beta + d_beta),radius*sin(beta + d_beta),radius*sin(alpha)*cos(beta + d_beta));
            p2 = new Point(radius*cos(alpha + d_alpha)*cos(beta + d_beta) ,radius*sin(beta + d_beta) ,radius*sin(alpha + d_alpha)*cos(beta + d_beta));
            p3 = new Point(radius*cos(alpha + d_alpha)*cos(beta) ,radius*sin(beta) ,radius*sin(alpha + d_alpha)*cos(beta));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);
        }
    }
}

Polygon::Polygon(){
    pontos = new vector<Point*>();
}

void Polygon::cone_vertex(float radius,float height,int slices,int stacks){
    float angle, height_act = 0, height_next = 0, radius_act = 0, radius_next = 0,d_alpha;
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

void Polygon::plane_vertex(float size) {
    Point *p1,*p2,*p3;

    p1 = new Point(size,0,size);
    p2 = new Point(size,0,-size);
    p3 = new Point(-size,0,-size);

    pontos->push_back(p1);
    pontos->push_back(p2);
    pontos->push_back(p3);


    p1 = new Point(size,0,size);
    p2 = new Point(-size,0,-size);
    p3 = new Point(-size,0,size);

    pontos->push_back(p1);
    pontos->push_back(p2);
    pontos->push_back(p3);
}

void Polygon::torus_vertex(float radius_outside,float radius_inside,int slices,int stacks){
    float teta, fi,d_teta,d_fi;
    Point *p1,*p2,*p3;

    for(int i = 0; i < stacks ; i++){
        for(int j = 0; j < slices ; j++){
            teta = j * (2 * M_PI) / slices;
            fi = i * (2 * M_PI) / stacks;
            d_teta = (2 * M_PI) / slices;
            d_fi = (2 * M_PI) / stacks;


            p1 = new Point((radius_outside + radius_inside*cos(teta))*cos(fi),radius_inside*sin(teta),(radius_outside + radius_inside*cos(teta))*sin(fi));
            p2 = new Point((radius_outside + radius_inside*cos(teta + d_teta))*cos(fi),radius_inside*sin(teta + d_teta),(radius_outside + radius_inside*cos(teta + d_teta))*sin(fi));
            p3 = new Point((radius_outside + radius_inside*cos(teta))*cos(fi + d_fi),radius_inside*sin(teta),(radius_outside + radius_inside*cos(teta))*sin(fi + d_fi));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point((radius_outside + radius_inside*cos(teta + d_teta))*cos(fi),radius_inside*sin(teta + d_teta),(radius_outside + radius_inside*cos(teta + d_teta))*sin(fi));
            p2 = new Point((radius_outside + radius_inside*cos(teta + d_teta))*cos(fi + d_fi),radius_inside*sin(teta + d_teta),(radius_outside + radius_inside*cos(teta + d_teta))*sin(fi + d_fi));
            p3 = new Point((radius_outside + radius_inside*cos(teta))*cos(fi + d_fi),radius_inside*sin(teta),(radius_outside + radius_inside*cos(teta))*sin(fi + d_fi));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);
        }
    }
}

void Polygon::box_vertex(float x,float y,float z,int partitions){
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

void Polygon::cylinder_vertex(float radius, float height,int slices,int stacks){
    float alpha,beta;


    int i,j;

    for(j = 0; j <= stacks; j++){
        beta = (j * (height / stacks)) - height/2;
        for(i = 0; i < slices; i++){
            alpha = i * (2*M_PI) / slices;

            if (j == stacks){
                pontos->push_back(new Point(radius*cos(alpha),height/2,radius*sin(alpha)));
                pontos->push_back(new Point(0,height/2,0));
                pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),height/2,radius*sin(alpha + (2*M_PI) / slices)));
            }
            else {
                if (j == 0){
                    pontos->push_back(new Point(0,-height/2,0));
                    pontos->push_back(new Point(radius*cos(alpha),-height/2,radius*sin(alpha)));
                    pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),-height/2,radius*sin(alpha + (2*M_PI) / slices)));
                }

                pontos->push_back(new Point(radius*cos(alpha),beta,radius*sin(alpha)));
                pontos->push_back(new Point(radius*cos(alpha),beta + (height / stacks),radius*sin(alpha)));
                pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),beta,radius*sin(alpha + (2*M_PI) / slices)));

                pontos->push_back(new Point(radius*cos(alpha),beta + (height / stacks),radius*sin(alpha)));
                pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),beta + (height / stacks),radius*sin(alpha + (2*M_PI) / slices)));
                pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),beta,radius*sin(alpha + (2*M_PI) / slices)));
            }
        }
    }
}
vector<Point*> * Polygon::getPontos(){
    return pontos;
}

Polygon::Polygon(vector<Point*> * v){
    pontos = v;
}

Polygon::~Polygon(){
    delete(pontos);
}

Point * Polygon::brezierValue(float u, Point * p0,Point * p1,Point * p2,Point * p3){
    float b0 = (1.0 - u) * (1.0 - u) * (1.0 - u);
    float b1 = 3.0 * u * (1.0 - u) * (1.0 - u);
    float b2 = 3 * u * u * (1.0 - u);
    float b3 = u * u * u;

    float x = p0->getX()*b0 + p1->getX()*b1 + p2->getX()*b2 +  p3->getX()*b3;
    float y = p0->getY()*b0 + p1->getY()*b1 + p2->getY()*b2 +  p3->getY()*b3;
    float z = p0->getZ()*b0 + p1->getZ()*b1 + p2->getZ()*b2 +  p3->getZ()*b3;

    return new Point(x,y,z);
}

Point * Polygon::brezierPatch(float u, float v,Patch * patch){
    Point * u_points [4];
    Point * v_points [4];

    int j = 0, k = 0;

    for(int i = 0; i < 16; i++){
        Point * aux = patch->pointAt(i);
        u_points[j] = aux;
        j++;

        if (j % 4 == 0){
            v_points[k++] = brezierValue(u,u_points[0],u_points[1],u_points[2],u_points[3]);

            j = 0;
        }
    }

    Point * res = brezierValue(v,v_points[0],v_points[1],v_points[2],v_points[3]);

    /**
    for(int i= 0; i < 4; i++)
        delete(v_points[i]);*/

    return res;
}

void Polygon::brezierPoints(vector<Patch *> * patches, int tessellation){
    float divisons = 1.0 / tessellation,u,u2,v,v2;

    for(int k = 0; k < patches->size(); k++) {
        Patch * p = patches->at(k);

        for (int i = 0; i < tessellation; i++) {
            for (int j = 0; j < tessellation; j++) {

                u = j * divisons;
                v = i * divisons;
                u2 = (j+1) * divisons;
                v2 = (i+1) * divisons;

                Point * p1 = brezierPatch(u,v,p);
                Point * p2 = brezierPatch(u2,v,p);
                Point * p3 = brezierPatch(u,v2,p);
                Point * p4 = brezierPatch(u2,v2,p);


                pontos->push_back(p2);
                pontos->push_back(p1);
                pontos->push_back(p4);

                pontos->push_back(p1);
                pontos->push_back(p3);
                pontos->push_back(p4);
            }
        }
    }
}