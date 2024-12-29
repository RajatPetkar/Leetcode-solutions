class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        vector<bool> present(nums.size() + 1, false);

        for (int num : nums) {
            present[num] = true;
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (!present[i]) {
                v.push_back(i);
            }
        }

        return v;
    }
};
