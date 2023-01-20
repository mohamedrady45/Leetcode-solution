class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       set<vector<int>>st;
        int n = nums.size();
        for (int i=0;i<(1<<n);i++){
            vector<int>curr;
            for (int j=0;j<n;j++){
               if (!(i&(1<<j)))
                   curr.push_back(nums[j]);
            }
            if(curr.size()>=2 && is_sorted(curr.begin(),curr.end()))
            st.insert(curr);
        }
         vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};