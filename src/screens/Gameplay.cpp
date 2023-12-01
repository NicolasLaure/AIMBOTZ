#include "screens/Gameplay.h"

#include "entities/Target.h"
#include "utils/Utilities.h"
#include "constants/ScreenDimensions.h"
#include "managers/FontsManager.h"

using namespace std;

namespace aimbotz
{
	namespace game
	{
		static int totalClicks = 0;
		static int totalHits = 0;
		static float accuracy;
		static float clicksPerMinute = 0;
		Clock cpmClock;

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
			cpmClock.restart();
		}


		bool isMousePressed = false;
		void Update(RenderWindow& window)
		{
			if (Mouse::isButtonPressed(Mouse::Left) && !isMousePressed)
			{
				totalClicks++;

				if (utilities::PointToCircleCollisionCheck(static_cast<Vector2f>(Mouse::getPosition(window)), target::GetCenter(), target::GetRadius()))
				{
					target::ResetPosition();
					totalHits++;
					Time cpm = cpmClock.restart();
					clicksPerMinute = 60 / cpm.asSeconds();
				}
				isMousePressed = true;
			}
			else if (!Mouse::isButtonPressed(Mouse::Left))
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

			const float UI_SIZE = 50;
			const Color UI_COLOR = Color::Red;
			string accuracyText = to_string(accuracy) + "%";
			utilities::DrawText(window, accuracyText, *fonts::GetFont(), UI_SIZE, Vector2f(0, 0), UI_COLOR);

			string timerMinutes = to_string(static_cast<int>(timer) / 60);
			string timerSeconds = static_cast<int>(timer) % 60 >= 10 ? to_string(static_cast<int>(timer) % 60) : "0" + to_string(static_cast<int>(timer) % 60);
			string timerText = timerMinutes + ":" + timerSeconds;
			utilities::DrawText(window, timerText, *fonts::GetFont(), UI_SIZE, Vector2f(static_cast<float>(screen::SCREEN_WIDTH) / 2, 0), UI_COLOR);

			string cpmText = "CPM: " + to_string(clicksPerMinute);
			Text cpmSfmlText = Text(cpmText, *fonts::GetFont(), UI_SIZE);
			float textWidth = cpmSfmlText.getLocalBounds().width;
			utilities::DrawText(window, cpmText, *fonts::GetFont(), UI_SIZE, Vector2f(static_cast<float>(screen::SCREEN_WIDTH) - textWidth, 0), UI_COLOR);

			window.display();
		}
	}
}