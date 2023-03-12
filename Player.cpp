#include "Player.h"

Player::Player(sf::Texture& texture) {
	mSprite.setTexture(texture);
	sf::IntRect rectSpriteSheet(0, 0, 120, 120);
	mSprite.setTextureRect(rectSpriteSheet);
}

void Player::setPosition(float x, float y) {
	mSprite.setPosition(x, y);
}

void Player::move(sf::Vector2f& movement) {
	mSprite.move(movement);
}

sf::Sprite& Player::getSprite() {
	return mSprite;
}

bool Player::checkCollision(Enemy& enemy) {
	return CollisionDetection::checkCollision(mSprite.getGlobalBounds(), enemy.getBoundingBox());
}