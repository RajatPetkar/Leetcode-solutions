class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };

        int res  = 0;
        for(int i=0;i<s.size();i++){
            int curr = mpp[s[i]];
            int next = mpp[s[i + 1]];

            if (next && curr < next) {
                res += next - curr;
                i++;
            } else {
                res += curr;
            }
        }
        return res;
    }
};

