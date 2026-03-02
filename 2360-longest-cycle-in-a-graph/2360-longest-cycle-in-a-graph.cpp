class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<int> visited(n, 0);
        vector<int> pathVisit(n, 0);
        vector<int> dist(n, 0);
        
        int ans = -1;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, edges, visited, pathVisit, dist, ans);
            }
        }
        
        return ans;
    }
    
    void dfs(int node, vector<int>& edges, 
             vector<int>& visited,
             vector<int>& pathVisit,
             vector<int>& dist,
             int &ans){
        
        visited[node] = 1;
        pathVisit[node] = 1;
        
        int next = edges[node];
        
        if(next != -1){
            
            if(!visited[next]){
                dist[next] = dist[node] + 1;
                dfs(next, edges, visited, pathVisit, dist, ans);
            }
            else if(pathVisit[next]){
                int cycleLen = dist[node] - dist[next] + 1;
                ans = max(ans, cycleLen);
            }
        }
        
        pathVisit[node] = 0; 
    }
};