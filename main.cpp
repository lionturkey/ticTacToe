#include <iostream>

const int X_VAL = 11;
const int O_VAL = 13;

class TicTacToe {
    private:
        int boardValues[3][3] = {};
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
    return; // TODO
}

bool TicTacToe::check_end() {
    return true; // TODO
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