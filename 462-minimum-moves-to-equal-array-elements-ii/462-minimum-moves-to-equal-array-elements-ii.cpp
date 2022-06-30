class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=n/2,cnt=0;
        for (auto i:nums)
            cnt+=abs(nums[mid]-i);
        return cnt;
    }
};