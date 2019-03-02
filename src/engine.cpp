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

vector<Figure*> figs;


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

void build_figure(string path){

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
	f = new Figure(v);
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

void renderScene(void) {
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(5,5,5,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);
	// End of frame
	glPolygonMode(GL_FRONT,GL_LINE);
	glColor3f(0,0,0);
	draw_figures();

	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

}


void processSpecialKeys(int key, int xx, int yy) {

}


int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");

	glClearColor(1,1,1,1) ;
	glClear(GL_COLOR_BUFFER_BIT);

// Required callback registry
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);


//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
