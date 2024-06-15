class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> projects(n);
    
    // Combine capital and profits into a vector of pairs
    for (int i = 0; i < n; ++i) {
        projects[i] = {capital[i], profits[i]};
    }
    
    // Sort projects based on the capital required (ascending order)
    sort(projects.begin(), projects.end());
    
    priority_queue<int> maxProfitHeap;
    int currentCapital = w;
    int projectIndex = 0;
    
    for (int i = 0; i < k; ++i) {
        // Move all projects that can be afforded to maxProfitHeap
        while (projectIndex < n && projects[projectIndex].first <= currentCapital) {
            maxProfitHeap.push(projects[projectIndex].second);
            projectIndex++;
        }
        
        // If no projects are available to undertake, break the loop
        if (maxProfitHeap.empty()) {
            break;
        }
        
        // Add the profit of the most profitable project to the current capital
        currentCapital += maxProfitHeap.top();
        maxProfitHeap.pop();
    }
    
    return currentCapital;
}
};