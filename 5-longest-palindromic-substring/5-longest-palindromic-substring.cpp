class Solution {
public:
    vector<vector<int>>dp;
  int pal (string &sub,int i,int j)
{
    if (i>=j)
        return 1;
     if (dp[i][j]!=-1)
         return dp[i][j];
     if (sub[i]==sub[j])
        return dp[i][j] = pal(sub,i+1,j-1);
     else return dp[i][j]=0;
}
    string longestPalindrome(string s) {
        string ans="";
        dp.resize(s.size(),vector<int>(s.size(),-1));
        if (pal(s,0,s.size()-1))
            return s;
        for (int i=0;i<s.size();i++)
        {
            for (int j=i;j<s.size();j++)
            {
            if (pal(s,i,j))
            {
                string ss=s.substr(i,j-i+1);
                if (ans.size()<ss.size())
                    ans=ss;
            }
            }
        }
        return ans;
    }
};