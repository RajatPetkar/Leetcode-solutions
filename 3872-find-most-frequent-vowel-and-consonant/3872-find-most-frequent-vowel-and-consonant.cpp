class Solution {
public:
     int maxFreqSum(string s) {
        unordered_map<char, int> mpp;
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        for (char ch : s) {
            mpp[ch]++;
        }

        for (auto& [ch, freq] : mpp) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                maxVowelFreq = max(maxVowelFreq, freq);
            } else if (isalpha(ch)) { 
                maxConsonantFreq = max(maxConsonantFreq, freq);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};