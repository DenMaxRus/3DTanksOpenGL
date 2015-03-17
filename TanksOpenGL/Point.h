#pragma once
class Point {
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

	Point(double x, double y, double z);
	virtual ~Point();

	// Transformations
	virtual void rotate(double xAngle, double yAngle, double zAngle); // Simplify rotation by setting rotationAngle x, y, z values
	void rotateRelative(double xAngleDelta, double yAngleDelta, double zAngleDelta); // Change rotationAngle x, y, z values by relative values
	void moveTo(double x, double y, double z); // Change center coordinates
	void shiftBy(double xDelta, double yDelta, double zDelta); // Change center coordinates by relative values
};

