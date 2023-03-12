#include "Game.h"
#include "Background.h"

#include <iostream>


Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer(mTexture), mEnemy(), mInputSystem(), mEventHandler(mInputSystem) {
	if (!mTexture.loadFromFile("/Users/rafael/Desktop/GameEngine/GameEngineII/images/texture.png")) {
		// Error: failed to load texture
		return;
	}
	mPlayer.setPosition(100, 100);
	mEnemy.setPosition(300, 300);

}

void Game::run()
{
	sf::Clock clock;
	while (mWindow.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		mEventHandler.handleEvent(event);
		switch (event.type) {
			case sf::Event::Closed:
				mWindow.close();
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
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mInputSystem.isMovingUp())
		movement.y -= PlayerSpeed;
	if (mInputSystem.isMovingDown())
		movement.y += PlayerSpeed;
	if (mInputSystem.isMovingLeft())
		movement.x -= PlayerSpeed;
	if (mInputSystem.isMovingRight())
		movement.x += PlayerSpeed;

	sf::Vector2f deltaMovement = movement * deltaTime.asSeconds();
	mPlayer.move(deltaMovement);

	if (mPlayer.checkCollision(mEnemy)) {
		std::cout << "Collision detected!" << std::endl;

	}
	else{
		std::cout << "No Collision" << std::endl;

	}
}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer.getSprite());
mWindow.draw(mEnemy.mShape);


	mWindow.display();
}