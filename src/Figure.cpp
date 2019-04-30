

#include "../headers/Figure.h"

void Figure::draw() {
    glPushMatrix();

    vector<Transformation*>::iterator it1;
    for(it1 = transformacoes->begin(); it1 != transformacoes->end(); it1++){
        (*it1)->perform();
    }

    vector<Material*>::iterator it2;
    for(it2 = materials->begin(); it2 != materials->end(); it2++){
        (*it2)->perform();
    }


    glBindBuffer(GL_ARRAY_BUFFER,buffer[0]);
    glVertexPointer(3,GL_FLOAT,0,0);

    glBindBuffer(GL_ARRAY_BUFFER,buffer[1]);
    glNormalPointer(GL_FLOAT,0,0);

    glDrawArrays(GL_TRIANGLES, 0, n_vertex * 3);

    glPopMatrix();
}


Figure::Figure(vector<Point*> * v,vector<Transformation*> &trans,vector<Point*> * normal,vector<Material*> *  mat){
    materials = mat;

    transformacoes = new vector<Transformation*>();
    vector<Transformation*>::iterator it;
    for(it = trans.begin(); it != trans.end(); it++){
        transformacoes->push_back((*it)->clone());
    }


    n_vertex = v->size();
	float * array_vertexs = (float *) malloc(sizeof(float) * 3 * n_vertex);
	float * array_normal = (float *) malloc(sizeof(float) * 3 * n_vertex);

    vector<Point*>::iterator point_it;
    int vertex = 0;
    for(point_it = v->begin(); point_it != v->end(); point_it++){
        Point * p = (*point_it);
        array_vertexs[vertex*3 + 0] = p->getX();
        array_vertexs[vertex*3 + 1] = p->getY();
        array_vertexs[vertex*3 + 2] = p->getZ();

        vertex++;
    }
    vertex = 0;
    for(point_it = normal->begin(); point_it != normal->end(); point_it++){
        Point * p = (*point_it);
        array_normal[vertex*3 + 0] = p->getX();
        array_normal[vertex*3 + 1] = p->getY();
        array_normal[vertex*3 + 2] = p->getZ();

        vertex++;
    }

    cleanVector(v);
    cleanVector(normal);
    glGenBuffers(2,buffer);

    glBindBuffer(GL_ARRAY_BUFFER,buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex * 3,array_vertexs,GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER,buffer[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex * 3,array_normal,GL_STATIC_DRAW);

    free(array_vertexs);
    free(array_normal);
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
