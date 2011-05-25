/*
 *  ObjLoader.cpp
 *  objloader
 *
 *  Created by Kaya Oğuz on 19.05.2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "ObjLoader.h"

using namespace std;


// http://www.infernodevelopment.com/perfect-c-string-explode-split

void StringExplode(string str, string separator, vector<string>* results){
    int found;
    found = str.find_first_of(separator);
    while(found != string::npos){
        if(found > 0){
            results->push_back(str.substr(0,found));
        }
        str = str.substr(found+1);
        found = str.find_first_of(separator);
    }
    if(str.length() > 0){
        results->push_back(str);
    }
}

int strToInt(string str) {
	stringstream ss(str);
	int val;
	ss >> val;
	return val;
}

ObjLoader::ObjLoader() {
	textureFileCount = 0;
}

// http://en.wikipedia.org/wiki/Wavefront_.obj_file

void ObjLoader::loadObj(string fname) {
	fstream dosya(fname.c_str());
	string temp;
	if(!dosya.is_open())return;
	int vcount = 0; int ncount = 0; int tcount = 0;
	while(dosya.good()) {
		dosya >> temp;
		if(temp.compare("v") == 0) { vcount++; getline(dosya, temp); }
		else if(temp.compare("vt") == 0) { tcount++; getline(dosya, temp); }
		else if(temp.compare("vn") == 0) { ncount++; getline(dosya, temp); }
		else getline(dosya, temp);
	}
	//cout << vcount << ", " << tcount << ", " << ncount << endl;
	Vertex3 *vertices = new Vertex3[vcount];
	Vertex3 *normals = new Vertex3[ncount];
	Vertex2 *tcoords = new Vertex2[tcount];
	int vc = 0;
	int nc = 0;
	int tc = 0;
	
	//rewind file
	dosya.clear();
	dosya.seekg(ios::beg);
	
	GLdouble x, y, z;
	Group* current = 0;
	while(dosya.good()) {
		dosya >> temp;
		if (temp.compare("#") == 0) getline(dosya, temp);
		else if (temp.compare("mtllib") == 0) {
			getline(dosya, temp);
			string filename = temp.substr(1, temp.length()-1 ); // 1.si bosluk
			loadMtl(filename);
		}
		else if(temp.compare("v") == 0) {
			dosya >> x >> y >> z;
			vertices[vc].set(x, y, z);
			vc++;
		}
		else if (temp.compare("vt") == 0) {
			dosya >> x >> y;
			tcoords[tc].set(x, y);
			tc++;
		}
		else if (temp.compare("vn") == 0) {
			dosya >> x >> y >> z;
			normals[nc].set(x, y, z);
			nc++;
		}
		else if (temp.compare("g") == 0) {
			dosya >> temp;
			if(current != 0) groups.push_back(*current);
			current = new Group();
			current->name = temp.substr(1);
		}
		else if (temp.compare("usemtl") == 0) {
			dosya >> temp;
			string mtlname = temp;
			// daha once kaydedilmis material'lari gez (vector'de)
			// ismi tutunca hemen bu gruba ekle
			bool ok = false;
			for(int i=0;i<mtls.size();i++) {
				if(mtlname.compare(mtls[i].name) == 0) {
					ok = true;
					current->mtl = mtls[i];
				}
			}
		}
		else if (temp.compare("f") == 0) { 
			// eger f gelmisse, illa ki ondan once bir g gelmis olmali.
			// bu face'ler current gruba ait olacaklar. 
			getline(dosya, temp);
			vector<string> noktalar;
			StringExplode(temp, " ", &noktalar);
			Face t;
			for(int i=0;i<noktalar.size();i++) {
				vector<string> degerler;
				StringExplode(noktalar[i], "/", &degerler);
				int v = strToInt(degerler[0]); // vertex
				int n;// = strToInt(degerler[2]); // normal
				int tt;
				if(degerler.size() < 3) {
					n = strToInt(degerler[1]);
					t.normals.push_back(normals[n-1]);
				}
				else {
					tt = strToInt(degerler[1]); // texture
					n = strToInt(degerler[2]); // normal 
					t.normals.push_back(normals[n-1]);
					t.tcoords.push_back(tcoords[tt-1]);
				}
				t.vertices.push_back(vertices[v-1]);
			}
			current->faces.push_back(t);
		}
		else { 
			getline(dosya, temp); // skip line
		}
	}
	// current'i eklemeyi unutma
	groups.push_back(*current);
	dosya.close();
}

void ObjLoader::loadMtl(string fname) {
	ifstream dosya(fname.c_str());
	if(!dosya.is_open()) return;
	string temp;
	Material* current = 0;
	GLfloat x, y, z;
	while(dosya.good()) {
		dosya >> temp;
		if(temp.compare("newmtl") == 0) {
			dosya >> temp;
			if(current != 0) mtls.push_back(*current);
			current = new Material();
			current->name = temp;
		}
		else if(temp.compare("Ka") == 0) {
			dosya >> x >> y >> z;
			current->ambient[0] = x;
			current->ambient[1] = y;
			current->ambient[2] = z;
		}
		else if(temp.compare("Kd") == 0) {
			dosya >> x >> y >> z;
			current->diffuse[0] = x;
			current->diffuse[1] = y;
			current->diffuse[2] = z;
		}
		else if(temp.compare("Ks") == 0) {
			dosya >> x >> y >> z;
			current->specular[0] = x;
			current->specular[1] = y;
			current->specular[2] = z;
		}
		else if(temp.compare("Ns") == 0) {
			dosya >> x;
			current->ns = x;
		}
		else if(temp.compare("map_Kd") == 0) {
			dosya >> temp;
			current->mapKd = temp;
			textureFileCount++; // burada ayni isimle olabilme olasigini hesaba
								// henuz katmadim :(
		}
		else getline(dosya, temp);
	}
	mtls.push_back(*current);
	dosya.close();
}


