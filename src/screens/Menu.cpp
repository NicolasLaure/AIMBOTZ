#include "screens/Menu.h"

#include "ui/Button.h"
#include "constants/ScreenDimensions.h"
#include "managers/FontsManager.h"

namespace aimbotz
{
	namespace menu
	{
		struct MenuData
		{
			const char* title = "Flappy Drake";
			int titleSize = 80;
			int titleLimitSpacing = 70;

			const char* credits = "Created By Nico Laure and Caro Pohn.";
			int creditsSize = 30;

			static const int buttonsQty = 2;
			Button scenesButtons[buttonsQty] = {
				{{Vector2f(0.0f,0.0f)}, Scenes::GAMEPLAY,"Play"},
				{{Vector2f(0.0f,0.0f)}, Scenes::EXIT,"Exit"}
			};
			Button itchPageButton = { {Vector2f(0.0f,0.0f)}, Scenes::MENU, credits };
		};

		static MenuData menuData;

		void Start()
		{
			Vector2f textSize = { 0,0 };

			float windowLimitSpacing = 20;
			Text credits = Text(menuData.itchPageButton.text, *fonts::GetFont(), menuData.itchPageButton.fontSize);
			textSize = Vector2f(credits.getLocalBounds().width, credits.getLocalBounds().height);
			menuData.itchPageButton.buttonRect = {Vector2f(screen::SCREEN_WIDTH - credits.getLocalBounds().width - 20, screen::SCREEN_HEIGHT - menuData.creditsSize - 20), textSize.y, textSize.x };

			for (int i = 0; i < menuData.buttonsQty; i++)
			{
				Text buttonText = Text(menuData.scenesButtons[i].text, *fonts::GetFont(), menuData.scenesButtons[i].fontSize);
				textSize = Vector2f(buttonText.getLocalBounds().width, buttonText.getLocalBounds().height);
				menuData.scenesButtons[i].buttonRect = { Vector2f(windowLimitSpacing, static_cast<float>(screen::SCREEN_HEIGHT) / 3 + i * menuData.scenesButtons[i].fontSize * 1.6f), 150, 250};
			}
		}
		void Update(RenderWindow& window, Scenes& scene)
		{
			//ItchPageButtonCollisionCheck(menuData.itchPageButton);
			
			for (Button& button : menuData.scenesButtons)
			{
				ButtonCollisionCheck(window, button, scene);
			}
		
		}

		void Draw(RenderWindow& window)
		{
			window.clear(Color::Black);

			Font font;
			font.loadFromFile("res/VT323.ttf");

			Text title;
			title.setFont(font);

			int titleSize = 120;
			title.setString("Aimbotz");
			title.setCharacterSize(titleSize);
			title.setFillColor(Color::White);
			title.setPosition(Vector2f(screen::SCREEN_WIDTH / 2 - title.getLocalBounds().width / 2, 20));

			window.draw(title);

			Text credits;
			credits.setFont(font);

			credits.setString(menuData.credits);
			credits.setCharacterSize(menuData.creditsSize);
			credits.setFillColor(Color::White);
			credits.setPosition(Vector2f(screen::SCREEN_WIDTH - 440, screen::SCREEN_HEIGHT - menuData.creditsSize - 20));

			window.draw(credits);
			//DrawText(menuData.title, GetScreenWidth() / 2 - MeasureText(menuData.title, menuData.titleSize) / 2, 20, menuData.titleSize, WHITE);
			//DrawText(menuData.credits, GetScreenWidth() - MeasureText(menuData.credits, menuData.creditsSize) - 20, GetScreenHeight() - menuData.creditsSize - 20, menuData.creditsSize, menuData.itchPageButton.currentTextColor);

			for (Button& button : menuData.scenesButtons)
			{
				ButtonDraw(window, button, false);
			}
			//userInterface::DrawVersionText();
			window.display();
		}
	}
}