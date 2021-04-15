#include "BlackjackView.h"
#include <iostream>

void BlackjackView::Introduction() {
	std::cout << "Welcome to Blackjack!\n\n";

}

bool BlackjackView::AskForRound() {
	char response;

	std::cout << "\nDo you want to play another round? (Y/N)\n\n";


	std::cin >> response;
	std::cout << "\n";

	return (response == 'y' || response == 'Y');
}

void BlackjackView::ShowPlayerHand(Player *player, int value) {
	

	std::cout << player->getName()<< " hand:\n";
	player->m_playerHand.PrintHand();
	std::cout << "Total: " << value << "\n\n";

}

void BlackjackView::PlayerBusted() {
	std::cout << "You busted! You lose!\n";


}

void BlackjackView::HouseBusted() {
	std::cout << "House busted! You win!\n";
}

void BlackjackView::PlayerWins() {
	std::cout << "You win!\n";
}

void BlackjackView::PlayerLoses() {
	std::cout << "You lose!\n";
}

void BlackjackView::PlayerTies() {
	std::cout << "You tie!\n";
}


