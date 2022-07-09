class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      int n=nums.size();
      vector<int>dp(n);
      priority_queue<pair<int,int>>pq;
      for(int i=n-1; i>=0; i--){
          while(pq.size()&&pq.top().second>i+k)
              pq.pop();
          dp[i]=dp[i]+nums[i];
          if (!pq.empty())
              dp[i]+=pq.top().first;
          pq.push({dp[i],i});
      }
      return dp[0];
    }
};