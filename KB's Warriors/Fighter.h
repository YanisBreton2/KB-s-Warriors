#ifndef FIGHTER_H_
# define FIGHTER_H_

# include <SFML\Graphics.hpp>

# define NONE (0)
# define RIGHT (1)
# define LEFT (2)

# define SPEED ((float)1.0f)

class Fighter
{
public:
	Fighter(int player);
	~Fighter(void);
	sf::Sprite	getSprite(void);
	void		flip(void);
	void		move(float x, float y);
	void		setMovement(int movement);
	void		doMovement(sf::View limit);
	int			hasJoystick(void);
	bool		faceToRight(void);
private:
	sf::Sprite	m_sprite;
	sf::Texture	m_texture;
	int			m_joystick;
	int			m_moving;
	bool		m_face_right;
};

#endif /* !FIGHTER_H_ */