class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int ans=0 , curr=0;
        mp[0]=1;
        for (int i=0;i<nums.size();i++){
            curr+=nums[i];
            curr%=k;
            curr+=k;
            curr%=k;
            if (mp.count(curr))
              ans+=(mp[curr]++);
            else mp[curr]++;
        }
        return ans;
    }
};