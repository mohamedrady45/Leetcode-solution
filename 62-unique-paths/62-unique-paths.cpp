class Solution {
    public :
    int dp[101][101];
    int solve (int i, int j, int m, int n) {
        if (i==m && j==n) 
        return 1;
        if (i>m || j>n) 
            return 0;
        int & ret = dp[i][j];
        if (~ret) 
            return ret ;
        return ret = solve (i+1,j, m, n) + solve (i,j+1, m, n) ;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp) ;
        return solve (1, 1, m, n);
    }
};