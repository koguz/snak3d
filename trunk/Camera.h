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

#ifndef CAMERA_H_
#define CAMERA_H_

#include "glheaders.h"
#include "Vector3.h"

class Camera {
public:
	Camera();
	void setPosition(GLdouble x, GLdouble y, GLdouble z);
	void setPosition(Vector3 p);
	void setLookAt(GLdouble x, GLdouble y, GLdouble z);
	void setLookAt(Vector3 l);
	void setUp(GLdouble x, GLdouble y, GLdouble z);
	Vector3 getPosition();
	void update();
private:
	GLdouble posx, posy, posz;
	GLdouble lx, ly, lz;
	GLdouble upx, upy, upz;
};

#endif
