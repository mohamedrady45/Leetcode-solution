class Solution {
public:
    vector<vector<int>>dp;
    int solve (string word1,string word2,int i,int j){
        if (i==0 ||j==0)
            return 0;
        if (dp[i][j]!=-1)
            return dp[i][j];
        if (word1[i-1]==word2[j-1])
            return dp[i][j]=solve(word1,word2,i-1,j-1)+1;
        else 
            return dp[i][j]=max(solve(word1,word2,i-1,j),solve(word1,word2,i,j-1));
    }
    int minDistance(string word1, string word2) {
         int n=word1.size();
	      int m=word2.size();
	    dp.resize(n+1,vector<int>(m+1,-1));
	     int ans=solve(word1,word2,n,m);
        return n+m-2*ans;
    }
};