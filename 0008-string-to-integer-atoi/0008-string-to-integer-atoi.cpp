// class Solution {
// public:
//     int myAtoi(string s) {
//         int ans = 0;  
//         int sign = 1;

//         for (int i = 0; i < s.size(); i++) {
            
//             if (!isdigit(s[i])) {
//                 if (s[i] == '-') {
//                     sign = -1;
//                     continue;  
//                 } else if (s[i] == '+') {
//                     continue;   
//                 } else {
//                     return ans * sign; 
//                 }
//             } 
//             else {
//                 ans = ans * 10 + (s[i] - '0');  
//             }
//         }
//         return ans * sign;
//     }
// };


class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;  
        int sign = 1;
        int i = 0;

        while (i < s.size() && s[i] == ' ') i++;

        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        for (; i < s.size(); i++) {
            if (!isdigit(s[i])) break;
            if(ans > (INT_MAX/10) || (ans == (INT_MAX/10) && s[i]- '0' >7)){
                if (sign==1) return INT_MAX;
                else return INT_MIN;
            }
            ans = ans * 10 + (s[i] - '0');
        }

        return ans * sign;
    }
};
