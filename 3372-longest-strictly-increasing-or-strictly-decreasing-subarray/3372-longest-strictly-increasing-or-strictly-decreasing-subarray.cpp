class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    if (nums.empty()) return 0; 
    
    int inc = 1, dec = 1, maxLength = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            inc++;
            dec = 1; 
        } else if (nums[i] < nums[i - 1]) {
            dec++;
            inc = 1; 
        } else {
            inc = 1;
            dec = 1; 
        }
        maxLength = max(maxLength, max(inc, dec));
    }
    
    return maxLength;
}

};