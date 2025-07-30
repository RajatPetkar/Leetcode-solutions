class Solution {
public:

    bool possible(vector<int>& nums, int ans, int threshold){
        int res = 0;
        for(int i=0;i<nums.size();i++){
           res += (nums[i] + ans - 1) / ans;
        }
        return (res <= threshold);
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(),nums.end());

        while(left<=right){
           int mid = left + (right - left) / 2;

            if(possible(nums,mid,threshold)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};