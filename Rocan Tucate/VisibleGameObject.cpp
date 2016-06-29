//
//  VisibleGameObject.cpp
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/20/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#include "VisibleGameObject.h"
#include <RocanTucatePrefix.pch>

VisibleGameObject::VisibleGameObject()
: _isloaded (false)
{
}

VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load(std::string filename)
{
    if (_image.loadFromFile(filename) == false)
    {
        _filename = "";
        _isloaded = false;
    }
    else
    {
        _filename = filename;
        _sprite.setTexture(_image);
        _isloaded = true;
    }
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
    if (_isloaded)
    {
        renderWindow.draw(_sprite);
    }
}

void VisibleGameObject::SetPosition(float x, float y)
{
    if (_isloaded) {
        _sprite.setPosition(x, y);
    }
}

void VisibleGameObject::Update(float elapsedTime)
{
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
    if (_isloaded)
    {
        return _sprite.getPosition();
    }
    return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::GetSprite()
{
    return _sprite;
}

bool VisibleGameObject::IsLoaded() const
{
    return _isloaded;
}


void VisibleGameObject::Rotate(float rotationAngle)
{
    _sprite.rotate(rotationAngle);
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const
{
    sf::Vector2u size = _image.getSize();
    sf::Vector2f position = _sprite.getPosition();
    
    return sf::Rect<float>(
        position.x - static_cast<float>(size.x/2),
        position.y - static_cast<float>(size.y/2),
        position.x + static_cast<float>(size.x/2),
        position.y + static_cast<float>(size.y/2)
    );
    
}

float VisibleGameObject::GetWidth() const
{
    return _image.getSize().y;
}
float VisibleGameObject::GetHeight() const
{
    return _image.getSize().x;
}

void VisibleGameObject::SetScale(float FactorX, float FactorY)
{
    _sprite.setScale(FactorX, FactorY);
}




