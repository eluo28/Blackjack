#pragma once
#include "Game.h"
#include "Hand.h"
#include "BlackjackView.h"

class BlackjackController:
    public Game
{

public:
    BlackjackController();
    virtual void Play();

private:
    int GetHandValue(Hand targetHand);
    void Round();
    BlackjackView view;
};

