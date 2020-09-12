#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// to get a unique random int list:
vector<int> getRndNums();

// to activate the list:
void newGuess(vector<int>& rndNumsVec);

// to check for valid user input:
bool checkValidInput(string uInput);

int main() {
	
	vector<int> rndNumsVec;
	newGuess(rndNumsVec);

	// main loop:
	bool playAgain = true;
	int guesses = 1;
	while (playAgain) {
		// get user input:
		string uInput = "";
		cout << "\nEnter guess -- 4 non-repeating digits (for example 4567): ";
		cin >> uInput;

		// input vec:
		vector<int> inputVec;

		// turn user input into int vec:
		for (int i = 0; i < uInput.length(); i++) {
			inputVec.push_back((int)(uInput[i] - 48));
		}

		// validate input:
		if (checkValidInput(uInput)) {
			int cows = 0;
			int bulls = 0;

			// check for matches:
			for (int i = 0; i < inputVec.size(); i++) {
				for (int j = 0; j < rndNumsVec.size(); j++) {
					// if the ints match:
					if (inputVec[i] == rndNumsVec[j]) {
						// if in same location, bull:
						if (i == j) {
							bulls++;
						}
						// if in different locations, cow:
						else {
							cows++;
						}
					}
				}
			}
			// display result:
			cout << "Guess #" << guesses << ": Bulls " << bulls << " Cows " << cows << "\n";
			
			// if player has won:
			if (bulls == 4) {
				cout << "\n*** YOU WIN ***\n";

				// ask to play again:
				char yOn = ' ';
				cout << "\nPlay again? (y/n): ";
				cin >> yOn;
				if (yOn == 'y') {
					// reset guess number:
					cout << '\n';
					newGuess(rndNumsVec);
				}
				// if they don't wanna play again, exit loop:
				else {
					playAgain = false;
				}
			}
			// if they didn't win, increase guess #:
			else {
				guesses++;
			}
		}
	}
	return 0;
}

vector<int> getRndNums() {
	// random vec:
	vector<int> rndNumsVec;
	// seed random with current time:
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
	retry:
		// get random num between 0 and 10:
		int rndNum = rand() % 10;
		// if first iteration:
		if (i == 0) {
			rndNumsVec.push_back(rndNum);
		}
		else {
			// check for duplicates:
			bool dup = false;
			for (int j = 0; j < rndNumsVec.size(); j++) {
				if (rndNum == rndNumsVec[j]) {
					dup = true;
				}
			}
			// if no dups:
			if (!dup) {
				// add rndNum:
				rndNumsVec.push_back(rndNum);
			}
			// if yes dups:
			else {
				// restart process:
				goto retry;
			}
		}
	}
	// return result after all values are unique:
	return rndNumsVec;
}

void newGuess(vector<int>& rndNumsVec) {
	// random vec:
	rndNumsVec = getRndNums();

	// display number to guess:
	cout << "Number to Guess is ";
	for (int i = 0; i < rndNumsVec.size(); i++) {
		cout << rndNumsVec[i];
	}
	cout << '\n';
}

bool checkValidInput(string uInput) {
	// check length:
	if (uInput.length() != 4) {
		cout << "Error:\tGuess must be 4 digits\n";
		return false;
	}
	// check for ints:
	for (int i = 0; i < uInput.length(); i++) {
		if (uInput[i] < '0' || uInput[i] > '9') {
			cout << "Error:\tGuess must be 4 digits\n";
			return false;
		}
	}
	// check for dups:
	bool dup = false;
	for (int i = 0; i < uInput.length(); i++) {
		for (int j = 0; j < uInput.length(); j++) {
			if (uInput[i] == uInput[j] && i != j) {
				dup = true;
			}
		}
	}
	if (dup) {
		cout << "Error:\tDigits cannot be repeated\n";
		return false;
	}
	return true;
}