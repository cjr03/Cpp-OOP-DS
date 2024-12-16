#include <iostream>
#include <string>
using namespace std;
class game {
public:
    game() {for (int i = 0; i < 100; ++i) board[i] = moves[i] = 0;}
    void ladder(int begin, int end) {board[begin-1] = end - begin;}
    void snake(int begin, int end) {board[begin-1] = end - begin;}
    void minmove(int move = 0, int place = 1) {
        if (place < 95){
            if (place > 1) cout << "Turn ended on " << place << ".\n";
            ++moves[place];
            int best[6]{board[place]+1, board[place+1]+2, board[place+2]+3, board[place+3]+4, board[place+4]+5, board[place+5]+6};
            return minmove(move + 1, place + *max_element(best, best + 6));
        } else if (place != 100) {
            cout << "Turn ended on " << place << ".\n";
            ++moves[place];
            return minmove(move + 1, 100);
        } else cout << "Peice reached 100.\nThe minimum moves for a 10x10 board is " << move << ".\n";
    }
    void gameover() {
        int move {0};
        for(auto i = 0; i <= 99; ++i) if(moves[i] == 1 or i == 99) moves[i] = ++move;
        for(auto i = 99; i >= 0; --i){
            cout << " [";
            if (moves[i] == 0) cout << " ] ";
            else cout << moves[i] << "] ";
            if((i) % 10 == 0) cout << "\n";
        }
    }
private:
    int board[100];
    int moves[100];
};



int main () {
    game cole;
    cole.ladder(3,21);
    cole.ladder(8,30);
    cole.ladder(28,84);
    cole.ladder(58,77);
    cole.ladder(75,86);
    cole.ladder(80,100);
    cole.ladder(90,91);
    cole.snake(17, 13);
    cole.snake(88, 18);
    cole.snake(62,22);
    cole.snake(52, 29);
    cole.snake(57,40);
    cole.snake(95,51);
    cole.snake(97,79);
    cole.minmove(0, 0);
    cole.gameover();
    return 0;
}
