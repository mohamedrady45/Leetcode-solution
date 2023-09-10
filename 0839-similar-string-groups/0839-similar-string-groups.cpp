class Solution {
public:
    int par[305] , groupsize[305];
    void makeset (int x){
    par [x] = x;
    groupsize[x] = 1;
}
int findset(int i){
        if(par[i] == i)
        return i;
        return par[i] = findset(par[i]);
}
void unionsets (int x , int y){
        int leader1 = findset(x);
        int leader2 = findset(y);
        if(leader1 == leader2)
            return;
    if(groupsize[leader1] < groupsize[leader2])
        swap (leader1 , leader2);
            par[leader2] =  leader1;
            groupsize[leader1] += groupsize[leader2];
}
    int numSimilarGroups(vector<string>& strs) {
        for (int i=0 ; i<=300;i++)
             makeset(i);
        for (int i=0;i<strs.size();i++){
           for (int j = 0;j<strs.size();j++){
            bool ok = 0;
              if (i==j)
                 continue;
             int cnt = 0;   
             for (int k=0;k<strs[j].size();k++){
                   if (strs[i][k]!=strs[j][k])
                      cnt++;
                      if (cnt>2)
                      break;
             }
             if (cnt<=2)
              unionsets (i,j);
        }
        }
        int ans = 0;
        map<int,int>mp;
        for (int i=0;i<strs.size();i++){
             int parent = findset(i);
             mp[parent]++;
        }
        ans = mp.size();
        return ans;
    }
};