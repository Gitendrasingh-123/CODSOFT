#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(static_cast<unsigned>(time(0)));

    int target = rand() % 100 + 1;

    int guess = 0;
    bool correct = false;

    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    while (!correct) {
        cout << "Enter your guessing number: ";
        cin >> guess;

        if (guess > target) {
            cout << "Your guess is high. Try again." << endl;
        } else if (guess < target) {
            cout << "Your guess is low. Try again." << endl;
        } else {
            correct = true;
            cout << "Congratulations! You guessed the correct number!" << endl;
        }
    }

    return 0;
}
