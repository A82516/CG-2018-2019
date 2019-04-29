

#import "../headers/parser.h"

void build_figure(string path,vector<Transformation*> &trans,vector<Figure*> * figures){

    string line;
    string delimiter = " ";
    float x,y,z;
    ifstream myfile(path);
    Figure * f;
    if (myfile.is_open())
    {
        vector<Point*> * v = new vector<Point*>();
        vector<Point*> * normal =  new vector<Point*>();

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

            normal->push_back(new Point(x,y,z));
        }
        f = new Figure(v,trans,normal);
        figures->push_back(f);
        myfile.close();
    }
    else cout << "error" << endl;
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

void parseModels(string f_path,vector<Transformation*> &trans,XMLElement * element,vector<Figure*> * figures){
    for (element = element->FirstChildElement(); element; element = element->NextSiblingElement()) {
        string figura = element->Attribute("file");

        string file2 = mergePath(f_path,figura);

        build_figure(file2,trans,figures);
    }

}

vector<Figure*> * parseXML(string  f_path){
    XMLDocument xmlDoc;
    XMLElement *element;

    vector<Transformation*> transf;

    vector<Figure*> * figuras = new vector<Figure*>();

    if (!(xmlDoc.LoadFile(f_path.c_str()))) {

        element = xmlDoc.FirstChildElement();
        for (element = element->FirstChildElement(); element; element = element->NextSiblingElement()) {
            parseGroup(f_path,transf,element,figuras);
        }

    }
    else {
        cout << "Ficheiro não encontrado! " << endl;
    }

    return figuras;
}

void parseGroup(string f_path,vector<Transformation*> &trans,XMLElement * element,vector<Figure*> * figures){
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
            int time = 0.0;
            percorrer->QueryIntAttribute( "Time", &time);
            percorrer->QueryFloatAttribute( "X", v );
            percorrer->QueryFloatAttribute( "Y", v+1 );
            percorrer->QueryFloatAttribute( "Z", v+2 );

            int type;
            if (name.compare("translate") == 0) {
                Translate * t = new Translate(time);
                if (time != 0.0){
                    parseTranslate(t,percorrer);
                }
                else {t->addPoint(new Point (v[0],v[1],v[2]));}
                clone.push_back(t);
            }
            else clone.push_back(new Scale(v));
        }
        else if (name.compare("rotate") == 0){

            float time = 0.0, angle = 0.0;
            v1[0] = 0; v1[1] = 0; v1[2] = 0;
            percorrer->QueryFloatAttribute( "Time", &time);
            percorrer->QueryFloatAttribute( "Angle", &angle);
            percorrer->QueryIntAttribute( "axisX", v1 );
            percorrer->QueryIntAttribute( "axisY", v1+1 );
            percorrer->QueryIntAttribute( "axisZ", v1+2 );


            clone.push_back(new Rotate(time, angle, v1));
        }
        else if (name.compare("models") == 0){
            parseModels(f_path,clone,percorrer,figures);
        }
        else if (name.compare("group") == 0){
            parseGroup(f_path,clone,percorrer,figures);
        }
    }

    for(it = clone.begin(); it != clone.end(); it++){
        delete (*it);
    }
}

void parseTranslate(Translate * t,XMLElement * element){
    float v[3];
    for (element = element->FirstChildElement(); element; element = element->NextSiblingElement()) {
        element->QueryFloatAttribute( "X", v );
        element->QueryFloatAttribute( "Y", v+1 );
        element->QueryFloatAttribute( "Z", v+2 );

        t->addPoint(new Point(v[0],v[1],v[2]));
    }
}