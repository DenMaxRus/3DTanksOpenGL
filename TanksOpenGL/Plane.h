#pragma once
#include "WorldObject.h"
#include "DrawableObject.h"
namespace primitives {
	class Plane :
		public WorldObject,
		public DrawableObject {
	public:
		Plane(double width, double length, double x = 0.0, double y = 0.0, double z = 0.0);
		virtual ~Plane() override;
		void virtual draw() const override;
	};
}