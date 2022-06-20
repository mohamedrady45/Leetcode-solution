class Solution {
public:
    vector<int>dp;
    int solve (int n){
        if (n==0 || n==1 || n==2)
            return n;
        if (dp[n]!=-1)
            return dp[n];
        return dp[n]=solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        dp.assign(n+10,-1);
        return solve(n);
    }
};