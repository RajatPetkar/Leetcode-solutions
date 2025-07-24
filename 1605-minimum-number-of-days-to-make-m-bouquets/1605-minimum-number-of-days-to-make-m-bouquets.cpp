class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k) {
        int n = arr.size();
        int cnt = 0;
        int noOfB = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++;
            } else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if (val > n)
            return -1;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left <= right) {
            int mid = (left + right) / 2;
            if (possible(bloomDay, mid, m, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};