#include <iostream>

class TicTacToe {
    private:
        int boardValues[3][3] = {};
        int nextPlayer = 11; // switch between 11 for X and 13 for O
    
    public:
        TicTacToe();
        int getPlayer(); // show who gets the next turn
        void next_move(int location); // update the board after input
        bool check_end(); // check if game is over
        friend std::ostream & operator << (std::ostream &out, const TicTacToe &T); // for easy board printing
};

char player_char_converter(int player_number) {
    return 'a';
}

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

std::ostream & operator << (std::ostream &out, const TicTacToe &T) {
    std::cout << "Gotta implement board printing!" << std::endl;
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