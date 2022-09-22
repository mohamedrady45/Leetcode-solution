class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int n = nums.size(),pivot_idx=-1;
        vector<int>pre(n,0),suff(n,0);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for (int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        for (int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i];
        }
        for (int i=0;i<n;i++){
            if (pre[i]==suff[i]){
                pivot_idx=i;
                break;
            }
        }
        return pivot_idx;
    }
};