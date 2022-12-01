// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Companion.cpp
// Partner: Dylan Teeples
#include <iostream>
#include <vector>
#include <string>
#include "Companion.h"
using namespace std;

Companion::Companion(){
    health_ = 50;
    name_ = "";
    alive_ = true;
}
Companion::Companion(int health, string name, bool alive){
    health_ = health;
    name_ = name;
    alive_ = alive;
}
// getters
int Companion::getHealth(){
    return health_;
}
string Companion::getName(){
    return name_;
}
bool Companion::getAlive(){
    return alive_;
}
// setters
void Companion::setHealth(int health){
    health_ = health;
}
void Companion::setName(string name){
    name_ = name;
}
void Companion::setAlive(bool alive){
    alive_ = alive;
}