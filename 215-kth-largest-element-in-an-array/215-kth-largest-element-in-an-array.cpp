class Solution {
public:
    #define all(v) ((v).begin()), ((v).end())
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        sort(all(nums),greater<int>());
        return nums[k-1];
    }
};