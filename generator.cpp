//
// Created by Diogo Sobral on 2019-02-26.
//

#include "headers/Point.h"
#include "headers/Figure.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>


void write_file(string file_name,vector<Point*> vertices){

    system("mkdir -p ../files/ ");
    string path = "../files/" + file_name;

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

    vector<Point*> v;
    Figure f(v);
    f.shpere_vertex(1,10,10);
    write_file("shpere.3d",f.getPontos());
}