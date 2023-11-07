#include <iostream>

using namespace std;

#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int secretNumber =rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Hello programmers welcome to the number guessing game!" <<endl;

    do {
        cout << "Enter the number (b/w 1 and 100): ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
        cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! programmers You've guessed the correct number in " << attempts << " attempts!" <<endl;
        }
    } while (guess != secretNumber);

return 0;
}
