//------------------------------------------------------------------
// Possessions.h
//
//  class for a player possessions object for programming 
//   assignment 3.
// Author: Adam Johnson
//------------------------------------------------------------------
#pragma once
#include "Possessions.h"
#include "Character.h"
#include <cstring>
#include <iostream>
#include <string.h>

Possessions::Possessions()
{
	m_pRoot = nullptr;
}
Possessions::~Possessions()
{
	destroyTree(m_pRoot);
}


bool Possessions::addItem(Item* newItem)
{
	return Insert(m_pRoot, newItem);
}

bool Possessions::Insert(Item*& tree, Item* newItem)
{
	if (tree == nullptr)
	{
		tree = newItem;
		return true;
	}
	int compare = (strcmp(newItem->m_sItemName, tree->m_sItemName));
	if (compare < 0)
	{
		return Insert(tree->m_pLeft, newItem);
	}
	if(compare > 0)
	{
		return Insert(tree->m_pRight, newItem);
	}

	if (compare == 0)
	{
		return false;
	}
	return 0;
}



Item* Possessions::dropItem(char* itemName)
{
	return Delete(m_pRoot, itemName);
}

Item* Possessions::Delete(Item*& tree, char* itemName)
{
	Item* temp=nullptr, *delNode=nullptr, *back = nullptr;
	if (!tree)
	{
		return nullptr;
	}
	int comp = strcmp(tree->m_sItemName, itemName);
	if (comp < 0) {
		return Delete(tree->m_pLeft, itemName);
	}
	if (comp > 0) {
		return Delete(tree->m_pRight, itemName);
	}
	if (comp == 0) {
		delNode = tree;
		temp = tree->m_pLeft;
	}
	if (temp) {
		if (tree->m_pRight) {
			while (temp->m_pRight) {
				back = temp;
				temp = temp->m_pRight;
			}
		}
	}
	if (back) {
		back->m_pRight = temp->m_pLeft;
		temp->m_pLeft = tree->m_pLeft;
		temp->m_pRight = tree->m_pRight;
		tree = temp;
	}
	else {
		tree = tree->m_pRight;
	}
	delNode=nullptr;
	return delNode;
}


Item* Possessions::Retrieve(Item*& tree, char* itemName)
{
	if (tree == nullptr) {
		return nullptr;
	}
	int compare = (strcmp(itemName, tree->m_sItemName));
		if (compare < 0)
		{
			return Retrieve(tree->m_pLeft, itemName);
		}
		if (compare > 0)
		{
			return Retrieve(tree->m_pRight, itemName);
		}
		if (compare == 0)
		{
			return nullptr;
		}
		return 0;
}
Item* Possessions::getItem(char* itemName)
{
	return Retrieve(m_pRoot, itemName);
}

void Possessions::printTree()
{
	printAll(m_pRoot);
}
void Possessions::printOne(Item* item)
{
	cout << item->m_sItemName << "\t\t" << item->m_dValue << "\t\t"
		<< item->m_dWeight << "\t\t" << item->m_iType << "\t\t" << endl;

	cout << "PrintOne succeeded." << endl;
}
void Possessions::destroyTree(Item* rt)
{
	if (rt != nullptr)
	{
		destroyTree(rt->m_pLeft);
		destroyTree(rt->m_pRight);
		delete rt;
	}
}
void Possessions::printAll(Item* rt)
{
	if (rt != nullptr)
	{
		printAll(rt->m_pLeft);
		printAll(rt);
		printAll(rt->m_pRight);
	}
}