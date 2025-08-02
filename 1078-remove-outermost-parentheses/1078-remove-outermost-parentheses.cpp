class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int Count = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (Count > 0) result += c;
                Count++;
            } else {
                Count--;
                if (Count > 0) result += c; 
            }
        }
        
        return result;
    }
};
