class Solution {
public:
    vector<int>dp;
    int solve (int i,int n,vector<int>& v)
    {
        if (i>n)
            return 0;
        if (dp[i]!=-1)
            return dp[i];
        return dp[i]=max(solve(i+1,n,v),solve(i+2,n,v)+v[i]);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0)
            return 0;
        if (n==1)
            return nums[0];
        dp.assign(n+1,-1);
        int mn,mini;
        mn=solve(0,n-2,nums);
        dp.assign(n+1,-1);
        mini=solve(1,n-1,nums);
        return max(mini,mn);
    }
};