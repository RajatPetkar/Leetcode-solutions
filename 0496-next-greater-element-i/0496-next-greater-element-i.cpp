class Solution {
public:
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     int count = 0;
    //     vector<int> arr;

    //     for (int i = 0; i < nums1.size(); i++) {
    //         for (int j = 0; j < nums2.size(); j++) {
    //             if (nums1[i] == nums2[j]) {
    //                 count = 1;
    //             }
    //             if (count == 1) {
    //                 if (nums1[i] < nums2[j]) {
    //                     arr.push_back(nums2[j]);
    //                     count = 0;
    //                 } else if (j == nums2.size() - 1) {
    //                     arr.push_back(-1);
    //                     count = 0;
    //                 }
    //             }
    //         }
    //     }
    //     return arr;
    // }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};