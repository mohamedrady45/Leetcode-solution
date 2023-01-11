class Solution {
public:
    const int Inf = 1e9 , N = 1e5+1;
    vector<int>dist;
    vector<bool>has; 
    vector<bool>visited;
    vector<int>adj[100005];
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    dist.assign(n,Inf);
    visited.assign(n,0);
    has = hasApple;
    for (auto &i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int ans = dfs(0);
    return ans ;
    }
    int dfs(int node){
        visited[node]=1;
        int ans =0;
        for (auto child : adj[node]){
            if (!visited[child]){
             int ret = dfs(child);
             if (ret || has[child])
             ans+=ret+2;
            }
        }
        return ans ; 
    }
};