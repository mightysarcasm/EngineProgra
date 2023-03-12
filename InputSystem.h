#pragma once

#include <SFML/Window.hpp>

class InputSystem {
public:
  InputSystem();
 bool isMovingUp() const;
  bool isMovingDown() const;
  bool isMovingLeft() const;
  bool isMovingRight() const;

  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
  bool mIsMovingUp;
  bool mIsMovingDown;
  bool mIsMovingLeft;
  bool mIsMovingRight;
};