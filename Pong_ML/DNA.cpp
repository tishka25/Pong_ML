//
//  DNA.cpp
//  Pong_ML
//
//  Created by Teodor Stanishev on 4/29/18.
//  Copyright © 2018 Teodor Stanishev. All rights reserved.
//
#ifndef DNA
#define DNA


#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
using namespace std;
using namespace sf;


#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4

class DNA_Class{
public:
    int num;
    vector<int>genes;
    int fitness;
    DNA_Class(int num){
        this->num=num;
        for(int i=0;i<num;i++){
            genes.push_back(rand()%4+1);
        }
    }
    DNA_Class(vector<vector<int>> child){
        genes.push_back(child);
    }
    int crossOver(vector<int>partner){
        vector<int>child;
        int crossover=rand()%genes.size();
        for(int i=0;i<genes.size();i++){
            if(i>crossover){
                child.push_back(genes[i]);
            }
            else{
                child.push_back(partner[i]);
            }
        }
        vector<int>newgenes=DNA_Class(child);
    }
    
    
};
#endif
