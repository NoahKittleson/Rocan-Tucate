//
//  Score.h
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/27/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Score
{
public:
    Score();
    ~Score();
    
    void Load(std::string filename);
    void Draw(sf::RenderWindow & renderWindow);
    void Update(float elapsedTime);
    void SetPosition(float x, float y);

private:
    sf::Text _text;
    sf::Font _font;
    std::string _filename;
    bool _isloaded;
    float _gamescore;
    
    std::string GetScoreString();
};