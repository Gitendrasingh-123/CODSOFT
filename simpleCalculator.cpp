#include <iostream>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "Choose an operation:\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Exit\n";
}

int main() {
    double num1, num2;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice, please try again.\n";
            continue;
        }

        if (choice == 5) {
            cout << "Exiting the program. Goodbye!\n";
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "Result: " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Result: " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Result: " << num1 * num2 << endl;
                break;
            case 4:
                
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero.\n";
                } else {
                    cout << "Result: " << num1 / num2 << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please select a valid operation.\n";
                break;
        }
    }

    return 0;
}
