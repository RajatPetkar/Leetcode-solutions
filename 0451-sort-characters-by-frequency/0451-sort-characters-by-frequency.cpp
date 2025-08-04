class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> mpp;
        string ans = "";
        for(char c: s){
            mpp[c]++;
        }
        priority_queue <pair<int,char>> maxHeap;
        for(auto &p : mpp){
            maxHeap.push({p.second,p.first});
        }

        while(!maxHeap.empty()){
            auto top = maxHeap.top();
            maxHeap.pop();
            ans.append( top.first,top.second );
        }
        return ans;
    }
};