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

#include "Light.h"

Light::Light(int a) {
	switch (a) {
		case 0:
			n = GL_LIGHT0;
			break;
		case 1:
			n = GL_LIGHT1;
			break;
		case 2:
			n = GL_LIGHT2;
			break;
		case 3:
			n = GL_LIGHT3;
			break;
		default:
			break;
	}
	pos = new GLfloat[4];
	ambient = new GLfloat[4];
	diffuse = new GLfloat[4];
	specular = new GLfloat[4];
	pos[0] = 0; pos[1] = 0.4; pos[2] = 1; pos[3] = 0;
	ambient[0] = 0.5; ambient[1] = 0.5; ambient[2] = 0.5; ambient[3] = 1;
	diffuse[0] = diffuse[1] = diffuse[2] = diffuse[3] = 1;
	specular[0] = specular[1] = specular[2] = specular[3] = 1;
}

void Light::init() {
	glEnable(n);
	glLightfv(n, GL_POSITION, pos);
	glLightfv(n, GL_AMBIENT, ambient);
	glLightfv(n, GL_DIFFUSE, diffuse);
	glLightfv(n, GL_SPECULAR, specular);
}
