class Solution {
public:
int par[1001], sz[1001];
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
        return ;
    int mn = min (a,b);
    int mx = max (a,b);
    par[mx] = mn;
    sz[mn] += sz[mx];
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
      for (int i=0;i<26;i++)
        makeset (i);
        string ans = "";
        for (int i=0;i<s1.size();i++){
            int mn = min(s1[i]-'a',s2[i]-'a');
            int mx = max(s1[i]-'a',s2[i]-'a');
             unionsets (mn,mx);
        }  
       for (auto &i:baseStr){
           ans.push_back(findset(i-'a')+'a');
       }
       return ans ;      
    }
};