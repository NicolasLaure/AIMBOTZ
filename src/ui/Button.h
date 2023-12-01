#pragma once

#include "utils/Utilities.h"
#include "constants/Scenes.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
namespace aimbotz
{
	struct Button
	{
		utilities::Rect buttonRect;
		Scenes sceneTo;
		Text text;

		int fontSize = 70;
		Color textColor = Color::White;
		Color currentTextColor = Color::White;

		float textHeightSpacerMultiplier = 2.25f;
		float textPositionX = 15;

		bool wasPressed{ false };
	};

	void ButtonCollisionCheck(RenderWindow& window, Button& button, Scenes& scene);
	void ResetButtonCollisionCheck(Button& button, bool& restartGame);
	void ButtonDraw(RenderWindow& window, Button& button, bool drawRectangle);
};