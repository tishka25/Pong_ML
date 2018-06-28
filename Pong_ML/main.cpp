//
//  main.cpp
//  Pong_ML
//
//  Created by Teodor Stanishev on 4/29/18.
//  Copyright © 2018 Teodor Stanishev. All rights reserved.
//


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include "Player.cpp"
#include "Enemy.cpp"

using namespace std;
using namespace sf;

static float WIDTH=800;
static float HEIGHT=600;
sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong AI");
Player player(Vector2f(0 , HEIGHT/2) , Vector2f(10,100) , 10 , Color::Blue);
Enemy enemy(Vector2f(WIDTH-10 , HEIGHT/2),Vector2f(10,100) ,10, Color::Green);
CircleShape ball;

Vector2f ballMove;
vector<FloatRect>collisionPoints;



void ballUpdate(){
    if(ball.getPosition().y>HEIGHT || ball.getPosition().y<0)
        ballMove.y=-ballMove.y;
    window.draw(ball);
}


static void setup(){
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
    ballMove.x=2;
    ballMove.y=2;
    ball.setRadius(10);
    ball.setPosition(WIDTH/2, HEIGHT/2);
}



static void loop(){
    ball.move(ballMove);
    enemy.update();
    player.update();
    
    collisionPoints.push_back(FloatRect (player.getPosition().x,player.getPosition().y,player.getSize().x,player.getSize().y));
    collisionPoints.push_back(FloatRect(enemy.getPosition().x,enemy.getPosition().y,enemy.getSize().x,enemy.getSize().y));
    
    for(auto collision : collisionPoints){
        if(collision.contains(ball.getPosition().x+10,ball.getPosition().y) || collision.contains(ball.getPosition().x+ball.getRadius(),ball.getPosition().y))
            ballMove.x=-ballMove.x;
    }
    
    collisionPoints.clear();
    ballUpdate();
}




int main(int, char const**)
{
    setup();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        loop();

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
