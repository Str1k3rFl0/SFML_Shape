#include "HUD.h"

sf::Text HUD::getMessage()
{
    // Create the text
    m_font.loadFromFile("fonts/lightfont.otf");
    m_StartMessage.setFont(m_font);
    m_StartMessage.setString("Apasa ENTER!");
    m_StartMessage.setCharacterSize(40);
    m_StartMessage.setFillColor(sf::Color::Black);

    // Position the test on the center of the screen
    textRect = m_StartMessage.getLocalBounds();
    m_StartMessage.setOrigin(textRect.left +
                textRect.width / 2.0f,
                textRect.top +
                textRect.height / 2.0f);
    m_StartMessage.setPosition(800 / 2.0f, 600 / 2.0f);

    return m_StartMessage;
}
