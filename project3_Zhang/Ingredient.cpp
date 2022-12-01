// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Item.cpp
#include <iostream>
#include "Ingredient.h"
using namespace std;

Ingredient::Ingredient(){
    ingredient_cost_ = 0;
}
Ingredient::Ingredient(int ingredient_cost){
    ingredient_cost_ = ingredient_cost;
}
int Ingredient::getCost(){
    return ingredient_cost_;
}
void Ingredient::setCost(int ingredient_cost){
    ingredient_cost_ = ingredient_cost;
}