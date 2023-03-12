#include "InputSystem.h"

InputSystem::InputSystem() :
mIsMovingUp(false),
mIsMovingDown(false),
mIsMovingLeft(false),
mIsMovingRight(false){}

void InputSystem::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::W)
	mIsMovingUp = isPressed;
  else if (key == sf::Keyboard::S)
	mIsMovingDown = isPressed;
  else if (key == sf::Keyboard::A)
	mIsMovingLeft = isPressed;
  else if (key == sf::Keyboard::D)
	mIsMovingRight = isPressed;
}

bool InputSystem::isMovingUp() const {
	return mIsMovingUp;
}

bool InputSystem::isMovingDown() const {
	return mIsMovingDown;
}

bool InputSystem::isMovingLeft() const {
	return mIsMovingLeft;
}

bool InputSystem::isMovingRight() const {
	return mIsMovingRight;
}