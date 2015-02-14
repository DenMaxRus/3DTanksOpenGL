#define _USE_MATH_DEFINES
#include <cmath>

#include "Cylinder.h"


primitives::Cylinder::Cylinder(double height, double topRadius, double bottomRadius, int sides, double x, double y, double z)
	: DrawableObject(0.0, 0.0, height, x, y, z), bottomRadius(bottomRadius), topRadius(topRadius), sides(sides) {}

primitives::Cylinder::~Cylinder() {}

const double& primitives::Cylinder::getWidth() const { return bottomRadius > topRadius ? bottomRadius : topRadius; }
const double& primitives::Cylinder::getLength() const { return bottomRadius > topRadius ? bottomRadius : topRadius; }

void primitives::Cylinder::draw() const {
	glPushMatrix();
	// Transformations
	glTranslated(x, y, z);
	glRotated(rotationAngle.getX(), 1.0, 0.0, 0.0);
	glRotated(rotationAngle.getY(), 0.0, 1.0, 0.0);
	glRotated(rotationAngle.getZ(), 0.0, 0.0, 1.0);
	// Drawing
	for(double i(0.0), step(M_PI / sides), angle(step), prevTopX(topRadius), prevBotX(bottomRadius), prevTopY(0.0), prevBotY(0.0); i < sides * 2; angle += step, ++i) {
		double sinA(sin(angle)), cosA(cos(angle)), topY(topRadius*sinA), topX(topRadius*cosA), botY(bottomRadius*sinA), botX(bottomRadius * cosA);
		// TOP
		glBegin(GL_TRIANGLES);
		glColor3d(sinA, sinA, cosA);
		glVertex3d(0.0, getHHeight(), 0.0);
		glVertex3d(topX, getHHeight(), topY);
		glVertex3d(prevTopX, getHHeight(), prevTopY);
		glEnd();
		// BOTTOM
		glBegin(GL_TRIANGLES);
		glColor3d(sinA, cosA, cosA);
		glVertex3d(0.0, -getHHeight(), 0.0);
		glVertex3d(prevBotX, -getHHeight(), prevBotY);
		glVertex3d(botX, -getHHeight(), botY);
		glEnd();
		// SIDE
		glBegin(GL_QUADS);
		glColor3d(cosA, cosA, sinA);
		glVertex3d(prevBotX, -getHHeight(), prevBotY);
		glVertex3d(prevTopX, getHHeight(), prevTopY);
		glVertex3d(topX, getHHeight(), topY);
		glVertex3d(botX, -getHHeight(), botY);
		glEnd();

		prevTopX = topX;
		prevTopY = topY;
		prevBotX = botX;
		prevBotY = botY;
	}
	double s = getHWidth() - 5;
	glPopMatrix();
}