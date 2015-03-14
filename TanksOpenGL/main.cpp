#define _USE_MATH_DEFINES
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <chrono>

#include <GL\freeglut.h>

#include "Primitives.h"
#include "OperatableObject.h"

void keyPressed(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void keysOperations();
void mainTimer(int);
void special(int, int, int);
void display(void);
void SpinCube(int);
void reshape(int, int);
bool *keyStates = new bool[256]{false};
GLdouble rotate_x(0.0);
GLdouble rotate_y(0.0);
GLdouble rotate_z(0.0);
primitives::Box body(3.0, 5.0, 1.0, 0.0, 0.5);
primitives::Cylinder tower(0.7, 1.0, 1.2, 5, false, true, 0.0, 0.85);
primitives::Cylinder gun(3.0, 0.15, 0.15, 5, false, true, 0.0, 0.85, 2.5);
int acceleration(0);
double speed(0.0), verticalSpeed(0.0), accelerationValue(0.0), frictionValue(0.30), mass(1.0), heightMap[50][50], engineForce(10.0);
std::chrono::system_clock::time_point prevTime;
const double smallG(9.8);

int main(int argc, char* argv[]) {
	gun.rotationAngle.setX(90.0);
	bool f(true);
	for(size_t i(0); i < 50; ++i) {
		for(size_t j(0); j < 50; ++j) {
			heightMap[i][j] = f ? 0 : 0.5;
			f = !f;
		}
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("GLUT Test");
	glViewport(0, 0, 800, 600);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyUp);
	glutSpecialFunc(&special);
	glutDisplayFunc(&display);
	glutReshapeFunc(&reshape);
	glutTimerFunc(40, &mainTimer, 0);
	glEnable(GL_CULL_FACE);
	prevTime = std::chrono::steady_clock::now();
	glutMainLoop();
	return EXIT_SUCCESS;
}
void keyPressed(unsigned char key, int x, int y) {
	keyStates[key] = true;
}
void keyUp(unsigned char key, int x, int y) {
	keyStates[key] = false;
}
void keysOperations() {
	if(keyStates['a']) {
		body.rotationAngle.setYr(5);
	} else if(keyStates['d']) {
		body.rotationAngle.setYr(-5);
	}
	if(keyStates['w']) {
		acceleration = 1;
	} else if(keyStates['s']) {
		acceleration = -1;
	} else {
		acceleration = 0;
	}
	if(keyStates['\x1B']) {
		body.moveTo(0, 0, 0);
		body.rotate(0, 0, 0);
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
	gluPerspective(90.0, width / (double)height, 0.1, 120.0);
	//gluLookAt(0, 0, -5, 0, 0, 0, 0, 100, 0);
	glMatrixMode(GL_MODELVIEW);
}

void physics(std::chrono::milliseconds &timestep) {
	//std::cout << timestep.count() << std::endl;
	/*if(acceleration) // Acceleration ON
		speed += acceleration*accelerationValue;
	if(speed) { // Add friction influence
		double frictionInfluence(frictionValue * mass);
		if(fabs(speed) <= frictionInfluence)
			speed = 0.0;
		else {
			speed += speed > 0.0 ? -frictionInfluence : frictionInfluence;
			// Limit speed

		}
	}*/
	std::cout << body.y << std::endl;
	double timestepSeconds = timestep.count() / 1000.0,
		sinA(sin(body.rotationAngle.getY() * M_PI / 180.0)),
		cosA(cos(body.rotationAngle.getY() * M_PI / 180.0)),
		dZ(timestepSeconds * (speed + timestepSeconds * accelerationValue / 2)*cosA),
		dX(timestepSeconds * (speed + timestepSeconds * accelerationValue / 2)*sinA),
		dY(timestepSeconds * (verticalSpeed + timestepSeconds * smallG / 2));
	body.shiftBy(dX, 0.0, dZ);

	verticalSpeed += timestepSeconds * smallG;

	double newAccelerationValue = 0;
	if(acceleration)
		newAccelerationValue += acceleration * engineForce;
	if(speed)
		newAccelerationValue -= (speed > 0 ? frictionValue : -frictionValue) * smallG;
	speed += timestepSeconds * (accelerationValue + newAccelerationValue) / 2;
	if(fabs(speed) > 8.0)
		speed = speed > 0.0 ? 8.0 : -8.0;
	else if(fabs(speed) < 0.1)
		speed = 0.0;
	accelerationValue = newAccelerationValue;

}

void mainTimer(int n) {
	keysOperations();
	auto currentTime = std::chrono::system_clock::now();
	physics(std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - prevTime));
	prevTime = currentTime;
	/*signed long int x(body.x), z(body.z);
	double Px(body.x - x), Dy(heightMap[x + 26][z + 26] - heightMap[x + 25][z + 25]),
	ddY(heightMap[x + 25][z + 25]+Px*Dy);
	body.y = ddY;*/
	glutPostRedisplay();
	glutTimerFunc(40, &mainTimer, n);
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
	//glutTimerFunc(10, &SpinCube, n);
}

void display() {
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Main point
	glTranslatef(0.0, -5.0, -15.0);
	glRotated(35.0, 1.0, 0.0, 0.0);

	glColor3d(0.62, 0.85, 0.43);
	// Draw surface
	for(int i(0); i < 50; ++i) {
		for(int j(0); j < 50; ++j) {

			glBegin(GL_QUADS);
			glVertex3d(j - 25, heightMap[j][i], i - 25);
			glVertex3d(j - 25, heightMap[j][i + 1], i - 24);
			glVertex3d(j - 24, heightMap[j + 1][i + 1], i - 24);
			glVertex3d(j - 24, heightMap[j + 1][i], i - 25);
			glEnd();

		}
	}

	body.draw();
	tower.draw();
	gun.draw();
	glFlush();
	glutSwapBuffers();
}