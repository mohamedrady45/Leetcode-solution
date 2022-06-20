class Solution {
public:
    vector<int>dp;
    int solve (int idx,vector<int>& v)
    {
        if (idx==v.size())
            return 0;
        if (idx==v.size()-1)
            return v[idx];
        if (dp[idx]!=-1)
            return dp[idx];
        int ret=v[idx];
        return dp[idx]=ret+=min(solve(idx+1,v),solve(idx+2,v));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.assign(n+10,-1);
        int mn=solve(0,cost);
        int mini=solve(1,cost);
        return min(mn,mini);
    }
};