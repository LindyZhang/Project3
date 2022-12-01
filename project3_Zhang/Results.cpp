// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - Companion.cpp
// Partner: Dylan Teeples
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Companion.h"
#include "Player.h"
#include "Results.h"
using namespace std;

// SORTING ALGORITHM (used to rank health and return the highest health)
void bubbleSortMVP(int arr[], int n, Companion c1, Companion c2, Companion c3, Companion c4, Player p){
    int temp = -1;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int k = 0; k < n; k++){
        cout << arr[k] << " ";
    }
    cout << endl;
    if(p.getHealth() == arr[n]){
        cout << p.getPlayerName() << " is the MVP with the highest health!" << endl;
    }
    if(c1.getHealth() == arr[n]){
        cout << c1.getName() << " is the MVP with the highest health!" << endl;
    }
    if(c2.getHealth() == arr[n]){
        cout << c2.getName() << " is the MVP with the highest health!" << endl;
    }
    if(c3.getHealth() == arr[n]){
        cout << c3.getName() << " is the MVP with the highest health!" << endl;
    }
    if(c4.getHealth() == arr[n]){
        cout << c4.getName() << " is the MVP with the highest health!" << endl;
    }
}

Results::Results(){
    names_ = "";
    file_name_ = "";
}
Results::Results(string names, string file_name){
    names_ = names;
    file_name_ = file_name;
}
string Results::createNames(Companion c1, Companion c2, Companion c3, Companion c4, Player p){
    if (c1.getAlive()){
        names_ += c1.getName();
        names_ += " ";
    }
    if (c2.getAlive()){
        names_ += c2.getName();
        names_ += " ";
    }
    if (c3.getAlive()){
        names_ += c3.getName();
        names_ += " ";
    }
    if (c4.getAlive()){
        names_ += c4.getName();
        names_ += " ";
    }
    return names_;
}
void Results::writeResults(string file_name, int rooms, int gold, int ring, int bracelet, int necklace, int circlet, int goblet, int spaces, int monsters, int turns, Companion c1, Companion c2, Companion c3, Companion c4, Player p){
    Results r;
    ofstream file;
    file.open("results.txt");
    file << "Game Results: \nAlive Players: " << p.getPlayerName() << " " << r.createNames(c1, c2, c3, c4, p) << "\nRooms Cleared: " << rooms << "\nGold Remaining: " << gold << "\n Rings: " << ring << " Necklaces: " << necklace << " Bracelets: " << bracelet << " Circlet: " << circlet << " Goblets: " << goblet << "\n Spaces explored: " << spaces << "\nMonsters Defeated: " << monsters << "\nTurns Taken: " << turns << endl;
    file.close();
}
void Results::readResults(string file_name, int rooms, int gold, int ring, int bracelet, int necklace, int circlet, int goblet, int spaces, int monsters, int turns, Companion c1, Companion c2, Companion c3, Companion c4, Player p){
    Results r;
    int arr[5] = {c1.getHealth(), c2.getHealth(), c3.getHealth(), c4.getHealth(), p.getHealth()};
    cout << "Game Results: \nAlive Players: " << p.getPlayerName() << " " << r.createNames(c1, c2, c3, c4, p) << "\nRooms Cleared: " << rooms << "\nGold Remaining: " << gold << "\n Rings: " << ring << " Necklaces: " << necklace << " Bracelets: " << bracelet << " Circlet: " << circlet << " Goblets: " << goblet << "\n Spaces explored: " << spaces << "\nMonsters Defeated: " << monsters << "\nTurns Taken: " << turns << endl;
    bubbleSortMVP(arr, 5, c1, c2, c3, c4, p);
}
