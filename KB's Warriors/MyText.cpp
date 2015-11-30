#include "MyText.h"

MyText::MyText(std::string text, std::string font_path, sf::Vector2f &position, int size_font)
{
	m_text.setString(text);
	m_font.loadFromFile(font_path);
	m_text.setFont(m_font);
	m_text.setCharacterSize(size_font);
	m_text.setOrigin(m_text.getLocalBounds().width / 2, 0);
	m_text.setPosition(position);
}

				MyText::~MyText(void)
{
}

sf::Text		MyText::getSprite(void)
{
	return m_text;
}

sf::Font		MyText::getFont(void)
{
	return m_font;
}

void			MyText::setFont(sf::Font &font)
{
	m_font = font;
	m_text.setFont(m_font);
}

void			MyText::setFont(std::string &font_path)
{
	m_font.loadFromFile(font_path);
	m_text.setFont(m_font);
}

int				MyText::getFontSize(void)
{
	return (m_text.getCharacterSize());
}

std::string		MyText::getText(void)
{
	return m_text.getString();
}

void			MyText::setText(std::string text)
{
	m_text.setString(text);
	m_text.setOrigin(m_text.getLocalBounds().width / 2, 0);
}

sf::Vector2f	MyText::getPosition(void)
{
	return (m_text.getPosition());
}

void			MyText::setPosition(float x, float y)
{
	m_text.setPosition(x, y);
}

void	MyText::setColor(sf::Color &color)
{
	m_text.setColor(color);
}
