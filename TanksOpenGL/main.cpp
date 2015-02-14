#include <iostream>
#include <stdlib.h>
#include <GL\freeglut.h>
#include "Primitives.h"


void keyboard(unsigned char key, int x, int y);
void display(void);
void SpinCube(int);
void reshape(int, int);
GLdouble rotate_x(0.0);
GLdouble rotate_y(0.0);
GLdouble rotate_z(0.0);

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("GLUT Test");
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(&keyboard);
	glutDisplayFunc(&display);
	glutReshapeFunc(&reshape);
	glutTimerFunc(10, SpinCube, 0);
	glutMainLoop();
	return EXIT_SUCCESS;
}
void keyboard(unsigned char key, int x, int y) {
	switch(key) {
	case '\x1B':
		exit(EXIT_SUCCESS);
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
	if(rotate_x > 360)
		rotate_x -= 360;
	rotate_y += 1;
	if(rotate_y > 360)
		rotate_y -= 360;
	glutPostRedisplay();
	glutTimerFunc(10, SpinCube, n);
}

void display() {
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Main point
	glTranslatef(0.0, 0.0, -10.0);

	primitives::Box box(3, 2, 1, 1.5);
	box.rotate(rotate_x, rotate_y, rotate_z);
	box.draw();
	box.rotate(-rotate_x, rotate_y, -rotate_z);
	box.shiftBy(-3, 0, 0);
	box.draw();

	glFlush();
	glutSwapBuffers();

}