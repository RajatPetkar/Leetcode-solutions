class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> ans = {-1, -1};

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                ans[0] = mid;
                ans[1] = mid;

                int low = mid - 1;
                while (low >= 0 && nums[low] == target) {
                    ans[0] = low;
                    low--;
                }

                int high = mid + 1;
                while (high < n && nums[high] == target) {
                    ans[1] = high;
                    high++;
                }

                break; 
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
