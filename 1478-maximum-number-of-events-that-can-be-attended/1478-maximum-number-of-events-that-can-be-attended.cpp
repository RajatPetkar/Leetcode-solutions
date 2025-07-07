class Solution {
public:

int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        multiset<int> endingDays;
        int day = 0, i = 0, res = 0, n = events.size();

        while (!endingDays.empty() || i < n) {
            if (endingDays.empty()) {
                day = events[i][0];
            }

            while (i < n && events[i][0] == day) {
                endingDays.insert(events[i][1]);
                i++;
            }

            auto it = endingDays.begin();
            if (it != endingDays.end()) {
                endingDays.erase(it);
                res++;
            }

            day++;
            while (!endingDays.empty() && *endingDays.begin() < day) {
                endingDays.erase(endingDays.begin());
            }
        }

        return res;
    }
};
