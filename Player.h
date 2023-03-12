#pragma once

#include <SFML/Graphics.hpp>
#include "CollisionDetection.h"
#include "Enemy.h"

class Enemy;

class Player {
public:
	Player(sf::Texture& texture);
	void setPosition(float x, float y);
	void move(sf::Vector2f& movement);
	sf::Sprite& getSprite();
	bool checkCollision(Enemy& enemy);

private:
	sf::Sprite mSprite;
};