class Solution {
public:
    vector<string> splitter(string s) {
        string s1 = "";
        vector<string> v;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') { 
                if (!s1.empty()) { 
                    v.push_back(s1);
                    s1 = "";
                }
            } else {
                s1 += s[i];
            }
        }
        if (!s1.empty()) {
            v.push_back(s1);
        }
        return v;
    }

    bool isCircular(vector<string> v) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (v[i].back() != v[j].front()) {
                return false;
            }
        }
        return true;
    }

    bool isCircularSentence(string sentence) {
        vector<string> words = splitter(sentence);
        return isCircular(words);
    }
};
