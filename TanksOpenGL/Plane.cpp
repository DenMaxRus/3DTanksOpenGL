#include <GL\freeglut.h>
#include "NotImplementedException.h"
#include "Plane.h"

primitives::Plane::Plane(double width, double length, double x, double y, double z) : DrawableObject(width, length, 0.0, x, y, z) {}

primitives::Plane::~Plane() {}

void primitives::Plane::draw() {
	glPushMatrix();
	// Transformations
	glTranslated(x, y, z);
	glRotated(rotationAngle.getX(), 1.0, 0.0, 0.0);
	glRotated(rotationAngle.getY(), 0.0, 1.0, 0.0);
	glRotated(rotationAngle.getZ(), 0.0, 0.0, 1.0);
	// Drawing
	double halfWidth(getWidth() / 2.0), halfLength(getLength() / 2.0); // TODO Make this variables as fields in WorldObject
	glBegin(GL_POLYGON);
	glVertex3d(-halfWidth, 0.0, halfLength);
	glVertex3d(-halfWidth, 0.0, -halfLength);
	glVertex3d(halfWidth, 0.0, -halfLength);
	glVertex3d(halfWidth, 0.0, halfLength);
	glEnd();

	glPopMatrix();
}
