//------------------------------------------------------------------
// CharacterList.cpp
//
// Implementation file for the list of characters players for  
//   programming assignment 2.
// Author: Adam Johnson
//------------------------------------------------------------------
#include "CharacterList.h"
#include <stdio.h> 
#include <string>
using namespace std;
//-----------------------------------------------
// Class constructor
//-----------------------------------------------
CharacterList::CharacterList()
{
	m_pHead = NULL;
}
//-----------------------------------------------
// Class destructor
//-----------------------------------------------
CharacterList::~CharacterList()
{
	Character* temp;
	temp = m_pHead;
	while (temp != nullptr)
	{
		delete m_pHead;
		m_pHead = temp;
	}
}
//-----------------------------------------------
// Add a character to the list of characters.
// This is an unsorted list so we will just add
//   the character at the m_pHead of the list.
//-----------------------------------------------
bool CharacterList::addCharacter(Character* newCharacter)
{
	Character* temp, * back;
	temp = m_pHead;
	back = nullptr;
	if (m_pHead == nullptr) // Add as first in the list
	{
		m_pHead = newCharacter;
		return true;
	}
	// Find location to insert new player into
	while ((temp != nullptr) && (strcmp(temp->getName(), newCharacter->getName()) <
		0))
	{
		back = temp;
		temp = temp->m_pNext;
	}
	if (back == nullptr) // Add at m_pHead of list
	{
		newCharacter->m_pNext = m_pHead;
		m_pHead = newCharacter;
	}
	else // Insert elsewhere in the list
	{
		newCharacter->m_pNext = temp;
		back->m_pNext = newCharacter;
	}
	return true;
}
//-----------------------------------------------
// Delete a character from the list of characters
//-----------------------------------------------
Character* CharacterList::deleteCharacter(char* playerName)
{
	Character* temp, * back;
	if (m_pHead == nullptr) return nullptr; // Nothing to delete
	back = nullptr;
	temp = m_pHead;
	while ((temp != nullptr) && (strcmp(temp->getName(), playerName) != 0))
	{
		back = temp;
		temp = temp->m_pNext;
	}
	if (temp == nullptr)
	{
		return nullptr;
	}
	else if (back == nullptr)
		m_pHead = temp->m_pNext;
	else
		back->m_pNext = temp->m_pNext;
	return temp;
}
//-----------------------------------------------
// Add an item to a character's list of items.
//-----------------------------------------------
bool CharacterList::addItem(char* playerName, Item* newItem)
{
	Character* temp;
	//Find the player
	temp = m_pHead;
	while ((temp != nullptr) && (strcmp(temp->getName(), playerName) != 0))
	{
		temp = temp->m_pNext;
	}
	if (temp != nullptr)
		return temp->addItem(newItem);
	else
		return false;
}
//-----------------------------------------------
// Get an item in a character's list of items.
//-----------------------------------------------
Item* CharacterList::getItem(char* playerName, char* itemName)
{
	Character* temp;
	//Find the player
	temp = m_pHead;
	while ((temp != nullptr) && (strcmp(temp->getName(), playerName) != 0))
	{
		temp = temp->m_pNext;
	}
	if (temp != nullptr)
		return temp->getItem(itemName);
	else
		return nullptr;
}
//-----------------------------------------------
// Delete an item from a character's list of items.
//-----------------------------------------------
Item* CharacterList::dropItem(char* playerName, char* itemName)
{
	Character* temp;
	//Find the player
	temp = m_pHead;
	while ((temp != nullptr) && (strcmp(temp->getName(), playerName) != 0))
	{
		temp = temp->m_pNext;
	}
	if (temp != nullptr)
		return temp->dropItem(itemName);
	else
		return nullptr;
}
//-----------------------------------------------
// Print the list of players and all their items.
//-----------------------------------------------
void CharacterList::printCharacters()
{
	Character* temp;
	temp = m_pHead;
	cout << "================================================================\n";
	cout << "           DEMONSTRATION, PROGRAMMING ASSIGNMENT 3\n";
	cout << "================================================================\n";
	cout << "  Character\tClass\tAlign\tHitPts\tCharacter Traits\n";
	cout << "----------------------------------------------------------------\n";
	while (temp != nullptr)
	{
		temp->printAll();
		temp = temp->m_pNext;
	}
}
