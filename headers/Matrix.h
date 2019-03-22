#ifndef __MATRIX__H
#define __MATRIX__H

#include <stdio.h>
#include <math.h>


void multiply		(float m1[4][4],float m2[4][4],int m1_collum, int m1_lines,int m2_collum,float result[4][4]);
void initMatrix		(float m[4][4],int c,int l);
void idMatrix		(float m[4][4],int c,int l);
void multiply_point	(float m[4][4],float p[4],float f[4]);
void initArray		(float m[],int size);
void translationM	(float v[3],float m[4][4]);
void intranslationM	(float v[3],float m[4][4]);
void scaleM			(float v[3],float m[4][4]);
void inscaleM		(float v[3],float m[4][4]);
void rotateX		(float angle,float m[4][4]);
void rotateY		(float angle,float m[4][4]);
void rotateZ		(float angle,float m[4][4]);
void inrotateX		(float angle,float m[4][4]);
void inrotateY		(float angle,float m[4][4]);
void inrotateZ		(float angle,float m[4][4]);
int  rotation_type	(int v[3]);
void copy			(float ori[4][4],float dest[4][4]);

#endif
