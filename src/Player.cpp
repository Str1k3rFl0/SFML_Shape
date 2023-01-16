#include "Player.h"

// Function for creating the shape
void Player::createShape(float startX, float startY)
{
    m_ShapePosition.x = startX;
    m_ShapePosition.y = startY;

    m_Shape.setSize(sf::Vector2f(50.f, 50.f));
    m_Shape.setPosition(m_ShapePosition);
    m_Shape.setFillColor(sf::Color::Blue);
}

// Return the shape
sf::RectangleShape Player::getShape()
{
    return m_Shape;
}

// Function for moving the shape
void Player::isShapeActive()
{
    if (!m_ActiveShape)
    {
        m_ActiveShape = true;
    }
    else
    {
        sf::Time dt = clock.restart();

        // Moving left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_Shape.setPosition(
                m_Shape.getPosition().x -
                (m_SpeedShape * dt.asSeconds()),
                m_Shape.getPosition().y);

            // Left screen collision
            if (m_Shape.getPosition().x < 0.f)
            {
                m_Shape.setPosition(0.f, m_Shape.getPosition().y);
                // Sound effect
                ad.getSound();
                // Change color
                m_Shape.setFillColor(sf::Color::Red);
            }
        }

        // Moving Right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_Shape.setPosition(
                m_Shape.getPosition().x +
                (m_SpeedShape * dt.asSeconds()),
                m_Shape.getPosition().y);

            // Right screen collision
            if (m_Shape.getPosition().x + m_Shape.getGlobalBounds().width > 800)
            {
                m_Shape.setPosition(800 - m_Shape.getGlobalBounds().width, m_Shape.getPosition().y);
                // Sound effect
                ad.getSound();
                // Change color
                m_Shape.setFillColor(sf::Color::Black);
            }
        }

        // Moving Top
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_Shape.setPosition(
                m_Shape.getPosition().x,
                m_Shape.getPosition().y -
                (m_SpeedShape * dt.asSeconds()));

            // Top screen collision
            if (m_Shape.getPosition().y < 0.f)
            {
                m_Shape.setPosition(m_Shape.getPosition().x, 0.f);
                // Sound effect
                ad.getSound();
                // Change color
                m_Shape.setFillColor(sf::Color::Magenta);
            }
        }

        // Moving Down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            m_Shape.setPosition(
                m_Shape.getPosition().x,
                m_Shape.getPosition().y +
                (m_SpeedShape * dt.asSeconds()));

            // Down screen collision
            if (m_Shape.getPosition().y + m_Shape.getGlobalBounds().height > 600)
            {
                m_Shape.setPosition(m_Shape.getPosition().x, 600 - m_Shape.getGlobalBounds().height);
                // Sound effect
                ad.getSound();
                // Change color
                m_Shape.setFillColor(sf::Color::Green);
            }
        }
    }
}
