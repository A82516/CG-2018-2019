//
// Created by Diogo Sobral on 2019-02-26.
//

#ifndef __FIGURES__H
#define __FIGURES__H

#include <vector>
#include "Point.h"


class Figure {
    vector<Point*> pontos;

    public:
        Figure(vector<Point*> pontos);
        void shpere_vertex(float radius,int slices,int stacks);
        void cone_vertex(float radius,float height,int slices,int stacks);
        vector<Point*> getPontos();

};


#endif //CG_TRABALHO_FIGURES_H
