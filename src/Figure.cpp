//
// Created by Diogo Sobral on 2019-02-26.
//

#include "../headers/Figure.h"

static float cores_sun[6][3] = {{255,127,80},{255,99,71},{255,69,0},{255,215,0},{255,165,0},{255,140,0}};
static float cores_terra[6][3] = {{32,178,170},{0,100,0},{128,128,0},{34,139,34},{0,139,139},{72,209,204}};
static float cores_sat[6][3] = {{222,184,135},{210,180,140},{245,222,179},{255,228,196},{255,228,181},{139,69,19}};
static float cores_mer[6][3] = {{105,105,105},{128,128,128},{0,191,255},{72,209,204},{211,211,211},{220,220,220}};
static float cores_ven[6][3] = {{255,99,71},{255,69,0},{240,128,128},{238,232,170},{240,230,140},{255,255,240}};
static float cores_jup[6][3] = {{255,255,240},{255,239,213},{244,164,96},{255,228,196},{184,134,11},{224,255,255}};
static float cores_mar[6][3] = {{165,42,42},{128,0,0},{220,20,60},{178,34,34},{165,42,42},{139,0,0}};
static float cores_ura[6][3] = {{72,209,204},{72,209,204},{72,209,204},{64,224,208},{64,224,208},{64,224,208}};
static float cores_nep[6][3] = {{65,105,225},{65,105,225},{65,105,225},{0,0,205},{0,0,205},{0,0,205}};
static float cores_moon[6][3] = {{220,220,220},{119,136,153},{255,255,255},{255,239,213},{169,169,169},{128,128,128}};



static int number_figures = 0;



void Figure::shpere_vertex(float radius,int slices,int stacks){
    int i=0;
    float alpha,d_alpha;
    float beta,d_beta;
    Point *p1,*p2,*p3;

    for(int k = 0; k < stacks ; k++){
        for(i=0; i < slices;i++){
            alpha = i*(2*M_PI / slices);
            beta = k*(M_PI / stacks) - (M_PI / 2);
			d_alpha =(2*M_PI / slices);
			d_beta = (M_PI / stacks);

            p1 = new Point(radius*cos(alpha)*cos(beta ),radius*sin(beta ),radius*sin(alpha)*cos(beta));
            p2 = new Point(radius*cos(alpha)*cos(beta + d_beta),radius*sin(beta + d_beta),radius*sin(alpha)*cos(beta + d_beta));
            p3 = new Point(radius*cos(alpha + d_alpha)*cos(beta) ,radius*sin(beta) ,radius*sin(alpha + d_alpha)*cos(beta));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point(radius*cos(alpha)*cos(beta + d_beta),radius*sin(beta + d_beta),radius*sin(alpha)*cos(beta + d_beta));
            p2 = new Point(radius*cos(alpha + d_alpha)*cos(beta + d_beta) ,radius*sin(beta + d_beta) ,radius*sin(alpha + d_alpha)*cos(beta + d_beta));
            p3 = new Point(radius*cos(alpha + d_alpha)*cos(beta) ,radius*sin(beta) ,radius*sin(alpha + d_alpha)*cos(beta));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);
        }
    }
}

vector<Point*>* Figure::getPontos(){
    vector<Point*> * fim = new vector<Point*>((*pontos));
    return fim;
}

Figure::Figure(){
    pontos = new vector<Point*>();
}

