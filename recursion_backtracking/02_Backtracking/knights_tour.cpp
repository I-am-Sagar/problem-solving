#include <bits/stdc++.h>
using namespace std;

#define N 5

// --------- Helper functions ----------
void print(int board[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            printf(" %2d", board[x][y]);
        }
        cout << endl;
    }
}

bool is_safe(int x, int y, int board[N][N]) {
    // 2 things to check: x, y is a valid position on the board and 
    // the cell is not visited before. 
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}


// ------------ MAIN LOGIC ---------------
// level is the move in the case. You have to cover, N*N moves. 
bool knights_tour(int x, int y, int move, int board[N][N], int x_move[N], int y_move[N]) {
    if (move == N*N) 
        return true;

    bool is_valid = false;

    // For a knight, there are always 8 possible jumps given any square
    for (int i = 0; i < 8; i++) {
        int next_x = x + x_move[i];
        int next_y = y + y_move[i];

        if (is_safe(next_x, next_y, board)) {
            board[next_x][next_y] = move;

            if (knights_tour(next_x, next_y, move+1, board, x_move, y_move)) {
                is_valid = true;
                return is_valid;
            }

            board[next_x][next_y] = -1;
        }
    }

    return is_valid;
}



int main() {
    int board[N][N];

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            board[x][y] = -1;

    // The way knight moves
    int x_move[8] = {2, 2, 1, 1, -2, -2, -1, -1};
    int y_move[8] = {1, -1, 2, -2, 1, -1, 2, -2};

    board[0][0] = 0;  // knight starts at (0, 0)

    if (!knights_tour(0, 0, 1, board, x_move, y_move))
        cout << "Solution doesn't exist for this n." << endl;
    else 
        print(board);

    return 0;
}