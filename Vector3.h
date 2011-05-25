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

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include "Matrix3.h"

class Vector3 {
public:
	Vector3();
	Vector3(double, double, double);
	double getx();
	double gety();
	double getz();
	double length();
	Vector3 multiplyMatrix(Matrix3 m);
	void rotatex(double d);
	void rotatey(double d);
	void rotatez(double d);
	void scale(double s);
	void translate(double, double, double);
	double _11, _21, _31, _41;
	Vector3 operator+(const Vector3 a);
	Vector3 operator-(const Vector3 a);
	Vector3 operator*(const double d);
	Vector3 operator/(const double d);
	void printMe();
};

#endif
