class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty())
                    break;

                int distance = i - st.top() - 1;
                int bounded_height =
                    min(height[i], height[st.top()]) - height[top];
                water += distance * bounded_height;
            }
            st.push(i);
        }
        return water;
    }
};

// int trap(vector<int>& height) {
//         int left = 0, right = height.size() - 1;
//         int left_max = 0, right_max = 0, water = 0;

//         while (left < right) {
//             if (height[left] < height[right]) {
//                 if (height[left] >= left_max) {
//                     left_max = height[left];
//                 } else {
//                     water += left_max - height[left];
//                 }
//                 left++;
//             } else {
//                 if (height[right] >= right_max) {
//                     right_max = height[right];
//                 } else {
//                     water += right_max - height[right];
//                 }
//                 right--;
//             }
//         }
//         return water;
//     }