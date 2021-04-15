#include "BlackjackController.h"


BlackjackController::BlackjackController() {

}

int BlackjackController::GetHandValue(Hand targetHand) {

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

void BlackjackController::Play() {

	bool playAgain = true;
	view.Introduction();

	while (playAgain) {
		Round();
		playAgain = view.AskForRound();
	}



}

void BlackjackController::Round() {
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
	view.ShowPlayerHand(&house, GetHandValue(house.m_playerHand));
	view.ShowPlayerHand(&player, GetHandValue(player.m_playerHand));




	//ask player to hit until he don't want to no more
	while (player.isHitting()) {
		gameDeck.Deal(player);

		view.ShowPlayerHand(&player, GetHandValue(player.m_playerHand));

	}

	//check if player busted
	if (GetHandValue(player.m_playerHand) > 21) {
		view.PlayerBusted();
		return;
	}


	//update house hand according to game rules
	house.m_playerHand.FlipFirstCard();

	while (GetHandValue(house.m_playerHand) < 17) {
		gameDeck.Deal(house);
	}

	view.ShowPlayerHand(&house, GetHandValue(house.m_playerHand));


	//get final result for round
	if (GetHandValue(house.m_playerHand) > 21) {
		view.HouseBusted();
		return;
	}
	else if (GetHandValue(house.m_playerHand) < GetHandValue(player.m_playerHand)) {
		view.PlayerWins();


	}
	else if (GetHandValue(house.m_playerHand) > GetHandValue(player.m_playerHand)) {
		view.PlayerLoses();

	}
	else {
		view.PlayerTies();


	}

	house.m_playerHand.Clear();
	player.m_playerHand.Clear();

}
