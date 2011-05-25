/*
 *  ObjModel.h
 *  glfw
 *
 *  Created by Kaya Oğuz on 19.05.2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
 
#ifndef OBJMODEL_H_
#define OBJMODEL_H_

#include <string>
#include "glheaders.h"
#include "Object3D.h"
#include "ObjLoader.h"

using namespace std;

class ObjModel:public Object3D {
private:
	ObjLoader loader;
public:
	bool areTexturesSet;
	ObjModel(string fn);
	virtual void drawMesh();
	void setTextures();
};

#endif

