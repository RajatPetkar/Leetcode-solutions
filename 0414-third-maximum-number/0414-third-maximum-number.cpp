class Solution {
public:
    int thirdMax(vector<int>& nums) {
         set<int> s;
        
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size() >= 3){
            int index = s.size()-3;
            auto thirdMax= next(s.begin(), index);
            return *thirdMax;
        }

        return *--s.end();
    }
};