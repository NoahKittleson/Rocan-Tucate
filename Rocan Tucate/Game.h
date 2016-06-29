//
//  Game.h
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/19/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Toucan.h"
#include "Jeremified.h"
#include "Score.h"
#include "MainMenu.h"



class Game
{
    
public:
    static void Start();

private:
    static bool IsExiting();
    static void GameLoop(float elapsed);
    
    static void ShowSplashScreen();
    static void ShowMenu();
    
    enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting, Playing2P };

    static GameState _gamestate;
    static sf::RenderWindow _mainwindow;
    static Toucan _toucan;
    static Jeremified _jeremified;
    static Score _score;
    static sf::Sprite _background;
    static sf::View _view1P;
    static sf::View _view2P;
    static sf::View _GUI;
    //static MainMenu _mainmenu;
    static bool _toggleview;

    static sf::Clock _clock;
};
