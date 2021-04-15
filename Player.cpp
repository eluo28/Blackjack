#include "Player.h"
#include "Deck.h"
#include <iostream>

Player::Player(std::string name) {
    m_name = name;
}

bool Player::isHitting() const {
    char response;
    std::cout << "Do you want a hit? (Y/N): ";
    
    std::cin >> response;
    std::cout << "\n";
    std::cout << "\n";
    return (response == 'y' || response == 'Y');
}

std::string Player::getName() {
    return m_name;
}