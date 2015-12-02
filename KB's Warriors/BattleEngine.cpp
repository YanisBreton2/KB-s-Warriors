#include "BattleEngine.h"


BattleEngine::BattleEngine(void)
{
	m_texture_background.loadFromFile("../Ressources/Background/ground.png");
	m_sprite_background.setTexture(m_texture_background);
	m_camera.setSize(1400, 800);
	m_camera.setCenter(1400, 400);
	m_player_1 = new Fighter(1);
	m_player_2 = new Fighter(2);
}


BattleEngine::~BattleEngine(void)
{
	delete m_player_1;
	delete m_player_2;
}

void	BattleEngine::run(sf::RenderWindow &win)
{
	bool	fighting = true;
	win.setView(m_camera);
	while (win.isOpen() && fighting)
	{
		sf::Event	event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
			event_handler(event);
		}
		m_player_1->doMovement(m_camera);
		m_player_2->doMovement(m_camera);
		win.clear(sf::Color::Black);
		win.draw(m_sprite_background);
		win.draw(m_player_1->getSprite());
		win.draw(m_player_2->getSprite());
		win.display();
	}
}

void		BattleEngine::event_handler(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::D)
			m_player_1->setMovement(RIGHT);
		else if (event.key.code == sf::Keyboard::Q)
			m_player_1->setMovement(LEFT);
		else if (event.key.code == sf::Keyboard::G)
			m_player_1->changeState(LIGHT_ATTACK);
		else if (event.key.code == sf::Keyboard::Right)
			m_player_2->setMovement(RIGHT);
		else if (event.key.code == sf::Keyboard::Left)
			m_player_2->setMovement(LEFT);
		else if (event.key.code == sf::Keyboard::K)
			m_player_2->changeState(LIGHT_ATTACK);
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Q)
			m_player_1->setMovement(NONE);
		else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left)
			m_player_2->setMovement(NONE);
	}
	else if (event.type == sf::Event::JoystickMoved && (event.joystickMove.joystickId == m_player_1->hasJoystick() || event.joystickMove.joystickId == m_player_2->hasJoystick()))
	{
		if (event.joystickMove.axis == sf::Joystick::X)
		{
			if (event.joystickMove.position < -30)
				event.joystickMove.joystickId == 0 ? m_player_1->setMovement(LEFT) : m_player_2->setMovement(LEFT);
			else if (event.joystickMove.position > 30)
				event.joystickMove.joystickId == 0 ? m_player_1->setMovement(RIGHT) : m_player_2->setMovement(RIGHT);
			else
				event.joystickMove.joystickId == 0 ? m_player_1->setMovement(NONE) : m_player_2->setMovement(NONE);
		}
	}
	else if (event.type == sf::Event::JoystickButtonPressed && (event.joystickMove.joystickId == m_player_1->hasJoystick() || event.joystickMove.joystickId == m_player_2->hasJoystick()))
	{
		if (event.joystickButton.button == 2)
			event.joystickMove.joystickId == 0 ? m_player_1->changeState(LIGHT_ATTACK) : m_player_2->changeState(LIGHT_ATTACK);
		else
			printf("%d\n", event.joystickButton.button);
	}
}
