/*
 *  ObjModel.cpp
 *  glfw
 *
 *  Created by Kaya Oğuz on 19.05.2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ObjModel.h"
#include <iostream>

using namespace std;

ObjModel::ObjModel(string fn) {
	loader.loadObj(fn);
	areTexturesSet = false;
}

void ObjModel::setTextures() {
	for(int i=0;i<loader.groups.size();i++) {
		if(loader.groups[i].mtl.mapKd.compare("") != 0) {
			loader.groups[i].mtl.tid = setTexture(loader.groups[i].mtl.mapKd);
		}
	}
	areTexturesSet = true;
}

void ObjModel::drawMesh(){ 
	for(int i=0;i<loader.groups.size();i++) {
		for(int k=0;k<loader.groups[i].faces.size();k++) {
			glMaterialfv(GL_FRONT, GL_AMBIENT, loader.groups[i].mtl.ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, loader.groups[i].mtl.diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR,loader.groups[i].mtl.specular);
			glBindTexture(GL_TEXTURE_2D, loader.groups[i].mtl.tid);
			
			glBegin(GL_POLYGON);
			for(int j=0;j<loader.groups[i].faces[k].vertices.size();j++) {
				glTexCoord2f(loader.groups[i].faces[k].tcoords[j].x, 
							 1-loader.groups[i].faces[k].tcoords[j].y);
				
				glNormal3d(loader.groups[i].faces[k].normals[j].x, 
						   loader.groups[i].faces[k].normals[j].y, 
						   loader.groups[i].faces[k].normals[j].z); 
				
				glVertex3d(loader.groups[i].faces[k].vertices[j].x, 
						   loader.groups[i].faces[k].vertices[j].y, 
						   loader.groups[i].faces[k].vertices[j].z);
				
			}
			glEnd();
		}
	} 
	
}

