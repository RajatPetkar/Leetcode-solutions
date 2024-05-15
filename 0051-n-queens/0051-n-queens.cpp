#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
void addSolution(const vector<vector<string>> &board, vector<vector<string>> &ans, int n) {
    vector<string> temp;
    for(int i = 0; i < n; i++) {
        string row;
        for(int j = 0; j < n; j++) {
            if (board[i][j] == "1") {
                row += "Q";
            } else {
                row += ".";
            }
        }
        temp.push_back(row);
    }
    ans.push_back(temp);
}

    
    bool isSafe(int col, int row, const vector<vector<string>> &board, int n) {
        for(int i = 0; i < col; i++) {
            if(board[row][i] == "1") {
                return false;
            }
        }
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == "1") {
                return false;
            }
        }
        
        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(board[i][j] == "1") {
                return false;
            }
        }
        
        return true;
    }
    
    void solve(int col, vector<vector<string>> &ans, vector<vector<string>> &board, int n) {
       if(col == n) {
           addSolution(board, ans, n);
           return;
       } 
        
        for(int row = 0; row < n; row++) {
            if(isSafe(col, row, board, n)) {
                board[row][col] = "1";
                solve(col + 1, ans, board, n);
                board[row][col] = "0";
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n , vector<string>(n, "0"));
        vector<vector<string>> ans;
        
        solve(0, ans, board, n);
        return ans;
    }
};
