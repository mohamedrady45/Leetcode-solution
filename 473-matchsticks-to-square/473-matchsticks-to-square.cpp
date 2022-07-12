class Solution {
public:
    bool solve (int i,vector<int>&v,vector<int>&sq,int len){
        
        int n=v.size();
        if (i==n)
            return true;
        for (int j=0;j<4;j++){
            if (sq[j]+v[i]<=len)
            {
            sq[j]+=v[i];
                if (solve(i+1,v,sq,len))
                    return true;
                sq[j]-=v[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>&v) {
        int sum=0;
        vector<int>sq(4,0);
        for (auto i:v)
            sum+=i;
        if (sum%4!=0)
            return false;
        int len=sum/4;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        return solve (0,v,sq,len);
    }
};