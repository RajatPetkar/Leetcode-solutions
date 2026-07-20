class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int totalElements = n * m;
        k = k % totalElements; 
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) { 
                ans.push_back(grid[i][j]);
            }
        }
        
        vector<vector<int>> result(n, vector<int>(m));
        for(int i = 0; i < totalElements; i++) {
            int newIndex = (i + k) % totalElements;
            int r = newIndex / m;
            int c = newIndex % m;
            result[r][c] = ans[i];
        }
        
        return result;
    }
};
