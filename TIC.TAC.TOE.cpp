#include <iostream>
using namespace std;

char board[3][3];
int currentPlayer = 1;
char currentMarker;

// Function to initialize the board with numbers 1 to 9
void initializeBoard() {
    char cell = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = cell++;
}

// Function to display the current state of the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check if a slot is available
bool isSlotAvailable(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

// Function to place the marker in a given slot
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (isSlotAvailable(slot)) {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

// Function to check for a win
bool checkWin() {
    // Rows and Columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentMarker && board[i][1] == currentMarker && board[i][2] == currentMarker) ||
            (board[0][i] == currentMarker && board[1][i] == currentMarker && board[2][i] == currentMarker))
            return true;
    }

    // Diagonals
    if ((board[0][0] == currentMarker && board[1][1] == currentMarker && board[2][2] == currentMarker) ||
        (board[0][2] == currentMarker && board[1][1] == currentMarker && board[2][0] == currentMarker))
        return true;

    return false;
}

// Function to switch between players
void switchPlayer() {
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

// Main function
int main() {
    initializeBoard();
    cout << "Welcome to Tic-Tac-Toe\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;

    if (currentMarker != 'X' && currentMarker != 'O') {
        cout << "Invalid choice! Defaulting to X for Player 1.\n";
        currentMarker = 'X';
    }

    char player1Marker = currentMarker;
    char player2Marker = (player1Marker == 'X') ? 'O' : 'X';

    displayBoard();

    for (int turn = 0; turn < 9; ++turn) {
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << "), enter your move (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9 || !isSlotAvailable(slot)) {
            cout << "Invalid move! Try again.\n";
            --turn;
            continue;
        }

        placeMarker(slot);
        displayBoard();

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            return 0;
        }

        switchPlayer();
    }

    cout << "It's a draw!\n";
    return 0;
}
