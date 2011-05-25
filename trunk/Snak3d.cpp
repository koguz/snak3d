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
    glTranslated(0, 0, -4);
    glRotatef(20, 1, 0, 0);
    glutSolidCube(1);	
}


void Snak3d::collisionDetection() { 
	
}

void Snak3d::update(double a) {

}

