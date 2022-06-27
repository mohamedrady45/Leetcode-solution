class Solution {
public:
    #define ll long long
    vector<ll>dp;
    ll solve (ll i,vector<int>& v)
    {
        if (i==v.size()-1)
            return 0;
        if (i>=v.size())
            return INT_MAX;
       ll &ret=dp[i];
        if (~ret)
            return ret;
        ll res=INT_MAX;
        for (int j=1;j<=v[i];j++)
        {
            res=min(res,solve(i+j,v)+1);
        }
        return ret=res;
        
    }
    int jump(vector<int>& nums) {
        int n =nums.size();
        dp.assign(n+1,-1);
        return solve(0,nums);
    }
};