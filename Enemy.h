#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Collision.h"

class Enemy : public Character {
public:
	Enemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float speed,float jumpHeight, float jumpTime,float gravity);
	void update(float deltaTime);
	void setTextureRect(sf::IntRect rect);

	sf::Sprite getSprite();
	Collision& getCollision(){return m_collision;}


private:
	Collision m_collision;

	float m_gravity;
};