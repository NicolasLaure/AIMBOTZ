#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace aimbotz
{
	namespace target
	{
		void Init();
		void SetRadius(float radius);
		void SetPosition(Vector2f position);
		float GetRadius();
		Vector2f GetPosition();
		Vector2f GetCenter();
	}
}

