class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
// -------- Brute force method (TLE ERROR SUSPECTED) --------
        
//        int n = nums.size();
//         int flips = 0;
    
//         for (int i = 0; i < n; ++i) {
//             if (nums[i] == 0) {
//                 if (i + k > n) {
//                     return -1;  
//                 }
//                 for (int j = i; j < i + k; ++j) {
//                     nums[j] = 1 - nums[j];  
//                 }
//                 flips += 1;
//             }
//         }
    
//         return flips; 
        
    int n = nums.size();
    vector<int> flip(n, 0); 
    int flips = 0, currentFlips = 0;

    for (int i = 0; i < n; ++i) {
        if (i >= k) {
            currentFlips -= flip[i - k];
        }

        if ((nums[i] + currentFlips) % 2 == 0) {
            if (i + k > n) {
                return -1;  
            }
            flip[i] = 1;  
            currentFlips++;
            flips++;
        }
    }

    return flips;
    }
};