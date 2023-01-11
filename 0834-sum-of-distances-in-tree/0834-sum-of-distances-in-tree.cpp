class Solution {
public:
  vector<int>adj[30005];
  map<pair<int,int>,pair<int,int>>dp;
  pair<int,int>dfs (int node , int parOfNode){
      int nodeDist =0;
      int parOfNodeDist =1;
      for (auto child : adj[node]){
          if (child != parOfNode){
              if(dp.find({node,child})==dp.end())
              dp[{node,child}] = dfs(child,node);
              parOfNodeDist+=dp[{node,child}].second;
              nodeDist+=(dp[{node,child}].first + dp[{node,child}].second);
          }
      }
      pair <int,int>ret={nodeDist,parOfNodeDist};
      return ret ;
  }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        for (int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i=0;i<n;i++){
           pair<int,int>p=dfs(i,-1);
           ans.push_back(p.first);
        }
        return ans ;
    }
};