// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Item.h
#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ingredient{
    private:
        int ingredient_cost_;
    public:
        Ingredient();
        Ingredient(int ingredient_cost);
        int getCost();
        void setCost(int ingredient_cost);
};
#endif