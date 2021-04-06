#include "Blackjack.h"


int main() {

	Blackjack blackjack;
	std::string name;
	char gameChoice;
	bool again = true;

	std::cout << "Welcome to my Casino!\n\n";

	std::cout << "What is your name?\n";
	std::cin >> name;

	std::cout << "Hello " << name<<"!\n";

	while (again) {
		std::cout << "Which game would you like to play?\nb for Blackjack\nq to quit\n";
		std::cin >> gameChoice;

		switch (gameChoice) {
		case 'b':
			blackjack.Play();
			break;
		case'q':
			again = false;
			break;
		default:
			std::cout << "That's not a valid choice!";
		}
	}

	std::cout << "Goodbye!\n";

	return 0;
}

