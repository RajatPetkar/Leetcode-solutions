class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size() / 3; 
    unordered_map<int, int> mp;
    vector<int> result;      
    
    for (int num : nums) {
        mp[num]++;
    }

   
    for (auto& entry : mp) {
        if (entry.second > n) {
            result.push_back(entry.first);
        }
    }

    return result;
}

};