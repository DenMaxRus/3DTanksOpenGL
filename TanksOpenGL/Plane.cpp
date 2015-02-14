#include <GL\freeglut.h>
#include "NotImplementedException.h"
#include "Plane.h"

primitives::Plane::Plane(double width, double length, double x, double y, double z) : DrawableObject(width, length, 0.0, x, y, z) {}

primitives::Plane::~Plane() {}

void primitives::Plane::draw() const {
	glPushMatrix();
	// Transformations
	glTranslated(x, y, z);
	glRotated(rotationAngle.getX(), 1.0, 0.0, 0.0);
	glRotated(rotationAngle.getY(), 0.0, 1.0, 0.0);
	glRotated(rotationAngle.getZ(), 0.0, 0.0, 1.0);
	// Drawing
	glBegin(GL_QUADS);
	glVertex3d(-getHWidth(), 0.0, getHLength());
	glVertex3d(-getHWidth(), 0.0, -getHLength());
	glVertex3d(getHWidth(), 0.0, -getHLength());
	glVertex3d(getHWidth(), 0.0, getHLength());
	glEnd();

	glPopMatrix();
}
