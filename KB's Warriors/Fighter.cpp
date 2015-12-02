#include "Fighter.h"


Fighter::Fighter(int player): m_joystick(-1), m_moving(NONE), m_face_right(true), m_state(STAND)
{
	m_texture.loadFromFile("../Ressources/Characters/az.png");
	m_sprite.setTexture(m_texture);
	m_texture_pos.height = HEIGHT;
	m_texture_pos.width = WIDTH;
	m_sprite.setTextureRect(m_texture_pos);
	m_sprite.setOrigin(WIDTH / 2, HEIGHT);
	if (player == 1)
	{
		m_sprite.setPosition(900, 800);
		if (sf::Joystick::isConnected(0))
			m_joystick = 0;
	}
	else
	{
		m_sprite.setPosition(1900, 800);
		flip();
		if (sf::Joystick::isConnected(1))
			m_joystick = 1;
	}
}

Fighter::~Fighter(void)
{
}

sf::Sprite	Fighter::getSprite(void)
{
	return (m_sprite);
}

void		Fighter::flip(void)
{
	m_face_right = !m_face_right;
	m_sprite.scale(-1, 1);
}

void		Fighter::move(float x, float y)
{
	m_sprite.move(x, y);
}

void		Fighter::setMovement(int movement)
{
	if (m_state == STAND)
		m_moving = movement;
}

void		Fighter::changeState(int state)
{
	if (m_state)
		return ;
	switch (state)
	{
	case LIGHT_ATTACK:
		m_state = LIGHT_ATTACK;
		m_anim_state = 0;
		m_anim_clock.restart();
		m_moving = NONE;
		break;
	}
}

void		Fighter::doAction(sf::View &limit)
{
	if (m_state == LIGHT_ATTACK && m_anim_clock.getElapsedTime().asMilliseconds() >= ANIMATION_SPEED)
	{
		m_anim_clock.restart();
		m_anim_state += 1;
		if (m_anim_state >= ANIMATION_KEY)
		{
			m_anim_state = 0;
			m_state = 0;
		}
		m_texture_pos.left = WIDTH * m_anim_state;
		m_sprite.setTextureRect(m_texture_pos);
	}
}

void		Fighter::doMovement(sf::View &limit)
{
	doAction(limit);
	if (m_moving)
	{
		float limit_left = limit.getCenter().x - limit.getSize().x / 2.0f;
		float limit_right = limit.getCenter().x + limit.getSize().x / 2.0f;
		float sprite_left = m_sprite.getGlobalBounds().left;
		float sprite_right = m_sprite.getGlobalBounds().left + m_sprite.getLocalBounds().width;
		if (m_moving == RIGHT)
		{
			if (sprite_right + SPEED < limit_right)
				m_sprite.move(SPEED, 0);
		}
		else if (m_moving == LEFT)
		{
			if (sprite_left - SPEED > limit_left)
				m_sprite.move(-SPEED, 0);
		}
	}
}

int		Fighter::hasJoystick(void)
{
	return (m_joystick);
}

bool		Fighter::faceToRight(void)
{
	return (m_face_right);
}