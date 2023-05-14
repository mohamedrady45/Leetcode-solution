class Solution {
public:
     vector<int>v;
     int dp[1<<15][15];
     int n;
    int solve (int msk , int i){
        if (msk==(1<<n)-1)
        return 0;
        int &ret = dp[msk][i];
        if (~ret)
           return ret;
           ret = 0;
        for (int j=0;j<n;j++){
            if ((msk&(1<<j)))
               continue;
            for (int k=0;k<n;k++){
                if (j==k)
                  continue;
                if (!(msk&(1<<k))){
                    msk|=(1<<j);
                    msk|=(1<<k);
                    ret = max(ret ,solve(msk , i+1)+ i*__gcd(v[j],v[k]));
                    msk^=(1<<j);
                    msk^=(1<<k);
                }
            }
        }
        return ret;

    }
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        v = nums;
        n = nums.size();
        return solve (0,1);
    }
};