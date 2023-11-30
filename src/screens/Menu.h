#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace aimbotz
{
	namespace menu
	{
		void Init();
		void Update(RenderWindow& window);
		void Draw(RenderWindow& window);
	}
}