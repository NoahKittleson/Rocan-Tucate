//
//  Toucan.cpp
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/21/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include "RocanTucatePrefix.pch"
#include "Toucan.h"
#include "ResourcePath.hpp"
//#include "Game.h"


Toucan::Toucan()
 : _rotation (360.0)
{
    Load(resourcePath() + "ROCAN.png");
    //assert(IsLoaded());
    
    GetSprite().setOrigin(63.0,47.0);
    GetSprite().setScale(2.0, 2.0);
}

Toucan::~Toucan()
{
}

void Toucan::Draw(sf::RenderWindow &rw)
{
    VisibleGameObject::Draw(rw);
}

float Toucan::GetRotation() const
{
    return _rotation;
}

void Toucan::Update(float ElapsedTime)          //useless and unused
{
    _rotation += 40.0 * ElapsedTime;
    if (_rotation >= 360.0)
    {
        _rotation -= 360.0;
    }
    
}

void Toucan::Rotate(float elapsedTime)
{
    VisibleGameObject::Rotate(_rotation*elapsedTime);
}






