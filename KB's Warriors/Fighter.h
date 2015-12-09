#ifndef FIGHTER_H_
# define FIGHTER_H_

# include <SFML\Graphics.hpp>

# define HEIGHT (421)
# define WIDTH (206)

# define NONE (0)
# define RIGHT (1)
# define LEFT (2)

# define STAND (0)
# define LIGHT_ATTACK (1)
# define STRONG_ATTACK (2)

# define ANIMATION_SPEED (0.15f)
# define LIGHT_ANIMATION_KEY (3)
# define STRONG_ANIMATION_KEY (4)
# define SPEED ((float)1.0f)
# define JUMP_SPEED ((float)1.5f)

# define GRAVITY (0.005f)

class Fighter
{
public:
	Fighter(int player);
	~Fighter(void);
	sf::Sprite	getSprite(void);
	void		flip(void);
	void		move(float x, float y);
	void		setMovement(int movement);
	void		doAction(sf::View &limit);
	void		doMovement(sf::View &limit);
	int			hasJoystick(void);
	bool		faceToRight(void);
	void		changeState(int state);
	void		jump(void);
private:
	sf::Sprite	m_sprite;
	sf::Texture	m_texture;
	sf::IntRect	m_texture_pos;
	int			m_joystick;
	int			m_moving;
	bool		m_face_right;
	int			m_state;
	int			m_anim_state;
	int			m_current_animation_keys;
	sf::Clock	m_anim_clock;
	float		m_vertical_speed;
};

#endif /* !FIGHTER_H_ */