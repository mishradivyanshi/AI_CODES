#include <iostream>
#include <vector>
using namespace std;

const int N = 20; // max board size (can be adjusted)

bool isSafe(int row, int col, vector<string> &board, int n) {
    // Check left row
    for (int j = 0; j < col; j++) {
        if (board[row][j] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check lower-left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}



void solveNQueens(int col, int n, vector<string> &board, vector<vector<string>> &solutions) {
    if (col == n) {
        solutions.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solveNQueens(col + 1, n, board, solutions);
            board[row][col] = '.'; // backtrack
        }
    }
}



int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;

    solveNQueens(0, n, board, solutions);

    cout << "\nTotal Solutions: " << solutions.size() << "\n\n";
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution #" << i + 1 << ":\n";
        for (int j = 0; j < n; j++) {
            cout << solutions[i][j] << "\n";
        }
        cout << "\n";
    }

    return 0;

}
