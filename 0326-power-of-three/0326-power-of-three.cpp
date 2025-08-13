class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int low = 0;
        int high = 19;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long power = 1;
            for (int i = 0; i < mid; ++i) {
                power *= 3;
                if (power > n) break;
            }
            if (power == n) {
                return true;
            } else if (power > n) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};