class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>occ(2);
        int n=nums.size();
        int st=0,en=n-1,mid,first_ans=-1;
        while(st<=en)
        {
            mid=(st+en)/2;
            if (nums[mid]<target)
                st=mid+1;
            else en=mid-1;
            if (nums[mid]==target)
            {
                first_ans=mid;
                en=mid-1;
            }
        }
     st=0,en=n-1,mid;
        int second_ans=-1;
        while(st<=en)
        {
            mid=(st+en)/2;
            if (nums[mid]==target)
            {
                second_ans=mid;
                st=mid+1;
            }
            else if (nums[mid]<target)
                st=mid+1;
            else en=mid-1;
        }
        occ[0]=first_ans;
        occ[1]=second_ans;
        return occ;
    }
};