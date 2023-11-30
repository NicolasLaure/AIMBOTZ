#include "Game.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "screens/Gameplay.h"
#include "screens/Menu.h"
#include "constants/ScreenDimensions.h"

using namespace sf;
namespace aimbotz
{

	void Init(RenderWindow& window);

	enum Screens
	{
		MENU,
		GAMEPLAY,
		EXIT
	};

	static Screens actualScreen;
	static Screens prevScreen;
	void RunGame()
	{
		RenderWindow window;

		Init(window);
		// Start the game loop
		while (window.isOpen())
		{
			bool enteredNewScene = actualScreen != prevScreen;
			prevScreen = actualScreen;

			switch (actualScreen)
			{
			case aimbotz::MENU:
				if (enteredNewScene)
					menu::Init();

				menu::Update(window);
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
					window.close();
			}
		}

	}

	void Init(RenderWindow& window)
	{
		srand(time(0));

		window.create(VideoMode(screen::SCREEN_WIDTH, screen::SCREEN_HEIGHT), "SFML window");

		actualScreen = Screens::GAMEPLAY;
		prevScreen = Screens::EXIT;
	}
}