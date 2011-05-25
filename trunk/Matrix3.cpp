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

#include <cmath>
#include "Matrix3.h"

const double PI = 3.1415926f;

Matrix3::Matrix3() {
	_11 = 1; _21 = 0; _31 = 0; _41 = 0;
	_12 = 0; _22 = 1; _32 = 0; _42 = 0;
	_13 = 0; _23 = 0; _33 = 1; _43 = 0;
	_14 = 0; _24 = 0; _34 = 0; _44 = 1;
}


void Matrix3::setRotationX(double degree) {
	double radian = degree*PI/180;
	_22 = _33 = cos(radian);
	_32 =  sin(radian);
	_23 = -_32;
}

void Matrix3::setRotationY(double degree) {
	double radian = degree*PI/180;
	_11 = _33 = cos(radian);
	_13 = sin(radian);
	_31 = -_13;
}

void Matrix3::setRotationZ(double degree) {
	double radian = degree*PI/180;
	_11 = _22 = cos(radian);
	_21 = sin(radian);
	_12 = -_21;
}

void Matrix3::setTranslation(double x, double y, double z) {
	_14 = x; _24 = y; _34 = z;
}

void Matrix3::setScale(double x, double y, double z) {
	_11 = x; _22 = y; _33 = z;
}

void Matrix3::setScale(double s) {
	setScale(s, s, s);
}



