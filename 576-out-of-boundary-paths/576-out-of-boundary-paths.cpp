class Solution {
public:
    const long long mod=1e9+7;
    long long  dp[51][51][51];
    long long solve (int n, int m, int rem,int i,int j){
        if (i<0 || i>=n || j<0 || j>=m)
            return 1;
        if (rem<1)
            return 0;
        long long  &ret =dp[i][j][rem];
        if (~ret)
            return ret;
        return ret = (solve (n,m,rem-1,i+1,j)%mod+ solve (n,m,rem-1,i-1,j)%mod + solve (n,m,rem-1,i,j+1)%mod + solve (n,m,rem-1,i,j-1)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
              memset(dp,-1,sizeof dp);
               return solve (m,n,maxMove,startRow,startColumn);      
    }
};