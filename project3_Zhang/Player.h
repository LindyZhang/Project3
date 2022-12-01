// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Player.h
// Partner: Dylan Teeples
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Companion.h"
using namespace std;

class Player
{
    private:
        string player_name_;
        float health_;
        bool alive_;
        Companion members_[4];
    public:
        Player();
        Player(string player_name, float health, bool alive);
        // getters
        string getPlayerName();
        float getHealth();
        bool getPlayerAlive();
        // setters
        void setPlayerName(string player_name);
        void setHealth(float health);
        void setPlayerAlive(bool alive);
        //void assignMembers()
};
#endif