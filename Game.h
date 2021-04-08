#pragma once
#include "Deck.h"
#include "Player.h"
#include "House.h"
class Game
{
public:
	Game();
	virtual void Play() = 0;
protected:
	Deck gameDeck;
	Player player;
	House house;


};

