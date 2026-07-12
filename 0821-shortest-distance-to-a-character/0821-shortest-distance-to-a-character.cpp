class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ind,ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                ind.push_back(i);
            }
        }
        for(int i=0;i<s.size();i++){
            int ele = INT_MAX;
            for(int j=0;j<ind.size();j++){
                ele = min(ele,abs(i-ind[j]));
            }
            ans.push_back(ele);
        }
        return ans;
    }
};