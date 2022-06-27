class Solution {
public:
    #define all(v) ((v).begin()), ((v).end())
    vector<int>dp;
    map<int,int>mp;
    int solve (int i,int j)
    {
        if (i>j)
            return 0;
        int &ret=dp[i];
        if (~ret)
            return ret;
        int take,leave;
        take=solve(i+2,j)+(i*mp[i]);
        leave =solve (i+1,j);
        return ret=max(take,leave);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mn,mx;
        mn=*min_element(all(nums));
        mx=*max_element(all(nums));
        dp.assign(mx+10,-1);
        for (auto i:nums)
            mp[i]++;
        return solve(mn,mx);
        
    }
};