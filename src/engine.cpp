#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define _USE_MATH_DEFINES
#include <math.h>

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "../headers/Point.h"
#include "../headers/Figure.h"
#include "../headers/tinyxml2.h"
#include "../headers/Matrix.h"
#include "../headers/Scale.h"
#include "../headers/Translate.h"
#include "../headers/Rotation.h"
#include "../headers/Camera.h"



using namespace tinyxml2;
using namespace std;

#define 	GLUT_WHEEL_UP 		3
#define 	GLUT_WHEEL_DOWN 	4

//variaveis globais
int WINDOW_X = 800;
int WINDOW_Y = 800;
int X_POS = WINDOW_X/2;
int Y_POS = WINDOW_Y/2;


float angleA = M_PI/3.0;
float angleB = M_PI/3.0;
float radius = 40;
GLenum viewMode = GL_POLYGON;

Camera * cam;


vector<Figure*> figs;


void teapot(){
	glPushMatrix();
	glTranslatef(5.0,0.0,2.0);

	glutSolidTeapot(0.1);
	glTranslatef(5.0,0.0,2.0);

	glutSolidTeapot(0.1);
	glPopMatrix();
}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void build_figure(string path,vector<Transformation*> &trans){

  string line;
  string delimiter = " ";
  float x,y,z;
  ifstream myfile(path);
  Figure * f;
  if (myfile.is_open())
  {
	vector<Point*> * v = new vector<Point*>();

    while (getline(myfile,line)){
		size_t pos = 0;
  		string token;

		pos = line.find(delimiter);
		token = line.substr(0, pos);
		x = atof(token.c_str());
		line.erase(0, pos + delimiter.length());

		pos = line.find(delimiter);
		token = line.substr(0, pos);
		y = atof(token.c_str());
		line.erase(0, pos + delimiter.length());

		pos = line.find(delimiter);
		token = line.substr(0, pos);
		z = atof(token.c_str());
		line.erase(0, pos + delimiter.length());

		v->push_back(new Point(x,y,z));
    }
	f = new Figure(v,trans);
	figs.push_back(f);
    myfile.close();
  }
  else cout << "error" << endl;
}

void draw_figures(){
	vector<Figure*>::iterator it;
	for(it = figs.begin(); it != figs.end(); it++){
		(*it)->draw();
	}
}

void draw_xyz(float size){
	glColor3f(1,1,1);
	//x
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(size,0,0);
	glEnd();
	//y
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(0,size,0);
	glEnd();
	//z
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(0,0,size);
	glEnd();
}

void renderScene(void) {
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	Point * pos = cam->getPosition();
	Point * look = cam->getLookup();
	Point * up = cam->getUp();
	gluLookAt(pos->getX(), pos->getY(),pos->getZ(),
					look->getX(),look->getY(),look->getZ(),
				up->getX(),up->getY(),up->getZ());
	// End of frame

	glPolygonMode(GL_FRONT,viewMode);
	draw_figures();


	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

	switch (c) {
			case 'w':
					cam->move(c,xx,yy);
					glutPostRedisplay();
					break;
			case 's':
					cam->move(c,xx,yy);
					glutPostRedisplay();
					break;
			case 'a':
					cam->move(c,xx,yy);
					glutPostRedisplay();
					break;
			case 'd':
					cam->move(c,xx,yy);
					glutPostRedisplay();
					break;
			case 'j':
					viewMode = GL_LINE;
					glutPostRedisplay();
					break;
			case 'k':
					viewMode = GL_POINT;
					glutPostRedisplay();
					break;
			case 'l':
					viewMode = GL_FILL;
					glutPostRedisplay();
					break;
			default:
					break;
	}

}


void processSpecialKeys(int key, int xx, int yy) {

}

void regPos(int x, int y){
	X_POS = x;
	Y_POS = y;
}



void mouse(int button, int state, int x, int y)
{
	// Used for wheels, has to be up
	if (state == GLUT_UP )	{

		if ( button == GLUT_WHEEL_UP ){
			radius *= 0.95;
		}
		else if( button == GLUT_WHEEL_DOWN ){
			radius *= 1.05;
		}
		glutPostRedisplay();
	}
}




