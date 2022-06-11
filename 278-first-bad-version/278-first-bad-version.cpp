// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long st=0,en=n,mid,ans=0;
        while(st<=en)
        {
            mid=(st+en)/2;
            if (isBadVersion(mid))
                en=mid-1,ans=mid;
            else st=mid+1;
        }
        return ans;
    }
};