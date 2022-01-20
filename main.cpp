#include <iostream>

class TicTacToe {
    private:
        int boardValues[3][3] = {};
        int nextTurn = 11; // switch between 11 for X and 13 for O
    
    public:
        TicTacToe();
        int getPlayer(); // show who gets the next turn
        void next_move(int location); // update the board after input
        int check_win(); // check if game is over
        friend std::ostream & operator << (std::ostream &out, const TicTacToe &T); // for easy board printing
}


int main(){
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl;
}