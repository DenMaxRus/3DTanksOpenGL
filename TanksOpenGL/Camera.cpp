#include "Camera.h"


Camera::Camera(double x, double y, double z) : Point(x, y, z), distance(0.0), target(nullptr) {}

Camera::~Camera() {}

const Camera::ViewType& Camera::getViewType() const { return currentViewType; }
const double& Camera::getDistance() const { return distance; }

void Camera::setViewType(ViewType value) { currentViewType = value; }
void Camera::setDistance(double value) {
	if(value >= 0.0)
		distance = value;
}
void Camera::setDistanceRelative(double value) {
	setDistance(distance + value);
}

void Camera::linkTo(const Point& target) {
	this->target = &target;
}

void Camera::setCamera() const {
	switch(currentViewType) {
		case THIRD_P:
			glTranslated(0.0, 0.0, -distance);
			glRotated(-rotationAngle.getX(), 1.0, 0.0, 0.0);
			glRotated(-rotationAngle.getY(), 0.0, 1.0, 0.0);
			glRotated(-rotationAngle.getZ(), 0.0, 0.0, 1.0);
			glTranslated(-target->x, -target->y - 1.0, -target->z);
			break;
		case FIRST_P:
			glRotated(rotationAngle.getX(), 1.0, 0.0, 0.0);
			glRotated(rotationAngle.getY(), 0.0, 1.0, 0.0);
			glRotated(rotationAngle.getZ(), 0.0, 0.0, 1.0);
			glTranslated(-target->x, -target->y - 1.0, -target->z);
			break;
		case FREE:
			glTranslated(-x, -y, -z);
			glRotated(-rotationAngle.getX(), 1.0, 0.0, 0.0);
			glRotated(-rotationAngle.getY(), 0.0, 1.0, 0.0);
			glRotated(-rotationAngle.getZ(), 0.0, 0.0, 1.0);
			break;
	}
}