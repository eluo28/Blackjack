#pragma once
class Card
{

public:
	enum rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};

	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	Card(rank rank, suit suit, bool faceUp);

	int GetValue() const;

	void Flip();

private:
	rank m_rank;
	suit m_suit;
	bool m_faceUp;
};
