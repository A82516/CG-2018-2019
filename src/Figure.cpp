//
// Created by Diogo Sobral on 2019-02-26.
//

#include "../headers/Figure.h"

Figure::Figure(){
    pontos = new vector<Point*>();
}

void Figure::draw() {
    glPushMatrix();

    vector<Transformation*>::iterator it1;
    for(it1 = transformacoes->begin(); it1 != transformacoes->end(); it1++){
        (*it1)->perform();
    }

    glBegin(GL_TRIANGLES);

    vector<Point*>::iterator it;
    vector<Point*>::iterator color_it;
	int i = 0;
    for(it = pontos->begin(); it != pontos->end() ; it++){
        Point * p = (*it);
        glVertex3f(p->getX(),p->getY(),p->getZ());
    }
    glEnd();
    glPopMatrix();
}


Figure::Figure(vector<Point*> * v,vector<Transformation*> &trans){
	pontos = v;

    transformacoes = new vector<Transformation*>();
    vector<Transformation*>::iterator it;
    for(it = trans.begin(); it != trans.end(); it++){
        transformacoes->push_back((*it)->clone());
    }
}

Figure::~Figure(){
	vector<Point*>::iterator it;
	for(it = pontos->begin(); it != pontos->end(); it++){
		delete((*it));
	}
	delete(pontos);
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
