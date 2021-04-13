#pragma once

#include "Hand.h"
#include <string>

class Player
{

public:
	Player();
	bool isHitting() const;

	Hand m_playerHand;

};

