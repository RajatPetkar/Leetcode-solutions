class Solution {
public:
    int ans = 0;
    int m, n;

    void dfs(vector<vector<int>>& grid, int i, int j, int cnt,
             int total) {

        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == -1)
            return;

        if (grid[i][j] == 2) {
            if (cnt == total)
                ans++;
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            dfs(grid, ni, nj, cnt + 1, total);
        }

        grid[i][j] = temp; 
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int sx, sy;
        int total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    total++;

                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }

        dfs(grid, sx, sy, 1, total);

        return ans;
    }
};