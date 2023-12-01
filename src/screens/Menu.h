#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "constants/Scenes.h"

using namespace sf;

namespace aimbotz
{
	namespace menu
	{
		void Start();
		void Update(RenderWindow& window, Scenes& scene);
		void Draw(RenderWindow& window);
	}
}