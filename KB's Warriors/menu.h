#ifndef MENU_H_
# define MENU_H_

# include <SFML\Graphics.hpp>
# include "MyText.h"
# include "joystick.h"
# include "BattleEngine.h"

# define	MAIN_MENU_CHOICE_COUNT (4)
# define	INTERLINE (70)
# define	TOP_BUTTON (350)

void		main_menu(sf::RenderWindow &window);

#endif /* !MENU_H_ */