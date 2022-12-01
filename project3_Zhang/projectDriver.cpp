// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - classDriver.cpp
// Partner: Dylan Teeples
#include <iostream>
#include "Map.h"
#include "Companion.h"
#include "Player.h"
#include "Ingredient.h"
#include "Weapon.h"
#include "Results.h"
#include <fstream>
using namespace std;

int split(string input_string, char separator, string arr[], int arr_size){
    int count = 0;
    int start = 0;
    if (input_string == ""){
        return count;
    }
    else{
        for (int i = 0; i < input_string.length(); i++){
            if (input_string[i] == separator){
                arr[count] = input_string.substr(start, i - start);
                start = i + 1;
                count++;
                if (count == arr_size){
                    return -1;
                }
            }
        }
    }
    arr[count] = input_string.substr(start, input_string.length() - start);
    if (count + 1 > arr_size){
        return -1;
    }
    else{
        return count + 1;
    }
}

int main(){
    srand(time(NULL));
    int anger = 0;
    int gold = 100;
    int ingredients = 0;
    // generating the map of dimensions 12x12
    Map map;
    // randomMap was added to the Map class implementation
    map.randomMap();
    map.displayMap();
    Results r;
    Player p;
    Companion c1;
    Companion c2;
    Companion c3;
    Companion c4;
    string player_name;
    string comp1_name;
    string comp2_name;
    string comp3_name;
    string comp4_name;
    cout << "What is your name?" << endl;
    cin >> player_name;
    p.setPlayerName(player_name);
    cout << "What is the name of your first companion?" << endl;
    cin >> comp1_name;
    c1.setName(comp1_name);
    cout << "What is the name of your second companion?" << endl;
    cin >> comp2_name;
    c2.setName(comp2_name);
    cout << "What is the name of your third companion?" << endl;
    cin >> comp3_name;
    c3.setName(comp3_name);
    cout << "What is the name of your fourth companion?" << endl;
    cin >> comp4_name;
    c4.setName(comp4_name);

    // visiting the merchant
    int merchant_choice = -1;
    int pot = 0;
    int pan = 0;
    int cauldron = 0;
    int club = 0;
    int spear = 0;
    int rapier = 0;
    int axe = 0;
    int longsword = 0;
    int armor = 0;
    int ring = 0;
    int necklace = 0;
    int bracelet = 0;
    int circlet = 0;
    int goblet = 0;
    int amount = -1;
    char ans = ' ';
    int weapon_choice = -1;
    int num = -1;
    int cookware_choice = -1;
    int rooms = 0;
    int keys = 0;
    int action_choice = -1;
    char direction_choice = ' ';
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int spaces = 0;
    int turns = 0;
    int num_monsters = 0;
    int cooking = 0;
    char cookware = ' ';
    int p_health = 0;
    int c1_health = 0;
    int c2_health = 0;
    int c3_health = 0;
    int c4_health = 0;
    int m1 = 0;
    int m2 = 0;
    int m3 = 0;
    int m4 = 0;
    int m5 = 0;
    int fight_choice = 0;
    int lost_c = 0;
    string line = "";
    string arr[2];
    vector <string> lvl1;
    vector <string> lvl2;
    vector <string> lvl3;
    vector <string> lvl4;
    vector <string> lvl5;
    int num_w = 0;
    int num_a = 0;
    int num_c = 0;
    int num_r1 = 0;
    int num_r2 = 0;
    int num_d = 0;
    int fight_score = 0;
    ifstream myFile;
    int NPC_choice = 0;
    ifstream riddle;
    vector <string> riddles;
    vector <string> answers;
    string answer = "";
    int room_choice = 0;
    char rps_choice = ' ';
    char door_choice = ' ';

    cout << "Between the 5 of you, you have 100 gold pieces.\nYou will need to spend the some of your money on the following items:\n- INGREDIENTS. To make food, you have to cook raw ingredients.\n- COOKWARE. If you want to cook, you have to have cookware first.\n- WEAPONS. You'll want at least one weapon per party member to fend off monsters.\n- ARMOR. Armor increases the chances of surviving a monster attack.\nYou can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl;
    cout << "If you're looking to get supplies, you've come to the right place.\nI would be happy to part with some of my wares...for the proper price!\n+-------------+\n| INVENTORY   |\n+-------------+\n| Gold        | "<< gold << "\n| Ingredients | "<< ingredients <<" kg\n| Cookware    | P: " << pot << " | F: " << pan << " | C: " << cauldron << "\n| Weapons     | C: " << club << " | S: " << spear << " | R: " << rapier << " | B: " << axe << " | L: " << longsword << "\n| Armor       | " << armor << "\n| Treasures   | R: " << ring << " | N: " << necklace << " | B: " << bracelet << " | C: " << circlet << " | G: " << goblet << "\nChoose one of the following:\n 1. Ingredients: To make food, you have to cook raw ingredients.\n 2. Cookware: You will need something to cook those ingredients.\n 3. Weapons: It's dangerous to go alone, take this!\n 4. Armor: If you want to survive monster attacks, you will need some armor.\n 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.\n 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
    cin >> merchant_choice;
    while (merchant_choice != 6){
        switch(merchant_choice){
        case 1:
            cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
            cin >> amount;
            cout << "You want to buy " << amount << " kg of ingredients for " << amount << " Gold? (y/n)" << endl;
            cin >> ans;
            if (amount == 0){
                break;
            }
            else if (ans == 'y' && gold >= amount){
                ingredients += amount;
                gold -= amount;
            }
            else if (gold <= amount){
                cout << "You do not have enough gold." << endl;
                break;
            }
            cout << "Thank you for your patronage! What else can I get for you?" << endl;
            break;
        case 2:
            cout << "I have a several types of cookware, which one would you like?\nEach type has a different probability of breaking when used, marked with (XX%).\nChoose one of the following:\n 1. (25%) Ceramic Pot [2 Gold]\n 2. (10%) Frying Pan [10 Gold] \n3. ( 2%) Cauldron [20 Gold]\n 4. Cancel" << endl;
            cin >> cookware_choice;
            if (cookware_choice == 4){
                break;
            }
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> num;
            if (num == 0){
                break;
            }
            switch(cookware_choice){
                case 1:
                    cout << "You want to buy " << num << "Ceramic Pot(s) for " << 2*num << " Gold? (y/n)" << endl;
                    cin >> ans;
                    if (ans == 'y'&& gold >= 2*num){
                        pot += num;
                        gold -= 2*num;
                    }
                    else if (gold <= 2*num){
                        cout << "You do not have enough gold." << endl;
                        break;
                    }
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    break;
                case 2:
                    cout << "You want to buy " << num << "Frying Pan(s) for " << 10*num << " Gold? (y/n)" << endl;
                    cin >> ans;
                    if (ans == 'y' && gold >= 10*num){
                        pan += num;
                        gold -= 10*num;
                    }
                    else if (gold <= 10*num){
                        cout << "You do not have enough gold." << endl;
                        break;
                    }
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    break;
                case 3:
                    cout << "You want to buy " << num << "Cauldron(s) for " << 20*num << " Gold? (y/n)" << endl;
                    cin >> ans;
                    if (ans == 'y' && gold >= 20*num){
                        cauldron += num;
                        gold -= 20*num;
                    }
                    else if (gold <= 20*num){
                        cout << "You do not have enough gold." << endl;
                        break;
                    }
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    break;
                default:
                    cout << "Please enter a valid input." << endl;
            }
            break;
        case 3:
            cout << "I have a plentiful collection of weapons to choose from, what would you like?\nNote that some of them provide you a special bonus in combat, marked by a (+X).\nChoose one of the following:\n1. Stone Club [2 Gold]\n 2. Iron Spear [2 Gold]\n 3. (+1) Mythril Rapier [5 Gold]\n 4. (+2) Flaming Battle-Axe [15 Gold]\n 5. (+3) Vorpal Longsword [50 Gold]\n 6. Cancel" << endl;
            cin >> weapon_choice;
            if (weapon_choice == 6){
                break;
            }
            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> num;
            if (num == 0){
                break;
            }
            switch (weapon_choice){
                case 1:
                    cout << "You want to buy " << num << " Stone Club(s) for " << 2*num << " Gold? (y/n)" << endl;
                    cin >> ans;
                    if (ans == 'y' && gold >= 2*num){
                        club += num;
                        gold -= 2*num;
                    }
                    else if (gold <= 2*num){
                        cout << "You do not have enough gold." << endl;
                        break;
                    }
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    break;
                case 2:
                    cout << "You want to buy " << num << " Iron Spear(s) for " << 2*num << " Gold? (y/n)" << endl;
                    cin >> ans;
                    if (ans == 'y' && gold >= 2*num){
                        spear += num;
                        gold -= 2*num;
                    }
                    else if (gold <= 2*num){
                        cout << "You do not have enough gold." << endl;
                        break;
                    }
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    break;
                case 3:
                    cout << "You want to buy " << num << "(+1) Mythril Rapier(s) for " << 5*num << " Gold? (y/n)" << endl;
                    cin >> ans;
                    if (ans == 'y' && gold >= 5*num){
                        rapier += num;
                        gold -= 5*num;
                    }
                    else if (gold <= 5*num){
                        cout << "You do not have enough gold." << endl;
                        break;
                    }
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    break;
                case 4:
                    cout << "You want to buy " << num << "(+2) Flaming Battle-Axe(s) for " << 15*num << " Gold? (y/n)" << endl;
                    cin >> ans;
                    if (ans == 'y' && gold >= 15*num){
                        axe += num;
                        gold -= 15*num;
                    }
                    else if (gold <= 15*num){
                        cout << "You do not have enough gold." << endl;
                        break;
                    }
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    break;
                case 5:
                    cout << "You want to buy " << num << " (+3) Vorpal Longsword(s) for " << 50*num << " Gold? (y/n)" << endl;
                    cin >> ans;
                    if (ans == 'y' && gold >= 50*num){
                        longsword += num;
                        gold -= 50*num;
                    }
                    else if (gold <= 50*num){
                        cout << "You do not have enough gold." << endl;
                        break;
                    }
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    break;
                default:
                    cout << "Please enter a valid input." << endl;
            }
            break;
        case 4:
            cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> num;
            if (num == 0){
                break;
            }
            cout << "You want to buy " << num << " suit(s) of armor for " << 5*num << " Gold? (y/n)" << endl;
            cin >> ans;
            if (ans == 'y' && gold >= 5*num){
                armor += num;
                gold -= 5*num;
            }
            else if (gold <= 5*num){
                cout << "You do not have enough gold." << endl;
                break;
            }
            cout << "Thank you for your patronage! What else can I get for you?" << endl;
            break;
        case 5:
            break;
        default:
            cout << "Please enter a valid input." << endl;
        }
        cout << "+-------------+\n| INVENTORY   |\n+-------------+\n| Gold        | "<< gold << "\n| Ingredients | "<< ingredients <<" kg\n| Cookware    | P: " << pot << " | F: " << pan << " | C: " << cauldron << "\n| Weapons     | C: " << club << " | S: " << spear << " | R: " << rapier << " | B: " << axe << " | L: " << longsword << "\n| Armor       | " << armor << "\n| Treasures   | R: " << ring << " | N: " << necklace << " | B: " << bracelet << " | C: " << circlet << " | G: " << goblet << "\nChoose one of the following:\n 1. Ingredients: To make food, you have to cook raw ingredients.\n 2. Cookware: You will need something to cook those ingredients.\n 3. Weapons: It's dangerous to go alone, take this!\n 4. Armor: If you want to survive monster attacks, you will need some armor.\n 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.\n 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cin >> merchant_choice;
    }
    if (merchant_choice == 6){
        cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
        cin >> ans;
        if (ans == 'y'){
            cout << "Stay safe out there! Goodbye!" << endl;
        }
    }
    map.setPlayerPosition(1, 12);
    while (p.getPlayerAlive()== true && rooms < 5){
        cout << "+-------------+\n| STATUS      |\n+-------------+\n| Rooms Cleared: " << rooms << " | Keys: " << keys << " | Anger Level: " << anger << "\n+-------------+\n| INVENTORY   |\n+-------------+\n| Gold        | " << gold << "\n| Ingredients | " << ingredients << " kg\n| Cookware    | P: " << pot << " | F: " << pan << " | C: " << cauldron << "\n| Weapons     | C: " << club << " | S: " << spear << " | R: " << rapier << " | B: " << axe << " | L: " << longsword << "\n| Armor       | " << armor << "\n| Treasures   | R: " << ring << " | N: " << necklace << " | B: " << bracelet << " | C: " << circlet << " | G: " << goblet << "\n+-------------+\n| PARTY       |\n+-------------+\n| " << player_name << " | Fullness: " << p.getHealth() << "\n| " << comp1_name << " | Fullness: "<< c1.getHealth() << "\n| " << comp2_name << " | Fullness: "<< c2.getHealth() << "\n| " << comp3_name << " | Fullness: "<< c3.getHealth() << "\n| " << comp4_name << " | Fullness: "<< c4.getHealth() << "\n+-------------+" << endl;
        map.displayMap();
        // action menu
        cout << "Select one:\n  1. Move\n  2. Investigate\n  3. Pick a Fight\n  4. Cook and Eat\n  5. Give up" << endl;
        cin >> action_choice;
        switch (action_choice){
            case 1:
                // Using w, s, a, d to choose where to move
                cout << "Where would you like to go? (w, a, s, d)" << endl;
                cin >> direction_choice;
                if (direction_choice == 'w' || direction_choice == 's' || direction_choice == 'a' || direction_choice == 'd'){
                    if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false){
                        anger++;
                    }
                    map.move(direction_choice);
                    a = rand()%100 + 1;
                    if (a <= 20){
                        p_health = p.getHealth();
                        p.setHealth(p_health - 1); 
                    }
                    b = rand()%100 + 1;
                    if (b <= 20){
                        c1_health = c1.getHealth();
                        p.setHealth(c1_health - 1); 
                    }
                    c = rand()%100 + 1;
                    if (c <= 20){
                        c2_health = c2.getHealth();
                        p.setHealth(c2_health - 1); 
                    }
                    d = rand()%100 + 1;
                    if (d <= 20){
                        c3_health = c3.getHealth();
                        p.setHealth(c3_health - 1); 
                    }
                    e = rand()%100 + 1;
                    if (e <= 20){
                        c4_health = c4.getHealth();
                        p.setHealth(c4_health - 1); 
                    }
                    if (anger >= 100){
                        cout << "The Sorcerer has destroyed your entire party." << endl;
                        r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                        r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                        return 0;
                    }
                    if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())){
                        cout << "You've entered a room, choose one of the following. 1. Move, 2. Open the Door, 3. Give up." << endl;
                        cin >> room_choice;
                        switch(room_choice){
                            case 1:
                                cout << "Where would you like to go? (w, a, s, d)" << endl;
                                cin >> direction_choice;
                                if (direction_choice == 'w' || direction_choice == 's' || direction_choice == 'a' || direction_choice == 'd'){
                                    if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false){
                                        anger++;
                                    }
                                    map.move(direction_choice);
                                    a = rand()%100 + 1;
                                    if (a <= 20){
                                        p_health = p.getHealth();
                                        p.setHealth(p_health - 1); 
                                    }
                                    b = rand()%100 + 1;
                                    if (b <= 20){
                                        c1_health = c1.getHealth();
                                        p.setHealth(c1_health - 1); 
                                    }
                                    c = rand()%100 + 1;
                                    if (c <= 20){
                                        c2_health = c2.getHealth();
                                        p.setHealth(c2_health - 1); 
                                    }
                                    d = rand()%100 + 1;
                                    if (d <= 20){
                                        c3_health = c3.getHealth();
                                        p.setHealth(c3_health - 1); 
                                    }
                                    e = rand()%100 + 1;
                                    if (e <= 20){
                                        c4_health = c4.getHealth();
                                        p.setHealth(c4_health - 1); 
                                    }
                                    if (anger >= 100){
                                        cout << "The Sorcerer has destroyed your entire party." << endl;
                                        r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                                        r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                                        return 0;
                                    }
                                break;
                            case 2:
                                if (keys > 0){
                                    myFile.open("monsters.txt");
                                    while(getline(myFile, line)){
                                        split(line, ',', arr, 2);
                                        if (stoi(arr[1]) == 1){
                                            lvl1.push_back(arr[0]);
                                        }
                                        if (stoi(arr[1]) == 2){
                                            lvl2.push_back(arr[0]);
                                        }
                                        if (stoi(arr[1]) == 3){
                                            lvl3.push_back(arr[0]);
                                        }
                                        if (stoi(arr[1]) == 4){
                                            lvl4.push_back(arr[0]);
                                        }
                                        if (stoi(arr[1]) == 5){
                                            lvl5.push_back(arr[0]);
                                        }
                                    }
                                    num_w = 5*(club + spear + rapier + axe + longsword + rapier) + (1*rapier) + (2*axe) + (3*longsword);
                                    num_a = armor;
                                    num_r1 = rand()%6 + 1;
                                    num_r2 = rand()%6 + 1;
                                    if (club >= 1 && spear >= 1 && rapier >= 1 && axe >= 1 && longsword >= 1){
                                        num_d = 4;      
                                    }
                                    switch(rooms){
                                        case 0:
                                            num_c = 2;
                                            m2 = rand()%3;
                                            cout << "Oh no! A " << lvl2[m2] << " is coming!" << endl;
                                            lvl2.erase(lvl2.begin() + m2);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                        case 1:
                                            num_c = 3;
                                            m3 = rand()%3;
                                            cout << "Oh no! A " << lvl3[m3] << " is coming!" << endl;
                                            lvl3.erase(lvl3.begin() + m3);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                        case 2:
                                            num_c = 4;
                                            m4 = rand()%3;
                                            cout << "Oh no! A " << lvl4[m4] << " is coming!" << endl;
                                            lvl4.erase(lvl4.begin() + m4);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                        case 3:
                                            num_c = 5;
                                            m5 = rand()%3;
                                            cout << "Oh no! A " << lvl5[m5] << " is coming!" << endl;
                                            lvl5.erase(lvl5.begin() + m5);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                        case 4:
                                            num_c = 5;
                                            m5 = rand()%3;
                                            cout << "Oh no! A " << lvl5[m5] << " is coming!" << endl;
                                            lvl5.erase(lvl5.begin() + m5);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                    }
                                    }
                                    num_monsters++;
                                    //rooms++;
                                }
                                else{
                                    cout << "You must now beat the door in a game of Rock, Paper, Scissors" << endl;
                                    cout << "Enter your move (r, p, s)" << endl;
                                    cin >> rps_choice;
                                    a = rand()%3 + 1;
                                    if (a == 1){
                                        door_choice = 'r';
                                    }
                                    if (a == 2){
                                        door_choice = 'p';
                                    }
                                    if (a == 3){
                                        door_choice = 's';
                                    }
                                    if (rps_choice == door_choice || (rps_choice == 's' && door_choice == 'r') || (rps_choice == 'r' && door_choice == 'p') || (rps_choice == 'p' && door_choice == 's')){
                                        cout << "You've lost! You now lose a party member." << endl;
                                        b = rand()%4 + 1;
                                        switch(b){
                                            case 1:
                                                c1.setHealth(0);
                                                c1.setAlive(false);
                                                break;
                                            case 2:
                                                c2.setHealth(0);
                                                c2.setAlive(false);
                                                break;
                                            case 3:
                                                c3.setHealth(0);
                                                c3.setAlive(false);
                                                break;
                                            case 4:
                                                c4.setHealth(0);
                                                c4.setAlive(false);
                                                break;
                                        }
                                    }
                                    else{
                                        cout << "You may now enter the room." << endl;
                                        myFile.open("monsters.txt");
                                        while(getline(myFile, line)){
                                            split(line, ',', arr, 2);
                                            if (stoi(arr[1]) == 1){
                                                lvl1.push_back(arr[0]);
                                            }
                                            if (stoi(arr[1]) == 2){
                                                lvl2.push_back(arr[0]);
                                            }
                                            if (stoi(arr[1]) == 3){
                                                lvl3.push_back(arr[0]);
                                            }
                                            if (stoi(arr[1]) == 4){
                                                lvl4.push_back(arr[0]);
                                            }
                                            if (stoi(arr[1]) == 5){
                                                lvl5.push_back(arr[0]);
                                            }
                                        }
                                        num_w = 5*(club + spear + rapier + axe + longsword + rapier) + (1*rapier) + (2*axe) + (3*longsword);
                                        num_a = armor;
                                        num_r1 = rand()%6 + 1;
                                        num_r2 = rand()%6 + 1;
                                        if (club >= 1 && spear >= 1 && rapier >= 1 && axe >= 1 && longsword >= 1){
                                            num_d = 4;      
                                        }
                                        switch(rooms){
                                            case 0:
                                                num_c = 2;
                                                m2 = rand()%3;
                                                cout << "Oh no! A " << lvl2[m2] << " is coming!" << endl;
                                                lvl2.erase(lvl2.begin() + m2);
                                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                                cin >> fight_choice;
                                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                    g = rand()%2 + 1;
                                                    if (g == 1){
                                                        p.setHealth(p.getHealth() - 1);
                                                    }
                                                    h = rand()%2 + 1;
                                                    if (h == 1){
                                                        c1.setHealth(c1.getHealth() - 1);
                                                    }
                                                    i = rand()%2 + 1;
                                                    if (i == 1){
                                                        c2.setHealth(c2.getHealth() - 1);
                                                    }
                                                    j = rand()%2 + 1;
                                                    if (j == 1){
                                                        c3.setHealth(c3.getHealth() - 1);
                                                    }
                                                    k = rand()%2 + 1;
                                                    if (k == 1){
                                                        c4.setHealth(c4.getHealth() - 1);
                                                    }
                                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                    if (fight_score > 0){
                                                        cout << "You win!" << endl;
                                                        gold += num_c*10;
                                                        ingredients += num_c*5;
                                                        a = rand()%10 + 1;
                                                        if (a == 1){
                                                            keys += 1;
                                                            cout << "You found a key!" << endl;
                                                        }
                                                    }
                                                    else{
                                                        cout << "You lose!" << endl;
                                                        gold = (gold*3)/4;
                                                        b = rand()%30 + 1;
                                                        ingredients -= b;
                                                        c = rand()%10 + 1;
                                                        if (c == 1){
                                                            c1.setAlive(false);
                                                            c1.setHealth(0);
                                                            cout << comp1_name << " has died." << endl;
                                                        }
                                                        d = rand()%10 + 1;
                                                        if (d == 1){
                                                            c2.setAlive(false);
                                                            c2.setHealth(0);
                                                            cout << comp2_name << " has died." << endl;
                                                        }
                                                        e = rand()%10 + 1;
                                                        if (e == 1){
                                                            c3.setAlive(false);
                                                            c3.setHealth(0);
                                                            cout << comp3_name << " has died." << endl;
                                                        }
                                                        f = rand()%10 + 1;
                                                        if (f == 1){
                                                            c4.setAlive(false);
                                                            c4.setHealth(0);
                                                            cout << comp4_name << " has died." << endl;
                                                        }
                                                    }
                                                }
                                                else{
                                                    lost_c = rand()%4 + 1;
                                                    switch(lost_c){
                                                        case 1:
                                                            c1.setHealth(0);
                                                            c1.setAlive(false);
                                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 2:
                                                            c2.setHealth(0);
                                                            c2.setAlive(false);
                                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 3:
                                                            c3.setHealth(0);
                                                            c3.setAlive(false);
                                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 4:
                                                            c4.setHealth(0);
                                                            c4.setAlive(false);
                                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                    }
                                                }
                                                break;
                                            case 1:
                                                num_c = 3;
                                                m3 = rand()%3;
                                                cout << "Oh no! A " << lvl3[m3] << " is coming!" << endl;
                                                lvl3.erase(lvl3.begin() + m3);
                                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                                cin >> fight_choice;
                                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                    g = rand()%2 + 1;
                                                    if (g == 1){
                                                        p.setHealth(p.getHealth() - 1);
                                                    }
                                                    h = rand()%2 + 1;
                                                    if (h == 1){
                                                        c1.setHealth(c1.getHealth() - 1);
                                                    }
                                                    i = rand()%2 + 1;
                                                    if (i == 1){
                                                        c2.setHealth(c2.getHealth() - 1);
                                                    }
                                                    j = rand()%2 + 1;
                                                    if (j == 1){
                                                        c3.setHealth(c3.getHealth() - 1);
                                                    }
                                                    k = rand()%2 + 1;
                                                    if (k == 1){
                                                        c4.setHealth(c4.getHealth() - 1);
                                                    }
                                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                    if (fight_score > 0){
                                                        cout << "You win!" << endl;
                                                        gold += num_c*10;
                                                        ingredients += num_c*5;
                                                        a = rand()%10 + 1;
                                                        if (a == 1){
                                                            keys += 1;
                                                            cout << "You found a key!" << endl;
                                                        }
                                                    }
                                                    else{
                                                        cout << "You lose!" << endl;
                                                        gold = (gold*3)/4;
                                                        b = rand()%30 + 1;
                                                        ingredients -= b;
                                                        c = rand()%10 + 1;
                                                        if (c == 1){
                                                            c1.setAlive(false);
                                                            c1.setHealth(0);
                                                            cout << comp1_name << " has died." << endl;
                                                        }
                                                        d = rand()%10 + 1;
                                                        if (d == 1){
                                                            c2.setAlive(false);
                                                            c2.setHealth(0);
                                                            cout << comp2_name << " has died." << endl;
                                                        }
                                                        e = rand()%10 + 1;
                                                        if (e == 1){
                                                            c3.setAlive(false);
                                                            c3.setHealth(0);
                                                            cout << comp3_name << " has died." << endl;
                                                        }
                                                        f = rand()%10 + 1;
                                                        if (f == 1){
                                                            c4.setAlive(false);
                                                            c4.setHealth(0);
                                                            cout << comp4_name << " has died." << endl;
                                                        }
                                                    }
                                                }
                                                else{
                                                    lost_c = rand()%4 + 1;
                                                    switch(lost_c){
                                                        case 1:
                                                            c1.setHealth(0);
                                                            c1.setAlive(false);
                                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 2:
                                                            c2.setHealth(0);
                                                            c2.setAlive(false);
                                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 3:
                                                            c3.setHealth(0);
                                                            c3.setAlive(false);
                                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 4:
                                                            c4.setHealth(0);
                                                            c4.setAlive(false);
                                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                    }
                                                }
                                                break;
                                            case 2:
                                                num_c = 4;
                                                m4 = rand()%3;
                                                cout << "Oh no! A " << lvl4[m4] << " is coming!" << endl;
                                                lvl4.erase(lvl4.begin() + m4);
                                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                                cin >> fight_choice;
                                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                    g = rand()%2 + 1;
                                                    if (g == 1){
                                                        p.setHealth(p.getHealth() - 1);
                                                    }
                                                    h = rand()%2 + 1;
                                                    if (h == 1){
                                                        c1.setHealth(c1.getHealth() - 1);
                                                    }
                                                    i = rand()%2 + 1;
                                                    if (i == 1){
                                                        c2.setHealth(c2.getHealth() - 1);
                                                    }
                                                    j = rand()%2 + 1;
                                                    if (j == 1){
                                                        c3.setHealth(c3.getHealth() - 1);
                                                    }
                                                    k = rand()%2 + 1;
                                                    if (k == 1){
                                                        c4.setHealth(c4.getHealth() - 1);
                                                    }
                                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                    if (fight_score > 0){
                                                        cout << "You win!" << endl;
                                                        gold += num_c*10;
                                                        ingredients += num_c*5;
                                                        a = rand()%10 + 1;
                                                        if (a == 1){
                                                            keys += 1;
                                                            cout << "You found a key!" << endl;
                                                        }
                                                    }
                                                    else{
                                                        cout << "You lose!" << endl;
                                                        gold = (gold*3)/4;
                                                        b = rand()%30 + 1;
                                                        ingredients -= b;
                                                        c = rand()%10 + 1;
                                                        if (c == 1){
                                                            c1.setAlive(false);
                                                            c1.setHealth(0);
                                                            cout << comp1_name << " has died." << endl;
                                                        }
                                                        d = rand()%10 + 1;
                                                        if (d == 1){
                                                            c2.setAlive(false);
                                                            c2.setHealth(0);
                                                            cout << comp2_name << " has died." << endl;
                                                        }
                                                        e = rand()%10 + 1;
                                                        if (e == 1){
                                                            c3.setAlive(false);
                                                            c3.setHealth(0);
                                                            cout << comp3_name << " has died." << endl;
                                                        }
                                                        f = rand()%10 + 1;
                                                        if (f == 1){
                                                            c4.setAlive(false);
                                                            c4.setHealth(0);
                                                            cout << comp4_name << " has died." << endl;
                                                        }
                                                    }
                                                }
                                                else{
                                                    lost_c = rand()%4 + 1;
                                                    switch(lost_c){
                                                        case 1:
                                                            c1.setHealth(0);
                                                            c1.setAlive(false);
                                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 2:
                                                            c2.setHealth(0);
                                                            c2.setAlive(false);
                                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 3:
                                                            c3.setHealth(0);
                                                            c3.setAlive(false);
                                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 4:
                                                            c4.setHealth(0);
                                                            c4.setAlive(false);
                                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                    }
                                                }
                                                break;
                                            case 3:
                                                num_c = 5;
                                                m5 = rand()%3;
                                                cout << "Oh no! A " << lvl5[m5] << " is coming!" << endl;
                                                lvl5.erase(lvl5.begin() + m5);
                                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                                cin >> fight_choice;
                                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                    g = rand()%2 + 1;
                                                    if (g == 1){
                                                        p.setHealth(p.getHealth() - 1);
                                                    }
                                                    h = rand()%2 + 1;
                                                    if (h == 1){
                                                        c1.setHealth(c1.getHealth() - 1);
                                                    }
                                                    i = rand()%2 + 1;
                                                    if (i == 1){
                                                        c2.setHealth(c2.getHealth() - 1);
                                                    }
                                                    j = rand()%2 + 1;
                                                    if (j == 1){
                                                        c3.setHealth(c3.getHealth() - 1);
                                                    }
                                                    k = rand()%2 + 1;
                                                    if (k == 1){
                                                        c4.setHealth(c4.getHealth() - 1);
                                                    }
                                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                    if (fight_score > 0){
                                                        cout << "You win!" << endl;
                                                        gold += num_c*10;
                                                        ingredients += num_c*5;
                                                        a = rand()%10 + 1;
                                                        if (a == 1){
                                                            keys += 1;
                                                            cout << "You found a key!" << endl;
                                                        }
                                                    }
                                                    else{
                                                        cout << "You lose!" << endl;
                                                        gold = (gold*3)/4;
                                                        b = rand()%30 + 1;
                                                        ingredients -= b;
                                                        c = rand()%10 + 1;
                                                        if (c == 1){
                                                            c1.setAlive(false);
                                                            c1.setHealth(0);
                                                            cout << comp1_name << " has died." << endl;
                                                        }
                                                        d = rand()%10 + 1;
                                                        if (d == 1){
                                                            c2.setAlive(false);
                                                            c2.setHealth(0);
                                                            cout << comp2_name << " has died." << endl;
                                                        }
                                                        e = rand()%10 + 1;
                                                        if (e == 1){
                                                            c3.setAlive(false);
                                                            c3.setHealth(0);
                                                            cout << comp3_name << " has died." << endl;
                                                        }
                                                        f = rand()%10 + 1;
                                                        if (f == 1){
                                                            c4.setAlive(false);
                                                            c4.setHealth(0);
                                                            cout << comp4_name << " has died." << endl;
                                                        }
                                                    }
                                                }
                                                else{
                                                    lost_c = rand()%4 + 1;
                                                    switch(lost_c){
                                                        case 1:
                                                            c1.setHealth(0);
                                                            c1.setAlive(false);
                                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 2:
                                                            c2.setHealth(0);
                                                            c2.setAlive(false);
                                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 3:
                                                            c3.setHealth(0);
                                                            c3.setAlive(false);
                                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 4:
                                                            c4.setHealth(0);
                                                            c4.setAlive(false);
                                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                    }
                                                }
                                                break;
                                            case 4:
                                                num_c = 5;
                                                m5 = rand()%3;
                                                cout << "Oh no! A " << lvl5[m5] << " is coming!" << endl;
                                                lvl5.erase(lvl5.begin() + m5);
                                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                                cin >> fight_choice;
                                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                    g = rand()%2 + 1;
                                                    if (g == 1){
                                                        p.setHealth(p.getHealth() - 1);
                                                    }
                                                    h = rand()%2 + 1;
                                                    if (h == 1){
                                                        c1.setHealth(c1.getHealth() - 1);
                                                    }
                                                    i = rand()%2 + 1;
                                                    if (i == 1){
                                                        c2.setHealth(c2.getHealth() - 1);
                                                    }
                                                    j = rand()%2 + 1;
                                                    if (j == 1){
                                                        c3.setHealth(c3.getHealth() - 1);
                                                    }
                                                    k = rand()%2 + 1;
                                                    if (k == 1){
                                                        c4.setHealth(c4.getHealth() - 1);
                                                    }
                                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                    if (fight_score > 0){
                                                        cout << "You win!" << endl;
                                                        gold += num_c*10;
                                                        ingredients += num_c*5;
                                                        a = rand()%10 + 1;
                                                        if (a == 1){
                                                            keys += 1;
                                                            cout << "You found a key!" << endl;
                                                        }
                                                    }
                                                    else{
                                                        cout << "You lose!" << endl;
                                                        gold = (gold*3)/4;
                                                        b = rand()%30 + 1;
                                                        ingredients -= b;
                                                        c = rand()%10 + 1;
                                                        if (c == 1){
                                                            c1.setAlive(false);
                                                            c1.setHealth(0);
                                                            cout << comp1_name << " has died." << endl;
                                                        }
                                                        d = rand()%10 + 1;
                                                        if (d == 1){
                                                            c2.setAlive(false);
                                                            c2.setHealth(0);
                                                            cout << comp2_name << " has died." << endl;
                                                        }
                                                        e = rand()%10 + 1;
                                                        if (e == 1){
                                                            c3.setAlive(false);
                                                            c3.setHealth(0);
                                                            cout << comp3_name << " has died." << endl;
                                                        }
                                                        f = rand()%10 + 1;
                                                        if (f == 1){
                                                            c4.setAlive(false);
                                                            c4.setHealth(0);
                                                            cout << comp4_name << " has died." << endl;
                                                        }
                                                    }
                                                }
                                                else{
                                                    lost_c = rand()%4 + 1;
                                                    switch(lost_c){
                                                        case 1:
                                                            c1.setHealth(0);
                                                            c1.setAlive(false);
                                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 2:
                                                            c2.setHealth(0);
                                                            c2.setAlive(false);
                                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 3:
                                                            c3.setHealth(0);
                                                            c3.setAlive(false);
                                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                        case 4:
                                                            c4.setHealth(0);
                                                            c4.setAlive(false);
                                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                                            break;
                                                    }
                                                }
                                                break;
                                        }
                                        }
                                        num_monsters++;
                                        rooms++;
                                    }
                                break;
                            case 3:
                                cout << "You have decided to give up. Better luck next time." << endl;
                                r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                                r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                                return 0;
                                break;
                        }
                    }
                    
                    if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())){
                        cout << "You've encountered an NPC. Choose 1 of the following: 1. Move, 2. Speak to NPC, or 3. Give up." << endl;
                        cin >> NPC_choice;
                        switch(NPC_choice){
                            case 1:
                                cout << "Where would you like to go? (w, a, s, d)" << endl;
                                cin >> direction_choice;
                                if (direction_choice == 'w' || direction_choice == 's' || direction_choice == 'a' || direction_choice == 'd'){
                                    if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false){
                                        anger++;
                                    }
                                    map.move(direction_choice);
                                    a = rand()%100 + 1;
                                    if (a <= 20){
                                        p_health = p.getHealth();
                                        p.setHealth(p_health - 1); 
                                    }
                                    b = rand()%100 + 1;
                                    if (b <= 20){
                                        c1_health = c1.getHealth();
                                        p.setHealth(c1_health - 1); 
                                    }
                                    c = rand()%100 + 1;
                                    if (c <= 20){
                                        c2_health = c2.getHealth();
                                        p.setHealth(c2_health - 1); 
                                    }
                                    d = rand()%100 + 1;
                                    if (d <= 20){
                                        c3_health = c3.getHealth();
                                        p.setHealth(c3_health - 1); 
                                    }
                                    e = rand()%100 + 1;
                                    if (e <= 20){
                                        c4_health = c4.getHealth();
                                        p.setHealth(c4_health - 1); 
                                    }
                                }
                                if (anger >= 100){
                                    cout << "The Sorcerer has destroyed your entire party." << endl;
                                    r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                                    r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                                    return 0;
                                }
                                break;
                            case 2:
                                riddle.open("riddles.txt");
                                while(getline(riddle, line)){
                                    split(line, '~', arr, 2);
                                    riddles.push_back(arr[0]);
                                    answers.push_back(arr[1]);
                                }
                                a = rand()%20 + 1;
                                cout << "Answer this riddle:" << endl;
                                cout << riddles[a] << endl;
                                cin >> answer;
                                if (answer == answers[a]){
                                    cout << "Correct! Would you like to buy more items? (y/n)" << endl;
                                    cin >> ans;
                                    if (ans == 'y'){
                                        cout << "If you're looking to get supplies, you've come to the right place.\nI would be happy to part with some of my wares...for the proper price!\n+-------------+\n| INVENTORY   |\n+-------------+\n| Gold        | "<< gold << "\n| Ingredients | "<< ingredients <<" kg\n| Cookware    | P: " << pot << " | F: " << pan << " | C: " << cauldron << "\n| Weapons     | C: " << club << " | S: " << spear << " | R: " << rapier << " | B: " << axe << " | L: " << longsword << "\n| Armor       | " << armor << "\n| Treasures   | R: " << ring << " | N: " << necklace << " | B: " << bracelet << " | C: " << circlet << " | G: " << goblet << "\nChoose one of the following:\n 1. Ingredients: To make food, you have to cook raw ingredients.\n 2. Cookware: You will need something to cook those ingredients.\n 3. Weapons: It's dangerous to go alone, take this!\n 4. Armor: If you want to survive monster attacks, you will need some armor.\n 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.\n 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
                                        cin >> merchant_choice;
                                        while (merchant_choice != 6){
                                            switch(merchant_choice){
                                            case 1:
                                                cout << "How many kg of ingredients do you need [" << 1*(1 + 0.25*rooms) << " Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
                                                cin >> amount;
                                                cout << "You want to buy " << amount << " kg of ingredients for " << amount * (1+0.25*rooms) << " Gold? (y/n)" << endl;
                                                cin >> ans;
                                                if (amount == 0){
                                                    break;
                                                }
                                                else if (ans == 'y' && gold >= amount * (1+0.25*rooms)){
                                                    ingredients += amount;
                                                    gold -= amount * (1+0.25*rooms);
                                                }
                                                else if (gold <= amount * (1+0.25*rooms)){
                                                    cout << "You do not have enough gold." << endl;
                                                    break;
                                                }
                                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                break;
                                            case 2:
                                                cout << "I have a several types of cookware, which one would you like?\nEach type has a different probability of breaking when used, marked with (XX%).\nChoose one of the following:\n 1. (25%) Ceramic Pot [" << 2*(1 + 0.25*rooms) << " Gold]\n 2. (10%) Frying Pan [" << 10*(1 + 0.25*rooms) << " Gold] \n3. ( 2%) Cauldron [" << 20*(1 + 0.25*rooms) << " Gold]\n 4. Cancel" << endl;
                                                cin >> cookware_choice;
                                                if (cookware_choice == 4){
                                                    break;
                                                }
                                                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                                                cin >> num;
                                                if (num == 0){
                                                    break;
                                                }
                                                switch(cookware_choice){
                                                    case 1:
                                                        cout << "You want to buy " << num << "Ceramic Pot(s) for " << 2*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                        cin >> ans;
                                                        if (ans == 'y'&& gold >= 2*num*(1 + 0.25*rooms)){
                                                            pot += num;
                                                            gold -= 2*num*(1 + 0.25*rooms);
                                                        }
                                                        else if (gold <= 2*num*(1 + 0.25*rooms)){
                                                            cout << "You do not have enough gold." << endl;
                                                            break;
                                                        }
                                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                        break;
                                                    case 2:
                                                        cout << "You want to buy " << num << "Frying Pan(s) for " << 10*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                        cin >> ans;
                                                        if (ans == 'y' && gold >= 10*num*(1 + 0.25*rooms)){
                                                            pan += num;
                                                            gold -= 10*num*(1 + 0.25*rooms);
                                                        }
                                                        else if (gold <= 10*num*(1 + 0.25*rooms)){
                                                            cout << "You do not have enough gold." << endl;
                                                            break;
                                                        }
                                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                        break;
                                                    case 3:
                                                        cout << "You want to buy " << num << "Cauldron(s) for " << 20*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                        cin >> ans;
                                                        if (ans == 'y' && gold >= 20*num*(1 + 0.25*rooms)){
                                                            cauldron += num;
                                                            gold -= 20*num*(1 + 0.25*rooms);
                                                        }
                                                        else if (gold <= 20*num*(1 + 0.25*rooms)){
                                                            cout << "You do not have enough gold." << endl;
                                                            break;
                                                        }
                                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                        break;
                                                    default:
                                                        cout << "Please enter a valid input." << endl;
                                                }
                                                break;
                                            case 3:
                                                cout << "I have a plentiful collection of weapons to choose from, what would you like?\nNote that some of them provide you a special bonus in combat, marked by a (+X).\nChoose one of the following:\n1. Stone Club [2 Gold]\n 2. Iron Spear [2 Gold]\n 3. (+1) Mythril Rapier [5 Gold]\n 4. (+2) Flaming Battle-Axe [15 Gold]\n 5. (+3) Vorpal Longsword [50 Gold]\n 6. Cancel" << endl;
                                                cin >> weapon_choice;
                                                if (weapon_choice == 6){
                                                    break;
                                                }
                                                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                                                cin >> num;
                                                if (num == 0){
                                                    break;
                                                }
                                                switch (weapon_choice){
                                                    case 1:
                                                        cout << "You want to buy " << num << " Stone Club(s) for " << 2*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                        cin >> ans;
                                                        if (ans == 'y' && gold >= 2*num*(1 + 0.25*rooms)){
                                                            club += num;
                                                            gold -= 2*num*(1 + 0.25*rooms);
                                                        }
                                                        else if (gold <= 2*num*(1 + 0.25*rooms)){
                                                            cout << "You do not have enough gold." << endl;
                                                            break;
                                                        }
                                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                        break;
                                                    case 2:
                                                        cout << "You want to buy " << num << " Iron Spear(s) for " << 2*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                        cin >> ans;
                                                        if (ans == 'y' && gold >= 2*num*(1 + 0.25*rooms)){
                                                            spear += num;
                                                            gold -= 2*num*(1 + 0.25*rooms);
                                                        }
                                                        else if (gold <= 2*num*(1 + 0.25*rooms)){
                                                            cout << "You do not have enough gold." << endl;
                                                            break;
                                                        }
                                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                        break;
                                                    case 3:
                                                        cout << "You want to buy " << num << "(+1) Mythril Rapier(s) for " << 5*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                        cin >> ans;
                                                        if (ans == 'y' && gold >= 5*num*(1 + 0.25*rooms)){
                                                            rapier += num;
                                                            gold -= 5*num*(1 + 0.25*rooms);
                                                        }
                                                        else if (gold <= 5*num*(1 + 0.25*rooms)){
                                                            cout << "You do not have enough gold." << endl;
                                                            break;
                                                        }
                                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                        break;
                                                    case 4:
                                                        cout << "You want to buy " << num << "(+2) Flaming Battle-Axe(s) for " << 15*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                        cin >> ans;
                                                        if (ans == 'y' && gold >= 15*num*(1 + 0.25*rooms)){
                                                            axe += num;
                                                            gold -= 15*num*(1 + 0.25*rooms);
                                                        }
                                                        else if (gold <= 15*num*(1 + 0.25*rooms)){
                                                            cout << "You do not have enough gold." << endl;
                                                            break;
                                                        }
                                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                        break;
                                                    case 5:
                                                        cout << "You want to buy " << num << " (+3) Vorpal Longsword(s) for " << 50*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                        cin >> ans;
                                                        if (ans == 'y' && gold >= 50*num*(1 + 0.25*rooms)){
                                                            longsword += num;
                                                            gold -= 50*num*(1 + 0.25*rooms);
                                                        }
                                                        else if (gold <= 50*num){
                                                            cout << "You do not have enough gold." << endl;
                                                            break;
                                                        }
                                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                        break;
                                                    default:
                                                        cout << "Please enter a valid input." << endl;
                                                }
                                                break;
                                            case 4:
                                                cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" << endl;
                                                cin >> num;
                                                if (num == 0){
                                                    break;
                                                }
                                                cout << "You want to buy " << num << " suit(s) of armor for " << 5*num*(1 + 0.25*rooms) << " Gold? (y/n)" << endl;
                                                cin >> ans;
                                                if (ans == 'y' && gold >= 5*num*(1 + 0.25*rooms)){
                                                    armor += num;
                                                    gold -= 5*num*(1 + 0.25*rooms);
                                                }
                                                else if (gold <= 5*num*(1 + 0.25*rooms)){
                                                    cout << "You do not have enough gold." << endl;
                                                    break;
                                                }
                                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                break;
                                            case 5:
                                                break;
                                            default:
                                                cout << "Please enter a valid input." << endl;
                                            }
                                            cout << "+-------------+\n| INVENTORY   |\n+-------------+\n| Gold        | "<< gold << "\n| Ingredients | "<< ingredients <<" kg\n| Cookware    | P: " << pot << " | F: " << pan << " | C: " << cauldron << "\n| Weapons     | C: " << club << " | S: " << spear << " | R: " << rapier << " | B: " << axe << " | L: " << longsword << "\n| Armor       | " << armor << "\n| Treasures   | R: " << ring << " | N: " << necklace << " | B: " << bracelet << " | C: " << circlet << " | G: " << goblet << "\nChoose one of the following:\n 1. Ingredients: To make food, you have to cook raw ingredients.\n 2. Cookware: You will need something to cook those ingredients.\n 3. Weapons: It's dangerous to go alone, take this!\n 4. Armor: If you want to survive monster attacks, you will need some armor.\n 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.\n 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
                                            cin >> merchant_choice;
                                        }
                                        if (merchant_choice == 6){
                                            cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
                                            cin >> ans;
                                            if (ans == 'y'){
                                                cout << "Stay safe out there! Goodbye!" << endl;
                                            }
                                        }
                                    }
                                    else{
                                        cout << "Good luck!" << endl;
                                    }
                                }
                                else{
                                    myFile.open("monsters.txt");
                                    while(getline(myFile, line)){
                                        split(line, ',', arr, 2);
                                        if (stoi(arr[1]) == 1){
                                            lvl1.push_back(arr[0]);
                                        }
                                        if (stoi(arr[1]) == 2){
                                            lvl2.push_back(arr[0]);
                                        }
                                        if (stoi(arr[1]) == 3){
                                            lvl3.push_back(arr[0]);
                                        }
                                        if (stoi(arr[1]) == 4){
                                            lvl4.push_back(arr[0]);
                                        }
                                        if (stoi(arr[1]) == 5){
                                            lvl5.push_back(arr[0]);
                                        }
                                    }
                                    num_w = 5*(club + spear + rapier + axe + longsword + rapier) + (1*rapier) + (2*axe) + (3*longsword);
                                    num_a = armor;
                                    num_r1 = rand()%6 + 1;
                                    num_r2 = rand()%6 + 1;
                                    if (club >= 1 && spear >= 1 && rapier >= 1 && axe >= 1 && longsword >= 1){
                                        num_d = 4;      
                                    }
                                    switch(rooms){
                                        case 0:
                                            num_c = 1;
                                            m1 = rand()%3;
                                            cout << "Oh no! A " << lvl1[m1] << " is coming!" << endl;
                                            lvl1.erase(lvl1.begin() + m1);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                        case 1:
                                            num_c = 2;
                                            m2 = rand()%3;
                                            cout << "Oh no! A " << lvl2[m2] << " is coming!" << endl;
                                            lvl2.erase(lvl2.begin() + m2);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                        case 2:
                                            num_c = 3;
                                            m3 = rand()%3;
                                            cout << "Oh no! A " << lvl3[m3] << " is coming!" << endl;
                                            lvl3.erase(lvl3.begin() + m3);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                        case 3:
                                            num_c = 4;
                                            m4 = rand()%3;
                                            cout << "Oh no! A " << lvl4[m4] << " is coming!" << endl;
                                            lvl4.erase(lvl4.begin() + m4);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                            break;
                                        case 4:
                                            num_c = 5;
                                            m5 = rand()%3;
                                            cout << "Oh no! A " << lvl5[m5] << " is coming!" << endl;
                                            lvl5.erase(lvl5.begin() + m5);
                                            cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                            cin >> fight_choice;
                                            if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                                g = rand()%2 + 1;
                                                if (g == 1){
                                                    p.setHealth(p.getHealth() - 1);
                                                }
                                                h = rand()%2 + 1;
                                                if (h == 1){
                                                    c1.setHealth(c1.getHealth() - 1);
                                                }
                                                i = rand()%2 + 1;
                                                if (i == 1){
                                                    c2.setHealth(c2.getHealth() - 1);
                                                }
                                                j = rand()%2 + 1;
                                                if (j == 1){
                                                    c3.setHealth(c3.getHealth() - 1);
                                                }
                                                k = rand()%2 + 1;
                                                if (k == 1){
                                                    c4.setHealth(c4.getHealth() - 1);
                                                }
                                                fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                                if (fight_score > 0){
                                                    cout << "You win!" << endl;
                                                    gold += num_c*10;
                                                    ingredients += num_c*5;
                                                    a = rand()%10 + 1;
                                                    if (a == 1){
                                                        keys += 1;
                                                        cout << "You found a key!" << endl;
                                                    }
                                                }
                                                else{
                                                    cout << "You lose!" << endl;
                                                    gold = (gold*3)/4;
                                                    b = rand()%30 + 1;
                                                    ingredients -= b;
                                                    c = rand()%10 + 1;
                                                    if (c == 1){
                                                        c1.setAlive(false);
                                                        c1.setHealth(0);
                                                        cout << comp1_name << " has died." << endl;
                                                    }
                                                    d = rand()%10 + 1;
                                                    if (d == 1){
                                                        c2.setAlive(false);
                                                        c2.setHealth(0);
                                                        cout << comp2_name << " has died." << endl;
                                                    }
                                                    e = rand()%10 + 1;
                                                    if (e == 1){
                                                        c3.setAlive(false);
                                                        c3.setHealth(0);
                                                        cout << comp3_name << " has died." << endl;
                                                    }
                                                    f = rand()%10 + 1;
                                                    if (f == 1){
                                                        c4.setAlive(false);
                                                        c4.setHealth(0);
                                                        cout << comp4_name << " has died." << endl;
                                                    }
                                                }
                                            }
                                            else{
                                                lost_c = rand()%4 + 1;
                                                switch(lost_c){
                                                    case 1:
                                                        c1.setHealth(0);
                                                        c1.setAlive(false);
                                                        cout << comp1_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 2:
                                                        c2.setHealth(0);
                                                        c2.setAlive(false);
                                                        cout << comp2_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 3:
                                                        c3.setHealth(0);
                                                        c3.setAlive(false);
                                                        cout << comp3_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                    case 4:
                                                        c4.setHealth(0);
                                                        c4.setAlive(false);
                                                        cout << comp4_name << " has died. You must continue on without them." << endl;
                                                        break;
                                                }
                                            }
                                    }    
                                    }
                                    num_monsters++;
                                
                                break;
                            case 3:
                                cout << "You have decided to give up. Better luck next time." << endl;
                                r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                                r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                                return 0;
                                break;
                        }
                    }
                }
                else{
                    cout << "Please enter a valid direction." << endl;
                    break;
                }
                break;
            case 2:
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol())){
                    cout << "This space has already been explored. Please choose another option.";
                }
                else{
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    f = rand()%100 + 1;
                    if (f <= 10){
                        cout << "You've found a key!" << endl;
                        keys += 1;
                    }
                    g = rand()%100 + 1;
                    if (g <= 20){
                        switch (rooms){
                            case 1:
                                cout << "You've found a ring!" << endl;
                                ring += 1;
                                break;
                            case 2:
                            cout << "You've found a necklace!" << endl;
                                necklace += 1;
                                break;
                            case 3: 
                                cout << "You've found a bracelet!" << endl;
                                bracelet += 1;
                                break;
                            case 4:
                                cout << "You've found a circlet!" << endl;
                                circlet += 1;
                                break;
                            case 5:
                                cout << "You've found a goblet!" << endl;
                                goblet += 1;
                                break;
                        }
                    }
                    h = rand()%100 + 1;
                    if (h <= 20){
                        myFile.open("monsters.txt");
                        while(getline(myFile, line)){
                            split(line, ',', arr, 2);
                            if (stoi(arr[1]) == 1){
                                lvl1.push_back(arr[0]);
                            }
                            if (stoi(arr[1]) == 2){
                                lvl2.push_back(arr[0]);
                            }
                            if (stoi(arr[1]) == 3){
                                lvl3.push_back(arr[0]);
                            }
                            if (stoi(arr[1]) == 4){
                                lvl4.push_back(arr[0]);
                            }
                            if (stoi(arr[1]) == 5){
                                lvl5.push_back(arr[0]);
                            }
                        }
                        num_w = 5*(club + spear + rapier + axe + longsword + rapier) + (1*rapier) + (2*axe) + (3*longsword);
                        num_a = armor;
                        num_r1 = rand()%6 + 1;
                        num_r2 = rand()%6 + 1;
                        if (club >= 1 && spear >= 1 && rapier >= 1 && axe >= 1 && longsword >= 1){
                            num_d = 4;      
                        }
                        switch(rooms){
                            case 0:
                                num_c = 1;
                                m1 = rand()%3;
                                cout << "Oh no! A " << lvl1[m1] << " is coming!" << endl;
                                lvl1.erase(lvl1.begin() + m1);
                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                cin >> fight_choice;
                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                    g = rand()%2 + 1;
                                    if (g == 1){
                                        p.setHealth(p.getHealth() - 1);
                                    }
                                    h = rand()%2 + 1;
                                    if (h == 1){
                                        c1.setHealth(c1.getHealth() - 1);
                                    }
                                    i = rand()%2 + 1;
                                    if (i == 1){
                                        c2.setHealth(c2.getHealth() - 1);
                                    }
                                    j = rand()%2 + 1;
                                    if (j == 1){
                                        c3.setHealth(c3.getHealth() - 1);
                                    }
                                    k = rand()%2 + 1;
                                    if (k == 1){
                                        c4.setHealth(c4.getHealth() - 1);
                                    }
                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                    if (fight_score > 0){
                                        cout << "You win!" << endl;
                                        gold += num_c*10;
                                        ingredients += num_c*5;
                                        a = rand()%10 + 1;
                                        if (a == 1){
                                            keys += 1;
                                            cout << "You found a key!" << endl;
                                        }
                                    }
                                    else{
                                        cout << "You lose!" << endl;
                                        gold = (gold*3)/4;
                                        b = rand()%30 + 1;
                                        ingredients -= b;
                                        c = rand()%10 + 1;
                                        if (c == 1){
                                            c1.setAlive(false);
                                            c1.setHealth(0);
                                            cout << comp1_name << " has died." << endl;
                                        }
                                        d = rand()%10 + 1;
                                        if (d == 1){
                                            c2.setAlive(false);
                                            c2.setHealth(0);
                                            cout << comp2_name << " has died." << endl;
                                        }
                                        e = rand()%10 + 1;
                                        if (e == 1){
                                            c3.setAlive(false);
                                            c3.setHealth(0);
                                            cout << comp3_name << " has died." << endl;
                                        }
                                        f = rand()%10 + 1;
                                        if (f == 1){
                                            c4.setAlive(false);
                                            c4.setHealth(0);
                                            cout << comp4_name << " has died." << endl;
                                        }
                                    }
                                }
                                else{
                                    lost_c = rand()%4 + 1;
                                    switch(lost_c){
                                        case 1:
                                            c1.setHealth(0);
                                            c1.setAlive(false);
                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 2:
                                            c2.setHealth(0);
                                            c2.setAlive(false);
                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 3:
                                            c3.setHealth(0);
                                            c3.setAlive(false);
                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 4:
                                            c4.setHealth(0);
                                            c4.setAlive(false);
                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                            break;
                                    }
                                }
                                break;
                            case 1:
                                num_c = 2;
                                m2 = rand()%3;
                                cout << "Oh no! A " << lvl2[m2] << " is coming!" << endl;
                                lvl2.erase(lvl2.begin() + m2);
                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                cin >> fight_choice;
                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                    g = rand()%2 + 1;
                                    if (g == 1){
                                        p.setHealth(p.getHealth() - 1);
                                    }
                                    h = rand()%2 + 1;
                                    if (h == 1){
                                        c1.setHealth(c1.getHealth() - 1);
                                    }
                                    i = rand()%2 + 1;
                                    if (i == 1){
                                        c2.setHealth(c2.getHealth() - 1);
                                    }
                                    j = rand()%2 + 1;
                                    if (j == 1){
                                        c3.setHealth(c3.getHealth() - 1);
                                    }
                                    k = rand()%2 + 1;
                                    if (k == 1){
                                        c4.setHealth(c4.getHealth() - 1);
                                    }
                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                    if (fight_score > 0){
                                        cout << "You win!" << endl;
                                        gold += num_c*10;
                                        ingredients += num_c*5;
                                        a = rand()%10 + 1;
                                        if (a == 1){
                                            keys += 1;
                                            cout << "You found a key!" << endl;
                                        }
                                    }
                                    else{
                                        cout << "You lose!" << endl;
                                        gold = (gold*3)/4;
                                        b = rand()%30 + 1;
                                        ingredients -= b;
                                        c = rand()%10 + 1;
                                        if (c == 1){
                                            c1.setAlive(false);
                                            c1.setHealth(0);
                                            cout << comp1_name << " has died." << endl;
                                        }
                                        d = rand()%10 + 1;
                                        if (d == 1){
                                            c2.setAlive(false);
                                            c2.setHealth(0);
                                            cout << comp2_name << " has died." << endl;
                                        }
                                        e = rand()%10 + 1;
                                        if (e == 1){
                                            c3.setAlive(false);
                                            c3.setHealth(0);
                                            cout << comp3_name << " has died." << endl;
                                        }
                                        f = rand()%10 + 1;
                                        if (f == 1){
                                            c4.setAlive(false);
                                            c4.setHealth(0);
                                            cout << comp4_name << " has died." << endl;
                                        }
                                    }
                                }
                                else{
                                    lost_c = rand()%4 + 1;
                                    switch(lost_c){
                                        case 1:
                                            c1.setHealth(0);
                                            c1.setAlive(false);
                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 2:
                                            c2.setHealth(0);
                                            c2.setAlive(false);
                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 3:
                                            c3.setHealth(0);
                                            c3.setAlive(false);
                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 4:
                                            c4.setHealth(0);
                                            c4.setAlive(false);
                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                            break;
                                    }
                                }
                                break;
                            case 2:
                                num_c = 3;
                                m3 = rand()%3;
                                cout << "Oh no! A " << lvl3[m3] << " is coming!" << endl;
                                lvl3.erase(lvl3.begin() + m3);
                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                cin >> fight_choice;
                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                    g = rand()%2 + 1;
                                    if (g == 1){
                                        p.setHealth(p.getHealth() - 1);
                                    }
                                    h = rand()%2 + 1;
                                    if (h == 1){
                                        c1.setHealth(c1.getHealth() - 1);
                                    }
                                    i = rand()%2 + 1;
                                    if (i == 1){
                                        c2.setHealth(c2.getHealth() - 1);
                                    }
                                    j = rand()%2 + 1;
                                    if (j == 1){
                                        c3.setHealth(c3.getHealth() - 1);
                                    }
                                    k = rand()%2 + 1;
                                    if (k == 1){
                                        c4.setHealth(c4.getHealth() - 1);
                                    }
                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                    if (fight_score > 0){
                                        cout << "You win!" << endl;
                                        gold += num_c*10;
                                        ingredients += num_c*5;
                                        a = rand()%10 + 1;
                                        if (a == 1){
                                            keys += 1;
                                            cout << "You found a key!" << endl;
                                        }
                                    }
                                    else{
                                        cout << "You lose!" << endl;
                                        gold = (gold*3)/4;
                                        b = rand()%30 + 1;
                                        ingredients -= b;
                                        c = rand()%10 + 1;
                                        if (c == 1){
                                            c1.setAlive(false);
                                            c1.setHealth(0);
                                            cout << comp1_name << " has died." << endl;
                                        }
                                        d = rand()%10 + 1;
                                        if (d == 1){
                                            c2.setAlive(false);
                                            c2.setHealth(0);
                                            cout << comp2_name << " has died." << endl;
                                        }
                                        e = rand()%10 + 1;
                                        if (e == 1){
                                            c3.setAlive(false);
                                            c3.setHealth(0);
                                            cout << comp3_name << " has died." << endl;
                                        }
                                        f = rand()%10 + 1;
                                        if (f == 1){
                                            c4.setAlive(false);
                                            c4.setHealth(0);
                                            cout << comp4_name << " has died." << endl;
                                        }
                                    }
                                }
                                else{
                                    lost_c = rand()%4 + 1;
                                    switch(lost_c){
                                        case 1:
                                            c1.setHealth(0);
                                            c1.setAlive(false);
                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 2:
                                            c2.setHealth(0);
                                            c2.setAlive(false);
                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 3:
                                            c3.setHealth(0);
                                            c3.setAlive(false);
                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 4:
                                            c4.setHealth(0);
                                            c4.setAlive(false);
                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                            break;
                                    }
                                }
                                break;
                            case 3:
                                num_c = 4;
                                m4 = rand()%3;
                                cout << "Oh no! A " << lvl4[m4] << " is coming!" << endl;
                                lvl4.erase(lvl4.begin() + m4);
                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                cin >> fight_choice;
                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                    g = rand()%2 + 1;
                                    if (g == 1){
                                        p.setHealth(p.getHealth() - 1);
                                    }
                                    h = rand()%2 + 1;
                                    if (h == 1){
                                        c1.setHealth(c1.getHealth() - 1);
                                    }
                                    i = rand()%2 + 1;
                                    if (i == 1){
                                        c2.setHealth(c2.getHealth() - 1);
                                    }
                                    j = rand()%2 + 1;
                                    if (j == 1){
                                        c3.setHealth(c3.getHealth() - 1);
                                    }
                                    k = rand()%2 + 1;
                                    if (k == 1){
                                        c4.setHealth(c4.getHealth() - 1);
                                    }
                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                    if (fight_score > 0){
                                        cout << "You win!" << endl;
                                        gold += num_c*10;
                                        ingredients += num_c*5;
                                        a = rand()%10 + 1;
                                        if (a == 1){
                                            keys += 1;
                                            cout << "You found a key!" << endl;
                                        }
                                    }
                                    else{
                                        cout << "You lose!" << endl;
                                        gold = (gold*3)/4;
                                        b = rand()%30 + 1;
                                        ingredients -= b;
                                        c = rand()%10 + 1;
                                        if (c == 1){
                                            c1.setAlive(false);
                                            c1.setHealth(0);
                                            cout << comp1_name << " has died." << endl;
                                        }
                                        d = rand()%10 + 1;
                                        if (d == 1){
                                            c2.setAlive(false);
                                            c2.setHealth(0);
                                            cout << comp2_name << " has died." << endl;
                                        }
                                        e = rand()%10 + 1;
                                        if (e == 1){
                                            c3.setAlive(false);
                                            c3.setHealth(0);
                                            cout << comp3_name << " has died." << endl;
                                        }
                                        f = rand()%10 + 1;
                                        if (f == 1){
                                            c4.setAlive(false);
                                            c4.setHealth(0);
                                            cout << comp4_name << " has died." << endl;
                                        }
                                    }
                                }
                                else{
                                    lost_c = rand()%4 + 1;
                                    switch(lost_c){
                                        case 1:
                                            c1.setHealth(0);
                                            c1.setAlive(false);
                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 2:
                                            c2.setHealth(0);
                                            c2.setAlive(false);
                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 3:
                                            c3.setHealth(0);
                                            c3.setAlive(false);
                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 4:
                                            c4.setHealth(0);
                                            c4.setAlive(false);
                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                            break;
                                    }
                                }
                                break;
                            case 4:
                                num_c = 5;
                                m5 = rand()%3;
                                cout << "Oh no! A " << lvl5[m5] << " is coming!" << endl;
                                lvl5.erase(lvl5.begin() + m5);
                                cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                                cin >> fight_choice;
                                if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                                    g = rand()%2 + 1;
                                    if (g == 1){
                                        p.setHealth(p.getHealth() - 1);
                                    }
                                    h = rand()%2 + 1;
                                    if (h == 1){
                                        c1.setHealth(c1.getHealth() - 1);
                                    }
                                    i = rand()%2 + 1;
                                    if (i == 1){
                                        c2.setHealth(c2.getHealth() - 1);
                                    }
                                    j = rand()%2 + 1;
                                    if (j == 1){
                                        c3.setHealth(c3.getHealth() - 1);
                                    }
                                    k = rand()%2 + 1;
                                    if (k == 1){
                                        c4.setHealth(c4.getHealth() - 1);
                                    }
                                    fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                                    if (fight_score > 0){
                                        cout << "You win!" << endl;
                                        gold += num_c*10;
                                        ingredients += num_c*5;
                                        a = rand()%10 + 1;
                                        if (a == 1){
                                            keys += 1;
                                            cout << "You found a key!" << endl;
                                        }
                                    }
                                    else{
                                        cout << "You lose!" << endl;
                                        gold = (gold*3)/4;
                                        b = rand()%30 + 1;
                                        ingredients -= b;
                                        c = rand()%10 + 1;
                                        if (c == 1){
                                            c1.setAlive(false);
                                            c1.setHealth(0);
                                            cout << comp1_name << " has died." << endl;
                                        }
                                        d = rand()%10 + 1;
                                        if (d == 1){
                                            c2.setAlive(false);
                                            c2.setHealth(0);
                                            cout << comp2_name << " has died." << endl;
                                        }
                                        e = rand()%10 + 1;
                                        if (e == 1){
                                            c3.setAlive(false);
                                            c3.setHealth(0);
                                            cout << comp3_name << " has died." << endl;
                                        }
                                        f = rand()%10 + 1;
                                        if (f == 1){
                                            c4.setAlive(false);
                                            c4.setHealth(0);
                                            cout << comp4_name << " has died." << endl;
                                        }
                                    }
                                }
                                else{
                                    lost_c = rand()%4 + 1;
                                    switch(lost_c){
                                        case 1:
                                            c1.setHealth(0);
                                            c1.setAlive(false);
                                            cout << comp1_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 2:
                                            c2.setHealth(0);
                                            c2.setAlive(false);
                                            cout << comp2_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 3:
                                            c3.setHealth(0);
                                            c3.setAlive(false);
                                            cout << comp3_name << " has died. You must continue on without them." << endl;
                                            break;
                                        case 4:
                                            c4.setHealth(0);
                                            c4.setAlive(false);
                                            cout << comp4_name << " has died. You must continue on without them." << endl;
                                            break;
                                    }
                                }
                                break;
                        }
                        num_monsters++;
                        break;
                    }
                    a = rand()%100 + 1;
                    if (a <= 50){
                        p_health = p.getHealth();
                        p.setHealth(p_health - 1); 
                    }
                    b = rand()%100 + 1;
                    if (b <= 50){
                        c1_health = c1.getHealth();
                        p.setHealth(c1_health - 1); 
                    }
                    c = rand()%100 + 1;
                    if (c <= 50){
                        c2_health = c2.getHealth();
                        p.setHealth(c2_health - 1); 
                    }
                    d = rand()%100 + 1;
                    if (d <= 50){
                        c3_health = c3.getHealth();
                        p.setHealth(c3_health - 1); 
                    }
                    e = rand()%100 + 1;
                    if (e <= 50){
                        c4_health = c4.getHealth();
                        p.setHealth(c4_health - 1); 
                    }
                    spaces++;
                }
                break;
            case 3:
                myFile.open("monsters.txt");
                while(getline(myFile, line)){
                    split(line, ',', arr, 2);
                    if (stoi(arr[1]) == 1){
                        lvl1.push_back(arr[0]);
                    }
                    if (stoi(arr[1]) == 2){
                        lvl2.push_back(arr[0]);
                    }
                    if (stoi(arr[1]) == 3){
                        lvl3.push_back(arr[0]);
                    }
                    if (stoi(arr[1]) == 4){
                        lvl4.push_back(arr[0]);
                    }
                    if (stoi(arr[1]) == 5){
                        lvl5.push_back(arr[0]);
                    }
                }
                num_w = 5*(club + spear + rapier + axe + longsword + rapier) + (1*rapier) + (2*axe) + (3*longsword);
                num_a = armor;
                num_r1 = rand()%6 + 1;
                num_r2 = rand()%6 + 1;
                if (club >= 1 && spear >= 1 && rapier >= 1 && axe >= 1 && longsword >= 1){
                    num_d = 4;      
                }
                switch(rooms){
                    case 0:
                        num_c = 1;
                        m1 = rand()%3;
                        cout << "Oh no! A " << lvl1[m1] << " is coming!" << endl;
                        lvl1.erase(lvl1.begin() + m1);
                        cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                        cin >> fight_choice;
                        if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                            g = rand()%2 + 1;
                            if (g == 1){
                                p.setHealth(p.getHealth() - 1);
                            }
                            h = rand()%2 + 1;
                            if (h == 1){
                                c1.setHealth(c1.getHealth() - 1);
                            }
                            i = rand()%2 + 1;
                            if (i == 1){
                                c2.setHealth(c2.getHealth() - 1);
                            }
                            j = rand()%2 + 1;
                            if (j == 1){
                                c3.setHealth(c3.getHealth() - 1);
                            }
                            k = rand()%2 + 1;
                            if (k == 1){
                                c4.setHealth(c4.getHealth() - 1);
                            }
                            fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                            if (fight_score > 0){
                                cout << "You win!" << endl;
                                gold += num_c*10;
                                ingredients += num_c*5;
                                a = rand()%10 + 1;
                                if (a == 1){
                                    keys += 1;
                                    cout << "You found a key!" << endl;
                                }
                            }
                            else{
                                cout << "You lose!" << endl;
                                gold = (gold*3)/4;
                                b = rand()%30 + 1;
                                ingredients -= b;
                                c = rand()%10 + 1;
                                if (c == 1){
                                    c1.setAlive(false);
                                    c1.setHealth(0);
                                    cout << comp1_name << " has died." << endl;
                                }
                                d = rand()%10 + 1;
                                if (d == 1){
                                    c2.setAlive(false);
                                    c2.setHealth(0);
                                    cout << comp2_name << " has died." << endl;
                                }
                                e = rand()%10 + 1;
                                if (e == 1){
                                    c3.setAlive(false);
                                    c3.setHealth(0);
                                    cout << comp3_name << " has died." << endl;
                                }
                                f = rand()%10 + 1;
                                if (f == 1){
                                    c4.setAlive(false);
                                    c4.setHealth(0);
                                    cout << comp4_name << " has died." << endl;
                                }
                            }
                        }
                        else{
                            lost_c = rand()%4 + 1;
                            switch(lost_c){
                                case 1:
                                    c1.setHealth(0);
                                    c1.setAlive(false);
                                    cout << comp1_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 2:
                                    c2.setHealth(0);
                                    c2.setAlive(false);
                                    cout << comp2_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 3:
                                    c3.setHealth(0);
                                    c3.setAlive(false);
                                    cout << comp3_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 4:
                                    c4.setHealth(0);
                                    c4.setAlive(false);
                                    cout << comp4_name << " has died. You must continue on without them." << endl;
                                    break;
                            }
                        }
                        break;
                    case 1:
                        num_c = 2;
                        m2 = rand()%3;
                        cout << "Oh no! A " << lvl2[m2] << " is coming!" << endl;
                        lvl2.erase(lvl2.begin() + m2);
                        cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                        cin >> fight_choice;
                        if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                            g = rand()%2 + 1;
                            if (g == 1){
                                p.setHealth(p.getHealth() - 1);
                            }
                            h = rand()%2 + 1;
                            if (h == 1){
                                c1.setHealth(c1.getHealth() - 1);
                            }
                            i = rand()%2 + 1;
                            if (i == 1){
                                c2.setHealth(c2.getHealth() - 1);
                            }
                            j = rand()%2 + 1;
                            if (j == 1){
                                c3.setHealth(c3.getHealth() - 1);
                            }
                            k = rand()%2 + 1;
                            if (k == 1){
                                c4.setHealth(c4.getHealth() - 1);
                            }
                            fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                            if (fight_score > 0){
                                cout << "You win!" << endl;
                                gold += num_c*10;
                                ingredients += num_c*5;
                                a = rand()%10 + 1;
                                if (a == 1){
                                    keys += 1;
                                    cout << "You found a key!" << endl;
                                }
                            }
                            else{
                                cout << "You lose!" << endl;
                                gold = (gold*3)/4;
                                b = rand()%30 + 1;
                                ingredients -= b;
                                c = rand()%10 + 1;
                                if (c == 1){
                                    c1.setAlive(false);
                                    c1.setHealth(0);
                                    cout << comp1_name << " has died." << endl;
                                }
                                d = rand()%10 + 1;
                                if (d == 1){
                                    c2.setAlive(false);
                                    c2.setHealth(0);
                                    cout << comp2_name << " has died." << endl;
                                }
                                e = rand()%10 + 1;
                                if (e == 1){
                                    c3.setAlive(false);
                                    c3.setHealth(0);
                                    cout << comp3_name << " has died." << endl;
                                }
                                f = rand()%10 + 1;
                                if (f == 1){
                                    c4.setAlive(false);
                                    c4.setHealth(0);
                                    cout << comp4_name << " has died." << endl;
                                }
                            }
                        }
                        else{
                            lost_c = rand()%4 + 1;
                            switch(lost_c){
                                case 1:
                                    c1.setHealth(0);
                                    c1.setAlive(false);
                                    cout << comp1_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 2:
                                    c2.setHealth(0);
                                    c2.setAlive(false);
                                    cout << comp2_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 3:
                                    c3.setHealth(0);
                                    c3.setAlive(false);
                                    cout << comp3_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 4:
                                    c4.setHealth(0);
                                    c4.setAlive(false);
                                    cout << comp4_name << " has died. You must continue on without them." << endl;
                                    break;
                            }
                        }
                        break;
                    case 2:
                        num_c = 3;
                        m3 = rand()%3;
                        cout << "Oh no! A " << lvl3[m3] << " is coming!" << endl;
                        lvl3.erase(lvl3.begin() + m3);
                        cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                        cin >> fight_choice;
                        if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                            g = rand()%2 + 1;
                            if (g == 1){
                                p.setHealth(p.getHealth() - 1);
                            }
                            h = rand()%2 + 1;
                            if (h == 1){
                                c1.setHealth(c1.getHealth() - 1);
                            }
                            i = rand()%2 + 1;
                            if (i == 1){
                                c2.setHealth(c2.getHealth() - 1);
                            }
                            j = rand()%2 + 1;
                            if (j == 1){
                                c3.setHealth(c3.getHealth() - 1);
                            }
                            k = rand()%2 + 1;
                            if (k == 1){
                                c4.setHealth(c4.getHealth() - 1);
                            }
                            fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                            if (fight_score > 0){
                                cout << "You win!" << endl;
                                gold += num_c*10;
                                ingredients += num_c*5;
                                a = rand()%10 + 1;
                                if (a == 1){
                                    keys += 1;
                                    cout << "You found a key!" << endl;
                                }
                            }
                            else{
                                cout << "You lose!" << endl;
                                gold = (gold*3)/4;
                                b = rand()%30 + 1;
                                ingredients -= b;
                                c = rand()%10 + 1;
                                if (c == 1){
                                    c1.setAlive(false);
                                    c1.setHealth(0);
                                    cout << comp1_name << " has died." << endl;
                                }
                                d = rand()%10 + 1;
                                if (d == 1){
                                    c2.setAlive(false);
                                    c2.setHealth(0);
                                    cout << comp2_name << " has died." << endl;
                                }
                                e = rand()%10 + 1;
                                if (e == 1){
                                    c3.setAlive(false);
                                    c3.setHealth(0);
                                    cout << comp3_name << " has died." << endl;
                                }
                                f = rand()%10 + 1;
                                if (f == 1){
                                    c4.setAlive(false);
                                    c4.setHealth(0);
                                    cout << comp4_name << " has died." << endl;
                                }
                            }
                        }
                        else{
                            lost_c = rand()%4 + 1;
                            switch(lost_c){
                                case 1:
                                    c1.setHealth(0);
                                    c1.setAlive(false);
                                    cout << comp1_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 2:
                                    c2.setHealth(0);
                                    c2.setAlive(false);
                                    cout << comp2_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 3:
                                    c3.setHealth(0);
                                    c3.setAlive(false);
                                    cout << comp3_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 4:
                                    c4.setHealth(0);
                                    c4.setAlive(false);
                                    cout << comp4_name << " has died. You must continue on without them." << endl;
                                    break;
                            }
                        }
                        break;
                    case 3:
                        num_c = 4;
                        m4 = rand()%3;
                        cout << "Oh no! A " << lvl4[m4] << " is coming!" << endl;
                        lvl4.erase(lvl4.begin() + m4);
                        cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                        cin >> fight_choice;
                        if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                            g = rand()%2 + 1;
                            if (g == 1){
                                p.setHealth(p.getHealth() - 1);
                            }
                            h = rand()%2 + 1;
                            if (h == 1){
                                c1.setHealth(c1.getHealth() - 1);
                            }
                            i = rand()%2 + 1;
                            if (i == 1){
                                c2.setHealth(c2.getHealth() - 1);
                            }
                            j = rand()%2 + 1;
                            if (j == 1){
                                c3.setHealth(c3.getHealth() - 1);
                            }
                            k = rand()%2 + 1;
                            if (k == 1){
                                c4.setHealth(c4.getHealth() - 1);
                            }
                            fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                            if (fight_score > 0){
                                cout << "You win!" << endl;
                                gold += num_c*10;
                                ingredients += num_c*5;
                                a = rand()%10 + 1;
                                if (a == 1){
                                    keys += 1;
                                    cout << "You found a key!" << endl;
                                }
                            }
                            else{
                                cout << "You lose!" << endl;
                                gold = (gold*3)/4;
                                b = rand()%30 + 1;
                                ingredients -= b;
                                c = rand()%10 + 1;
                                if (c == 1){
                                    c1.setAlive(false);
                                    c1.setHealth(0);
                                    cout << comp1_name << " has died." << endl;
                                }
                                d = rand()%10 + 1;
                                if (d == 1){
                                    c2.setAlive(false);
                                    c2.setHealth(0);
                                    cout << comp2_name << " has died." << endl;
                                }
                                e = rand()%10 + 1;
                                if (e == 1){
                                    c3.setAlive(false);
                                    c3.setHealth(0);
                                    cout << comp3_name << " has died." << endl;
                                }
                                f = rand()%10 + 1;
                                if (f == 1){
                                    c4.setAlive(false);
                                    c4.setHealth(0);
                                    cout << comp4_name << " has died." << endl;
                                }
                            }
                        }
                        else{
                            lost_c = rand()%4 + 1;
                            switch(lost_c){
                                case 1:
                                    c1.setHealth(0);
                                    c1.setAlive(false);
                                    cout << comp1_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 2:
                                    c2.setHealth(0);
                                    c2.setAlive(false);
                                    cout << comp2_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 3:
                                    c3.setHealth(0);
                                    c3.setAlive(false);
                                    cout << comp3_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 4:
                                    c4.setHealth(0);
                                    c4.setAlive(false);
                                    cout << comp4_name << " has died. You must continue on without them." << endl;
                                    break;
                            }
                        }
                        break;
                    case 4:
                        num_c = 5;
                        m5 = rand()%3;
                        cout << "Oh no! A " << lvl5[m5] << " is coming!" << endl;
                        lvl5.erase(lvl5.begin() + m5);
                        cout << "Do you want to 1. Fight or 2. Surrender?" << endl;
                        cin >> fight_choice;
                        if (fight_choice == 1 && (club > 0 || spear > 0 || rapier > 0 || axe > 0 || longsword > 0)){
                            g = rand()%2 + 1;
                            if (g == 1){
                                p.setHealth(p.getHealth() - 1);
                            }
                            h = rand()%2 + 1;
                            if (h == 1){
                                c1.setHealth(c1.getHealth() - 1);
                            }
                            i = rand()%2 + 1;
                            if (i == 1){
                                c2.setHealth(c2.getHealth() - 1);
                            }
                            j = rand()%2 + 1;
                            if (j == 1){
                                c3.setHealth(c3.getHealth() - 1);
                            }
                            k = rand()%2 + 1;
                            if (k == 1){
                                c4.setHealth(c4.getHealth() - 1);
                            }
                            fight_score = (num_r1 * num_w + num_d) - ((num_r2 * num_c) / num_a);
                            if (fight_score > 0){
                                cout << "You win!" << endl;
                                gold += num_c*10;
                                ingredients += num_c*5;
                                a = rand()%10 + 1;
                                if (a == 1){
                                    keys += 1;
                                    cout << "You found a key!" << endl;
                                }
                            }
                            else{
                                cout << "You lose!" << endl;
                                gold = (gold*3)/4;
                                b = rand()%30 + 1;
                                ingredients -= b;
                                c = rand()%10 + 1;
                                if (c == 1){
                                    c1.setAlive(false);
                                    c1.setHealth(0);
                                    cout << comp1_name << " has died." << endl;
                                }
                                d = rand()%10 + 1;
                                if (d == 1){
                                    c2.setAlive(false);
                                    c2.setHealth(0);
                                    cout << comp2_name << " has died." << endl;
                                }
                                e = rand()%10 + 1;
                                if (e == 1){
                                    c3.setAlive(false);
                                    c3.setHealth(0);
                                    cout << comp3_name << " has died." << endl;
                                }
                                f = rand()%10 + 1;
                                if (f == 1){
                                    c4.setAlive(false);
                                    c4.setHealth(0);
                                    cout << comp4_name << " has died." << endl;
                                }
                            }
                        }
                        else{
                            lost_c = rand()%4 + 1;
                            switch(lost_c){
                                case 1:
                                    c1.setHealth(0);
                                    c1.setAlive(false);
                                    cout << comp1_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 2:
                                    c2.setHealth(0);
                                    c2.setAlive(false);
                                    cout << comp2_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 3:
                                    c3.setHealth(0);
                                    c3.setAlive(false);
                                    cout << comp3_name << " has died. You must continue on without them." << endl;
                                    break;
                                case 4:
                                    c4.setHealth(0);
                                    c4.setAlive(false);
                                    cout << comp4_name << " has died. You must continue on without them." << endl;
                                    break;
                            }
                        }
                        break;
                }

                num_monsters++;
                //rooms++;
                break;
            case 4:
                // pot has 25% chance of breaking, pan has 10%, cauldron has 2%
                cout << "How many ingredients do you want to use to cook? (Enter a multiple of 5)" << endl;
                cin >> cooking;
                if (ingredients < cooking){
                    cout << "You do not have sufficient ingredients." << endl;
                    break;
                }
                else{
                    cout << "What cookware do you want to use? (p, f, c)" << endl;
                    cin >> cookware;
                    switch (cookware){
                        case 'p':
                            if (pot >= 1){
                                ingredients -= cooking;
                                a = rand()%4 + 1;
                                if (a != 1){
                                   p_health = p.getHealth();
                                   p.setHealth(p_health + (ingredients / 5));
                                   c1_health = c1.getHealth();
                                   c1.setHealth(c1_health + (ingredients / 5));
                                   c2_health = c2.getHealth();
                                   c2.setHealth(c2_health + (ingredients / 5));
                                   c3_health = c3.getHealth();
                                   c3.setHealth(c3_health + (ingredients / 5));
                                   c4_health = c4.getHealth();
                                   c4.setHealth(c4_health + (ingredients / 5));
                                   if (p.getHealth() > 50){
                                        p.setHealth(50);
                                    }
                                    if (c1.getHealth() > 50){
                                        c1.setHealth(50);
                                    }
                                    if (c2.getHealth() > 50){
                                        c2.setHealth(50);
                                    }
                                    if (c3.getHealth() > 50){
                                        c3.setHealth(50);
                                    }
                                    if (c4.getHealth() > 50){
                                        c4.setHealth(50);
                                    }
                                   cout << "Cooking successful!" << endl;
                                   cout << "Ingredients left: " << ingredients << endl;
                                   cout << player_name << " | Fullness: " << p.getHealth() << "\n| " << comp1_name << " | Fullness: "<< c1.getHealth() << "\n| " << comp2_name << " | Fullness: "<< c2.getHealth() << "\n| " << comp3_name << " | Fullness: "<< c3.getHealth() << "\n| " << comp4_name << " | Fullness: "<< c4.getHealth() << endl;   
                                }
                                else{
                                    pot -= 1;
                                    cout << "Cooking unsuccessful" << endl;
                                   cout << "Ingredients left: " << ingredients << endl;
                                   cout << player_name << " | Fullness: " << p.getHealth() << "\n| " << comp1_name << " | Fullness: "<< c1.getHealth() << "\n| " << comp2_name << " | Fullness: "<< c2.getHealth() << "\n| " << comp3_name << " | Fullness: "<< c3.getHealth() << "\n| " << comp4_name << " | Fullness: "<< c4.getHealth() << endl;
                                }
                            }
                            break;
                        case 'f':
                            if (pan >= 1){
                                ingredients -= cooking;
                                a = rand()%10 + 1;
                                if (a != 1){
                                   p_health = p.getHealth();
                                   p.setHealth(p_health + (ingredients / 5));
                                   c1_health = c1.getHealth();
                                   c1.setHealth(c1_health + (ingredients / 5));
                                   c2_health = c2.getHealth();
                                   c2.setHealth(c2_health + (ingredients / 5));
                                   c3_health = c3.getHealth();
                                   c3.setHealth(c3_health + (ingredients / 5));
                                   c4_health = c4.getHealth();
                                   c4.setHealth(c4_health + (ingredients / 5));
                                   if (p.getHealth() > 50){
                                        p.setHealth(50);
                                    }
                                    if (c1.getHealth() > 50){
                                        c1.setHealth(50);
                                    }
                                    if (c2.getHealth() > 50){
                                        c2.setHealth(50);
                                    }
                                    if (c3.getHealth() > 50){
                                        c3.setHealth(50);
                                    }
                                    if (c4.getHealth() > 50){
                                        c4.setHealth(50);
                                    }
                                   cout << "Cooking successful!" << endl;
                                   cout << "Ingredients left: " << ingredients << endl;
                                   cout << player_name << " | Fullness: " << p.getHealth() << "\n| " << comp1_name << " | Fullness: "<< c1.getHealth() << "\n| " << comp2_name << " | Fullness: "<< c2.getHealth() << "\n| " << comp3_name << " | Fullness: "<< c3.getHealth() << "\n| " << comp4_name << " | Fullness: "<< c4.getHealth() << endl;   
                                }
                                else{
                                    pan -= 1;
                                    cout << "Cooking unsuccessful" << endl;
                                    cout << "Ingredients left: " << ingredients << endl;
                                    cout << player_name << " | Fullness: " << p.getHealth() << "\n| " << comp1_name << " | Fullness: "<< c1.getHealth() << "\n| " << comp2_name << " | Fullness: "<< c2.getHealth() << "\n| " << comp3_name << " | Fullness: "<< c3.getHealth() << "\n| " << comp4_name << " | Fullness: "<< c4.getHealth() << endl;
                                }
                            }
                            break;
                        case 'c':
                            if (cauldron >= 1){
                                ingredients -= cooking;
                                a = rand()%50 + 1;
                                if (a != 1){
                                    p_health = p.getHealth();
                                    p.setHealth(p_health + (ingredients / 5));
                                    c1_health = c1.getHealth();
                                    c1.setHealth(c1_health + (ingredients / 5));
                                    c2_health = c2.getHealth();
                                    c2.setHealth(c2_health + (ingredients / 5));
                                    c3_health = c3.getHealth();
                                    c3.setHealth(c3_health + (ingredients / 5));
                                    c4_health = c4.getHealth();
                                    c4.setHealth(c4_health + (ingredients / 5));
                                    if (p.getHealth() > 50){
                                        p.setHealth(50);
                                    }
                                    if (c1.getHealth() > 50){
                                        c1.setHealth(50);
                                    }
                                    if (c2.getHealth() > 50){
                                        c2.setHealth(50);
                                    }
                                    if (c3.getHealth() > 50){
                                        c3.setHealth(50);
                                    }
                                    cout << "Cooking successful!" << endl;
                                    cout << "Ingredients left: " << ingredients << endl;
                                    cout << player_name << " | Fullness: " << p.getHealth() << "\n| " << comp1_name << " | Fullness: "<< c1.getHealth() << "\n| " << comp2_name << " | Fullness: "<< c2.getHealth() << "\n| " << comp3_name << " | Fullness: "<< c3.getHealth() << "\n| " << comp4_name << " | Fullness: "<< c4.getHealth() << endl;   
                                }
                                else{
                                    cauldron -= 1;
                                    cout << "Cooking unsuccessful" << endl;
                                    cout << "Ingredients left: " << ingredients << endl;
                                    cout << player_name << " | Fullness: " << p.getHealth() << "\n| " << comp1_name << " | Fullness: "<< c1.getHealth() << "\n| " << comp2_name << " | Fullness: "<< c2.getHealth() << "\n| " << comp3_name << " | Fullness: "<< c3.getHealth() << "\n| " << comp4_name << " | Fullness: "<< c4.getHealth() << endl;
                                }
                            }
                            break;
                    }
                }
                break;
            case 5:
                cout << "You have decided to give up. Better luck next time." << endl;
                r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                return 0;
            default:
                cout << "Please enter a valid input." << endl;
        }
        if (action_choice == 2 || action_choice == 3 || action_choice == 4){
            a = rand()%10 + 1;
            if (a <= 4){
                b = rand()%10 + 1;
                if (b <= 3){
                    cout << "Misfortune. Your team has been robbed!" << endl;
                    c = rand()%3 + 1;
                    if (c == 1){
                        ingredients -= 10;
                    }
                    else if (c == 2){
                        if (pot > 0){
                            pot -= 1;
                            cout << "Misfortune. You've lost a pot!" << endl;
                        }
                        else if (pan > 0){
                            pan -= 1;
                            cout << "Misfortune. You've lost a pan!" << endl;
                        }
                    }
                    else{
                        cout << "Misfortune. You have lost an armor!" << endl;
                        if (armor > 0){
                            armor-=1;
                        }
                    }
                }
                else if (b == 4){
                    if (armor > 0){
                        armor -= 1;
                        cout << "Misfortune, you have lost one armor." << endl;
                    }
                    else if (club > 0){
                        club -= 1;
                        cout << "Misfortune, you have lost one club." << endl;
                    }
                }
                else if (b >= 5 && b <= 7){
                    b = rand()%4 + 1;
                    switch(b){
                        case 1:
                            if (c1.getHealth() > 10){
                                c1.setHealth(c1.getHealth() - 10);
                            }
                            else{
                                cout << comp1_name << " has died" << endl;
                                c1.setHealth(0);
                                c1.setAlive(false);
                            }
                            break;
                        case 2:
                            if (c2.getHealth() > 10){
                                c2.setHealth(c2.getHealth() - 10);
                            }
                            else{
                                cout << comp2_name << " has died" << endl;
                                c2.setHealth(0);
                                c2.setAlive(false);
                            }
                            break;
                        case 3:
                            if (c3.getHealth() > 10){
                                c3.setHealth(c3.getHealth() - 10);
                            }
                            else{
                                cout << comp3_name << " has died" << endl;
                                c3.setHealth(0);
                                c3.setAlive(false);
                            }
                            break;
                        case 4:
                            if (c4.getHealth() > 10){
                                c4.setHealth(c4.getHealth() - 10);
                            }
                            else{
                                cout << comp4_name << " has died" << endl;
                                c4.setHealth(0);
                                c4.setAlive(false);
                            }
                            break;
                    }
                }
                else{
                    if (room_choice == 2 && keys > 0){
                        cout << "Your teammate has gotten trapped in a room. " << endl;
                        b = rand()%4 + 1;
                        switch(b){
                            case 1:
                                if (c1.getHealth() > 10){
                                    c1.setHealth(c1.getHealth() - 10);
                                }
                                else{
                                    cout << comp1_name << " has died" << endl;
                                    c1.setHealth(0);
                                    c1.setAlive(false);
                                }
                                break;
                            case 2:
                                if (c2.getHealth() > 10){
                                    c2.setHealth(c2.getHealth() - 10);
                                }
                                else{
                                    cout << comp2_name << " has died" << endl;
                                    c2.setHealth(0);
                                    c2.setAlive(false);
                                }
                                break;
                            case 3:
                                if (c3.getHealth() > 10){
                                    c3.setHealth(c3.getHealth() - 10);
                                }
                                else{
                                    cout << comp3_name << " has died" << endl;
                                    c3.setHealth(0);
                                    c3.setAlive(false);
                                }
                                break;
                            case 4:
                                if (c4.getHealth() > 10){
                                    c4.setHealth(c4.getHealth() - 10);
                                }
                                else{
                                    cout << comp4_name << " has died" << endl;
                                    c4.setHealth(0);
                                    c4.setAlive(false);
                                }
                    }
                }
                }
            break;
        }
        }
        if (c1.getHealth() <= 0){
            cout << comp1_name << " has died of hunger." << endl;
            c1.setAlive(false);
            c1.setHealth(0);
        }
        if (c2.getHealth() <= 0){
            cout << comp2_name << " has died of hunger." << endl;
            c2.setAlive(false);
            c2.setHealth(0);
        }
        if (c3.getHealth() <= 0){
            cout << comp3_name << " has died of hunger." << endl;
            c3.setAlive(false);
            c3.setHealth(0);
        }
        if (c4.getHealth() <= 0){
            cout << comp4_name << " has died of hunger." << endl;
            c4.setAlive(false);
            c4.setHealth(0);
        }
        if (c1.getAlive() == false && c2.getAlive() == false && c2.getAlive() == false && c4.getAlive() == false){
                cout << "You do not have enough people to finish the game. You lose!" << endl;
                r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                return 0;
        }
        
        turns++;
    }

