//
//  Toucan.h
//  Rocan Tucate
//
//  Created by Noah Kittleson on 10/21/14.
//  Copyright (c) 2014 Noah. All rights reserved.
//

#pragma once

#include "VisibleGameObject.h"

class Toucan : public VisibleGameObject
{
public:
    Toucan();
    ~Toucan();
    
    //void Load (std::string Filename);
    void Update(float ElapsedTime);
    void Draw(sf::RenderWindow& rw);
    
    float GetRotation() const;
    void Rotate(float elapsedTime);
    
private:
    float _rotation;

};
