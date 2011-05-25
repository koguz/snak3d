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

#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include <string>
#include <vector>
#include "glheaders.h"
#include "Vector3.h"

using namespace std;

class TexNames {
public:
	int tid;
	string name;
};

class Object3D {
public:
	static vector<TexNames> texnames;
	Object3D();
	void translate(GLdouble px, GLdouble py, GLdouble pz);
	void rotatex(GLdouble a);
	void rotatey(GLdouble a);
	void rotatez(GLdouble a);
	void scale(GLdouble a);
	void scale(GLdouble x, GLdouble y, GLdouble z);
	void draw();
	virtual void drawMesh(); 
	GLdouble getX() { return x; }
	GLdouble getY() { return y; }
	GLdouble getZ() { return z; }
	Vector3 getPosition();
	
	int setTexture(string fname);//[], int tcount);
	int setTexture(string fname, bool edge);
protected:
	GLuint *texture; 
	int texcount;
	GLdouble x, y, z; // position
	GLdouble rotx, roty, rotz; // rotation
	GLdouble sx, sy, sz; // scale
	void init();
	bool wired;
};

#endif 
