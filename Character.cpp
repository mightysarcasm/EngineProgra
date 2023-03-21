#include "Character.h"

Character::Character(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed, float jumpHeight, float jumpTime) : GameObject(texture, size, position) {
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	this->jumpTime = jumpTime;
	this->jumpTimer = 0.f;
	this->isJumping = false;

}

Character::~Character() {
}

void Character::setSpeed(float speed) {
	this->speed = speed;
}

void Character::setJumpHeight(float jumpHeight) {
	this->jumpHeight = jumpHeight;
}

void Character::setJumpTime(float jumpTime) {
	this->jumpTime = jumpTime;
}

float Character::getSpeed() {
	return speed;
}

float Character::getJumpHeight() {
	return jumpHeight;
}

float Character::getJumpTime() {
	return jumpTime;
}

void Character::moveLeft() {
		m_velocity.x = -speed;
}

void Character::moveRight() {
		m_velocity.x = speed;
}

void Character::Idle(){
m_velocity.x = 0.f;


}

void Character::jump() {
	if (!isJumping) {
		isJumping = true;
		jumpTimer = 0.f;
	}
}

void Character::update(float deltaTime) {
	if (isJumping) {
		jumpTimer += deltaTime;
		if (jumpTimer <= jumpTime / 2.f) {
			sprite.move(0.f, -2 * jumpHeight * deltaTime / jumpTime);
		} else if (jumpTimer <= jumpTime) {
			sprite.move(0.f, 2 * jumpHeight * deltaTime / jumpTime);
		} else {
			isJumping = false;
		}
	}
}