if (rooms == 5 && p.getPlayerAlive()){
    // battle the sorcerer extra credit
    cout << "You now have to battle the sorcerer to win the game! Phase 1 starts now." << endl;
    cout << "You must beat the sorcerer in a game of Rock, Paper, Scissors" << endl;
    cout << "Enter your move (r, p, s)" << endl;
    cin >> rps_choice;
    a = rand()%3 + 1;
    if (a == 1){
        door_choice = 'r';
    }
    if (a == 2){
        door_choice = 'p';
    }
    if (a == 3){
        door_choice = 's';
    }
    if (rps_choice == door_choice || (rps_choice == 's' && door_choice == 'r') || (rps_choice == 'r' && door_choice == 'p') || (rps_choice == 'p' && door_choice == 's')){
        cout << "You've lost! The sorcerer has killed you and your remaining party member(s). Game over" << endl;
        r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
        r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
        return 0;
    }
    else{
        cout << "You have won! You will now move on to Phase 2." << endl;
        cout << "I will pick a random number between 1 and 10. You and the sorcerer will choose numbers between 1 and 10. Whoever is closest, wins phase 2." << endl;
        cin >> a;
        b = rand()%10 + 1;
        c = rand()%10 + 1;
        if (abs(c - a) > abs(c - b)){
            cout << "You've lost! The sorcerer has killed you and your remaining party member(s). Game over" << endl;
            r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
            r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
            return 0;
        }
        else{
            cout << "You have won! You will now move on to Phase 3 and battle the sorcerer." << endl;
            cout << "Do you want to Fight (y/n)" << endl;
            cin >> ans;
            if (ans == 'y'){
                a = 1;
                if (c1.getAlive()){
                    a++;
                }
                if (c2.getAlive()){
                    a++;
                }
                if (c3.getAlive()){
                    a++;
                }
                if (c4.getAlive()){
                    a++;
                }
                b = (p.getHealth() + c1.getHealth() + c2.getHealth() + c3.getHealth() + c4.getHealth() + armor) / a;
                if (b > 20){
                    cout << "You've beat the sorcerer and won the game. Congrats! Hope to see you again soon :)" << endl;
                    r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                    r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                    return 0;
                }
                else{
                    cout << "You've lost! The sorcerer has killed you and your remaining party member(s). Game over" << endl;
                    r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                    r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                    return 0; 
                }
            }
            else{
                cout << "You've decided to surrender and have lost the game. Better luck next time." << endl;
                r.writeResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                r.readResults("results.txt", rooms, gold, ring, bracelet, necklace, circlet, goblet, spaces, num_monsters, turns, c1, c2, c3, c4, p);
                return 0;
            }
        }
    }
}
}



