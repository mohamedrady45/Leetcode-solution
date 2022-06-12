class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int>prefix(nums.size()+5,0);
        map<int,int>occ;
        prefix[1]=nums[0];
        occ[prefix[1]]=0;
        for (int i=2;i<=nums.size();i++)
            prefix[i]=prefix[i-1]+nums[i-1];
        int ans=prefix[1],last_idx=-1;
        for (int i=0;i<(int)nums.size();i++)
        {
            if (occ[nums[i]]>last_idx)
            {   
                last_idx=occ[nums[i]];
            }
            ans=max(ans,prefix[i+1]-prefix[last_idx]);     
            occ[nums[i]]=i+1;
        } 
        return ans;
    }
};