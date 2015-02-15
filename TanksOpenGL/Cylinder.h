#pragma once
#include "WorldObject.h"
#include "DrawableObject.h"
namespace primitives {
	class Cylinder :
		public WorldObject,
		public DrawableObject {
	public:
		Cylinder(double height, double topRadius, double bottomRadius, int sides, bool renderBottom = true, bool renderTop = true, double x = 0.0, double y = 0.0, double z = 0.0);
		~Cylinder();

		virtual const double& getWidth() const override;
		virtual const double& getLength() const override;
		virtual void draw() const override;
	private:
		bool renderBottom, renderTop;
		unsigned int sides; // Top & bottom circles sides count
		double bottomRadius, topRadius;
	};
}