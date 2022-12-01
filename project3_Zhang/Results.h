// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Results.h
// Partner: Dylan Teeples
#ifndef RESULTS_H
#define RESULTS_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Results{
    private:
        string names_;
        string file_name_;
    public:
        Results();
        Results(string names, string file_name);
        string createNames(Companion c1, Companion c2, Companion c3, Companion c4, Player p);
        void writeResults(string file_name, int rooms, int gold, int ring, int bracelet, int necklace, int circlet, int goblet, int spaces, int monsters, int turns, Companion c1, Companion c2, Companion c3, Companion c4, Player p);
        void readResults(string file_name, int rooms, int gold, int ring, int bracelet, int necklace, int circlet, int goblet, int spaces, int monsters, int turns, Companion c1, Companion c2, Companion c3, Companion c4, Player p);
};
#endif