class Solution {
public:
    int mySqrt(int x) {
     long long st=1,en=x,mid,ans;
        while (st<=en)
        {
            mid=(st+en)/2;
            mid=(st+en)/2;
            if (mid*mid<=x)
            {
                st=mid+1;
                ans=mid;
            }
            else en=mid-1;
        }
        if (x<=1)
            return x;
        else return ans;
    }
};