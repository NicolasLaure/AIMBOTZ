#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace aimbotz
{
	namespace textures
	{
		enum Textures
		{
			BUG, 
			BACKGROUND, 
			CURSOR,
			PAUSE,
			TEXTURE_COUNT
		};

		void Init();
		void Unload();

		Sprite* GetSprite(Textures assetType);
	}
}