class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int ret=0;
        for (int i:v)
            ret+=i;
         if (x>ret)
            return -1; 
        if (x==ret)
            return (int) v.size();
        int cur=ret-x;
        int st,sum,ans=-1e9;
        st=sum=0;
        for (int i=0;i<v.size();i++)
        {
            sum+=v[i];
            while(sum>cur)
            {
                sum-=v[st++];
            }
            if (sum==cur)
            {
                ans=max(ans,i-st+1);
            }
        }
        if (ans==-1e9)
            return -1;
        else 
    return v.size()-ans;
    }
};