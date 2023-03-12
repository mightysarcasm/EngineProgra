#pragma once

#include <SFML/Graphics.hpp>
#include "CollisionDetection.h"
#include "Player.h"

class Player;
class Enemy {
public:
	Enemy();

	void setPosition(float x, float y);
	void move(sf::Vector2f& movement);
	sf::Sprite& getSprite();
	sf::FloatRect getBoundingBox() const;
	bool checkCollision(Player& player);
	sf::RectangleShape mShape;


private:
};