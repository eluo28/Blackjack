#pragma once
#include "Card.h"
#include <iostream>
#include <vector>

class Hand
{

public:
	Hand();
	void AddCard(Card* card);
	void Clear();
protected:
	std::vector<Card*> m_cards;
};

