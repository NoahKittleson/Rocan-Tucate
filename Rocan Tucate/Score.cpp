//
//  Score.cpp
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/27/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include "Score.h"
#include <sstream>
#include <SFML/Graphics.hpp>

Score::Score()
: _gamescore(0)
{
}

Score::~Score()
{
}

void Score::Load(std::string filename)
{
    if (_font.loadFromFile(filename) == false)
    {
        _filename = "";
        _isloaded = false;
    }
    else
    {
        _filename = filename;
        _text.setFont(_font);
        _isloaded = true;
        _text.setCharacterSize(50);
        _text.setColor(sf::Color::White);
        _text.setString(GetScoreString());
    }
}

void Score::Draw(sf::RenderWindow & renderWindow)
{
    if (_isloaded)
    {
        renderWindow.draw(_text);
    }
}

void Score::Update(float elapsedTime)
{
    _gamescore += (30*elapsedTime);
    _text.setString(GetScoreString());
}

void Score::SetPosition(float x, float y)
{
    if (_isloaded)
    {
        _text.setPosition(x, y);
    }
}

std::string Score::GetScoreString()
{
    sf::Text text;
    std::ostringstream ss;
    ss << "Score: " << static_cast<int>(_gamescore);
    return (ss.str());
}
