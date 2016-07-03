//
//  Jeremified.cpp
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/25/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include "Jeremified.h"
#include "RocanTucatePrefix.pch"
#include <cassert>
#include "game.h"
#include "ResourcePath.hpp"


#include <cmath>

Jeremified::Jeremified():
 _rotation(90.0),
 _velocity(500.0),
 _angle(70.0)
{
    Load (resourcePath() + "jeremified.png");
    //assert (IsLoaded());
    
    GetSprite().setOrigin(48.0, 34.0);
    GetSprite().setScale(2.0, 2.0);
};

Jeremified::~Jeremified()
{
}

void Jeremified::Draw(sf::RenderWindow &rw)
{
    VisibleGameObject::Draw(rw);
}

void Jeremified::Rotate(float elapsedtime)
{
    VisibleGameObject::Rotate(_rotation*elapsedtime);
}

void Jeremified::Update(float elapsedTime)
{
    //_elapsedTimeSinceStart += elapsedTime;                //this is not right, where is elapsedTime?
    float moveAmount = _velocity * elapsedTime;                           // * elapsedTime
    
    float moveByX = LinearVelocityX(_angle) * moveAmount;
    float moveByY = LinearVelocityY(_angle) * moveAmount;
    
    //collision with left side
    if (GetPosition().x + moveByX <= 0.0 + GetWidth()/2.0
        || GetPosition().x + GetHeight()/2.0 + moveByY >= 1024.0)       //1024 is screen width
    {
        //ricochet by Valve
        _angle = 360.0 - _angle;
        //if(_angle > 260.0f && _angle < 280.0f) _angle += 20.0f;     //optional "bouncy" code
        //if(_angle > 80.0f && _angle < 100.0f) _angle += 20.0f;      //optional "bouncy" code
        moveByX = -moveByX;
    }
    if(GetPosition().y - GetHeight()/2 <= 0.0
       || GetPosition().y + GetHeight()/2 >= 768)                   //this is still a little wonky
    {
        _angle = 180.0 - _angle;
        moveByY = -moveByY;
    }
    GetSprite().move(moveByX,moveByY);
}

float Jeremified::LinearVelocityX(float angle)
{
    angle -= 90.0;
    if (angle < 0.0) {angle = 360.0 + angle;};
    return (float)std::cos( angle * ( 3.1415926 / 180.0f ));
}

float Jeremified::LinearVelocityY(float angle)
{
    angle -= 90.0;
    if (angle < 0.0) {angle = 360.0 + angle;};
    return (float)std::sin( angle * ( 3.1415926 / 180.0f ));
}





