#ifndef BATTLE_ENGINE_H_
# define BATTLE_ENGINE_H_

# include <SFML\Graphics.hpp>
# include "Fighter.h"

class BattleEngine
{
public:
				BattleEngine(void);
				~BattleEngine(void);
	void		run(sf::RenderWindow &win);
	void		event_handler(sf::Event event);
private:
	sf::Sprite	m_sprite_background;
	sf::Texture	m_texture_background;
	sf::View	m_camera;
	Fighter		*m_player_1;
	Fighter		*m_player_2;
};

#endif /* !BATTLE_ENGINE_H_ */