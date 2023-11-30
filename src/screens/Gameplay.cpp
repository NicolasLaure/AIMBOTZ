#include "screens/Gameplay.h"

#include "entities/Target.h"
#include "utils/Utilities.h"
#include "managers/FontsManager.h"

namespace aimbotz
{
	namespace game
	{
		static int totalClicks = 0;
		static int totalHits = 0;
		static float accuracy;

		void Init()
		{
			target::Init();
			totalClicks = 0;
			totalHits = 0;
		}

		bool isMousePressed = false;

		void Update(RenderWindow& window)
		{
			if (Mouse::isButtonPressed(Mouse::Left) && !isMousePressed)
			{
				totalClicks++;

				if (utilities::PointToCircleCollisionCheck(static_cast<Vector2f>(Mouse::getPosition(window)), target::GetCenter(), target::GetRadius()))
				{
					target::SetPosition(utilities::GetRandomVector2(target::GetRadius() * 2));
					totalHits++;
				}
				isMousePressed = true;
			}
			else if(!Mouse::isButtonPressed(Mouse::Left))
				isMousePressed = false;

			if (totalClicks > 0)
				accuracy = (static_cast<float>(totalHits) / totalClicks) * 100;
		}

		void Draw(RenderWindow& window)
		{
			window.clear(Color::Black);

			CircleShape shape(target::GetRadius());
			shape.setPosition(target::GetPosition());
			shape.setFillColor(Color::Green);
			window.draw(shape);

			Text accuracyText;
			Font font;
			font.loadFromFile("res/VT323.ttf");
			accuracyText.setFont(font);

			accuracyText.setString(std::to_string(accuracy) + "%");
			//accuracyText.setString(std::to_string(accuracy));
			accuracyText.setCharacterSize(50);
			accuracyText.setFillColor(Color::Red);
			window.draw(accuracyText);

			window.display();
		}
	}
}