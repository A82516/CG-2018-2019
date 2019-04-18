//
// Created by Diogo Sobral on 2019-04-18.
//

#ifndef _PARSER_H
#define _PARSER_H


#include <iostream>
#include <fstream>
#include <vector>
#include "Point.h"
#include "Figure.h"
#include "tinyxml2.h"
#include "Scale.h"
#include "Translate.h"
#include "Rotate.h"

using namespace tinyxml2;

vector<Figure*> * parseXML(string  f_path);
void parseGroup(string f_path,vector<Transformation*> &trans,XMLElement * element,vector<Figure*> * figures);
void parseTranslate(Translate * t,XMLElement * element);
void parseModels(string f_path,vector<Transformation*> &trans,XMLElement * element,vector<Figure*> * figures);
string mergePath(string path, string prog);
void build_figure(string path,vector<Transformation*> &trans,vector<Figure*> * figures);


#endif //GENERATOR_PARSER_H
