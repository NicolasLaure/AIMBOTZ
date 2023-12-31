#include "FontsManager.h"

#include <iostream>

namespace aimbotz
{
	namespace fonts
	{
		static Font* font = new Font();

		void Init()
		{
			font->loadFromFile("res/VT323.ttf");
		}
		void Unload()
		{
			delete font;
		}

		Font* GetFont()
		{
			return font;
		}
	}
}