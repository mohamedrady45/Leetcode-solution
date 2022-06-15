class Solution {
public:
    static bool cmp(string &s1 ,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        map<string,int>dp;
        int ans=0;
        sort(words.begin(),words.end(),cmp);
        for (auto s : words)
        {
            for (int i=0;i<s.size();i++)
            {
                string sub=s.substr(0,i)+s.substr(i+1);
                dp[s]=max(dp[s],dp[sub]+1);
            }
            ans=max(ans,dp[s]);
        }
        return ans;
    }
};