#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define _USE_MATH_DEFINES
#include <math.h>

#include <stdio.h>
#include <iostream>
#include <vector>
#include "headers/Point.h"
#include "headers/Figure.h"


#include "Figure.cpp"

float ay = 0;

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

void draw_xyz(float size){
	glColor3f(0,0,0);
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

void draw_shpere(float radius,int slices,int stacks){
	int i=0;
	float alpha = 2*M_PI / slices;
	float beta = M_PI / stacks;

	int k = -(stacks / 2);

	glBegin(GL_TRIANGLES);

	for(; k < (stacks / 2); k++){

		for(i=0; i < slices;i++){
			alpha = 2*M_PI / slices;
			beta = M_PI / stacks;

			glColor3f(0.423,0.321,0.792);
			glVertex3f(radius*cos(i*alpha)*cos(k*beta) ,radius*sin(k*beta) ,radius*sin(i*alpha)*cos(k*beta));
			glVertex3f(radius*cos(i*alpha)*cos((k+1)*beta),radius*sin((k+1)*beta),radius*sin(i*alpha)*cos((k+1)*beta));
			glVertex3f(radius*cos((i+1)*alpha)*cos(k*beta) ,radius*sin(k*beta) ,radius*sin((i+1)*alpha)*cos(k*beta));


			glColor3f(0.423,0.321,0.792);
			glVertex3f(radius*cos(i*alpha)*cos((k+1)*beta),radius*sin((k+1)*beta),radius*sin(i*alpha)*cos((k+1)*beta));
			glVertex3f(radius*cos((i+1)*alpha)*cos((k+1)*beta) ,radius*sin((k+1)*beta) ,radius*sin((i+1)*alpha)*cos((k+1)*beta));
			glVertex3f(radius*cos((i+1)*alpha)*cos(k*beta) ,radius*sin(k*beta) ,radius*sin((i+1)*alpha)*cos(k*beta));
		}
	}
	glEnd();
}

void draw_plane(){
	glColor3f(0.792,0.321,0.423);
	glBegin(GL_TRIANGLES);
		glVertex3f(2,0,2);
		glVertex3f(2,0,-2);
		glVertex3f(-2,0,-2);


		glVertex3f(2,0,2);
		glVertex3f(-2,0,-2);
		glVertex3f(-2,0,2);

        glVertex3f(2,0,2);
        glVertex3f(-2,0,-2);
        glVertex3f(2,0,-2);

        glVertex3f(2,0,2);
        glVertex3f(-2,0,2);
        glVertex3f(-2,0,-2);
	glEnd();
}

void draw_box(float x,float y,float z,int partitions){
	float dx,dy,dz;

	dx = x / partitions;
	dy = y / partitions;
	dz = z / partitions;

	glBegin(GL_TRIANGLES);

		glColor3f(0.792,0.321,0.423);
		//Face Frente


		int i = 0;
		for(i = 0; i < partitions; i++){
		}


		glColor3f(0.423,0.321,0.792);
		//Face trás


		glColor3f(0.6,0.2,0.1);
		//Face lateral frente


		glColor3f(0.2,0.3,0.792);
		//Face lateral trás

		glColor3f(0.4,0.1,0.792);

		//Face cima


		glColor3f(0.5,0.5,0.792);
		//Face baixo


	glEnd();

}

void draw_cone(float radius,float height,int slices,int stacks){
		float angle, height_act = 0, height_next = 0, radius_act = 0, radius_next = 0;
		glColor3f(0.4,0.1,0.792);
		glBegin(GL_TRIANGLES);
		int k = 0,i;

		//base
		for(i = 0; i < slices; i++){
			angle = i * ((2*M_PI) / slices);
			glVertex3f(radius*cos(angle + ((2*M_PI) / slices)),0,radius*sin(angle + ((2*M_PI) / slices)));
			glVertex3f(0,0,0);
			glVertex3f(radius*cos(angle),0,radius*sin(angle));
		}

		for(i = 0; i < slices; i++){
			for(k = 0; k < stacks - 1; k++){
				height_act = k * (height / stacks);
				height_next = (k+1) * (height / stacks);
				radius_act = (radius * (height - height_act)) / height;
				radius_next = (radius * (height - height_next)) / height;
				angle = i * ((2*M_PI) / slices);

				glVertex3f(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));
				glVertex3f(radius_act*cos(angle),height_act,radius_act*sin(angle));
				glVertex3f(radius_next*cos(angle),height_next,radius_next*sin(angle));

				glVertex3f(radius_next*cos(angle),height_next,radius_next*sin(angle));
				glVertex3f(radius_next*cos(angle + ((2*M_PI) / slices)),height_next,radius_next*sin(angle + ((2*M_PI) / slices)));
				glVertex3f(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));
			}
		}

		for(i = 0; i < slices; i++){
			height_act = k * (height / stacks);
			radius_act = (radius * (height - height_act)) / height;
			angle = i * ((2*M_PI) / slices);

			glVertex3f(0,height,0);
			glVertex3f(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));
			glVertex3f(radius_act*cos(angle),height_act,radius_act*sin(angle));
		}

		glEnd();

}

