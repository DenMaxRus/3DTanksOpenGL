#include <GL\freeglut.h>
#include "NotImplementedException.h"
#include "Box.h"

primitives::Box::Box(double width, double length, double height, double x, double y, double z) : DrawableObject(width, length, height, x, y, z) {}

primitives::Box::~Box() {}

void primitives::Box::draw() {
	glPushMatrix();
	// Transformations
	glTranslated(x, y, z);
	glRotated(rotationAngle.getX(), 1.0, 0.0, 0.0);
	glRotated(rotationAngle.getY(), 0.0, 1.0, 0.0);
	glRotated(rotationAngle.getZ(), 0.0, 0.0, 1.0);
	// Drawing
	// FRONT
	glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 1.0); // WHITE TODO Remove
	glVertex3d(-getHWidth(), -getHHeight(), getHLength());
	glVertex3d(-getHWidth(), getHHeight(), getHLength());
	glVertex3d(getHWidth(), getHHeight(), getHLength());
	glVertex3d(getHWidth(), -getHHeight(), getHLength());
	glEnd();
	// BACK
	glBegin(GL_POLYGON);
	glColor3d(0.0, 1.0, 0.0); // GREEN TODO Remove
	glVertex3d(-getHWidth(), -getHHeight(), -getHLength());
	glVertex3d(getHWidth(), -getHHeight(), -getHLength());
	glVertex3d(getHWidth(), getHHeight(), -getHLength());
	glVertex3d(-getHWidth(), getHHeight(), -getHLength());
	glEnd();
	// LEFT
	glBegin(GL_POLYGON);
	glColor3d(0.0, 0.0, 1.0); // BLUE TODO Remove
	glVertex3d(-getHWidth(), -getHHeight(), getHLength());
	glVertex3d(-getHWidth(), -getHHeight(), -getHLength());
	glVertex3d(-getHWidth(), getHHeight(), -getHLength());
	glVertex3d(-getHWidth(), getHHeight(), getHLength());
	glEnd();
	// RIGHT
	glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 0.0); // YELLOW TODO Remove
	glVertex3d(getHWidth(), -getHHeight(), getHLength());
	glVertex3d(getHWidth(), -getHHeight(), -getHLength());
	glVertex3d(getHWidth(), getHHeight(), -getHLength());
	glVertex3d(getHWidth(), getHHeight(), getHLength());
	glEnd();
	// TOP
	glBegin(GL_POLYGON);
	glColor3d(1.0, 0.0, 0.0); // RED TODO Remove
	glVertex3d(-getHWidth(), getHHeight(), getHLength());
	glVertex3d(-getHWidth(), getHHeight(), -getHLength());
	glVertex3d(getHWidth(), getHHeight(), -getHLength());
	glVertex3d(getHWidth(), getHHeight(), getHLength());
	glEnd();
	// BOTTOM
	glBegin(GL_POLYGON);
	glColor3d(0.0, 1.0, 1.0); // PURPLE TODO Remove
	glVertex3d(-getHWidth(), -getHHeight(), getHLength());
	glVertex3d(getHWidth(), -getHHeight(), getHLength());
	glVertex3d(getHWidth(), -getHHeight(), -getHLength());
	glVertex3d(-getHWidth(), -getHHeight(), -getHLength());
	glEnd();

	glPopMatrix();
}