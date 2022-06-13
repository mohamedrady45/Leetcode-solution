class Solution {
public:
    vector<vector<int>>dp;
    int solve (int rows,int col,vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        if (rows==n-1)
            return triangle[rows][col];
        if (dp[rows][col]!=-1)
            return dp[rows][col];
        int down=solve(rows+1,col,triangle)+triangle[rows][col];
        int down_right=solve(rows+1,col+1,triangle)+triangle[rows][col];
        return dp[rows][col]=min(down_right,down);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(triangle.size(),vector<int>(triangle.size(),-1));
       int res;
        res=solve(0,0,triangle);
        return res;
    }
};