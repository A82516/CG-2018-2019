#include "../headers/Matrix.h"


void multiply(float m1[4][4],float m2[4][4],int m1_collum, int m1_lines,int m2_collum,float result[4][4]){
    int i,j,k;
    float aij;
	initMatrix(result,4,4);

    for (i = 0; i < m1_lines; i++) {
        for(j = 0; j < m2_collum; j++) {
            for(k = 0; k < m1_collum; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void initMatrix(float m[4][4],int c,int l){
    for (int i=0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = 0;
        }
    }
}

void idMatrix(float m[4][4],int c,int l){
    for (int i=0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = j == i ? 1.0 : 0.0;
        }
    }
}

void multiply_point(float m[4][4],float p[4],float f[4]){
    for (int k=0; k < 4; k++) {
        f[k] = 0;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            f[i] += m[i][j]*p[j];
        }
    }
}

void initArray(float m[],int size){
    for (int i= 0; i < size; i++) {
        m[i] = 0;
    }
}

void translationM(float v[3],float m[4][4]){
    idMatrix(m,4,4);
    m[0][3] = v[0];
    m[1][3] = v[1];
    m[2][3] = v[2];
}

void intranslationM(float v[3],float m[4][4]){
    idMatrix(m,4,4);
    m[0][3] = -v[0];
    m[1][3] = -v[1];
    m[2][3] = -v[2];
}

void scaleM(float v[3],float m[4][4]){
    idMatrix(m,4,4);
    m[0][0] = v[0];
    m[1][1] = v[1];
    m[2][2] = v[2];
}

void inscaleM(float v[3],float m[4][4]){
    idMatrix(m,4,4);
    m[0][0] = 1.0 / v[0];
    m[1][1] = 1.0 / v[1];
    m[2][2] = 1.0 / v[2];
}

void rotateX(float angle,float m[4][4]){
    idMatrix(m,4,4);
    m[1][1] = cos(angle);
    m[1][2] = -sin(angle);
    m[2][1] = sin(angle);
    m[2][2] = cos(angle);
}

void rotateY(float angle,float m[4][4]){
    idMatrix(m,4,4);
    m[0][0] = cos(angle);
    m[0][2] = sin(angle);
    m[2][0] = -sin(angle);
    m[2][2] = cos(angle);
}

void rotateZ(float angle,float m[4][4]){
    idMatrix(m,4,4);
    m[0][0] = cos(angle);
    m[0][1] = -sin(angle);
    m[1][0] = sin(angle);
    m[1][1] = cos(angle);
}

void inrotateX(float angle,float m[4][4]){
    rotateX(-angle,m);
}

void inrotateY(float angle,float m[4][4]){
    rotateY(-angle,m);
}

void inrotateZ(float angle,float m[4][4]){
    rotateZ(-angle,m);
}

int rotation_type(int v[3]){
    if (v[0])
        return 1;
    if (v[1])
        return 2;
    return 3;
}


void copy(float ori[4][4],float dest[4][4]){
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4 ; j++)
			dest[i][j] = ori[i][j];
}
