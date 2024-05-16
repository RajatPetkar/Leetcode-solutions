class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val){
        for(int i = 0; i < board.size(); i++){
            if(board[row][i] == val){
                return false;
            }
        }
        
        for(int i = 0; i < board.size(); i++){
            if(board[i][col] == val){
                return false;
            }
        }
        
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    char val = board[i][j];
                    board[i][j] = '.'; 
                    if(!isSafe(i, j, board, val)){
                        return false;
                    }
                    board[i][j] = val;
                }
            }
        }
        
        return true;
    }
};
