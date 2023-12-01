#include "screens/Menu.h"

#include "ui/Button.h"
#include "constants/ScreenDimensions.h"

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
				{{Vector2f(0.0f,0.0f)}, Scenes::GAMEPLAY},
				{{Vector2f(0.0f,0.0f)}, Scenes::EXIT}
			};
			Button itchPageButton = { {Vector2f(0.0f,0.0f)}, Scenes::MENU };
		};

		static MenuData menuData;

		void Start()
		{
			Vector2f textSize = { 0,0 };

			menuData.scenesButtons[0].text.setString("Play");
			menuData.scenesButtons[1].text.setString("Exit");

			menuData.itchPageButton.text.setString(menuData.credits);

			float windowLimitSpacing = 20;
			textSize = Vector2f(menuData.itchPageButton.text.getLocalBounds().width, menuData.itchPageButton.text.getLocalBounds().height);
			menuData.itchPageButton.buttonRect = {Vector2f(screen::SCREEN_WIDTH - menuData.itchPageButton.text.getLocalBounds().width - 20, screen::SCREEN_HEIGHT - menuData.creditsSize - 20), textSize.y, textSize.x };

			for (int i = 0; i < menuData.buttonsQty; i++)
			{
				textSize = Vector2f(menuData.scenesButtons[i].text.getLocalBounds().width, menuData.scenesButtons[i].text.getLocalBounds().height);
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