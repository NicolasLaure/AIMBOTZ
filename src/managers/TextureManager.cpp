#include "TextureManager.h"

#include <iostream>

namespace aimbotz
{
	namespace textures
	{
		struct Asset
		{
			Textures asset;
			Texture* texture;
			Sprite* sprite;
		};

		static Asset textures[TEXTURE_COUNT];

		void Init()
		{
			Texture* bugTexture = new Texture();
			bugTexture->loadFromFile("res/ladybug.png");
			Sprite* bugSprite = new Sprite();
			bugSprite->setTexture(*bugTexture);
			Asset bug = { Textures::BUG, bugTexture, bugSprite};

			Texture* gardenTexture = new Texture();
			gardenTexture->loadFromFile("res/background.png");
			Sprite* gardenSprite = new Sprite();
			gardenSprite->setTexture(*gardenTexture);
			Asset background = { Textures::BACKGROUND, gardenTexture, gardenSprite};

			Asset auxTextures[TEXTURE_COUNT] = {
				bug,
				background
			};

			for (int i = 0; i < TEXTURE_COUNT; i++) 
			{
				textures[i] = auxTextures[i];
			}
		}

		void Unload()
		{
			for (int i = 0; i < TEXTURE_COUNT; i++)
			{
				delete textures[i].texture;
				delete textures[i].sprite;
			}
		}

		Sprite* GetSprite(Textures assetType)
		{
			for (int i = 0; i < TEXTURE_COUNT; i++)
			{
				if (textures[i].asset == assetType)
				{
					return textures[i].sprite;
				}
			}

			return {};
		}
	}
}