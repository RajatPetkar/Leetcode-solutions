class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;

        unordered_map<char,int> m;
        for(char c:s){
            m[c]++;
        }

        int oddCnt = 0;
        for(auto& e : m){
            if(e.second%2 !=0) oddCnt++;
        }
        return oddCnt<=k;
    }
};