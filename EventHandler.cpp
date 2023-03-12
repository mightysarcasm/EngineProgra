#include "EventHandler.h"

EventHandler::EventHandler(InputSystem& inputSystem) : mInputSystem(inputSystem) {}

void EventHandler::handleEvent(const sf::Event& event) {
	switch (event.type) {
		case sf::Event::Closed:
			mInputSystem.handlePlayerInput(sf::Keyboard::Escape, true);
			break;
		case sf::Event::KeyPressed:
			mInputSystem.handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			mInputSystem.handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Resized:
			break;
		case sf::Event::LostFocus:
			break;
		case sf::Event::GainedFocus:
			break;
		default:
			break;
	}
}