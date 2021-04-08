#pragma once
#include "Game.h"
#include "Hand.h"
class Blackjack :
    public Game
{

public:
    Blackjack();
    virtual void Play();

private:
    int GetHandValue(Hand targetHand);
    void Introduction();
    void Round();
};

