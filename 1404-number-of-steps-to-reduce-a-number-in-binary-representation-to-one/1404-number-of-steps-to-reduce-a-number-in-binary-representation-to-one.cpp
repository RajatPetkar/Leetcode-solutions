class Solution {
public:
    int numSteps(string s) {
    int step = 0;
    while (s != "1") {
        int len = s.length();
        if (s[len - 1] == '0') {
            
            s.pop_back();
        } else {
            int i = len - 1;
            while (i >= 0 && s[i] == '1') {
                s[i] = '0';
                i--;
            }
            if (i >= 0) {
                s[i] = '1';
            } else {
                s = '1' + s;
            }
        }
        step++;
    }
    return step;
}
};