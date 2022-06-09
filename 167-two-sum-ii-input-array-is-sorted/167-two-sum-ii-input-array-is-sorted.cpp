class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   vector<int> v;
    map<int,int>mp;
    bool ok=0;
    for (int i=0; i<nums.size(); i++)
    {
        mp[nums[i]]=i;
    }
    for (int i=0; i<nums.size(); i++)
    {
        if (mp[target-nums[i]]!=i && mp[target-nums[i]])
        {
            v.push_back(mp[target-nums[i]]+1),v.push_back(i+1);
            break;
        }
    }
        sort (v.begin(),v.end());
        return v;
    }
};