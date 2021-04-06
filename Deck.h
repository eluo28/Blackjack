#pragma once
#include "Hand.h"
class Deck
{

public:
	Deck();
	void Populate();
	void Shuffle();

	void Deal(Hand& hand);

};

