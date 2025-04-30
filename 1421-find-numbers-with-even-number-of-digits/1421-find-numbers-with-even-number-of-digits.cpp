class Solution {
public:
    int findNumbers(vector<int>& nums) {
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++) {
        int number = nums[i];
        int digitCount = 0;
        
        while(number) {
            number = number / 10;
            digitCount++;
        }
        
        if(digitCount % 2 == 0) {
            cnt++;
        }
    }
    return cnt;
}

};