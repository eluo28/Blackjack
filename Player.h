#pragma once

#include "Hand.h"
#include <string>

class Player
{

public:
	Player(std::string name = "Player");
	bool isHitting() const;
	virtual std::string getName();
	Hand m_playerHand;
	std::string m_name;

};