void draw_anel(float radius_outside,float radius_inside,int slices,int stacks){
	float teta, fi;

	glBegin(GL_TRIANGLES);
	for(int i = 0; i < stacks ; i++){
		for(int j = 0; j < slices ; j++){
			teta = (2 * M_PI) / slices;
			fi = (2 * M_PI) / stacks;

			glColor3f(0.4,0.1,0.792);
			glVertex3f((radius_outside + radius_inside*cos(j*teta))*cos(i*fi),radius_inside*sin(j*teta),(radius_outside + radius_inside*cos(j*teta))*sin(i*fi));
			glVertex3f((radius_outside + radius_inside*cos((j+1)*teta))*cos(i*fi),radius_inside*sin((j+1)*teta),(radius_outside + radius_inside*cos((j+1)*teta))*sin(i*fi));
			glVertex3f((radius_outside + radius_inside*cos(j*teta))*cos((i+1)*fi),radius_inside*sin(j*teta),(radius_outside + radius_inside*cos(j*teta))*sin((i+1)*fi));

			glColor3f(0,0,0);
			glVertex3f((radius_outside + radius_inside*cos((j+1)*teta))*cos(i*fi),radius_inside*sin((j+1)*teta),(radius_outside + radius_inside*cos((j+1)*teta))*sin(i*fi));
			glVertex3f((radius_outside + radius_inside*cos((j+1)*teta))*cos((i+1)*fi),radius_inside*sin((j+1)*teta),(radius_outside + radius_inside*cos((j+1)*teta))*sin((i+1)*fi));
			glVertex3f((radius_outside + radius_inside*cos(j*teta))*cos((i+1)*fi),radius_inside*sin(j*teta),(radius_outside + radius_inside*cos(j*teta))*sin((i+1)*fi));

		}
	}
	glEnd();

}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(5,5,5,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	glRotatef(ay,0,0,1);

	//glPolygonMode(GL_FRONT,GL_LINE);
	//sdraw_xyz(3);
	//draw_shpere(3,10,10);
	//draw_plane();
	//draw_box(1,1,1);
	//draw_cone(1,2,10,1);
	glColor3f(0,0,0);
	Figure f;
	f.torus_vertex(1,1,20,20);
	f.draw();
	//draw_anel(1,1,1000,1000);

	//glutWireSphere(1,9,9);
	//glutWireCone(1,2,5,3);

	// End of frame
	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {
	switch (c) {
          case 'q':
             ay += 45;
             glutPostRedisplay();
             break;
		  case 'w':
		  	 ay -= 45;
		  	 glutPostRedisplay();
		 	 break;
		  default:
		  	 break;
	}
}


void processSpecialKeys(int key, int xx, int yy) {

// put code to process special keys in here
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
