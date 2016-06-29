//
//  SplashScreen.h
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/19/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#pragma once


class SplashScreen
{
public:
    SplashScreen(sf::RenderWindow &rw);
    bool handleEvent(sf::RenderWindow &rw);
    void draw (sf::RenderWindow& window);
    bool update(float elapsed);
    
private:
    sf::Sprite icon;
    sf::Texture texture;
    sf::Text title;
    sf::Text message;
    sf::Text copyright;
    sf::Font font;
    bool blink {true};
    float totalElapsed {0.f};
};