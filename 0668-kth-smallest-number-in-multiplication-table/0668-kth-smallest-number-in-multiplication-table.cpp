class Solution {
public:
    int countLessEqual(int m, int n, int target) {
    int count = 0;
    for (int i = 1; i <= m; i++) {
        count += min(n, target / i);
    }
    return count;
}

int findKthNumber(int m, int n, int k) {
    int low = 1, high = m * n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int cnt = countLessEqual(m, n, mid);
        if (cnt < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}
};