#include<bits/stdc++.h>
using namespace std;

// -------- Helper functions ----------
// print() just prints the board.
void print(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// is_safe() checks if the queen is safe at board[i][col].
bool is_safe(int row, int col, vector<vector<int>> &board) {
    // Check if there is any queen in same row on previous columns
    for (int i = 0; i < col; i++) 
        if (board[row][i])
            return false;

    // Check for upper diagonal  
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j])
            return false;

    // Check for lower diagonal
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}


// --------- MAIN LOGIC ---------------
// Level in this game is about columns.
bool n_queens(int col, vector<vector<int>> &board) {
    if (col >= board.size()) {
        print(board);
        return true;
    }

    bool is_valid = false;

    // Checking all possibilities
    for (int i = 0; i < board.size(); i++) {
        // Checking if constraint is satisfied
        if (is_safe(i, col, board)) {
            // Considering this to be a potential possibility
            board[i][col] = 1;

            // Try to solve for further levels
            if (n_queens(col+1, board)) {
                is_valid = true;
                // return is_valid;   // This commented means all possibilities
            }

            // If unable to solve for further levels, remove the potential possibility
            board[i][col] = 0;
        }
    }

    return is_valid;
}


int main() {
    int n; cin >> n;

    // nxn board with all zeros
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!n_queens(0, board))
        cout << "Solution doesn't exist for this value of n." << endl;

    return 0;
}

/*

Note: If you comment, the return is_valid statement inside if block, you will print 
all the solutions!!

*/