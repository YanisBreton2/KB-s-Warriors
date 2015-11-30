#include <iostream>
#include <SFML\Graphics.hpp>
#include "menu.h"

int	main()
{
	sf::RenderWindow window(sf::VideoMode(1400, 800), "Runner");
	while (window.isOpen())
	{
		main_menu(window);
	}
	return (0);
}
