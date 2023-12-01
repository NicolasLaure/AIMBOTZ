#include "screens/Gameplay.h"

#include "entities/Target.h"
#include "utils/Utilities.h"
#include "constants/ScreenDimensions.h"
#include "managers/FontsManager.h"
#include "managers/TextureManager.h"

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
			textures::Init();
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

			int windowLimitSpacing = 40;

			Sprite gardenSprite = *textures::GetSprite(textures::Textures::BACKGROUND);
			gardenSprite.setPosition(Vector2f(0.0f, 0.0f));
			window.draw(gardenSprite);

			Sprite bugSprite = *textures::GetSprite(textures::Textures::BUG);
			bugSprite.setPosition(target::GetPosition());
			window.draw(bugSprite);

			const float UI_SIZE = 50;
			const Color UI_COLOR = Color::Red;
			string accuracyText = "Accuracy: " + to_string(accuracy).substr(0, 5) + "%";
			utilities::DrawText(window, accuracyText, *fonts::GetFont(), UI_SIZE, Vector2f(windowLimitSpacing, 0), UI_COLOR);

			string timerMinutes = to_string(static_cast<int>(timer) / 60);
			string timerSeconds = static_cast<int>(timer) % 60 >= 10 ? to_string(static_cast<int>(timer) % 60) : "0" + to_string(static_cast<int>(timer) % 60);
			string timerText = timerMinutes + ":" + timerSeconds;
			utilities::DrawText(window, timerText, *fonts::GetFont(), UI_SIZE, Vector2f(static_cast<float>(screen::SCREEN_WIDTH) / 2, 0), UI_COLOR);

			string cpmText = "CPM: " + to_string(static_cast<int>(clicksPerMinute));
			Text cpmSfmlText = Text(cpmText, *fonts::GetFont(), UI_SIZE);
			float textWidth = cpmSfmlText.getLocalBounds().width;
			utilities::DrawText(window, cpmText, *fonts::GetFont(), UI_SIZE, Vector2f(static_cast<float>(screen::SCREEN_WIDTH) - textWidth - windowLimitSpacing, 0), UI_COLOR);

			window.display();
		}
	}
}