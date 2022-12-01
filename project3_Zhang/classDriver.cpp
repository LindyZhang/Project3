// CSCI 1300 Fall 2022
// Author: Lindy Zhang
// Recitation 303 - Xuefei Sun
// Project 3 - classDriver.cpp
// Partner: Dylan Teeples
#include <iostream>
#include "Armor.h"
#include "Cookware.h"
#include "Companion.h"
#include "Party.h"
#include "Player.h"
#include "Treasure.h"
#include "Weapon.h"
#include <cassert>
using namespace std;

int main(){
    // test for armor class functions
    Armor armor;
    assert(armor.getArmorCost() == 0);
    assert(armor.getWorking() == true);
    armor.setArmorCost(10);
    armor.setWorking(false);
    assert(armor.getArmorCost() == 10);
    assert(armor.getWorking() == false);

    Armor armor1(6, false);
    assert(armor1.getArmorCost() == 6);
    assert(armor1.getWorking() == false);

    // test for cookware class functions
    Cookware cookware;
    assert(cookware.getCookware() == ' ');
    assert(cookware.getRooms() == 0);
    assert(cookware.getCondition() == 100);
    cookware.setCookware('P');
    cookware.setRooms(2);
    cookware.setCondition(50);
    assert(cookware.getCookware() == 'P');
    assert(cookware.getRooms() == 2);
    assert(cookware.getCondition() == 50);

    Cookware cookware1('F', 3, 90);
    assert(cookware1.getCookware() == 'F');
    assert(cookware1.getRooms() == 3);
    assert(cookware1.getCondition() == 90);

    assert(cookware1.newCookwareCost(cookware1.getCookware(), cookware1.getRooms()) == 17);

    // test for companion class functions
    Companion companion;
    assert(companion.getHealth() == 50);
    cout << companion.getName() << endl;
    // expected output: ""
    assert(companion.getAlive() == true);
    companion.setHealth(0);
    companion.setName("Dylan");
    companion.setAlive(false);
    assert(companion.getHealth() == 0);
    cout << companion.getName() << endl;
    // expected output: "Dylan"
    assert(companion.getAlive() == false);

    Companion companion1(12, "Blue", true);
    assert(companion1.getHealth() == 12);
    assert(companion1.getAlive() == true);
    cout << companion1.getName() << endl;
    // expected output: "Blue"

    // test for party class
    Party party;
    assert(party.getGold() == 100);
    assert(party.getIngredients() == 0);
    assert(party.getArmor() == 0);
    party.setGold(82);
    party.setIngredients(30);
    party.setArmor(4);
    assert(party.getGold() == 82);
    assert(party.getIngredients() == 30);
    assert(party.getArmor() == 4);
    party.getWeapons();
    // expected output: 
    /**
     * 0
     * 0
     * 0
     * 0
     * 0
     */
    party.getTreasures();
    /**
     * 0
     * 0
     * 0
     * 0
     * 0
     */
    party.getCookware();
    /**
     * 0
     * 0
     * 0
     */
    int arr[5] = {1, 1, 1, 0, 1};
    party.setWeapons(arr);
    party.getWeapons();
    /**
     * 1
     * 1
     * 1
     * 0
     * 1
     */
    int arr1[3] = {1, 2, 3};
    party.setCookware(arr1);
    party.getCookware();
    /**
     * 1
     * 2
     * 3
     */
    int arr2[5] = {1, 1, 0, 1, 1};
    party.setTreasures(arr2);
    party.getTreasures();
    /**
     * 1
     * 1
     * 0
     * 1
     * 1
     */
    int arr3[5] = {1, 1, 1, 1, 1};
    int arr4[3] = {1, 2, 2};
    int arr5[5] = {1, 2, 0, 0, 2};
    Party party1(12, 30, 4, arr3, arr4, arr5);
    assert(party1.getGold() == 12);
    assert(party1.getIngredients() == 30);
    assert(party1.getArmor() == 4);
    party1.getWeapons();
    /**
     * 1
     * 1
     * 1
     * 1
     * 1
     */
    party1.getCookware();
    /**
     * 1
     * 2
     * 2
     */
    party1.getTreasures();
    /**
     * 1
     * 2
     * 0
     * 0
     * 2
     */

    // test for player class
    Player player;
    assert(player.getHealth() == 50);
    assert(player.getPlayerAlive() == true);
    player.getPlayerName();
    // expected output: ""
    player.setHealth(0);
    player.setPlayerAlive(false);
    player.setPlayerName("Red");
    assert(player.getHealth() == 0);
    assert(player.getPlayerAlive() == false);
    cout << player.getPlayerName() << endl;
    //expected output: "Red"

    Player player1("Orange", 12, true);
    assert(player1.getHealth() == 12);
    assert(player1.getPlayerAlive() == true);
    cout << player1.getPlayerName() << endl;;
    // expected output: "Orange"

    // test for treasure class
    Treasure treasure;
    assert(treasure.getRooms() == 0);
    treasure.setRooms(3);
    assert(treasure.getRooms() == 3);

    Treasure treasure1(4);
    assert(treasure1.getRooms() == 4);
    assert(treasure1.newTreasureCost(treasure1.getRooms()) == 40);

    // test for weapon class
    Weapon weapon;
    assert(weapon.getWeaponName() == ' ');
    assert(weapon.getRooms() == 0);
    weapon.setWeaponName('C');
    weapon.setRooms(2);
    assert(weapon.getWeaponName()== 'C');
    assert(weapon.getRooms() == 2);

    Weapon weapon1('L', 2);
    assert(weapon1.getWeaponName() == 'L');
    assert(weapon1.getRooms() == 2);
    assert(weapon1.newCost(weapon1.getWeaponName(), weapon1.getRooms()) == 75);


}