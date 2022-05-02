//--------------------------------------------------------------------------
// Character.cpp
// Demonstration of programming assignment 1.  This class implements a
//   player character for a Dungeons and Dragons style adventure game.
// Author: Adam Johnson
//--------------------------------------------------------------------------
#pragma warning(disable:4996)
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <string.h> 
#pragma once

using std::cout;
using std::endl;

//-----------------------------------------------
// Default class constructor
//-----------------------------------------------
Character::Character()
{
	strcpy(m_sName, "");
	m_iClass = 0;
	m_iAlignment = 0;
	m_iHitPoints = 0;
	m_iCharTraits[0] = 0;
	m_iCharTraits[1] = 0;
	m_iCharTraits[2] = 0;
	m_iCharTraits[3] = 0;
	m_iCharTraits[4] = 0;
	m_iCharTraits[5] = 0;
	m_pBattleItems = new Possessions;
	m_pTreasureItems = new Possessions;
	m_pNext = nullptr;
	
}

Character::Character(char* name, int Class, int Alignment, int Hitpoints, int
	Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom,
	int Charisma)
{
	strcpy(m_sName, name);
	m_iClass = Class;
	m_iAlignment = Alignment;
	m_iHitPoints = Hitpoints;
	m_iCharTraits[0] = Strength;
	m_iCharTraits[1] = Dexterity;
	m_iCharTraits[2] = Constitution;
	m_iCharTraits[3] = Intelligence;
	m_iCharTraits[4] = Wisdom;
	m_iCharTraits[5] = Charisma;
	m_pBattleItems = new Possessions;
	m_pTreasureItems = new Possessions;
	m_pNext = nullptr;
	
}

Character::~Character()
{
}

char* Character::getName()
{
	return m_sName;
}

void Character::setName(char* name)
{
	strcpy(m_sName, name);
}

int Character::getClass()
{
	return m_iClass;
}

void Character::setClass(int cl)
{
	m_iClass = cl;
}

int Character::getAlignment()
{
	return m_iAlignment;
}
void Character::setAlignment(int al)
{
	m_iAlignment = al;
}
int Character::getHitPoints()
{
	return m_iHitPoints;
}

void Character::setHitPoints(int hp)
{
	m_iHitPoints = hp;
}

int Character::getStrength()
{
	return m_iCharTraits[0];
}

void Character::setStrength(int str)
{
	m_iCharTraits[0] = str;
}

int Character::getDexterity()
{
	return m_iCharTraits[1];
}

void Character::setDexterity(int dex)
{
	m_iCharTraits[1] = dex;
}

int Character::getConstitution()
{
	return m_iCharTraits[2];
}

void Character::setConstitution(int cn)
{
	m_iCharTraits[2] = cn;
}

int Character::getIntelligence()
{
	return m_iCharTraits[3];
}

void Character::setIntelligence(int itl)
{
	m_iCharTraits[3] = itl;
}

int Character::getWisdom()
{
	return m_iCharTraits[4];
}

void Character::setWisdom(int wis)
{
	m_iCharTraits[4] = wis;
}

int Character::getCharisma()
{
	return m_iCharTraits[5];
}

void Character::setCharisma(int chr)
{
	m_iCharTraits[5] = chr;
}
//-----------------------------------------------
// Add an item to the list of items
//-----------------------------------------------
bool Character::addItem(Item* item)
{
	// See if there is an empty place to hold this item
	if (item->m_iType == BATTLE_ITEM)
	{
		return m_pBattleItems->addItem(item);
	}
	else if (item->m_iType == TREASURE_ITEM)
	{
		return m_pTreasureItems->addItem(item);
	}
	else
	{
		return false;
	}
}

Item* Character::getItem(char* itemName)
{
	Item* temp;
	temp = m_pBattleItems->getItem(itemName);

	if (temp == nullptr)
	{
		temp = m_pBattleItems->getItem(itemName);
	}
	return temp;
}

Item* Character::dropItem(char* m_sItemName)
{
	// Search all items
	Item* temp;
	temp = m_pBattleItems->dropItem(m_sItemName);
	if (temp == nullptr)
	{
		temp = m_pTreasureItems->dropItem(m_sItemName);
	}
	return temp;
}
//-----------------------------------------------
// Print everything about this character
//-----------------------------------------------
void Character::printAll()
{
	int count = 0;
	cout << m_sName;
	if (strlen(m_sName) >= 8)
		cout << "\t";
	else
		cout << "\t\t";
	cout << m_iClass << "\t" << m_iAlignment << "\t" << m_iHitPoints << "\t" <<
		m_iCharTraits[0] << "  " << m_iCharTraits[1] << "  " <<
		m_iCharTraits[2] << "  " <<
		m_iCharTraits[3] << "  " << m_iCharTraits[4] << "  " <<
		m_iCharTraits[5] << "\n";
	cout << "\tItems carried: " << "\n";
	cout << m_pBattleItems << "\n" << m_pTreasureItems << endl;
}