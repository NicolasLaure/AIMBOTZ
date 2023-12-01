#include "FontsManager.h"

#include <iostream>

namespace aimbotz
{
	namespace fonts
	{
		static Font* font = new Font();

		void Init()
		{
			if (font->loadFromFile("res/VT323.ttf"))
			{
				std::cout << "LOADED";
			}
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