#pragma once
#include "Hand.h"
#include "Player.h"
#include <vector>
class Deck
{

public:
	static constexpr unsigned DECK_SIZE{ 52 };
	Deck();
	~Deck();
	void Populate();
	void Shuffle();
	void Clear();
	void Deal(Player& player);
	void AddCard(Card* card);
	void PrintDeck();

private:
	std::vector<Card*> m_deck;
};

