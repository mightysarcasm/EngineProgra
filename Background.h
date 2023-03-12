#pragma once

#include <SFML/Graphics.hpp>

class Background {
public:
	Background(sf::Texture& texture);

	void draw(sf::RenderWindow& window);

private:
	sf::Sprite mSprite;
};