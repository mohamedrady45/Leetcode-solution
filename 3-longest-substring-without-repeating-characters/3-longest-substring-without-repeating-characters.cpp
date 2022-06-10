class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<long long>v(100,0);
        long long ans=0,idx=32;
        for (long long i=0,j=0;j<s.size();j++)
        {
            i=max(i,v[s[j]-idx]);
            ans=max(ans,j-i+1);
            v[s[j]-idx]=j+1;
        }
        return ans;
    }
};