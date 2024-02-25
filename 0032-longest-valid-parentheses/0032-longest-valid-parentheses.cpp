class Solution {
public:
 int longestValidParentheses(string s) {
        stack<int> stk;
        int max_length = 0;
        int start = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                    if (stk.empty()) {
                        max_length = max(max_length, i - start);
                    } else {
                        max_length = max(max_length, i - stk.top());
                    }
                } else {
                    start = i;
                }
            }
        }

        return max_length;
    }
};