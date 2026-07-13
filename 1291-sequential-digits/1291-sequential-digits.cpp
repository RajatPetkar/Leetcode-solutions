class Solution {
public:
    vector<int> ans;

    void generate(int num, int lastDigit, int low, int high) {
        if (num > high || lastDigit > 9)
            return;
        if (num >= low)
            ans.push_back(num);
        if(lastDigit ==9 ) return;
        generate(num * 10 + (lastDigit + 1), lastDigit + 1, low, high);
    }
    vector<int> sequentialDigits(int low, int high) {
        for (int i = 1; i <= 9; i++) {
            generate(i, i, low, high);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};