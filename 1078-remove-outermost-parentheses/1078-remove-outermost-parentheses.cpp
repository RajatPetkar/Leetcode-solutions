class Solution {
public:
    // string removeOuterParentheses(string s) {
    //     string result;
    //     int Count = 0;

    //     for (char c : s) {
    //         if (c == '(') {
    //             if (Count > 0) result += c;
    //             Count++;
    //         } else {
    //             Count--;
    //             if (Count > 0) result += c;
    //         }
    //     }

    //     return result;
    // }

    string removeOuterParentheses(string s) {
        stack<char> stk;
        string ans;
        int i = 0;
        int n = s.size();

        while (i < n) {
            if (s[i] == '(') {
                if (!stk.empty()) {
                    ans += '(';
                }
                stk.push('(');
            } else {
                if (!stk.empty()) {
                    stk.pop();
                    if (!stk.empty()) {
                        ans += ')';
                    }  
                }
            }
            i++;
        }
        return ans;
    }
};
