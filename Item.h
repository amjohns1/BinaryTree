//------------------------------------------------------------------
// Item.h
//
// Define the Item structure for use in programming assignment 3
// Author: Adam Johnson
//------------------------------------------------------------------
#pragma once
#define BATTLE_ITEM   1
#define TREASURE_ITEM 2
struct Item
{
    char    m_sItemName[65];
    char    m_sDesc[128];
    int     m_iType;
    double  m_dValue;
    double  m_dWeight;
    Item* m_pLeft;
    Item* m_pRight;
};