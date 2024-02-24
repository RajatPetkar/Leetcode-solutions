class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
                            int count  = 0;
        vector<int> arr;

        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    count=1;
                }
                if(count==1){
                    if(nums1[i]<nums2[j]){
                        arr.push_back(nums2[j]);
                        count=0;
                    }
                    else if(j==nums2.size()-1){
                        arr.push_back(-1);
                        count=0;
                    }
                }
            }
        }
        return arr;
    }
};