#pragma once
#include <SFML/Graphics.hpp>


class GameObject {
public:
	GameObject(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	virtual ~GameObject();

	// Setters
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);

	// Getters
	sf::Vector2f getPosition();

	sf::Vector2f getSize();
	sf::FloatRect getGlobalBounds();



	virtual void draw(sf::RenderWindow& window);

protected:

	sf::Sprite sprite;
};