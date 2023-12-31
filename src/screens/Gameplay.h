#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace aimbotz
{
	namespace game
	{
		void Init();
		void Update(RenderWindow& window, bool& isPaused);
		void Draw(RenderWindow& window);
	}
}
