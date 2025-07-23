class Solution {
public:
    int removePair(string &s, char first, char second, int points) {
        stack<char> st;
        int score = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                score += points;
            } else {
                st.push(c);
            }
        }

        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        return score;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x >= y) {
            total += removePair(s, 'a', 'b', x); 
            total += removePair(s, 'b', 'a', y); 
        } else {
            total += removePair(s, 'b', 'a', y); 
            total += removePair(s, 'a', 'b', x);
        }

        return total;
    }
};
