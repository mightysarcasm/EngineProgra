#include "Player.h"
#include <cmath>

Player::Player(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed, float jumpHeight, float jumpTime, float gravity):Character(texture, size, position, speed, jumpHeight,jumpTime), m_collision(sprite){
	m_velocity.x = 0.f;
	m_velocity.y = 0.f;
	m_gravity = 20.f;
}

void Player::handleInput() {
	// Left & Right Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	    moveRight();
	}
	else {
		Idle();
	}

	// Jump
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
		m_velocity.y = -sqrtf(2.f * jumpHeight * m_gravity);
		isJumping = true;
	}
}

void Player::update(float deltaTime) {
	// Apply gravity
	m_velocity.y += m_gravity * deltaTime;

	// X-Movement
	sprite.move(m_velocity.x * deltaTime, 0.f);

	// Collision with screen edges
	if (sprite.getPosition().x < 0.f) {
		sprite.setPosition(0.f, sprite.getPosition().y);
	}
	else if (sprite.getPosition().x + sprite.getGlobalBounds().width > 800.f) {
		sprite.setPosition(800.f - sprite.getGlobalBounds().width, sprite.getPosition().y);
	}

	// Y-Movement
	sprite.move(0.f, m_velocity.y * deltaTime);

	// Collision With Ground
	if (sprite.getPosition().y + sprite.getGlobalBounds().height > 600.f) {
		sprite.setPosition(sprite.getPosition().x, 600.f - sprite.getGlobalBounds().height);
		m_velocity.y = 0.f;
		isJumping = false;
	}
}

sf::Sprite Player::getSprite() {
	return sprite;
}

