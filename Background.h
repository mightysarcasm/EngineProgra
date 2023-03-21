#include "GameObject.h"
#pragma once

class Background : public GameObject {
public:
	Background(sf::Texture* texture, sf::Vector2u windowSize);
};