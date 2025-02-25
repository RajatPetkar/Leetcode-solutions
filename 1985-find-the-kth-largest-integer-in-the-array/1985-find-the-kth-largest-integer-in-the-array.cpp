class NumStrMinComparator {
public:
    bool operator() (string &b, string &a) { 
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, NumStrMinComparator> pq;

        for (const string& num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};