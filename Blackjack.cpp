#include "Blackjack.h"


Blackjack::Blackjack() {

}

int Blackjack::GetHandValue(Hand targetHand) {
	

	return 10;
}

void Blackjack::Play() {
	
	bool playAgain = true;
	char response;
	Introduction();

	while (playAgain) {
		Round();
		std::cout << "Do you want to play another round? (Y/N)\n\n";


		std::cin >> response;
		std::cout << "\n";
		playAgain = (response == 'y' || response == 'Y');
	}

}

void Blackjack::Introduction() {
	std::cout << "Welcome to Blackjack!\n\n";

}

void Blackjack::Round() {
	gameDeck.Populate();
	gameDeck.Shuffle();

	//deal two cards to player and house
	for (int i = 0;i < 2;++i) {
		gameDeck.Deal(player);
		gameDeck.Deal(house);
	}

	//flip house first card
	house.m_playerHand.FlipFirstCard();


	//show hands
	std::cout << "House hand:\n";

	house.m_playerHand.PrintHand();
	std::cout << "Total: "<< GetHandValue(house.m_playerHand) <<"\n\n";


	std::cout << "\nPlayer hand:\n";
	player.m_playerHand.PrintHand();
	std::cout << "Total: " << GetHandValue(player.m_playerHand) << "\n\n";



	//ask player to hit


	

}

