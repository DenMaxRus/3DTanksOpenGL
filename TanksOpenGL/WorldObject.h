#pragma once
#include <GL\freeglut.h>
class WorldObject {
public:
	class RotationAngle {
	public:
		RotationAngle();
		// Get rotation angles
		const double& getX() const;
		const double& getY() const;
		const double& getZ() const;
		// Set rotation angles
		void setX(double);
		void setY(double);
		void setZ(double);
	private:
		double x, y, z; // Rotation angle values
		double& getNormalAngle(double&) const; // Get angle as (0 <= angle < 360)
	};

	double x, y, z; // Center coordinates
	RotationAngle rotationAngle; // Rotation angles

	WorldObject(double width, double length, double height, double x = 0.0, double y = 0.0, double z = 0.0);
	virtual ~WorldObject();
	// Get sizes (should be calculated for each child class for more precise)
	virtual double getWidth() const;
	virtual double getLength() const;
	virtual double getHeight() const;
	void rotate(double x, double y, double z); // Simplify rotation by setting rotationAngle x, y, z values 
private:
	double width, length, height; // Sizes
};