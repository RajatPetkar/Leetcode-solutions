// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int n = mat.size();    
//         int m = mat[0].size(); 
//         int left = 0, right = n * m - 1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             int row = mid / m;  
//             int col = mid % m;  

//             int curr = mat[row][col];
//             int up    = (row > 0)      ? mat[row - 1][col] : -1;
//             int down  = (row < n - 1)  ? mat[row + 1][col] : -1;
//             int leftN = (col > 0)      ? mat[row][col - 1] : -1;
//             int rightN= (col < m - 1)  ? mat[row][col + 1] : -1;

//             if (curr > up && curr > down && curr > leftN && curr > rightN) {
//                 return {row, col};
//             }

//             if (up > curr) {
//                 right = mid - 1;
//             } 
//             else if (down > curr) {
//                 left = mid + 1;
//             } 
//             else if (leftN > curr) {
//                 right = mid - 1;
//             } 
//             else if (rightN > curr) {
//                 left = mid + 1;
//             }
//         }

//         return {0, 0};
//     }
// };

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int lowCol = 0, highCol = m - 1;

        while (lowCol <= highCol) {
            int midCol = lowCol + (highCol - lowCol) / 2;
            
            int maxRow = 0;
            for (int i = 1; i < n; ++i) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int currentVal = mat[maxRow][midCol];
            int leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightVal = (midCol < m - 1) ? mat[maxRow][midCol + 1] : -1;

            if (currentVal > leftVal && currentVal > rightVal) {
                return {maxRow, midCol};
            } 
            else if (leftVal > currentVal) {
                highCol = midCol - 1;
            } 
            else {
                lowCol = midCol + 1;
            }
        }
        return {-1, -1}; 
    }
};
