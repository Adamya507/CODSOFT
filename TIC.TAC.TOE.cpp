#include<bits/stdc++.h>
using namespace std;
    //Tic-Tac-Toe
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
int user = 1;
char currentMarker;

void displayBoard() {
    cout << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return user;

        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return user;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return user;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return user;

    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    user = (user == 1) ? 2 : 1;
}

int main() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;

    if (currentMarker != 'X' && currentMarker != 'O') {
        cout << "Invalid marker! Defaulting to X for Player 1.\n";
        currentMarker = 'X';
    }

    displayBoard();

    int winnerPlayer = 0;
    for (int i = 0; i < 9; i++) {
        int slot;
        cout << "Player " << user << ", enter your move : ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid input! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try another.\n";
            i--;
            continue;
        }

        displayBoard();

        winnerPlayer = checkWinner();
        if (winnerPlayer != 0) {
            cout << "Player " << winnerPlayer << " wins! 🎊\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (winnerPlayer == 0) {
        cout << "It's a draw! \n";
    }

    return 0;
}
