class Solution {
public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> mp(26, 0);
//         for (char ch : tasks) {
//             mp[ch - 'A']++;
//         }

//         priority_queue<int> pq;
//         for (int i = 0; i < 26; i++) {
//             if (mp[i] > 0) pq.push(mp[i]);
//         }

//         int time = 0;

//         while (!pq.empty()) {
//             vector<int> temp;
//             int cnt = 0;

//             for (int i = 0; i <= n; i++) {
//                 if (!pq.empty()) {
//                     int freq = pq.top();
//                     pq.pop();
//                     if (--freq > 0) temp.push_back(freq);
//                     cnt++;
//                 }
//             }

//             for (int f : temp) pq.push(f);

//             if (pq.empty())
//                 time += cnt;    
//             else
//                 time += n + 1;  
//         }

//         return time;
//     }
// };


int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for(char c : tasks) freq[c - 'A']++;

    sort(freq.begin(), freq.end());
    int maxFreq = freq[25] - 1;
    int idleSlots = maxFreq * n;

    for(int i = 24; i >= 0 && freq[i] > 0; i--)
        idleSlots -= min(freq[i], maxFreq);

    return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
}
};