//
// Created by Diogo Sobral on 2019-02-26.
//

#include "headers/Point.h"
#include "headers/Figure.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>


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

int main(int argc, char **argv){

    vector<Point*> v;
    Figure f(v);

    if (argc == 3 && strcmp(argv[1],"plane")){

    }
    else if (argc == 6 && strcmp(argv[1],"sphere")){

    }
    else if (argc == 7 && strcmp(argv[1],"cone")){

    }
}