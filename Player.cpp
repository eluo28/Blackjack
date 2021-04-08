#include "Player.h"
#include "Deck.h"
#include <iostream>

Player::Player() {

}

bool Player::isHitting() const {
    char response;
    std::cout << "Do you want a hit? (Y/N): ";
    
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}
void Player::Win() const {
    std::cout << "You won!\n";
}
void Player::Lose() const {
    std::cout << "You lost.\n";
}

