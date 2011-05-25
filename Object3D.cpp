/*
    This file is part of OpenGL Framework (glfw), which is a simple set of 
    classes to wrap OpenGL functionality. 
    Copyright (C) 2011  Kaya Oguz <kaya@oguz.name.tr>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "Object3D.h"

using namespace std;

vector<TexNames> Object3D::texnames;

Object3D::Object3D() {
	init();
};

void Object3D::init() {
	x = 0; y = 0; z = 0;
	rotx = 0; roty = 0; rotz = 0;
	sx = 1; sy = 1; sz = 1;
	wired = false;
	texture = 0;
	texcount = 0;
}

void Object3D::translate(GLdouble px, GLdouble py, GLdouble pz) {
	x += px; y += py; z += pz;
}

int Object3D::setTexture(string fname) {
    return setTexture(fname, false);
}

int Object3D::setTexture(string fname, bool edge=false) { 
	texture = new GLuint[1];
	texcount = 1; // obsolete :) 
	
	for(int i=0;i<texnames.size();i++) {
		if(texnames[i].name.compare(fname) == 0) {
			texture[0] = texnames[i].tid;
			glBindTexture(GL_TEXTURE_2D, texnames[i].tid);
			return texnames[i].tid;
		}
	}
	
	glGenTextures(1, texture);
	int w = 0;
	
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if(edge) {
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	} else {
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	
	ifstream::pos_type size;
	char* data;
	ifstream dosya(fname.c_str(), ios::in|ios::binary|ios::ate);
	if(dosya.is_open()) {
		size = dosya.tellg();
		w = sqrt((float)size/3.0);
		data = new char[size];
		dosya.seekg(0, ios::beg);
		dosya.read(data, size);
		dosya.close();
	}
	else return -1;
	
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, w, w, GL_RGB, GL_UNSIGNED_BYTE, data);
	delete[] data;
	
	TexNames yeni; yeni.name = fname; yeni.tid = texture[0];
	texnames.push_back(yeni);
	return texture[0];
}

void Object3D::rotatex(GLdouble a) {
	rotx = (rotx + a);
}
void Object3D::rotatey(GLdouble a) {
	roty = (roty + a);
}
void Object3D::rotatez(GLdouble a) {
	rotz = (rotz + a);
}

void Object3D::scale(GLdouble x, GLdouble y, GLdouble z) {
	sx *= x; sy *= y; sz *= z;
}

void Object3D::scale(GLdouble a) {
	sx *= a; sy *= a; sz *= a;
}

void Object3D::drawMesh() {
	if(wired)
		glutWireCube(1.0);
	else glutSolidTeapot(1.0);
}

void Object3D::draw() {
	glPushMatrix();
	    glTranslated(x, y, z);
	    glRotated(rotx, 1.0, 0.0, 0.0);
	    glRotated(roty, 0.0, 1.0, 0.0);
	    glRotated(rotz, 0.0, 0.0, 1.0);
	    glScaled(sx, sy, sz);
	
	if (texture != 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
	} else glDisable(GL_TEXTURE_2D);
	    drawMesh();
	glPopMatrix();
}

Vector3 Object3D::getPosition() {
	return Vector3(x, y, z);
}

