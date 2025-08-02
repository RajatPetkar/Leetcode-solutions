class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string word;

        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    v.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) v.push_back(word); 

        string result;
        for (int i = v.size() - 1; i >= 0; i--) {
            result += v[i];
            if (i != 0) result += " ";
        }
        return result;
    }
};
