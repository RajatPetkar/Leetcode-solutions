class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;
    vector<string> distinct;

    for (const auto& str : arr) {
        countMap[str]++;
    }

    for (const auto& str : arr) {
        if (countMap[str] == 1) {
            distinct.push_back(str);
        }
    }

    if (distinct.size() >= k) {
        return distinct[k - 1];
    } else {
        return "";
    }
    }
};