#pragma once
#include <GL\freeglut.h>
class WorldObject {
public:
	class RotationAngle {
	public:
		RotationAngle();
		// Get rotation angles
		const double& getX() const; // Get rotation angle around X axis
		const double& getY() const; // Get rotation angle around Y axis
		const double& getZ() const; // Get rotation angle around Z axis
		// Set absolute rotation angles
		void setX(double); // Set absolute rotation angle around X axis
		void setY(double); // Set absolute rotation angle around Y axis
		void setZ(double); // Set absolute rotation angle around Z axis
		// Set relative rotation angles
		void setXr(double); // Set relative (+-) rotation angle around X axis
		void setYr(double); // Set relative (+-) rotation angle around Y axis
		void setZr(double); // Set relative (+-) rotation angle around Z axis
	private:
		double xAngle, yAngle, zAngle; // Angle values
		double& getNormalAngle(double&) const; // Get angle as (0 <= angle < 360)
	};

	double x, y, z; // Center coordinates
	RotationAngle rotationAngle; // Object, containing rotation angles around axes

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
	virtual double getWidth() const; // Get width
	virtual double getLength() const; // Get length
	virtual double getHeight() const; // Get height
	// Set sizes
	virtual void setWidth(double); // Set width
	virtual void setLength(double); // Set length
	virtual void setHeight(double); // Set height
	// Get half sizes
	virtual double getHWidth() const; // Get width/2
	virtual double getHLength() const; // Get length/2
	virtual double getHHeight() const; // Get height/2
	// Transformations
	void rotate(double xAngle, double yAngle, double zAngle); // Simplify rotation by setting rotationAngle x, y, z values
	void rotateRelative(double xAngleDelta, double yAngleDelta, double zAngleDelta); // Change rotationAngle x, y, z values by relative values
	void moveTo(double x, double y, double z); // Change center coordinates
	void shiftBy(double xDelta, double yDelta, double zDelta); // Change center coordinates by relative values
protected:
private:
	double width, length, height; // Sizes
	double halfWidth, halfLength, halfHeight; // Half sizes
};