#include "Player.h"
#include "Deck.h"
#include <iostream>

Player::Player() {

}

bool Player::isHitting() const {
    char response;
    std::cout << "Do you want a hit? (Y/N): ";
    
    std::cin >> response;
    std::cout << "\n";
    std::cout << "\n";
    return (response == 'y' || response == 'Y');
}

