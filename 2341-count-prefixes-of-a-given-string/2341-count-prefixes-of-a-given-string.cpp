class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for(int i=0;i<words.size();i++){
            if(s.substr(0,words[i].length()) == words[i]){
                ans++;
            }
        }
    return ans;
    }
};