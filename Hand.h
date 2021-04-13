#pragma once
#include "Card.h"
#include <iostream>
#include <vector>

class Hand
{

public:
	Hand();
	~Hand();
	void AddCard(Card* card);
	void FlipFirstCard();
	void PrintHand();
	void Clear();
	std::vector<Card*> m_hand;
};

