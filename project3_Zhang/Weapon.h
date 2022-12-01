// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Weapon.h
// Partner: Dylan Teeples
#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Weapon{
    private:
        char weaponName_;
        int rooms_;
    public:
        Weapon();
        Weapon(char weaponName, int rooms);
        // getters
        char getWeaponName();
        int getRooms();
        // setters
        void setWeaponName(char weaponName);
        void setRooms(int rooms);
        // other
        int newCost(char weaponName, int rooms);
};
#endif