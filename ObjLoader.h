/*
 *  ObjLoader.h
 *  objloader
 *
 *  Created by Kaya Oğuz on 19.05.2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OBJLOADER_H_
#define OBJLOADER_H_

#include <string>
#include <vector>
#include <iostream>
#include "glheaders.h"

using namespace std;

class Vertex2 {
public:
	GLdouble x, y;
	Vertex2() { x = 0; y = 0; }
	void set(GLdouble a, GLdouble b) {
		x = a; y = b; 
	}
};

class Vertex3 {
public:
	GLdouble x, y, z;
	Vertex3() { x = 0; y = 0; z = 0; }
	void set(GLdouble a, GLdouble b, GLdouble c) {
		x = a; y = b; z = c;
	}
};

class Face {
public:
	vector<Vertex3> vertices;
	vector<Vertex3> normals;
	vector<Vertex2> tcoords;
};

class Material {
public:
	Material() {
		for(int i=0;i<3;i++) {
			ambient[i] = 0;
			diffuse[i] = 0;
			specular[i]= 0;
		}
		ns = 0;
		mapKd = "";
		tid = 0;
	}
	string name;
	GLfloat ambient[3];
	GLfloat diffuse[3];
	GLfloat specular[3];
	GLfloat ns;
	string mapKd;
	GLuint tid; // texture id
	void removeTexture() {
		if(tid != 0) glDeleteTextures(1, &tid);
	}
};

class Group {
public:
	string name;
	vector<Face> faces;
	Material mtl;
};

class ObjLoader {
public:
	ObjLoader();
	void loadObj(string fname);
	vector<Group> groups;
	vector<Material> mtls;
	int textureFileCount;
private:
	void loadMtl(string fname);
};

#endif

