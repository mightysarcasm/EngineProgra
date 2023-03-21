#include "GameObject.h"
#pragma once
#include <SFML/Graphics.hpp>
class Character : public GameObject {
public:
	Character(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed, float jumpHeight, float jumpTime);
	virtual ~Character();

	// Setters
	void setSpeed(float speed);
	void setJumpHeight(float jumpHeight);
	void setJumpTime(float jumpTime);

	// Getters
	float getSpeed();
	float getJumpHeight();
	float getJumpTime();

	// Other functions
	void moveLeft();
	void moveRight();
	void Idle();
	void jump();
	virtual void update(float deltaTime);

	sf::Vector2f m_velocity;


protected:
	float speed;
	float jumpHeight;
	float jumpTime;
	float jumpTimer;
	bool isJumping;
};