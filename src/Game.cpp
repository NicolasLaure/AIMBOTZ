#include "Game.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "screens/Gameplay.h"
#include "screens/Menu.h"
#include "constants/Scenes.h"
#include "constants/ScreenDimensions.h"
#include "managers/FontsManager.h"

using namespace sf;

namespace aimbotz
{
	void Init(RenderWindow& window);

	static Scenes actualScene;
	static Scenes prevScene;

	void RunGame()
	{
		RenderWindow window;

		Init(window);
		// Start the game loop
		while (window.isOpen())
		{
			bool enteredNewScene = actualScene != prevScene;
			prevScene = actualScene;

			switch (actualScene)
			{
			case aimbotz::MENU:
				if (enteredNewScene)
					menu::Start();

				menu::Update(window,actualScene);
				menu::Draw(window);
				break;
			case aimbotz::GAMEPLAY:
				if (enteredNewScene)
					game::Init();

				game::Update(window);
				game::Draw(window);

				break;
			case aimbotz::EXIT:
				return;
				break;
			default:
				break;
			}

			Event event;
			while (window.pollEvent(event))
			{
				// Close window: exit
				if (event.type == Event::Closed)
				{
					fonts::Unload();
					window.close();
				}
			}
		}

	}

	void Init(RenderWindow& window)
	{
		srand(time(0));

		window.create(VideoMode(screen::SCREEN_WIDTH, screen::SCREEN_HEIGHT), "SFML window");

		fonts::Init();

		actualScene = Scenes::MENU;
		prevScene = Scenes::EXIT;
	}
}