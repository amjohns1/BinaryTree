//------------------------------------------------------------------
// Character.h
//
// Header file for a player character object for programming 
//   assignment 3.
// Author: Adam Johnson
//------------------------------------------------------------------
#pragma once
#include <iostream>
#include "Item.h"
#include "Possessions.h"
using namespace std;
class Character
{
private:
    char        m_sName[65];
    int         m_iClass;
    int         m_iAlignment;
    int         m_iHitPoints;
    int         m_iCharTraits[6]; // Strength, Dexterity, Constitution, 
                            // Intelligence, Wisdom, Charisma
    Possessions* m_pBattleItems;
    Possessions* m_pTreasureItems;
public:
    Character* m_pNext;
    Character();                      // Class constructor
    Character(char* name, int Class, int Alignment, int HitPoints, int Strength,
        int Dexterity, int Constitution, int Intelligence, int Wisdom,
        int Charisma);
    ~Character();                     // Class destructor
    char* getName();                  // Get the player's name
    void setName(char* name);         // Set the player's name
    int getClass();                   // Get the player's class
    void setClass(int cl);            // Set the player's class
    int getAlignment();               // Get the player's alignment
    void setAlignment(int al);        // Set the player's alignment
    int getHitPoints();               // Get the player's class
    void setHitPoints(int hp);        // Set the player's class
    // Char traits get/set methods
    int getStrength();                // Get the player's Strength
    void setStrength(int str);        // Set the player's Strength
    int getDexterity();               // Get the player's Dexterity
    void setDexterity(int dex);       // Set the player's Dexterity
    int getConstitution();            // Get the player's Constitution
    void setConstitution(int cn);     // Set the player's Constitution
    int getIntelligence();            // Get the player's Intelligence
    void setIntelligence(int itl);    // Set the player's Intelligence
    int getWisdom();                  // Get the player's Wisdom
    void setWisdom(int wis);          // Set the player's Wisdom
    int getCharisma();                // Get the player's Charisma
    void setCharisma(int chr);        // Set the player's Charisma
    bool addItem(Item* item);         // Add an item to the list of items
    Item* getItem(char* itemName);    // Get a pointer to an item in the list
    Item* dropItem(char* itemName);   // Remove an item from the list of items
    void printAll();                  // Print everything about this character, 
  
        // class, alignment, hit points, all traits, 
};
