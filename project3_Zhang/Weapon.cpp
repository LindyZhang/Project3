// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Weapon.cpp
// Partner: Dylan Teeples
#include <iostream>
#include "Weapon.h"
using namespace std;

Weapon::Weapon(){
    weaponName_ = ' ';
    rooms_ = 0;
}
Weapon::Weapon(char weaponName, int rooms){
    weaponName_ = weaponName;
    rooms_ = rooms;
}
// getters
char Weapon::getWeaponName(){
    return weaponName_;
}
int Weapon::getRooms(){
    return rooms_;
}
// setters
void Weapon::setWeaponName(char weaponName){
    weaponName_ = weaponName;
}
void Weapon::setRooms(int rooms){
    rooms_ = rooms;
}
int Weapon::newCost(char weaponName, int rooms){
    int cost = 0;
    if (weaponName == 'C'){
        cost = 2;
    }
    else if (weaponName == 'S'){
        cost = 2;
    }
    else if (weaponName == 'R'){
        cost = 5;
    }
    else if (weaponName == 'B'){
        cost = 15;
    }
    else if (weaponName == 'L'){
        cost = 50;
    }
    int add = (1+0.25*rooms) * cost;
    return add;
}
