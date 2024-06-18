class Solution {
public:
bool canArrange(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> remainderCount(k, 0);
    
    for (int i = 0; i < n; ++i) {
        int remainder = ((arr[i] % k) + k) % k;  
        remainderCount[remainder]++;
    }

    for (int i = 1; i < k; ++i) {
        if (remainderCount[i] != remainderCount[k - i]) {
            return false;
        }
    }

    if (remainderCount[0] % 2 != 0) {
        return false;
    }

    return true;
}

};