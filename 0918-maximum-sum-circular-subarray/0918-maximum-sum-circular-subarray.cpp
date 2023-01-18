class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = INT_MIN, 
        curMax = 0, minSum = INT_MAX, curMin = 0;
        for (auto t : nums) {
            curMax = max(curMax + t, t);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + t, t);
            minSum = min(minSum, curMin);
            total += t;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};