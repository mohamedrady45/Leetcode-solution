class Solution {
public:
    int minDeletions(string s) {
       vector<int>freq(26,0);
        for (auto i:s)
            freq[i-'a']++;
        int mx=0;
        sort(freq.begin(),freq.end(),greater<int>());
        mx=freq[0];
        int ans=0;
        for (auto i:freq)
        { 
            if (i> mx)
            {
                if (mx>0)
                ans+=(i-mx);
                else ans+=i;
            }
            mx=min(mx-1,i-1);
        }
        return ans;
    }
};