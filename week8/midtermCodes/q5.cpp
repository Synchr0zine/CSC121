#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int diceToRoll = 20; // Number of dice to roll
    const int sides = 20; // Sides of each die

    // Seed the random number generator with the current time so everytime seed is different
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Rolling " << diceToRoll << " twenty-sided dice:\n";

    // Roll the dice and print the results
    for (int i = 0; i < diceToRoll; ++i) {
        int roll = rand() % sides + 1; // Generate a number between 1 and 20
        cout << roll << " "; // Output the result
    }

    cout << endl; // New line after rolling

    return 0;
}
