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

#include "Camera.h"

Camera::Camera() {
	posx = 0; posy = 0; posz = 0;
	lx = 0; ly = 0; lz = -10;
	upx = 0; upy = 1; upz = 0;
}

Vector3 Camera::getPosition() {
	return Vector3(posx, posy, posz);
}

void Camera::setPosition(GLdouble x, GLdouble y, GLdouble z) {
	posx = x; posy = y; posz = z;
}

void Camera::setPosition(Vector3 p) {
	setPosition(p.getx(), p.gety(), p.getz());
}

void Camera::setLookAt(GLdouble x, GLdouble y, GLdouble z) {
	lx = x; ly = y; lz = z;
}

void Camera::setLookAt(Vector3 p) {
	setLookAt(p.getx(), p.gety(), p.getz());
}

void Camera::setUp(GLdouble x, GLdouble y, GLdouble z) {
	upx = x; upy = y; upz = z;
}

void Camera::update() {
	gluLookAt(posx, posy, posz, lx, ly, lz, upx, upy, upz);
}

