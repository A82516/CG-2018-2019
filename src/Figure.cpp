//
// Created by Diogo Sobral on 2019-02-26.
//

#include "../headers/Figure.h"

void Figure::draw() {
    glPushMatrix();

    vector<Transformation*>::iterator it1;
    for(it1 = transformacoes->begin(); it1 != transformacoes->end(); it1++){
        (*it1)->perform();
    }

    glColor3f(1,0,0);
    glBindBuffer(GL_ARRAY_BUFFER,buffer[0]);
    glVertexPointer(3,GL_FLOAT,0,0);
    glDrawArrays(GL_TRIANGLES, 0, n_vertex * 3);

    glPopMatrix();
}


Figure::Figure(vector<Point*> * v,vector<Transformation*> &trans){
    transformacoes = new vector<Transformation*>();
    vector<Transformation*>::iterator it;
    for(it = trans.begin(); it != trans.end(); it++){
        transformacoes->push_back((*it)->clone());
    }

    n_vertex = v->size();
	float * array_vertexs = (float *) malloc(sizeof(float) * 3 * n_vertex);

    vector<Point*>::iterator point_it;
    int vertex = 0;
    for(point_it = v->begin(); point_it != v->end(); point_it++){
        Point * p = (*point_it);
        array_vertexs[vertex*3 + 0] = p->getX();
        array_vertexs[vertex*3 + 1] = p->getY();
        array_vertexs[vertex*3 + 2] = p->getZ();

        vertex++;
    }

    cleanVector(v);
    glGenBuffers(1,buffer);
    glBindBuffer(GL_ARRAY_BUFFER,buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex * 3,array_vertexs,GL_STATIC_DRAW);

    free(array_vertexs);
}

Figure::~Figure(){
    vector<Transformation*>::iterator it1;
    for(it1 = transformacoes->begin(); it1 != transformacoes->end(); it1++){
        delete((*it1));
    }
    delete(transformacoes);
}


void cleanVector(vector<Point*> * limpar){
    vector<Point*>::iterator it;
    for(it = limpar->begin(); it != limpar->end(); it++){
        delete((*it));
    }
    delete(limpar);
}

void rgbToDecimal(float v[6][3],int y,float dest[3]){
    for(int i= 0; i < 3; i++)
        dest[i] = v[y][i] / 255;
}
