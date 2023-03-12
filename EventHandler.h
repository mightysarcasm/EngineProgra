#pragma once

#include <SFML/Graphics.hpp>
#include "InputSystem.h"

class EventHandler {
public:
	EventHandler(InputSystem& inputSystem);

	void handleEvent(const sf::Event& event);

private:
	InputSystem& mInputSystem;
};