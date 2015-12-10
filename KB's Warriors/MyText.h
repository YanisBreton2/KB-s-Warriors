#ifndef MY_TEXT_H_
# define MY_TEXT_H_

# include <SFML\Graphics.hpp>

class MyText
{
public:
					MyText(std::string text, std::string font_path, sf::Vector2f &position, int size_font = 30);
					~MyText(void);
	sf::Text		getSprite(void);
	sf::Font		getFont(void);
	void			setFont(sf::Font &font);
	void			setFont(std::string &font_path);
	int				getFontSize(void);
	std::string		getText(void);
	void			setText(std::string text);
	sf::Vector2f	getPosition(void);
	void			setPosition(float x, float y);
	void			setColor(sf::Color &color);
private:
	sf::Text		m_text;
	sf::Font		m_font;
};

#endif /* !MY_TEXT_H_ */
