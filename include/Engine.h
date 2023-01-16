#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"
#include "HUD.h"

class Engine
{
private:
    // The texture holder
    TextureHolder th;
    // The player holder
    Player pl;
    // The HUD holder
    HUD hud;

    // Variable for window
    sf::RenderWindow m_Window;
    sf::Vector2f m_Position;

    // Is game still running?
    bool m_pausedTest = true;

    // Variable for background
    // Texture and Sprite
    sf::Texture m_BackgroundTexture;
    sf::Sprite m_BackgroundSprite;

    // Private Functions for engine
    void input();
    void update();
    void draw();

    void limitFPS();

protected:
    // Variables for window resolution
    const unsigned WINDOW_WIDTH  = 800;
    const unsigned WINDOW_HEIGHT = 600;

public:
    Engine();
    void run();
};

#endif // ENGINE_H
