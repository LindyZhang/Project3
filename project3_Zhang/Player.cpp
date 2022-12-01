// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Player.cpp
// Partner: Dylan Teeples
#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;

Player::Player(){
    player_name_ = "";
    health_ = 50.0;
    alive_ = true;
}
Player::Player(string player_name, float health, bool alive){
    player_name_ = player_name;
    health_ = health;
    alive_ = alive;
}
// getters
string Player::getPlayerName(){
    return player_name_;
}
float Player::getHealth(){
    return health_;
}
bool Player::getPlayerAlive(){
    return alive_;
}
// setters
void Player::setPlayerName(string player_name){
    player_name_ = player_name;
}
void Player::setHealth(float health){
    health_ = health;
}
void Player::setPlayerAlive(bool alive){
    alive_ = alive;
}
//void assignMembers()
/**
 * take input from the user and create Companion objects to put into the members_ array
 * store an array of size 4 containing the Players' companions
 */