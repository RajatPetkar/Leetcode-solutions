class Solution {
public:

vector<int> nextSmallerElement(vector<int> arr, int n) {
    stack<int> s;
    vector<int> ans(n);

    s.push(-1);

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {
    stack<int> s;
    vector<int> ans(n);

    s.push(-1);

    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> next = nextSmallerElement(heights, n);

    vector<int> prev = prevSmallerElement(heights, n);

    int area = INT_MIN + 1; // Corrected initialization

    for (int i = 0; i < n; i++) {
        int l = heights[i];
        int b = next[i] - prev[i] - 1; // Corrected calculation of base
        if (next[i] == -1) {
            b = n - prev[i] - 1; // Adjusting base if next[i] is -1
        }
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

};