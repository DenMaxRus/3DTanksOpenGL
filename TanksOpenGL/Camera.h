#pragma once
#include "Point.h"
#include <GL\freeglut.h>

class Camera :
	public Point {
public:
	enum ViewType { FIRST_P, THIRD_P, FREE };

	Camera(double x, double y, double z);
	~Camera();

	const ViewType& getViewType() const;
	const double& getDistance() const;

	void setViewType(ViewType);
	void setDistance(double);
	void setDistanceRelative(double);

	void linkTo(const Point&);
	void setCamera() const;
private:
	double distance;
	const Point *target;
	ViewType currentViewType;
};

