class Solution {
public:
    bool possible(vector<int>& weights, int capacity, int days) {
        int curr = 0, cnt = 1;
        for(int w : weights) {
            if(curr + w > capacity) {
                cnt++;
                curr = 0;
            }
            curr += w;
        }
        return cnt <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while(left < right) { 
            int mid = left + (right - left) / 2;
            if(possible(weights, mid, days)) 
                right = mid; 
            else 
                left = mid + 1;
        }
        return left;
    }
};
