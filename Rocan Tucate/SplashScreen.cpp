//
//  SplashScreen.cpp
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/19/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include <RocanTucatePrefix.pch>
#include "SplashScreen.h"


SplashScreen::SplashScreen(sf::RenderWindow &rw)
{
    texture.loadFromFile("RocanTucateIcon.png");
    icon.setTexture(texture);
    icon.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    icon.setPosition(rw.getSize().x/2, rw.getSize().y/2);
    font.loadFromFile("BasicHandwriting.ttf");
    message.setFont(font);
    message.setString("Press Any Button to Start");
    message.setColor(sf::Color::Red);
    message.setPosition(320, rw.getSize().y/4*3);
    title.setFont(font);
    title.setString("ROCAN TUCATE ALPHA 1.0");
    title.setCharacterSize(60);
    title.setColor(sf::Color::Red);
    title.setPosition(100, rw.getSize().y/6);
    copyright.setFont(font);
    copyright.setString("Copyright LOLOLOL");
    copyright.setCharacterSize(10);
    copyright.setColor(sf::Color::Red);
    copyright.setPosition(rw.getSize().x/6*5, rw.getSize().y/10*9);
}

void SplashScreen::draw(sf::RenderWindow & renderWindow)
{
    renderWindow.clear(sf::Color::Black);
    renderWindow.draw(title);
    renderWindow.draw(icon);
    renderWindow.draw(copyright);
    if (blink) {
        renderWindow.draw(message);
    }
    renderWindow.display();
}

bool SplashScreen::handleEvent(sf::RenderWindow &rw)
{
    sf::Event event;
    while (rw.pollEvent(event)) {
        if (event.type == sf::Event::EventType::KeyPressed
            || event.type == sf::Event::EventType::MouseButtonPressed
            || event.type == sf::Event::EventType::Closed)
        {
            return true;
        }
    }
    return false;
}


bool SplashScreen::update(float elapsed)
{
    totalElapsed += elapsed;
    if (totalElapsed > 1.f) {
        blink = !blink;
        totalElapsed = 0;
        return true;
    }
    return false;
}