#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "constants/Scenes.h"

using namespace sf;

namespace aimbotz
{
	namespace Pause
	{
		void init();
		void Update(RenderWindow& window, bool& isPaused, Scenes& scene);
		void Draw(RenderWindow& window);
	}
}
