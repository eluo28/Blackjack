#pragma once
#include "Player.h"
class House :
    public Player
{

public:
    House(std::string name = "House");
    std::string getName();
    void InitialDraw();
    std::string m_name;
};

