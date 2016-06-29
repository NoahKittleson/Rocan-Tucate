//
//  Jeremified.h
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/25/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#pragma once
#include "VisibleGameObject.h"

class Jeremified :
 public VisibleGameObject

{
public:
    Jeremified();
    virtual ~Jeremified();
    void Update(float);
    
    void Draw(sf::RenderWindow& rw);
    void Rotate(float elapsedTime);
    
private:
    float _rotation;
    float _velocity;
    float _angle;
    
    float LinearVelocityX(float angle);
    float LinearVelocityY(float angle);
};
