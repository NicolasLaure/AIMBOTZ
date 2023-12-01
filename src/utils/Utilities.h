#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace aimbotz
{
	namespace utilities
	{
		struct Rect
		{
			Vector2f position{};
			float height{};
			float width{};
		};

		sf::Vector2f GetRandomVector2(float size);
		bool PointToCircleCollisionCheck(sf::Vector2f point, sf::Vector2f circlePos, float circleRadius);

		void DrawText(RenderWindow& window, std::string text, const Font& font, float fontSize, Vector2f position, Color color);
	}
}
