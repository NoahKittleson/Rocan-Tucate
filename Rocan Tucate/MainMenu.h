//
//  MainMenu.h
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/20/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#pragma once

//#include <RocanTucatePrefix.pch>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

class MainMenu
{
    
public:
    MainMenu();
    enum MenuResult { Nothing, Exit, Play, Play2P };
    
    struct MenuItem
    {
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };
    MenuResult GetMenuResponse(sf::RenderWindow& window, float elapsedTime);
    
private:
    void ChangeColor(float elapsed);
	void ReverseChangeColor(float elapsed);
    MenuResult HandleClick(int x, int y);
    std::list<MenuItem> _menuitems;
    
    void Update(float Elapsed);
    float TotalElapsed;
    sf::Sprite _MenuButtons;
    sf::Sprite _MenuSprite;
    sf::Sprite _SunSprite;
    sf::Sprite _StarSprite;
    sf::Texture _texture;
    sf::Texture _texture2;
    sf::Texture _texture3;
    sf::Texture _texture4;
    sf::Color _backgroundColor;
    
    float red;
    float green;
    float blue;
    float Opacity;
    
    bool _daynight;                 //day = true, night = false
    bool _flip;						//used for animation
	bool _reverse;					//used for day to night then night to day transition.
};