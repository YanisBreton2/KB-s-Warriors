#include "menu.h"

using namespace	sf;

void	makeChoice(int choice, sf::RenderWindow &window, BattleEngine &be)
{
	switch (choice)
	{
	case 0:
		be.run(window);
		break;
	case 3:
		window.close();
		break;
	default:
		printf("%d\n", choice);
		break;
	}
}

void	main_menu(sf::RenderWindow &window)
{
	MyText	title("KB's Fighter", "../Ressources/Font/hominis.ttf", sf::Vector2f(700, 90), 130);
	MyText	versus("Versus", "../Ressources/Font/breamcatcher.ttf", sf::Vector2f(700, TOP_BUTTON));
	MyText	training("Training", "../Ressources/Font/breamcatcher.ttf", sf::Vector2f(700, TOP_BUTTON + INTERLINE));
	MyText	config("Config", "../Ressources/Font/breamcatcher.ttf", sf::Vector2f(700, TOP_BUTTON + INTERLINE * 2));
	MyText	exit("Exit", "../Ressources/Font/breamcatcher.ttf", sf::Vector2f(700, TOP_BUTTON + INTERLINE * 3));
	title.setColor(Color(136, 40, 40));
	Sprite	selector;
	Texture	texture;

	texture.loadFromFile("../Ressources/selector.png");
	selector.setTexture(texture);
	selector.setOrigin(100, 0);
	selector.setPosition(700, TOP_BUTTON);
	Event	event;
	int		choice = 0;
	Clock	clock;
	BattleEngine be;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::JoystickMoved && clock.getElapsedTime().asMilliseconds() > 120)
			{
				if (event.joystickMove.axis == Joystick::Axis::Y)
				{
					clock.restart();
					float y = event.joystickMove.position;
					if (y > 50.0f && choice < MAIN_MENU_CHOICE_COUNT - 1)
					{
						choice += 1;
						selector.move(0, INTERLINE);
					}
					else if (y < -50.0f && choice > 0)
					{
						choice -= 1;
						selector.move(0, -INTERLINE);
					}
				}
			}
			else if (event.type == Event::JoystickButtonReleased)
			{
				if (event.joystickButton.button == JOYSTICK_A)
				{
					makeChoice(choice, window, be);
				}
			}
			else if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Down && choice < MAIN_MENU_CHOICE_COUNT - 1)
				{
					choice += 1;
					selector.move(0, INTERLINE);
				}
				else if (event.key.code == Keyboard::Up && choice > 0)
				{
					choice -= 1;
					selector.move(0, -INTERLINE);
				}
				else if (event.key.code == Keyboard::Return)
				{
					makeChoice(choice, window, be);
				}
			}
		}
		window.clear(Color::Black);
		window.draw(title.getSprite());
		window.draw(selector);
		window.draw(versus.getSprite());
		window.draw(training.getSprite());
		window.draw(config.getSprite());
		window.draw(exit.getSprite());
		window.display();
	}
}