void Figure::cone_vertex(float radius,float height,int slices,int stacks){
    float angle, height_act = 0, height_next = 0, radius_act = 0, radius_next = 0,d_alpha;
    int k = 0,i;

    Point *p1,*p2,*p3;

    //base
    for(i = 0; i < slices; i++){
        angle = i * ((2*M_PI) / slices);
        p1 = new Point(radius*cos(angle + ((2*M_PI) / slices)),0,radius*sin(angle + ((2*M_PI) / slices)));
        p2 = new Point(0,0,0);
        p3 = new Point(radius*cos(angle),0,radius*sin(angle));

        pontos->push_back(p1);
        pontos->push_back(p2);
        pontos->push_back(p3);
    }

    for(i = 0; i < slices; i++){
        for(k = 0; k < stacks - 1; k++){
            height_act = k * (height / stacks);
            height_next = (k+1) * (height / stacks);
            radius_act = (radius * (height - height_act)) / height;
            radius_next = (radius * (height - height_next)) / height;
            angle = i * ((2*M_PI) / slices);

            p1 = new Point(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));
            p2 = new Point(radius_act*cos(angle),height_act,radius_act*sin(angle));
            p3 = new Point(radius_next*cos(angle),height_next,radius_next*sin(angle));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point(radius_next*cos(angle),height_next,radius_next*sin(angle));
            p2 = new Point(radius_next*cos(angle + ((2*M_PI) / slices)),height_next,radius_next*sin(angle + ((2*M_PI) / slices)));
            p3 = new Point(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);
        }
    }

    for(i = 0; i < slices; i++){
        height_act = k * (height / stacks);
        radius_act = (radius * (height - height_act)) / height;
        angle = i * ((2*M_PI) / slices);

        p1 = new Point(0,height,0);
        p2 = new Point(radius_act*cos(angle + ((2*M_PI) / slices)),height_act,radius_act*sin(angle + ((2*M_PI) / slices)));
        p3 = new Point(radius_act*cos(angle),height_act,radius_act*sin(angle));

        pontos->push_back(p1);
        pontos->push_back(p2);
        pontos->push_back(p3);
    }
}

void Figure::plane_vertex(float size) {
    Point *p1,*p2,*p3;

    p1 = new Point(size,0,size);
    p2 = new Point(size,0,-size);
    p3 = new Point(-size,0,-size);

    pontos->push_back(p1);
    pontos->push_back(p2);
    pontos->push_back(p3);


    p1 = new Point(size,0,size);
    p2 = new Point(-size,0,-size);
    p3 = new Point(-size,0,size);

    pontos->push_back(p1);
    pontos->push_back(p2);
    pontos->push_back(p3);
}

void Figure::draw() {
    glPushMatrix();

    vector<Transformation*>::iterator it1;
    for(it1 = transformacoes->begin(); it1 != transformacoes->end(); it1++){
        (*it1)->performe();
    }

    glBegin(GL_TRIANGLES);

    vector<Point*>::iterator it;
    vector<Point*>::iterator color_it;
	int i = 0;
    for(it = pontos->begin(),color_it = cores->begin(); it != pontos->end() && color_it != cores->end(); it++,color_it++){
        Point * p = (*it),* p2 = (*color_it);
        /**
		if ((i % 3) == 0){
			float r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			float r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			float r3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			glColor3f(r1,r2,r3);
		}*/
		glColor3f(p2->getX(),p2->getY(),p2->getZ());
        glVertex3f(p->getX(),p->getY(),p->getZ());
        i++;
    }
    glEnd();
    glPopMatrix();
}

void Figure::torus_vertex(float radius_outside,float radius_inside,int slices,int stacks){
    float teta, fi,d_teta,d_fi;
    Point *p1,*p2,*p3;

    for(int i = 0; i < stacks ; i++){
        for(int j = 0; j < slices ; j++){
            teta = j * (2 * M_PI) / slices;
            fi = i * (2 * M_PI) / stacks;
			d_teta = (2 * M_PI) / slices;
			d_fi = (2 * M_PI) / stacks;


            p1 = new Point((radius_outside + radius_inside*cos(teta))*cos(fi),radius_inside*sin(teta),(radius_outside + radius_inside*cos(teta))*sin(fi));
            p2 = new Point((radius_outside + radius_inside*cos(teta + d_teta))*cos(fi),radius_inside*sin(teta + d_teta),(radius_outside + radius_inside*cos(teta + d_teta))*sin(fi));
            p3 = new Point((radius_outside + radius_inside*cos(teta))*cos(fi + d_fi),radius_inside*sin(teta),(radius_outside + radius_inside*cos(teta))*sin(fi + d_fi));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);

            p1 = new Point((radius_outside + radius_inside*cos(teta + d_teta))*cos(fi),radius_inside*sin(teta + d_teta),(radius_outside + radius_inside*cos(teta + d_teta))*sin(fi));
            p2 = new Point((radius_outside + radius_inside*cos(teta + d_teta))*cos(fi + d_fi),radius_inside*sin(teta + d_teta),(radius_outside + radius_inside*cos(teta + d_teta))*sin(fi + d_fi));
            p3 = new Point((radius_outside + radius_inside*cos(teta))*cos(fi + d_fi),radius_inside*sin(teta),(radius_outside + radius_inside*cos(teta))*sin(fi + d_fi));

            pontos->push_back(p1);
            pontos->push_back(p2);
            pontos->push_back(p3);
        }
    }
}

