#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "constants/ScreenDimensions.h"

namespace aimbotz
{

	static sf::RenderWindow window;
	void RunGame()
	{

		// Start the game loop
		while (window.isOpen())
		{
			// Process events
			float randX = rand() % screen::SCREEN_WIDTH;
			float randY = rand() % screen::SCREEN_HEIGHT;

			sf::CircleShape shape(50.f);
			shape.setFillColor(sf::Color::Green);
			shape.setPosition(sf::Vector2f(120.f, 50.f));

			sf::Event event;
			while (window.pollEvent(event))
			{

				// Close window: exit
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// Clear screen
			window.clear(sf::Color::Black);

			// Draw
			window.draw(shape);
			//window.draw(text);

			// Update the window
			window.display();
		}

	}

	void Init()
	{
		srand(time(0));


		// Create the main window
		sf::RenderWindow window(sf::VideoMode(screen::SCREEN_WIDTH, screen::SCREEN_HEIGHT), "SFML window");
	}

	void Update()
	{

	}

	void Draw()
	{

	}
}