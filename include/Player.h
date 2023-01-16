#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Audio.h"

class Player
{
private:
    // Audio header
    Audio ad;

    // The player is a shape
    sf::RectangleShape m_Shape;

    // The position of shape
    sf::Vector2f m_ShapePosition;

    // Clock for timing
    sf::Clock clock;

    // How fast is the shape?
    float m_SpeedShape = 500.f;

    // Is shape still active?
    bool m_ActiveShape = false;

public:
    void createShape(float startX, float startY);
    sf::RectangleShape getShape();
    void isShapeActive();
};

#endif // PLAYER_H
