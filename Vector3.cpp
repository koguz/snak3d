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
#include "Vector3.h"
#include <iostream>
using namespace std;

void Vector3::printMe() {
	cout << _11 << ", " << _21 << ", " << _31 << endl;
}

Vector3::Vector3() {
	_11 = 0; _21 = 0; _31 = 0; _41 = 1;
}

Vector3::Vector3(double x, double y, double z) {
	_11 = x; _21 = y; _31 = z;
}

double Vector3::getx() { return _11; }
double Vector3::gety() { return _21; }
double Vector3::getz() { return _31; }

Vector3 Vector3::multiplyMatrix(Matrix3 m) {
	Vector3 r;
	r._11 = (_11 * m._11) + (_21 * m._12) + (_31 * m._13) + (_41 * m._14);
	r._21 = (_11 * m._21) + (_21 * m._22) + (_31 * m._23) + (_41 * m._24);
	r._31 = (_11 * m._31) + (_21 * m._32) + (_31 * m._33) + (_41 * m._34);
	r._41 = (_11 * m._41) + (_21 * m._42) + (_31 * m._43) + (_41 * m._44);
	return r;
}

double Vector3::length() {
	return sqrt(pow(_11, 2) + pow(_21, 2) + pow(_31, 2));
}

void Vector3::rotatex(double d) {
	Matrix3 m;
	m.setRotationX(d);
}

Vector3 Vector3::operator+(Vector3 a) {
	return Vector3(a.getx()+getx(), a.gety()+gety(), a.getz()+getz());
}
Vector3 Vector3::operator-(Vector3 a) {
	return Vector3(a.getx()-getx(), a.gety()-gety(), a.getz()-getz());
}
Vector3 Vector3::operator*(const double d) {
	Vector3 v = *this;
	return Vector3(v.getx()*d, v.gety()*d, v.getz()*d);
}
Vector3 Vector3::operator/(const double d) {
	Vector3 v = *this;
	return Vector3(v.getx()/d, v.gety()/d, v.getz()/d);
}