void Figure::box_vertex(float x,float y,float z,int partitions){
    float dx,dy,dz,sX,sY,sZ;

    dx = x / partitions;
    dy = y / partitions;
    dz = z / partitions;

    sX = -x/2;
    sY = -y/2;
    sZ = -z/2;

    int i,j;
    for(i = 0; i < partitions; i++){
        for(j = 0; j < partitions; j++){
            //Face Frente
            pontos->push_back(new Point(x/2,i*dy + sY,j*dz + sZ));
            pontos->push_back(new Point(x/2,(i+1)*dy + sY,j*dz + sZ));
            pontos->push_back(new Point(x/2,i*dy + sY,(j+1)*dz + sZ));

            pontos->push_back(new Point(x/2,(i+1)*dy + sY,j*dz + sZ));
            pontos->push_back(new Point(x/2,(i+1)*dy + sY,(j+1)*dz + sZ));
            pontos->push_back(new Point(x/2,i*dy + sY,(j+1)*dz + sZ));

            //Face trás
            pontos->push_back(new Point(-x/2,i*dy + sY,j*dz + sZ));
            pontos->push_back(new Point(-x/2,i*dy + sY,(j+1)*dz + sZ));
            pontos->push_back(new Point(-x/2,(i+1)*dy + sY,j*dz + sZ));

            pontos->push_back(new Point(-x/2,i*dy + sY,(j+1)*dz + sZ));
            pontos->push_back(new Point(-x/2,(i+1)*dy + sY,(j+1)*dz + sZ));
            pontos->push_back(new Point(-x/2,(i+1)*dy + sY,j*dz + sZ));

            //Face lateral frente
            pontos->push_back(new Point(j*dx + sX,i*dy + sY,z/2));
            pontos->push_back(new Point((j+1)*dx + sX,i*dy + sY,z/2));
            pontos->push_back(new Point(j*dx + sX,(i+1)*dy + sY,z/2));

            pontos->push_back(new Point((j+1)*dx + sX,i*dy + sY,z/2));
            pontos->push_back(new Point((j+1)*dx + sX,(i+1)*dy + sY,z/2));
            pontos->push_back(new Point(j*dx + sX,(i+1)*dy + sY,z/2));

            //Face lateral trás
            pontos->push_back(new Point((j+1)*dx + sX,i*dy + sY,-z/2));
            pontos->push_back(new Point(j*dx + sX,i*dy + sY,-z/2));
            pontos->push_back(new Point(j*dx + sX,(i+1)*dy + sY,-z/2));

            pontos->push_back(new Point(j*dx + sX,(i+1)*dy + sY,-z/2));
            pontos->push_back(new Point((j+1)*dx + sX,(i+1)*dy + sY,-z/2));
            pontos->push_back(new Point((j+1)*dx + sX,i*dy + sY,-z/2));

            //Face cima
            pontos->push_back(new Point(j*dx + sX,y/2,i*dz + sZ));
            pontos->push_back(new Point(j*dx + sX,y/2,(i+1)*dz + sZ));
            pontos->push_back(new Point((j+1)*dx + sX,y/2,(i+1)*dz + sZ));

            pontos->push_back(new Point((j+1)*dx + sX,y/2,i*dz + sZ));
            pontos->push_back(new Point(j*dx + sX,y/2,i*dz + sZ));
            pontos->push_back(new Point((j+1)*dx + sX,y/2,(i+1)*dz + sZ));

            //Face baixo
            pontos->push_back(new Point((j+1)*dx + sX,-y/2,(i+1)*dz + sZ));
            pontos->push_back(new Point(j*dx + sX,-y/2,(i+1)*dz + sZ));
            pontos->push_back(new Point(j*dx + sX,-y/2,i*dz + sZ));

            pontos->push_back(new Point(j*dx + sX,-y/2,i*dz + sZ));
            pontos->push_back(new Point((j+1)*dx + sX,-y/2,i*dz + sZ));
            pontos->push_back(new Point((j+1)*dx + sX,-y/2,(i+1)*dz + sZ));
        }
    }
}

