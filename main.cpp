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

#include <ctime>
#include "glheaders.h"
#include "Light.h"
#include "Snak3d.h"

const int fps = 1000/60; // set frame rate here
bool* keyStates = new bool[256];
Snak3d oyun;

Light anaIsik(0);

void init(void) {
	for(int i=0;i<256;i++) keyStates[i] = false;
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	anaIsik.init();
	oyun.init();
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -3.0/4.0, 3.0/4.0, 1, 2000);
	glMatrixMode(GL_MODELVIEW);
}

void keyOperations() {
    if(keyStates[27]) {  // 27 is -> ESC key
        exit(0);
    }
}

void display() {
	keyOperations();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	oyun.draw();
	glutSwapBuffers();
}

void timerFunc(int t) {
    int basla = glutGet(GLUT_ELAPSED_TIME);
    int elapsedTime = basla - t;
    //oyun.update(elapsedTime);
	glutPostRedisplay();
    int bitir = glutGet(GLUT_ELAPSED_TIME);
    glutTimerFunc(fps - (bitir-basla), timerFunc, bitir);
}

void keyPressed(unsigned char key, int x, int y) {
    keyStates[key] = true;
}

void keyUp(unsigned char key, int x, int y) {
    keyStates[key] = false;
}

int main (int argc, char ** const argv) { 
	srand(time(NULL)); // seed once
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Snak3D");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glutTimerFunc(fps, timerFunc, 0);
	
	glutMainLoop();
    return 0;
}
