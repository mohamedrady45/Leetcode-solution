class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if( n< 2) 
            return n;
        int pre = nums[1]-nums[0];
        int count=1;
        if (!pre)
            count=0;
        for(int i=2; i<nums.size(); i++){
            int diff = nums[i]- nums[i-1];
            
            if((diff>0 && pre<=0) || (diff<0 && pre>=0)){
                count++;
                pre = diff;
            }
        }
        return count+1;
    }
};