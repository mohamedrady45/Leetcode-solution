class Solution {
public:
int par[200001], sz[200001];
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i=0;i<n;i++)
        makeset(i);
        for (auto &i : edges ){
         unionsets(i[0],i[1]);
        }
        return findset(source)==findset(destination);

    }
};