class Solution {
public:
    vector<int>adj[100005];
    int Inf = 1e9;
    vector<int> bfs (int node){
        vector<int>dist(100005,Inf);
        queue<int>q;
        dist[node]=0;
        q.push(node);
        while (q.size()){
            int curr_node = q.front();
            q.pop();
            int curr =  dist[curr_node]+1;
            for (auto child : adj[curr_node]){
                 if (dist[child] > curr){
                    dist[child] = curr;
                    q.push(child);
                 }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        for (int i=0;i<edges.size();i++){
            if (edges[i]==-1)
            continue;
              adj[i].push_back(edges[i]);
        }
        int ans =-1;
        vector<int>dist1 = bfs(node1);
        vector<int>dist2 = bfs(node2);
        int mn = 1e9;
        for (int i=0 ; i<edges.size();i++){
            int curr = max(dist1[i],dist2[i]);
            if (curr < mn )
            mn = curr , ans = i;
        }
        return ans;
    }
};