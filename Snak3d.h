/*
 *  Snak3d.h
 *  glfw
 *
 *  Created by Kaya Oğuz on 21.05.2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SNAK3D_H_
#define SNAK3D_H_

#include "glheaders.h"
#include "Camera.h"

class Snak3d {
public:
	Snak3d();
	void init();
	void update(double t); // frame independent 
	void draw();
	int getPoints();
	int getRemainingSeconds();
private:
	Camera kamera;
	void collisionDetection();
	int points;
	int sure;
};

#endif

