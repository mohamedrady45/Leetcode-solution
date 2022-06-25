class Solution {
public:
    bool checkPossibility(vector<int>&v) {
        int n=v.size();
        int cnt=0;
        for (int i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
                cnt++;
            if (i==0)
            {
                v[i]=v[i+1];
                continue;
            }
            if (v[i+1]>=v[i-1])
            v[i]=v[i+1];
            else v[i+1]=v[i];
            }
        }
        if (cnt>1)
            return false;
        return true;
    }
};