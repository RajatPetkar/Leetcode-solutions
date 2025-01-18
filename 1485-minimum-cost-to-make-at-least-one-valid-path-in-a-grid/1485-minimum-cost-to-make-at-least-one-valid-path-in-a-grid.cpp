class Solution {
public:

int minCost(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    deque<pair<int, int>> dq;
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

    dq.push_front({0, 0});
    cost[0][0] = 0;

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        if (x == m - 1 && y == n - 1) return cost[x][y];

        for (int d = 0; d < 4; ++d) {
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int newCost = cost[x][y] + (grid[x][y] == d + 1 ? 0 : 1);

                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;

                    if (grid[x][y] == d + 1) {
                        dq.push_front({nx, ny}); 
                    } else {
                        dq.push_back({nx, ny}); 
                    }
                }
            }
        }
    }

    return -1;
}

};