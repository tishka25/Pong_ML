//
//  Enemy.cpp
//  Pong_ML
//
//  Created by Teodor Stanishev on 4/29/18.
//  Copyright © 2018 Teodor Stanishev. All rights reserved.
//
#ifndef ENEMY
#define ENEMY

#include "Player.cpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class Enemy:  public Player{
protected:
    void movement(){
        if(sf::Keyboard::isKeyPressed(Keyboard::Up)){
            rect.move(0,-speed);
        }
        else if(sf::Keyboard::isKeyPressed(Keyboard::Down)){
            rect.move(0,speed);
        }
    }
public:
    
    Enemy(sf::Vector2f position,Vector2f size):Player(position,size){
    }
    Enemy(sf::Vector2f position,Vector2f size,float speed,Color color):Player(position,size,speed,color){
    }
    
    void update(){
        movement();
        Player : restrictMovement();
        window.draw(rect);
    }
    
};
#endif
