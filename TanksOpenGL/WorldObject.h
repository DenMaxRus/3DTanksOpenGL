#pragma once
#include "Point.h"
#include <GL\freeglut.h>
class WorldObject : public Point {
public:

	WorldObject(double width, double length, double height, double x = 0.0, double y = 0.0, double z = 0.0);
	virtual ~WorldObject();
	/*// Get center coordinates
	double getX() const;
	double getY() const;
	double getZ() const;
	// Set center coordinates
	void setX(double);
	void setY(double);
	void setZ(double);*/
	// Get sizes (should be calculated for each child class for more precise)
	virtual const double& getWidth() const; // Get width
	virtual const double& getLength() const; // Get length
	virtual const double& getHeight() const; // Get height
	// Set sizes
	virtual void setWidth(double); // Set width
	virtual void setLength(double); // Set length
	virtual void setHeight(double); // Set height
	// Get half sizes
	virtual const double& getHWidth() const; // Get width/2
	virtual const double& getHLength() const; // Get length/2
	virtual const double& getHHeight() const; // Get height/2

protected:
private:
	double width, length, height; // Sizes
	double halfWidth, halfLength, halfHeight; // Half sizes
};