//
//  MainMenu.cpp
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/20/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include <RocanTucatePrefix.pch>
#include "MainMenu.h"
#include "ResourcePath.hpp"

MainMenu::MainMenu()
: TotalElapsed(0),
_flip(true), _daynight(true), _reverse(false),
red(130), green(200), blue(230), Opacity(0)

{
	_backgroundColor = sf::Color(red, green, blue);	//R - G - B
	
    //MenuScreen sprite
    _texture.loadFromFile(resourcePath() + "NewMenuScreen.png");
    _MenuSprite.setTexture(_texture);
    _MenuSprite.setScale(16.0f, 16.0f);
	//Sun Sprite
	_texture3.loadFromFile(resourcePath() + "GloriousFather.png");
	_SunSprite.setTexture(_texture3);
	_SunSprite.setScale(16.0f, 16.0f);
	_SunSprite.setTextureRect(sf::IntRect(0,0,30,30));
	_SunSprite.setPosition(-80.0f, -80.0f);
	//Star Sprite
	_texture4.loadFromFile(resourcePath() + "StarryNight.png");
	_StarSprite.setTexture(_texture4);
	_StarSprite.setScale(16.0f, 16.0f);
	_StarSprite.setColor(sf::Color(125,125,125,0));
	//MenuButton Sprite
    _texture2.loadFromFile(resourcePath() + "MenuButtons.png");
    _MenuButtons.setTexture(_texture2);
    _MenuButtons.setScale(16.0f, 16.0f);
    
    //Setup clickable regions
    
    //Play menu item coordinates
    MenuItem playButton;
	playButton.rect = sf::IntRect(48,256,416,96);
    playButton.action = Play;
    
    //Play menu item coordinates
    MenuItem play2PButton;
	play2PButton.rect = sf::IntRect(528,240,384,112);
    play2PButton.action = Play2P;
    
    //Exit menu item coordinates
    MenuItem exitButton;
	exitButton.rect = sf::IntRect(304,464,448,128);
    exitButton.action = Exit;
    
    _menuitems.push_back(playButton);
    _menuitems.push_back(play2PButton);
    _menuitems.push_back(exitButton);
    
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;
    
    for ( it = _menuitems.begin(); it != _menuitems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
        if (menuItemRect.contains(x, y))
		{ return (*it).action; }
    }
    return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse (sf::RenderWindow& window, float elapsed)
{
    sf::Event menuEvent;

        while (window.pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::MouseButtonPressed)
            {
                return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
			if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
			if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Key::Escape)
			{
				return Exit;
			}
                
        }
        Update(elapsed);
		if (_reverse)
		{ ReverseChangeColor(elapsed); }
		else ChangeColor(elapsed);
	
        window.clear(_backgroundColor);
	
		if (_daynight)
		{ window.draw(_SunSprite);}
		else window.draw(_StarSprite);
	
		window.draw(_MenuSprite);
        window.draw(_MenuButtons);
        window.display();
	
	return Nothing;
}


void MainMenu::Update(float Elapsed)
{
	_SunSprite.move(10*Elapsed, 30*Elapsed);
	
    TotalElapsed += Elapsed;
    if (TotalElapsed >= 1.0)
    {
        TotalElapsed = 0;
        _MenuButtons.move(0, -10);
		_SunSprite.setTextureRect(sf::IntRect(0,0,30,30));
        if (_flip == false)
        {
            _MenuButtons.move(0,20);
			_SunSprite.setTextureRect(sf::IntRect(30,0,30,30));
		}
        _flip = !_flip;
    }
}

void MainMenu::ChangeColor(float elapsed)
{
	if (_daynight)
	{
		if (red > 20)
		{
			red -= (20*elapsed);
		}
		if (green > 20)
		{
			green -= (10*elapsed);
		}
		if (blue > 30 && green < 80)
		{
			blue -= (35*elapsed);
			if (blue <= 30)
			{
				_daynight = false;
			}
		}
		_backgroundColor = sf::Color(red,green,blue);
	}
	else
	{
		Opacity += (30*elapsed);
		_StarSprite.setColor(sf::Color(125,125,125, Opacity));
		if (Opacity >= 255)
		{
			_reverse = true;
		}
	}
}

void MainMenu::ReverseChangeColor(float elapsed)
{
	if (!_daynight)
	{
		if (blue < 230)				//130/200/230 RGB
		{
			blue += (35*elapsed);
		}
		if (green < 200)
		{
			green += (15*elapsed);
		}
		if (red < 130 && green > 130)
		{
			red += (40*elapsed);
		}
		_backgroundColor = sf::Color(red, green, blue);
		if (Opacity > 1)
		{ Opacity -= (125*elapsed); }
		_StarSprite.setColor(sf::Color(125,125,125,Opacity));
		if (green >= 200)
		{
			_daynight = true;
			_SunSprite.setPosition(-230, -530);
		}
	}
	else
	{
		if (_SunSprite.getPosition().x >= -80)
		{
			_reverse = false;
		}
	}
}







