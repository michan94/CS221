// Make random number
// "What is your guess?"
// std::cin guess
// If right
//	"Congratulations!"
// If wrong
//	"Better luck next time!"
//	"Try again?"
//	If yes
//		cin
//	If no
//		end				

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void) {
	int randNum;
	int guess;
	string continueOn;
	srand (time(NULL));
	randNum = 1 + (rand() % (int)(100));
	cout << randNum << endl;
	do {
		cout << "What is your guess?" << endl;
		cin >> guess;
		if (guess != randNum) {
			cout << "Try again? (y/n)" << endl;
			cin >> continueOn; 
		}
		else {
			cout << "You guess it right!" << endl;
		}
	}
	while (continueOn.compare("y") == 0 && guess != randNum);
	cout << "Thank you for playing" << endl;
	return 0;
} 


