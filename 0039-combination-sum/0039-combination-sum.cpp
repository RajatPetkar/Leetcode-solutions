class Solution {
public:
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //    vector<vector<int>> ans;
    //    vector<int> ele;
    //    int cnt;
    //    int temp;

    //    for(int i=0;i<candidates.size();i++){
    //         ele.push_back(candidates[i]);
    //         if(ele[i]<=target){
    //             temp = ele[i];
    //             temp = ele[i]*temp;
    //             if(temp<=target){
    //                 cnt++;
    //             }
    //             for(int j=0;j<cnt-1;j++){
    //                 ele.push_back(temp);
    //             }
    //             cnt = 0;
    //             temp = 0;
    //         }else if(ele[i]-candidates[i]<=target){
    //             ele.push_back(candidates[i]);
    //         }
    //         ans.push_back(ele);
    //    }
    //    return ans;
    // }

    void findCombination(int ind, vector<int>& candidates, int target,vector<vector<int>>& ans, vector<int>& ds) {
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findCombination(ind,candidates,target-candidates[ind],ans,ds);
            ds.pop_back();
        }
        findCombination(ind+1,candidates,target,ans,ds);
        
    }

     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                vector<vector<int>> ans;
                vector<int> ds;
                findCombination(0, candidates, target, ans, ds);
                return ans;
    }
        };
