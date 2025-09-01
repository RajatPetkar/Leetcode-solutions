class Solution {
public:
    bool isSubsequence(string s, string t) {
        return check(0, 0, s, t);
    }

    bool check(int i, int j, string &s, string &t) {
        if (i == s.size()) return true;   
        if (j == t.size()) return false; 

        if (s[i] == t[j]) {
            return check(i + 1, j + 1, s, t); 
        } else {
            return check(i, j + 1, s, t);    
        }
    }
};
