class Solution {
public:
    vector<int> getRow(int n) {
         vector<vector<long long>>dp (100,vector<long long>(100));
        if (n==0){
            return {1};
        }
        dp[0][0] = 1;
        for(int i=1;i<n+2;i++){
            dp[i].resize(i+1);
            dp[i][0]=dp[i][i]=1;
            for(int j=1;j<i;j++)
            {
                dp[i][j]= dp[i-1][j]+dp[i-1][j-1];
            }
        }
        vector<long long>ans = dp[n];
        vector<int>res;
        for (auto & i : ans)
            res.push_back(i);
        return res;
    }
};