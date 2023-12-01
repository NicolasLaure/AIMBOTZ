#include "Button.h"

#include <iostream>

#include "managers/FontsManager.h"

using namespace std;

namespace aimbotz
{
	static const Color PRESSED_BUTTON_DARKGRAY = { 20,20,20,160 };

	static const Color GRAY = Color(130, 130, 130, 255);
	static const Color DARKGRAY = Color(80, 80, 80, 255);
	static const Color WHITE = Color(255, 255, 255, 255);

	void MenuButtonBehaviour(RenderWindow& window,Button& button, Scenes& scene)
	{
		Vector2i mousePos = Mouse::getPosition(window);

		if (ButtonCollision(window, button))
		{
			button.currentTextColor = GRAY;

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				button.wasPressed = true;
				/*if (!IsSoundPlaying(GetSound(SoundIdentifier::ButtonClick)))
					PlaySound(GetSound(SoundIdentifier::ButtonClick));*/
			}

			if (Mouse::isButtonPressed(Mouse::Left) && button.wasPressed)
			{
				button.currentTextColor = DARKGRAY;
			}

			if (!Mouse::isButtonPressed(Mouse::Left))
			{
				if (button.wasPressed)
				{
					/*if (!IsSoundPlaying(GetSound(SoundIdentifier::ButtonRelease)))
						PlaySound(GetSound(SoundIdentifier::ButtonRelease));*/
					scene = button.sceneTo;
				}
			}
		}
		else
		{
			button.currentTextColor = WHITE;
			button.wasPressed = false;
		}
	}
	
	bool ButtonCollision(RenderWindow& window, Button& button)
	{
		Vector2i mousePos = Mouse::getPosition(window);

		if (mousePos.x >= button.buttonRect.position.x &&
			mousePos.x <= button.buttonRect.position.x + button.buttonRect.width &&
			mousePos.y >= button.buttonRect.position.y &&
			mousePos.y <= button.buttonRect.position.y + button.buttonRect.height)
		{
			return true;
		}
		else
			return false;
	}

	void ButtonDraw(RenderWindow& window, Button& button, bool drawRectangle)
	{
		utilities::DrawText(window, button.text, *fonts::GetFont(), button.fontSize, button.buttonRect.position, button.currentTextColor);
	}
};