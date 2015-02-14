#include <iostream>
#include <stdlib.h>
#include <GL\freeglut.h>
#include "Primitives.h"


void keyboard(unsigned char key, int x, int y);
void display(void);
void SpinCube(int);
void resize(int, int);
GLfloat rotate_x(0);
GLfloat rotate_y(0);

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("GLUT Test");
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(&keyboard);
	glutDisplayFunc(&display);
	glutReshapeFunc(resize);
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

void resize(int width, int height) {
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

	// Other Transformations
	glTranslatef(0.0, 0.0, -10.0);

	primitives::Plane plane(1, 5);
	plane.rotationAngle.setX(90);
	glColor3d(0.0, 1.0, 0.0);
	plane.draw();

	// Rotate when user changes rotate_x and rotate_y
	/*glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);*/

	// Other Transformations
	// glScalef( 2.0, 2.0, 0.0 );          // Not included

	//Multi-colored side - FRONT
	/*glBegin(GL_POLYGON);
	glVertex3d(1.0, 0.0, 0.0);     glVertex3d(0.5, -0.5, -0.5);      // P1 is red
	glVertex3d(0.0, 1.0, 0.0);     glVertex3d(0.5, 0.5, -0.5);      // P2 is green
	glVertex3d(0.0, 0.0, 1.0);     glVertex3d(-0.5, 0.5, -0.5);      // P3 is blue
	glVertex3d(1.0, 0.0, 1.0);     glVertex3d(-0.5, -0.5, -0.5);      // P4 is purple
	glEnd();

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 1.0);
	glVertex3d(0.5, -0.5, 0.5);
	glVertex3d(0.5, 0.5, 0.5);
	glVertex3d(-0.5, 0.5, 0.5);
	glVertex3d(-0.5, -0.5, 0.5);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3d(1.0, 0.0, 1.0);
	glVertex3d(0.5, -0.5, -0.5);
	glVertex3d(0.5, 0.5, -0.5);
	glVertex3d(0.5, 0.5, 0.5);
	glVertex3d(0.5, -0.5, 0.5);
	glEnd();
	
	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3d(0.0, 1.0, 0.0);
	glVertex3d(-0.5, -0.5, 0.5);
	glVertex3d(-0.5, 0.5, 0.5);
	glVertex3d(-0.5, 0.5, -0.5);
	glVertex3d(-0.5, -0.5, -0.5);
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3d(0.0, 0.0, 1.0);
	glVertex3d(0.5, 0.5, 0.5);
	glVertex3d(0.5, 0.5, -0.5);
	glVertex3d(-0.5, 0.5, -0.5);
	glVertex3d(-0.5, 0.5, 0.5);
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3d(1.0, 0.0, 0.0);
	glVertex3d(0.5, -0.5, -0.5);
	glVertex3d(0.5, -0.5, 0.5);
	glVertex3d(-0.5, -0.5, 0.5);
	glVertex3d(-0.5, -0.5, -0.5);
	glEnd();
	// Draw gun
	glTranslated(1.5, 0.0, 0.0);
	glRotated(rotate_x, 1.0, 0.0, 0.0);
	//Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glColor3d(1.0, 0.0, 0.0);     glVertex3d(-1.5, 0.2, 0.2);      // P1 is red
	glColor3d(0.0, 1.0, 0.0);     glVertex3d(1.5, 0.2, 0.2);      // P2 is green
	glColor3d(0.0, 0.0, 1.0);     glVertex3d(1.5, -0.2, 0.2);      // P3 is blue
	glColor3d(1.0, 0.0, 1.0);     glVertex3d(-1.5, -0.2, 0.2);      // P4 is purple
	glEnd();

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 1.0);
	glVertex3d(-1.5, 0.2, -0.2);
	glVertex3d(1.5, 0.2, -0.2);
	glVertex3d(1.5, -0.2, -0.2);
	glVertex3d(-1.5, -0.2, -0.2);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3d(1.0, 0.0, 1.0);
	glVertex3d(1.5, 0.2, 0.2);
	glVertex3d(1.5, 0.2, -0.2);
	glVertex3d(1.5, -0.2, -0.2);
	glVertex3d(1.5, -0.2, 0.2);
	glEnd();

	// Green side - LEFT : not needed

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3d(0.0, 0.0, 1.0);
	glVertex3d(-1.5, 0.2, 0.2);
	glVertex3d(-1.5, 0.2, -0.2);
	glVertex3d(1.5, 0.2, -0.2);
	glVertex3d(1.5, 0.2, 0.2);
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3d(1.0, 0.0, 0.0);
	glVertex3d(-1.5, -0.2, 0.2);
	glVertex3d(1.5, -0.2, 0.2);
	glVertex3d(1.5, -0.2, -0.2);
	glVertex3d(-1.5, -0.2, -0.2);
	glEnd();*/

	glFlush();
	glutSwapBuffers();

}