void Figure::cylinder_vertex(float radius, float height,int slices,int stacks){
	float alpha,beta;


	int i,j;

	for(j = 0; j <= stacks; j++){
		beta = (j * (height / stacks)) - height/2;
		for(i = 0; i < slices; i++){
			alpha = i * (2*M_PI) / slices;

			if (j == stacks){
				pontos->push_back(new Point(radius*cos(alpha),height/2,radius*sin(alpha)));
				pontos->push_back(new Point(0,height/2,0));
				pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),height/2,radius*sin(alpha + (2*M_PI) / slices)));
			}
			else {
				if (j == 0){
					pontos->push_back(new Point(0,-height/2,0));
					pontos->push_back(new Point(radius*cos(alpha),-height/2,radius*sin(alpha)));
					pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),-height/2,radius*sin(alpha + (2*M_PI) / slices)));
				}

				pontos->push_back(new Point(radius*cos(alpha),beta,radius*sin(alpha)));
				pontos->push_back(new Point(radius*cos(alpha),beta + (height / stacks),radius*sin(alpha)));
				pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),beta,radius*sin(alpha + (2*M_PI) / slices)));

				pontos->push_back(new Point(radius*cos(alpha),beta + (height / stacks),radius*sin(alpha)));
				pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),beta + (height / stacks),radius*sin(alpha + (2*M_PI) / slices)));
				pontos->push_back(new Point(radius*cos(alpha + (2*M_PI) / slices),beta,radius*sin(alpha + (2*M_PI) / slices)));
			}
		}
	}
}

Figure::Figure(vector<Point*> * v){
	pontos = v;
}

Figure::Figure(vector<Point*> * v,vector<Transformation*> &trans){
	pontos = v;

    transformacoes = new vector<Transformation*>();
    vector<Transformation*>::iterator it;
    for(it = trans.begin(); it != trans.end(); it++){
        transformacoes->push_back((*it)->clone());
    }


    cores = new vector<Point*>();
    float cor_aux[3];

    for(int k = 0; k < pontos->size(); k++){
        int r1 = (static_cast <int> (rand())) % (static_cast <int> (6));


        switch (number_figures % 11){
            case 0:{ rgbToDecimal(cores_sun,r1,cor_aux); break;}
            case 1:{ rgbToDecimal(cores_mer,r1,cor_aux); break;}
            case 2:{ rgbToDecimal(cores_ven,r1,cor_aux); break;}
            case 3:{ rgbToDecimal(cores_terra,r1,cor_aux); break;}
            case 4:{ rgbToDecimal(cores_moon,r1,cor_aux); break;}
            case 5:{ rgbToDecimal(cores_mar,r1,cor_aux); break;}
            case 6:{ rgbToDecimal(cores_sat,r1,cor_aux); break;}
            case 7:{ rgbToDecimal(cores_jup,r1,cor_aux); break;}
            case 8:{ rgbToDecimal(cores_sat,r1,cor_aux); break;}
            case 9:{ rgbToDecimal(cores_ura,r1,cor_aux); break;}
            case 10:{ rgbToDecimal(cores_nep,r1,cor_aux); break;}



            }
        cores->push_back(new Point(cor_aux[0],cor_aux[1],cor_aux[2]));
    }
    number_figures++;
}

Figure::~Figure(){
	vector<Point*>::iterator it;
	for(it = pontos->begin(); it != pontos->end(); it++){
		delete((*it));
	}
	delete(pontos);
    vector<Transformation*>::iterator it1;
    for(it1 = transformacoes->begin(); it1 != transformacoes->end(); it1++){
        delete((*it1));
    }
    delete(transformacoes);
}


void cleanVector(vector<Point*> * limpar){
    vector<Point*>::iterator it;
    for(it = limpar->begin(); it != limpar->end(); it++){
        delete((*it));
    }
    delete(limpar);
}

void rgbToDecimal(float v[6][3],int y,float dest[3]){
    for(int i= 0; i < 3; i++)
        dest[i] = v[y][i] / 255;
}
