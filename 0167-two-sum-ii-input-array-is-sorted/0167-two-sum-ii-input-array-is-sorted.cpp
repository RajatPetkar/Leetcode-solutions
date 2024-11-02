class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ANS;
        
        int left = 0;
        int right = n-1;
        
        while(left<right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                ANS.push_back(left+1);
                ANS.push_back(right+1);
                return ANS;
            }else if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        return ANS;
    }
};