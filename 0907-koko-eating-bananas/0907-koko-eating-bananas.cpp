class Solution {
public:
    long long func(vector<int>& piles, int hourly) {
        long long totalTime = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalTime += (piles[i] + hourly - 1LL) / hourly;
        }
        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long reqTime = func(piles, mid);

            if (reqTime <= h) {
                right = mid; 
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
