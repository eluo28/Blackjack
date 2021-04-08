#include "Card.h"
#include <iostream>


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


std::ostream& operator<<(std::ostream& os, const Card::rank& rank) {

	switch (rank) {
	case 1:
		os << "ACE";
		break;
	case 2:
		os << "TWO";
		break;
	case 3:
		os << "THREE";
		break;
	
	case 4:
		os << "FOUR";
		break;
	case 5:
		os << "FIVE";
		break;
	case 6:
		os << "SIX";
		break;
	case 7:
		os << "SEVEN";
		break;
	case 8:
		os << "EIGHT";
		break;
	case 9:
		os << "NINE";
		break;
	case 10:
		os << "TEN";
		break;
	case 11:
		os << "JACK";
		break;
	case 12:
		os << "QUEEN";
		break;
	case 13:
		os << "KING";
		break;
}
return os;

}

std::ostream& operator<<(std::ostream& os, const Card::suit& suit) {

	switch (suit) {
	case 0:
		os << "CLUBS";
		break;
	case 1:
		os << "DIAMONDS";
		break;
	case 2:
		os << "HEARTS";
		break;

	case 3:
		os << "SPADES";
		break;
	
	}
	return os;

}

void Card::PrintCard() {
	std::cout << m_rank << "\t" << m_suit << "\t" << m_faceUp << "\t";
}

