#include "FontsManager.h"

#include <iostream>

namespace aimbotz
{
	namespace fonts
	{
		static Font font;

		void Init()
		{
			font.loadFromFile("res/VT323.ttf");
		}
		void Unload()
		{
			//font.~Font();
		}

		Font GetFont()
		{
			return font;
		}
	}
}