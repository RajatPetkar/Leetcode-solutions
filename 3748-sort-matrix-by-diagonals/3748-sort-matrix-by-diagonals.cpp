// class Solution {
// public:
//     vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();

//         int topR = 0;
//         int topB = 1;

//         for (int i = 0; i < row - 1; i++) {
//             if (i + 1 < row && topR + 1 < col) {
//                 if (grid[i][topR] < grid[i + 1][topR + 1]) {
//                     swap(grid[i][topR], grid[i + 1][topR + 1]);
//                 }
//             }

//             if (topR < col - 1)
//                 topR++;
//         }

//         for (int i = 0; i < row - 1; i++) {
//             if (i + 1 < row && topB + 1 < col) {
//                 if (grid[i][topB] > grid[i + 1][topB + 1]) {
//                     swap(grid[i][topB], grid[i + 1][topB + 1]);
//                 }
//             }

//             if (topB < col - 1)
//                 topB++;
//         }

//         return grid;
//     }
// };


class Solution {
public:
   vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; i + j < n; j++) {
                tmp.push_back(grid[i + j][j]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = tmp[j];
            }
        }
        for (int j = 1; j < n; j++) {
            vector<int> tmp;
            for (int i = 0; j + i < n; i++) {
                tmp.push_back(grid[i][j + i]);
            }
            sort(tmp.begin(), tmp.end());
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp[i];
            }
        }
        return grid;
    }
};
