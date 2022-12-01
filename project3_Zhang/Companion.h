// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Companion.h
// Partner: Dylan Teeples
#ifndef COMPANION_H
#define COMPANION_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Companion{
    private:
        int health_;
        string name_;
        bool alive_;
    public:
        Companion();
        Companion(int health, string name, bool alive);
        // getters
        int getHealth();
        string getName();
        bool getAlive();
        // setters
        void setHealth(int health);
        void setName(string name);
        void setAlive(bool alive);
};
#endif