class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};

        for (char c : t) {
            hash[c]++;
        }

        int l = 0, r = 0;
        int cnt = 0;
        int minlen = INT_MAX;
        int start = -1;

        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            r++;

            while (cnt == t.size()) {
                if (r - l < minlen) {
                    minlen = r - l;
                    start = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }

        return start == -1 ? "" : s.substr(start, minlen);
    }
};
