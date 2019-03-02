//
// Created by Diogo Sobral on 2019-02-26.
//

#include "../headers/Point.h"
#include "../headers/Figure.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>


void write_file(string file_name,vector<Point*> * vertices){

    system("mkdir -p ../files/ ");
    string path = "../files/" + file_name;

    ofstream outputFile;
    outputFile.open(path);

    vector<Point*>::iterator it;
    for(it = vertices->begin(); it != vertices->end(); it++){
        outputFile << (*(*it)).to_String() << endl;
    }
	delete(vertices);

    outputFile.close();
}

void print_error(string s){
	cout << s << endl;
}

void printHelp(){
	cout << "#_____________________________ HELP _____________________________# " << endl;
	cout << "|                                                                |" << endl;
	cout << "|   Usage: ./generator {COMMAND} ... {OUTPUT FILE}               |" << endl;
	cout << "|   COMMANDS:                                                    |" << endl;
	cout << "| - plane                                                        |" << endl;
	cout << "|      Cria um plano paralelo a XZ                               |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - box [SIZE X] [SIZE Y] [SIZE Z] [DIVISIONS]                   |" << endl;
	cout << "|      Cria um paralelepipedo com as dimensões pretendidas.      |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - sphere [RADIUS] [SLICE] [STACK]                              |" << endl;
	cout << "|      Cria uma esfera com o raio, slices e stacks pretendidas.  |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - cone [RADIUS] [HEIGHT] [SLICE] [STACK]                       |" << endl;
	cout << "|      Cria um cone com o raio, altura, slices e stacks          |" << endl;
	cout << "|      pretendidas.                                              |" << endl;
	cout << "|                                                                |" << endl;
	cout << "| - torus [OUTER RADIUS] [INNER RADIUS] [RINGS DIVISIONS] [RINGS]|" << endl;
	cout << "|      Cria um torus com as dimensões pretendidas                |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|   OUTPUT FILE:                                                 |" << endl;
	cout << "| In the file section you can specify any file in which you wish |" << endl;
	cout << "| to save the coordinates generated with the previous commands.  |" << endl;
	cout << "|                                                                |" << endl;
	cout << "#________________________________________________________________#" << endl;
}

int main(int argc, char **argv){

    Figure f;
	int flag = 0,slices,stacks,opt;
	float radius,height,radius2;
	float x,y,z;



    if (argc == 3 && strcmp(argv[1],"plane") == 0){
		f.plane_vertex(2);
		flag = 1;
    }
    else if (argc == 6 && strcmp(argv[1],"sphere") == 0){
		radius = atof(argv[2]);
		slices = atoi(argv[3]);
		stacks = atoi(argv[4]);

		if (radius != 0 && slices != 0 && stacks != 0){
			f.shpere_vertex(radius,slices,stacks);
			flag = 1;
		}else print_error("Erro no input");
    }
    else if (argc == 7 && strcmp(argv[1],"cone")){
		radius = atof(argv[2]);
		height = atof(argv[3]);
		slices = atoi(argv[4]);
		stacks = atoi(argv[5]);

		if (radius != 0 && slices != 0 && stacks != 0 && height != 0){
			f.cone_vertex(radius,height,slices,stacks);
			flag = 1;
		}else print_error("Erro no input");
    }
	else if ((argc == 7 || argc == 6) && strcmp(argv[1],"box") == 0){
		x = atof(argv[2]);
		y = atof(argv[3]);
		z = atof(argv[4]);

		if (argc == 7){
			opt = atoi(argv[5]);
		}
		else opt = 1;

		if (x != 0 && y != 0 && z != 0 && opt != 0){
			f.box_vertex(x,y,z,opt);
			flag = 1;
		}else print_error("Erro no input");
	}
	else if (argc == 7 && strcmp(argv[1],"torus") == 0){
		radius = atof(argv[2]);
		radius2 = atof(argv[3]);
		slices = atoi(argv[4]);
		stacks = atoi(argv[5]);

		if (radius != 0 && slices != 0 && stacks != 0 && radius2 != 0 && (radius >= radius2)){
			f.torus_vertex(radius,radius2,slices,stacks);
			flag = 1;
		}else print_error("Erro no input");
	}
	else{
		printHelp();
	}

	if (flag){
		write_file(argv[argc-1],f.getPontos());
	}
}
