class Solution {
public:
    int minSwaps(string s) {
       int size = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '[') 
                size++;
            else if (size > 0) 
                size--;
        }
        return (size + 1) / 2;  
    }
};