#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Animation.h"



int main() {
	// Create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Paper Mario World");

	// Load textures
	sf::Texture bgTexture;
	bgTexture.loadFromFile("/Users/rafael/Desktop/Paper Mario World/resources/background.png");
	sf::Texture marioTexture;
	marioTexture.loadFromFile("/Users/rafael/Desktop/Paper Mario World/resources/mario.png");
	sf::Texture dragonTexture;
	dragonTexture.loadFromFile("/Users/rafael/Desktop/Paper Mario World/resources/dragon.png");



	// Render GameObjects
	Player player(&marioTexture, sf::Vector2f(64.f, 110.f), sf::Vector2f(400.f, 400.f), 20.f, 250.f,200.f, 2.f);
	Enemy enemy(&dragonTexture, sf::Vector2f(440.f, 110.f), sf::Vector2f(400.f, 400.f), 10.f, 0.f,0.f, 0.5f);
	Background background(&bgTexture, window.getSize());
	Animation animation(&dragonTexture, sf::Vector2u(5,1) ,0.1f);


	float deltaTime = 0.0f;
	sf::Clock clock;

	// GameLoop
	while (window.isOpen()) {


deltaTime=clock.restart().asSeconds();
		// Handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// Inputs
		player.handleInput();

		// Updates
		player.update(1.f / 60.f);
		enemy.update(1.f / 60.f);
		player.getCollision().checkCollision(enemy.getCollision(),1.0f);
		animation.Update(0,deltaTime);
		enemy.setTextureRect(animation.uvRect);

		// Draw
		window.clear();
		background.draw(window);
		window.draw(player.getSprite());
		window.draw(enemy.getSprite());

		window.display();
	}

	return 0;
}