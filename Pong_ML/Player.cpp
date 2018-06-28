//
//  Player.cpp
//  Pong_ML
//
//  Created by Teodor Stanishev on 4/29/18.
//  Copyright © 2018 Teodor Stanishev. All rights reserved.
//
#ifndef PLAYER
#define PLAYER

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>

using namespace std;
using namespace sf;

extern RenderWindow window;

class Player{
protected:
    Vector2f position;
    Color color=Color::Red;
    Vector2f size;
    void movement(){
        if(Keyboard::isKeyPressed(Keyboard::W))
            rect.move(0,-speed);
        else if (Keyboard::isKeyPressed(Keyboard::S))
            rect.move(0,speed);
    }
public:
    float speed=15.0f;
    RectangleShape rect;

    Player();
    Player(Vector2f position,Vector2f size){
        this->size=size;
        this->position=position;
        rect.setSize(size);
        rect.setPosition(position);
        rect.setFillColor(color);
    }
    Player(Vector2f position,Vector2f size,float speed){
        this->size=size;
        this->position=position;
        rect.setSize(size);
        rect.setPosition(position);
        rect.setFillColor(color);
        this->speed=speed;
    }
    Player(Vector2f position,Vector2f size,float speed,Color color){
        this->position=position;
        this->size=size;
        rect.setSize(size);
        rect.setPosition(position);
        rect.setFillColor(color);
        this->speed=speed;
    }
    
    void update(){
        movement();
        restrictMovement();
        window.draw(rect);
    }
    
    void restrictMovement(){
        if(getPosition().y>window.getSize().y-getSize().y){
            rect.move(0, -speed);
        }
        else if(getPosition().y<0){
            rect.move(0, speed);
        }
    }
    
    Vector2f getPosition(){
        return rect.getPosition();
    }
    Vector2f getSize(){
        return rect.getSize();
    }
};



#endif
