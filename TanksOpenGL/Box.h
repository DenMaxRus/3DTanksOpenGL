#pragma once
#include "DrawableObject.h"
namespace primitives {
	class Box :
		public DrawableObject {
	public:
		Box(double width, double length, double height, double x = 0.0, double y = 0.0, double z = 0.0);
		virtual ~Box() override;
		void virtual draw() const override;
	};
}