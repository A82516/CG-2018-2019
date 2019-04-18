//
// Created by Diogo Sobral on 2019-04-17.
//

#include <iostream>
#include "../headers/Camera.h"


static void cross(float *a, float *b, float *res) {

    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
}

Camera::Camera() {
    position = new Point(40,20,0);
    lookup = new Point(0,0,0);
    up = new Point(0,1,0);
    alpha = 0.0;
    beta = M_PI / 6;
    radius = 40;
    speed = 0.01;
    updateUp();
    updateLookup();
}

Point * Camera::getPosition() {
    return position;
}

Point * Camera::getUp() {
    return up;
}

Point * Camera::getLookup() {
    return lookup;
}

void Camera::updateCamera(float a,float b){
    alpha += a;
    beta += b;

    updateLookup();
    updateUp();
}

Camera::~Camera() {}

void Camera::updateUp(){
    up->setX(1.0 * cos(beta + (M_PI / 2)) * cos(alpha));
    up->setY(1.0 * sin(beta + (M_PI / 2)));
    up->setZ(1.0 * cos(beta + (M_PI / 2)) * sin(alpha));
}

void Camera::updateLookup() {
    lookup->setX(-radius * cos(beta) * cos(alpha) + position->getX());
    lookup->setY(-radius * sin(beta) + position->getY());
    lookup->setZ(-radius * cos(beta) * sin(alpha) + position->getZ());
}

void Camera::move(unsigned char c, int xx, int yy){
    float x,y,z;

    float res[3];
    float d[3],upA[3];

    x = position->getX();
    y = position->getY();
    z = position->getZ();
    d[0] = speed * (lookup->getX() - x);
    d[1] = speed * (lookup->getY() - y);
    d[2] = speed * (lookup->getZ() - z);
    upA[0] = up->getX();
    upA[1] = up->getY();
    upA[2] = up->getZ();

    cross(d,upA,res);

    switch (c){
        case 'w':
            position->setX(x+d[0]);
            position->setY(y+d[1]);
            position->setZ(z+d[2]);
            break;
        case 's':
            position->setX(x-d[0]);
            position->setY(y-d[1]);
            position->setZ(z-d[2]);
            break;
        case 'a':
            position->setX(x-res[0]);
            position->setY(y-res[1]);
            position->setZ(z-res[2]);
            break;
        case 'd':
            position->setX(x+res[0]);
            position->setY(y+res[1]);
            position->setZ(z+res[2]);
            break;
        default:
            break;
    }

    updateLookup();
    updateUp();
}

