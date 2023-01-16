#pragma once
#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <sstream>

class HUD
{
private:
    sf::Text m_StartMessage;
    sf::Font m_font;
    sf::FloatRect textRect;

public:
    sf::Text getMessage();
};

#endif // HUD_H
