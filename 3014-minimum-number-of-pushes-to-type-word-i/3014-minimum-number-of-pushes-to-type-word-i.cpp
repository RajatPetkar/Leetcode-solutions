class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int point = 1;
        for(int i=0;i<word.size();i++){
            ans+=point;
            if ((i + 1) % 8 == 0) {
                point++;
            }
        }
        return ans;
    }
};