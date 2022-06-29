class Solution {
public:
    static bool cmp(vector<int> &v,vector<int>&vv)
    {
        if (v[0]!=vv[0])
            return v[0]>vv[0];
            return v[1]<vv[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>ans;
        for (auto i:people)
        {
            pair<int,int>p=make_pair(i[0],i[1]);
            ans.insert(ans.begin()+p.second,i);
        }
        return ans;
    }
};