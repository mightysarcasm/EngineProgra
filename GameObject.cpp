#include "GameObject.h"

GameObject::GameObject(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) {
	sprite.setTexture(*texture);
	sprite.setScale(size.x / texture->getSize().x, size.y / texture->getSize().y);
	sprite.setPosition(position);
}

GameObject::~GameObject() {
}

void GameObject::setPosition(sf::Vector2f position) {
	sprite.setPosition(position);
}

void GameObject::setSize(sf::Vector2f size) {
	sprite.setScale(size.x / sprite.getTexture()->getSize().x, size.y / sprite.getTexture()->getSize().y);
}

sf::Vector2f GameObject::getPosition() {
	return sprite.getPosition();
}

sf::Vector2f GameObject::getSize() {
	return sf::Vector2f(sprite.getTexture()->getSize().x * sprite.getScale().x, sprite.getTexture()->getSize().y * sprite.getScale().y);
}

sf::FloatRect GameObject::getGlobalBounds() {
	return sprite.getGlobalBounds();
}

void GameObject::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}