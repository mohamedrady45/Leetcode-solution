class Solution {
public:
    int maxScore(vector<int>&v, int k) {
        int n=v.size(),sum=0,mx=0;
        int left=0,right=v.size()-k;
        for (int i=right;i<n;i++)
            sum+=v[i];
    mx=sum;
        while(right<n)
        {
            sum+=v[left++]-v[right++];
            mx=max(mx,sum);
        }
        return mx;
    }
};