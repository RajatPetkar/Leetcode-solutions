class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // if(nums.size()<=1){
        //     return false;
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==nums[nums.size()-i-1]){
        //         return true;
        //     }
        // }
        // return false;

        // TLE 

        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        std::set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size()==nums.size()){
            return false;
        }
        return true;
    }
};