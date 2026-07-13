// class Solution {
// public:
//     vector<int> ans;

//     void generate(int num, int lastDigit, int low, int high) {
//         if (num > high || lastDigit > 9)
//             return;
//         if (num >= low)
//             ans.push_back(num);
//         if(lastDigit ==9 ) return;
//         generate(num * 10 + (lastDigit + 1), lastDigit + 1, low, high);
//     }
//     vector<int> sequentialDigits(int low, int high) {
//         for (int i = 1; i <= 9; i++) {
//             generate(i, i, low, high);
//         }
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string s = "123456789";
        string l = to_string(low);
        string h = to_string(high);

        for(int i = l.size(); i <= h.size(); i++) {
            for(int j = 0; j <= 9 - i; j++) {
                string n = s.substr(j, i);
                int num = stoi(n);
                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};