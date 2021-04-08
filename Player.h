#pragma once

#include "Hand.h"
#include <string>

class Player
{

public:
	Player();
	bool isHitting() const;
	void Win() const;
	void Lose() const;
	Hand m_playerHand;

};

