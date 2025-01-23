#include <iostream>
#include <vector>
using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--------\n";  
    }
    cout << endl;  
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false; 
        }
    }
    return true; 
}

void makeMove(vector<vector<char>>& board, char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter your move (row and column [1-3]): ";
        cin >> row >> col;
        row--; col--;  
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            cout << "Invalid move, try again.\n";
        }
    }
}

int main() {
    char playAgain;
    do {
        vector<vector<char>> board(3, vector<char>(3, ' '));  
        char currentPlayer = 'X'; 
        bool gameWon = false;
        bool gameDraw = false;

        cout << "Welcome to Tic-Tac-Toe!\n";
        
        while (!gameWon && !gameDraw) {
            displayBoard(board);
            makeMove(board, currentPlayer);
            gameWon = checkWin(board, currentPlayer); 
            gameDraw = checkDraw(board); 

            if (!gameWon && !gameDraw) {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  
            }
        }

        displayBoard(board);

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else {
            cout << "It's a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!\n";

    return 0;
}
