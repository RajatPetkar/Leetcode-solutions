#include <vector>
using namespace std;

class Solution {
public:

    bool isSafe(int col, int row, const vector<vector<char>>& board, int n) {
        for (int i = 0; i < col; i++) {
            if (board[row][i] == '1') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == '1') {
                return false;
            }
        }

        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == '1') {
                return false;
            }
        }

        return true;
    }

    void solve(int col, int &ans, vector<vector<char>>& board, int n) {
        if (col == n) {
            ans+=1;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(col, row, board, n)) {
                board[row][col] = '1';
                solve(col + 1, ans, board, n);
                board[row][col] = '0';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '0'));
        int ans = 0;
        solve(0, ans, board, n);
        return ans;
    }
};
