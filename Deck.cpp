#include "Deck.h"
#include <algorithm>
#include "Player.h"

Deck::Deck() {
	m_deck.reserve(DECK_SIZE);
	
}
Deck::~Deck() {
	Clear();
}


void Deck::Populate() {

	Clear();

	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
			AddCard(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s), false));
		}
	}

}

void Deck::PrintDeck() {
	for (std::vector<Card*>::iterator it = m_deck.begin(); it != m_deck.end(); ++it) {
		(*it)->PrintCard();
		std::cout << "\n";
	}
}


void Deck::AddCard(Card* card) {
	m_deck.push_back(card);
}

void Deck::Shuffle() {
	std::random_shuffle(m_deck.begin(), m_deck.end());
}

void Deck::Deal(Player& player) {


	if (!m_deck.empty()) {
		player.m_playerHand.AddCard(m_deck.back());
		m_deck.pop_back();
	}
	else {
		std::cout << "Out of cards. Unable to deal. ";
	}
}

void Deck::Clear()
{
	std::vector<Card*>::iterator iter = m_deck.begin();
	for (iter = m_deck.begin(); iter != m_deck.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	m_deck.clear();
}