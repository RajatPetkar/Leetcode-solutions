class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for (char ch : tasks) {
            mp[ch - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0) pq.push(mp[i]);
        }

        int time = 0;

        while (!pq.empty()) {
            vector<int> temp;
            int cnt = 0;

            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    if (--freq > 0) temp.push_back(freq);
                    cnt++;
                }
            }

            for (int f : temp) pq.push(f);

            if (pq.empty())
                time += cnt;    
            else
                time += n + 1;  
        }

        return time;
    }
};
