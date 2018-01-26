/* Josiah Turnquist
 * Jan 25, 2018
 * Highly efficient sorting machine
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
//#define WINVER 0x0502
#include <windows.h>

using namespace std;

int main() {
	srand(time(0)); // Random Seed
	
	const int arrayMax = 50;
	int randList[arrayMax];
	int tempInt;
	
	for (int i = 0; i < arrayMax; ++i) {
		tempInt = rand() % 100;
		randList[i] = tempInt; // Sets each number in the array to a random number between 0-1,000
	}
	
	char userInput = '-';
	bool exit = false;
	
	cout << "Hello, this is a program designed to calculate the efficiency of a certain sorting method." << endl;// INTRODUCTION MESSAGE
	
	while (exit == false) {
		cout << "Enter [S] for sort or [P] for Print: ";
		cin >> userInput;
		
		switch (userInput) {
			case 'p': // PRINT NUMBERS
				for (int i = 0; i < arrayMax; ++i) {
					cout << randList[i] << ", ";
				}
				cout << endl;
				break;
			case 's': // SORT NUMBERS
				int x; // Counter
				
				cout << "Sortings numbers...";
				// TO-DO: make another loop to check if it's done sorting and end at appropriate time.
				for (x = 1; x < arrayMax; ++x) {
					for (int i = 0; i < arrayMax - 1; ++i) {
						if (randList[i] > randList[i + 1]) {
							tempInt = randList[i + 1];
							randList[i + 1] = randList[i];
							randList[i] = tempInt;
						}
					}
				}
				
				cout << "Looped " << x << " times." << endl;
				break;
			case 'q': // QUIT PROGRAM
				cout << "Quit...\n";
				Sleep (50);
				exit = true;
				break;
			default: // DEFAULT
				cout << "Invalid input.\n";
				break;
		}
	}
	
	return 0;
}

