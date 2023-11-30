#include "screens/Gameplay.h"

#include "entities/Target.h"
#include "utils/Utilities.h"

namespace aimbotz
{
	namespace game
	{
		void Init()
		{
			target::Init();
		}

		static int totalClicks;
		static int totalHits;

		static float accuracy;
		void Update(RenderWindow& window)
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				totalClicks++;

				if (utilities::PointToCircleCollisionCheck(static_cast<Vector2f>(Mouse::getPosition(window)), target::GetCenter(), target::GetRadius()))
				{
					target::SetPosition(utilities::GetRandomVector2(target::GetRadius() * 2));
					totalHits++;
				}
			}
			if (totalClicks > 0)
				accuracy = (totalHits / totalClicks) * 100;
		}

		void Draw(RenderWindow& window)
		{
			window.clear(Color::Black);

			// Draw
			CircleShape shape(target::GetRadius());
			shape.setPosition(target::GetPosition());
			shape.setFillColor(Color::Green);
			window.draw(shape);

			/*Text accuracyText;
			accuracyText.setFont();
			accuracyText.setString(std::to_string(accuracy));
			accuracyText.setCharacterSize(50);
			window.draw(accuracyText);*/

			// Update the window
			window.display();
		}
	}
}