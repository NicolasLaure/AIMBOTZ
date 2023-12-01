#include "Button.h"

#include <iostream>

namespace aimbotz
{
	static const Color PRESSED_BUTTON_DARKGRAY = { 20,20,20,160 };

	static const Color GRAY = Color(130, 130, 130, 255);
	static const Color DARKGRAY = Color(80, 80, 80, 255);
	static const Color WHITE = Color(255, 255, 255, 255);

	void ButtonCollisionCheck(RenderWindow& window,Button& button, Scenes& scene)
	{
		Vector2i mousePos = Mouse::getPosition(window);

		if (mousePos.x >= button.buttonRect.position.x &&
			mousePos.x <= button.buttonRect.position.x + button.buttonRect.width &&
			mousePos.y >= button.buttonRect.position.y &&
			mousePos.y <= button.buttonRect.position.y + button.buttonRect.height)
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

	void ResetButtonCollisionCheck(Button& button, bool& restartGame)
	{
		Vector2i mousePos = Mouse::getPosition();

		if (mousePos.x > button.buttonRect.position.x
			&& mousePos.x <  button.buttonRect.position.x + button.buttonRect.width
			&& mousePos.y > button.buttonRect.position.y
			&& mousePos.y < button.buttonRect.position.y + button.buttonRect.height)
		{
			button.currentTextColor = GRAY;
			if (Mouse::isButtonPressed(Mouse::Left) && !button.wasPressed)
			{
				button.wasPressed = true;
				/*if (!IsSoundPlaying(GetSound(SoundIdentifier::ButtonClick)))
					PlaySound(GetSound(SoundIdentifier::ButtonClick));*/
			}

			if (Mouse::isButtonPressed(Mouse::Left) && button.wasPressed)
			{
				button.currentTextColor = DARKGRAY;
			}

			//mouse release 
			if (!Mouse::isButtonPressed(Mouse::Left))
			{
				if (button.wasPressed)
				{
					/*if (!IsSoundPlaying(GetSound(SoundIdentifier::ButtonRelease)))
						PlaySound(GetSound(SoundIdentifier::ButtonRelease));*/
					restartGame = true;
				}
			}
		}
		else
		{
			button.currentTextColor = button.textColor;
			button.wasPressed = false;
		}
	}

	void ButtonDraw(RenderWindow& window, Button& button, bool drawRectangle)
	{
		Font font;
		font.loadFromFile("res/VT323.ttf");

		Text buttonText;
		buttonText.setFont(font);

		buttonText.setString(button.text.getString());
		buttonText.setPosition(Vector2f(button.buttonRect.position.x, button.buttonRect.position.y));
		buttonText.setCharacterSize(button.fontSize);
		buttonText.setFillColor(button.currentTextColor);
		window.draw(buttonText);
	}
};