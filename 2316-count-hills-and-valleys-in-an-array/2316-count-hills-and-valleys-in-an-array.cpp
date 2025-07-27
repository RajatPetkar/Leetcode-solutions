class Solution {
public:

    // O(N) BOTH SAPCE AND TIME

    // int countHillValley(vector<int>& nums) {
    //     vector<int> arr;
    //     arr.push_back(nums[0]);

    //     for (int i = 1; i < nums.size(); i++) {
    //         if (nums[i] != nums[i - 1]) arr.push_back(nums[i]);
    //     }
        
    //     int cnt = 0;
    //     for (int i = 1; i < arr.size() - 1; i++) {
    //         if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || 
    //             (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
    //             cnt++;
    //         }
    //     }
    //     return cnt;
    // }


    // O(N) TIME && O(1) SPACE

   int countHillValley(vector<int>& nums) {
    int n = nums.size();
    int k = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    
    int cnt = 0;
    for (int i = 1; i < k - 1; i++) {
        if ((nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) || 
            (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])) {
            cnt++;
        }
    }
    return cnt;
}

};
