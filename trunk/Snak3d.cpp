/*
 *  NFSGame.cpp
 *  glfw
 *
 *  Created by Kaya Oğuz on 21.05.2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <cmath>
#include "Vector3.h"
#include "Snak3d.h"

Snak3d::Snak3d() {
	points = 0;
	sure = 0;
	p = 0;
}

int Snak3d::getPoints() {
	return points;
}
int Snak3d::getRemainingSeconds() {
    return 0;
}

void Snak3d::init() {
}

void Snak3d::draw() {
	glTranslatef(0, 0, -12);
	glRotatef(p, 0, 1, 0);
	glColor3f(0.2, 0.2, 0.3);
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			for(int k=0;k<10;k++) {
				glPushMatrix();
				glTranslatef(i-5, j-5, k-5);
				glutSolidCube(0.7);
				glPopMatrix();
			}
		}
	}
	//GLfloat vertices[] = { 1, -1, -1, 1, -1, 1, -1, -1, 1};
}


void Snak3d::collisionDetection() { 
	
}

void Snak3d::update(double a) {
	p++;
}

