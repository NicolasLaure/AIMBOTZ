#include "managers/pauseManager.h"

#include <string>

#include "managers/TextureManager.h"
#include "ui/Button.h"
#include "Game.h"
#include "managers/FontsManager.h"
#include "constants/ScreenDimensions.h"

using namespace std;

namespace aimbotz
{
	namespace Pause
	{
		void checkMenuInputAndCollision(RenderWindow& window, bool& isPaused, Scenes& scene);

		static const int verticalAssetsDisplacement = 80;

		bool canUnpause = false;

		void Update(RenderWindow& window, bool& isPaused, Scenes& scene)
		{
			checkMenuInputAndCollision(window, isPaused, scene);
		}

		void Draw(RenderWindow& window)
		{
			//Texture pausePanel = AssetManager::getTexture(AssetManager::Textures::PAUSE_PANEL);

			// draw PausePanel
		}

		void checkMenuInputAndCollision(RenderWindow& window, bool& isPaused, Scenes& scene)
		{
			if (!Keyboard::isKeyPressed(Keyboard::Escape) && !Mouse::isButtonPressed(Mouse::Middle))
				canUnpause = true;

			if ((Keyboard::isKeyPressed(Keyboard::Escape) || Mouse::isButtonPressed(Mouse::Middle)) && canUnpause)
			{
				canUnpause = false;
				isPaused = false;
			}

			if (Keyboard::isKeyPressed(Keyboard::Space))
				scene = Scenes::MENU;
		}
	}
}