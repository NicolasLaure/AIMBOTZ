#include "screens/Gameplay.h"

#include "entities/Target.h"
#include "utils/Utilities.h"
#include "constants/ScreenDimensions.h"
#include "managers/FontsManager.h"

namespace aimbotz
{
	namespace game
	{
		static int totalClicks = 0;
		static int totalHits = 0;
		static float accuracy;

		static int duration = 300;
		static float timer;

		Clock deltaClock;

		void Init()
		{
			target::Init();
			totalClicks = 0;
			totalHits = 0;
			timer = duration;
			deltaClock.restart();
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

			Time dt = deltaClock.restart();
			timer -= dt.asSeconds();

		}

		void Draw(RenderWindow& window)
		{
			window.clear(Color::Black);

			CircleShape shape(target::GetRadius());
			shape.setPosition(target::GetPosition());
			shape.setFillColor(Color::Green);
			window.draw(shape);
		
			Font font;
			font.loadFromFile("res/VT323.ttf");

			Text accuracyText;
			accuracyText.setFont(font);

			accuracyText.setString(std::to_string(accuracy) + "%");
			//accuracyText.setString(std::to_string(accuracy));
			accuracyText.setCharacterSize(50);
			accuracyText.setFillColor(Color::Red);
			window.draw(accuracyText);

			Text timerText;
			std::string timerMinutes = std::to_string(static_cast<int>(timer) / 60);
			std::string timerSeconds = static_cast<int>(timer) % 60 >= 10 ? std::to_string(static_cast<int>(timer) % 60) : "0" +std::to_string(static_cast<int>(timer) % 60);
			timerText.setFont(font);
			timerText.setString(timerMinutes + ":" + timerSeconds);
			timerText.setCharacterSize(50);
			timerText.setFillColor(Color::Red);
			timerText.setPosition(Vector2f(static_cast<float>(screen::SCREEN_WIDTH) / 2, 0));
			window.draw(timerText);

			window.display();
		}
	}
}