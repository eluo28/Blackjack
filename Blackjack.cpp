#include "Blackjack.h"


Blackjack::Blackjack() {

}

int Blackjack::GetHandValue(Hand targetHand) {

	if (targetHand.m_hand.empty())
	{
		return 0;
	}
	int total = 0;
	std::vector<Card*>::const_iterator iter;
	for (iter = targetHand.m_hand.begin(); iter != targetHand.m_hand.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}

	
	bool containsAce = false;
	for (iter = targetHand.m_hand.begin(); iter != targetHand.m_hand.end(); ++iter)
	{
		if ((*iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}

	if (containsAce && total <= 11)
	{
		//add only 10
		total += 10;
	}
	return total;
}

void Blackjack::Play() {
	
	bool playAgain = true;
	char response;
	Introduction();

	while (playAgain) {
		Round();

		std::cout << "\nDo you want to play another round? (Y/N)\n\n";


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



	//ask player to hit until he don't want to no more
	while (player.isHitting()) {
		gameDeck.Deal(player);

		std::cout << "\nPlayer hand:\n";
		player.m_playerHand.PrintHand();
		std::cout << "Total: " << GetHandValue(player.m_playerHand) << "\n\n";
	}

	//check if player busted
	if (GetHandValue(player.m_playerHand) > 21) {
		std::cout << "You busted! You lose!\n";
		return;
	}


	//update house hand according to game rules
	house.m_playerHand.FlipFirstCard();

	while (GetHandValue(house.m_playerHand) < 17) {
		gameDeck.Deal(house);
	}

	std::cout << "House hand:\n";
	house.m_playerHand.PrintHand();
	std::cout << "Total: " << GetHandValue(house.m_playerHand) << "\n\n";


	//get final result for round
	if (GetHandValue(house.m_playerHand) > 21) {
		std::cout << "House busted! You win!\n";
		return;
	}
	else if (GetHandValue(house.m_playerHand) < GetHandValue(player.m_playerHand)) {
		std::cout << "You win!\n";

	}
	else if (GetHandValue(house.m_playerHand) > GetHandValue(player.m_playerHand)) {
		std::cout << "You lose!\n";

	}
	else {
		std::cout << "It's a tie!\n";

	}

	house.m_playerHand.Clear();
	player.m_playerHand.Clear();
	
}

