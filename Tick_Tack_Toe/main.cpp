#include <iostream>

using namespace std;

char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1 = " ";
string n2 = " ";

void functionOne() {
    // Structure of the Tic-Tac-Toe game
    cout << "    |      |    \n";
    cout << " " << space[0][0] << "  |  " << space[0][1] << "   | " << space[0][2] << "  \n";
    cout << "____|______|____\n";
    cout << "    |      |    \n";
    cout << " " << space[1][0] << "  |  " << space[1][1] << "   | " << space[1][2] << "  \n";
    cout << "____|______|____\n";
    cout << "    |      |    \n";
    cout << " " << space[2][0] << "  |  " << space[2][1] << "   | " << space[2][2] << "  \n";
    cout << "    |      |    \n";
}

void functionTwo() {
    int digit;
    if(token == 'x') {
        cout << n1 << ", please enter: ";
        cin >> digit;
    } else if(token == '0') {
        cout << n2 << ", please enter: ";
        cin >> digit;
    }

    if(digit == 1) {
        row = 0; column = 0;
    } else if(digit == 2) {
        row = 0; column = 1;
    } else if(digit == 3) {
        row = 0; column = 2;
    } else if(digit == 4) {
        row = 1; column = 0;
    } else if(digit == 5) {
        row = 1; column = 1;
    } else if(digit == 6) {
        row = 1; column = 2;
    } else if(digit == 7) {
        row = 2; column = 0;
    } else if(digit == 8) {
        row = 2; column = 1;
    } else if(digit == 9) {
        row = 2; column = 2;
    } else {
        cout << "Invalid input!" << endl;
        functionTwo(); // Ask for input again if invalid
        return;
    }

    if(token == 'x' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = 'x';
        token = '0';
    } else if(token == '0' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = '0';
        token = 'x';
    } else {
        cout << "The spot is already taken!" << endl;
        functionTwo(); // Ask for input again if spot is taken
    }
}

bool functionThree() {
    // Check rows, columns, and diagonals for a win
    for(int i = 0; i < 3; i++) {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2])
            return true;
        if(space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }

    if(space[0][0] == space[1][1] && space[0][0] == space[2][2])
        return true;
    if(space[0][2] == space[1][1] && space[0][2] == space[2][0])
        return true;

    // Check for tie
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    // Number of players
    cout << "Enter the name of player 1: ";
    getline(cin, n1);
    cout << "Enter the name of player 2: ";
    getline(cin, n2);

    cout << n1 << " (x) will play first.\n";
    cout << n2 << " (0) will play second.\n";

    while(!functionThree()) {
        functionOne();
        functionTwo();
        functionThree();
    }

    functionOne();  // Show the final state of the game

    if(tie) {
        cout << "It's a draw!" << endl;
    } else if(token == '0' && tie == false) {  // Check if player 1 wins
        cout << n1 << " wins!" << endl;
    } else if(token == 'x' && tie == false) {  // Check if player 2 wins
        cout << n2 << " wins!" << endl;
    }

    return 0;
}
