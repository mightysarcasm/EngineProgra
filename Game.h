#pragma once

#include <SFML/Graphics.hpp>
#include "InputSystem.h"
#include "EventHandler.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"

class Game {
public:
    Game();

    void run();
    const float PlayerSpeed = 100.f;

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow mWindow;
    Player mPlayer;
    Enemy mEnemy;

    sf::Texture mTexture;
    InputSystem mInputSystem;
    EventHandler mEventHandler;
};