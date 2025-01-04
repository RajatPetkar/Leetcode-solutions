class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, -1); 
        vector<int> last(26, -1);  
        
       
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }
        
        int result = 0;
       
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] > first[i]) {
                unordered_set<char> unique_chars;
                for (int j = first[i] + 1; j < last[i]; j++) {
                    unique_chars.insert(s[j]);
                }
                result += unique_chars.size(); 
            }
        }
        
        return result;
    }
};
