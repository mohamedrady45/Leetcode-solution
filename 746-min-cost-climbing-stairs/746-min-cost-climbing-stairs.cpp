class Solution {
public:
    vector<int>dp;
    int solve(int i,vector<int>&v){
        int n=v.size();
        if (i>=n)
            return 0;
        int &ret=dp[i];
        if (~ret)
            return ret;
        int ans=min(solve(i+1,v),solve(i+2,v))+v[i];
        return ret=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size()+1,-1);
        return min(solve(1,cost),solve(0,cost));
    }
};