#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Collision.h"


class Player : public Character {
public:
	Player(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed, float jumpHeight,float jumpTime, float gravity);

	void handleInput();
	void update(float deltaTime);
	sf::Sprite getSprite();

	Collision& getCollision(){return m_collision;}
private:
	Collision m_collision;
	float m_gravity;
};
