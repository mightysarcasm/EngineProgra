#include "Enemy.h"

Enemy::Enemy() {
	mShape.setFillColor(sf::Color::Red);
	mShape.setSize(sf::Vector2f(50.f, 50.f));
}

void Enemy::setPosition(float x, float y) {
	mShape.setPosition(x, y);
}

void Enemy::move(sf::Vector2f& movement) {
	mShape.move(movement);
}

sf::Sprite& Enemy::getSprite() {

	static sf::Sprite tempSprite;
	return tempSprite;
}

sf::FloatRect Enemy::getBoundingBox() const {
	return mShape.getGlobalBounds();
}

bool Enemy::checkCollision(Player& player) {
	return CollisionDetection::checkCollision(mShape.getGlobalBounds(), player.getSprite().getGlobalBounds());
}

