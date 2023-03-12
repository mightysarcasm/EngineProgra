#pragma once

#include <SFML/Graphics.hpp>

class CollisionDetection {
public:
	static bool checkCollision(const sf::FloatRect& rect1, const sf::FloatRect& rect2);
};