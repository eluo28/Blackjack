#include "Blackjack.h"


int main() {

	Blackjack blackjack;
	std::string name;
	char gameChoice;
	bool again = true;

	std::cout << "Welcome to my Casino!\n\n";

	std::cout << "What is your name?\n\n";
	std::cin >> name;

	std::cout << "\nHello " << name<<"!\n\n";

	while (again) {
		std::cout << "Which game would you like to play?\n\nb for Blackjack\nq to quit\n\n";
		std::cin >> gameChoice;
		std::cout << "\n";
		switch (gameChoice) {
		case 'b':
			blackjack.Play();
			break;
		case'q':
			again = false;
			break;
		default:
			std::cout << "That's not a valid choice!\n\n";
		}
	}

	std::cout << "Goodbye!\n";

	return 0;
}

