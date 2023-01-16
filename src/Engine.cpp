#include "Engine.h"

Engine::Engine()
{
    // Creating the window
    m_Position.x = WINDOW_WIDTH;
    m_Position.y = WINDOW_HEIGHT;
    m_Window.create(sf::VideoMode(m_Position.x, m_Position.y),
                    "SFML TEST WORK");

    // Frame limit 75
    limitFPS();

    // Creating background
    m_BackgroundTexture = TextureHolder::GetTexture(
        "graphics/background.jpg");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    m_BackgroundSprite.setPosition(0, 0);

    // Create Shape
    pl.createShape(800 / 2, 600 / 2);
}

// Function Run()
void Engine::run()
{
    while (m_Window.isOpen())
    {
        input();
        update();
        draw();
    }
}

// Function input()
void Engine::input()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_Window.close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_Window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        m_pausedTest = false;
    }
}

// Function update()
void Engine::update()
{
    if (!m_pausedTest)
    {
        pl.isShapeActive();
    }
}

// Function draw()
void Engine::draw()
{
    m_Window.clear();
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(pl.getShape());
    if (m_pausedTest)
    {
        // Draw the text
        m_Window.draw(hud.getMessage());
    }
    m_Window.display();
}

void Engine::limitFPS()
{
    m_Window.setFramerateLimit(75);
}
