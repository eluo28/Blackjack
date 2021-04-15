#pragma once
#include "Player.h"
class BlackjackView
{
public:
    void Introduction();
    bool AskForRound();
    void ShowPlayerHand(Player* player, int value);
    void PlayerBusted();
    void HouseBusted();
    void PlayerWins();
    void PlayerLoses();
    void PlayerTies();

};

