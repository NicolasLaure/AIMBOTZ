#include "Utilities.h"

#include "constants/ScreenDimensions.h"

namespace aimbotz
{
	namespace utilities
	{
		sf::Vector2f GetRandomVector2(float size)
		{
			int maxX = screen::SCREEN_WIDTH - size;
			int maxY = screen::SCREEN_HEIGHT - size;
			float randX = rand()% maxX;
			float randY = rand()% maxY;
			return sf::Vector2f(randX, randY);
		}

		bool PointToCircleCollisionCheck(sf::Vector2f point, sf::Vector2f circleCenter, float circleRadius)
		{
			double distX = circleCenter.x - point.x;
			double distY = circleCenter.y - point.y;

			float distance = static_cast<float>(sqrt(distX * distX + distY * distY));

			return distance <= circleRadius;
		}

		void DrawText(RenderWindow& window,std::string text, const Font& font, float fontSize, Vector2f position, Color color)
		{
			Text sfmlText;
			sfmlText.setFont(font);
			sfmlText.setString(text);
			sfmlText.setCharacterSize(fontSize);
			sfmlText.setFillColor(color);
			sfmlText.setPosition(position);
			window.draw(sfmlText);
		}

	}
}