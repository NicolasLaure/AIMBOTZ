#pragma once
#include <SFML/Graphics.hpp>

namespace aimbotz
{
	namespace utilities
	{
		sf::Vector2f GetRandomVector2(float size);
		bool PointToCircleCollisionCheck(sf::Vector2f point, sf::Vector2f circlePos, float circleRadius);
	}
}
