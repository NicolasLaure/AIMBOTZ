#include "Game.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "constants/ScreenDimensions.h"
#include "utils/Utilities.h"
#include "entities/Target.h"

using namespace sf;
namespace aimbotz
{

	void Init(RenderWindow& window);
	void Update(RenderWindow& window);
	void Draw(RenderWindow& window);

	void RunGame()
	{
		RenderWindow window;

		Init(window);
		// Start the game loop
		while (window.isOpen())
		{
			Update(window);
			Draw(window);
		}

	}

	void Init(RenderWindow& window)
	{
		srand(time(0));

		window.create(VideoMode(screen::SCREEN_WIDTH, screen::SCREEN_HEIGHT), "SFML window");

		target::Init();
	}

	void Update(RenderWindow& window)
	{
		if (utilities::PointToCircleCollisionCheck(static_cast<Vector2f>(Mouse::getPosition(window)), target::GetCenter(), target::GetRadius()) && Mouse::isButtonPressed(Mouse::Left))
			target::SetPosition(utilities::GetRandomVector2(target::GetRadius() * 2));

		Event event;
		while (window.pollEvent(event))
		{

			// Close window: exit
			if (event.type == Event::Closed)
				window.close();
		}
	}

	void Draw(RenderWindow& window)
	{
		window.clear(Color::Black);

		// Draw
		CircleShape shape(target::GetRadius());
		shape.setPosition(target::GetPosition());
		shape.setFillColor(Color::Green);
		window.draw(shape);

		//window.draw(text);

		// Update the window
		window.display();
	}
}