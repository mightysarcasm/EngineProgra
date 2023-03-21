#pragma once
#include <SFML/Graphics.hpp>


class Collision {
public:
	Collision(sf::Sprite& body);

	void Move(float x, float y) { body.move(x, y); }

	bool checkCollision(Collision& other, float recoil);

	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getHalfSize() {
		sf::FloatRect bounds = body.getLocalBounds();
		return sf::Vector2f(bounds.width / 2.0f, bounds.height / 2.0f);
	}

private:
	sf::Sprite& body;
};
