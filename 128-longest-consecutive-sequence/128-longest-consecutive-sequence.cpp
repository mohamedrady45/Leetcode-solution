class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;        
        set<int> set;
        for(auto i: nums)
            set.insert(i);       
        int cnt = 1;
        int maxCnt = INT_MIN;
        for(int i: set)
        {
            if(set.find(i+1) != set.end())    
                cnt++;
            else
                maxCnt = max(cnt, maxCnt),cnt = 1;
        }
        
        maxCnt = max(cnt, maxCnt);
        
        return maxCnt;
    }
};