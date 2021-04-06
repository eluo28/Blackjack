#include "Card.h"

Card::Card(rank rank, suit suit, bool faceUp) {
	m_rank = rank;
	m_suit = suit;
	m_faceUp = faceUp;
}

int Card::GetValue() const {
	int value = 0;

	if (m_faceUp) {
		value = m_rank > 10 ? 10 : m_rank ; //if rank is face card value is 10
	}

	return value;
}

void Card::Flip()
{
	m_faceUp = !m_faceUp;
}