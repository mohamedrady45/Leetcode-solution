class Solution {
public :
    vector<int>adj[30002];
int par[30002], sz[30002];
void makeset(int node)
{
    par[node] = node;
    sz[node] = 1;
}
int findset(int a)
{
    if(par[a] == a)
        return a;
    return par[a] = findset(par[a]);
}
void unionsets(int a, int b)
{
    a = findset(a);
    b = findset(b);
    if(a == b)
        return;
    if(sz[b] > sz[a])
        swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        for (int i=0;i<=n;i++)
            makeset(i);
        map<int,vector<int>>mp;
    for (auto i : edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
     for (int i=0;i<vals.size();i++)
         mp[vals[i]].push_back(i);
     int ans =0;
        int mx = *max_element(vals.begin(),vals.end());
      for (int i=0;i<=mx;i++){
          for (auto node : mp[i]){
              for (auto child : adj[node]){
                  if (i>= vals[child])
                      unionsets(node,child);
              }
          }
          map<int,int>freq;
         for (auto curr : mp[i]){
             int parent = findset(curr);
             freq[parent]++;
         }
         for(auto p : freq)
         ans += p.second*(p.second+1)/2;
      }
      return ans;
    }
};