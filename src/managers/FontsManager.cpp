#include "FontsManager.h"



namespace aimbotz
{
	namespace fonts
	{
		static Font font;
		void Init()
		{
			font.Font::loadFromFile("res/VT323.ttf");
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