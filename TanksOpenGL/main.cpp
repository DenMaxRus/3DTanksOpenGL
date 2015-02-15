#define _USE_MATH_DEFINES
#include <iostream>
#include <stdlib.h>
#include <cmath>

#include <GL\freeglut.h>

#include "Primitives.h"

void keyboard(unsigned char key, int x, int y);
void special(int, int, int);
void display(void);
void SpinCube(int);
void reshape(int, int);
GLdouble rotate_x(0.0);
GLdouble rotate_y(0.0);
GLdouble rotate_z(0.0);
primitives::Box body(3.0, 5.0, 1.0);
primitives::Cylinder tower(0.7, 1.0, 1.2, 5, false, true, 0.0, 0.85);
primitives::Cylinder gun(3.0, 0.15, 0.15, 5, false, true, 0.0, 0.85, 2.5);

int main(int argc, char* argv[]) {
	gun.rotationAngle.setX(90.0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("GLUT Test");
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(&keyboard);
	glutSpecialFunc(&special);
	glutDisplayFunc(&display);
	glutReshapeFunc(&reshape);
	glutTimerFunc(10, &SpinCube, 0);
	glEnable(GL_CULL_FACE);
	glutMainLoop();
	return EXIT_SUCCESS;
}
void keyboard(unsigned char key, int x, int y) {
	switch(key) {
	case '\x1B':
		body.moveTo(0, 0, 0);
		body.rotate(0, 0, 0);
		break;
	case 'w':{
		double sinA(sin(body.rotationAngle.getY() * M_PI / 180.0)), cosA(cos(body.rotationAngle.getY() * M_PI / 180.0)), topY(1.0*cosA), topX(1.0*sinA);
		body.shiftBy(topX, 0.0, topY);
	}
		break;
	case 's':{
		double sinA(sin(body.rotationAngle.getY() * M_PI / 180.0)), cosA(cos(body.rotationAngle.getY() * M_PI / 180.0)), topY(-1.0*cosA), topX(-1.0*sinA);
		body.shiftBy(topX, 0.0, topY);
	}
		break;
	case 'a':
		body.rotationAngle.setYr(5);
		break;
	case 'd':
		body.rotationAngle.setYr(-5);
		break;
	}
}

void special(int key, int x, int y) {
	switch(key) {
	case GLUT_KEY_UP:
		//do something here
		break;
	case GLUT_KEY_DOWN:
		//do something here
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
	}
}

void reshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, width / (double)height, 0.1, 50.0);
	//gluLookAt(0, 0, -5, 0, 0, 0, 0, 100, 0);
	glMatrixMode(GL_MODELVIEW);
}

void SpinCube(int n) {
	rotate_x += 1;
	if(rotate_x >= 360)
		rotate_x -= 360;
	rotate_y += 1;
	if(rotate_y >= 360)
		rotate_y -= 360;
	rotate_z += 1;
	if(rotate_z >= 360)
		rotate_z -= 360;
	glutPostRedisplay();
	glutTimerFunc(10, SpinCube, n);
}

void display() {
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Reset transformations
	glLoadIdentity();
	
	// Main point
	glTranslatef(0.0, -5.0, -15.0);
	glRotated(35.0, 1.0, 0.0, 0.0);
	body.draw();
	tower.draw();
	gun.draw();
	glFlush();
	glutSwapBuffers();
}