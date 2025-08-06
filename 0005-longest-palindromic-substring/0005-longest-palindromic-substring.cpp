class Solution {
public:
    bool isPalindrome(const string &str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string longest = "";

        for (int i = 0; i < s.size(); i++) {
            string word = "";
            for (int j = i; j < s.size(); j++) {
                word += s[j];
                if (isPalindrome(word) && word.size() > longest.size()) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};
