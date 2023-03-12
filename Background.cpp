#include "Background.h"

Background::Background(sf::Texture& texture) {
	mSprite.setTexture(texture);
}

void Background::draw(sf::RenderWindow& window) {
	window.draw(mSprite);
}