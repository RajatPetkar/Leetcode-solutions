class Solution {
public:

   bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false; 

       
        int openCount = 0, unlockCount = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') openCount++;
                else openCount--;
            } else {
                unlockCount++;
            }
            if (openCount + unlockCount < 0) return false; 
        }

       
        int closeCount = 0;
        unlockCount = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                if (s[i] == ')') closeCount++;
                else closeCount--;
            } else {
                unlockCount++;
            }
            if (closeCount + unlockCount < 0) return false; 
        }

        return true; 
    }
};