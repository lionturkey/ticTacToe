#include <iostream>

const int X_VAL = 17;
const int O_VAL = 19;

class TicTacToe {
    private:
        int boardValues[3][3] = {};
        int valueSums[3][3] = {}; // row 0 rows; row 1 cols; row 2 diags and total; used for check_end
        int valueCounts[3][3] = {}; // similar to valueSums
        int nextPlayer = X_VAL; // switch between 11 for X and 13 for O
    
    public:
        TicTacToe();
        int getPlayer(); // show who gets the next turn
        void next_move(int location); // update the board after input
        bool check_end(); // check if game is over
        friend std::ostream & operator << (std::ostream &out, const TicTacToe &T); // for easy board printing
};

TicTacToe::TicTacToe() {
    // set initial board values of 1-9 (no 0 bc we're depending on divisibility tests)
    for (int i = 0; i < 9; i++) {
        boardValues[(i/3)][(i%3)] = (i+1);
    }
}

int TicTacToe::getPlayer() {
    return nextPlayer;
}

void TicTacToe::next_move(int location){
    // ensure location is in bounds
    if ((location > 9) || (location < 1)) {
        std::cout << "Invalid square please try again." << std::endl;
        return;
    }

    int row = (location - 1) / 3;
    int col = (location - 1) % 3;

    if (boardValues[row][col] > 9) {
        std::cout << "Square already occupied, try again." << std::endl;
        return;
    }

    // since location passed the above checks, edit the board
    boardValues[row][col] = (location * nextPlayer);

    // add information to valueSums and checkCounts for check_end to use
    valueSums[0][row] += (location * nextPlayer); // update row info
    valueCounts[0][row] += 1;
    valueSums[1][col] += (location * nextPlayer); // update col info
    valueCounts[1][col] += 1;
    if (row == col) { // update forward diagonal info
        valueSums[2][0] += (location * nextPlayer);
        valueCounts[2][0] += 1;
    }
    if ((row + col) == 2) { // update backward diagonal info
        valueSums[2][1] += (location * nextPlayer);
        valueCounts[2][1] += 1;
    }
    valueSums[2][2] += (location * nextPlayer); // unused, but had one extra spot in the array lol
    valueCounts[2][2] += 1;
    
    nextPlayer = (nextPlayer == X_VAL) ? O_VAL : X_VAL; // toggle nextPlayer
    return;
}

int check_divisibility(int toCheck) {
    if ((toCheck % X_VAL) == 0) {
        return X_VAL;
    } else if ((toCheck % O_VAL) == 0) {
        return O_VAL;
    } else {
        return 0;
    }
}

bool TicTacToe::check_end() {
    for (int i = 0; i < 8; i++) {
        int row = i / 3;
        int col = i % 3;
        if (valueCounts[row][col] == 3) {
            int toCheck = valueSums[row][col];
            if (check_divisibility(toCheck) == 0) {
                continue;
            } else if (check_divisibility(toCheck) == X_VAL) { // the row, col, or diag sum is divisible by X_VALUE
                std::cout << "Congratulations Player X!" << std::endl;
                return true;
            } else if (check_divisibility(toCheck) == O_VAL) { // the row, col, or diag sum is divisible by O_VALUE
                std::cout << "Congratulations Player O!" << std::endl;
                return true;
            } else { // hopefully won't happen
                std::cout << "Something is screwy..." << std::endl;
                return true;
            }
        }
    }

    if (valueCounts[2][2] == 9) { // if all 9 squares are occupied
        std::cout << "It's a draw -_-" << std::endl;
        return true;
    }

    return false; // continue game
}

// if a number is divisible by X_VAL or O_VAL, print X or O respectively
char player_char_converter(int player_number) {
    if ((player_number % X_VAL) == 0) {
        return 'X';
    } else if ((player_number % O_VAL) == 0) {
        return 'O';
    } else {
        return static_cast<char>(player_number + 48); // add 48 for the ASCII to match the int
    }
}

// example output:
//      |     |
//   1  |  X  |  3
// _____|_____|_____
//      |     |
//   4  |  5  |  6
// _____|_____|_____
//      |     |
//   7  |  8  |  9
//      |     |
std::ostream & operator << (std::ostream &out, const TicTacToe &T) {
    std::cout << "     |     |" << std::endl;
    std::cout << "  " << player_char_converter(T.boardValues[0][0]);
    std::cout << "  |  " << player_char_converter(T.boardValues[0][1]);
    std::cout << "  |  " << player_char_converter(T.boardValues[0][2]) << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |" << std::endl;
    std::cout << "  " << player_char_converter(T.boardValues[1][0]);
    std::cout << "  |  " << player_char_converter(T.boardValues[1][1]);
    std::cout << "  |  " << player_char_converter(T.boardValues[1][2]) << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |" << std::endl;
    std::cout << "  " << player_char_converter(T.boardValues[2][0]);
    std::cout << "  |  " << player_char_converter(T.boardValues[2][1]);
    std::cout << "  |  " << player_char_converter(T.boardValues[2][2]) << std::endl;
    std::cout << "     |     |" << std::endl;
    return out;
}



int main(){
    TicTacToe gameBoard;
    bool endCondition = false; // check if the game is over with check_end

    // start the game!
    std::cout << "Welcome to Tic-Tac-Toe" << std::endl;
    while (endCondition == false) {
        std::cout << gameBoard << std::endl;
        int which_player = gameBoard.getPlayer();
        std::cout << "Player " << player_char_converter(which_player);
        std::cout << " type the number of a square to play your move:" << std::endl;

        int location;
        std::cin >> location;
        gameBoard.next_move(location);
        endCondition = gameBoard.check_end();
    }
    std::cout << gameBoard << std:: endl;
    return 0;
}