#include "Enemy.h"
#include <cmath>

Enemy::Enemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed,float jumpHeight, float jumpTime, float gravity):Character(texture, size, position, speed, jumpHeight,jumpTime), m_collision(sprite){
	m_velocity.x = speed;
	m_gravity = 100.f;
}


void Enemy::update(float deltaTime) {
	// Apply gravity
	m_velocity.y += m_gravity * deltaTime;

	// X Movement
	sprite.move(m_velocity.x * deltaTime, 5.f);

	// Collision with screen edges
	if (sprite.getPosition().x < 0.f) {
		sprite.setPosition(0.f, sprite.getPosition().y);
		moveRight();

	}
	else if (sprite.getPosition().x + sprite.getGlobalBounds().width > 800.f) {
		sprite.setPosition(800.f - sprite.getGlobalBounds().width, sprite.getPosition().y);
		moveLeft();

	}

	// Collision with ground
	if (sprite.getPosition().y + sprite.getGlobalBounds().height > 600.f) {
		sprite.setPosition(sprite.getPosition().x, 600.f - sprite.getGlobalBounds().height);
		m_velocity.y = 0.f;
		isJumping = false;
	}
}

sf::Sprite Enemy::getSprite() {
	return sprite;
}

void Enemy::setTextureRect(sf::IntRect rect) {
	sprite.setTextureRect(rect);
}

