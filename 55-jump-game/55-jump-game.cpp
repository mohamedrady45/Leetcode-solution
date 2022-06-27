class Solution {
public:
    vector<int>dp;
    bool solve (int i,vector<int>& v)
    {
        if (i>=v.size()-1)
            return true;
        if (dp[i]!=-1)
            return dp[i];
        for (int j=v[i];j>0;j--)
        {
            if (solve (i+j,v))
               return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        dp.assign(n+1,-1);
        return solve(0,nums);
    }
};