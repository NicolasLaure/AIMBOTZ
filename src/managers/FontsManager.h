#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace aimbotz
{
	namespace fonts
	{
		void Init();
		void Unload();

		Font GetFont();
	}
}