void activeMotion(int x, int y){
	float alpha = ((float)(x - X_POS)/WINDOW_X)*M_PI;
	float beta = ((float)(y - Y_POS)/WINDOW_Y)*M_PI;
	regPos(x,y);
	cam->updateCamera(alpha,beta);
	glutPostRedisplay();
}

string mergePath(string path, string prog){



	int i ;
	int flag = 0;
	for( i = path.length() - 1 ; i>=0 && !flag; i-- )
		if(path[i] == '/') flag = 1;

	std::string pathFull = path.substr (0,i+2);     // "think"

	string pathProg = pathFull + prog;
	cout << pathProg << endl;

	return pathProg;


}

void parseModels(string f_path,vector<Transformation*> &trans,XMLElement * element){
	for (element = element->FirstChildElement(); element; element = element->NextSiblingElement()) {
		string figura = element->Attribute("file");

		string file2 = mergePath(f_path,figura);

		build_figure(file2,trans);
	}

}

void parseGroup(string f_path,vector<Transformation*> &trans,XMLElement * element){
	XMLElement * percorrer;

	float v[3];
	int v1[3];

    vector<Transformation*> clone;

	vector<Transformation*>::iterator it;
	for(it = trans.begin(); it != trans.end(); it++){
		clone.push_back((*it)->clone());
	}

	for(percorrer = element->FirstChildElement(); percorrer; percorrer = percorrer->NextSiblingElement()){
		string name = percorrer->Name();
		if (name.compare("translate") == 0 || name.compare("scale") == 0){
			v[0] = 0.0; v[1] = 0.0; v[2] = 0.0;
			percorrer->QueryFloatAttribute( "X", v );
			percorrer->QueryFloatAttribute( "Y", v+1 );
			percorrer->QueryFloatAttribute( "Z", v+2 );

			int type;
			if (name.compare("translate") == 0)
				clone.push_back(new Translate(v));
			else clone.push_back(new Scale(v));
		}
		else if (name.compare("rotate") == 0){

			float angle = 0.0;
            v1[0] = 0; v1[1] = 0; v1[2] = 0;
            percorrer->QueryIntAttribute( "axisX", v1 );
            percorrer->QueryIntAttribute( "axisY", v1+1 );
            percorrer->QueryIntAttribute( "axisZ", v1+2 );
            percorrer->QueryFloatAttribute( "angle", &angle);

			clone.push_back(new Rotation(v1,angle));
		}
		else if (name.compare("models") == 0){
			parseModels(f_path,clone,percorrer);
		}
		else if (name.compare("group") == 0){
			parseGroup(f_path,clone,percorrer);
		}
	}

    for(it = clone.begin(); it != clone.end(); it++){
        delete (*it);
    }
}

void parseXML(string  f_path){
    XMLDocument xmlDoc;
    XMLElement *element;

    vector<Transformation*> transf;

    if (!(xmlDoc.LoadFile(f_path.c_str()))) {

        element = xmlDoc.FirstChildElement();
        for (element = element->FirstChildElement(); element; element = element->NextSiblingElement()) {
            parseGroup(f_path,transf,element);
        }

    }
    else {
        cout << "Ficheiro não encontrado! " << endl;
    }
}

void initGL(){

#ifndef __APPLE__
	glewInit();
#endif
	//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_VERTEX_ARRAY);
}

int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WINDOW_X,WINDOW_Y);
	glutCreateWindow("CG@DI-UM");




	glClearColor(0,0,0,1) ;
	glClear(GL_COLOR_BUFFER_BIT);




	if(argc < 2){
	     cout << "Input not given!" << endl;
	     return 0;
	}

	else parseXML(argv[1]); // Read XML File
// Required callback registry
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(regPos);
	glutMotionFunc(activeMotion);
	glutMouseFunc(mouse);

	initGL();
	cam = new Camera();

// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
