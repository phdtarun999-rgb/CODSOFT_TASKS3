#include <iostream>
using namespace std;

char board[3][3];


void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}


void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i != 2)
            cout << "---|---|---" << endl;
    }
    cout << "\n";
}


bool checkWin(char player) {

   
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

   
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}


bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main() {

    char playAgain;

    do {
        initializeBoard();
        char currentPlayer = 'X';

        while (true) {

            displayBoard();

            int choice;
            cout << "Player " << currentPlayer
                 << ", enter position (1-9): ";
            cin >> choice;

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

        
            if (choice < 1 || choice > 9 ||
                board[row][col] == 'X' ||
                board[row][col] == 'O') {

                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            
            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

         
            if (checkDraw()) {
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

        
            if (currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}