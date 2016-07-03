//
//  Game.cpp
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/19/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include <RocanTucatePrefix.pch>
#include "Game.h"
#include "ResourcePath.hpp"
#include "SplashScreen.h"


void Game::Start(void)
{
    if (_gamestate != Uninitialized)
        return;
    _mainwindow.create (sf::VideoMode (1024, 768, 32), "Rocan Tucate");
	_mainwindow.setFramerateLimit(60);
	
	sf::Image icon;
	icon.loadFromFile(resourcePath() + "RocanTucateIcon.png");
	//_mainwindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::Texture texture;
	texture.loadFromFile(resourcePath() + "MainBackground.png");
	_background.setTexture(texture);
	_background.setScale(8.0f, 8.0f);
	
	_view1P.setSize(300, 300);
	_view1P.setCenter(100, 100);
	_view1P.setViewport(sf::FloatRect(0, 0, .5, 1));
	_view2P.setSize(300, 300);
	_view2P.setCenter(502, 384);
	_view2P.setViewport(sf::FloatRect(.5, 0, .5, 1));
	_GUI.setSize(400, 300);
	_GUI.setCenter(300, 300);
	_GUI.setViewport(sf::FloatRect(.25,0,0.5,0.5));
	
    _score.Load(resourcePath() + "BasicHandwriting.ttf");
    _score.SetPosition(200.0f, 200.0f);
    
    _jeremified.Load(resourcePath() + "Jeremified.png");
    _jeremified.SetPosition(100.0, 100.0);
    
    //_toucan.Load("ROCAN.png");                   //I don't need to load, because constructor does it
    _toucan.SetPosition(512, 384);
	
	_toggleview = true;
	
    _gamestate = Game::ShowingSplash;

	sf::Clock clock;
    while (!IsExiting())
    {
		float elapsed = clock.restart().asSeconds();
        GameLoop(elapsed);
    }

    _mainwindow.close();

}

bool Game::IsExiting()
{
    if (_gamestate == Game::Exiting)
        return true;
    else
        return false;
}

void Game::GameLoop(float elapsedtime)
{
	_mainwindow.setView(_mainwindow.getDefaultView());
    switch (_gamestate)
    {
        case Game::ShowingMenu:
        {
            ShowMenu();
            break;
        }
        case Game::ShowingSplash:
        {
            ShowSplashScreen();
            break;
        }
		case Game::Playing2P:
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				_toucan.Rotate(elapsedtime);
				_score.Update(elapsedtime);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				_toucan.Rotate(-elapsedtime);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				_jeremified.Update(elapsedtime);
				_score.Update(elapsedtime);
			}
			sf::Event currentevent2P;
			while (_mainwindow.pollEvent(currentevent2P))
			{
				if (currentevent2P.type == sf::Event::Closed)
				{
					_gamestate = Game::Exiting;
				}
				if (currentevent2P.type == sf::Event::KeyPressed)
				{
					if(currentevent2P.key.code == sf::Keyboard::Key::Escape) ShowMenu();
					if (currentevent2P.key.code == sf::Keyboard::Key::F)
					{
						_toggleview = !_toggleview;
						_mainwindow.setView(_mainwindow.getDefaultView());	//this will be overridden if toggleridden is false, so don't worry.
					}
				}
			}
			_mainwindow.clear(sf::Color (0, 0, 0));
			if (!_toggleview)
			{
				_view1P.setCenter(_jeremified.GetPosition().x, _jeremified.GetPosition().y);
				_mainwindow.setView(_view1P);
			}
			_mainwindow.draw(_background);
			_jeremified.Draw(_mainwindow);
			_toucan.Draw(_mainwindow);
			if (!_toggleview) {_mainwindow.setView(_view2P);}
			_mainwindow.draw(_background);
			_jeremified.Draw(_mainwindow);
			_toucan.Draw(_mainwindow);
			_mainwindow.setView(_GUI);
			_score.Draw(_mainwindow);

			_mainwindow.display();
			break;
		}
		
        case Game::Playing:
        {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				_jeremified.Update(elapsedtime);
				_score.Update(elapsedtime);
				_toucan.Rotate(elapsedtime);
			}
			
            sf::Event currentevent;
            while (_mainwindow.pollEvent(currentevent))
            {
                if (currentevent.type == sf::Event::Closed)
                {
                    _gamestate = Game::Exiting;
                }
                if (currentevent.type == sf::Event::KeyPressed)
                {
                    if(currentevent.key.code == sf::Keyboard::Key::Escape) ShowMenu();
                }
            }
			
			_mainwindow.clear(sf::Color (0, 0, 0));
			_mainwindow.draw(_background);
			_jeremified.Draw(_mainwindow);
			_toucan.Draw(_mainwindow);
			_score.Draw(_mainwindow);
			_mainwindow.display();

			break;
        }
        case Game::Paused:
        {
            //nothing here.
			break;
        }
		default:
		{
			break;
		}
    }
}

void Game::ShowSplashScreen()
{
	sf::Clock timer;
	SplashScreen splashscreen (_mainwindow);
	while (_mainwindow.isOpen()) {
		float elapsed = timer.restart().asSeconds();
		splashscreen.update(elapsed);
		splashscreen.draw(_mainwindow);
		if (splashscreen.handleEvent(_mainwindow)) {
			_gamestate = GameState::ShowingMenu;
			return;
		}
	}
}

void Game::ShowMenu()
{
	sf::Clock tempclock;
	MainMenu mainmenu;
	while (_mainwindow.isOpen())
	{
		float elapsed = tempclock.restart().asSeconds();
		MainMenu::MenuResult result = mainmenu.GetMenuResponse(_mainwindow, elapsed);
		switch (result)
		{
			case MainMenu::Exit:
				_gamestate = Game::Exiting;
				return;
			case MainMenu::Play:
				_gamestate = Game::Playing;
				return;
			case MainMenu::Play2P:
				_gamestate = Game::Playing2P;
				return;
			case MainMenu::Nothing:
				_gamestate = Game::ShowingMenu;
				break;
		}
	}
}

Game::GameState Game::_gamestate = Uninitialized;
sf::RenderWindow Game::_mainwindow;
Toucan Game::_toucan;
Jeremified Game::_jeremified;
Score Game::_score;
sf::Sprite Game::_background;
sf::View Game::_view1P;
sf::View Game::_view2P;
sf::View Game::_GUI;
//MainMenu Game::_mainmenu;
sf::Clock Game::_clock;
bool Game::_toggleview;




