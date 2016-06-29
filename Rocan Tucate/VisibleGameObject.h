//
//  VisibleGameObject.h
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/20/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class VisibleGameObject
{
public:
    VisibleGameObject();
    virtual ~VisibleGameObject();
    
    virtual void Load(std::string filename);
    virtual void Draw (sf::RenderWindow & window);
    virtual void Update (float elapsedTime);
    
    virtual void Rotate (float rotationAngle);
    
    virtual void SetPosition (float x, float y);
    virtual void SetScale (float FactorX, float FactorY);
    virtual sf::Vector2f GetPosition() const;
    virtual bool IsLoaded() const;
    
    virtual sf::Rect<float> GetBoundingRect() const;
    virtual float GetWidth() const;
    virtual float GetHeight() const;
    
protected:
    sf::Sprite& GetSprite();
    
private:
    sf::Sprite _sprite;
    sf::Texture _image;
    std::string _filename;
    bool _isloaded;
};
