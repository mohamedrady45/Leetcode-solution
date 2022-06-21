class Solution {
public:
    #define all(v) ((v).begin()), ((v).end())
    int furthestBuilding(vector<int>& v, int bricks, int ladders) {
        int n= v.size();
        int st=0,en=n-1,mid,ans=0;
        int x=bricks,y=ladders;
        while(st<=en)
        {
            bool ok=1;
            mid=(st+en)/2;
             vector<int>d;
            bricks=x,ladders=y;
            for (int i=1;i<=mid;i++)
            {
                if (v[i]-v[i-1]>0)
                d.push_back(v[i]-v[i-1]);
            }
            sort(all(d));
            reverse (all(d));
           for (auto i:d)
           {
               if (ladders)
                   ladders--;
               else bricks-=i;
           }
            if (bricks<0)
                ok=0;
            if (!ok)
                en=mid-1;
            else 
            {
                ans=max(ans,mid);
                st=mid+1;
            }
        }
        return ans;
    }
};